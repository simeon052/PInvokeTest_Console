// LibTest_Console.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>
#include "..\Win32CppLib\stdafx.h"

int main()
{
	struct Data *datalist;
	GetData(&datalist);
	struct Data *pos = datalist;
	struct Data* prev;
	std::cout << "Start\n";
	do {
		printf("%d %d %ws\n",pos->info, pos->subInfo, pos->message);
		prev = pos;
		pos = pos->next;
	}while(prev->next != nullptr);
	std::cout << "End\n";

    return 0;
}


