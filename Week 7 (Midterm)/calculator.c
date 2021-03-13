#include <stdio.h>

int main(void) {
	char input[15], firsts[15], seconds[15];
	char operator, ntype = 'i';
	double firstd = 0.0, secondd = 0.0, resultd;
	int ind = 0, checkf, fdecimal = 0, sdecimal = 0, firsti = 0, secondi = 0, resulti;

	printf("Enter values to calculate (example: 3 + 7): ");
	scanf("%[^\n]%*c", input);

	for (int i = 0; i < 15; i++) {
		if (input[i] == ' '){
		} else if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
			firsts[i] = input[i];
		} else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%') {
			operator = input[i];
			ind = i;
		}
	}
	for (int i = 0; i < 15; i++) {
		seconds[i] = input[i + ind + 1];
	}
	for (int i = 0; i < 15; i++) {
		if (firsts[i] == '.' || seconds[i] == '.'){
			ntype = 'd';
		}
	}
    if (ntype == 'i') {
	    for (int i = 0; i < 15; i++) {
			if (firsts[i] >= 48 && firsts[i] <= 57)	{
				firsti = firsti + (firsts[i] - 48);
				firsti = firsti * 10;
			} else {
				break;
			}
		}
		firsti = firsti / 10;
		for (int i = 0; i < 15; i++) {
			if (seconds[i] >= 48 && seconds[i] <= 57)	{
				secondi = secondi + (seconds[i] - 48);
				secondi = secondi * 10;
			}
		}
		secondi = secondi / 10;
		switch(operator) {
			case '+':
				resulti = firsti + secondi;
				printf("%d\n", resulti);
				break;
			case '-':
				resulti = firsti - secondi;
				printf("%d\n", resulti);
				break;
			case '*':
				resulti = firsti * secondi;
				printf("%d\n", resulti);
				break;
			case '/':
				if (secondi == 0) {
					printf("ERROR: CANNOT DIVIDE BY 0\n");
				} else {
					resultd = (double) firsti / secondi;
					printf("%.2lf\n", resultd);
				}
				break;
			case '%':
				if (secondi == 0) {
					printf("CANNOT DO MODULUS BY ZERO\n");
				} else {
					resulti = firsti % secondi;
					printf("%d\n", resulti);
				}
				break;
			default:
				printf("INVALID OPERATOR\n");
		}
	} else if (ntype == 'd') {
	    for (int i = 0; i < 15; i++) {
				if (firsts[i] >= '0' && firsts[i] <= '9') {
					firstd = firstd + ((firsts[i] - 48.0)/100);
					firstd = firstd * 10.0;
				} else if (firsts[i] == '.'){
					fdecimal = 1;
				} else {
					break;
				}
			}
			if (fdecimal == 0) {
				firstd = firstd * 10;
			}
    	for (int i = 0; i < 15; i++) {
				if (seconds[i] == ' ') {
					// do nothing
				} else if (seconds[i] >= '0' && seconds[i] <= '9') {
					secondd = secondd + ((seconds[i] - 48.0)/100);
					secondd = secondd * 10.0;
				} else if (seconds[i] == '.'){
					sdecimal = 1;
				}
			}
			if (sdecimal == 0) {
				secondd = secondd * 10;
			}
		   	switch(operator) {
			case '+':
				resultd = firstd + secondd;
				printf("%.2lf\n", resultd);
				break;
			case '-':
				resultd = firstd - secondd;
				printf("%.2lf\n", resultd);
				break;
			case '*':
				resultd = firstd * secondd;
				printf("%.2lf\n", resultd);
				break;
			case '/':
				if (secondd == 0.0) {
					printf("ERROR: CANNOT DIVIDE BY 0\n");
				} else {
					resultd = (double) firstd / secondd;
					printf("%.2lf\n", resultd);
				}
				break;
			case '%':
				printf("CANNOT DO MODULUS ON NON INTEGRAL VALUES\n");
				break;
			default:
				printf("INVALID OPERATOR\n");
		}
	}
	return 0;
}