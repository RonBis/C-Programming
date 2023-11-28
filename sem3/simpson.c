#include <stdio.h>

double fx(double x) {
    return 1/x;
}

double simpsons(double low, double high, int interval) {
    double h = (high - low) / interval;
    double t = fx(high) + fx(low);
    double term = low+h;

    int multiplier;
    for(int i=1; term <= high-h; i++, term+=h) {
        if(i%2 == 0)
            multiplier = 2;
        else
            multiplier = 4;

        t = t + fx(term) * multiplier;
    }
    t *= h/3;
    return t;
}

int main() {
    double low, high;
    printf("Enter lower and upper limits (separated by space): ");
    scanf("%lf %lf", &low, &high);

    int interval;
    printf("Number of intervals: ");
    scanf("%d", &interval);

    printf("Simpson's method result: %lf\n", simpsons(low, high, interval));
    return 0;
}
