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
// multiplies the alpha of whatever colour is used: this is what the
// Transparency options do, and doing it here means dragging one costs
// nothing but a redraw
uniform float uAlphaScale;
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
  vColor.a *= uAlphaScale;
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
// 0 to paint on the window, 1 to sum into the two buffers order independent
// transparency keeps
uniform int uOitPass;

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

// Everything that gets drawn leaves through here. On the window it is simply
// the colour; in the transparency pass it is added to what the other fragments
// over the same pixel have left, which is what makes the result the same
// whatever order they were drawn in.
void emit(vec4 c)
{
  if(uOitPass == 1) {
    // How much this fragment counts for: the nearer and the more opaque, the
    // more. This is the weight of Mc Guire and Bavoil, whose point is that a
    // sum weighted this way looks close enough to the ordered blend. Theirs is
    // scaled by 1e8; the scale cancels out when the sum is divided by itself
    // below, and one that never passes 1 is what keeps a thousand fragments
    // over the same pixel inside what a half float can hold.
    float w = clamp(pow(min(1.0, c.a * 10.0) + 0.01, 3.0) *
                    pow(1.0 - gl_FragCoord.z * 0.9, 3.0), 1e-4, 1.0);
    fColor = vec4(c.rgb * c.a, c.a) * w;
    // How much light gets through is a product over the fragments, and only a
    // sum can be had from a buffer that every target blends the same way: the
    // logarithm is summed here and undone when the two are put on the window.
    fDepth = vec4(log(max(1.0 - c.a, 1e-4)));
  }
  else {
    fColor = c;
    fDepth = packDepth(gl_FragCoord.z);
  }
}

void main()
{
  for(int i = 0; i < 6; i++)
    if(vClip[i] < 0.0) discard;

  if(uStipple) {
    int bit = int(mod(floor(vDash / float(uStippleFactor)), 16.0));
    if((uStipplePattern & (1 << bit)) == 0) discard;
  }

  // an image is the colour of what it covers, lit or not: this is what
  // GL_REPLACE did, and nothing below has anything left to say about it
  if(uTextured == 2) {
    emit(texture(uTexture, vTexCoord));
    return;
  }

  // a string is drawn as a picture of itself: the texture says how much of the
  // colour each pixel of the quad gets, whether or not it is lit
  float alpha = vColor.a;
  if(uTextured == 1) alpha *= texture(uTexture, vTexCoord).r;

  if(!uLighting) {
    emit(vec4(vColor.rgb, alpha));
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

  emit(vec4(min(c, vec3(1.0)), alpha));
}
)";

  // What puts the two buffers of the transparency pass on the window. It is a
  // program of its own because it has samplers of its own and nothing else of
  // the drawing program to say, and it needs no vertices: three of them cover
  // the window, made out of the vertex number alone.
  const char *compositeVertexBody = R"(
void main()
{
  vec2 p = vec2((gl_VertexID == 1) ? 3.0 : -1.0,
                (gl_VertexID == 2) ? 3.0 : -1.0);
  gl_Position = vec4(p, 0.0, 1.0);
}
)";

  const char *compositeFragmentBody = R"(
uniform sampler2D uAccum;
uniform sampler2D uReveal;
layout(location = 0) out vec4 fColor;

