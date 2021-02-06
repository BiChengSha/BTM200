#include <stdio.h>

int main(void)
{
	double loanAmt, intRate, monthlyPay, remAmt;
	double calcInt[12];

	printf("Enter amount of loan: ");
	scanf("%lf", &loanAmt);
	printf("Enter interest rate: ");
	scanf("%lf", &intRate);
	printf("Enter monthly payment: ");
	scanf("%lf", &monthlyPay);

	printf("%-6s%11s%12s%12s%13s", "Month", "Balance", "Interest", "Payment", "Remaining\n");

	for (int i = 0; i < 12; i++)
	{
		calcInt[i] = loanAmt * (intRate / 100 / 12);
		remAmt = (loanAmt - monthlyPay) + calcInt[i];
		printf("   %02d%12.2lf%12.2lf%12.2lf%12.2lf\n", i + 1, loanAmt, calcInt[i], monthlyPay, remAmt);
		loanAmt = remAmt;
	}

	return 0;
}
