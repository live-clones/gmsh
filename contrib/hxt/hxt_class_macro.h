
#define FE_0(WHAT, _)
#define FE_1(WHAT, X, _) WHAT(X,1) 
#define FE_2(WHAT, X, ...) WHAT(X,2)FE_1(WHAT, __VA_ARGS__)
#define FE_3(WHAT, X, ...) WHAT(X,3)FE_2(WHAT, __VA_ARGS__)
#define FE_4(WHAT, X, ...) WHAT(X,4)FE_3(WHAT, __VA_ARGS__)
#define FE_5(WHAT, X, ...) WHAT(X,5)FE_4(WHAT, __VA_ARGS__)
#define FE_6(WHAT, X, ...) WHAT(X,6)FE_5(WHAT, __VA_ARGS__)
#define FE_7(WHAT, X, ...) WHAT(X,7)FE_6(WHAT, __VA_ARGS__)
#define FE_8(WHAT, X, ...) WHAT(X,8)FE_7(WHAT, __VA_ARGS__)
#define FE_9(WHAT, X, ...) WHAT(X,9)FE_8(WHAT, __VA_ARGS__)

#define GET_MACRO(_0_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME 
#define FOR_EACH(action,...) \
  GET_MACRO(__VA_ARGS__,FE_9,FE_8,FE_7,FE_6,FE_5,FE_4,FE_3,FE_2,FE_1,FE_0)(action,__VA_ARGS__)
#define ARG_AND_NAME(X, I) ,X _##I
#define NAME_ONLY(X, I) , _##I
#define ARG_ONLY(X, I) ,X
#define ARGS_AND_NAMES(...) FOR_EACH(ARG_AND_NAME,__VA_ARGS__)
#define NAMES_ONLY(...) FOR_EACH(NAME_ONLY,__VA_ARGS__)
#define ARGS_ONLY(...) FOR_EACH(ARG_ONLY,__VA_ARGS__)

#define HXT_FUNCTION_MEMBER_ASSIGN(derivedType,member, ...) \
{\
  HXTStatus(*castcheck)(HXT##derivedType* ARGS_ONLY(__VA_ARGS__)) = hxt##derivedType##member;\
  c->member = (HXTStatus(*)(void* ARGS_ONLY(__VA_ARGS__)))castcheck;\
}

#define HXT_FUNCTION_MEMBER_DECLARE(derivedType, member, ...) \
  HXTStatus(*member)(void* ARGS_ONLY(__VA_ARGS__))

#define HXT_FUNCTION_MEMBER_IMPLEMENT(derivedType, member, ...) \
HXTStatus hxt##derivedType##member(HXT##derivedType *c ARGS_AND_NAMES(__VA_ARGS__)) { \
  return c->c->member(c->data NAMES_ONLY(__VA_ARGS__)); \
}

#define HXT_DECLARE_DERIVED_CLASS(baseType, derivedType) \
static HXT##baseType##Class *hxt##derivedType##Class;\
HXTStatus hxt##derivedType##Register() \
{ \
  HXT_CHECK(hxtMalloc(&hxt##derivedType##Class, sizeof(HXT##baseType##Class))); \
  HXT##baseType##Class *c = hxt##derivedType##Class; \
  HXT##baseType##_MEMBERS(HXT_FUNCTION_MEMBER_ASSIGN, derivedType) \
  HXTStatus(*castcheck)(HXT##derivedType**) = hxt##derivedType##Delete; \
  c->Delete =  (HXTStatus(*)(void**))castcheck; \
  return HXT_STATUS_OK;\
} \
\
HXTStatus hxt##baseType##Get##derivedType(HXT##baseType *b, HXT##derivedType **d) { \
  if (b->c == hxt##derivedType##Class) { \
    *d = b->data; \
  } \
  else { \
    *d = NULL; \
  } \
  return HXT_STATUS_OK; \
}

#define HXT_DECLARE_INTERFACE(baseType) \
typedef struct { \
  HXT##baseType##_MEMBERS(HXT_FUNCTION_MEMBER_DECLARE,) \
  HXTStatus (*Delete)(void **); \
} HXT##baseType##Class; \
struct HXT##baseType##Struct { \
  HXT##baseType##Class *c;\
  void *data; \
}; \
HXT##baseType##_MEMBERS(HXT_FUNCTION_MEMBER_IMPLEMENT,baseType) \
HXTStatus hxt##baseType##Delete(HXT##baseType **pp) {\
  HXT_CHECK((*pp)->c->Delete(&(*pp)->data));\
  HXT_CHECK(hxtFree(pp));\
  return HXT_STATUS_OK;\
} \
HXTStatus hxt##baseType##Create(HXT##baseType **pp, HXT##baseType##Class *c, void *data) {\
  HXT_CHECK(hxtMalloc(pp, sizeof(HXT##baseType))); \
  (*pp)->c = c; \
  (*pp)->data = data; \
  return HXT_STATUS_OK;\
}
