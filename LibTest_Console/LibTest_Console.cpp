// LibTest_Console.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>
#include "..\Win32CppLib\stdafx.h"

int main()
{
	struct Data datalist[10];
	GetErrors(datalist, 10);
	std::cout << "Test";
    return 0;
}

