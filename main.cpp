#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>

#include "Compare.h"

int main() {
	// 6つのパターンのインスタンスを作成して、小さい方の値を表示
	Compare<int, int> intIns(11, 7);
	std::cout << "Min(int, int)" << intIns.Min() << std::endl;

	Compare<float, float> floatIns(5.2f, 13.5f);
	std::cout << "Min(float, float)" << floatIns.Min() << std::endl;

	Compare<double, double> doubleIns(42.8, 27.1);
	std::cout << "Min(double, double)" << doubleIns.Min() << std::endl;

	Compare<int, float> intFloatIns(32, 18.8f);
	std::cout << "Min(int, float)" << intFloatIns.Min() << std::endl;

	Compare<int, double> intDoubleIns(9, 21.4);
	std::cout << "Min(int, double)" << intDoubleIns.Min() << std::endl;

	Compare<float, double> floatDoubleIns(89.4f, 56.2);
	std::cout << "Min(float, double)" << floatDoubleIns.Min() << std::endl;

	return 0;
}