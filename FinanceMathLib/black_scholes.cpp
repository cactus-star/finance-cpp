#include "black_scholes.h"
#include "normal_distribution.h"
#include <cmath>

double BlackScholes::call_price(const Option& opt)
{
	double S = opt.S;
	double K = opt.K;
	double r = opt.r;
	double sigma = opt.sigma;
	double T = opt.T;

	double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T)/ (sigma * std::sqrt(T));
	double d2 = d1 - sigma * std::sqrt(T);
	double Nd1 = StandardNormalDistribution::cdf(d1);
	double Nd2 = StandardNormalDistribution::cdf(d2);

	return S * Nd1 - K * std::exp(-r * T) * Nd2;

}

double BlackScholes::put_price(const Option& opt)
{
	double S = opt.S;
	double K = opt.K;
	double r = opt.r;
	double sigma = opt.sigma;
	double T = opt.T;

	double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
	double d2 = d1 - sigma * std::sqrt(T);
	double Nd1 = StandardNormalDistribution::cdf(-d1);
	double Nd2 = StandardNormalDistribution::cdf(-d2);

	return K * std::exp(-r * T) * Nd2 - S * Nd1;

}