#include <iostream>
#include "com_example_demo_better_Framework.h"

/*
 * Class:     com_example_demo_better_Framework
 * Method:    whl
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_demo_better_Framework_whl
  (JNIEnv *env, jobject, jstring name_obj)
  {
        jclass str_cls = env->GetObjectClass(name_obj);
        jstring encode = env->NewStringUTF("UTF-8");
        //(Ljava/lang/String;)[B　开头的Ｌ表示后面表示的是一个类　括号里面放置getBytes函数的参数，括号后面表示返回类型为bytes数组
        //多个类参数有;隔开，如(Ljava/lang/String;Ljava/lang/String;)I.表示 int Func(String,String)
        //多个简单参数直接跟着写, (II)V 表示 void Func(int, int);
        //(ILjava/lang/String;)V　输入一个int,一个String,返回void
        jmethodID get_bytes_mid = env->GetMethodID(str_cls, "getBytes", "(Ljava/lang/String;)[B");
        
        jbyteArray name_bytes = (jbyteArray)env->CallObjectMethod(name_obj, get_bytes_mid, encode);
        jsize name_bytes_len = (jsize)env->GetArrayLength(name_bytes);
        bool need_copy = false;
        jbyte *name_ptr = (jbyte*)env->GetByteArrayElements(name_bytes, (jboolean*)&need_copy);
        std::cout << "receviced: " << std::string((char*)name_ptr, (char*)name_ptr + int(name_bytes_len)) << std::endl;
        env->ReleaseByteArrayElements(name_bytes, name_ptr, 0);
        // env->DeleteLocalRef(name_obj);

        return env->NewStringUTF("Java_com_example_demo_better_Framework_whl");
  }

/*
 * Class:     com_example_demo_better_Framework
 * Method:    create
 * Signature: ()Lcom/example/demo/domain/Camera;
 */
JNIEXPORT jobject JNICALL Java_com_example_demo_better_Framework_create
  (JNIEnv *env, jobject)
  {
        jclass camera_cls = env->FindClass("com/example/demo/domain/Camera");
        if(!camera_cls)
        {
            std::cout << "find com/example/demo/domain/Camera failed" << std::endl;
            return nullptr;
        }
        jmethodID constrocter_mid = env->GetMethodID(camera_cls, "<init>", "()V");
        jfieldID camera_fid = env->GetFieldID(camera_cls, "id", "I");
        jfieldID camera_fname = env->GetFieldID(camera_cls, "name", "Ljava/lang/String;");
        jfieldID camera_ffeature = env->GetFieldID(camera_cls, "feature", "[F");

        jobject camera_jobj = env->NewObject(camera_cls, constrocter_mid);
        env->SetIntField(camera_jobj, camera_fid, 10);
        env->SetObjectField(camera_jobj, camera_fname, env->NewStringUTF("camera0"));
        
        float feature[10]{1.0, 2.0, 3.0, 4.0, 5.0 ,6.0, 7.0, 8.0, 9.0, 10.0};
        jfloatArray feature_jarray = env->NewFloatArray(sizeof(feature)/sizeof(float));
        jsize feature_jlen = env->GetArrayLength(feature_jarray);
        std::cout << "feature len " << (int)feature_jlen << std::endl;
        env->SetFloatArrayRegion(feature_jarray, 0, sizeof(feature)/sizeof(float), feature);
        env->SetObjectField(camera_jobj, camera_ffeature, feature_jarray);
        return camera_jobj;
  }