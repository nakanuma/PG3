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

// 指定秒待機する関数
void WaitSeconds(uint32_t seconds) { 
	Sleep(seconds * 1000); 
}

// 入力検証を行う関数
void ValidateInput(uint32_t randomNumber, char input) {
	// 入力の検証
	if ((randomNumber % 2 == 1 && input == '0') || (randomNumber % 2 == 0 && input == '1')) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

// 待機してから入力検証を行うコールバック関数
void WaitAndValidate(uint32_t randomNumber, char input, void (*waitCallback)(uint32_t), void (*validateCallback)(uint32_t, char)) {
	// コールバックで3秒待機
	waitCallback(3);

	// コールバックで入力検証
	validateCallback(randomNumber, input);
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

	// 待機してから入力の検証をコールバックで実行
	WaitAndValidate(randomNumber, input, WaitSeconds, ValidateInput);

	return 0;
}