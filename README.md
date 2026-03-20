# finance-cpp Library
This project implements finance models in C++.

## Implemented Models

### Week1: Standard Normal Distribution

Functions implemented:
- pdf(x):probability density function.
- cdf(x):cumulative distribution function.
  the cdf is implemented using the complementary error function (erfc).

Files:
- normal_distribution.h
- normal_distribution.cpp

### Week2: Black-Scholes Option Pricing

Implemented:
- European call option pricing
- European put option pricing

Files:
- black_scholes.h
- black_scholes.cpp

### Week3: Monte Carlo Pricing

Implemented:
- Monte Carlo simulation for option pricing
- support for call options
- payoff abstraction

Design Highlights:
1. payoff abstraction: 新しいpayoffに拡張可能
  - payoff ( interface )
  - callpayoff ( derived classed)

2. Monte Carlo Pricing
  - random number generation using std::mt19937
  - standard normal sampling via std::normal_distribution
  - simulatin under Geometric Brownian Motion:$S_T=S_\cdot \exp( (r- \frac{1}{2}\sigma^2)T + \sigma \sqrt{T} Z\right)
  
### Next Steps
- Greeks Calculation
- Implied Volatility
- yield curve
- interest rate derivatives( FRA or swap)
