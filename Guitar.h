#pragma once
#include "Instrument.h"

class Guitar : public Instrument{
public:
	void Play() const override;
};
