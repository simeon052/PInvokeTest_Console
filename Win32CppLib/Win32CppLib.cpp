// Win32CppLib.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>


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


void GetData(struct Data** dataList) {

	int count = 3;
	struct Data *currentPos;
	currentPos = new struct Data;
	*dataList = currentPos; // �擪��ۑ�

	int i = 0;
	while (1) {
		currentPos->info = i + 1; //���݂̗v�f�ɒl����
		currentPos->subInfo = i + 0xff;
		currentPos->message = L"Some message";

		if (i + 1 >= count) {
			currentPos->next = nullptr;
			printf("0x%016llx [%d]\n  -> 0x%16llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			break;
		}
		else
		{
			//���̗v�f���m��
			currentPos->next = new struct Data;
			printf("0x%016llx [%d]\n  -> 0x%016llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			currentPos = currentPos->next; // �v�f�����Ɉړ�
		}
		i++;
	}

	return;
}
