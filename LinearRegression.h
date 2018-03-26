#pragma once
#ifndef __LINEAR_REGRESSION_H__
#define __LINEAR_REGRESSION_H__

#define DISTANCE_SQUARE(a, b, x, y) pow((fabs((a) * (x) - (y) + (b)) / sqrt((a) * (a) + 1)), 2)

typedef long double LData; // Linear Equation Data

typedef struct
{
	long double distance;
	long double aValue;
	long double bValue;
} LinearEquation;

/*
a : 기울기
b : y절편
y = ax + b
lengthX : x의 원소의 개수
count : 반복학습할 횟수
*/
LinearEquation *learningLinearEquation(LData *x, LData *y, long double aMin, long double aMax, long double bMin, long double bMax, int lengthX, int count);

// y값을 이용해 x의 값을 예측함.
LData predictX(LinearEquation *solution, LData y);

// x값을 이용해 y값을 예측함.
LData predictY(LinearEquation *solution, LData x);

#endif
