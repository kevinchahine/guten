#pragma once

#ifdef __linux__
	using WORD = unsigned short;
	using HANDLE = void *;
	using CONSOLE_SCREEN_BUFFER_INFO = void *;	// TODO: Fix this for linux
	
#elif _WIN32
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
	#endif // WIN32_LEAN_AND_MEAN
	
	#ifndef NOMINMAX
		#define NOMINMAX   
	#endif
	
	// Windows Header Files
	#include <windows.h>
#endif // _WIN32