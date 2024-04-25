/*
 * @file OutPutLog.h
 * @brief デバッグなどで使用
 * @author 青木雄一郎
 * @date 作成日：04/05/2024
 *
 * @date 04/05 関数の追加
 */
#ifndef _____OUT_PUT_LOG_H_____
#define _____OUT_PUT_LOG_H_____

#include <sstream>
#include <Windows.h>

namespace RYUU
{
/// @brief エラーのメッセージボックスを表示する
/// @param [msg] エラーメッセージ
/// @memo ボタンはOKのみ
void Error(LPCSTR msg);

/// @brief デバッグをコンソールに表示する
/// @param [DebugMsg] 表示する文字列へのポインタ
void OutputDebug(std::string DebugMsg);
}

#endif // !_____OUT_PUT_LOG_H_____
