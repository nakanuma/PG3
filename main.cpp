#include <stdio.h>
#include <iostream>
#include <chrono>

int main() {
	// 10万文字の文字列を作成
	std::string a(100000, 'a');

	///
	/// コピーにかかる時間を計測
	/// 
	std::chrono::high_resolution_clock::time_point start_copy, end_copy;
	start_copy = std::chrono::high_resolution_clock::now(); // 計測開始時間

	volatile std::string copied_string = a; // 文字列のコピーを行う

	end_copy = std::chrono::high_resolution_clock::now();                                                     // 計測終了時間
	auto copy_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count(); // 処理に要した時間をミリ秒に変換

	std::cout << "コピーに要した時間 : " << copy_elapsed << "μs" << std::endl;

	///
	///	移動にかかる時間を計測
	/// 
	std::chrono::high_resolution_clock::time_point start_move, end_move;
	start_move = std::chrono::high_resolution_clock::now(); // 計測開始時間

	volatile std::string moved_string = std::move(a); // 文字列の移動を行う

	end_move = std::chrono::high_resolution_clock::now();                                                     // 計測終了時間
	auto move_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count(); // 処理に要した時間をミリ秒に変換

	std::cout << " 移動に要した時間 : " << move_elapsed << "μs" << std::endl;

	return 0;
}