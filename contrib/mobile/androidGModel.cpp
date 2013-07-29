#include <android/log.h>
#include <dlfcn.h>

#define  LOG_TAG    "Gmsh"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include <gmsh/GModel.h>
#include <gmsh/onelab.h>
#include <gmsh/onelabUtils.h>
#include <gmsh/Context.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/PViewOptions.h>

#include "androidGModel.h"
#include "drawContext.h"

onelab::server *getOnelab() {return onelab::server::instance();}
extern "C"
{
static JavaVM *gJavaVM;
static JNIEnv *env;
static jobject gCallbackObject = NULL;
};

class MobileMessage : public GmshMessage
{
	private:
	public:
	MobileMessage(){}
	~MobileMessage(){}
	void operator()(std::string level, std::string message)
	{
		if(level == "Error")
		{
	 		LOGE("%s", message.c_str());
			if(message.size() <= 26 || message.substr(message.size()-25,25) != "check the log for details")
				return;
			if(!gCallbackObject)
				return;
			if ((gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
				return;
			jstring jstr = env->NewStringUTF(message.c_str());
			jclass jClass = env->FindClass("org/geuz/onelab/Gmsh"); 
			if(jClass == 0)
				return;
			jmethodID mid = env->GetMethodID(jClass, "ShowPopup", "(Ljava/lang/String;)V");
			if (mid == 0)
				return;
			env->CallVoidMethod(gCallbackObject, mid, jstr);
			env->DeleteLocalRef(jstr);
			env->DeleteLocalRef(jClass);
			return;
		}
		else if(level == "Progress")
		{
			if(!gCallbackObject)
				return;
			if ((gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
				return;
			jstring jstr = env->NewStringUTF(message.c_str());
			jclass jClass = env->FindClass("org/geuz/onelab/Gmsh"); 
			if(jClass == 0)
				return;
			jmethodID mid = env->GetMethodID(jClass, "SetLoading", "(Ljava/lang/String;)V");
			if (mid == 0)
				return;
			env->CallVoidMethod(gCallbackObject, mid, jstr);
			env->DeleteLocalRef(jstr);
			env->DeleteLocalRef(jClass);
			return;
		}
		else if(level == "RequestRender")
		{
			requestRender();
			return;
		}
	 	LOGI("%s:\t%s", level.c_str(), message.c_str());
	}
};

void requestRender()
{
	if(!gCallbackObject)
		return;
	if ((gJavaVM->AttachCurrentThread(&env, NULL)) < 0)
		return;
	jclass jClass = env->FindClass("org/geuz/onelab/Gmsh"); 
	if(jClass == 0)
		return;
	jmethodID mid = env->GetMethodID(jClass, "RequestRender", "()V");
	if (mid == 0)
		return;
	env->CallVoidMethod(gCallbackObject, mid);
	env->DeleteLocalRef(jClass);
}

void getBitmapFromString(const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth)
{
	if(!gCallbackObject || (gJavaVM->AttachCurrentThread(&env, NULL)) < 0) return;
	jclass jClass = env->FindClass("org/geuz/onelab/StringTexture"); 
	if(jClass == 0)
		return;
	jstring jtext = env->NewStringUTF(text);
	jmethodID mid = env->GetStaticMethodID(jClass, "getHeightFromString", "(Ljava/lang/String;I)I");
	*height = env->CallIntMethod(gCallbackObject, mid, jtext, textsize);
	mid = env->GetStaticMethodID(jClass, "getWidthFromString", "(Ljava/lang/String;I)I");
	*width = env->CallIntMethod(gCallbackObject, mid, jtext, textsize);
	if(realWidth != NULL){
		mid = env->GetStaticMethodID(jClass, "getRealWidthFromString", "(Ljava/lang/String;I)I");
		*realWidth = env->CallIntMethod(gCallbackObject, mid, jtext, textsize);
	}
	mid = env->GetStaticMethodID(jClass, "getBytesFromString", "(Ljava/lang/String;I)[B");
	jobject jbuffer = env->CallObjectMethod(gCallbackObject, mid, jtext, textsize);
	jbyteArray *jarray = reinterpret_cast<jbyteArray*>(&jbuffer);
	*map = (unsigned char *) malloc((*height)*(*width));
	env->GetByteArrayRegion(*jarray, 0, (*height)*(*width), (jbyte*)*map);
	env->DeleteLocalRef(jClass);
}

extern "C" {
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	gJavaVM = vm;
	return JNI_VERSION_1_6;
}
JNIEXPORT jlong JNICALL Java_org_geuz_onelab_Gmsh_init
  (JNIEnv *env, jobject obj, jstring jname)
{
	gCallbackObject = env->NewGlobalRef(obj);
	gJavaVM->GetEnv((void**)&env, JNI_VERSION_1_6);
	Msg::SetCallback(new MobileMessage());
	
	const char*  name = env->GetStringUTFChars(jname, NULL);
	return reinterpret_cast<jlong>(new drawContext());
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_loadFile
  (JNIEnv *env, jobject obj, jlong jptr, jstring jname)
{
	const char*  filename = env->GetStringUTFChars(jname, NULL);
	((drawContext *)jptr)->load(filename);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_initView
  (JNIEnv *env, jobject obj, jlong jptr, jint w, jint h)
{
	((drawContext *)jptr)->initView(w,h);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_drawView
  (JNIEnv *env, jobject obj, jlong jptr)
{
	((drawContext *)jptr)->drawView();
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_eventHandler
  (JNIEnv *env, jobject obj, jlong jptr, jint jevent, jfloat jx, jfloat jy)
{
	((drawContext *)jptr)->eventHandler(jevent, jx, jy);
}
JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setShow
  (JNIEnv *env, jobject obj, jlong jptr, jstring jwhat, jboolean value)
{
	const char*  what = env->GetStringUTFChars(jwhat, NULL);
	if(strcmp(what, "mesh") == 0)
		((drawContext *)jptr)->showMesh(value);
	else if(strcmp(what, "geom") == 0)
		((drawContext *)jptr)->showGeom(value);
}
JNIEXPORT jlong JNICALL Java_org_geuz_onelab_Gmsh_getOnelabInstance
  (JNIEnv *env , jobject obj)
{
	return reinterpret_cast<jlong>(getOnelab());
}

JNIEXPORT jobjectArray JNICALL Java_org_geuz_onelab_Gmsh_getParams
  (JNIEnv *env, jobject obj)
{
	jclass stringClass = env->FindClass( "java/lang/String" );
	std::vector<std::string> tmp =  onelab::server::instance()->toChar();
	for(unsigned int i=0;i<tmp.size();i++)
		for(unsigned int j=0; j<tmp[i].size();j++)
			if(tmp[i][j] == '\0') tmp[i][j] = '\n';
	jobjectArray params = env->NewObjectArray(tmp.size(), stringClass, 0);
	for(int i=0; i<tmp.size();i++){
		jstring s = env->NewStringUTF(tmp[i].c_str());
		env->SetObjectArrayElement(params, i, s);
	}
	return params;
}

JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_setParam
  (JNIEnv *env, jobject obj, jstring jtype, jstring jname, jstring jvalue)
{
	const char *type = env->GetStringUTFChars(jtype, NULL);
	const char *name = env->GetStringUTFChars(jname, NULL);
	const char *value = env->GetStringUTFChars(jvalue, NULL);
	// Get the original param and then change the value
	if(strcmp(type,"ParameterNumber") == 0){
		std::vector<onelab::number> s;
		if(onelab::server::instance()->get(s,  name)) s[0].setValue(atof(value));
		onelab::server::instance()->set(s[0]);
	}
	else if(strcmp(type,"ParameterString") == 0){
		std::vector<onelab::string> s;
		if(onelab::server::instance()->get(s,  name)) s[0].setValue(value);
		onelab::server::instance()->set(s[0]);
	}
}

JNIEXPORT jobjectArray JNICALL Java_org_geuz_onelab_Gmsh_getPView
  (JNIEnv *env, jobject obj)
{
	jclass stringClass = env->FindClass( "java/lang/String" );
	jobjectArray jPView = env->NewObjectArray(PView::list.size(), stringClass, 0);
	for(unsigned int i = 0; i < PView::list.size(); i++){
		std::ostringstream sstream;
		sstream	<< PView::list[i]->getData()->getName().c_str()
			<< "\n" <<  PView::list[i]->getOptions()->intervalsType
			<< "\n" << ((PView::list[i]->getOptions()->visible) ? 1 : 0)
			<< "\n"  << PView::list[i]->getOptions()->nbIso;
		jstring s = env->NewStringUTF(sstream.str().c_str());
		env->SetObjectArrayElement(jPView, i, s);
	}
	return jPView;
}

JNIEXPORT void JNICALL Java_org_geuz_onelab_Gmsh_setPView
  (JNIEnv *env, jobject, jint pos, jint intervalsType, jint visible, jint nIntervals)
{
	if(intervalsType > 0 && intervalsType < 4) PView::list[pos]->getOptions()->intervalsType = intervalsType;
	if(visible >= 0) PView::list[pos]->getOptions()->visible = visible;
	if(nIntervals > 0) PView::list[pos]->getOptions()->nbIso = nIntervals;
	PView::list[pos]->setChanged(true);
}

JNIEXPORT jint JNICALL Java_org_geuz_onelab_Gmsh_onelabCB
  (JNIEnv *env, jobject obj, jstring jaction)
{
	const char*  action = env->GetStringUTFChars(jaction, NULL);
	return onelab_cb(action);
}
}
