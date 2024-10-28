#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

#include "Instrument.h"
#include "Guitar.h"
#include "Piano.h"
#include "Drums.h"

int main() {
	// 楽器のリストを作成
	std::vector<std::unique_ptr<Instrument>> instruments;
	instruments.push_back(std::make_unique<Guitar>());
	instruments.push_back(std::make_unique<Piano>());
	instruments.push_back(std::make_unique<Drums>());

	// 各楽器の音を出力
	for (const auto& instrument : instruments) {
		instrument->Play();
	}

	return 0;
}