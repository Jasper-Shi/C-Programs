

/*
== Vehicle Rentals ==

Author	: Gayan Gamage
Date	: 14-02-2017
Revision: 1.0
Workshop: #6 in-Lab

*/

#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

double addPositive (double amount, double newAmount){
	amount = amount + newAmount;
	return amount;
}
/* main program */
int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;							// Variable for "for-loop" counters

   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

   int nodays;
   double  basep;
   double kilo;
   double kiloc;
   double charge;





   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
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
         	printf("%8d%10.2lf\n",vRent[i].id, vRent[i].earnings);
         }

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
            // Display Base Charge, cost for km and the Total 
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");
            printf("%6.2lf %6.2lf %6.2lf\n\n",basep, kiloc, vRent[flag].earnings);

         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}

