// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GUTEN_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GUTEN_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef __linux__
	#define GUTEN_API 
#elif _WIN32
	#ifdef GUTEN_EXPORTS
	#define GUTEN_API __declspec(dllexport)
	#else
	#define GUTEN_API __declspec(dllimport)
	#endif
#else
	#define GUTEN_API 
#endif

#pragma warning(disable: 4251)

// This class is exported from the dll
//class GUTEN_API CGuten {
//public:
//	CGuten(void);
//	// TODO: add your methods here.
//};

extern GUTEN_API int nGuten;

GUTEN_API int fnGuten(void);
