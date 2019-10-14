/*******************
Name: Joseph Sigar
Tut: 10:30 Tuesday
Assignment 2 code 1
********************/

#include <stdio.h>
#include <ctype.h>


int GetChange(int change)
{
	/* Gets integer from user regardless of its range */
	
	printf("Enter amount of money to be converted: \n");
	scanf("%d%*c", &change);
	
	return(change);
}

int GetAmount(int change)
{
	/* Limiting the data entered into the input that is required */
	
	change = GetChange(change);
	
	while(change < 5 || change > 95 || change % 5 != 0)
	{
		printf("You have entered and invalid number\n \n");

		change = GetChange(change);
	}
	
	return(change);
}

void CalcChange(int change, int num, int &rem, int &coins)
{
	/* Counts the change and calculates the remainder of the amount entered. */
	
	if (change > num || change < num || change <= 5) 
	{		
		/* This breaks down certian numbers into required denomination. 
		e.g. 50 into 2 20's and 1 10*/
		
		coins = change / num ;
		rem = change % num;
	}
	else
	{
		coins = 0;
		rem = change;
	}
	
	return;
}

void MakeChange(int rem, int &coins1, int &coins2, int &coins3, int &coins4)
{
	/* gathers the number of coins according to each denomination. */

	CalcChange(rem, 50, rem, coins1);
	CalcChange(rem, 20, rem, coins2);
	CalcChange(rem, 10, rem, coins3);
	CalcChange(rem, 5, rem, coins4);
	
	return;
}

void PrintChange(int cent, int coins1, int coins2, int coins3, int coins4)
{
	/* prints the acquired numbers of each denomination*/
	
	printf("The change for the amount %d is:\n \n", cent );
	printf("Number of coins		|	Amount(Change)\n");
	printf("	%d		|		 50 \n", coins1);
	printf("	%d		|		 20 \n", coins2);
	printf("	%d		|		 10 \n", coins3);
	printf("	%d		|		 5 \n \n", coins4);
	
	return;
}

int main()
{
	int change, coins1, coins2, coins3, coins4;
	char choice;
	
	change = GetAmount(change);
	MakeChange(change, coins1, coins2, coins3, coins4);
	PrintChange(change, coins1, coins2, coins3, coins4);

	return(0);
}

