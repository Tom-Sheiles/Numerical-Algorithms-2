#include <iostream>
#include <cmath>

double fx(double x, double y){
    return (1.2*x) - (0.6*x*y);
}

double fy(double x, double y){
    return -(0.8*y) + (0.3*x*y); 
}


int main()
{
    double a = 1.2, b = 0.6, c = 0.8, d = 0.3;
    double h = 0.1;

    double initX = 2, initY = 1;
    double x0 = initX, y0 = initY;

    double k1, k2, k3, k4, k;
    double yvalue;
    int steps = 30;

    double xValues[30];
    double yValues[30];
    double kvalues[30];

    double x2Values[30];
    double y2Values[30];
    double k2values[30];

    for(int i = 0; i < steps; i++)
    {
        k1 = h *(fx(x0,y0));
        k2 = h * (fx( (x0+h/2), (y0+k1/2) ));
        k3 = h * (fx( (x0+h/2), (y0+k2/2) ));
        k4 = h * (fx( (x0+h), (y0+k3) ));
        
        k = (k1+2*k2+2*k3+k4)/6;
        yvalue = y0+k;

        xValues[i] = x0;
        yValues[i] = y0;
        kvalues[i] = yvalue;

        x0 = x0+h;
        y0 = yvalue;
    }
    
    std::cout << "------------------\n";

    x0 = initX;
    y0 = initY;

    for(int i = 0; i < steps; i++)
    {
        k1 = h *(fy(x0,y0));
        k2 = h * (fy( (x0+h/2), (y0+k1/2) ));
        k3 = h * (fy( (x0+h/2), (y0+k2/2) ));
        k4 = h * (fy( (x0+h), (y0+k3) ));
        
        k = (k1+2*k2+2*k3+k4)/6;
        yvalue = y0+k;
        
        x2Values[i] = x0;
        y2Values[i] = y0;
        k2values[i] = yvalue;

        x0 = x0+h;
        y0 = yvalue;
    }

    for(int i = 0; i < 30; i++)
    {
        std::cout << y2Values[i] << ", ";
    }

}