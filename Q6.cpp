#include <iostream>
#include <cmath>

using namespace std;

double fa(double x)
{
    return 1/(1+(x*x));
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

    double c1, c2, x1,x2, a,b;
    cout << "Enter c1, c2, x1, x2";
    cin >> c1;
    cin >> c2;
    cin >> x1;
    cin >> x2;
    cout << "Enter integral limits a, b: ";
    cin >> a;
    cin >> b;

    double limitFactor = (b-a)/2;
    double limitFactor2 = (b+a)/2;

    double fx1, fx2;

    switch (func)
    {
        case 'a':
            fx1 = fa((limitFactor * x1) + limitFactor2);
            fx2 = fa((limitFactor * x2) + limitFactor2);
            break;
        
        case 'b':
            fx1 = fb((limitFactor * x1) + limitFactor2);
            fx2 = fb((limitFactor * x2) + limitFactor2);
            break;
        case 'c':
            fx1 = fc((limitFactor * x1) + limitFactor2);
            fx2 = fc((limitFactor * x2) + limitFactor2);
            break;
    }

    fx1 *= c1;
    fx2 *= c2;
    fx1 += fx2;

    double ans = limitFactor * fx1;

    cout << "The approximate integral of the function is " << ans;

}