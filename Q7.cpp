#include <iostream>
#include <cmath>

void Decomp(double a[3][3], double lower[3][3],double upper[3][3]){

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j < i)
                lower[j][i] = 0;
            else{
                lower[j][i] = a[j][i];
                for(int k = 0; k < i; k++)
                {
                    lower[j][i] = lower[j][i] - lower[j][k] * upper[k][i];
                }
            }
        }
        for(int j = 0; j < 3; j++)
        {
            if(j < i)
                upper[i][j] = 0;
            else if(j == i)
                upper[i][j] = 1;
            else
            {
                upper[i][j] = a[i][j] / lower[i][i];
                for(int k = 0; k < i; k++)
                    upper[i][j] = upper[i][j] - ((lower[i][k] * upper[k][j]) / lower[i][i]);
            }
        }
    }
}


int main()
{
    double matrix[3][3];
    double lower[3][3];
    double upper[3][3];
    double equals[3];
    std::cout << "Enter first equation coefficients: ";
    std::cin >> matrix[0][0] >> matrix[0][1] >> matrix[0][2];
    
    std::cout << "Enter second equation coefficients: ";
    std::cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2];

    std::cout << "Enter third equation coefficients: ";
    std::cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];

    std::cout << "Enter the equaity of the equations: ";
    std::cin >> equals[0] >> equals[1] >> equals[2];

    Decomp(matrix, lower, upper);
    
    std::cout << "lower matrix:\n";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         std::cout<<lower[i][j]<<" ";
      }
      std::cout << std::endl;
   }
   std::cout << "\nUpper matrix:\n";

   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         std::cout<<upper[i][j]<<" ";
      }
      std::cout << std::endl;
   }

    double x = equals[0] / lower[0][0];
    double y = equals[1] - (lower[1][0] * x) / lower[1][1];
    double z = equals[2] - (lower[2][0] * x) - (lower[2][1] * y) / lower[2][2];

    
    std::cout << "\nLower solutions: \n" <<"x1 = "<< x << " x2 = " << y << " x3 = " << z;

    z = equals[2] / upper[2][2];
    y = equals[1] - (upper[1][2] * z) / upper[1][1];
    x = equals[0] - (upper[0][1] * y) - (upper[0][2] * z) / upper[0][0];

    std::cout << "\nUpper solutions: \n" <<"x1 = "<< x << " x2 = " << y << " x3 = " << z;
    
}