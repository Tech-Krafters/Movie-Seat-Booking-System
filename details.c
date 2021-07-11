#include<stdio.h>
//#include"moviedetails.c"
//#include"file.c"
#include"seats.c"
// #include"admin.c"



struct moviedetails{
	char name[50];
	char phone[10];
	char adhaar[13];
}md;

void write_user()
{

}

//
// int choice1(void)
// {
// 	int choice;
// 	printf("                 Simple Movie Ticket Booking System\n");
// 	printf("\n==================================================================\n");
// 	printf("||             1- To edit price of ticket (only admin)            ||\n");
// 	printf("||             2- To view reserved tickets (only admin)           ||\n");
// 	printf("||             3- To purchase ticket                              ||\n");
// 	printf("||             4- To cancel the seat                              ||\n");
// 	printf("||             5- Exit system                                     ||\n");
// 	printf("||================================================================||\n");
// 	printf("  Enter your choice: ");
// 	scanf("%d",&choice);
// 	return choice;
// }

// void movie()
// {
//
// }




void details_main(){


// char temp[100];
FILE *fp;
	fp = fopen("details.csv","a");
printf("\nNAME :");
 scanf("%s",&md.name);

 printf("\nNUMBER :");
 scanf("%s",&md.phone);

 printf("\nAADHAAR CARD DETAILS :");
 scanf("%s",&md.adhaar);

 fprintf(fp, "%s,%s,%s,%d\n",md.name,md.phone,md.adhaar,t1.id);
 fprintf(stdout, "%s, %s, %s, %d\n",md.name,md.phone,md.adhaar,t1.id);

read_movie();

  printf("\nPLEASE SELECT THE MOVIE U WANNA WATCH :");
  printf("\n================================================================\n");
	for(i=0;i<size1;i++)
    {
        printf("%10s "," PRESS");
        printf("%d For : %10s\n",i+1,data[i].movie);
    }
  printf("================================================================\n");
  printf(" Enter your choice: ");
	scanf("%d",&mid);
	seats_main();
 	fclose(fp);
}
