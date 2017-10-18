

#include<stdio.h>
int main(){
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	int n,d,n1,n2,n3;
	int temph[10];
	int templ[10];
	int total = 0;
	float ave;
	printf("Please enter the number of days between 3 and 10, inclusive:");
	scanf("%d",&d);
	printf("\n");
	while(d<3||d>10){
		printf("Invalid entry, please enter a number between 3 and 10, inclusive:");
		scanf("%d",&d);
	}
	printf("\n");
	for(n=0;n<d;n++){
		printf("Day %d - High:",n+1);
		scanf("%d",&temph[n]);
		printf("Day %d - Low:",n+1);
		scanf("%d",&templ[n]);
		if(temph[n]<templ[n]){
			while(temph[n]<templ[n]){
				printf("Day %d - High:",n+1);
				scanf("%d",&temph[n]);
				printf("Day %d - Low:",n+1);
				scanf("%d",&templ[n]);
			}
		}
	}
	printf("\n");
	printf("Day  Hi  Low\n");
	for(n1=0;n1<d;n1++){
		printf("%-4d %-4d %-4d\n",n1+1, temph[n1], templ[n1]);
	}
	printf("\n");
	while(n2>0){
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",n);
		scanf("%d",&n2);
		printf("\n");
		while((n2<1&&n2>0)||n2>n){
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ",n);
			scanf("%d",&n2);
			printf("\n");
			for(n3=0;n3<n2;n3++){
				total = total + temph[n3] + templ[n3];

			}
			if(n2>0){
			ave = (float)total / ((float)n2 * 2);
			printf("The average temperature up to day %d is: %.2f\n",n2,ave);
			total = 0;
			printf("\n");}
	}
	printf("Goodbye!\n");
	return 0;
} 