#include<stdio.h>

struct complex{
	int imag;
	float real;
};

struct number{
	struct complex comp;
	int integers;
} num1, num2;

int main(){
	num1.integers = 12;
	num1.comp.imag = 20;
	num1.comp.real = 44.12;
	
	num2.integers = 1;
	num2.comp.imag = 0;
	num2.comp.real = 0.5;
	
	printf("Angka pertama %d %d %.2f\n", num1.integers, num1.comp.imag, num1.comp.real);
	printf("Angka kedua %d %d %.2f\n", num2.integers, num2.comp.imag, num2.comp.real);
}
