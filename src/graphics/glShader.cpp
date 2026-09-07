// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <vector>

#include <cstddef>
#include "glShader.h"
#include "GmshMessage.h"

namespace glShader {
  namespace {
    // The body of the two shaders, without the version line: the only thing
    // that separates a desktop core profile from OpenGL ES is that prologue,
    // as long as nothing here uses what one of them does not have -
    // gl_ClipDistance and the geometry stage in particular.
    const char *vertexBody = R"(
in vec3 aVertex;
in vec3 aNormal;
in vec4 aColor;
// one glyph: the three rows of the transform that places it, and the two
// radii a cylinder is shaped by. These come one per glyph rather than one per
// vertex, which is what lets the same shape be drawn many times over in one
// call.
in vec4 aGlyph0;
in vec4 aGlyph1;
in vec4 aGlyph2;
in vec2 aGlyphParam;
in vec2 aTexCoord;
in float aDash;
// the far end of a line drawn wide, and what it carries: such a line is one
// instance of a six cornered quad rather than a line of its own, and the
// vertex shader is handed both of its ends to work the quad out from
in vec3 aVertexB;
in vec3 aNormalB;
in vec4 aColorB;

uniform bool uInstanced;
uniform bool uTaper;
// A line wider than one pixel, which a core profile will not draw: it is drawn
// as a quad of that width in pixels instead, worked out where the line lands
// on the screen. uViewport is what turns the one into the other.
uniform bool uWideLine;
uniform float uLineWidth;
uniform vec2 uViewport;
uniform mat4 uModelview;
uniform mat4 uProjection;
uniform mat3 uNormalMatrix;
uniform bool uColorArray;
uniform vec4 uColor;
uniform float uPointSize;
uniform vec4 uClipPlane[6];
uniform bool uClipOn[6];

out vec3 vEye;
out vec3 vNormal;
out vec4 vColor;
out vec2 vTexCoord;
out float vDash;
out float vClip[6];

void main()
{
  vec3 p = aVertex;
  vec3 n = aNormal;
  vec4 eye;
  if(uInstanced) {
    if(uTaper) {
      // the radius of a cylinder follows its length, and the normal of its
      // side leans over by as much: the shape carries the cosine and the sine
      // of the angle each of its corners is at, which is what both come from
      float r = aGlyphParam.x + p.z * (aGlyphParam.y - aGlyphParam.x);
      n = vec3(p.x, p.y, aGlyphParam.x - aGlyphParam.y);
      p = vec3(p.x * r, p.y * r, p.z);
    }
    vec4 p4 = vec4(p, 1.0);
    p = vec3(dot(aGlyph0, p4), dot(aGlyph1, p4), dot(aGlyph2, p4));
    // The normals follow the inverse transpose of the transform. Up to a
    // positive factor, which normalizing takes out again, that is the
    // cofactors of its three columns.
    vec3 c0 = vec3(aGlyph0.x, aGlyph1.x, aGlyph2.x);
    vec3 c1 = vec3(aGlyph0.y, aGlyph1.y, aGlyph2.y);
    vec3 c2 = vec3(aGlyph0.z, aGlyph1.z, aGlyph2.z);
    n = mat3(cross(c1, c2), cross(c2, c0), cross(c0, c1)) * n;
  }
  vec4 clip;
  float dash = aDash;
  if(uWideLine) {
    // Which corner of the quad this is: two triangles over the two ends,
    // (A-, A+, B+) and (A-, B+, B-), so that the quad is wound the same way
    // round whichever way the line runs.
    int corner = gl_VertexID;
    bool atB = (corner == 2 || corner == 4 || corner == 5);
    float side = (corner == 1 || corner == 2 || corner == 4) ? 1.0 : -1.0;

    vec4 ea = uModelview * vec4(aVertex, 1.0);
    vec4 eb = uModelview * vec4(aVertexB, 1.0);
    vec4 ca = uProjection * ea;
    vec4 cb = uProjection * eb;
    // where the two ends land on the screen, which is where the width of the
    // line and the length the dashes are counted along it are measured
    vec2 sa = ca.xy / ca.w * uViewport * 0.5;
    vec2 sb = cb.xy / cb.w * uViewport * 0.5;
    vec2 along = sb - sa;
    float len = length(along);
    vec2 dir = (len > 0.0) ? along / len : vec2(1.0, 0.0);
    vec2 across = vec2(-dir.y, dir.x);

    eye = atB ? eb : ea;
    clip = atB ? cb : ca;
    n = atB ? aNormalB : aNormal;
    vColor = uColorArray ? (atB ? aColorB : aColor) : uColor;
    dash = atB ? len : 0.0;
    // half the width to each side, in the clip coordinates the screen ones
    // came from
    clip.xy += across * (side * uLineWidth * 0.5) / uViewport * 2.0 * clip.w;
  }
  else {
    eye = uModelview * vec4(p, 1.0);
    clip = uProjection * eye;
    vColor = uColorArray ? aColor : uColor;
  }
  vEye = eye.xyz;
  vNormal = uNormalMatrix * n;
  vTexCoord = aTexCoord;
  vDash = dash;
  // the planes are in eye coordinates, as glClipPlane() left them once the
  // modelview it was given had been applied
  for(int i = 0; i < 6; i++)
    vClip[i] = uClipOn[i] ? dot(uClipPlane[i], vec4(eye.xyz, 1.0)) : 1.0;
  gl_PointSize = uPointSize;
  gl_Position = clip;
}
)";

