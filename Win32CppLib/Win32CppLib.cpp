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

void replacestr(char *pstrsrc, int length, int capacity)
{
	for (int i = 0; i < length; i++)
	{
		if (pstrsrc[i] == 's') {
			pstrsrc[i] = '*';
		}
	}
	return;
}


void addstr(char *pstrsrc, int capacity)
{
	strcat_s(pstrsrc, capacity, "_Test");

	return;
}


static struct Data* stored;

///
/// データの領域を確保して、リストにして返す
///
void GetData(struct Data** dataList) {

	int count = 5;
	struct Data *currentPos;
	currentPos = new struct Data;
	*dataList = currentPos; // 先頭を保存

	stored = currentPos;

	int i = 0;
	while (1) {
		currentPos->info = i + 1; //現在の要素に値を代入
		currentPos->subInfo = i + 0xff;
		currentPos->message = L"Some message";

		if (i + 1 >= count) {
			currentPos->next = nullptr;
			printf("  >>> 0x%016llx [%d]\n       -> 0x%16llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			break;
		}
		else
		{
			//次の要素を確保
			currentPos->next = new struct Data;
			printf("  >>> 0x%016llx [%d]\n       -> 0x%016llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			currentPos = currentPos->next; // 要素を次に移動
		}
		i++;
	}

	return;
}


void Cleanup() {

	if (stored != nullptr) {
		struct Data *tmp = stored->next;
		do {
			delete(stored);
			stored = tmp;
			tmp = stored->next;
		} while (tmp != nullptr);
		delete(stored);
	}
}