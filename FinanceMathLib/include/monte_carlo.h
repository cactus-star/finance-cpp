#pragma once
#include "option.h"
#include "payoff.h"

class MonteCarloPricer
{
public:
	static double price(
		const Option& opt,
		const Payoff& payoff,
		int num_simulations
	);

};

