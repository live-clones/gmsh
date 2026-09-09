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
    // The shader bodies without the version line, which is all that
    // separates a desktop core profile from OpenGL ES, as long as nothing
    // here uses what one lacks (gl_ClipDistance, geometry shaders).
    const char *vertexBody = R"(
in vec3 aVertex;
in vec3 aNormal;
in vec4 aColor;
// per glyph (instanced drawing): three rows of the placing transform, and the
// two radii of a cylinder
in vec4 aGlyph0;
in vec4 aGlyph1;
in vec4 aGlyph2;
in vec2 aGlyphParam;
in vec2 aTexCoord;
in float aDash;
// the far end of a wide line: such a line is an instance of a six vertex
// quad, and the shader needs both ends to build it
in vec3 aVertexB;
in vec3 aNormalB;
in vec4 aColorB;

uniform bool uInstanced;
uniform bool uTaper;
// a line wider than one pixel is drawn as a quad of that width in pixels,
// computed where the line lands on screen (uViewport)
uniform bool uWideLine;
uniform float uLineWidth;
uniform vec2 uViewport;
uniform mat4 uModelview;
uniform mat4 uProjection;
uniform mat3 uNormalMatrix;
uniform bool uColorArray;
// multiplies the alpha of every colour (the Transparency options)
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
      // the radius of a cylinder varies along its length and its side normal
      // leans by as much; the shape carries the cosine and sine of each
      // corner's angle
      float r = aGlyphParam.x + p.z * (aGlyphParam.y - aGlyphParam.x);
      n = vec3(p.x, p.y, aGlyphParam.x - aGlyphParam.y);
      p = vec3(p.x * r, p.y * r, p.z);
    }
    vec4 p4 = vec4(p, 1.0);
    p = vec3(dot(aGlyph0, p4), dot(aGlyph1, p4), dot(aGlyph2, p4));
    // normals follow the inverse transpose of the transform, which up to a
    // positive factor is the cofactors of its columns
    vec3 c0 = vec3(aGlyph0.x, aGlyph1.x, aGlyph2.x);
    vec3 c1 = vec3(aGlyph0.y, aGlyph1.y, aGlyph2.y);
    vec3 c2 = vec3(aGlyph0.z, aGlyph1.z, aGlyph2.z);
    n = mat3(cross(c1, c2), cross(c2, c0), cross(c0, c1)) * n;
  }
  vec4 clip;
  float dash = aDash;
  if(uWideLine) {
    // which corner of the quad: triangles (A-, A+, B+) and (A-, B+, B-),
    // wound the same way whichever way the line runs
    int corner = gl_VertexID;
    bool atB = (corner == 2 || corner == 4 || corner == 5);
    float side = (corner == 1 || corner == 2 || corner == 4) ? 1.0 : -1.0;

    vec4 ea = uModelview * vec4(aVertex, 1.0);
    vec4 eb = uModelview * vec4(aVertexB, 1.0);
    vec4 ca = uProjection * ea;
    vec4 cb = uProjection * eb;
    // where the ends land on screen: the width and the dash length are
    // measured there
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
    // half the width to each side, back in clip coordinates
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
  // the planes are in eye coordinates
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

// the dash pattern of a line: a bit every uStippleFactor pixels along the
// line, fragments in a hole are discarded; vDash (distance along the line) is
// computed where the line was collected, as it cannot be known here
uniform bool uStipple;
uniform int uStippleFactor;
uniform int uStipplePattern;
// 0: no texture; 1: the texture is the alpha of the colour (a string); 2: it
// is the colour (an image)
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
// 0: the fixed function model below; 1: studio; 2: the shadow catcher of the
// studio model, on which only the shadow is drawn
uniform int uShading;
// the studio light: the key direction and the model's up axis in eye
// coordinates, the key's shadow map with the matrix from eye coordinates to
// it, and the same for the dome direction of the current sample
uniform vec3 uStudioLight;
uniform vec3 uStudioUp;
// the size of a texel of the maps, in eye coordinates
uniform float uShadowTexel;
uniform bool uShadowOn;
uniform mat4 uShadowFromEye;
uniform sampler2DShadow uShadow;
uniform bool uDomeOn;
uniform vec3 uDomeDir;
uniform mat4 uDomeFromEye;
uniform sampler2DShadow uDome;
// drawing into a shadow map, and the seed of the frame being accumulated
// (negative on the plain frame)
uniform bool uShadowPass;
uniform float uSeed;
// 0: draw on the window; 1: sum into the transparency buffers
uniform int uOitPass;

layout(location = 0) out vec4 fColor;
// A picking pass also reads the depth back, which OpenGL ES and WebGL cannot
// do from a depth buffer: it is written as a colour, 24 bits over three
// bytes. With a single draw buffer the write goes nowhere.
layout(location = 1) out vec4 fDepth;

vec4 packDepth(float d)
{
  float v = clamp(d, 0.0, 1.0) * 16777215.0;
  float r = floor(v / 65536.0);
  float g = floor((v - r * 65536.0) / 256.0);
  float b = floor(v - r * 65536.0 - g * 256.0);
  return vec4(r, g, b, 255.0) / 255.0;
}

// every fragment leaves through here: written as is on the window, added to
// the other fragments of the pixel in the transparency pass
void emit(vec4 c)
{
  if(uOitPass == 1) {
    // the weight of McGuire and Bavoil: the nearer and the more opaque, the
    // more the fragment counts. Their 1e8 scale cancels out in the division
    // at composite time, and a weight below 1 keeps the sum within a half
    // float.
    float w = clamp(pow(min(1.0, c.a * 10.0) + 0.01, 3.0) *
                    pow(1.0 - gl_FragCoord.z * 0.9, 3.0), 1e-4, 1.0);
    fColor = vec4(c.rgb * c.a, c.a) * w;
    // the light let through is a product over the fragments, but a buffer
    // can only sum: sum the logarithm here, exponentiate at composite time
    fDepth = vec4(log(max(1.0 - c.a, 1e-4)));
  }
  else {
    fColor = c;
    fDepth = packDepth(gl_FragCoord.z);
  }
}

// Where a fragment of normal n is looked up in the map of a light in the
// direction l: a texel or two away along the normal, more so at grazing
// angles, and a little nearer the light (the z), so that a surface does not
// shadow itself. z is set beyond 1 outside the map.
vec3 mapCoord(mat4 fromEye, vec3 n, vec3 l)
{
  float nl = clamp(dot(n, l), -1.0, 1.0);
  vec3 at = vEye + n * uShadowTexel * (1.0 + 2.0 * sqrt(1.0 - nl * nl));
  vec4 p = fromEye * vec4(at, 1.0);
  vec3 q = p.xyz / p.w;
  q.z -= 0.0005 + 0.0015 * (1.0 - max(nl, 0.0));
  if(q.x < 0.0 || q.x > 1.0 || q.y < 0.0 || q.y > 1.0) q.z = 2.0;
  return q;
}

// How much of the key light, and of the dome, reaches this fragment of
// normal n through its map: 1 outside the map or with nothing in front, 0 in
// full shade, filtered over 5x5 texels. One function per map: a sampler
// handed to a function as an argument is not something every driver gets
// right.
float keyLit(vec3 n)
{
  vec3 q = mapCoord(uShadowFromEye, n, uStudioLight);
  if(q.z > 1.0) return 1.0;
  vec2 texel = 1.0 / vec2(textureSize(uShadow, 0));
  float lit = 0.0;
  for(int i = -2; i <= 2; i++)
    for(int j = -2; j <= 2; j++)
      lit += texture(uShadow, vec3(q.xy + vec2(float(i), float(j)) * texel,
                                   q.z));
  return lit / 25.0;
}

float domeLit(vec3 n)
{
  vec3 q = mapCoord(uDomeFromEye, n, uDomeDir);
  if(q.z > 1.0) return 1.0;
  vec2 texel = 1.0 / vec2(textureSize(uDome, 0));
  float lit = 0.0;
  for(int i = -2; i <= 2; i++)
    for(int j = -2; j <= 2; j++)
      lit += texture(uDome, vec3(q.xy + vec2(float(i), float(j)) * texel,
                                 q.z));
  return lit / 25.0;
}

void main()
{
  for(int i = 0; i < 6; i++)
    if(vClip[i] < 0.0) discard;

  if(uShadowPass && vColor.a < 1.0) {
    // a transparent fragment casts a shadow in proportion to its opacity:
    // kept with that probability on the accumulated frames, and when at
    // least half opaque on the plain one
    if(uSeed < 0.0) {
      if(vColor.a < 0.5) discard;
    }
    else {
      float r = fract(sin(dot(gl_FragCoord.xy + vec2(uSeed),
                              vec2(12.9898, 78.233))) * 43758.5453);
      if(r > vColor.a) discard;
    }
  }

  if(uStipple) {
    int bit = int(mod(floor(vDash / float(uStippleFactor)), 16.0));
    if((uStipplePattern & (1 << bit)) == 0) discard;
  }

  // an image is the colour of what it covers, lit or not (GL_REPLACE)
  if(uTextured == 2) {
    emit(texture(uTexture, vTexCoord));
    return;
  }

  // a string is a picture of itself: the texture is the alpha of the colour
  float alpha = vColor.a;
  if(uTextured == 1) alpha *= texture(uTexture, vTexCoord).r;

  if(uShading == 2) {
    // the shadow catcher: a tint as opaque as the shade it is in, from the
    // key light and, once the dome is sampled, from the ambient occlusion
    vec3 nf = normalize(vNormal);
    float lit = uShadowOn ? keyLit(nf) : 1.0;
    float shade = 1.0 - lit;
    if(uDomeOn) shade = 1.0 - 0.6 * lit - 0.4 * domeLit(nf);
    emit(vec4(vColor.rgb, alpha * shade));
    return;
  }

  if(!uLighting) {
    emit(vec4(vColor.rgb, alpha));
    return;
  }

  // GL_NORMALIZE: the normals are made unit again after the transform
  vec3 n = normalize(vNormal);
  // GL_LIGHT_MODEL_TWO_SIDE: a back face is lit with its normal flipped
  if(uTwoSide && !gl_FrontFacing) n = -n;

  if(uShading == 1) {
    // studio: the light is computed in linear space, from a hemisphere
    // ambient (sky above, darker ground below, in eye space) and a wrapped
    // diffuse key light (the studio light, with light 0's colour) that casts
    // the shadow, with no specular; the result goes back to sRGB
    vec3 base = pow(vColor.rgb, vec3(2.2));
    vec3 key = uLightOn[0] ? uLightDiffuse[0] : vec3(1.0);
    float nl = dot(n, uStudioLight);
    float lit = uShadowOn ? keyLit(n) : 1.0;
    // the ground below, and the sky above: analytic on the first frame, and
    // from a dome direction of each frame afterwards (cosine weighted about
    // the up axis, so that a surface facing up gets 1 on average and a tilted
    // one (n.d)/(up.d)), which converges to the occluded sky
    float nu = dot(n, uStudioUp);
    vec3 ambient = vec3(0.25 * (0.5 - 0.5 * nu));
    if(uDomeOn) {
      float nd = dot(n, uDomeDir), ud = dot(uStudioUp, uDomeDir);
      float v = domeLit(n);
      ambient += vec3(0.55 * v * min(max(nd, 0.0) / max(ud, 0.05), 4.0));
    }
    else
      ambient += vec3(0.55 * (0.5 + 0.5 * nu));
    float d = clamp((nl + 0.5) / 1.5, 0.0, 1.0);
    vec3 c = base * (ambient + 0.6 * key * d * d * lit);
    emit(vec4(pow(min(c, vec3(1.0)), vec3(1.0 / 2.2)), alpha));
    return;
  }

  // GL_COLOR_MATERIAL on GL_AMBIENT_AND_DIFFUSE, and the default global
  // ambient of 0.2
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
      // infinite viewer: half vector against (0, 0, 1)
      vec3 h = normalize(l + vec3(0.0, 0.0, 1.0));
      c += uLightSpecular[i] * uSpecular * pow(max(dot(n, h), 0.0), uShininess);
    }
  }

  emit(vec4(min(c, vec3(1.0)), alpha));
}
)";

  // The composite program of the transparency pass: its own samplers, and no
  // vertices (three made out of gl_VertexID cover the window).
  const char *compositeVertexBody = R"(
