#include <stdio.h>
#include <string.h>

int checkAge(int age){
	if (age >= 18 && age <= 35) {
		return 0;
	} else if (age >= 36 && age <= 55) {
		return 1;
	} else if (age > 55) {
		return 2;
	} else {
		printf("Invalid age.\n");
		return (-1);
	}
}

int checkRating(char rating[15]){
	/*//convert all to lowercase
	int i = 0;
	for (i; i < 15; i++) {
		if (rating[i] >= 65 && rating[i] <= 90){
			rating[i] = rating[i] + 32;
		}
	}*/
	if (strcmp("Fair", rating) == 0) {
		return 0;
	} else if (strcmp("Good", rating) == 0) {
		return 1;
	} else if (strcmp("Excellent", rating) == 0) {
		return 2;
	} else {
		printf("Invalid score.\n");
		return (-1);
	}
}

int main(void) {

	int userAge, ageGroup, scoreGroup;
	char userJc, userHc;
	char userJob[5], userHouse[5], userRating[15];

	printf("---=== Credit Card Application ===---\n");
	printf("Enter your age: ");
	scanf("%d%*c", &userAge);
	ageGroup = checkAge(userAge);
	if (ageGroup < 0) {
		return 0;
	}
	printf("Do you have a job? ");
	scanf("%s", userJob);
	userJc = userJob[0];
	printf("Do you own a house? ");
	scanf("%s", userHouse);
	userHc = userHouse[0];
	printf("Enter the credit rating: ");
	scanf("%s", userRating);
	scoreGroup = checkRating(userRating);

	switch (ageGroup){
		case 0:
			if (userJc == 'y' || userHc == 'y' || scoreGroup >= 1) {
				printf("approved\n");
			} else {
				printf("not approved\n");
			}
			break;
		case 1:
			if (userJc == 'y' || userHc == 'y' || scoreGroup >= 1) {
				printf("approved\n");
			} else {
				printf("not approved\n");
			}
			break;
		case 2:
			if (userJc == 'y' || userHc == 'y' || scoreGroup >= 1) {
				printf("approved\n");
			} else {
				printf("not approved\n");
			}
			break;
	}
	return 0;
}
