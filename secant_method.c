#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 1;
}

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int i = 1, n;

    printf("\n--------------------------------------------");
    printf("------      Newton Raphson method        ------");
    printf("--------------------------------------------\n\n");

    //  Value entry //

    printf("Enter x0: ");
    scanf("%f", &x0);
    printf("Enter x1: ");
    scanf("%f", &x1);

    printf("Enter error: ");
    scanf("%f", &e);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &n);

    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------      Newton Raphson Method        -----------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n|Iteration\t|\t   x0\t\t|\t   x1 \t|\t   x2 \t\t|\t f(x2)\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    while (fabs(f2) > e)
    {
        f0 = f(x0);
        f1 = f(x1);

        // Check for division by zero //
        if (f1 - f0 == 0.0) 
        {
            printf("\nMathematical Error: Division by zero.\n");
            return 1; 
        }

        // The Secant Method Formula //
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2);

        printf("|\t%d \t|\t %f \t|\t %f \t|\t %f \t|\t %f \t|\n", i, x0, x1, x2, f2);

        
        x0 = x1;
        x1 = x2;
        i++;

        if (i > n) 
        {
            printf("\nConvergence not achieved. Maximum iterations reached.\n");
            return 1;
        }

    }
  
    
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\nApproximate Root = %.4f\n", x2);

    return 0;
}
