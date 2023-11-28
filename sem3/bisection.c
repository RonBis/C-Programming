#include<stdio.h>
#include<math.h>

float f(float x) {
	return x*x*x - 8*x - 4;
}

int main() {
	float a = -0.5, b, x = 0, x1 = 0, flag = 1;
	int i = 0;
	while(f(a + 0.5) < 0) {
		a += 0.5;
	}
	b = a + 1;
	printf("i  a(+ve)  b(-ve)  xn1=(a+b)/2  f(xn1)\n");
    printf("--------------------------------------\n");
	while(flag > 0.001)
	{
		x = x1;
		x1 = (a+b)/2;
		printf("%d  %.3f   %.3f   %.3f       %.3f \n", i, a, b, x1, f(x1));
		if(f(x1) > 0)
		    b=x1;
		else
		    a=x1;
		flag = fabs(x1-x);
		i++;
	}
	printf("\nRoot of f(x) = x^3-8x-4 is %.2f\n",x1);
	return 0;
}