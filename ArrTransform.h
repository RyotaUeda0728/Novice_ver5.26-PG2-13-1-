#pragma once

const int Quantity = 5;

typedef struct ArrTransform {
	int x[Quantity];
	int y[Quantity];
	int radius[Quantity];
	int speed[Quantity];
	int isShot[Quantity];
}ArrTransform;