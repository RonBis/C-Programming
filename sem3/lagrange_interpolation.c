#include <stdio.h>

double lagrange_interpolate(double x, int size, double table[size][2]) {
	double res = 0;
	for(int i=0; i<size; i++) {
		double x_const = table[i][0];
		double y = table[i][1];
		
		double prod = y;
		for(int j=0; j<size; j++) {
			if(j == i) continue;
			
			prod *= ( x - table[j][0] )/( x_const - table[j][0] );
		}
		
		res += prod;
	}
}

int main() {
	int n;
	printf("Number of x inputs: ");
	scanf("%d", &n);
	
	double table[n][2];
	
	// input x
	for(int i=0; i<n; i++) {
		printf("Input x[%d]> ", i);
		scanf("%lf", &table[i][0]);
	}
	
	printf("\n");
	// input f(x) ie: y
	for(int i=0; i<n; i++) {
		printf("Input y[%d]> ", i);
		scanf("%lf", &table[i][1]);
	}
	
	double x;
	printf("\nEnter value for lagrange interpolation: ");
	scanf("%lf", &x);
	
	// interpolation
	x = lagrange_interpolate(x, n, table);
	printf("\nResult: %lf\n", x);
	
	return 0;
}

