#pragma once
#include "Instrument.h"

class Piano : public Instrument {
public:
	void Play() const override;
};
