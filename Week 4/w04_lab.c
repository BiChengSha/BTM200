#include <stdio.h>

int main(void)
{
	double loanAmt, intRate, monthlyPay, remAmt;

	printf("Enter amount of loan: ");
	scanf("%lf", &loanAmt);
	printf("Enter interest rate: ");
	scanf("%lf", &intRate);
	printf("Enter monthly payment: ");
	scanf("%lf", &monthlyPay);

	remAmt = (loanAmt - monthlyPay) + (loanAmt * (intRate / 100 / 12));
	loanAmt = remAmt;
	printf("Balance remaining after first payment: %.2lf\n", remAmt);
	remAmt = (loanAmt - monthlyPay) + (loanAmt * (intRate / 100 / 12));
	loanAmt = remAmt;
	printf("Balance remaining after second payment: %.2lf\n", remAmt);
	remAmt = (loanAmt - monthlyPay) + (loanAmt * (intRate / 100 / 12));
	loanAmt = remAmt;
	printf("Balance remaining after third payment: %.2lf\n", remAmt);
	return 0;
}
