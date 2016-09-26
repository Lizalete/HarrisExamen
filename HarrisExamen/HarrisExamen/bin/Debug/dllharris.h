#ifndef _DLLHARRIS_H_
#define _DLLHARRIS_H_

#if BUILDING_DLL
#define MYAPI __declspec(dllexport)
#else
#define MYAPI __declspec(dllimport)
#endif

#include <string>
#include <iomanip>

/**

* Header con los métodos YUV, Sobel y HarrisCorner.

* @author: Lizbeth Peralta Malváez

* @version: 25/09/2016/C

*/


extern "C" {
	
MYAPI void __stdcall YUV(unsigned char image[], int size);

MYAPI void __stdcall Sobel(unsigned char image[], int height, int width, int size);

MYAPI void __stdcall HarrisCorner(unsigned char image[], int height, int width, int size); 
}
#endif

