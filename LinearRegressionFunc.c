#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "LinearRegression.h"

LinearEquation *learningLinearEquation(LData *x, LData *y, long double aMin, long double aMax, long double bMin, long double bMax, int lengthX, int count)
{
	int i, j;

	LinearEquation *distanceSum = (LinearEquation *)calloc(1, sizeof(LinearEquation));
	LinearEquation *distanceMin = (LinearEquation *)calloc(1, sizeof(LinearEquation));
	srand((size_t)time(NULL));

	distanceSum->distance = 0;
	distanceSum->aValue = (double)rand() / RAND_MAX * (aMax - aMin) + aMin; // amin < a < amax 내의 임의의 값으로 설정
	distanceSum->bValue = (double)rand() / RAND_MAX * (bMax - bMin) + bMin; // bmin < b < bmax 내의 임의의 값으로 설정

	for (i = 0; i < lengthX; i++)
		distanceSum->distance += DISTANCE_SQUARE(distanceSum->aValue, distanceSum->bValue, x[i], y[i]);

	memcpy(distanceMin, distanceSum, sizeof(LinearEquation));

	for (i = 1; i < count + 1; i++)
	{
		distanceSum->distance = 0;
		distanceSum->aValue = (double)rand() / RAND_MAX * (aMax - aMin) + aMin; // amin < a < amax 내의 임의의 값으로 설정
		distanceSum->bValue = (double)rand() / RAND_MAX * (bMax - bMin) + bMin; // bmin < b < bmax 내의 임의의 값으로 설정

		for (j = 0; j < lengthX; j++)
			distanceSum->distance += DISTANCE_SQUARE(distanceSum->aValue, distanceSum->bValue, x[j], y[j]);

		if (distanceSum->distance < distanceMin->distance)
			memcpy(distanceMin, distanceSum, sizeof(LinearEquation));

		if (i % 1000 == 0)
			printf("%d번째 학습 중\n", i);
	}

	free(distanceSum);
	return distanceMin;
}

LData predictX(LinearEquation *solution, LData y)
{
	if (solution->aValue == 0)
		printf("a값이 0입니다. 따라서 x는 양 또는 음의 무한대로 발산합니다.");
	return (y - solution->bValue) / solution->aValue;
}

LData predictY(LinearEquation *solution, LData x)
{
	return solution->aValue * x + solution->bValue;
}
