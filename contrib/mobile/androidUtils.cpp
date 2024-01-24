#undef NDEBUG

#ifndef NDEBUG
#include <android/log.h>
#define LOG_TAG "Gmsh"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#include <dlfcn.h>

#include <gmsh/GmshGlobal.h>
#include <gmsh/GmshConfig.h>
#include <gmsh/GmshVersion.h>
#include <gmsh/GModel.h>
#include <gmsh/onelab.h>
#include <gmsh/onelabUtils.h>
#include <gmsh/Context.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

#include <getdp/GetDPConfig.h>
#include <getdp/GetDPVersion.h>

#include "androidUtils.h"
#include "drawContext.h"

extern "C" {
static JavaVM *gJavaVM;
static jobject gCallbackObject = NULL;
};

class MobileMessage : public GmshMessage {
public:
  MobileMessage() {}
  ~MobileMessage() {}
  void operator()(std::string level, std::string message)
  {
    if(level == "Error") {
#ifndef NDEBUG
      LOGE("Error:\t%s", message.c_str());
#endif
      JNIEnv *env;
      if(gJavaVM->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) !=
           JNI_OK ||
         !gCallbackObject || (gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
        return;
      jstring jstr = env->NewStringUTF(message.c_str());
      jclass jClass = env->FindClass("org/geuz/onelab/Gmsh");
      if(jClass == 0 || env->ExceptionCheck()) return;
      jmethodID mid =
        env->GetMethodID(jClass, "ShowPopup", "(Ljava/lang/String;)V");
      if(mid == 0 || env->ExceptionCheck()) return;
      env->CallVoidMethod(gCallbackObject, mid, jstr);
      env->DeleteLocalRef(jstr);
      env->DeleteLocalRef(jClass);
      return;
    }
    else if(level == "Progress") {
      JNIEnv *env;
      if(gJavaVM->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) !=
           JNI_OK ||
         !gCallbackObject || (gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
        return;
      jstring jstr = env->NewStringUTF(message.c_str());
      jclass jClass = env->FindClass("org/geuz/onelab/Gmsh");
      if(jClass == 0 || env->ExceptionCheck()) return;
      jmethodID mid =
        env->GetMethodID(jClass, "SetLoading", "(Ljava/lang/String;)V");
      if(mid == 0 || env->ExceptionCheck()) return;
      env->CallVoidMethod(gCallbackObject, mid, jstr);
      env->DeleteLocalRef(jstr);
      env->DeleteLocalRef(jClass);
      return;
    }
    else if(level == "RequestRender") {
      requestRender();
      return;
    }
#ifndef NDEBUG
    LOGI("%s:\t%s", level.c_str(), message.c_str());
#endif
  }
};

void requestRender()
{
  JNIEnv *env;
  if(gJavaVM->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) !=
       JNI_OK ||
     !gCallbackObject || (gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
    return;
  jclass jClass = env->FindClass("org/geuz/onelab/Gmsh");
  if(jClass == 0 || env->ExceptionCheck()) return;
  jmethodID mid = env->GetMethodID(jClass, "RequestRender", "()V");
  if(mid == 0 || env->ExceptionCheck()) return;
  env->CallVoidMethod(gCallbackObject, mid);
  env->DeleteLocalRef(jClass);
}

void getBitmapFromString(const char *text, int textsize, unsigned char **map,
                         int *height, int *width, int *realWidth)
{
  JNIEnv *env;
  if(gJavaVM->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) !=
       JNI_OK ||
     !gCallbackObject || (gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
    return;
  jclass jClass = env->FindClass("org/geuz/onelab/StringTexture");
  if(jClass == 0 || env->ExceptionCheck()) return;
  jstring jtext = env->NewStringUTF(text);
  jmethodID mid = env->GetStaticMethodID(jClass, "getHeightFromString",
                                         "(Ljava/lang/String;I)I");
  if(mid == 0 || env->ExceptionCheck()) return;
  *height = env->CallStaticIntMethod(jClass, mid, jtext, textsize);
  mid = env->GetStaticMethodID(jClass, "getWidthFromString",
                               "(Ljava/lang/String;I)I");
  if(mid == 0 || env->ExceptionCheck()) return;
  *width = env->CallStaticIntMethod(jClass, mid, jtext, textsize);
  if(realWidth != NULL) {
    mid = env->GetStaticMethodID(jClass, "getRealWidthFromString",
                                 "(Ljava/lang/String;I)I");
    if(mid == 0 || env->ExceptionCheck()) return;
    *realWidth = env->CallStaticIntMethod(jClass, mid, jtext, textsize);
  }
  mid = env->GetStaticMethodID(jClass, "getBytesFromString",
                               "(Ljava/lang/String;I)[B");
  if(mid == 0 || env->ExceptionCheck()) return;
  jobject jbuffer = env->CallStaticObjectMethod(jClass, mid, jtext, textsize);
  jbyteArray *jarray = reinterpret_cast<jbyteArray *>(&jbuffer);
  int ms = (*height) * (*width);
  if(ms) {
    *map = (unsigned char *)malloc(ms);
    env->GetByteArrayRegion(*jarray, 0, ms, (jbyte *)*map);
  }
  env->DeleteLocalRef(jClass);
  env->DeleteLocalRef(jtext);
}

extern "C" {
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
  gJavaVM = vm;
  return JNI_VERSION_1_6;
}
JNIEXPORT jlong JNICALL Java_org_geuz_onelab_Gmsh_init(JNIEnv *env, jobject obj,
                                                       jfloat fontFactor)
{
  if(gCallbackObject != NULL) env->DeleteGlobalRef(gCallbackObject);
  gCallbackObject = env->NewGlobalRef(obj);
  gJavaVM->GetEnv((void **)&env, JNI_VERSION_1_6);
  Msg::SetCallback(new MobileMessage());
  return reinterpret_cast<jlong>(new drawContext(fontFactor));
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_loadFile(JNIEnv *env,
                                                          jobject obj,
                                                          jlong jptr,
                                                          jstring jname)
{
  const char *filename = env->GetStringUTFChars(jname, NULL);
  ((drawContext *)jptr)->load(filename);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_initView(JNIEnv *env,
                                                          jobject obj,
                                                          jlong jptr, jint w,
                                                          jint h)
{
  ((drawContext *)jptr)->initView(w, h);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_drawView(JNIEnv *env,
                                                          jobject obj,
                                                          jlong jptr)
{
  ((drawContext *)jptr)->drawView();
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_eventHandler(
  JNIEnv *env, jobject obj, jlong jptr, jint jevent, jfloat jx, jfloat jy)
{
  ((drawContext *)jptr)->eventHandler(jevent, jx, jy);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setStringOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jstring v, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(v, NULL);
  const std::string value(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(v, tmp);
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  std::string category(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(c, tmp);
  GmshSetStringOption(category, name, value, (int)idx);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setDoubleOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jdouble v, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  const std::string category(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(c, tmp);
  GmshSetNumberOption(category, name, (double)v, (int)idx);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setIntegerOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jint v, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  const std::string category(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(c, tmp);
  GmshSetColorOption(category, name, (unsigned int)v, (int)idx);
}
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getStringOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  const std::string category(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(c, tmp);
  std::string value;
  value = GmshGetStringOption(category, name, (int)idx);
  return env->NewStringUTF(value.c_str());
}
JNIEXPORT jdouble JNICALL Java_org_geuz_onelab_Gmsh_getDoubleOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  const std::string category(tmp, strlen(tmp));
  double value = GmshGetNumberOption(category, name, (int)idx);
  return value;
}
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_getIntegerOption(
  JNIEnv *env, jobject obj, jstring c, jstring n, jint idx)
{
  const char *tmp;
  tmp = env->GetStringUTFChars(n, NULL);
  const std::string name(tmp, strlen(tmp));
  env->ReleaseStringUTFChars(n, tmp);
  tmp = env->GetStringUTFChars(c, NULL);
  const std::string category(tmp, strlen(tmp));
  unsigned int value = GmshGetColorOption(category, name, (int)idx);
  return value;
}
JNIEXPORT jobjectArray JNICALL Java_org_geuz_onelab_Gmsh_getParams(JNIEnv *env,
                                                                   jobject obj)
{
  jclass stringClass = env->FindClass("java/lang/String");
  std::vector<std::string> tmp = onelab::server::instance()->toChar();
  for(unsigned int i = 0; i < tmp.size(); i++)
    for(unsigned int j = 0; j < tmp[i].size(); j++)
      if(tmp[i][j] == '\0') tmp[i][j] = 0x03;
  jobjectArray params = env->NewObjectArray(tmp.size(), stringClass, 0);
  for(int i = 0; i < tmp.size(); i++) {
    jstring s = env->NewStringUTF(tmp[i].c_str());
    env->SetObjectArrayElement(params, i, s);
    env->DeleteLocalRef(s);
  }
  return params;
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setParam(
  JNIEnv *env, jobject obj, jstring jtype, jstring jname, jstring jvalue)
{
  const char *type = env->GetStringUTFChars(jtype, NULL);
  const char *name = env->GetStringUTFChars(jname, NULL);
  const char *value = env->GetStringUTFChars(jvalue, NULL);
  if(strcmp(type, "ParameterNumber") == 0) {
    std::vector<onelab::number> s;
    if(onelab::server::instance()->get(s, name)) {
      s[0].setValue(atof(value));
      onelab::server::instance()->set(s[0]);
    }
  }
  else if(strcmp(type, "ParameterString") == 0) {
    std::vector<onelab::string> s;
    if(onelab::server::instance()->get(s, name)) {
      s[0].setValue(value);
      onelab::server::instance()->set(s[0]);
    }
  }
}

JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_onelabCB(JNIEnv *env,
                                                          jobject obj,
                                                          jstring jaction)
{
  const char *action = env->GetStringUTFChars(jaction, NULL);
  return onelab_cb(action);
}

JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_numberOfAnimation(JNIEnv *,
                                                                   jobject)
{
  return number_of_animation();
}
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_animationNext(JNIEnv *,
                                                               jobject)
{
  return animation_next();
}
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_animationPrev(JNIEnv *,
                                                               jobject)
{
  return animation_prev();
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setAnimation(JNIEnv *, jobject,
                                                              jint animation)
{
  set_animation(animation);
}
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getAboutGmsh(JNIEnv *env,
                                                                 jclass c)
{
  std::ostringstream sstream;
  sstream << "<center><h3>Gmsh</h3>"
          << "Version " << GMSH_VERSION << " "
          << "(<i>Build date:</i> " << GMSH_DATE << ")"
          << "<p>Copyright (C) 1997-2024 Christophe Geuzaine and "
             "Jean-Fran&ccedil;ois Remacle</p>"
          << "<p><a href=\"https://gmsh.info/CREDITS.txt\">Credits</a> "
          << "and <a href=\"https://gmsh.info/LICENSE.txt\">licensing "
             "information</a></p>"
          << "<p><i>Build options:</i> " << GMSH_CONFIG_OPTIONS << "</p>"
          << "<p>Visit <a href=\"https://gmsh.info\">https://gmsh.info</a> for "
             "more information</p></center>";
  return env->NewStringUTF(sstream.str().c_str());
}
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getAboutGetDP(JNIEnv *env,
                                                                  jclass c)
{
  std::ostringstream sstream;
  sstream
    << "<center><h3>GetDP</h3>"
    << "Version " << GETDP_VERSION << " "
    << "(<i>Build date:</i> " << GETDP_DATE << ")"
    << "<p>Copyright (C) 1997-2024 Patrick Dular and Christophe "
       "Geuzaine, University of Li&egrave;ge</p>"
    << "<p><a href=\"https://getdp.info/CREDITS.txt\">Credits</a> "
    << "and <a href=\"https://getdp.info/LICENSE.txt\">licensing "
       "information</a></p>"
    << "<p><i>Build options:</i> " << GETDP_CONFIG_OPTIONS << "</p>"
    << "<p>Visit <a href=\"https://getdp.info\">https://getdp.info</a> for "
       "more information</p></center>";
  return env->NewStringUTF(sstream.str().c_str());
}
}
