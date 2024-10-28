#pragma once
#include <iostream>

class Instrument {
public:
	// 仮想デストラクタ
	virtual ~Instrument() = default;

	virtual void Play() const;
};
