// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <windows.h>

struct Data {
	int error;
	char errormessage[32];
	char *description;
	
};

// TODO: プログラムに必要な追加ヘッダーをここで参照してください
extern "C"
{

__declspec(dllexport) 	int add(int a, int b);

__declspec(dllexport) 	char * addstr(char **src, int length);

__declspec(dllexport) 	void replacestr(char **src, int length);

__declspec(dllexport)   void GetErrors(struct Data *, int);

__declspec(dllexport)   struct Data *GetErrors2(int *count);


}
