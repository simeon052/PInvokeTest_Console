// LibTest_Console.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include "..\Win32CppLib\stdafx.h"

int main()
{

#ifdef _DEBUG
	::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
#endif

	struct Data *datalist;
	GetData(&datalist);
	struct Data *current = datalist;
	std::cout << "Start\n";
	do {
		printf("%d %d %ws\n",current->info, current->subInfo, current->message);
		current = current->next;
	}while(current != nullptr);
	std::cout << "End\n";

	Cleanup();
    return 0;
}


