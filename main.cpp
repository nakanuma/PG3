#include <Windows.h>
#include <random>
#include <stdio.h>

// 1~6の値をランダムで返す関数
uint32_t GenerateRandomNumber() {
	// 乱数生成器の初期化
	std::random_device rd;
	std::mt19937 rng(rd());

	std::uniform_int_distribution<uint32_t> distNumber(1, 6);

	return distNumber(rng);
}

int main() {
	// 関数ポインタの定義
	uint32_t (*randomNumberFunc)() = GenerateRandomNumber;

	// プレイヤーの入力を受け取る
	char input;
	printf("半(奇数)なら0、丁(偶数)なら1を入力 : ");
	scanf_s("%c", &input);

	// 数字を生成
	uint32_t randomNumber = randomNumberFunc();
	printf("出た数字 : %d\n", randomNumber);

	// 3秒待機
	Sleep(3000);

	// 入力の検証
	if ((randomNumber % 2 == 1 && input == '0') || (randomNumber % 2 == 0 && input == '1')) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}

	return 0;
}