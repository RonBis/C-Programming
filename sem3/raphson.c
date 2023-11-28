#include <stdio.h>
#include <math.h>

// Function to find the root
double equation(double x) {
    return (x*x*x) - (8 * x) - 4;
}

// Derivative of the function
double derivative(double x) {
    return 3 * (x*x) - 8;
}

// Newton-Raphson Method function
double newtonRaphson(double x0, double epsilon, int max) {
    int i = 0;
    double x = x0;
    while (fabs(equation(x)) > epsilon && i < max) {
        x = x - equation(x) / derivative(x);
        i++;
    }
    if (i == max) {
        printf("Maximum iterations reached. No convergence.\n");
        return -1; // Error code
    }
    return x;
}

int main() {
    double x0, epsilon;
    int maxIterations;

    // Get input values
    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    // Use Newton-Raphson method to find the root
    double root = newtonRaphson(x0, epsilon, maxIterations);
    if (root == -1) {
        return 1; // Error occurred
    }

    // Display the result
    printf("Approximate root: %lf\n", root);
    return 0;
}