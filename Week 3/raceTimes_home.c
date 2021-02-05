#include<stdio.h>
//#define ITERATIONS 3;

int main(void) {
	const int ITERATIONS = 3;
	int totalHour, totalMin;
	double totalTime;
	int startHours[ITERATIONS], startMins[ITERATIONS], endHours[ITERATIONS], endMins[ITERATIONS], elapsedHours[ITERATIONS], elapsedMins[ITERATIONS];
	double startTimes[ITERATIONS], endTimes[ITERATIONS], elapsedTimes[ITERATIONS];

	printf("Enter the start time (hr:min): ");
	scanf("%d:%d", &startHours[0], &startMins[0]);

	for (int i = 0; i < ITERATIONS; i++) {
		printf("Enter the time for lap %d (hr:min): ", i + 1);
		scanf("%d:%d", &endHours[i], &endMins[i]);
	}

	for (int i = 0; i < ITERATIONS - 1; i++)
	{
		startHours[i + 1] = endHours[i];
		startMins[i + 1] = endMins[i];
	}

	for (int i = 0; i < ITERATIONS; i++) {
		startTimes[i] = startHours[i] + (startMins[i] / 60.0);
		endTimes[i] = endHours[i] + (endMins[i] / 60.0);
		elapsedTimes[i] = endTimes[i] - startTimes[i] + 0.000005;
		elapsedHours[i] = elapsedTimes[i];
		elapsedMins[i] = (elapsedTimes[i] - elapsedHours[i]) * 60;
	}

	printf("\nLap   Start  Finish Elapsed\n");

	for (int i = 0; i < 3; i++) {
		printf("  %d    %d:%2d    %d:%2d    %d:%2d\n", i + 1, startHours[i], startMins[i], endHours[i], endMins[i], elapsedHours[i], elapsedMins[i]);
	}

	totalTime = endTimes[2] - startTimes[0];
	totalHour = totalTime;
	totalMin = (totalTime - totalHour) * 60;

	printf("ALL    %d:%2d    %d:%2d    %d:%2d\n", startHours[0], startMins[0], endHours[2], endMins[2], totalHour, totalMin);

	return(0);
}