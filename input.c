#include <stdio.h>


int main(void){
	//input/temp string character limit
	int char_limit = 20;
	//gets user input
	char input[char_limit];

	//temp string for string reversal
	char temp[char_limit];
	//gets user input
	printf("Enter your input:\n");
	fgets(input,char_limit, stdin);
	printf("%s",input);
	//index counter for loop, runs through string and gets length of actual input
	int i;
	//loop is needed to iterate through input to determine which element in arrays arent null
	for(i = 0; input[i]!='\n';i++);
	if(i>char_limit){
	return 1;
	}
	//sets up counter to count up while down_count counts down
	//this is needed so that it can be used to put reversed characters into the temp array
	//as down_count walks down rev_index walks up through temp, temp[rev_index]
	int rev_index = 0;
	//down_count goes down from the length of the user input, 
	//in order to collect the input in reverse order
	for(int down_count =i-1; down_count>=0;down_count--)
	{
		//assign user input char from right side to temp on left side
		temp[rev_index]=input[down_count];
		//increments rev_index so it can continue on left side of temp array
		rev_index++;
	}
	//new line char so that reversed input is on one line
	printf("\n");
	// reversed string
	printf("reversed: %s\n",temp);
	//user input echoed
	printf("regular: %s\n",input);
	//count of characters in input < char_limit
	printf("string contains %d characters",i); 
	return 0;
}





