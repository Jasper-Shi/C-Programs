

/*
Name:Ziyi Shi
Student number:124812157
Email:zshi1996@gmail.com
Workshop:7
Section:inlab
Date:16 March 2017
*/

#include <stdio.h>
#define SIZE 3
void decompose(const long long pn, int *ads1, int *ads2, int *ads3);

int isValid(const long long pn);

/* main program */
int main(void) {

    int option;
    long long phoneNumber[SIZE] = {0LL};
    int i = 0;
    int a = 0;
    int n1, n2, n3;
    int flag;
    printf("---=== Phone Numbers ===---\n\n");

    do {
        // Display the Option List
        printf("1. Display Phone List\n");
        printf("2. Add a Number\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
        case 0: // Exit the program

            printf("Exiting Phone Number App. Good Bye!!!\n"); break;

        case 1: // Display the Phone List
                // @IN-LAB
            printf("Phone Numbers\n");
            printf("==============\n");
            // Display each number in decomposed form
            for(i = 0; i < SIZE; i++){
            decompose(phoneNumber[i], &n1, &n2, &n3);
            }
			printf("\n"); break; 
        case 2: // Add a Phone Number
                // @IN-LAB
            printf("Add a Number\n");
            printf("============\n");
            if (a >= SIZE) {
                printf("ERROR!!! Phone Number List is Full\n");
            }
            else {
                scanf("%lld", &phoneNumber[a]);
                flag = isValid(phoneNumber[a]);
                if(flag == 1){
                	a++;
                }
                
            }; 
			printf("\n"); break;


        default:
            printf("ERROR!!!: Incorrect Option: Try Again\n\n");

        }

    } while (option != 0);

    return 0;
}

void decompose(const long long pn, int *ads1, int *ads2, int *ads3) {
    int areaCode;
    int prefix;
    int lineNum;
    *ads1 = areaCode;
    *ads2 = prefix;
    *ads3 = lineNum;
    areaCode = pn / 10000000;
    prefix = (int)(pn - (areaCode * 10000000)) / 10000;
    lineNum = pn - areaCode * 10000000 - prefix * 10000;
    if((areaCode > 99 && areaCode <1000) && (prefix > 99 && prefix < 1000) && (lineNum > 999 && lineNum < 10000)){ 
		printf("(%3d)-%3d-%4d\n", areaCode, prefix, lineNum);
		}  
}

int isValid(const long long pn){
	int areaCode;
    int prefix;
    int lineNum;
    areaCode = pn / 10000000;
    prefix = (int)(pn - (areaCode * 10000000)) / 10000;
    lineNum = pn - areaCode * 10000000 - prefix * 10000;
    if((areaCode == 416 || areaCode == 647 || areaCode == 905) && (prefix >= 100 && prefix <= 999)){
    	return 1;
    }else{
    	printf("ERROR!!! Phone Number is not Valid\n");
    	return 0;
    }
    
}