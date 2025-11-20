#include <stdio.h>
#include <math.h>

//  function    //
float f(float x) {
    return (x * x * x) - 2 * x - 7;
}

int main()
{
    float x0, x1, x2; 
    float y0, y1, y2, e; 
    int i = 1, n;    

    printf("\n--------------------------------------------");
    printf("------      Bisection Method        ------");
    printf("--------------------------------------------\n\n");
    
    //  Value entry //

    printf("Enter the value of x0: ");
    scanf("%f", &x0);

    printf("Enter the value of x1: ");
    scanf("%f", &x1);

    printf("Enter the allowed error value: ");
    scanf("%f", &e);

    printf("Number of iterations: ");
    scanf("%d", &n);


    y0 = f(x0);
    y1 = f(x1);

    if (y0 * y1 >= 0) 
    {
        printf("\n!!Error!!\nStarting values are unsuitable.\n");
        printf("The values of f(x0) and f(x1) must have opposite signs.\n\n");
        return 1;
    }


    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------      Bisection Method        -----------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n|Iteration\t|\t  x0\t\t|\t  x1\t\t|\t  x2\t\t|\t f(x2)\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    while (i <= n)
    {
        x2 = (x0 + x1) / 2;
        y2 = f(x2);

        printf("|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\t|\n", i, x0, x1, x2, y2);
        if (fabs(y2) <= e) 
        {
            printf("-----------------------------------------------------------------------------------------------------------------\n");

            printf("\nSolution found after %d iterations.\n", i);
            printf("Root: %f\n", x2);
            return 0; 
        }
        if (y0 * y2 < 0)
        {
            x1 = x2; 
            y1 = y2; 
        }
        else
        {
            x0 = x2; 
            y0 = y2; 
        }
        i++; 
    }

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\nSolution not within %d iterations.\n", i);
    printf("Last calculated value: x2 = %f, f(x2) = %f\n", x2, y2);

    return 0;
}

