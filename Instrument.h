#pragma once
#include <iostream>

class Instrument {
public:
	// ���z�f�X�g���N�^
	virtual ~Instrument() = default;

	virtual void Play() const;
};