    const char *fragmentBody = R"(
in vec3 vEye;
in vec3 vNormal;
in vec4 vColor;
in vec2 vTexCoord;
in float vDash;
in float vClip[6];

// a string is drawn as a picture of itself: the texture says how much of the
// colour each pixel of the quad gets, and nothing else about it
// the dash pattern of a line: a bit of it every uStippleFactor pixels along
// the line, and the fragments the pattern has a hole at are thrown away.
// vDash is how far along its line this fragment is, worked out where the line
// was collected - there is no way to know it here
uniform bool uStipple;
uniform int uStippleFactor;
uniform int uStipplePattern;
// 0 no texture, 1 the texture says how much colour a pixel gets - a string
// drawn as a picture of itself - and 2 it is the colour, for an image
uniform int uTextured;
uniform sampler2D uTexture;
uniform bool uLighting;
uniform bool uTwoSide;
uniform vec4 uLightPosition[6];
uniform vec3 uLightAmbient[6];
uniform vec3 uLightDiffuse[6];
uniform vec3 uLightSpecular[6];
uniform bool uLightOn[6];
uniform vec3 uSpecular;
uniform float uShininess;

layout(location = 0) out vec4 fColor;
// A picking pass reads the depth back as well as the identifier, and neither
// OpenGL ES nor WebGL will read a depth buffer: it is written here as a colour
// instead, the 24 bits of it spread over three bytes. When only one buffer is
// being drawn into - which is every pass but that one - the write goes nowhere.
layout(location = 1) out vec4 fDepth;

vec4 packDepth(float d)
{
  float v = clamp(d, 0.0, 1.0) * 16777215.0;
  float r = floor(v / 65536.0);
  float g = floor((v - r * 65536.0) / 256.0);
  float b = floor(v - r * 65536.0 - g * 256.0);
  return vec4(r, g, b, 255.0) / 255.0;
}

void main()
{
  for(int i = 0; i < 6; i++)
    if(vClip[i] < 0.0) discard;

  if(uStipple) {
    int bit = int(mod(floor(vDash / float(uStippleFactor)), 16.0));
    if((uStipplePattern & (1 << bit)) == 0) discard;
  }

  fDepth = packDepth(gl_FragCoord.z);

  // an image is the colour of what it covers, lit or not: this is what
  // GL_REPLACE did, and nothing below has anything left to say about it
  if(uTextured == 2) {
    fColor = texture(uTexture, vTexCoord);
    return;
  }

  // a string is drawn as a picture of itself: the texture says how much of the
  // colour each pixel of the quad gets, whether or not it is lit
  float alpha = vColor.a;
  if(uTextured == 1) alpha *= texture(uTexture, vTexCoord).r;

  if(!uLighting) {
    fColor = vec4(vColor.rgb, alpha);
    return;
  }

  // GL_NORMALIZE: the normals are made unit again after the transform
  vec3 n = normalize(vNormal);
  // GL_LIGHT_MODEL_TWO_SIDE: a back face is lit with its normal flipped
  if(uTwoSide && !gl_FrontFacing) n = -n;

  // GL_COLOR_MATERIAL on GL_AMBIENT_AND_DIFFUSE: the material ambient and
  // diffuse colours are the current colour. The global ambient light is the
  // OpenGL default, which Gmsh never changes.
  vec3 c = 0.2 * vColor.rgb;

  for(int i = 0; i < 6; i++) {
    if(!uLightOn[i]) continue;
    vec3 l = (uLightPosition[i].w == 0.0) ?
               normalize(uLightPosition[i].xyz) :
               normalize(uLightPosition[i].xyz - vEye);
    c += uLightAmbient[i] * vColor.rgb;
    float d = max(dot(n, l), 0.0);
    c += uLightDiffuse[i] * vColor.rgb * d;
    if(d > 0.0) {
      // an infinite viewer: the half vector is taken against (0, 0, 1) rather
      // than against the direction to the vertex
      vec3 h = normalize(l + vec3(0.0, 0.0, 1.0));
      c += uLightSpecular[i] * uSpecular * pow(max(dot(n, h), 0.0), uShininess);
    }
  }

  fColor = vec4(min(c, vec3(1.0)), alpha);
}
)";

    GLuint _program = 0, _vao = 0;
    // one buffer for the vertices a caller holds itself and one for their
    // colours, grown as needed and reused from frame to frame
    GLuint _streamVertices = 0, _streamColors = 0, _streamNormals = 0;
    // one more for the glyphs a shape is drawn many times over with
    GLuint _streamGlyphs = 0, _streamTex = 0, _streamDash = 0;
    // A one pixel texture bound whenever nothing else is. The program has a
    // sampler in it whether or not what is being drawn goes through one, and
    // a driver checks that every sampler points at a complete texture when it
    // draws, not only when the branch that reads it is taken.
    GLuint _noTexture = 0;
    // the picking buffer and what it is made of
    GLuint _pickFbo = 0, _pickColorTex = 0, _pickDepthTex = 0, _pickDepthRb = 0;
    int _pickWidth = 0, _pickHeight = 0;
    bool _tried = false;

    struct {
      GLint modelview, projection, normalMatrix, colorArray, color, pointSize;
      GLint clipPlane, clipOn;
      GLint lighting, twoSide, specular, shininess;
      GLint instanced, taper;
      GLint textured, texture;
      GLint stipple, stippleFactor, stipplePattern;
      GLint wideLine, lineWidth, viewport;
      GLint lightPosition, lightAmbient, lightDiffuse, lightSpecular, lightOn;
    } _u;

    // A uniform is set on the program that is current, and these are called
    // from places that are not drawing - the lights are set once a frame,
    // before anything is drawn - so each of them says which program it means.
    bool ensure()
    {
      if(!_program) return false;
      glApi::UseProgram(_program);
      return true;
    }

    // the array uniforms are set one element at a time, which needs the
    // location of that element rather than of the array
    GLint element(const char *name, int i)
    {
      char buf[64];
      snprintf(buf, sizeof(buf), "%s[%d]", name, i);
      return glApi::GetUniformLocation(_program, buf);
    }

    std::string prologue()
    {
      if(glApi::isES())
        return "#version 300 es\nprecision highp float;\n";
      return "#version 330 core\n";
    }

    GLuint compile(GLenum type, const std::string &source)
    {
      GLuint s = glApi::CreateShader(type);
      if(!s) return 0;
      const char *src = source.c_str();
      glApi::ShaderSource(s, 1, &src, nullptr);
      glApi::CompileShader(s);
      GLint ok = 0;
      glApi::GetShaderiv(s, GL_COMPILE_STATUS, &ok);
      if(!ok) {
        GLint len = 0;
        glApi::GetShaderiv(s, GL_INFO_LOG_LENGTH, &len);
        std::vector<char> log(len > 1 ? len : 1, 0);
        if(len > 1) glApi::GetShaderInfoLog(s, len, nullptr, &log[0]);
        Msg::Error("Could not compile the %s shader: %s",
                   (type == GL_VERTEX_SHADER) ? "vertex" : "fragment",
                   &log[0]);
        glApi::DeleteShader(s);
        return 0;
      }
      return s;
    }

    bool build()
    {
      if(_tried) return _program != 0;
      _tried = true;

      if(!glApi::haveShaders()) {
        Msg::Warning("This OpenGL context has no shaders: drawing with the "
                     "fixed function pipeline instead");
        return false;
      }

      GLuint vs = compile(GL_VERTEX_SHADER, prologue() + vertexBody);
      if(!vs) return false;
      GLuint fs = compile(GL_FRAGMENT_SHADER, prologue() + fragmentBody);
      if(!fs) {
        glApi::DeleteShader(vs);
        return false;
      }

      GLuint p = glApi::CreateProgram();
      glApi::AttachShader(p, vs);
      glApi::AttachShader(p, fs);
      // the attribute numbers are ours, so that a vertex array can be bound
      // without asking the program where each of them went
      glApi::BindAttribLocation(p, ATTRIB_VERTEX, "aVertex");
      glApi::BindAttribLocation(p, ATTRIB_NORMAL, "aNormal");
      glApi::BindAttribLocation(p, ATTRIB_COLOR, "aColor");
      glApi::BindAttribLocation(p, ATTRIB_GLYPH0, "aGlyph0");
      glApi::BindAttribLocation(p, ATTRIB_GLYPH1, "aGlyph1");
      glApi::BindAttribLocation(p, ATTRIB_GLYPH2, "aGlyph2");
      glApi::BindAttribLocation(p, ATTRIB_GLYPH_PARAM, "aGlyphParam");
      glApi::BindAttribLocation(p, ATTRIB_TEXCOORD, "aTexCoord");
      glApi::BindAttribLocation(p, ATTRIB_DASH, "aDash");
      glApi::BindAttribLocation(p, ATTRIB_VERTEXB, "aVertexB");
      glApi::BindAttribLocation(p, ATTRIB_NORMALB, "aNormalB");
      glApi::BindAttribLocation(p, ATTRIB_COLORB, "aColorB");
      glApi::LinkProgram(p);
      glApi::DeleteShader(vs);
      glApi::DeleteShader(fs);

      GLint ok = 0;
      glApi::GetProgramiv(p, GL_LINK_STATUS, &ok);
      if(!ok) {
        GLint len = 0;
        glApi::GetProgramiv(p, GL_INFO_LOG_LENGTH, &len);
        std::vector<char> log(len > 1 ? len : 1, 0);
        if(len > 1) glApi::GetProgramInfoLog(p, len, nullptr, &log[0]);
        Msg::Error("Could not link the drawing program: %s", &log[0]);
        glApi::DeleteProgram(p);
        return false;
      }

      _program = p;
      _u.modelview = glApi::GetUniformLocation(p, "uModelview");
      _u.projection = glApi::GetUniformLocation(p, "uProjection");
      _u.normalMatrix = glApi::GetUniformLocation(p, "uNormalMatrix");
      _u.colorArray = glApi::GetUniformLocation(p, "uColorArray");
      _u.color = glApi::GetUniformLocation(p, "uColor");
      _u.pointSize = glApi::GetUniformLocation(p, "uPointSize");
      _u.lighting = glApi::GetUniformLocation(p, "uLighting");
      _u.twoSide = glApi::GetUniformLocation(p, "uTwoSide");
      _u.specular = glApi::GetUniformLocation(p, "uSpecular");
      _u.shininess = glApi::GetUniformLocation(p, "uShininess");
      _u.instanced = glApi::GetUniformLocation(p, "uInstanced");
      _u.taper = glApi::GetUniformLocation(p, "uTaper");
      _u.textured = glApi::GetUniformLocation(p, "uTextured");
      _u.texture = glApi::GetUniformLocation(p, "uTexture");
      _u.stipple = glApi::GetUniformLocation(p, "uStipple");
      _u.stippleFactor = glApi::GetUniformLocation(p, "uStippleFactor");
      _u.stipplePattern = glApi::GetUniformLocation(p, "uStipplePattern");
      _u.wideLine = glApi::GetUniformLocation(p, "uWideLine");
      _u.lineWidth = glApi::GetUniformLocation(p, "uLineWidth");
      _u.viewport = glApi::GetUniformLocation(p, "uViewport");
      // the arrays are addressed element by element
      _u.clipPlane = _u.clipOn = -1;
      _u.lightPosition = _u.lightAmbient = _u.lightDiffuse = -1;
      _u.lightSpecular = _u.lightOn = -1;

      // a core profile draws nothing without a vertex array object bound, and
      // one is enough: the arrays it holds are set again at every draw
      glApi::GenVertexArrays(1, &_vao);

      Msg::Debug("Drawing program built, GLSL %s",
                 (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
      return true;
    }
  } // namespace

  bool available() { return build(); }

  bool use()
  {
    if(!build()) return false;
    glApi::UseProgram(_program);
    glApi::BindVertexArray(_vao);
    // OpenGL ES always takes the point size from the shader; a desktop core
    // profile only does when it is told to
    if(!glApi::isES()) glEnable(GL_PROGRAM_POINT_SIZE);
    return true;
  }

  void reset()
  {
    // the program and the array object belonged to a context that is gone;
    // deleting them now would be deleting names in whichever context is
    // current, which are not ours
    _program = _vao = 0;
    _streamVertices = _streamColors = _streamNormals = 0;
    _streamGlyphs = _streamTex = _streamDash = 0;
    _noTexture = 0;
    _pickFbo = _pickColorTex = _pickDepthTex = _pickDepthRb = 0;
    _pickWidth = _pickHeight = 0;
    _tried = false;
  }

  void setMatrices(const double modelview[16], const double projection[16])
  {
    if(!ensure()) return;
    float m[16], p[16];
    for(int i = 0; i < 16; i++) {
      m[i] = (float)modelview[i];
      p[i] = (float)projection[i];
    }
    glApi::UniformMatrix4fv(_u.modelview, 1, GL_FALSE, m);
    glApi::UniformMatrix4fv(_u.projection, 1, GL_FALSE, p);

    // the normal matrix is the inverse transpose of the upper left 3x3 of the
    // modelview, which is what a non-uniform scale needs; GL_NORMALIZE takes
    // care of the length afterwards
    double a[9] = {modelview[0], modelview[1], modelview[2],
                   modelview[4], modelview[5], modelview[6],
                   modelview[8], modelview[9], modelview[10]};
    double det = a[0] * (a[4] * a[8] - a[5] * a[7]) -
                 a[3] * (a[1] * a[8] - a[2] * a[7]) +
                 a[6] * (a[1] * a[5] - a[2] * a[4]);
    float n[9];
    if(det != 0.) {
      double id = 1. / det;
      // the inverse transpose, written out in the same column major layout
      n[0] = (float)((a[4] * a[8] - a[5] * a[7]) * id);
      n[1] = (float)((a[6] * a[5] - a[3] * a[8]) * id);
      n[2] = (float)((a[3] * a[7] - a[6] * a[4]) * id);
      n[3] = (float)((a[7] * a[2] - a[1] * a[8]) * id);
      n[4] = (float)((a[0] * a[8] - a[6] * a[2]) * id);
      n[5] = (float)((a[6] * a[1] - a[0] * a[7]) * id);
      n[6] = (float)((a[1] * a[5] - a[4] * a[2]) * id);
      n[7] = (float)((a[3] * a[2] - a[0] * a[5]) * id);
      n[8] = (float)((a[0] * a[4] - a[3] * a[1]) * id);
    }
    else {
      for(int i = 0; i < 9; i++) n[i] = (float)a[i];
    }
    glApi::UniformMatrix3fv(_u.normalMatrix, 1, GL_FALSE, n);
  }

  void setLight(int i, const double position[4], const float ambient[3],
                const float diffuse[3], const float specular[3])
  {
    if(i < 0 || i > 5 || !ensure()) return;
    const float black[3] = {0.f, 0.f, 0.f};
    float p[4] = {(float)position[0], (float)position[1], (float)position[2],
                  (float)position[3]};
    glApi::Uniform4fv(element("uLightPosition", i), 1, p);
    glApi::Uniform3fv(element("uLightAmbient", i), 1, ambient ? ambient : black);
    glApi::Uniform3fv(element("uLightDiffuse", i), 1, diffuse ? diffuse : black);
    glApi::Uniform3fv(element("uLightSpecular", i), 1,
                      specular ? specular : black);
    glApi::Uniform1i(element("uLightOn", i), 1);
  }

  void setLightOff(int i)
  {
    if(i < 0 || i > 5 || !ensure()) return;
    glApi::Uniform1i(element("uLightOn", i), 0);
  }

  void setMaterial(double shine, double shineExponent)
  {
    if(!ensure()) return;
    float s[3] = {(float)shine, (float)shine, (float)shine};
    glApi::Uniform3fv(_u.specular, 1, s);
    // the fixed function exponent is in [0, 128]
    glApi::Uniform1f(_u.shininess, (float)shineExponent);
  }

  void setLighting(bool on, bool twoSide)
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.lighting, on ? 1 : 0);
    glApi::Uniform1i(_u.twoSide, twoSide ? 1 : 0);
  }

  void setClipPlane(int i, const double plane[4])
  {
    if(i < 0 || i > 5 || !ensure()) return;
    float p[4] = {(float)plane[0], (float)plane[1], (float)plane[2],
                  (float)plane[3]};
    glApi::Uniform4fv(element("uClipPlane", i), 1, p);
    glApi::Uniform1i(element("uClipOn", i), 1);
  }

  void setClipPlaneOff(int i)
  {
    if(i < 0 || i > 5 || !ensure()) return;
    glApi::Uniform1i(element("uClipOn", i), 0);
  }

  // say that nothing is drawn through a texture, and leave the sampler
  // pointing at one that is at least there
  void noTexture()
  {
    if(!_noTexture) {
      const unsigned char one = 255;
      glGenTextures(1, &_noTexture);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, _noTexture);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 1, 1, 0, GL_RED, GL_UNSIGNED_BYTE,
                   &one);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else {
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, _noTexture);
    }
    glApi::Uniform1i(_u.texture, 0);
    glApi::Uniform1i(_u.textured, 0);
  }

  void setStipple(bool on, int factor, unsigned short pattern)
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.stipple, on ? 1 : 0);
    glApi::Uniform1i(_u.stippleFactor, (factor > 0) ? factor : 1);
    glApi::Uniform1i(_u.stipplePattern, (int)pattern);
  }

  void setColorArray(bool on)
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.colorArray, on ? 1 : 0);
  }

  void setColor(const unsigned char color[4])
  {
    if(!ensure()) return;
    float c[4] = {color[0] / 255.f, color[1] / 255.f, color[2] / 255.f,
                  color[3] / 255.f};
    glApi::Uniform4fv(_u.color, 1, c);
  }

  void setPointSize(double size)
  {
    if(!ensure()) return;
    glApi::Uniform1f(_u.pointSize, (float)size);
  }

  void streamArrays(const float *vertices, const unsigned char *colors,
                    int count)
  {
    if(count <= 0 || !ensure()) return;
    if(!_streamVertices) glApi::GenBuffers(1, &_streamVertices);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamVertices);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 3 * sizeof(float),
                      vertices, GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_VERTEX);
    glApi::VertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, 0,
                               nullptr);
    glApi::DisableVertexAttribArray(ATTRIB_NORMAL);
    if(colors) {
      if(!_streamColors) glApi::GenBuffers(1, &_streamColors);
      glApi::BindBuffer(GL_ARRAY_BUFFER, _streamColors);
      glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 4, colors,
                        GL_STREAM_DRAW);
      glApi::EnableVertexAttribArray(ATTRIB_COLOR);
      glApi::VertexAttribPointer(ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0,
                                 nullptr);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_COLOR);
    }
    glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void streamDash(const float *dashes, int count)
  {
    if(!ensure()) return;
    if(!dashes || count <= 0) {
      glApi::DisableVertexAttribArray(ATTRIB_DASH);
      return;
    }
    if(!_streamDash) glApi::GenBuffers(1, &_streamDash);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamDash);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * sizeof(float),
                      dashes, GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_DASH);
    glApi::VertexAttribPointer(ATTRIB_DASH, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glApi::VertexAttribDivisor(ATTRIB_DASH, 0);
    glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
  }

  bool drawWideLines(const float *vertices, const void *normals,
                     GLenum normalType, const unsigned char *colors, int count,
                     double width, bool lit)
  {
    if(count < 2 || !glApi::haveInstancing() || !ensure()) return false;
    int segments = count / 2;
    glApi::BindVertexArray(_vao);

    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    float view[2] = {(float)vp[2], (float)vp[3]};
    glApi::Uniform2fv(_u.viewport, 1, view);
    glApi::Uniform1f(_u.lineWidth, (float)width);
    glApi::Uniform1i(_u.wideLine, 1);

    // The two ends of a segment are the same buffer read at a stride of two
    // vertices, one of them a vertex further along: that is what lets the
    // shader see both of them at once, one segment to an instance.
    if(!_streamVertices) glApi::GenBuffers(1, &_streamVertices);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamVertices);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 3 * sizeof(float),
                      vertices, GL_STREAM_DRAW);
    const GLsizei vstride = 6 * sizeof(float);
    glApi::EnableVertexAttribArray(ATTRIB_VERTEX);
    glApi::VertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, vstride,
                               nullptr);
    glApi::VertexAttribDivisor(ATTRIB_VERTEX, 1);
    glApi::EnableVertexAttribArray(ATTRIB_VERTEXB);
    glApi::VertexAttribPointer(ATTRIB_VERTEXB, 3, GL_FLOAT, GL_FALSE, vstride,
                               (const GLvoid *)(std::size_t)(3 *
                                                             sizeof(float)));
    glApi::VertexAttribDivisor(ATTRIB_VERTEXB, 1);

    if(lit && normals) {
      // the arrays keep their normals as bytes and the collector as floats,
      // so how far apart two of them are depends on which is being drawn
      std::size_t nsize = (normalType == GL_FLOAT) ? sizeof(float) : 1;
      GLboolean norm = (normalType == GL_FLOAT) ? GL_FALSE : GL_TRUE;
      if(!_streamNormals) glApi::GenBuffers(1, &_streamNormals);
      glApi::BindBuffer(GL_ARRAY_BUFFER, _streamNormals);
      glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)(count * 3 * nsize),
                        normals, GL_STREAM_DRAW);
      glApi::EnableVertexAttribArray(ATTRIB_NORMAL);
      glApi::VertexAttribPointer(ATTRIB_NORMAL, 3, normalType, norm,
                                 (GLsizei)(6 * nsize), nullptr);
      glApi::VertexAttribDivisor(ATTRIB_NORMAL, 1);
      glApi::EnableVertexAttribArray(ATTRIB_NORMALB);
      glApi::VertexAttribPointer(ATTRIB_NORMALB, 3, normalType, norm,
                                 (GLsizei)(6 * nsize),
                                 (const GLvoid *)(3 * nsize));
      glApi::VertexAttribDivisor(ATTRIB_NORMALB, 1);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_NORMAL);
      glApi::DisableVertexAttribArray(ATTRIB_NORMALB);
    }

    if(colors) {
      if(!_streamColors) glApi::GenBuffers(1, &_streamColors);
      glApi::BindBuffer(GL_ARRAY_BUFFER, _streamColors);
      glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 4, colors,
                        GL_STREAM_DRAW);
      glApi::EnableVertexAttribArray(ATTRIB_COLOR);
      glApi::VertexAttribPointer(ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, 8,
                                 nullptr);
      glApi::VertexAttribDivisor(ATTRIB_COLOR, 1);
      glApi::EnableVertexAttribArray(ATTRIB_COLORB);
      glApi::VertexAttribPointer(ATTRIB_COLORB, 4, GL_UNSIGNED_BYTE, GL_TRUE,
                                 8, (const GLvoid *)(std::size_t)4);
      glApi::VertexAttribDivisor(ATTRIB_COLORB, 1);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_COLOR);
      glApi::DisableVertexAttribArray(ATTRIB_COLORB);
    }
    glApi::DisableVertexAttribArray(ATTRIB_TEXCOORD);
    glApi::DisableVertexAttribArray(ATTRIB_DASH);

    setColorArray(colors != nullptr);
    noTexture();
    glApi::DrawArraysInstanced(GL_TRIANGLES, 0, 6, segments);

    glApi::Uniform1i(_u.wideLine, 0);
    glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    const int attribs[6] = {ATTRIB_VERTEX,  ATTRIB_VERTEXB, ATTRIB_NORMAL,
                            ATTRIB_NORMALB, ATTRIB_COLOR,   ATTRIB_COLORB};
    for(int i = 0; i < 6; i++) {
      glApi::DisableVertexAttribArray(attribs[i]);
      glApi::VertexAttribDivisor(attribs[i], 0);
    }
    return true;
  }

  bool drawGlyphs(const float *vertices, const float *normals, int numVertices,
                  const void *glyphs, int numGlyphs, bool taper, bool colors)
  {
    if(numVertices <= 0 || numGlyphs <= 0) return true;
    if(!glApi::haveInstancing() || !ensure()) return false;
    glApi::BindVertexArray(_vao);

    // the shape itself, once
    if(!_streamVertices) glApi::GenBuffers(1, &_streamVertices);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamVertices);
    glApi::BufferData(GL_ARRAY_BUFFER,
                      (GLsizeiptr)numVertices * 3 * sizeof(float), vertices,
                      GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_VERTEX);
    glApi::VertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, 0,
                               nullptr);
    glApi::VertexAttribDivisor(ATTRIB_VERTEX, 0);

    if(!_streamNormals) glApi::GenBuffers(1, &_streamNormals);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamNormals);
    glApi::BufferData(GL_ARRAY_BUFFER,
                      (GLsizeiptr)numVertices * 3 * sizeof(float), normals,
                      GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_NORMAL);
    glApi::VertexAttribPointer(ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, 0,
                               nullptr);
    glApi::VertexAttribDivisor(ATTRIB_NORMAL, 0);

    // and the glyphs, one of each of these per glyph rather than per vertex,
    // which is what the divisor says
    const GLsizei stride = GLYPH_STRIDE;
    if(!_streamGlyphs) glApi::GenBuffers(1, &_streamGlyphs);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamGlyphs);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)numGlyphs * stride, glyphs,
                      GL_STREAM_DRAW);
    for(int i = 0; i < 3; i++) {
      glApi::EnableVertexAttribArray(ATTRIB_GLYPH0 + i);
      glApi::VertexAttribPointer(ATTRIB_GLYPH0 + i, 4, GL_FLOAT, GL_FALSE,
                                 stride,
                                 (const GLvoid *)(std::size_t)(16 * i));
      glApi::VertexAttribDivisor(ATTRIB_GLYPH0 + i, 1);
    }
    glApi::EnableVertexAttribArray(ATTRIB_GLYPH_PARAM);
    glApi::VertexAttribPointer(ATTRIB_GLYPH_PARAM, 2, GL_FLOAT, GL_FALSE,
                               stride, (const GLvoid *)(std::size_t)52);
    glApi::VertexAttribDivisor(ATTRIB_GLYPH_PARAM, 1);
    if(colors) {
      glApi::EnableVertexAttribArray(ATTRIB_COLOR);
      glApi::VertexAttribPointer(ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE,
                                 stride, (const GLvoid *)(std::size_t)48);
      glApi::VertexAttribDivisor(ATTRIB_COLOR, 1);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_COLOR);
    }

    setColorArray(colors);
    noTexture();
    glApi::Uniform1i(_u.instanced, 1);
    glApi::Uniform1i(_u.taper, taper ? 1 : 0);
    glApi::DrawArraysInstanced(GL_TRIANGLES, 0, numVertices, numGlyphs);
    glApi::Uniform1i(_u.instanced, 0);

    glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    glApi::DisableVertexAttribArray(ATTRIB_VERTEX);
    glApi::DisableVertexAttribArray(ATTRIB_NORMAL);
    glApi::DisableVertexAttribArray(ATTRIB_COLOR);
    for(int i = 0; i < 3; i++) {
      glApi::DisableVertexAttribArray(ATTRIB_GLYPH0 + i);
      glApi::VertexAttribDivisor(ATTRIB_GLYPH0 + i, 0);
    }
    glApi::DisableVertexAttribArray(ATTRIB_GLYPH_PARAM);
    glApi::VertexAttribDivisor(ATTRIB_GLYPH_PARAM, 0);
    // the colour is a per vertex attribute everywhere else
    glApi::VertexAttribDivisor(ATTRIB_COLOR, 0);
    return true;
  }

  void drawImmediate(GLenum mode, const float *vertices, const float *normals,
                     const unsigned char *colors, const float *texCoords,
                     const float *dashes, unsigned int texture, int textureMode,
                     int count)
  {
    if(count <= 0 || !ensure()) return;
    glApi::BindVertexArray(_vao);

    if(!_streamVertices) glApi::GenBuffers(1, &_streamVertices);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamVertices);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 3 * sizeof(float),
                      vertices, GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_VERTEX);
    glApi::VertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, 0,
                               nullptr);

    if(!_streamNormals) glApi::GenBuffers(1, &_streamNormals);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamNormals);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 3 * sizeof(float),
                      normals, GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_NORMAL);
    glApi::VertexAttribPointer(ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, 0,
                               nullptr);

    if(!_streamColors) glApi::GenBuffers(1, &_streamColors);
    glApi::BindBuffer(GL_ARRAY_BUFFER, _streamColors);
    glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 4, colors,
                      GL_STREAM_DRAW);
    glApi::EnableVertexAttribArray(ATTRIB_COLOR);
    glApi::VertexAttribPointer(ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0,
                               nullptr);

    if(dashes) {
      if(!_streamDash) glApi::GenBuffers(1, &_streamDash);
      glApi::BindBuffer(GL_ARRAY_BUFFER, _streamDash);
      glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * sizeof(float),
                        dashes, GL_STREAM_DRAW);
      glApi::EnableVertexAttribArray(ATTRIB_DASH);
      glApi::VertexAttribPointer(ATTRIB_DASH, 1, GL_FLOAT, GL_FALSE, 0,
                                 nullptr);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_DASH);
    }

    // the texture a string is drawn as a picture of itself through, if there
    // is one; the coordinates go with it and are nothing without it
    if(texture && texCoords) {
      if(!_streamTex) glApi::GenBuffers(1, &_streamTex);
      glApi::BindBuffer(GL_ARRAY_BUFFER, _streamTex);
      glApi::BufferData(GL_ARRAY_BUFFER, (GLsizeiptr)count * 2 * sizeof(float),
                        texCoords, GL_STREAM_DRAW);
      glApi::EnableVertexAttribArray(ATTRIB_TEXCOORD);
      glApi::VertexAttribPointer(ATTRIB_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 0,
                                 nullptr);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, texture);
      glApi::Uniform1i(_u.texture, 0);
      glApi::Uniform1i(_u.textured, textureMode ? textureMode : 1);
    }
    else {
      glApi::DisableVertexAttribArray(ATTRIB_TEXCOORD);
      noTexture();
    }

    // every vertex carries the colour that was current when it was given
    setColorArray(true);
    glDrawArrays(mode, 0, count);

    noTexture();
    glApi::BindBuffer(GL_ARRAY_BUFFER, 0);
    glApi::DisableVertexAttribArray(ATTRIB_VERTEX);
    glApi::DisableVertexAttribArray(ATTRIB_NORMAL);
    glApi::DisableVertexAttribArray(ATTRIB_COLOR);
    glApi::DisableVertexAttribArray(ATTRIB_TEXCOORD);
  }

  bool bindPickBuffer(int width, int height)
  {
    if(width < 1 || height < 1) return false;
    if(!ensure() || !glApi::haveFramebufferObjects()) return false;

    if(_pickFbo && (_pickWidth != width || _pickHeight != height)) {
      // the window has been resized: the attachments are the wrong size
      glApi::DeleteFramebuffers(1, &_pickFbo);
      glDeleteTextures(1, &_pickColorTex);
      glDeleteTextures(1, &_pickDepthTex);
      glApi::DeleteRenderbuffers(1, &_pickDepthRb);
      _pickFbo = _pickColorTex = _pickDepthTex = _pickDepthRb = 0;
    }

    if(!_pickFbo) {
      glApi::GenFramebuffers(1, &_pickFbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _pickFbo);

      glGenTextures(1, &_pickColorTex);
      glBindTexture(GL_TEXTURE_2D, _pickColorTex);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, nullptr);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                  GL_TEXTURE_2D, _pickColorTex, 0);

      glGenTextures(1, &_pickDepthTex);
      glBindTexture(GL_TEXTURE_2D, _pickDepthTex);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, nullptr);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 1,
                                  GL_TEXTURE_2D, _pickDepthTex, 0);

      // the pass still depth tests: what it reads back is the depth of what
      // ended up in front, not of everything that was drawn
      glApi::GenRenderbuffers(1, &_pickDepthRb);
      glApi::BindRenderbuffer(GL_RENDERBUFFER, _pickDepthRb);
      glApi::RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width,
                                 height);
      glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                                     GL_RENDERBUFFER, _pickDepthRb);
      glBindTexture(GL_TEXTURE_2D, 0);

      if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
         GL_FRAMEBUFFER_COMPLETE) {
        Msg::Warning("Could not make a buffer to pick in: picking in the "
                     "window instead");
        glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
        glApi::DeleteFramebuffers(1, &_pickFbo);
        _pickFbo = 0;
        return false;
      }
      _pickWidth = width;
      _pickHeight = height;
      Msg::Debug("Picking into a %dx%d buffer, with the depth as a colour",
                 width, height);
    }

    glApi::BindFramebuffer(GL_FRAMEBUFFER, _pickFbo);
    const GLenum bufs[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT0 + 1};
    glApi::DrawBuffers(2, bufs);
    return true;
  }

  void readPickBuffer(int x, int y, int w, int h, unsigned char *colors,
                      float *depths)
  {
    if(!_pickFbo || w < 1 || h < 1) return;
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadBuffer(GL_COLOR_ATTACHMENT0);
    glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, colors);

    std::vector<unsigned char> packed((std::size_t)4 * w * h, 0);
    glReadBuffer(GL_COLOR_ATTACHMENT0 + 1);
    glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &packed[0]);
    for(std::size_t i = 0; i < (std::size_t)w * h; i++) {
      // the three bytes the shader spread the depth over; a fragment that was
      // never drawn leaves them at zero, which the alpha tells apart from a
      // depth of zero
      unsigned int v = ((unsigned int)packed[4 * i] << 16) |
                       ((unsigned int)packed[4 * i + 1] << 8) |
                       (unsigned int)packed[4 * i + 2];
      depths[i] = packed[4 * i + 3] ? (float)(v / 16777215.) : 1.f;
    }
  }

  void releasePickBuffer()
  {
    if(!_pickFbo) return;
    glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
  }
} // namespace glShader
