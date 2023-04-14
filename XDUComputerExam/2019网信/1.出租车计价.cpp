#include <cstdio>

int main() {
    int startMile = 3;
    double startFee = 10;
    double mileFee = 2;
    int subsidyMile = 10;
    double subsidyFee = 3;

    double mile;
    scanf("%lf", &mile);
    if (mile <= startMile) {
        printf("%.1lf\n", startFee);
    } else if (mile > 3 && mile <= 10) {
        printf("%.1lf\n", startFee + (double)(mile - startMile) * mileFee);
    } else if (mile > 10) {
        printf("%.1lf\n", startFee + (double)(subsidyMile - startMile) * mileFee + (double)(mile - subsidyMile) * subsidyFee);
    }

    return 0;
}
