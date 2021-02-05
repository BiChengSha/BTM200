#include<stdio.h>

int main(void) {
	int startHour, startMinute, endHour, endMinute, elapsedHour, elapsedMin;
	double startTime, endTime, elapsedTime;

	printf("Enter the start time (hr:min): ");
	scanf("%d:%d", &startHour, &startMinute);

	startTime = startHour + (startMinute / 60.0);

	printf("Enter the finish time (hr:min): ");
	scanf("%d:%d", &endHour, &endMinute);
	endTime = endHour + (endMinute / 60.0);

	elapsedTime = endTime - startTime;
	elapsedHour = elapsedTime;
	elapsedMin = (elapsedTime - elapsedHour) * 60;

	printf("start at %d:%2d, finish at %d:%2d, elapsed = %d:%02d\n", startHour, startMinute, endHour, endMinute, elapsedHour, elapsedMin);

	return(0);
}
