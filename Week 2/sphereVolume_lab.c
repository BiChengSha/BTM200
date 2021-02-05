#include<stdio.h>
//#include<math.h>

int main(void) {
	const double SPHERE = 4.0/3.0 * 3.1415926535;
	int radius = 10;
	//double volume = SPHERE * pow(radius, 3);
	double volume = SPHERE * radius * radius * radius;

	printf("Volume of a sphere with a %i-meter radius is: %.2lf\n", radius, volume);

	return 0;
}
