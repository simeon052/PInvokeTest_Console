// Win32CppLib.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
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
		(list + i)->error = i;
		strcpy_s((list + i)->errormessage,"Error Message");
		OutputDebugString(_T("Now"));
	}

	return;
}
 