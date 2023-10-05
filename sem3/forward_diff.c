#include <stdio.h>

int main() {
	int n;
	printf("Number of x inputs: ");
	scanf("%d", &n);
	
	double table[n][n+1];
	
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
	
	return 0;
}
