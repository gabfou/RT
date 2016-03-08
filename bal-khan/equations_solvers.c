#include <math.h>
#include <stdio.h>

// double	cubic_polynomial(double a, double b, double c, double d)
// {
// 	double	p;
// 	double	q;
// 	double	u;
// 	double	v;
// 	double	X;
// 	double	delta;

// 	p = (-(b * b) / (3.0 * a * a)) + c / a;
// 	q = (b / (27.0 * a)) * (((2.0 * b * b) / (a * a)) - ((9.0 * c) / a)) + d / a;
// 	delta = (q * q) + (4.0 / 27.0) * p * p * p;

// 	if (delta > 0)
// 	{printf("1\n");
// 		u = ((-q + sqrt(delta)) / 2.0);
// 		v = ((-q - sqrt(delta)) / 2.0);
// 	}
// 	else if (delta < 0)
// 	{printf("2\n");
// 		u = ((-q + sqrt(-delta)) / 2.0); // i * sqrt .....
// 		v = ((-q - sqrt(-delta)) / 2.0); // et je prend qu'une des 3 valeurs
// 	}
// 	else
// 	{printf("3\n");
// 		u = (-q / 2.0);
// 		v = (-q / 2.0);
// 	}
// 		printf("u = %lf\n, v = %lf\n", u, v);
// 		printf("u * v = %lf\n, -(p*p*p) / 27.0 = %lf\n, u + v = %lf\n, -q = %lf\n", u * v, -(p*p*p) / 27.0, u + v, -q);
// 		// printf("u * v = %lf\n, -(p*p*p) / 27.0 = %lf\n, u + v = %lf\n, -q = %lf\n", (q*q +sqrt(-delta)*sqrt(-delta))/4.0, -(p*p*p) / 27.0, u + v, -q);
// 		printf("v1 * u1 = %lf\n", cbrt(v) * cbrt(u));//(cbrt(-q)*cbrt(-q) * -exp(2.0 * M_PI / 3.0) * -exp(-2.0 * M_PI / 3.0))
// 		printf("v1 * u1 = %lf\n", cbrt((q*q +sqrt(-delta)*sqrt(-delta))/4.0));// * -exp(2.0 * M_PI / 3.0) * -exp(-2.0 * M_PI / 3.0)));//cbrt(q*q-sqrt(-delta)*sqrt(-delta))
// 		printf("-p / 3.0 = %lf\n", -p / 3.0); // yayzzzzz
// // v = cbrt(v) ;//* exp((2.0 * M_PI) / 3.0); work in case 1
// // u = cbrt(u) ;//* exp(-(2.0 * M_PI) / 3.0);

//  // u = exp(2.0*M_PI/9.0);
//  // v = exp(-2.0*M_PI/9.0);

//  X = u + v - b/(3.0*a);
//  // X = cbrt(u) + cbrt(v) - (b / (3.0 * a));
// 	//X = (1.0/3.0)*(cbrt(5.0/2.0)- cbrt(50.0) + 1.0);
// 	printf("\n%lf, %lf\n a * X * X * X + b * X * X + c * X + d = %lf\n", u, v, a * X * X * X + b * X * X + c * X + d);
// 	return (a * X * X * X + b * X * X + c * X + d); // changer pour return un y pour les quartics
// }

double		resolver_cardan(double p, double q);
double		solve_cardan(double a, double b, double c, double d);
double		solve_quartic(double a, double b, double c, double d, double e);

double		solve_cardan(double a, double b, double c, double d)
{
	double   p;
	double   q;
	double   ret;

	p = c / a - pow(b, 2) / (3.0 * pow(a, 2));
	q = (2.0 * pow(b, 3)) / (27.0 * pow(a, 3)) - (b * c) / (3.0 * pow(a, 2)) + d / a;
	ret = resolver_cardan(p, q);
	ret = ret -(b / (3.0 * a));
	return (ret);
}

