
#include <stdio.h>

#define MAX_TITLE_SIZE 21
//Type the struct here

	struct Book {
        int _isbn;
        float _price;
        int _year;
        char _title[MAX_TITLE_SIZE];
        int _qty;
};

//Type the function prototypes here
void menu();
void displayInventory(const char filename[]);
int searchInventory(FILE *fp,const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[],const int isbn2find);
int readRecord(FILE *fp, struct Book *b2read);
float calculateCapital(const char filename[]);


int main()
{
   //Type your code here:
   int n;
   struct Book mybook; //An object of struct Book 
   char filename[] = "inventory.txt"; //Name of the file
   
   printf("Welcome to the Book Store\n");
   printf("=========================\n");
   
  	while(n != 0){
                menu();
				printf("Select: ");
                scanf("%d", &n);
                switch(n){
                        case 1: displayInventory(filename);break;
                        case 2: addBook(filename,&mybook);break;
                        case 3: checkPrice(filename,mybook._isbn);break;
                        case 4: calculateCapital(filename);break;
						case 0: printf("Goodbye!\n");break;
                        default: printf("Invalid input, try again:\n");break;
                }
                
        }
    
    return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n");
}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
    struct Book book;
    
    //Open the file, and check for null pointer
    FILE *fp = NULL;
    fp = fopen("inventory.txt","r");
    printf("%d\n",readRecord(fp,&book));
    //If the file is properly opened, display headers, similar to workshop 8
    if(fp != NULL){
    	printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
  		printf("---------+-------------------+----+-------+--------\n");

    
    
    //Use a while loop to call readRecord and display the records.
    	while(readRecord(fp,&book) == 2 /*call readRecord and check its return value*/){
        //display the record
        	printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
    
        
    		printf("===================================================\n\n");//Display the footer
    
    		fclose(fp);//Close the file
    	}
	}
}





void addBook(const char filename[], struct Book *b2Add)
{
 printf("Not implemented!");    //Not implemented!
}

void checkPrice(const char filename[],const int isbn2find)
{
    
 printf("Not implemented!"); //Not implemented!

 
}

int searchInventory(FILE *fp,const int isbn2find)
{
 printf("Not implemented!"); //Not implemented!
}


float calculateCapital(const char filename[])
{
    
    FILE *fp;

    struct Book book;//Define an object of struct Book
    
    float total_capital = 0;//Define and initialize total_capital
    
    
    fp = fopen("inventory.txt","r"); //Open the file, and check for null pointer
    
    
    if(fp != NULL){ //If the file is properly opened, use a while loop to call readRecord
    	while(readRecord(fp,&book) == 2/*call readRecord and check its return value*/){
    		
        	total_capital = total_capital + book._price * book._qty;//Accumulate the multiplication of the price of each item to its quantity

    		printf("===================================================\n\n");//Display the footer
    		
    		fclose(fp);//Close the file
    	}
    }
    
        
    return total_capital;//return the total_capital
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    int rv = 0; //Define a variable int rv = 0
    
    rv = fscanf(fp, "%d;%f;%d;%f;;%[^\n]", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), b2read->_title /*Type your code here*/);
   
    return rv; //return rv;

}
