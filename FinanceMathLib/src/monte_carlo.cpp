#include"monte_carlo.h"

#include <random>
#include <cmath>

double MonteCarloPricer::price(const Option& opt, const Payoff& payoff,int num_simulations)
{
	double S0 = opt.S;
	double K = opt.K;
	double r = opt.r;
	double sigma = opt.sigma;
	double T = opt.T;

	std::mt19937 rng(42);
	std::normal_distribution<> norm(0, 1);
	double payoff_sum = 0;

	for (int i = 0;i < num_simulations;i++)
	{
		double Z = norm(rng);
		double ST = S0 * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * Z);
		payoff_sum += payoff(ST);
		//double VT = std::max(ST - K, 0.0);
		//payoff_sum += VT;

	}

	double V0 = std::exp(-r * T) / num_simulations * payoff_sum;
	return V0;

}