double   resolver_cardan(double p, double q)
{
	double   root;
	double   delta;
	double   rho;
	double   theta;

	root = 0.0;
	delta = pow(q, 2) + (4.0 * pow(p, 3)) / 27.0;
	if (delta < 0)
	{
		rho = sqrt(pow(q, 2) - delta) / 2.0;
		theta = acos(-q / (2.0 * rho));
		root = 2.0 * cbrt(rho) * cos(theta / 3.0) - 2.0;
	}
	else if (delta == 0.0)
		root = cbrt(-4.0 * q);
	else
		root = cbrt((-q + sqrt(delta)) / 2.0) + cbrt((-q - sqrt(delta)) / 2.0);
	return (root);
}


// int		main(void)
// {
// //	cubic_polynomial(1.0, -6.0, 9.0, -1.0);
// 	// cubic_polynomial(6.0, -6.0, 12.0, 7.0);
// 	double	tester;

// 	tester = solve_cardan(1.0, -6.0, 9.0, -1.0);
// 	printf("tester = %lf\n", tester);
// 	printf("%lf truth = \n", 2 * cos(2*M_PI/9));

// 	tester = solve_cardan(6.0, -6.0, 12.0, 7.0);
// 	printf("tester = %lf\n", tester);
// 	printf("%lf truth = \n", (1.0/3.0)*(cbrt(5.0/2.0) - cbrt(50) + 1));

// 	tester = solve_cardan(1.0, 0.0, -18.0, -35.0);
// 	printf("tester = %lf\n", tester);
// 	printf("%lf truth = \n", 5.0);
// 	return (0);
// }

double	solve_quartic(double a, double b, double c, double d, double e)
{
	double	y;
	double	p;
	double	q;
	double	r;
	double	del_o;
	double	del_b;
	double	x0;
	double	x1;
	double	x2;
	double	x3;

	p = -(3.0 * b * b) / 8.0 + c;
	q = (pow(b, 3) / 8.0) - (b * c / 2.0) + d;
	r = -3.0 * (pow(b / 4.0, 4)) + (c * pow(b, 2)) / 16.0 - (b * d) / 4.0 + e;
	y = solve_cardan(8.0, -4.0 * p, 8.0 * r, 4.0 * r * p - pow(q, 2));
	x0 = 0;
	x1 = 0;
	x2 = 0;
	x3 = 0;

	if ((-p + 2 * y) < 0)
	{
		// printf("no solution\n");
		return (0);
	}
	// if ((pow(y, 2) - r) < 0)
	// {
	// 	// printf("no solution_2\n");
	// 	return (0);
	// }
	// if (-q / (2.0 * sqrt(-p + 2 * y)) < 0)
	// {
	// 	// printf("no solution_3\n");
	// 	return (0);
	// }
	del_o = pow((-p + 2.0 * y), 1) - 4.0 * (y + (-q / (2.0 * sqrt(-p + 2.0 * y))));
	del_b = pow((-p + 2.0 * y), 1) - 4.0 * (y - (-q / (2.0 * sqrt(-p + 2.0 * y))));
	if (del_o < 0)
	{del_o = (double)del_o;
		// printf("no solution del_o\n");
	}
	else if (del_o)
	{
		x0 = (-(-p + 2.0 * y) + sqrt(del_o)) / (2.0 * a);
		x1 = (-(-p + 2.0 * y) - sqrt(del_o)) / (2.0 * a);
	}
	else
		x0 = -(-p + 2.0 * y);
	if (del_b < 0)
	{del_o = (double)del_o;
		// printf("no solution del_b\n");
	}
	else if (del_b)
	{
		x2 = (-(-p + 2.0 * y) + sqrt(del_b)) / (2.0 * a);
		x3 = (-(-p + 2.0 * y) - sqrt(del_b)) / (2.0 * a);
	}
	else
		x2 = -(-p + 2.0 * y);

	if (x0)
		return (x0);// - b / 4.0);
	if (x1)
		return (x1);// - b / 4.0);
	if (x2)
		return (x2);// - b / 4.0);
	if (x3)
		return (x3);// - b / 4.0);
	else
		return (0);
}



