#include <stdio.h>
#include <stdlib.h>
#include "LinearRegression.h"

int main()
{
	int i = 0;
	LData x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	LData y[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	LinearEquation *linearEquation = NULL;

	linearEquation = learningLinearEquation(x, y, -100, 100, -100, 100, sizeof(x) / sizeof(LData), 5000000);
	printf("%.15f %.15f %.15f\n", linearEquation->distance, linearEquation->aValue, linearEquation->bValue);

	printf("%f %f", predictX(linearEquation, 11), predictY(linearEquation, 11));


	system("pause");
	return 0;
}
