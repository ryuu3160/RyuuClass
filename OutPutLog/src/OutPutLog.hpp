 /*+===================================================================
	 File: OutPutLog.hpp
	 Summary: デバッグなどで使用する関数のヘッダ
	 Author: AT12C192 01 青木雄一郎
	 Date: 04/05/2024 初回作成
 ===================================================================+*/
#pragma once

#include <sstream>
#include <Windows.h>

/// @brief エラーのメッセージボックスを表示する
/// @param [In_cMsg] エラーメッセージ
/// @memo ボタンはOKのみ
void Error(LPCSTR In_cMsg);

/**
 * @brief エラーのメッセージボックスを表示する
 * @param [In_hWnd] 親ウィンドウへのハンドル
 * @param [In_cMsg] エラーメッセージ
 * @memo ボタンはOKのみ
 */
void Error(HWND In_hWnd, LPCSTR In_cMsg);

/// @brief デバッグをコンソールに表示する
/// @param [In_strDebugMsg] 表示する文字列へのポインタ
void OutputDebug(std::string In_strDebugMsg);
