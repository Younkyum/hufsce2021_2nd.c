#include <stdio.h>

int main() {
	int month, kwh;
	int basicCharge, energyCharge;
	int electricCharge;
	int totalCharge;
	int vat, powerIndustrialFund;

	scanf("%d", &kwh);
	if (kwh <= 200) {
		basicCharge = 910;
		energyCharge = kwh * 93.3;
	}
	else if (kwh <= 400) {
		basicCharge = 1600;
		energyCharge = 200 * 93.3 + (kwh - 200) * 187.9;
	}
	else {
		basicCharge = 7300;
		energyCharge = 200 * 93.3 + 200 * 187.9 + (kwh-400)*280.6;
	}
	electricCharge = basicCharge + energyCharge;
	vat = (int)(electricCharge * 0.1+0.5);
	powerIndustrialFund = (int)((electricCharge * 0.037) - (int)(electricCharge * 0.037)%10);
	totalCharge = electricCharge + vat + powerIndustrialFund - (int)((electricCharge + vat + powerIndustrialFund)%10);
	printf("%d", totalCharge);

	return 0;
}