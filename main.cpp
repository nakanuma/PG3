#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>

// SetTimeout関数の実装
void SetTimeout(std::function<void()> functionRef, int delay) {
	Sleep(delay);
	functionRef();
}

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

	// ラムダ式を使用して入力の検証を行う
	SetTimeout([randomNumber, input]() {
		 if ((randomNumber % 2 == 1 && input == '0') || (randomNumber % 2 == 0 && input == '1')) {
			printf("正解\n");
		} else {
			printf("不正解\n");
		}
	}, 3000); // 3秒待機してから検証を実行

	return 0;
}