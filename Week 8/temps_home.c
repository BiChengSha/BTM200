#include <stdio.h>

#define NUMS 4

int main() {
	int i, valid, high, low, max = -40, min = 40, hiday, loday;
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
			if (high > max) {
				max = high;
				hiday = i + 1;
			}
			if (low < min) {
				min = low;
				loday = i + 1;
			}
		} while (valid == 0);
	}
	total = total / (NUMS * 2);
	printf("The average (mean) temperature was: %.2f\n", total);
	printf("The highest temperature was %d, on day %d\n", max, hiday);
	printf("The lowest temperature was %d, on day %d\n", min, loday);
	return 0;
}
