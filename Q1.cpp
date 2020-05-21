#include <iostream>
#include <cmath>

double f(double x)
{
    return 2 * sin(x)-x*x/10;
}

int main()
{
 

    double a = -4, b = -1.5, c = 0;
    double x = b - 0.5 * pow(b-a,2)*(f(b)-f(c))-pow(b-c,2)*(f(b)-f(a)) / (b-a)*(f(b)-f(c))-(b-c)*(f(b)-f(a));

    std::cout << "The function minimum is: " << x << " between -4 and 0";
}