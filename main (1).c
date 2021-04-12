#include <stdlib.h>
#include <math.h>

double count_tan(double arg, double eps)
{
    double tanx;
    double sinx = arg, sin_temp = arg;
    double cosx = 1, cos_temp = 1;
    double n;
    
    n = 0;
    while (fabs(sin_temp) > eps)
    {
        n++;
        sin_temp *= -arg*arg/(2.0*n)/(2.0*n+1.0);
        sinx += sin_temp;
    }
    
    n = 0;
    while (fabs(cos_temp) > eps)
    {
        n++;
        cos_temp *= -arg*arg/(2.0*n)/(2.0*n-1.0);
        cosx += cos_temp;
    }
    
    if (cosx == 0)
        exit(1);
    else
        tanx = sinx/cosx;

    return tanx;
}

#define test_number 6
int main()
{
    double eps = 0.001;
    double arg[test_number] = {0, 3.141, 3.141, 6.282, 1, 5};
    double res[test_number] = {0.000000, -0.000593, -0.01, -0.001185, 1.557408, -3.380515};
    
    for(int i = 0; i < test_number; i++)
    {
        double tanx = count_tan(arg[i], eps);
        if (fabs(tanx-res[i]) > eps)
        {
            return 1;
        }
    }
    
    return 0;
}