/*
	Program name:	Programming Competition
	Version:	1.0
	Created at:	28 January 2018 01:58
	Author:		Raja Nand Sharma
	E-mail:		rajpeaks@gmail.com
	Git:		http://github.com/raj96
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s {
	char *name;	//Name Record
	int 	d,	//December Record
		j,	//January Record
		diff;	//Difference Record
} Student;

int main() {
	int 	n,			//Total no. of students
		i,			//Counter variables
		winner_index = 0;	//Index of winner in the structure students

	scanf("%d",&n);
	Student students[n];

	//Storing the input of the users
	for(i=0;i<n;i++) {
		students[i].name = (char *)malloc(sizeof(char) * 20);
		scanf("%s",students[i].name);
		scanf("%d",&students[i].d);
		scanf("%d",&students[i].j);
		students[i].diff = abs(students[i].d - students[i].j);
	}

	//Checking for the winner student
	for(i=1;i<n;i++) 
		if(students[winner_index].diff < students[i].diff)
			winner_index = i;

	//Printing the name and number of solved questions
	printf("%s %d\n",students[winner_index].name,students[winner_index].diff);

	return 0;

}
