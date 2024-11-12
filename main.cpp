#include <Windows.h>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <random>
#include <stdio.h>
#include <thread>
#include <vector>

int main() {
	std::list<const char*> yamanoteLineStations = {"Tokyo",  "Kanda",     "Akihabara", "Okachimachi",  "Ueno",       "Uguisudani",  "Nippori",   "Tabata",   "Komagome", "Sugamo",
	                                               "Otsuka", "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo", "Shinjuku",    "Yoyogi",    "Harajuku", "Shibuya",  "Ebisu",
	                                               "Meguro", "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",    "Hamamatucho", "Shimbashi", "Yurakucho"};
	                                       
	// 1970�N�̉w�ꗗ��\��
	std::cout << "1970 : " << std::endl;
	for (auto itr = yamanoteLineStations.begin(); itr != yamanoteLineStations.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	std::cout << "\n" << std::endl;


	// �����闢�w��ǉ�
	for (auto itr = yamanoteLineStations.begin(); itr != yamanoteLineStations.end(); ++itr) {
		if (*itr == "Tabata") {
			yamanoteLineStations.insert(itr, "Nishi-Nippori");
		}
	}


	// 2019�N�̉w�ꗗ��\��
	std::cout << "2019 : " << std::endl;
	for (auto itr = yamanoteLineStations.begin(); itr != yamanoteLineStations.end(); ++itr) {
		std::cout << *itr << "\n";
	}
	std::cout << "\n" << std::endl;


	// ���փQ�[�g�E�F�C�w��ǉ�
	for (auto itr = yamanoteLineStations.begin(); itr != yamanoteLineStations.end(); ++itr) {
		if (*itr == "Tamachi") {
			yamanoteLineStations.insert(itr, "Takanawa-Gateway");
		}
	}


	// 2022�N�̉w�ꗗ��\��
	std::cout << "2022 : " << std::endl;
	for (auto itr = yamanoteLineStations.begin(); itr != yamanoteLineStations.end(); ++itr) {
		std::cout << *itr << "\n";
	}

	return 0;
}