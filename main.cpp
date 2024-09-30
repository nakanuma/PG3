#include <stdio.h>
#include <iostream>

// 一般的な賃金体系の場合、働いた時間に応じて総収入を計算する関数
uint32_t CalculateTotalEarningsGeneral(uint32_t hours) { 
	return hours * 1072; 
}

// 再帰的な賃金体系の場合、働いた時間に応じて総収入を計算する関数
uint32_t CalculateTotalEarningsRecursive(uint32_t hours) { 
	if (hours <= 0) {
		return 0;
	}

	uint32_t totalEarnings = 0; // 総収入
	uint32_t currentWage = 100; // 最初の時給

	for (uint32_t i = 0; i <= hours; i++) {
		totalEarnings += currentWage; // 現在の時給を総収入に加算
		currentWage = currentWage * 2 - 50; // 次の時給を計算
	}

	return totalEarnings;
}

int main() {
	uint32_t hours = 1;

	while (true) {
		uint32_t generalEarnings = CalculateTotalEarningsGeneral(hours);
		uint32_t recursiveEarnings = CalculateTotalEarningsRecursive(hours);

		// 再帰的に計算した賃金が、一般的な賃金よりも高くなったらループを抜ける
		if (recursiveEarnings > generalEarnings) {
			printf("general : %d, recursive : %d\n", generalEarnings, recursiveEarnings);
			printf("hours : %d\n", hours);
			break;
		}

		hours++;
	}

	return 0;
}