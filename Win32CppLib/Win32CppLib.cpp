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
/// �f�[�^�̗̈���m�ۂ��āA���X�g�ɂ��ĕԂ�
///
void GetData(struct Data** dataList) {

	int count = 5;
	struct Data *currentPos;
	currentPos = new struct Data;
	*dataList = currentPos; // �擪��ۑ�

	stored = currentPos;

	int i = 0;
	while (1) {
		currentPos->info = i + 1; //���݂̗v�f�ɒl����
		currentPos->subInfo = i + 0xff;
		currentPos->message = L"Some message";

		if (i + 1 >= count) {
			currentPos->next = nullptr;
			printf("  >>> 0x%016llx [%d]\n       -> 0x%16llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			break;
		}
		else
		{
			//���̗v�f���m��
			currentPos->next = new struct Data;
			printf("  >>> 0x%016llx [%d]\n       -> 0x%016llx\n", (UINT64)currentPos, currentPos->info, (UINT64)currentPos->next);
			currentPos = currentPos->next; // �v�f�����Ɉړ�
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