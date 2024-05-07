#include <stdio.h>
long double result = 2.00;

void divide(double num) {
result = result + 1/num;
}

int main() {
long double fat = 1;
for (int i = 2; i < 64; i++) {
fat = fat*i;
divide(fat);
}
printf("\n%.70Lf\n", result);
return 0;
}
