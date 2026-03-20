#pragma once
#include <algorithm>

//インターフェース
class Payoff
{
public:
	virtual ~Payoff() {}

	//引数：株価S. 戻り値：payoff
	virtual double operator()(double S) const = 0;
};

class CallPayoff :public Payoff
{
public:
	CallPayoff(double K);

	double operator()(double S) const override;

private:
	double K_;
};
