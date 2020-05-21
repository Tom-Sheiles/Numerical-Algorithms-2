#include <iostream>
#include <cmath>

double f(double x)
{
    return ((-1*x)+4)+4;
}

int main()
{
    //GOLDEN SECTION SEARCH
    double a = 1, b = 10, c, d, ratio = 1.618;

    c = b - (b - a) / ratio;
    d = a + (b - a) / ratio;
    while (abs(c - d) > 0.0001)
    {
        if(f(c) < f(d))
        {
            b = d;
        }
        else
        {
            a = c;
        }   
        c = b - (b - a) / ratio;
        d = a + (b - a) / ratio;
        
    }

    double x = (a+b)/2;
    std::cout << "The shortest ladder must be " << x << "m" << "\n";
}