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
	// �y��̃��X�g���쐬
	std::vector<std::unique_ptr<Instrument>> instruments;
	instruments.push_back(std::make_unique<Guitar>());
	instruments.push_back(std::make_unique<Piano>());
	instruments.push_back(std::make_unique<Drums>());

	// �e�y��̉����o��
	for (const auto& instrument : instruments) {
		instrument->Play();
	}

	return 0;
}