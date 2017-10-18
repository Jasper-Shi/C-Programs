

#include <stdio.h>
int main(){
	int opn;
	int i=0;
	struct employee{
		int id;
		int age;
		double salary;
	} emp[2];
	printf("---=== EMPLOYEE DATA ===---\n");
	printf("\n");
	do{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Please select from the above options: ");
		scanf("%d",&opn);
		if(opn == 2){
			printf("\n");		
			printf("Adding Employee\n");
			printf("===============\n");
			if(i < 2){
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].id);
				
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
			
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].salary);
				
				i = i + 1;
			}else if(i >= 2){
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			printf("\n");
		}else if(opn == 1){
			printf("\n");
			printf("EMP ID EMP AGE EMP SALARY\n");
			printf("====== ======= ==========\n");
			printf("%6d%9d %11.2lf\n", emp[0].id, emp[0].age, emp[0].salary);
			printf("%6d%9d %11.2lf\n", emp[1].id, emp[1].age, emp[1].salary);
			printf("\n");
		}
		
	}while(opn!=0);
	printf("\n");
	printf("Exiting Employee Data Program. Good Bye!!!\n");
	return 0;
} 