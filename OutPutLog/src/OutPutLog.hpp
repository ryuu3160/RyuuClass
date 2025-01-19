 /*+===================================================================
	 File: OutPutLog.hpp
	 Summary: �f�o�b�O�ȂǂŎg�p����֐��̃w�b�_
	 Author: AT12C192 01 �ؗY��Y
	 Date: 04/05/2024 ����쐬
 ===================================================================+*/
#pragma once

#include <sstream>
#include <Windows.h>

/// @brief �G���[�̃��b�Z�[�W�{�b�N�X��\������
/// @param [In_cMsg] �G���[���b�Z�[�W
/// @memo �{�^����OK�̂�
void Error(LPCSTR In_cMsg);

/**
 * @brief �G���[�̃��b�Z�[�W�{�b�N�X��\������
 * @param [In_hWnd] �e�E�B���h�E�ւ̃n���h��
 * @param [In_cMsg] �G���[���b�Z�[�W
 * @memo �{�^����OK�̂�
 */
void Error(HWND In_hWnd, LPCSTR In_cMsg);

/// @brief �f�o�b�O���R���\�[���ɕ\������
/// @param [In_strDebugMsg] �\�����镶����ւ̃|�C���^
void OutputDebug(std::string In_strDebugMsg);
