#include <iostream>
#include <cmath>

double fx(double x, double y, double a, double b){
    return (a*x) - (b*x*y);
}

double fy(double x, double y, double c, double d){
    return -(c*y) + (d*x*y);
}


int main()
{
    double a = 1.2, b = 1, c = 0.8, d = 1;
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
        k1 = h *(fx(x0,y0, a, b));
        k2 = h * (fx( (x0+h/2), (y0+k1/2) , a, b));
        k3 = h * (fx( (x0+h/2), (y0+k2/2) , a, b));
        k4 = h * (fx( (x0+h), (y0+k3) , a, b));
        
        k = (k1+2*k2+2*k3+k4)/6;
        yvalue = y0+k;

        xValues[i] = x0;
        yValues[i] = y0;
        kvalues[i] = yvalue;

        std::cout << x0 << " " << y0 << " " << yvalue << "\n";

        x0 = x0+h;
        y0 = yvalue;
    }
    
    std::cout << "------------------\n";

    x0 = initX;
    y0 = initY;

    for(int i = 0; i < steps; i++)
    {
        k1 = h *(fy(x0,y0, c, d));
        k2 = h * (fy( (x0+h/2), (y0+k1/2) ,c, d));
        k3 = h * (fy( (x0+h/2), (y0+k2/2) ,c, d));
        k4 = h * (fy( (x0+h), (y0+k3) ,c, d));
        
        k = (k1+2*k2+2*k3+k4)/6;
        yvalue = y0+k;
        
        x2Values[i] = x0;
        y2Values[i] = y0;
        k2values[i] = yvalue;

        std::cout << x0 << " " << y0 << " " << yvalue << "\n";

        x0 = x0+h;
        y0 = yvalue;
    }

for(int i = 0; i < steps; i++)
{
    std::cout << y2Values[i] << ", ";
}
    

}