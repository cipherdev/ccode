#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#if 0
int tong(int a, int b){
	return a+b;
}

int hieu(int a,int b){
	return a-b;
}

int tich(int a, int b){
	return a*b;
}

int main(){
	int (*func)(int,int);
	func=tong;
	printf("%s:%d Tong= %d\n", __func__,__LINE__,func(2,3));
	func=hieu;
	printf("%s:%d Hieu= %d\n", __func__,__LINE__,func(2,3));
	func=tich;
	printf("%s:%d Tich= %d\n", __func__,__LINE__,func(2,3));
	return 0;
}
#endif
#ifdef _function_ponter_
void Tong(int a, int b)
{
	printf("Addition is %d\n", a+b);
}
void Hieu(int a, int b)
{
	printf("Subtraction is %d\n", a-b);
}
void Tich(int a, int b)
{
	printf("Multiplication is %d\n", a*b);
}

int main()
{
	// fun_ptr_arr is an array of function pointers
	void (*fun_ptr_arr[])(int, int) = {Tong, Hieu, Tich};
	unsigned int ch, a = 15, b = 10;

	printf("Enter Choice: \n\t 0 for Tong \n\t 1 for Hieu \n\t 2 for Tich: \n");
	scanf("%d", &ch);

	if (ch > 2) return 0;

	(fun_ptr_arr[ch])(a, b);
	printf("Current File :%s\n", __FILE__ );
	printf("Current Date :%s\n", __DATE__ );
	printf("Current Time :%s\n", __TIME__ );
	printf("Line Number :%d\n", __LINE__ );
	return 0;
}
#endif
