#include <iostream>
#include <cmath>

#define EPSILON 0.00000001

using namespace std;

int solve1stDegEqua(double a, double b, double& x);
int solve2ndDegEqua(double a, double b, double c, double& x1, double& x2);

int main()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;

	cout << "Enter a,b,c (ax2+bx+c=0):\n";
	cin >> a;
	cin >> b;
	cin >> c;

	int numSol = solve2ndDegEqua(a, b, c, x1, x2);

	switch (numSol)
	{
	case 1: cout << "1 solution:\nx = " << x1; break; //1 solution
	case 2: cout << "2 solutions:\nx1 = " << x1 << endl << "x2 = " << x2; break; //2 solutions
	case -1: cout << "Wealth of counter"; break;  //Wealth of counter
	default: cout << "NO solution"; break;
	}
	return 0;
}

int solve1stDegEqua(double in_a, double in_b, double& out_x)
{
	// solve: ax+b = 0
	if (in_a != 0)
	{
		out_x = -in_b / in_a;
		return 1; //1 solution
	}
	if (in_b != 0)
	{
		return 0; // No solution
	}
	return -1; //Wealth of counter
}

int solve2ndDegEqua(double in_a, double in_b, double in_c, double& out_x1, double& out_x2)
{
	// solve: ax2+bx+c = 0

	if (abs(in_a) < EPSILON)
	{
		return  solve1stDegEqua(in_b, in_c, out_x1);
	}
	double delta = in_b * in_b - 4 * in_a * in_c;
	if (delta < 0)
	{
		return 0;
	}
	if (delta == 0)
	{
		out_x1 = out_x2 = -in_b / (2 * in_a);
		return 1; //double solution
	}
	double sqrtDelta = sqrt(delta);
	out_x1 = (-in_b + sqrtDelta) / (2 * in_a);
	out_x2 = (-in_b - sqrtDelta) / (2 * in_a);
	return 2; //2 solutions
}