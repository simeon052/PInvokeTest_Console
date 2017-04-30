// Win32CppLib.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>


__declspec(dllexport)

int add(int a, int b)
{
	return a + b;
}

void replacestr(char **pstrsrc, int length)
{
	for (int i = 0; i < length; i++)
	{
		(*pstrsrc)[i] = '*';
	}
	return;
}


char* addstr(char **pstrsrc, int length)
{
	char* addstr = "_UWP";

	char* pstrDist = (char *)malloc(length + 8);
	memcpy(pstrDist, *pstrsrc, length);
	memcpy(pstrDist + length, addstr, 8);

	return pstrDist;
}

