/*
Project: Assignment 1 - movie.c
Authors: Paulina Swierzbinska & BiCheng Sha
Course: BTM200
Date (Due): March 12 2021
*/

//INCLUDE C HEADER FILES
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//DECLARE CONSTANTS
const int ticketBase = 14;
const int eveningSC = 3;
const int snackPass = 15;
const int vipSC = 5;
const double weekendSC = 1.2;
const double blockbusterSC = 1.1;
const double discountYouth = 0.15;
const double discountSenior = 0.1;
const double tax = 0.13;

//DECLARE GLOBAL VARIABLES
bool vipEligible = false, isBlockbuster = false;
int timeSlots = 0;

//DECLARE FUNCTIONS
int movieMenu();
int selectTime(int movieChoice);
int selectVIP();
int selectSnack();
int summary(int userAge, int movieChoice, int timeChoice, int vipChoice, int snackChoice);

int main(void) { //MAIN FUNCTION HERE
	int userAge, movieChoice, timeChoice, vipChoice = 0, snackChoice = 0;

	printf("Enter your age: ");
	scanf("%d", &userAge);
//DETERMINING MOVIE CHOICE
	do {
		movieChoice = movieMenu();
		if (movieChoice == 0) {
			printf("Invalid selection: must be between 1 and 4.\n");
		}
	} while (movieChoice == 0);
//DETERMINING MOVIE TIME SLOT
	do {
		timeChoice = selectTime(movieChoice);
		if (timeChoice == 0) {
			printf("Invalid selection: must be between 1 and %d.\n", timeSlots);
		}
	} while (timeChoice == 0);
//CHOOSING VIP OPTION
	if (vipEligible == true) {
		printf("Would you like to purchase VIP seating for ");
		switch (movieChoice){
			case 1:
				printf("The Gentleman ");
				if (timeChoice == 2) {
					printf("Thu 19:00? \n");
				} else if (timeChoice == 3){
					printf("Sat 13:00? \n");
				}
				break;
			case 2:
				printf("The Invisible Man ");
				if (timeChoice == 2) {
					printf("Wed 19:00? \n");
				} else if (timeChoice == 3){
					printf("Sun 13:00? \n");
				}
				break;
			case 3:
				//printf("This is Sonic, there is no VIP. You did something wrong.\n");
				break;
			case 4:
				printf("Bad Boys For Life ");
				if (timeChoice == 1) {
					printf("Mon 17:30? \n");
				} else if (timeChoice == 3){
					printf("Sat 13:00? \n");
				} else if (timeChoice == 4){
					printf("Sun 15:00? \n");
				}
				break;
		}
		do {
			vipChoice = selectVIP();
			if (vipChoice == 0) {
				printf("Invalid selection: must be Y or N\n");
			}
		} while (vipChoice == 0);
	}
//DETERMINING SNACK OPTION
	printf("Would you like to purchase our snack pass? ");
	do {
		snackChoice = selectSnack(snackChoice);
		if (snackChoice == 0) {
			printf("Invalid selection: must be Y or N\n");
		}
	} while (snackChoice == 0);
//PRINT SUMMARY
	summary(userAge, movieChoice, timeChoice, vipChoice, snackChoice);

	return 0;
}
//DISPLAY MAIN MOVIE MENU OPTIONS
int movieMenu(){
	int movieChoice;
	printf("Please select from the following movies: \n");
	printf("1- The Gentleman\n");
	printf("2- The Invisible Man\n");
	printf("3- Sonic The Hedgehog\n");
	printf("4- Bad Boys for Life\n");
	scanf("%d", &movieChoice);
		
	switch(movieChoice){
		case 1:
			timeSlots = 3;
			return 1;
			break;
		case 2:
			timeSlots = 3;
			return 2;
			break;
		case 3:
			isBlockbuster = true;
			timeSlots = 2;
			return 3;
			break;
		case 4:
			timeSlots = 4;
			return 4;
			break;
		default:
			return 0;
	}
}
//DISPLAY MOVIE SHOWTIME OPTIONS
int selectTime (int movieChoice){
	int timeChoice = 0;
	printf("Select one of the following showing times: \n");
	switch (movieChoice){
		case 1:
			printf("1- Wed 15:30\n");
			printf("2- Thu 19:00\n");
			printf("3- Sat 13:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice == 2 || timeChoice == 3) {
				vipEligible = true;
			}
			if (timeChoice >= 1 && timeChoice <= 3){
				return timeChoice;
			} else {
				return 0;
			}
			break;
		case 2:
			printf("1- Tue 13:30\n");
			printf("2- Wed 19:00\n");
			printf("3- Sun 13:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice == 2 || timeChoice == 3) {
				vipEligible = true;
			}
			if (timeChoice >= 1 && timeChoice <= 3){
				return timeChoice;
			} else {
				return 0;
			}
			break;
		case 3:
			printf("1- Mon 16:30\n");
			printf("2- Fri 14:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice >= 1 && timeChoice <= 2){
				return timeChoice;
			} else {
				return 0;
			}
			break;
		case 4:
			printf("1- Mon 17:00\n");
			printf("2- Wed 10:00\n");
			printf("3- Sat 13:00\n");
			printf("4- Sun 15:00\n");
			scanf("%d", &timeChoice);
			if (timeChoice == 1 || timeChoice == 3 || timeChoice == 4) {
				vipEligible = true;
			}
			if (timeChoice >= 1 && timeChoice <= 4){
				return timeChoice;
			} else {
				return 0;
			}
			break;
		default:
		printf("DEFAULTED IN SELECTTIME\n");
		return 0;
	}
}
//PROMPT USER FOR VIP SELECTION (IF AVAILABLE)
int selectVIP(){
	int i = 0;
	char selection[20];	
	scanf("%s", selection);
	//ENABLE C99 COMPLIING IN THE SUBMITTER SO I CAN USE FOR LOOPS. I'M CURRENTLY NOT ALLOWED TO USE THEM AND IT'S INFURIATING
	//for (int i = 0; i < 20; i++) {
	//	selection[i] = tolower(selection[i]);
	//}
	//WHILE LOOP IN PLACE OF A FOR LOOP DUE TO REASONS IN COMMENT ABOVE.
	while (i < 20){
		selection[i] = tolower(selection[i]);
		i++;
	}

	if (selection[0] == 'y') {
		if (((strcmp(selection, "yes")) == 0) || (selection[0] == 'y')) {
			return 2;
		} else {
			return 0;
		}
	} else if (selection[0] == 'n') {
		if (((strcmp(selection, "no")) == 0) || (selection[0] == 'n')) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}
//PROMPT USER FOR SNACK PASS
int selectSnack(){
	int i = 0;
	char selection[20];	
	scanf("%s", selection);
	//ENABLE C99 COMPLIING IN THE SUBMITTER SO I CAN USE FOR LOOPS. I'M CURRENTLY NOT ALLOWED TO USE THEM AND IT'S INFURIATING
	//for (int i = 0; i < 20; i++) {
	//	selection[i] = tolower(selection[i]);
	//}
	//WHILE LOOP IN PLACE OF A FOR LOOP DUE TO REASONS IN COMMENT ABOVE.
	while (i < 20){
		selection[i] = tolower(selection[i]);
		i++;
	}

	if (selection[0] == 'y') {
		if (((strcmp(selection, "yes")) == 0) || (selection[0] == 'y')) {
			return 2;
		} else {
			return 0;
		}
	} else if (selection[0] == 'n') {
		if (((strcmp(selection, "no")) == 0) || (selection[0] == 'n')) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int summary(int userAge, int movieChoice, int timeChoice, int vipChoice, int snackChoice){
	double ageDiscount, taxCost, totalCost = ticketBase;

	printf("********** Seneca Theatre **********\n");
	switch (movieChoice){
		case 1:
			printf("       The Gentleman ");
			if (timeChoice == 1) {
				printf("Wed 15:30 ");
			} else if (timeChoice == 2) {
				printf("Thu 19:00 ");
				totalCost = totalCost + eveningSC;
			} else if (timeChoice == 3){
				printf("Sat 13:00 ");
				totalCost = totalCost * weekendSC;
			}
			break;
		case 2:
			printf("   The Invisible Man ");
			if (timeChoice == 1) {
				printf("Tue 13:30 ");
			} else if (timeChoice == 2) {
				printf("Wed 19:00 ");
				totalCost = totalCost + eveningSC;
			} else if (timeChoice == 3){
				printf("Sun 13:00 ");
				totalCost = totalCost * weekendSC;
			}
			break;
		case 3:
			printf("  Sonic The Hedgehog ");
			totalCost = totalCost * blockbusterSC;
			if (timeChoice == 1) {
				printf("Mon 16:30 ");
			} else if (timeChoice == 2) {
				printf("Fri 14:00 ");
			}
			break;
		case 4:
			printf("   Bad Boys For Life ");
			if (timeChoice == 1) {
				printf("Mon 17:30 ");
				totalCost = totalCost + eveningSC;
			} else if (timeChoice == 2) {
				printf("Wed 10:00 ");
			} else if (timeChoice == 3){
				printf("Sat 13:00 ");
				totalCost = totalCost * weekendSC;
			} else if (timeChoice == 4){
				printf("Sun 15:00 ");
				totalCost = totalCost * weekendSC;
			}
			break;
	}

	printf("%5.2f\n", totalCost);

	if (userAge <= 16) {
		ageDiscount = totalCost * discountYouth;
		printf("                  Age Discount %5.2f\n", ageDiscount);
		totalCost = totalCost - ageDiscount;
	} else if (userAge >= 65){
		ageDiscount = totalCost * discountSenior;
		printf("                  Age Discount %5.2f\n", ageDiscount);
		totalCost = totalCost - ageDiscount;
	}
	
	if (vipChoice == 2) {
		printf("                   VIP Seating  5.00\n");
		totalCost = totalCost + 5;
	}

	if (snackChoice == 2) {
		printf("                    Snack Pass 15.00\n");
		totalCost = totalCost + 15;
	}
	taxCost = totalCost * tax;
	printf("                           Tax %5.2f\n", taxCost);
	totalCost = totalCost + taxCost;
	printf("                         Total %5.2f\n", totalCost);
	return 0;
}