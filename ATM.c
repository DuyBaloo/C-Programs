/*Duy Nguyen - lab 3 - CIS 2107 - ATM - Sep 20th 2017
This program will show an ATM interface letting the user withdraw, deposit, check balance and stop using the ATM. The user will have 3 times to get the right input, otherwise the program will stop. In addition, if the user input invalid choices the program will exit after 3 times. It will show how many transactions the user made.
*/
#include <stdio.h>
#include <stdlib.h>

//initialize and declare variables
float balance = 5000.0, balance1;
int PIN = 3014;

//here I put tries to count the times the user input invalid inputs
//tran to count the number of transactions the user made.
//confirm to get the do while loop to re-appear the screen of activities for the user to choose.
int userinput, choice, tries = 1, tries1 = 1, tries2 = 1, another, tran = 0, confirm;
float amount, withdraw, deposit;


int main(){

	//get the PIN from the user
	puts("Please enter your PIN: ");
	scanf("%d", &userinput);
	
	//if the user puts in the wrong PIN the program will ask the user to redo
	while (tries < 3 && userinput != PIN)
		{
			puts("You have entered the wrong pin, please enter again: ");
			scanf("%d", &userinput);
			++tries;
		}
	
	//when the user already passed 3 tries, the program will appear a message and exit
	if (tries >= 3 && userinput != PIN)
		{
			puts("You have entered the wrong PIN for 3 times, the ATM is now logged off.");
			exit(0);
		}

	//show the menu for the user to choose
	do	
		{
			puts("Please select the activity you want to do: ");
			puts("Press 1 for withdrawal.");
			puts("Press 2 to deposit.");
			puts("Press 3 to check balance.");
			puts("Press 4 to exit.");
			scanf("%d", &choice);
		
		//get the input from the user 
		switch (choice)
		{
			//if the user input 1 as choice
			case 1:
				//get the amount from the user
				puts("Enter the amount you want to withdraw: ");
				scanf("%f", &amount);
				//increase amount of transaction
				++tran;
				//balace1 is to check if the user puts in invalid amount
				balance1 = balance;
			
			//if the user puts in the amount that larger than the balance or negative amount
			do
			{
				if ((balance1 - amount) < 0 || amount < 0)
					{
						puts("The amount you entered is invalid, please enter again: ");
						scanf("%f", &amount);
						++tries1;
					}
				else break;

			} while (tries1 < 3);
			
			//if the user gets 3 wrong tries, program will exit
			if (tries1 > 3)
			{
				puts("You have entered the invalid amount 3 times, the program is exiting.");
				exit(0);
			}

			//if valid amount
			if (amount <= balance && amount > 0)
                                {
                                        balance -= amount;
                                        printf("You withdrew %.1f$ from your account.\n", amount);
                                        printf("You balance now is: %.1f$\n", balance);
					//reset the tries so the user can have 3 tries in later transaction
					tries1 = 1;
                                }
			
			break;

			//if the user input 2 as choice
			case 2:
				//get the amount from user
				puts("Enter the amount you want to deposit: ");
				scanf("%f", &deposit);
				//increase tran to count number of transaction
				++tran;
			
				do
					{
						//if user puts in negative amount
						if (deposit < 0)
							{
								puts("The amount you entered is invalid, please enter again: ");
								scanf("%f", &deposit);
								//count the numbers of tries
								++tries2;
							}
						else break;

					} while (tries2 < 3);
				
				//if the user puts invalid amount 3 times
				if (tries2 > 3)
					{
						//display a message and exit
						puts("You have entered the invalid amount 3 times, the program is exiting.");
						exit(0);
					}
			
				//if valid amount
				if(deposit > 0)
					{
						balance += deposit;
						printf("You deposit %.1f$ into your account.\n", deposit);
						printf("Your balance is now: %.1f$\n", balance);
						//reset the number of tries for later transactions
						tries2 = 1;
					}
				break;

			//if the user input 3 as choice
			case 3:
				printf("Your account balance is: %.1f\n", balance);
				break;

			//if the user input 4 as choice
			case 4:
				//shows how many transations have been made and exit
				printf("You have made %d transaction(s).\n", tran);
				puts("Thank you for using the ATM.");
				puts("See you again.");
				exit(0);
				break;

			//if the user input anything besides the menu
			default:
				puts("Invalid choice.");
		}
	
		//ask if the user wants to make another transaction after every activity is done
		puts("Would you like to make another transaction? 1 for YES, 2 for NO.");
		scanf("%d", &another);
		
		//confirm will be 1 if the user does not want to make another transaction
		if (another == 2)
			confirm = 1;

	//this do while loop will continue to work if confirm is not 1
	}while (!confirm);
	
	//if the user does not want to make another transaction, program will print exit messages
	printf("You have made %d transaciton(s).\n", tran);
	puts("Thank you for using the ATM.");
	puts("See you again.");
}

