#pragma once
#include "option.h"
#include "payoff.h"



class Greeks
{
public:
	//Delta
	static double delta(
		const Option& opt,
		const Payoff& payoff,
		double h,
		int num_paths
	);

	//vega
	static double vega(
		const Option& opt,
		const Payoff& payoff,
		double h,
		int num_paths
	);

	//Gamma
	static double gamma(
		const Option& opt,
		const Payoff& payoff,
		double h,
		int num_paths
	);

};

