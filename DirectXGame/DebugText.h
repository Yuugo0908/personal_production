#pragma once

#include "Image2d.h"
#include <Windows.h>
#include <string>

class DebugText
{
public:
	// �f�o�b�O�e�L�X�g�p�̃e�N�X�`���ԍ����w��
	static const int maxCharCount = 256; // �ő啶����
	static const int fontWidth = 9; // �t�H���g�摜��1�������̉���
	static const int fontHeight = 18; // �t�H���g�摜��1�������̏c��
	static const int fontLineCount = 14; // �t�H���g�摜��1�s���̕�����

	DebugText();
	~DebugText();

	void Initialize(UINT texnumber);

	void Print(const std::string& text, float x, float y, float size);

	void DrawAll(ID3D12GraphicsCommandList* cmdList);

private:
	// �摜�f�[�^�̔z��
	Image2d* image2dDatas[maxCharCount] = {};
	// �摜�f�[�^�z��̓Y�����ԍ�
	int image2dIndex = 0;
};