// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows �w�b�_�[����g�p����Ă��Ȃ����������O���܂��B
// Windows �w�b�_�[ �t�@�C��:
#include <windows.h>

struct Data {
	int info;
	int subInfo;
	LPWSTR message;
	struct Data *next;
};

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă�������
extern "C"
{

__declspec(dllexport) 	int add(int a, int b);

__declspec(dllexport) 	void addstr(char *src, int length);

__declspec(dllexport) 	void replacestr(char *src, int length, int capacity);

__declspec(dllexport)   void GetData(struct Data **);

__declspec(dllexport)   void Cleanup();

__declspec(dllexport)   void GetDataByArray(struct Data** dataList, int *count);

}
