#pragma once
#include <stdint.h>
#include "Vector3.h"

class Enemy {
public:
	enum Phase {
		APPROACH,
		FIRE, 
		LEAVE
	};

public:
	Enemy();
	~Enemy();

	// �ڋ�
	void Approach();
	// �ˌ�
	void Fire();
	// ���E
	void Leave();

	// �X�V
	void Update();

	// ���݃t�F�[�Y�̖��O���擾
	const char* GetPhaseName() const;
	// ���݃t�F�[�Y���擾
	Phase GetCurrentPhase() const { return phase_; }
	// ���W���擾
	Vector3 GetPosition() const { return position_; }
	// �c�e�����擾
	uint32_t GetLeftBullet() const { return bullet_; }

private:
	// �����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::*spFuncTable[])();

	// ���݃t�F�[�Y
	Phase phase_;

	// ���W
	Vector3 position_;

	// �e
	int32_t bullet_;
};
