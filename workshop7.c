

/*
== Vehicle Rentals ==

Name  : Ziyi Shi
Student_id: 124812157
Date    : 23-02-2017
Workshop: #6 in-Lab

*/

#include <stdio.h>

#define distRate1  0.69                 // Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49                 // Rate per Kilometer above 100km

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;                                              // ID of the Rental Vehicle
   double baseDay;                              // Daily Base Price
   double earnings;                     // Total earnings from this rental
};

double addPositive (double amount, double newAmount){
        if(newAmount >= 0){
			amount = amount + newAmount;
        }
        return amount;
}

double taxCalc (double price, double rate){
		double taxes;
		taxes = price * rate;
		return taxes;
}

double subtractPositive (double amount, double newAmount){
        if(newAmount >= 0){
			amount = amount - newAmount;
        }
        return amount;
}
/* main program */
int main()
{
   const int noVehicles = 3;                    // Number of Vehicles
   int option;                                                  // Variable to store the option selected
   int flag;                                                    // Flag to support vehicle ID find
   int tempID;                                                  // To hold user input for vehicle ID
   int i = 0;                                                   // Variable for "for-loop" counters
   double taxRate = 0.14;				// Tax rate is 14%
   double discount = 5;    			// Discount amount for rentals (in CAD)


   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{125, 29.95, 0} };

   int nodays;
   double  basep;
   double kilo;
   double kiloc;
   double charge;
   char d;
   char y;
   char Y; 
   double taxes;
   double gcamount;

   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("3.) Apply Taxes to All Rentals\n");
      printf("4.) Apply Gift Card\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");

         for(i=0;i<noVehicles;i++){
                printf("%8d %10.2lf\n",vRent[i].id, vRent[i].earnings);
         }
         printf("\n");
         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);

         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
 }
         }

         if (flag != -1) {

            printf("Enter Rental Period (in Days): ");
            scanf("%d",&nodays);
                basep = nodays * vRent[flag].baseDay;
                        printf("Enter kilometers driven: ");
            scanf("%lf",&kilo);
            if(kilo > 100){
                kiloc = (kilo - 100) * distRate2 + 100 * distRate1;
            }else{
                kiloc = kilo * distRate1;
            }
            charge = basep + kiloc;
            vRent[flag].earnings = addPositive(vRent[flag].earnings,charge);

            printf("Apply Discount: ");
            scanf(" %c", &d);
            printf("\n");         		
			if(d == 'y' || d == 'Y'){
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings,discount);
            }
            printf("\nBase   kmCost DiscStatus Total\n");
            printf("====== ====== ========== ======\n");
            printf("%6.2lf %6.2lf %10c %6.2lf\n\n",basep, kiloc, d, vRent[flag].earnings);


	
         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;
         
         case 3:
         	printf("\n-- Apply Taxes To all Accounts--\n");
         	printf("\nID#      Earnings   Taxes\n");
         	printf("-------- ---------- ------\n");
         	for(i = 0;i < noVehicles;i++){
	         	taxes = taxCalc(vRent[i].earnings,taxRate);
	         	vRent[i].earnings = addPositive(vRent[i].earnings,taxes);
	         	printf("%8.2d%11.2lf%7.2lf\n",vRent[i].id, vRent[i].earnings, taxes);
	         }
			 printf("\n");
			 break;
         case 4: 
		 	 flag = -1;
         printf("\n-- Apply Gift Card --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);


         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }
         if (flag != -1) {

            // Capture Gift card amount

			printf("Enter Gift Card Amount: ");
			scanf("%lf", &gcamount);
            /* call function subtractPositive with current earnings for the rental and Gift card
            amount as arguments and assign the returned result back to earnings
            */

			vRent[flag].earnings = subtractPositive(vRent[flag].earnings,gcamount);
			printf("Discount Applied\n");
         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         printf("\n");

         break;

      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }

   } while (option != 0);

   return 0;
}

