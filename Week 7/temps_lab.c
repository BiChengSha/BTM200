#include <stdio.h>

#define NUMS 3

int main() {
	int i, valid, high, low;
	double total = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++) {
		valid = 0;
		do {
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			
			if ((high > 40 || low < -40) || low > high) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			} else {
				valid = 1;
				total = total + high + low;
			}
		} while (valid == 0);
	}
	total = total / (NUMS * 2);
	printf("The average (mean) temperature was: %.2f\n", total);
	return 0;
}