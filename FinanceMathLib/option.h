#pragma once


class Option
{
public:
	double S;		//underlying price
	double K;		//strike
	double r;		//interest rate
	double sigma;	//vol
	double T;		//maturity

	Option(double S_, double K_, double r_, double sigma_, double T_) :S(S_), K(K_), r(r_), sigma(sigma_), T(T_)
	{}

};

