#include <cmath>
#include <iostream>

bool g_InvalidInput = false;

double equal(double a1, double a2)
{
	return (std::abs(a1- a2) * 1000000000000. <= std::min(std::abs(a1), std::abs(a2)));
}

double powerWithUnsignedExponent(double base, unsigned int exponent)
{
//	double result = 1.0;
//	for (int i = 1; i <= exponent; ++i)
//		result *= base;
//	
//	return result;
	if (exponent == 0)
		return 1;
	else if (exponent == 1)
		return base;

	result *= powerWithUnsignedExponent(base, exponent >> 1);
	if (exponent & 0x01 == 1)
		result *= base;

	return result;
}

double power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	if (equal(base, 0.0))
		return 0.0;

	unsigned int absExponent = std::abs(exponent);

	double result = powerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	
	return result;
}

int main(int argc, char *argv[])
{
	std::cout << power(2.0, 2) << std::endl;
	std::cout << power(2.0, -2) << std::endl;
	std::cout << power(0.0, 2) << std::endl;
	std::cout << power(0.0, -2) << std::endl;
	return 0;
}
