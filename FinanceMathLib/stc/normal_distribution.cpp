#include "normal_distribution.h"

double StandardNormalDistribution::pdf(double x)
{
	static const double INV_SQRT_2PI = 0.3989422804014327;
	return INV_SQRT_2PI * std::exp(-0.5*x*x);
}

double StandardNormalDistribution::cdf(double x)
{
	return 0.5*std::erfc(-x / std::sqrt(2));
}