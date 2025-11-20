#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 1;
}

float g(float x) {
    return 3*x*x - 1;
}

int main() {
    float x0, x1, f0, g0, e;
    int i = 1, n;

    printf("\n--------------------------------------------");
    printf("------      Newton Raphson method        ------");
    printf("--------------------------------------------\n\n");

    //  Value entry //

    printf("Enter x0: ");
    scanf("%f", &x0);

    printf("Enter relative error: ");
    scanf("%f", &e);

    printf("No of iterations: ");
    scanf("%d", &n);


    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------      Newton Raphson Method        -----------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n|Iteration\t|\t   x0\t\t|\t   f(x0) \t|\t   x1 \t\t|\t f(x1)\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    while (fabs(f(x1)) > e)
    {
        f0 = f(x0);
        g0 = g(x0);

        // Check for division by zero //
        if (g0 == 0.0) 
        {
            printf("\nMathematical Error: Division by zero.\n");
            printf("The derivative is zero at x = %.4f.\n", x0);
            return 1;
        }

        // The Newton-Raphson Formula //
        x1 = x0 - f0 / g0;

        printf("|\t%d \t|\t %f \t|\t %f \t|\t %f \t|\t %f \t|\n", i, x0, f0, x1, f(x1));
        
        x0 = x1;
        i++;

        if (i > n) 
        {
            printf("\nConvergence not achieved. Maximum iterations reached.\n");
            return 1; 
        }

    } 

    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("\nApproximate Root = %.4f\n", x1);

    return 0;
}
