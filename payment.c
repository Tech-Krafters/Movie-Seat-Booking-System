#include<stdio.h>
#include<stdlib.h>
#include"details.c"

int pprice;

int extra(){
    char ch;
    printf("\nWanna buy snacks? Press 'Y' \n");
    scanf("%c",&ch);
    int choice=0;
    if(ch==121 || ch==89){
    printf("                 Dining Options\n");
	printf(" ===============================================================================\n");
	printf("||             1- Small Popcorn                              Rs. 150          ||\n");
	printf("||             2- Medium Popcorn                             Rs. 199          ||\n");
	printf("||             3- Large Popcorn                              Rs. 250          ||\n");
	printf("||             4- Combo-1 (Medium Popcorn + Pepsi)           Rs. 280          ||\n");
	printf("||             5- Combo-2 (Large Popcorn + Pepsi)            Rs. 320          ||\n");
	printf("||============================================================================||\n");
	printf("  Enter your choice: ");
    scanf("%d",&choice);
    }
    return choice;
}
int payment(int choice){
    //ticket t1={100,2,1,2};
    ticket* t = &t1;
    printf(" ==================================================================||\n");
    int val=0;
    if(choice == 1)
    val=150;
    else if(choice==2)
    val=199;
    else if(choice==3)
    val=250;
    else if(choice==4)
    val=280;
    else if(choice==5)
    val=320;
    printf(" Seat Number(s) booked : ");
    for(i=0;i<t->n_seats;i++)
    {
    	printf("%d, ",t->tseats[i]);
	}
	printf("Price Of Each Seat Is: %s\n",data[mid].price);
	pprice = atoi(data[mid].price);
    int tot= (t->n_seats*pprice)+val;
    printf("\n                                                       TOTAL: %d\n",tot);
     printf(" ==================================================================||\n");
}
int payment_main(){

    int choice = extra();
    payment(choice);
    return 0;
}
