// Win32CppLib.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
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
	*dataList = currentPos; // 先頭を保存

	int i = 0;
	while (1) {
		currentPos->info = i + 1; //現在の要素に値を代入
		currentPos->subInfo = i + 0xff;
		currentPos->message = L"Some message";

		if (i + 1 >= count) {
			currentPos->next = nullptr;
			printf("0x%016llx [%d]\n  -> 0x%16llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			break;
		}
		else
		{
			//次の要素を確保
			currentPos->next = new struct Data;
			printf("0x%016llx [%d]\n  -> 0x%016llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			currentPos = currentPos->next; // 要素を次に移動
		}
		i++;
	}

	return;
}
