#include "greeks.h"
#include "monte_carlo.h"


//Delta ( Central Difference )
double Greeks::delta(const Option& opt,const Payoff& payoff,
					double h,int num_paths)
{
	Option up = opt;
	Option down = opt;
	up.S += h;
	down.S -= h;

	double up_price = MonteCarloPricer::price(up,payoff,num_paths);
	double down_price = MonteCarloPricer::price(down, payoff, num_paths);

	return (up_price - down_price) / (2.0 * h);
}

//vega
double Greeks::vega(const Option& opt, const Payoff& payoff,
					double h, int num_paths)
{
	Option up = opt;
	Option down = opt;
	up.sigma += h;
	down.sigma -= h;

	double up_price = MonteCarloPricer::price(up, payoff, num_paths);
	double down_price = MonteCarloPricer::price(down, payoff, num_paths);

	return (up_price - down_price) / (2.0 * h);
}

//gamma
double Greeks::gamma(const Option& opt, const Payoff& payoff,
	double h, int num_paths)
{
	Option up = opt;
	Option mid = opt;
	Option down = opt;
	up.S += h;
	down.S -= h;

	double up_price = MonteCarloPricer::price(up, payoff, num_paths);
	double mid_price = MonteCarloPricer::price(mid, payoff, num_paths);
	double down_price = MonteCarloPricer::price(down, payoff, num_paths);

	return (up_price - 2 * mid_price + down_price) / (h * h);
}