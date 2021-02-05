#include<stdio.h>
//#include<math.h>

int main(void) {
	const double SPHERE = 4.0/3.0 * 3.1415926535;
	float radius;
	double volume;

	printf("Please enter the radius of the sphere (in m): ");
	scanf("%f&*c", &radius);

	//volume = SPHERE * pow(radius, 3);
	volume = SPHERE * radius * radius * radius;

	printf("Volume of a sphere with a %.2f-meter radius is: %.2lf\n", radius, volume);

	return 0;
}
