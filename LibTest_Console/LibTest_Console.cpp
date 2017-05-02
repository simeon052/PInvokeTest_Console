// LibTest_Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include "..\Win32CppLib\stdafx.h"

int main()
{
	struct Data datalist[10];
	GetErrors(datalist, 10);
	std::cout << "Test\n";

	struct Data *datalist2;
	int count;
	datalist2 = GetErrors2(&count);
	struct Data *p;
	for (int i = 0; i < count; i++) {
		p = datalist2 + i;
		std::cout << p->errormessage;
//		std::cout << p->description;
	}

    return 0;
}


