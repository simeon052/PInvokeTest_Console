// Win32CppLib.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>
#include <tchar.h>


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
	char* addstr = "_Windows";

	char* pstrDist = (char *)malloc(length + 9);
	memcpy(pstrDist, *pstrsrc, length);
	memcpy(pstrDist + length, addstr, 9);
	OutputDebugStringA(pstrDist);
	return pstrDist;
}


void GetErrors(struct Data* list, int count) {

	for (int i = 0; i < count; i++) {

		list[i].description = (char *)calloc(256, 0);
		list[i].error = i;
		strcpy_s(list[i].errormessage,"Error Message\n\0");
//		memcpy_s(list[i].description, 256, "Some Message\n\0", 11);
		OutputDebugString(_T("Now"));
	}

	return;
}

struct Data *GetErrors2(int *count) {

	struct Data *list;
	*count = 10;
	list = new struct Data[*count];
	for (int i = 0; i < *count; i++) {
		list[i].description = (char *)calloc(256, 0);
		(list + i)->error = i;
		strcpy_s((list + i)->errormessage,"Error Message 2\n\0");
//		memcpy_s(list[i].description, 256, "Some Message\n\0", 11);
		OutputDebugString(_T("Now"));
	}

	return list;
}
