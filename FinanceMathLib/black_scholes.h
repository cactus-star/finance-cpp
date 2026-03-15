#pragma once
#include "option.h"

class BlackScholes
{
public:
	static double call_price(const Option& opt);
	static double put_price(const Option& opt);


};

