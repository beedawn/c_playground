#include <stdio.h>


int main(void){

int x = 0;
for(;;)
	{
printf("%d\n",x);
if(x==100000)
	break;

x++;
	}
return 0;

}
