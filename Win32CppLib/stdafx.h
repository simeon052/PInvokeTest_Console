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
	int error;
	char errormessage[32];
	char *description;
	
};

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă�������
extern "C"
{

__declspec(dllexport) 	int add(int a, int b);

__declspec(dllexport) 	char * addstr(char **src, int length);

__declspec(dllexport) 	void replacestr(char **src, int length);

__declspec(dllexport)   void GetErrors(struct Data *, int);

__declspec(dllexport)   struct Data *GetErrors2(int *count);


}
