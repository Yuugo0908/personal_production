#pragma once

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
#include "Model.h"
#include "Camera.h"

class Object3d
{
protected: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public: // �T�u�N���X
	// �萔�o�b�t�@�p�f�[�^�\����B0
	struct ConstBufferDataB0
	{
		//XMFLOAT4 color; // �F (RGBA)
		XMMATRIX mat; // �R�c�ϊ��s��
	};

public: // �ÓI�����o�֐�
	// �ÓI������
	static bool StaticInitialize(ID3D12Device* device);
	// �`��O����
	static void PreDraw(ID3D12GraphicsCommandList* cmdList);
	// �`��㏈��
	static void PostDraw();
	// 3D�I�u�W�F�N�g����
	static Object3d* Create();
	// �O���t�B�b�N�p�C�v���C������
	static bool CreateGraphicsPipeline();

private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;
	// �R�}���h���X�g
	static ID3D12GraphicsCommandList* cmdList;
	// ���[�g�V�O�l�`��
	static ComPtr<ID3D12RootSignature> rootsignature;
	// �p�C�v���C���X�e�[�g�I�u�W�F�N�g
	static ComPtr<ID3D12PipelineState> pipelinestate;	
	// ���_�V�F�[�_�I�u�W�F�N�g
	static ComPtr<ID3DBlob> vsBlob;
	// �s�N�Z���V�F�[�_�I�u�W�F�N�g
	static ComPtr<ID3DBlob> psBlob;
	// �G���[�I�u�W�F�N�g
	static ComPtr<ID3DBlob> errorBlob;

public: // �����o�֐�
	bool Initialize();
	// ���t���[������
	void Update();
	// �`��
	void Draw();
	// ���f���X�P�[���̎擾
	const XMFLOAT3& GetScale() { return scale; }
	// ���f���X�P�[���̐ݒ�
	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
	// ��]�p�̎擾
	const XMFLOAT3& GetRotation() { return rotation; }
	// ��]�p�̐ݒ�
	void SetRotation(XMFLOAT3 rotation) { this->rotation = rotation; }
	// ���W�̎擾
	const XMFLOAT3& GetPosition() { return position; }
	// ���W�̐ݒ�
	void SetPosition(XMFLOAT3 position) { this->position = position; }
	// ���f���̐ݒ�
	void SetModel(Model* model) { this->model = model; };

private: // �����o�ϐ�
	ComPtr<ID3D12Resource> constBufferB0; // �萔�o�b�t�@
	// �F
	XMFLOAT4 color = { 1,1,1,1 };
	// ���[�J���X�P�[��
	XMFLOAT3 scale = { 1,1,1 };
	// X,Y,Z�����̃��[�J����]�p
	XMFLOAT3 rotation = { 0,0,0 };
	// ���[�J�����W
	XMFLOAT3 position = { 0,0,0 };
	// ���[�J�����[���h�ϊ��s��
	XMMATRIX matWorld;
	// �e�I�u�W�F�N�g
	Object3d* parent = nullptr;

	Model* model = nullptr;
};