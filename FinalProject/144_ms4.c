#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define DATAFILE "items.txt"

// Constant TAX value:
const double TAX = 0.13;



// Item structure:
struct Item{
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};





// Function Prototypes Milestone 1:
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);





// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(const struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Prototypes Milesone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// Function Prototypes Milesone 4:
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);


// Function Implementations Milestone 1:
// code your functions here:
void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(grandTotal > 0){
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}


void pause(void){
	printf("Press <ENTER> to continue...");
	while(getchar() != '\n');
}

void flushKeyboard(void){
	while(getchar() != '\n');
}

int getInt(void){
	char NL = 'x';
	int VALUE;
	while(NL != '\n'){
		scanf("%d%c",&VALUE,&NL);
		if(NL != '\n'){
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	return VALUE;
}
double getDouble(void){
	char NL = 'x';
	double VALUE;
	while(NL != '\n'){
		scanf("%lf%c",&VALUE,&NL);
		if(NL != '\n'){
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return VALUE;
}

int getIntLimited(int lowerLimit, int upperLimit){
	int value;
	value = getInt();
	while((value < lowerLimit) || (value > upperLimit)){
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		value = getInt();

	}
	return value;
}
double getDoubleLimited(double lowerLimit, double upperLimit){
	double value;
	value = getDouble();
	while((value < lowerLimit) || (value > upperLimit)){
		printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		value = getDouble();
	}
	return value;
}



int yes(void){
	char c;
	int op;
	scanf(" %c", &c);
	flushKeyboard();
	while(c != 'Y' && c != 'y' && c != 'N' && c != 'n'){
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &c);
		flushKeyboard();
	}
	if(c == 'Y' || c == 'y' ){

		op = 1;
	}else{

		op = 0;
	}
	return op;
}

int menu(void){
	int n;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d",&n);
	return n;
}

void GroceryInventorySystem(void){
	int n;
	welcome();
	while(n != 0 ){
		n = menu();
		while(n != 0 && (n < 1 || n > 7)){
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &n);
		}
		switch(n){
			case 1: printf("List Items under construction!\n");
					pause();
					printf("\n");break;
			case 2: printf("Search Items under construction!\n");
					pause();
					printf("\n");break;
			case 3: printf("Checkout Item under construction!\n");
					pause();
					printf("\n");break;
			case 4: printf("Stock Item under construction!\n");
					pause();
					printf("\n");break;
			case 5: printf("Add/Update Item under construction!\n");
					pause();
					printf("\n");break;
			case 6: printf("Delete Item under construction!\n");
					pause();
					printf("\n");break;
			case 7: printf("Search by name under construction!\n");
					pause();
					printf("\n");break;

			case 0: printf("Exit the program? (Y)es/(N)o: ");
					n = yes();

	}


}

}

// Function Implementations Milestone 2:
double totalAfterTax(struct Item item){
	double total;
	if (item.isTaxed){
		total = item.price * item.quantity * (1 + TAX);
	}else{
		total = item.price * item.quantity;
	}
	return total;
}

int isLowQuantity(struct Item item){
		int op;
		if(item.quantity < item.minQuantity){
		op = 1;
	}else{
		op = 0;
	}
	return op;
}

struct Item itemEntry(int sku){
       struct Item item;

	item.sku = sku;
	printf("        SKU: %d\n", item.sku);
	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	flushKeyboard();
	printf("      Price: ");
	item.price = getDoubleLimited(0.01,1000.00);
	printf("   Quantity: ");
	item.quantity = getIntLimited(1,MAX_QTY);
	printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0,100);
	printf("   Is Taxed: ");
	item.isTaxed = yes();

	return item;
}


void displayItem(const struct Item item,int linear){
	if(linear){
		printf("|%3d|%-20s|%8.2lf|  ", item.sku, item.name, item.price);
		if(item.isTaxed){
			printf("%3s","Yes");
		}else{
			printf("%3s","No");
		}
		printf("| %3d | %3d |%12.2lf|",item.quantity, item.minQuantity, totalAfterTax(item));
		if(isLowQuantity(item)){
			printf("***\n");
		}else{
			printf("\n");
		}

	}else{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n",item.minQuantity);

		if (item.isTaxed){
			printf("   Is Taxed: %s\n","Yes");
		}else{
			printf("   Is Taxed: %s\n","No");
		}

		if (isLowQuantity(item) == 1){
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
		}
}

void listItems(const struct Item item[], int noOfItems){
	int i;
	double gTotal = 0;
	printTitle();
	for(i = 0; i < noOfItems; i++){
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		gTotal = gTotal + totalAfterTax(item[i]);
	}
	printFooter(gTotal);}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
	int i;
	int op = 0;
		for (i = 0; i < NoOfRecs; i++) {
		if (item[i].sku == sku) {
			*index = i;
			op =1;
		}
	}
	return op;
}

//Function Impelementation Milestone 3:
void search(const struct Item item[], int NoOfRecs){
	int sku, index;
	int i;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	if((sku > SKU_MIN)&&(sku < SKU_MAX)){
		i = locateItem(item, NoOfRecs, sku, &index);
		if(i == 1){
			displayItem(item[index], FORM);
		}else{
			printf("Item not found!\n");
		}
	}
}


void updateItem(struct Item* itemptr){
	struct Item itemup;
	int flag;
	printf("Enter new data:\n");
	itemup = itemEntry((*itemptr).sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	flag = yes();
	if(flag == 1){
		*itemptr = itemup;
		printf("--== Updated! ==--\n");
	}else if(flag == 0){
		printf("--== Aborted! ==--\n");
	}else{
		printf("Invalid input\n");
	}
}

void addItem(struct Item item[], int *NoOfRecs, int sku){
	struct Item newitem;
	int flag;
	if(*NoOfRecs < MAX_ITEM_NO){
		newitem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		flag = yes();
		if(flag == 1){

			item[*NoOfRecs].sku = newitem.sku;
			strcpy(item[*NoOfRecs].name,newitem.name);
			item[*NoOfRecs].price = newitem.price;
			item[*NoOfRecs].quantity = newitem.quantity;
			item[*NoOfRecs].minQuantity = newitem.minQuantity;
			item[*NoOfRecs].isTaxed = newitem.isTaxed;
			*NoOfRecs = *NoOfRecs + 1;

			printf("--== Added! ==--\n");
		}else{
			printf("--== Aborted! ==--\n");
		}
	}else{
		printf("Can not add new item; Storage Full!\n");
	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs){
	int i, sku, index, flag;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	if((sku > SKU_MIN)&&(sku < SKU_MAX)){
		i = locateItem(item, *NoOfRecs, sku, &index);
		if(i == 1){
			displayItem(item[index], FORM);
			printf("Item already exists, Update? (Y)es/(N)o: ");
			flag = yes();
			if(flag == 1){
				updateItem(item);
			}else{
				printf("--== Aborted! ==--\n");
			}
		}else{
			addItem(item,NoOfRecs,sku);
		}
	}
}
void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
	int sku, i, index, qty;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	if((sku > SKU_MIN)&&(sku < SKU_MAX)){
		i = locateItem(item, NoOfRecs, sku, &index);
		if(i == 1){
			displayItem(item[index], FORM);
			if(stock == 1){
				printf("Please enter the quantity to stock; Maximum of %d or 0 to abort: ", MAX_QTY - item->quantity);
				scanf("%d", &qty);
				if((qty > 0)&&(qty < (MAX_QTY - item->quantity))){
					item->quantity = item->quantity + qty;
					printf("--== Stocked! ==--\n");
				}else if(qty == 0){
					printf("--== Aborted! ==--\n");
				}
			}else if(stock == 0){
				printf("Please enter the quantity to checkout; Maximum of %d or 0 to abort: ", item->quantity);
				scanf("%d", &qty);
				if((qty > 0)&&(qty < item->quantity)){
					item->quantity = item->quantity - qty;
					printf("--== Checked out! ==--\n");
				}else if(qty == 0){
					printf("--== Aborted! ==--\n");
				}
			}
		}else{
			printf("SKU not found in storage!\n");
		}
	}
}

// Function Implementations Milestone :4

void saveItem(struct Item item, FILE* dataFile){
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n",item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}

int loadItem(struct Item* item, FILE* dataFile){
	int op = 0, i;
	i = fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]", &(item->sku), &(item->quantity), &(item->minQuantity), &(item->price), &(item->isTaxed), item->name);
	if(i == 6)
	{
		op = 1; 
	}
	return op;
}

int saveItems(const struct Item item[], char fileName[], int NoOfRecs){
	FILE *fp = NULL;
	int i, op = 0;
	fp = fopen(fileName, "w");
	if(fp !=NULL){
		for(i = 0; i < NoOfRecs; i++){
			saveItem(item[i],fp);
		}
		fclose(fp);
		op = 1;
	}
	return op;
}

int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr){

	FILE *fp = NULL;
	int op = 0;
	*NoOfRecsPtr = 0;
	fp = fopen(fileName,"r");

	if(fp != NULL){
		while(loadItem(&item[*NoOfRecsPtr], fp) != 0){
			*NoOfRecsPtr = *NoOfRecsPtr + 1;
		}
		fclose(fp);
		op = 1;
	}
	return op;



}
