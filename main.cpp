#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>

// SetTimeout�֐��̎���
void SetTimeout(std::function<void()> functionRef, int delay) {
	Sleep(delay);
	functionRef();
}

// 1~6�̒l�������_���ŕԂ��֐�
uint32_t GenerateRandomNumber() {
	// ����������̏�����
	std::random_device rd;
	std::mt19937 rng(rd());

	std::uniform_int_distribution<uint32_t> distNumber(1, 6);

	return distNumber(rng);
}

int main() {
	// �֐��|�C���^�̒�`
	uint32_t (*randomNumberFunc)() = GenerateRandomNumber;

	// �v���C���[�̓��͂��󂯎��
	char input;
	printf("��(�)�Ȃ�0�A��(����)�Ȃ�1����� : ");
	scanf_s("%c", &input);

	// �����𐶐�
	uint32_t randomNumber = randomNumberFunc();
	printf("�o������ : %d\n", randomNumber);

	// �����_�����g�p���ē��͂̌��؂��s��
	SetTimeout([randomNumber, input]() {
		 if ((randomNumber % 2 == 1 && input == '0') || (randomNumber % 2 == 0 && input == '1')) {
			printf("����\n");
		} else {
			printf("�s����\n");
		}
	}, 3000); // 3�b�ҋ@���Ă��猟�؂����s

	return 0;
}