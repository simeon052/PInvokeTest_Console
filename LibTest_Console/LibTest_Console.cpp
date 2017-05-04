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

	std::cout << "Start 2\n";
	struct Data *datalist2;
	int count;
	GetDataByArray(&datalist2, &count);
	int s = sizeof(struct Data);
	for (int i = 0; i < count; i++) {
		printf("%d %d %ws\n", datalist2[i].info, datalist2[i].subInfo, datalist2[i].message);
	}
	std::cout << "End 2\n";

	Cleanup();
    return 0;
}


