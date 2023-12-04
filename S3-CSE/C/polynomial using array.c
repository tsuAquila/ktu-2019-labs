#include <stdio.h>

void main()
{
	struct Poly
	{
		int coeff;
		int pow;
	} p[10];

	int n;
	printf("Enter the number of terms: ");
	scanf("%d", &n);

	// read polynomial
	for (int i; i < n; i++)
	{
		printf("Enter the coefficient:");
		scanf("%d", &p[i].coeff);

		printf("Enter the power:");
		scanf("%d", &p[i].pow);
	}

	// print the polynomial
	int i;
	for (i = 0; i < n - 1; i++)
	{
		printf("%dx^%d", p[i].coeff, p[i].pow);
		printf(" + ");
	}
	printf("%dx^%d", p[i].coeff, p[i].pow);
	printf("\n");
}
