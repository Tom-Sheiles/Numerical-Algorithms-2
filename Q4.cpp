#include <iostream>
#include <cmath>

double f(double x)
{
    return 2 * sin(x)- (x*x)/10;
}

double IQI(double a, double b, double lastB, double fa, double fb, double lastFb){
    return a*fb*lastFb/((fa-fb)*(fa-lastFb)) + b*fa*lastFb/((fb-fa)*(fb-lastFb)) + lastB*fa*fb/((lastFb-fa)*(lastFb-fb));
}
double secant(double a, double b, double fa, double fb){
    return b-fb*(b-a)/(fb-fa);
}
bool b_bisection(double bisection, double a, double b, double lastB, double penultimateB, double s)
{
    double delta = 0.0001;
    return (bisection && fabs(s-b) >= 0.5*fabs(b-lastB)) ||                 
               (!bisection && fabs(s-b) >= 0.5*fabs(lastB-penultimateB)) ||    
               (bisection  && fabs(b-lastB) < delta) ||
               (!bisection && fabs(lastB-penultimateB) < delta);
}

int main()
{
    // BRENT METHOD
    double a = 1.3f,b = 1.5f;
    double epsilon = 0.0001;

    double fa = f(a);
    double fb = f(b);
    
    double lastB = a;
    double lastFb = fa;
    double pb = a;
    double s = 1.79769e+308, fs = 1.79769e+308;
    bool bisection = true;

    while(fabs(fb) > epsilon && fabs(fs) > epsilon && fabs(b-a) > epsilon)
    {
        if(fa != lastFb && fb != lastFb)
        {
            //IQI
            s = IQI(a, b, lastB, fa, fb, lastFb);
        }
        else{
            //SECANT
            s = secant(a, b, fa, fb);
        }

        if(b_bisection(bisection, a, b, lastB, pb, s)){
            //BISECTION
            s = 0.5 * (a+b);
            bisection = true;
        }
        else
        {
            bisection = false;
        }

        fs = f(s);
        pb = lastB;
        lastB = b;

        if(fa*fs < 0) {
            b = s;
        }
        else {
            a = s;
        }

        fa = f(a);
        lastFb = fb;
        fb = f(b);

        if (fabs(fa) < fabs(fb)) {
            std::swap(a, b);
            std::swap(fa, fb);
        }
    }

    std::cout << "The approximate maximum of the function is " << fb << " at x = " << b;
    
}