void main()
{
  ivec2 at = ivec2(gl_FragCoord.xy);
  vec4 accum = texelFetch(uAccum, at, 0);
  // the sum of the logarithms is a product again
  float reveal = exp(texelFetch(uReveal, at, 0).r);
  // the colour the fragments average out to, and how much of the pixel they
  // cover between them: an ordinary "over" from here
  fColor = vec4(accum.rgb / max(accum.a, 1e-5), 1.0 - reveal);
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

    // The buffers the transparency pass sums into, the program that puts them
    // on the window, and whether that pass is the one being drawn. The depth
    // is a copy of the window's, so that what is transparent is hidden by the
    // opaque geometry in front of it.
    GLuint _oitFbo = 0, _oitAccum = 0, _oitReveal = 0, _oitDepthRb = 0;
    int _oitWidth = 0, _oitHeight = 0;
    GLuint _oitProgram = 0;
    GLint _uAccum = -1, _uReveal = -1;
    bool _oitOn = false, _oitFailed = false, _oitTried = false;
    // which of the two depth formats the window's buffer can be copied into:
    // they have to match exactly, and there is no asking which one it is
    GLenum _oitDepthFormat = 0;

    struct {
      GLint modelview, projection, normalMatrix, colorArray, color, pointSize;
      GLint clipPlane, clipOn, alphaScale;
      GLint lighting, twoSide, specular, shininess;
      GLint instanced, taper;
      GLint textured, texture;
      GLint stipple, stippleFactor, stipplePattern;
      GLint wideLine, lineWidth, viewport;
      GLint oitPass;
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
      _u.alphaScale = glApi::GetUniformLocation(p, "uAlphaScale");
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
      _u.oitPass = glApi::GetUniformLocation(p, "uOitPass");
      // the arrays are addressed element by element
      _u.clipPlane = _u.clipOn = -1;
      _u.lightPosition = _u.lightAmbient = _u.lightDiffuse = -1;
      _u.lightSpecular = _u.lightOn = -1;

      // a uniform starts at zero, and an alpha scale of zero would draw
      // nothing at all: it is the one that has to be given a value up front
      glApi::UseProgram(_program);
      glApi::Uniform1f(_u.alphaScale, 1.f);

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
    _oitFbo = _oitAccum = _oitReveal = _oitDepthRb = 0;
    _oitWidth = _oitHeight = 0;
    _oitProgram = 0;
    _uAccum = _uReveal = -1;
    _oitOn = _oitFailed = _oitTried = false;
    _oitDepthFormat = 0;
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
      glApi::ActiveTexture(GL_TEXTURE0);
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
      glApi::ActiveTexture(GL_TEXTURE0);
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

  void setAlphaScale(double scale)
  {
    if(!ensure()) return;
    glApi::Uniform1f(_u.alphaScale, (float)scale);
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
      glApi::ActiveTexture(GL_TEXTURE0);
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

  namespace {
    bool buildComposite()
    {
      if(_oitTried) return _oitProgram != 0;
      _oitTried = true;

      GLuint vs = compile(GL_VERTEX_SHADER, prologue() + compositeVertexBody);
      if(!vs) return false;
      GLuint fs =
        compile(GL_FRAGMENT_SHADER, prologue() + compositeFragmentBody);
      if(!fs) {
        glApi::DeleteShader(vs);
        return false;
      }
      GLuint p = glApi::CreateProgram();
      glApi::AttachShader(p, vs);
      glApi::AttachShader(p, fs);
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
        Msg::Error("Could not link the transparency program: %s", &log[0]);
        glApi::DeleteProgram(p);
        return false;
      }
      _oitProgram = p;
      _uAccum = glApi::GetUniformLocation(p, "uAccum");
      _uReveal = glApi::GetUniformLocation(p, "uReveal");
      return true;
    }

    void dropOitBuffers()
    {
      if(!_oitFbo) return;
      glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
      glApi::DeleteFramebuffers(1, &_oitFbo);
      glDeleteTextures(1, &_oitAccum);
      glDeleteTextures(1, &_oitReveal);
      glApi::DeleteRenderbuffers(1, &_oitDepthRb);
      _oitFbo = _oitAccum = _oitReveal = _oitDepthRb = 0;
    }

    GLuint floatTarget(int width, int height, GLenum internal, GLenum format)
    {
      GLuint t = 0;
      glGenTextures(1, &t);
      glBindTexture(GL_TEXTURE_2D, t);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexImage2D(GL_TEXTURE_2D, 0, internal, width, height, 0, format,
                   GL_HALF_FLOAT, nullptr);
      return t;
    }

    // The two buffers plus a copy of the window's depth, and the copy itself.
    // The depth formats of the two buffers have to match exactly for it, and
    // there is no way to ask what the window's is, so this is tried with one
    // and then the other.
    bool makeOitBuffers(int width, int height, GLenum depthFormat)
    {
      glApi::GenFramebuffers(1, &_oitFbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _oitFbo);

      // what the colours are summed in, and what the light left over is
      _oitAccum = floatTarget(width, height, GL_RGBA16F, GL_RGBA);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                  GL_TEXTURE_2D, _oitAccum, 0);
      _oitReveal = floatTarget(width, height, GL_R16F, GL_RED);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 1,
                                  GL_TEXTURE_2D, _oitReveal, 0);
      glBindTexture(GL_TEXTURE_2D, 0);

      glApi::GenRenderbuffers(1, &_oitDepthRb);
      glApi::BindRenderbuffer(GL_RENDERBUFFER, _oitDepthRb);
      glApi::RenderbufferStorage(GL_RENDERBUFFER, depthFormat, width, height);
      glApi::FramebufferRenderbuffer(
        GL_FRAMEBUFFER,
        (depthFormat == GL_DEPTH24_STENCIL8) ? GL_DEPTH_STENCIL_ATTACHMENT :
                                               GL_DEPTH_ATTACHMENT,
        GL_RENDERBUFFER, _oitDepthRb);

      if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
         GL_FRAMEBUFFER_COMPLETE) {
        dropOitBuffers();
        return false;
      }
      _oitWidth = width;
      _oitHeight = height;
      return true;
    }

    bool copyWindowDepth(int width, int height, GLenum depthFormat)
    {
      if(!_oitFbo && !makeOitBuffers(width, height, depthFormat)) return false;
      // whatever error was already pending is not ours to read
      while(glGetError() != GL_NO_ERROR) {}
      glApi::BindFramebuffer(GL_READ_FRAMEBUFFER, 0);
      glApi::BindFramebuffer(GL_DRAW_FRAMEBUFFER, _oitFbo);
      glApi::BlitFramebuffer(0, 0, width, height, 0, 0, width, height,
                             GL_DEPTH_BUFFER_BIT, GL_NEAREST);
      if(glGetError() == GL_NO_ERROR) return true;
      dropOitBuffers();
      return false;
    }
  } // namespace

  bool transparentPass() { return _oitOn; }

  bool beginTransparent()
  {
    if(_oitFailed || _oitOn) return false;
    if(!ensure() || !glApi::haveFramebufferObjects() ||
       !glApi::haveFloatColorBuffers() || !glApi::BlitFramebuffer ||
       !buildComposite()) {
      _oitFailed = true;
      return false;
    }

    // the whole window, as that is what the depth is copied from
    GLint vp[4];
    glGetIntegerv(GL_VIEWPORT, vp);
    int w = vp[0] + vp[2], h = vp[1] + vp[3];
    if(w < 1 || h < 1) return false;

    if(_oitFbo && (_oitWidth != w || _oitHeight != h)) dropOitBuffers();

    bool ok = false;
    if(_oitDepthFormat) { ok = copyWindowDepth(w, h, _oitDepthFormat); }
    else {
      const GLenum formats[2] = {GL_DEPTH24_STENCIL8, GL_DEPTH_COMPONENT24};
      for(int i = 0; i < 2 && !ok; i++) {
        ok = copyWindowDepth(w, h, formats[i]);
        if(ok) _oitDepthFormat = formats[i];
      }
    }
    if(!ok) {
      Msg::Debug("Could not sum transparency into buffers of our own: "
                 "drawing it sorted instead");
      _oitFailed = true;
      glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
      return false;
    }

    glApi::BindFramebuffer(GL_FRAMEBUFFER, _oitFbo);
    const GLenum bufs[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT0 + 1};
    glApi::DrawBuffers(2, bufs);

    // Both start at zero: nothing summed yet, and a summed logarithm of zero
    // is all of the light getting through. The depth that was just copied is
    // left alone.
    GLfloat clear[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clear);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(clear[0], clear[1], clear[2], clear[3]);

    // every fragment is added to what the others left, and none of them hides
    // another: that is the whole point
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glApi::Uniform1i(_u.oitPass, 1);
    _oitOn = true;
    return true;
  }

  void endTransparent()
  {
    if(!_oitOn) return;
    _oitOn = false;
    // said on the drawing program, which is still the one in use
    glApi::Uniform1i(_u.oitPass, 0);

    glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
    glDepthMask(GL_TRUE);

    glApi::UseProgram(_oitProgram);
    glApi::BindVertexArray(_vao);
    // the three vertices are made out of their own numbers, and an attribute
    // left enabled from the last draw would only be read from a stale buffer
    for(int i = ATTRIB_VERTEX; i <= ATTRIB_COLORB; i++)
      glApi::DisableVertexAttribArray(i);

    glApi::ActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _oitAccum);
    glApi::Uniform1i(_uAccum, 0);
    glApi::ActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, _oitReveal);
    glApi::Uniform1i(_uReveal, 1);
    glApi::ActiveTexture(GL_TEXTURE0);

    // what the fragments average out to, laid over the window in the
    // proportion the pixel still lets through
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    // The colour goes on the window the ordinary way. The window's own alpha
    // is what a saved image keeps, and it has to end up covered as much as the
    // pixel is, which is not what squaring it through the same factor would
    // give: it gets a blending of its own.
    if(glApi::BlendFuncSeparate)
      glApi::BlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE,
                               GL_ONE_MINUS_SRC_ALPHA);
    else
      // without it the window's alpha comes out squared where the transparency
      // covers it, which is what the ordinary blend has always done anyway
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glApi::UseProgram(_program);
  }
} // namespace glShader
