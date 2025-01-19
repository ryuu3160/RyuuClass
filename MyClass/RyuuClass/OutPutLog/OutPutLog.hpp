 /*+===================================================================
	 File: OutPutLog.hpp
	 Summary: デバッグなどで使用
	 Author: AT12C192 01 青木雄一郎
	 Date: 04/05/2024 初回作成
			 /10 関数の追加 [IntegerSort]
			 /11 関数の追加 [SetStrArrayData,StringSort]
 ===================================================================+*/
#pragma once

#include <sstream>
#include <Windows.h>

/// @brief エラーのメッセージボックスを表示する
/// @param [msg] エラーメッセージ
/// @memo ボタンはOKのみ
void Error(LPCSTR msg);

/**
 * @brief エラーのメッセージボックスを表示する
 * @param hWnd 親ウィンドウへのハンドル
 * @param msg エラーメッセージ
 * @memo ボタンはOKのみ
 */
void Error(HWND hWnd, LPCSTR msg);

/// @brief デバッグをコンソールに表示する
/// @param [DebugMsg] 表示する文字列へのポインタ
void OutputDebug(std::string DebugMsg);
