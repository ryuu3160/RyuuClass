 /*+===================================================================
	 File: OutPutLog.hpp
	 Summary: �f�o�b�O�ȂǂŎg�p
	 Author: AT12C192 01 �ؗY��Y
	 Date: 04/05/2024 ����쐬
			 /10 �֐��̒ǉ� [IntegerSort]
			 /11 �֐��̒ǉ� [SetStrArrayData,StringSort]
 ===================================================================+*/
#pragma once

#include <sstream>
#include <Windows.h>

/// @brief �G���[�̃��b�Z�[�W�{�b�N�X��\������
/// @param [msg] �G���[���b�Z�[�W
/// @memo �{�^����OK�̂�
void Error(LPCSTR msg);

/**
 * @brief �G���[�̃��b�Z�[�W�{�b�N�X��\������
 * @param hWnd �e�E�B���h�E�ւ̃n���h��
 * @param msg �G���[���b�Z�[�W
 * @memo �{�^����OK�̂�
 */
void Error(HWND hWnd, LPCSTR msg);

/// @brief �f�o�b�O���R���\�[���ɕ\������
/// @param [DebugMsg] �\�����镶����ւ̃|�C���^
void OutputDebug(std::string DebugMsg);
