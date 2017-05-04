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
	int info;
	int subInfo;
	LPWSTR message;
	struct Data *next;
};

// TODO: プログラムに必要な追加ヘッダーをここで参照してください
extern "C"
{

__declspec(dllexport) 	int add(int a, int b);

__declspec(dllexport) 	void addstr(char *src, int length);

__declspec(dllexport) 	void replacestr(char *src, int length, int capacity);

__declspec(dllexport)   void GetData(struct Data **);

__declspec(dllexport)   void Cleanup();

__declspec(dllexport)   void GetDataByArray(struct Data** dataList, int *count);

}
