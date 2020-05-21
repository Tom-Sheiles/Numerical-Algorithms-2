#include <iostream>
#include <cmath>

using namespace std;

double fa(double x)
{
    return 1/(1+x*x);
}

double fb(double x)
{
    return 0.8+5*x-100*(x*x)+75*(x*x*x)+100*pow(x,5);
}

double fc(double x)
{
    return (pow(x,0.1) *(1.2 - x) * 1-exp(20*(x-1)));
}

int main()
{
    char func;
    cout << "f(x) = [a,b,c]";
    cin >> func;

    double b, a;

    cout << "enter a, b: ";
    cin >> a;
    cin >> b;

    double fx;

    switch (func)
    {
        case 'a':
            fx = fa((b+a)/2);
            break;
        
        case 'b':
            fx = fb((b+a)/2);
            break;
        case 'c':
            fx = fc((b+a)/2);
            break;
    }

    fx = (b-a)*fx;
    cout << "Gaussian Quadrature for function is " << fx;

}