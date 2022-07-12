#include "DebugText.h"

DebugText::DebugText()
{
}

DebugText::~DebugText()
{
	for (int i = 0; i < _countof(image2dDatas); i++)
	{
		delete image2dDatas[i];
	}
}

void DebugText::Initialize(UINT texnumber)
{
	// �S�Ẳ摜�f�[�^�ɂ���
	for (int i = 0; i < _countof(image2dDatas); i++)
	{
		// �摜�𐶐�����
		image2dDatas[i] = Image2d::Create(texnumber, { 0,0 });
	}
}

// 1������ǉ�
void DebugText::Print(const std::string& text, float x, float y, float scale = 1.0f)
{
	// �S�Ă̕����ɂ���
	for (int i = 0; i < text.size(); i++)
	{
		// �ő啶��������
		if (image2dIndex >= maxCharCount)
		{
			break;
		}

		// 1�������o��(��ASCII�R�[�h�ł������藧���Ȃ�)
		const unsigned char& character = text[i];

		int fontIndex = character - 32;
		if (character >= 0x7f)
		{
			fontIndex = 0;
		}

		int fontIndexY = fontIndex / fontLineCount;
		int fontIndexX = fontIndex % fontLineCount;

		// ���W�v�Z
		image2dDatas[image2dIndex]->SetPosition({ x + fontWidth * scale * i, y });
		image2dDatas[image2dIndex]->SetTextureRect({ (float)fontIndexX * fontWidth, (float)fontIndexY * fontHeight }, { (float)fontWidth, (float)fontHeight });
		image2dDatas[image2dIndex]->SetSize({ fontWidth * scale, fontHeight * scale });

		// �������P�i�߂�
		image2dIndex++;
	}
}

// �܂Ƃ߂ĕ`��
void DebugText::DrawAll(ID3D12GraphicsCommandList* cmdList)
{
	// �S�Ă̕����̉摜�ɂ���
	for (int i = 0; i < image2dIndex; i++)
	{
		// �摜�`��
		image2dDatas[i]->Draw();
	}

	image2dIndex = 0;
}