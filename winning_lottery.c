/*
	Program name:	Programming Competition
	Version:	1.0
	Created at:	28 January 2018 18:21
	Author:		Raja Nand Sharma
	E-mail:		rajpeaks@gmail.com
	Git:		http://github.com/raj96
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WINNING_CONSTANT 45

long int winningLotteryTicket(int tickets_size, char** tickets) {
	int 	isWinningPair,      	//To check if pair is a winning pair
		isSeenInFirst[10],	//To see if this number is already seen in the first ticket
		isSeenInSecond[10],	//To see if this number is already seen in the second ticket
		i,j,k,                  //Counter Variables
    		first_length,		//Length of first ticket
		second_length,		//Length of first ticket
		value;	
	long int winningPairs = 0;   	//Total no.of winning pairs

    //Traversing through the tickets
    for(i=0;i<tickets_size;i++) {
	//Storing the length of first ticket
	first_length = strlen(tickets[i]);

        //Initializing the seen marker to 0 for the first part of the ticket
        for(j=0;j<10;j++)
            isSeenInFirst[j] = 0;

	//Mark the digits in isWinningPair in accordance with first part of the ticket
	for(j=0;j<first_length;j++) {
		value = tickets[i][j] - 48;
		if(isSeenInFirst[value]==0)
			isSeenInFirst[value] = 1;
	}

	if((isSeenInFirst[0] & isSeenInFirst[1] & isSeenInFirst[2] & isSeenInFirst[3] & isSeenInFirst[4] & isSeenInFirst[5] & isSeenInFirst[6] & isSeenInFirst[7] & isSeenInFirst[8] & isSeenInFirst[9]) == 1) {
		winningPairs += (tickets_size - (i+1));
		continue;
	}

	//Second part of the ticket calculations
	for(j=(i+1);j<tickets_size;j++) {
		//Storing the length of second ticket
		second_length = strlen(tickets[j]);

		//Initializing the seen marker to 0 for the second part of the ticket
		for(k=0;k<10;k++)
			isSeenInSecond[k] = 0;

		//Calculating sum of digits for the pair
		for(k=0;k<second_length;k++) {
			value = tickets[j][k] - 48;
			if((isSeenInFirst[value]|isSeenInSecond[value]) == 0)
				isSeenInSecond[value] = 1;
		}

		//Checking for the winning conditions
		if( (isSeenInFirst[0] | isSeenInSecond[0]) & (isSeenInFirst[1] | isSeenInSecond[1]) & (isSeenInFirst[2] | isSeenInSecond[2]) & (isSeenInFirst[3] | isSeenInSecond[3]) & (isSeenInFirst[4] | isSeenInSecond[4]) & (isSeenInFirst[5] | isSeenInSecond[5]) & (isSeenInFirst[6] | isSeenInSecond[6]) & (isSeenInFirst[7] | isSeenInSecond[7]) & (isSeenInFirst[8] | isSeenInSecond[8]) & (isSeenInFirst[9] | isSeenInSecond[9]) )
			winningPairs++;

	}

    }

	return winningPairs;
}

int main() {
    int n; 
    scanf("%i", &n);
    char* *tickets = malloc(sizeof(char*) * n);
    for (int tickets_i = 0; tickets_i < n; tickets_i++) {
       tickets[tickets_i] = (char *)malloc(10240 * sizeof(char));
       scanf("%s",tickets[tickets_i]);
    }
    long int result = winningLotteryTicket(n,tickets);
    printf("%ld\n", result);
    return 0;
}

