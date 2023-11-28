#include <stdio.h>

double fx(double x) {
    return 1 / (1 + x);
}

double trapezoidal(double low, double high, int interval) {
    double h = (high - low) / interval;
    double t = fx(high) + fx(low);
    for(double i=low+h; i <= high-h; i+=h) {
        t = t + 2*fx(i);
    }
    t *= h/2;
    return t;
}

int main() {
    double low, high;
    printf("Enter lower and upper limits (separated by space): ");
    scanf("%lf %lf", &low, &high);

    int interval;
    printf("Number of intervals: ");
    scanf("%d", &interval);

    printf("Trapezoidal method result: %lf\n", trapezoidal(low, high, interval));
    return 0;
}