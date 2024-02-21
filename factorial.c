#include <stdio.h>

int main(void){
	int input;
	printf("Enter your number:");
	scanf("%d",&input);
	
	long long int temp=1;
	for(long long int i=1; i<=input; i++){
		temp *= i;
	}

	printf("Factorial: %lld\n",temp);
	return 0;
}
