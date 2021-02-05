/*
Project: Assignment 1 - movie.c
Authors: Paulina Swierzbinska & BiCheng Sha
Course: BTM200
Date (Due): March 8 2021
*/

#include<stdio.h>
#include<stdbool.h>

int main(void) {

	const int ticketBase = 14;
	const int eveningSC = 3;
	const int snackPass = 15;
	const int vipSC = 5;
	const int vipHr = 17;
	const int movie1Timeslots = 3;
	const int movie2Timeslots = 3;
	const int movie3Timeslots = 2;
	const int movie4Timeslots = 4;
	//const int movie1Times[1][movie1Timeslots][movie1Timeslots] = {{3,15,30},{4,19,0},{6,13,0}};
	//const int movie2Times[1][movie2Timeslots][movie2Timeslots] = {{2,13,30},{3,19,0},{7,13,0}};
	//const int movie3Times[1][movie3Timeslots][movie3Timeslots] = {{1,16,30},{5,14,0}};
	//const int movie4Times[1][movie4Timeslots][movie4Timeslots] = {{1,17,30},{3,10,0},{6,13,0},{7,15,0}};
	const double weekendSC = 1.2;
	const double blockbusterSC = 1.1;
	const double discountYouth = 0.85;
	const double discountSenior = 0.9;
	const double tax = 1.13;
	//const char movieNames[4][30] = {"","","","",};

	int userAge, movieChoice, timeChoice;
	bool validTime = false, addSnack = false, addVIP = false;
	double ageDiscount, taxCost, totalCost;

	/*
	printf("Title\t\t\tBlockbuster\tShowtimes\n");
	printf("The Gentleman\t\tNo\t\tWed 15:30, Thu 19:00, Sat 13:00\n");
	printf("The Invisible Man\tNo\t\tTue 13:30, Wed 19:00, Sun 13:00\n");
	printf("Sonic The Hedgehog\tYes\t\tMon 16:30, Fri 14:00\n");
	printf("Bad Boys for Life\tNo\t\tMon 17:30, Wed 10:00, Sat 13:00, Sun 15:00\n");
	*/

	printf("Enter your age: ");
	scanf("%d", &userAge);
	//printf("Your age is confirmed as %d\n", userAge);

	do {
		printf("Please select from the following movies:\n");
		printf("1- The Gentleman\n");
		printf("2- The Invisible Man\n");
		printf("3- Sonic The Hedgehog\n");
		printf("4- Bad Boys for Life\n");

		scanf("%d", &movieChoice);

		if (movieChoice > 4 || movieChoice < 1){
			printf("Invalid entry, please try again.\n");
		}
	} while (movieChoice > 4 || movieChoice < 1);

	do {
		if (movieChoice == 1){
			printf("Select one of the following showtimes:\n");
			printf("1- Wed 15:30\n");
			printf("2- Thu 19:00\n");
			printf("3- Sat 13:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice > 0 || timeChoice < 3){
				validTime = true;
			}
		} else if (movieChoice == 2) {
			//
			printf("Select one of the following showtimes:\n");
			printf("1- Tue 13:30\n");
			printf("2- Wed 19:00\n");
			printf("3- Sun 13:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice > 0 || timeChoice < 3){
				validTime = true;
			}
		} else if (movieChoice == 3) {
			//
			printf("Select one of the following showtimes:\n");
			printf("1- Mon 16:30\n");
			printf("2- Fri 14:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice > 0 || timeChoice < 3){
				validTime = true;
			}
		} else if (movieChoice == 4) {
			//
			printf("Select one of the following showtimes:\n");
			printf("1- Mon 17:00\n");
			printf("2- Wed 10:00\n");
			printf("3- Sat 13:00\n");
			printf("4- Sun 15:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice > 0 || timeChoice < 3){
				validTime = true;
			}
		}
	} while (validTime == false);

	printf("Would you like to purchase our snack pass? \n");

	return (0);
}
