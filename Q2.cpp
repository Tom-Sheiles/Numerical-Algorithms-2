#include <iostream>
#include <cmath>

double f(double x, double c, double t)
{
    return (9.8*x)/c*(1-exp(-(c/x)*t));
}

int main()
{
    double c = 15;
    double t = 9;
    {
        double xl = 50, xu = 100;    
        

        // FALSE POSITION
        double xr = f(xu, c, t)*xl - f(xl,c, t)*xu / (f(xu,c, t)-f(xl,c, t));

        double fs = f(xl,c, t);
        double ft = f(xu,c, t);
        double fr;
        int side = 0;

        for (int n = 0; n < 100; n++)
        {
        xr = (fs*xu - ft*xl) / (fs - ft);
        if (fabs(xu-xl) < 0.01*fabs(xu+xl)) break;
        fr = f(xr,c, t);

        if (fr * ft > 0)
        {
            xu = xr; ft = fr;
            if (side==-1) fs /= 2;
            side = -1;
        }
        else if (fs * fr > 0)
        {
            xl = xr;  fs = fr;
            if (side==+1) ft /= 2;
            side = +1;
        }
        else
        {
            break;
        } 
        }
        std::cout << "a)The mass needed is = "<< xr << "\n";
    }

    c = 80, t = 4;
    //BISECTION SEARCH
    float x0 = 3.0, x1 = 4.0;
    float speed1 = f(x0,c, t);
    float speed2 = f(x1,c, t);
    float x2, speed3;

    do{

        x2 = (x0 + x1) / 2.0f;
        speed3 = f(x2,c, t);
        if(speed1 * speed3  < 36)
        {
            x1 = x2;
            speed2 = speed3;
        }else{
            x0 = x2;
            speed1 = speed3;
        }
    }while (abs(speed3 - 36) <= 0.00001);

    std::cout << "b)A drag coefficient of " << x2 << " is needed\n"; 

}