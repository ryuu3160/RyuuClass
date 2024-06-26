/*
 * @file OutPutLog.h
 * @brief デバッグなどで使用
 * @author 青木雄一郎
 * @date 作成日：04/05/2024
 *
 * @date 04/05 関数の追加
 */
#pragma once

#include <sstream>
#include <Windows.h>

namespace RYUU
{
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
}