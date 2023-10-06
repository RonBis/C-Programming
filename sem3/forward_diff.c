#include <stdio.h>

int _fact(int n) {
	int fact = 1;
	for(int i=n; i>=2; i--) {
		fact *= i;
	}
	return fact;
}

double fwd_interpolate(double x, int size, double table[size][size+1]) {
	double h = table[1][0] - table[0][0];
	double u = (x - table[0][0]) / h;
	
	double res = 0;
	for(int i=1; i<=size; i++) {
		double t = 1;
		// product of u terms
		for(int j=0; j<i-1; j++) {
			t = t*(u-j);
		}
		
		// divide u term by factorial
		t = t / _fact(i-1);
		
		//multiply by del(y) term
		t = t * table[0][i];
		
		res += t;
	}
	return res;
}

double back_interpolate(double x, double table, int size) {

}

int main() {
	int n;
	printf("Number of x inputs: ");
	scanf("%d", &n);
	
	double table[n][n+1];
	
	// input x
	for(int i=0; i<n; i++) {
		while(1) {
			double xval;
			printf("Input x[%d]> ", i);
			scanf("%lf", &xval);
			
			if(i>=2) {
				if((xval - table[i-1][0]) != (table[1][0] - table[0][0])) {
				printf("Invalid interval, try again\n\n");
					continue; // diff is not the same, retake input
				} else {
					table[i][0] = xval;
					break;
				}
			} else {
				table[i][0] = xval;
				break;
			}
		}
	}
	
	printf("\n");
	// input f(x) ie: y
	for(int i=0; i<n; i++) {
		printf("Input y[%d]> ", i);
		scanf("%lf", &table[i][1]);
	}
	
	// generate del(y)
	int i=2;
	while(i != n+1) {
		for(int j=0; j<n-i+1; j++) {
			table[j][i] = table[j+1][i-1] - table[j][i-1];
		}
		i++;
	}
	
	// display
	printf("\nx\ty");
	for(int k=2; k<n+1; k++) {
		printf("\tdel%d(y)", k);
	}
	printf("\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n+1-i; j++) {
			printf("%.3lf\t", table[i][j]);
		}
		printf("\n");
	}
	
	double x;
	printf("\nEnter value for forward interpolation: ");
	scanf("%lf", &x);
	
	// interpolation
	x = fwd_interpolate(x, n, table);
	printf("Result: %.4lf\n", x);
	
	return 0;
}
