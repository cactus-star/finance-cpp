#pragma once
#include "payoff.h"


CallPayoff::CallPayoff(double K) :K_(K) {}

double CallPayoff::operator()(double S) const
{
	return std::max(S-K_,0.0);
}




