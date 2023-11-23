#include <stdio.h>

// Function to calculate factorial
int _factorial(int n) {
    if (n == 0) return 1;
    return n * _factorial(n - 1);
}

// Function to calculate forward difference table
void calculateForwardDifference(int n, double x[], double y[][n]) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

// Function to perform Newton's forward interpolation
double forwardInterpolation(int n, double x[], double y[][n], double xi) {
    double result = y[0][0];
    double term = 1;
    double u = (xi - x[0]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++) {
        term = term * (u - i + 1) / i;
        result = result + term * y[0][i];
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][n];

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i][0]);
    }

    // Calculate forward difference table
    calculateForwardDifference(n, x, y);

    // Interpolation point
    double xi;
    printf("Enter the interpolation point: ");
    scanf("%lf", &xi);

    // Perform interpolation
    double interpolationResult = forwardInterpolation(n, x, y, xi);
    printf("Interpolated value at x = %.2f is %.4f\n", xi, interpolationResult);

    return 0;
}
