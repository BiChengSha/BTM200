#include <stdio.h>

int main(void) {

	int startHour, startMinute, startSecond, addHour, addMinute, addSecond, resultDay, resultHour, resultMinute, resultSecond;

	printf("Enter an initial 24-hour time as hours minutes and seconds (0 to stop): ");
	scanf("%d %d %d", &startHour, &startMinute, &startSecond);
	printf("Enter the time to add as hours minutes and seconds: ");
	scanf("%d %d %d", &addHour, &addMinute, &addSecond);

	resultSecond = (startSecond + addSecond);
	resultMinute = (resultSecond / 60) + startMinute + addMinute;
	resultSecond = resultSecond % 60;
	resultHour = (resultMinute / 60) + startHour + addHour;
	resultMinute = resultMinute % 60;
	resultDay = resultHour / 24;
	resultHour = resultHour % 24;

	printf("Total is ");

	if (resultHour == 0 || resultHour == 12){
		printf("12");
	} else if (resultHour < 12){
		printf("%d", resultHour);
	} else if (resultHour > 12) {
		printf("%d", resultHour - 12);
	}

	printf(":%02d:%02d", resultMinute, resultSecond);

	if (resultHour == 0){
		printf(" AM");
	} else if (resultHour < 12){
		printf(" AM");
	} else if (resultHour == 12){
		printf(" PM");
	} else if (resultHour > 12) {
		printf(" PM");
	}

	if (resultDay == 1) {
		printf(" tomorrow");
	} else if (resultDay > 1) {
		printf(" in %d days", resultDay);
	}
	printf("\n");
	return 0;
}