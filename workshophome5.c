

#include <stdio.h>
#define SIZE 4
struct employee{
        int id;
        int age;
        double salary;
};
struct employee emp[SIZE] = {{0}};
int main(){
        int opn;
        int i = 0;
        int b = 0;
        int a = 0;
        int id1;
        printf("---=== EMPLOYEE DATA ===---\n");
        printf("\n");
        do{
                printf("\n");
				printf("1. Display Employee Information\n");
                printf("2. Add Employee\n");
                printf("3. Update Employee Salary\n");
                printf("4. Remove Employee\n");
                printf("0. Exit\n");
                printf("\n");
                printf("Please select from the above options: ");
                scanf("%d",&opn);
                switch(opn){
                	case 2: printf("\n");
     						printf("Adding Employee\n");
                    		printf("===============\n");
                        	if(i < SIZE){
                                printf("Enter Employee ID: ");
                                scanf("%d", &emp[i].id);
                                
                                printf("Enter Employee Age: ");
                                scanf("%d", &emp[i].age);

                                printf("Enter Employee Salary: ");
                                scanf("%lf", &emp[i].salary);
                                i = i + 1;
                        }else if(i >= SIZE){
                                printf("ERROR!!! Maximum Number of Employees Reached\n");
                        } break;
                   
                   case 1: printf("\n");
                     	   printf("EMP ID  EMP AGE EMP SALARY\n");
                           printf("======  ======= ==========\n");
                           for(i=0;i<SIZE;i++){
                  				printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
                           }
                           break;
                   case 3: printf("\n");
                           printf("Update Employee Information\n");
                           printf("===========================\n");
                           printf("Enter Employee ID: ");
                           scanf("%d", &id1);
                           while(id1 != emp[b].id){
                           		b = b + 1;
                           }
                           printf("The current salary is %.2lf\n", emp[b].salary);
                           printf("Enter Employee New Salary: ");
                           scanf("%lf", emp[b].salary);
						   printf("\n");break;
                   case 4: printf("Remove Employee\n");
   			               printf("===============\n");
   			               printf("Enter Employee ID: ");
   			               scanf("%d",&id1);
   			               printf("\n");
   			               while(id1 != emp[a].id){
						   		a = a + 1;
                           }
                           emp[a].id = -1;
                           printf("Employee %d will be removed\n", id1);
                           printf("\n");break;
                   default:printf("\n");
			   			   printf("ERROR: Incorrect Option: Try Again\n");break;
        }}while(opn!=0);
        printf("\n");
        printf("Exiting Employee Data Program. Good Bye!!!\n");
        return 0;
}


