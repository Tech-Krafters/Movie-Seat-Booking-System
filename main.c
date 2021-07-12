#include<stdio.h>
#include<conio.h>
// #include"details.c"
//#include"file.c"
//#include"seats.c"
//#include"admin.c"
#include"payment.c"

void main()
{

    int p=0;
	do{
  	int choice;
  	printf("WHAT DO U WANNA DO?\n");
  	printf("\n==================================================================\n");
  	printf("||             1- Access only admin                               ||\n");
  	// printf("||             2- To add movie (only admin)                       ||\n");
  	printf("||             2- To purchase ticket                              ||\n");
  	// printf("||             4- To cancel the seat                              ||\n");
  	printf("||             3- Exit system                                     ||\n");
  	printf("||================================================================||\n");
  	printf("  Enter your choice: ");
  	scanf("%d",&choice);

    switch (choice) {
      case 1: admin_main();

              break;
      case 2: details_main();
              break;
      case 3:exit(1);
      default:printf("ERROR 404!");
    }
    system("CLS");
    printf("\nWANNA GO BACK TO MAIN-MENU? ENTER S OR s\n");
    scanf("%c",&p);
    if(p == 'S' || p == 's')
    {
      p = 0;
    }
  }while(p);
}
