#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern double fmean(double x[], uint32_t count);

#define COUNT 3

int main(void)
{
	double x[COUNT];
	double result;
	uint32_t i;

	for(i = 0; i < COUNT; i++) {
		printf("Enter double %d: ", i);
		scanf("%lf", &x[i]); // for displaying a double, we use 'lf' - 64 bit value [ long float). In gcc compiler, 'lf' means a 64 bit floating point value, but in other compilers it will be different
	}

	result = fmean(x, COUNT);
	printf("Mean = %lf\n", result);

	return EXIT_SUCCESS;
}
