// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <vector>

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
out float vClip[6];

void main()
{
  vec4 eye = uModelview * vec4(aVertex, 1.0);
  vEye = eye.xyz;
  vNormal = uNormalMatrix * aNormal;
  vColor = uColorArray ? aColor : uColor;
  // the planes are in eye coordinates, as glClipPlane() left them once the
  // modelview it was given had been applied
  for(int i = 0; i < 6; i++)
    vClip[i] = uClipOn[i] ? dot(uClipPlane[i], vec4(eye.xyz, 1.0)) : 1.0;
  gl_PointSize = uPointSize;
  gl_Position = uProjection * eye;
}
)";

    const char *fragmentBody = R"(
in vec3 vEye;
in vec3 vNormal;
in vec4 vColor;
in float vClip[6];

uniform bool uLighting;
uniform bool uTwoSide;
uniform vec4 uLightPosition[6];
uniform vec3 uLightAmbient[6];
uniform vec3 uLightDiffuse[6];
uniform vec3 uLightSpecular[6];
uniform bool uLightOn[6];
uniform vec3 uSpecular;
uniform float uShininess;

out vec4 fColor;

void main()
{
  for(int i = 0; i < 6; i++)
    if(vClip[i] < 0.0) discard;

  if(!uLighting) {
    fColor = vColor;
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

  fColor = vec4(min(c, vec3(1.0)), vColor.a);
}
)";

    GLuint _program = 0, _vao = 0;
    bool _tried = false;

    struct {
      GLint modelview, projection, normalMatrix, colorArray, color, pointSize;
      GLint clipPlane, clipOn;
      GLint lighting, twoSide, specular, shininess;
      GLint lightPosition, lightAmbient, lightDiffuse, lightSpecular, lightOn;
    } _u;

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
    return true;
  }

  void reset()
  {
    // the program and the array object belonged to a context that is gone;
    // deleting them now would be deleting names in whichever context is
    // current, which are not ours
    _program = _vao = 0;
    _tried = false;
  }

  void setMatrices(const double modelview[16], const double projection[16])
  {
    if(!_program) return;
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
    if(!_program || i < 0 || i > 5) return;
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
    if(!_program || i < 0 || i > 5) return;
    glApi::Uniform1i(element("uLightOn", i), 0);
  }

  void setMaterial(double shine, double shineExponent)
  {
    if(!_program) return;
    float s[3] = {(float)shine, (float)shine, (float)shine};
    glApi::Uniform3fv(_u.specular, 1, s);
    // the fixed function exponent is in [0, 128]
    glApi::Uniform1f(_u.shininess, (float)shineExponent);
  }

  void setLighting(bool on, bool twoSide)
  {
    if(!_program) return;
    glApi::Uniform1i(_u.lighting, on ? 1 : 0);
    glApi::Uniform1i(_u.twoSide, twoSide ? 1 : 0);
  }

  void setClipPlane(int i, const double plane[4])
  {
    if(!_program || i < 0 || i > 5) return;
    float p[4] = {(float)plane[0], (float)plane[1], (float)plane[2],
                  (float)plane[3]};
    glApi::Uniform4fv(element("uClipPlane", i), 1, p);
    glApi::Uniform1i(element("uClipOn", i), 1);
  }

  void setClipPlaneOff(int i)
  {
    if(!_program || i < 0 || i > 5) return;
    glApi::Uniform1i(element("uClipOn", i), 0);
  }

  void setColorArray(bool on)
  {
    if(!_program) return;
    glApi::Uniform1i(_u.colorArray, on ? 1 : 0);
  }

  void setColor(const unsigned char color[4])
  {
    if(!_program) return;
    float c[4] = {color[0] / 255.f, color[1] / 255.f, color[2] / 255.f,
                  color[3] / 255.f};
    glApi::Uniform4fv(_u.color, 1, c);
  }

  void setPointSize(double size)
  {
    if(!_program) return;
    glApi::Uniform1f(_u.pointSize, (float)size);
  }
} // namespace glShader
