#pragma once
#include <DirectXMath.h>
class Camera
{
protected: // �G�C���A�X
// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
public: // �ÓI�����o�֐�
	// �J����������
	static void Initialize(const int window_width, const int window_height);
	// ���_���W�̎擾
	static const XMFLOAT3& GetEye() { return eye; }
	// ���_���W�̐ݒ�
	static void SetEye(XMFLOAT3 eye);
	// �����_���W�̎擾
	static const XMFLOAT3& GetTarget() { return target; }
	// �����_���W�̐ݒ�
	static void SetTarget(XMFLOAT3 target);
	// �x�N�g���ɂ��ړ�
	static void CameraMoveVector(XMFLOAT3 move);
	static void CameraMoveEyeVector(XMFLOAT3 move);
	// �r���[�s����X�V
	static void UpdateViewMatrix();
	//�ˉe�s����X�V
	//static void UpdateProjectionMatrix();
private: // �ÓI�����o�ϐ�
	// �r���[�s��
	static XMMATRIX matView;
	// �ˉe�s��
	static XMMATRIX matProjection;
	// �r���[�ˉe�s��
	static XMMATRIX matViewProjection;
	// ���_���W
	static XMFLOAT3 eye;
	// �����_���W
	static XMFLOAT3 target;
	// ������x�N�g��
	static XMFLOAT3 up;
public: // �����o�֐�
	static const XMMATRIX& GetMatViewProjection();
};