void main()
{
  vec2 p = vec2((gl_VertexID == 1) ? 3.0 : -1.0,
                (gl_VertexID == 2) ? 3.0 : -1.0);
  gl_Position = vec4(p, 0.0, 1.0);
}
)";

  // what adds a frame to the accumulation buffer and puts the average back
  const char *blitFragmentBody = R"(
uniform sampler2D uTex;
uniform float uScale;
layout(location = 0) out vec4 fColor;

void main()
{
  fColor = texelFetch(uTex, ivec2(gl_FragCoord.xy), 0) * uScale;
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
  // the average colour of the fragments, laid over with their total coverage
  fColor = vec4(accum.rgb / max(accum.a, 1e-5), 1.0 - reveal);
}
)";

    GLuint _program = 0, _vao = 0;
    // buffers for client arrays, grown as needed and reused across frames
    GLuint _streamVertices = 0, _streamColors = 0, _streamNormals = 0;
    // and for the glyphs, the texture coordinates and the dashes
    GLuint _streamGlyphs = 0, _streamTex = 0, _streamDash = 0;
    // a 1x1 texture bound whenever no other is: a driver validates every
    // sampler at draw time, whether or not its branch is taken
    GLuint _noTexture = 0;
    // the shadow maps of the studio shading (the key light and the dome), and
    // the 1x1 depth texture bound in their place when there is none (the
    // samplers must always point at one)
    GLuint _shadowFbo[2] = {0, 0}, _shadowTex[2] = {0, 0}, _noShadow = 0;
    int _shadowSize[2] = {0, 0};
    GLint _shadowViewport[4] = {0, 0, 0, 0};
    int _shadowPass = -1;
    // what stands in for the window: 0, or the print target while there is
    // one
    GLuint _window = 0, _printFbo = 0, _printColor = 0, _printDepth = 0;
    // the accumulation of the studio frames: the sum, a copy of the window
    // to add to it, and the program that does both
    GLuint _accFbo = 0, _accTex = 0, _accCopy = 0, _blitProgram = 0;
    int _accWidth = 0, _accHeight = 0;
    GLint _uBlitTex = -1, _uBlitScale = -1;
    bool _blitTried = false;
    // the picking buffer and what it is made of
    GLuint _pickFbo = 0, _pickColorTex = 0, _pickDepthTex = 0, _pickDepthRb = 0;
    int _pickWidth = 0, _pickHeight = 0;
    bool _tried = false;

    // the transparency buffers, the composite program and whether that pass
    // is being drawn; the depth is a copy of the window's, so that opaque
    // geometry hides what is behind it
    GLuint _oitFbo = 0, _oitAccum = 0, _oitReveal = 0, _oitDepthRb = 0;
    int _oitWidth = 0, _oitHeight = 0;
    GLuint _oitProgram = 0;
    GLint _uAccum = -1, _uReveal = -1;
    bool _oitOn = false, _oitFailed = false, _oitTried = false;
    // the depth format the window's buffer can be copied into: it must match
    // exactly and cannot be queried
    GLenum _oitDepthFormat = 0;

    struct {
      GLint modelview, projection, normalMatrix, colorArray, color, pointSize;
      GLint alphaScale;
      GLint lighting, twoSide, specular, shininess, shading;
      GLint instanced, taper;
      GLint textured, texture;
      GLint stipple, stippleFactor, stipplePattern;
      GLint wideLine, lineWidth, viewport;
      GLint oitPass;
      // one location per array element, looked up at link time: asking by
      // name at every draw is costly on scenes of many small draws
      GLint clipPlane[6], clipOn[6];
      GLint studioLight, studioUp, shadowTexel, shadowOn, shadowFromEye, shadow;
      GLint domeOn, domeDir, domeFromEye, dome, shadowPass, seed;
      GLint lightPosition[6], lightAmbient[6], lightDiffuse[6];
      GLint lightSpecular[6], lightOn[6];
    } _u;

    // uniforms are set on the current program, and some setters are called
    // outside drawing (the lights, once a frame): make the program current
    // bind the 1x1 depth texture in place of shadow map `which', on unit
    // 2 + which
    void bindNoShadow(int which)
    {
      glApi::ActiveTexture(GL_TEXTURE0 + 2 + which);
      if(!_noShadow) {
        const GLuint one = 0xffffffff;
        glGenTextures(1, &_noShadow);
        glBindTexture(GL_TEXTURE_2D, _noShadow);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, 1, 1, 0,
                     GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, &one);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE,
                        GL_COMPARE_REF_TO_TEXTURE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
      }
      else
        glBindTexture(GL_TEXTURE_2D, _noShadow);
      glApi::ActiveTexture(GL_TEXTURE0);
    }

    bool ensure()
    {
      if(!_program) return false;
      glApi::UseProgram(_program);
      return true;
    }

    // location of element i of an array uniform
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
      // fixed attribute numbers, so that arrays can be bound without asking
      // the program
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
      _u.shading = glApi::GetUniformLocation(p, "uShading");
      _u.studioLight = glApi::GetUniformLocation(p, "uStudioLight");
      _u.studioUp = glApi::GetUniformLocation(p, "uStudioUp");
      _u.shadowTexel = glApi::GetUniformLocation(p, "uShadowTexel");
      _u.shadowOn = glApi::GetUniformLocation(p, "uShadowOn");
      _u.shadowFromEye = glApi::GetUniformLocation(p, "uShadowFromEye");
      _u.shadow = glApi::GetUniformLocation(p, "uShadow");
      _u.domeOn = glApi::GetUniformLocation(p, "uDomeOn");
      _u.domeDir = glApi::GetUniformLocation(p, "uDomeDir");
      _u.domeFromEye = glApi::GetUniformLocation(p, "uDomeFromEye");
      _u.dome = glApi::GetUniformLocation(p, "uDome");
      _u.shadowPass = glApi::GetUniformLocation(p, "uShadowPass");
      _u.seed = glApi::GetUniformLocation(p, "uSeed");
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
      for(int i = 0; i < 6; i++) {
        _u.clipPlane[i] = element("uClipPlane", i);
        _u.clipOn[i] = element("uClipOn", i);
        _u.lightPosition[i] = element("uLightPosition", i);
        _u.lightAmbient[i] = element("uLightAmbient", i);
        _u.lightDiffuse[i] = element("uLightDiffuse", i);
        _u.lightSpecular[i] = element("uLightSpecular", i);
        _u.lightOn[i] = element("uLightOn", i);
      }

      // a uniform starts at zero, and a zero alpha scale would draw nothing
      glApi::UseProgram(_program);
      // the shadow maps live on texture units 2 and 3
      glApi::Uniform1i(_u.shadow, 2);
      glApi::Uniform1i(_u.dome, 3);
      bindNoShadow(0);
      bindNoShadow(1);
      glApi::Uniform1f(_u.alphaScale, 1.f);

      // a core profile draws nothing without a vertex array object; one is
      // enough, its arrays are set at every draw
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
    // OpenGL ES always takes the point size from the shader, a desktop core
    // profile only if told to
    if(!glApi::isES()) glEnable(GL_PROGRAM_POINT_SIZE);
    return true;
  }

  void reset()
  {
    // the names belonged to a context that is gone: deleting them now would
    // delete names of the current one
    _program = _vao = 0;
    _streamVertices = _streamColors = _streamNormals = 0;
    _streamGlyphs = _streamTex = _streamDash = 0;
    _noTexture = 0;
    _shadowFbo[0] = _shadowFbo[1] = _shadowTex[0] = _shadowTex[1] = 0;
    _shadowSize[0] = _shadowSize[1] = 0;
    _noShadow = 0;
    _shadowPass = -1;
    _accFbo = _accTex = _accCopy = _blitProgram = 0;
    _accWidth = _accHeight = 0;
    _window = _printFbo = _printColor = _printDepth = 0;
    _uBlitTex = _uBlitScale = -1;
    _blitTried = false;
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

    // inverse transpose of the upper left 3x3 of the modelview, for
    // non-uniform scales; the shader normalizes afterwards
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
    glApi::Uniform4fv(_u.lightPosition[i], 1, p);
    glApi::Uniform3fv(_u.lightAmbient[i], 1, ambient ? ambient : black);
    glApi::Uniform3fv(_u.lightDiffuse[i], 1, diffuse ? diffuse : black);
    glApi::Uniform3fv(_u.lightSpecular[i], 1, specular ? specular : black);
    glApi::Uniform1i(_u.lightOn[i], 1);
  }

  void setLightOff(int i)
  {
    if(i < 0 || i > 5 || !ensure()) return;
    glApi::Uniform1i(_u.lightOn[i], 0);
  }

  void setMaterial(double shine, double shineExponent)
  {
    if(!ensure()) return;
    float s[3] = {(float)shine, (float)shine, (float)shine};
    glApi::Uniform3fv(_u.specular, 1, s);
    // the fixed function exponent is in [0, 128]
    glApi::Uniform1f(_u.shininess, (float)shineExponent);
  }

  void setShading(int model)
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.shading, model);
  }

  void setStudioLight(const double dir[3], const double up[3], double texel)
  {
    if(!ensure()) return;
    float d[3] = {(float)dir[0], (float)dir[1], (float)dir[2]};
    float u[3] = {(float)up[0], (float)up[1], (float)up[2]};
    glApi::Uniform3fv(_u.studioLight, 1, d);
    glApi::Uniform3fv(_u.studioUp, 1, u);
    glApi::Uniform1f(_u.shadowTexel, (float)texel);
  }

  void setDome(const double dir[3])
  {
    if(!ensure()) return;
    float d[3] = {(float)dir[0], (float)dir[1], (float)dir[2]};
    glApi::Uniform3fv(_u.domeDir, 1, d);
  }

  void setDomeOff()
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.domeOn, 0);
    bindNoShadow(1);
  }

  void setShadowOff()
  {
    if(!ensure()) return;
    glApi::Uniform1i(_u.shadowOn, 0);
    bindNoShadow(0);
    setDomeOff();
  }

  bool beginShadowPass(int which, int size, int sample)
  {
    if(which < 0 || which > 1 || size < 1 || _shadowPass >= 0) return false;
    if(!ensure() || !glApi::haveFramebufferObjects()) return false;
    GLuint &fbo = _shadowFbo[which], &tex = _shadowTex[which];
    if(fbo && _shadowSize[which] != size) {
      glApi::DeleteFramebuffers(1, &fbo);
      glDeleteTextures(1, &tex);
      fbo = tex = 0;
    }
    if(!fbo) {
      glApi::GenFramebuffers(1, &fbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, fbo);
      glGenTextures(1, &tex);
      glApi::ActiveTexture(GL_TEXTURE0 + 2 + which);
      glBindTexture(GL_TEXTURE_2D, tex);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, size, size, 0,
                   GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, nullptr);
      // linear filtering of a comparison is a 2x2 filter of the results
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE,
                      GL_COMPARE_REF_TO_TEXTURE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
      glApi::ActiveTexture(GL_TEXTURE0);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                                  GL_TEXTURE_2D, tex, 0);
      // depth only: no colour is written or read
      const GLenum none = GL_NONE;
      glApi::DrawBuffers(1, &none);
      glReadBuffer(GL_NONE);
      if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
         GL_FRAMEBUFFER_COMPLETE) {
        Msg::Warning("Could not make a shadow map: drawing without shadows");
        glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
        glApi::DeleteFramebuffers(1, &fbo);
        glDeleteTextures(1, &tex);
        fbo = tex = 0;
        return false;
      }
      _shadowSize[which] = size;
      Msg::Debug("Shadow map %d of %dx%d texels", which, size, size);
    }
    else
      glApi::BindFramebuffer(GL_FRAMEBUFFER, fbo);

    // the map is being written, so it must not be read
    glApi::Uniform1i(which ? _u.domeOn : _u.shadowOn, 0);
    bindNoShadow(which);
    glApi::Uniform1i(_u.shadowPass, 1);
    glApi::Uniform1f(_u.seed, sample > 0 ? 0.7318f * sample : -1.f);
    glGetIntegerv(GL_VIEWPORT, _shadowViewport);
    glViewport(0, 0, size, size);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glClear(GL_DEPTH_BUFFER_BIT);
    _shadowPass = which;
    return true;
  }

  void endShadowPass(int which, const double fromEye[16])
  {
    if(_shadowPass != which) return;
    _shadowPass = -1;
    glApi::Uniform1i(_u.shadowPass, 0);
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
    glViewport(_shadowViewport[0], _shadowViewport[1], _shadowViewport[2],
               _shadowViewport[3]);
    if(!fromEye) {
      if(which)
        setDomeOff();
      else {
        glApi::Uniform1i(_u.shadowOn, 0);
        bindNoShadow(0);
      }
      return;
    }
    glApi::ActiveTexture(GL_TEXTURE0 + 2 + which);
    glBindTexture(GL_TEXTURE_2D, _shadowTex[which]);
    glApi::ActiveTexture(GL_TEXTURE0);
    float m[16];
    for(int i = 0; i < 16; i++) m[i] = (float)fromEye[i];
    glApi::UniformMatrix4fv(which ? _u.domeFromEye : _u.shadowFromEye, 1,
                            GL_FALSE, m);
    glApi::Uniform1i(which ? _u.domeOn : _u.shadowOn, 1);
  }

  namespace {
    GLuint floatTarget(int width, int height, GLenum internal, GLenum format);

    bool buildBlit()
    {
      if(_blitTried) return _blitProgram != 0;
      _blitTried = true;
      GLuint vs = compile(GL_VERTEX_SHADER, prologue() + compositeVertexBody);
      if(!vs) return false;
      GLuint fs = compile(GL_FRAGMENT_SHADER, prologue() + blitFragmentBody);
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
        Msg::Warning("Could not link the accumulation program");
        glApi::DeleteProgram(p);
        return false;
      }
      _uBlitTex = glApi::GetUniformLocation(p, "uTex");
      _uBlitScale = glApi::GetUniformLocation(p, "uScale");
      _blitProgram = p;
      return true;
    }
  } // namespace

  bool accumulate(int width, int height, bool first, int count)
  {
    if(width < 1 || height < 1 || count < 1) return false;
    if(!ensure() || !glApi::haveFramebufferObjects() ||
       !glApi::haveFloatColorBuffers() || !buildBlit())
      return false;
    if(_accFbo && (_accWidth != width || _accHeight != height)) {
      glApi::DeleteFramebuffers(1, &_accFbo);
      glDeleteTextures(1, &_accTex);
      glDeleteTextures(1, &_accCopy);
      _accFbo = _accTex = _accCopy = 0;
    }
    glApi::ActiveTexture(GL_TEXTURE0);
    if(!_accFbo) {
      glApi::GenFramebuffers(1, &_accFbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _accFbo);
      _accTex = floatTarget(width, height, GL_RGBA16F, GL_RGBA);
      glApi::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                  GL_TEXTURE_2D, _accTex, 0);
      const GLenum buf = GL_COLOR_ATTACHMENT0;
      glApi::DrawBuffers(1, &buf);
      if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
         GL_FRAMEBUFFER_COMPLETE) {
        Msg::Warning("Could not make an accumulation buffer");
        glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
        glApi::DeleteFramebuffers(1, &_accFbo);
        glDeleteTextures(1, &_accTex);
        _accFbo = _accTex = 0;
        return false;
      }
      glGenTextures(1, &_accCopy);
      glBindTexture(GL_TEXTURE_2D, _accCopy);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, nullptr);
      _accWidth = width;
      _accHeight = height;
      first = true;
    }

    // the window into the copy
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
    glReadBuffer(_window ? GL_COLOR_ATTACHMENT0 : GL_BACK);
    glBindTexture(GL_TEXTURE_2D, _accCopy);
    glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, width, height);

    // what is changed below is put back: this runs in the middle of a frame,
    // and what is drawn afterwards expects the state it left
    GLint vp[4];
    GLfloat clear[4];
    GLboolean wasDepth = glIsEnabled(GL_DEPTH_TEST);
    GLboolean wasBlend = glIsEnabled(GL_BLEND);
    glGetIntegerv(GL_VIEWPORT, vp);
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clear);
    glViewport(0, 0, width, height);
    glDisable(GL_DEPTH_TEST);
    glApi::UseProgram(_blitProgram);
    glApi::BindVertexArray(_vao);
    // the vertices come from gl_VertexID; an attribute left enabled would
    // read a stale buffer
    for(int i = ATTRIB_VERTEX; i <= ATTRIB_COLORB; i++)
      glApi::DisableVertexAttribArray(i);
    glApi::Uniform1i(_uBlitTex, 0);

    // added to the sum
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _accFbo);
    if(first) {
      glClearColor(0.f, 0.f, 0.f, 0.f);
      glClear(GL_COLOR_BUFFER_BIT);
    }
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glApi::Uniform1f(_uBlitScale, 1.f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // and the average put back on the window
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
    glDisable(GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, _accTex);
    glApi::Uniform1f(_uBlitScale, 1.f / count);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glViewport(vp[0], vp[1], vp[2], vp[3]);
    glClearColor(clear[0], clear[1], clear[2], clear[3]);
    if(wasDepth) glEnable(GL_DEPTH_TEST);
    if(wasBlend) glEnable(GL_BLEND);
    glApi::UseProgram(_program);
    glApi::BindVertexArray(_vao);
    noTexture();
    return true;
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
    glApi::Uniform4fv(_u.clipPlane[i], 1, p);
    glApi::Uniform1i(_u.clipOn[i], 1);
  }

  void setClipPlaneOff(int i)
  {
    if(i < 0 || i > 5 || !ensure()) return;
    glApi::Uniform1i(_u.clipOn[i], 0);
  }

  // draw without texture, keeping the 1x1 one bound
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
    // a context with shaders but no instancing has no divisor to reset
    if(glApi::VertexAttribDivisor) glApi::VertexAttribDivisor(ATTRIB_DASH, 0);
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

    // both ends of a segment come from the same buffer at a stride of two
    // vertices, the far end one vertex further: one segment per instance
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
      // vertex arrays keep normals as bytes, the collector as floats
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

    // the glyphs, one per instance (divisor 1)
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

    // the texture (a string drawn as a picture of itself), with its
    // coordinates
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

      // depth tested, so that what is read back is what ended up in front
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
        glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
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
      // the three bytes the shader spread the depth over; the alpha tells a
      // pixel never drawn from a depth of zero
      unsigned int v = ((unsigned int)packed[4 * i] << 16) |
                       ((unsigned int)packed[4 * i + 1] << 8) |
                       (unsigned int)packed[4 * i + 2];
      depths[i] = packed[4 * i + 3] ? (float)(v / 16777215.) : 1.f;
    }
  }

  void releasePickBuffer()
  {
    if(!_pickFbo) return;
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
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
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
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

    // The two buffers plus a copy of the window's depth. The depth formats
    // must match exactly and the window's cannot be queried, so both are
    // tried.
    bool makeOitBuffers(int width, int height, GLenum depthFormat)
    {
      glApi::GenFramebuffers(1, &_oitFbo);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _oitFbo);

      // the weighted colours, and the light let through
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
      glApi::BindFramebuffer(GL_READ_FRAMEBUFFER, _window);
      glApi::BindFramebuffer(GL_DRAW_FRAMEBUFFER, _oitFbo);
      glApi::BlitFramebuffer(0, 0, width, height, 0, 0, width, height,
                             GL_DEPTH_BUFFER_BIT, GL_NEAREST);
      if(glGetError() == GL_NO_ERROR) return true;
      dropOitBuffers();
      return false;
    }
  } // namespace

  bool transparentPass() { return _oitOn; }

  bool beginPrintTarget(int width, int height)
  {
    if(width < 1 || height < 1 || _printFbo) return false;
    if(!ensure() || !glApi::haveFramebufferObjects()) return false;
    GLint maxSize = 0;
    glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &maxSize);
    if(width > maxSize || height > maxSize) {
      Msg::Warning("Picture of %dx%d pixels larger than the largest buffer "
                   "(%dx%d)", width, height, maxSize, maxSize);
      return false;
    }
    glApi::GenFramebuffers(1, &_printFbo);
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _printFbo);
    glApi::GenRenderbuffers(1, &_printColor);
    glApi::BindRenderbuffer(GL_RENDERBUFFER, _printColor);
    glApi::RenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
    glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                                   GL_RENDERBUFFER, _printColor);
    glApi::GenRenderbuffers(1, &_printDepth);
    glApi::BindRenderbuffer(GL_RENDERBUFFER, _printDepth);
    glApi::RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width,
                               height);
    glApi::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                                   GL_RENDERBUFFER, _printDepth);
    const GLenum buf = GL_COLOR_ATTACHMENT0;
    glApi::DrawBuffers(1, &buf);
    if(glApi::CheckFramebufferStatus(GL_FRAMEBUFFER) !=
       GL_FRAMEBUFFER_COMPLETE) {
      Msg::Warning("Could not make a buffer of %dx%d pixels to print into",
                   width, height);
      glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
      glApi::DeleteFramebuffers(1, &_printFbo);
      glApi::DeleteRenderbuffers(1, &_printColor);
      glApi::DeleteRenderbuffers(1, &_printDepth);
      _printFbo = _printColor = _printDepth = 0;
      return false;
    }
    _window = _printFbo;
    // the transparency buffers were made to match the window
    dropOitBuffers();
    _oitDepthFormat = 0;
    Msg::Debug("Printing into a %dx%d buffer", width, height);
    return true;
  }

  void readPrintTarget(int width, int height, GLenum format, GLenum type,
                       void *pixels)
  {
    if(!_printFbo) return;
    glApi::BindFramebuffer(GL_FRAMEBUFFER, _printFbo);
    glReadBuffer(GL_COLOR_ATTACHMENT0);
    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, width, height, format, type, pixels);
  }

  void endPrintTarget()
  {
    if(!_printFbo) return;
    _window = 0;
    glApi::BindFramebuffer(GL_FRAMEBUFFER, 0);
    glApi::DeleteFramebuffers(1, &_printFbo);
    glApi::DeleteRenderbuffers(1, &_printColor);
    glApi::DeleteRenderbuffers(1, &_printDepth);
    _printFbo = _printColor = _printDepth = 0;
    dropOitBuffers();
    _oitDepthFormat = 0;
  }

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
      glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
      return false;
    }

    glApi::BindFramebuffer(GL_FRAMEBUFFER, _oitFbo);
    const GLenum bufs[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT0 + 1};
    glApi::DrawBuffers(2, bufs);

    // nothing summed yet, and a summed log of zero lets all light through;
    // the copied depth is left alone
    GLfloat clear[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clear);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(clear[0], clear[1], clear[2], clear[3]);

    // every fragment is added, none hides another
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

    glApi::BindFramebuffer(GL_FRAMEBUFFER, _window);
    glDepthMask(GL_TRUE);

    glApi::UseProgram(_oitProgram);
    glApi::BindVertexArray(_vao);
    // the vertices come from gl_VertexID; an attribute left enabled would
    // read a stale buffer
    for(int i = ATTRIB_VERTEX; i <= ATTRIB_COLORB; i++)
      glApi::DisableVertexAttribArray(i);

    glApi::ActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _oitAccum);
    glApi::Uniform1i(_uAccum, 0);
    glApi::ActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, _oitReveal);
    glApi::Uniform1i(_uReveal, 1);
    glApi::ActiveTexture(GL_TEXTURE0);

    // the averaged colour, laid over the window with the fragments' coverage
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    // the window's alpha (kept by saved images) must end up as covered as the
    // pixel is, which a plain SRC_ALPHA blend would square: blend it apart
    if(glApi::BlendFuncSeparate)
      glApi::BlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE,
                               GL_ONE_MINUS_SRC_ALPHA);
    else
      // the window's alpha comes out squared, as the ordinary blend always
      // did
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glApi::UseProgram(_program);
  }
} // namespace glShader
