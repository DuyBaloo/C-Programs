/*Duy Nguyen - CIS 2107 - Fall 2017 - Sep 9th, 2017 - lab2 - revenue
this program asks user to input item price and quantity, then based on the quantity the program will give a specific amount if discount and calculate the discount amount and total. If the user input invalid inputs the program will display an error and exit the program.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
        //initialize all the variables.
        float cost = 0.0, discount = 0.0, disamount = 0.0, total = 0.0;
        float a, itemPrice, Quantity;

        //ask the user to input employee number and get a to be = employeenumber
        puts("Welcome to 'Temple' store");
        puts("Please input your item price: ");
        scanf("%f", &itemPrice);

        //check if itemPrice is less than or equal to 0
        if (itemPrice <= 0)
                {
                        //prints error and exits program
                        puts("This is not a valid item price, please run the program again.\n");
                        puts("Thank you for using 'TEMPLE' store");
                        exit(0);
                }

        //ask the user to input Quantity and a = Quantity
        puts("Please input your item quantity: ");
        scanf("%f", &Quantity);
	a = Quantity;

        //check if Quantity is negative or equals to 0 or a float, Quantity cannot have fraction
        if(Quantity <= 0 || (int)Quantity != a)
                {
                        //prints out error if the input is invalid and exits program
                        printf("This is not a valid item quantity, please run the program again.\n");
                        printf("Thank you for using 'TEMPLE' store\n");
                        exit(0);
                }

        //check the quantity
        if((int)Quantity >= 1 && (int)Quantity <= 49)
                {
                        //gives 0% as discount if Quantity is between 1 and 49
                        discount = 0.0;
			cost = itemPrice * Quantity;
			total = cost;
		}
	//if Quantity between 50 and 99
        if((int)Quantity >= 50 && (int)Quantity <= 99)
                {
			//gives 10% as discount and calculate cost, discount amount and total
			discount = 10.0;
			cost = itemPrice * Quantity;
			disamount = cost * (discount / 100);
			total = cost - disamount;
                }

	//if Quantity between 100 and 149
	if((int)Quantity >= 100 && (int)Quantity <= 149)
                {
			//gives 15% as discount and calculate cost, discount amount and total
			discount = 15.0;
			cost = itemPrice * Quantity;
			disamount = cost * (discount / 100);
			total = cost - disamount;
                }

	//if Quantity equal or greater than 150
	if((int)Quantity >= 150)
                {
			//gives 25% as discount and calculate cost, discount amount and total
			discount = 25.0;
			cost = itemPrice * Quantity;
			disamount = cost * (discount / 100);
			total = cost - disamount;
                }

        //here the program prints out the format as described in the pdf along with the calculations and information.
        puts("=====================================");
        printf("The item price is: $%.1f\n", itemPrice);
        printf("The order is: %d item(s)\n", (int)Quantity);
        printf("The cost is: $%.1f\n", cost);
        printf("The discount is: %.1f%c\n", discount, 37);
        printf("The discount amount is: $%.1f\n", disamount);
        printf("The total is: $%.1f\n", total);
        puts("Thank you for using 'TEMPLE' store");

//end main
}
