/*******************
Name: Joseph Sigar
Tut: 10:30 Tuesday
Assignment 2 code 2
********************/

#include <stdio.h>
#include <ctype.h>

double GetAmount(double amount)
{
	/* Gets amount to be changed in double */
	
	printf("Enter Amount to be changed here: ");
	scanf("%lf%*c", &amount);
	
	return(amount);
}

void ConvChange(double change, int &dollar, int &cent)
{
	/* Converts the changed entered into integer dollars and cents */
	
	dollar = (int)change;
	cent = (int)(((change - dollar)*100)+0.5);
	
	return;
}

void GetChange(double change, int &dollar, int &cent)
{
	/* Only allows the processing of change under certain requirements */

	ConvChange(change, dollar, cent);
	
	while (cent % 5 != 0 || change <= 0)
	{
		printf("\n");
		printf("You have entered an Invalid cent value.\nPlease check The amount of Change entered and try again \n \n");
		
		change = GetAmount(change);
		ConvChange(change, dollar, cent);
	}
	
	return;
}

void CalcChange(int change, int num[], int &rem, int countch[], int valid_val, int x)
{
	/* Counts the change and calculates the remainder of the change entered. */
	
	int i;
	rem = change ;
	
	for (i = x; i < valid_val ; i++)
	{
		/* the var x here indicates the starting point since not all problems would want to start 0*/
		
		countch[i] = rem / num[i];
		rem = rem % num[i];
	}
	
	return;
}

void DisplayResult(int countch[], int num[], int valid_val, int x)
{
	/* countch used to imply counting of change for either the dollar or cents. */
	
	int i;
		
	for (i = x ; i < valid_val ; i++)
	{
		printf("		 %d  		|		%d \n", countch[i], num[i]);
	}
	
	return;
}

void PrintChange(double change, int countd[], int countc[], int num[], int valid_val)
{
	/* Prints the results of the change */
	
	printf("The amount of change required for %lf Dollar is : \n", change);
	printf("Number of Change		|		Dollars\n");
	DisplayResult(countd, num, valid_val , 0);
	printf("Number of Change		|		cents\n");
	DisplayResult(countc, num, (valid_val-2) , 1);
	
	return;	
}
	
int main()
{
	const int VALID_VAL = 7;
	double change;
	int dollar, cent;
	int countc[VALID_VAL - 3];
	int countd[VALID_VAL];
	int num[VALID_VAL] = {100, 50, 20, 10, 5, 2, 1};
	
	change = GetAmount(change);
	GetChange(change, dollar, cent);
	CalcChange(dollar, num, dollar, countd, VALID_VAL, 0);
	CalcChange(cent, num, cent, countc, VALID_VAL-2, 1);
	PrintChange(change, countd, countc, num,  VALID_VAL);

	return(0);
	
}