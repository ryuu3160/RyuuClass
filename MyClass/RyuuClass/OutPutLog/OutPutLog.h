/*
 * @file OutPutLog.h
 * @brief �f�o�b�O�ȂǂŎg�p
 * @author �ؗY��Y
 * @date �쐬���F04/05/2024
 *
 * @date 04/05 �֐��̒ǉ�
 */
#ifndef _____OUT_PUT_LOG_H_____
#define _____OUT_PUT_LOG_H_____

#include <sstream>
#include <Windows.h>

namespace RYUU
{
/// @brief �G���[�̃��b�Z�[�W�{�b�N�X��\������
/// @param [msg] �G���[���b�Z�[�W
/// @memo �{�^����OK�̂�
void Error(LPCSTR msg);

/// @brief �f�o�b�O���R���\�[���ɕ\������
/// @param [DebugMsg] �\�����镶����ւ̃|�C���^
void OutputDebug(std::string DebugMsg);
}

#endif // !_____OUT_PUT_LOG_H_____
