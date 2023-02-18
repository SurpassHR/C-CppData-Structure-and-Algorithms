#include <stdio.h>

int main() {
    int age;
    printf("Input your age: ");
    scanf("%d", &age);
    printf("Age(years): %d, Age(days): %d\n", age, age * 365);

    return 0;
}