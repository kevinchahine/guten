// Guten.cpp : Defines the exported functions for the DLL.
//

#include "../pch.h"
#include "framework.h"
#include "GutenExports.h"


// This is an example of an exported variable
GUTEN_API int nGuten=0;

// This is an example of an exported function.
GUTEN_API int fnGuten(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
//CGuten::CGuten()
//{
//    return;
//}
