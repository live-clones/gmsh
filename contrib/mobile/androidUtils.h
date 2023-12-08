#ifndef ONELAB_ANDROID_UTILS_H
#define ONELAB_ANDROID_UTILS_H

#include <jni.h>

void requestRender();

void getBitmapFromString(const char *text, int textsize, unsigned char **map,
                         int *height, int *width, int *realWidth = NULL);

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL Java_org_geuz_onelab_Gmsh_init(JNIEnv *, jobject,
                                                       jfloat);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_loadFile(JNIEnv *, jobject,
                                                          jlong, jstring);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_initView(JNIEnv *, jobject,
                                                          jlong, jint, jint);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_drawView(JNIEnv *, jobject,
                                                          jlong);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_eventHandler(JNIEnv *, jobject,
                                                              jlong, jint,
                                                              jfloat, jfloat);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setStringOption(
  JNIEnv *, jobject, jstring, jstring, jstring, jint);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setDoubleOption(
  JNIEnv *, jobject, jstring, jstring, jdouble, jint);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setIntegerOption(
  JNIEnv *, jobject, jstring, jstring, jint, jint);
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getStringOption(
  JNIEnv *, jobject, jstring, jstring, jint);
JNIEXPORT jdouble JNICALL Java_org_geuz_onelab_Gmsh_getDoubleOption(
  JNIEnv *, jobject, jstring, jstring, jint);
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_getIntegerOption(
  JNIEnv *, jobject, jstring, jstring, jint);
JNIEXPORT jobjectArray JNICALL Java_org_geuz_onelab_Gmsh_getParams(JNIEnv *,
                                                                   jobject);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setParam(JNIEnv *, jobject,
                                                          jstring, jstring,
                                                          jstring);
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_onelabCB(JNIEnv *, jobject,
                                                          jstring);
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_numberOfAnimation(JNIEnv *,
                                                                   jobject);
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_animationNext(JNIEnv *,
                                                               jobject);
JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_animationPrev(JNIEnv *,
                                                               jobject);
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setAnimation(JNIEnv *, jobject,
                                                              jint);
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getAboutGmsh(JNIEnv *,
                                                                 jclass);
JNIEXPORT jstring JNICALL Java_org_geuz_onelab_Gmsh_getAboutGetDP(JNIEnv *,
                                                                  jclass);

#ifdef __cplusplus
}
#endif

#endif
