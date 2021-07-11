#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size1=0,i;
char buffer[1024];
    int row=0, column=0;
    char movie_name[50], new_price[10];
    int price;
    char time[50];
    char mov_name[50];

struct info{
    char movie[50];
    char time[10];
    char price[10];
}data[30];

void add_movie()
{
    FILE *fp,*fs;
	fp = fopen("file2.csv","a+");
	fs = fopen("avseats.txt","a+");
    if (fp == NULL)
    {
        printf("Error");
        exit(-1);
    }
    else
    {
        printf("Enter the movie name : ");
        scanf("%s",&mov_name);
        printf("Set the show timing : ");
        scanf("%s",&time);
        printf("Set the price of ticket");
        scanf("%d",&price);
        fprintf(fp,"%s,%s,%d\n",mov_name,time,price);

        for(i=0;i<100;i++)
        {
        	fprintf(fs,"%d, ",i+1);
		}
		fprintf(fs,"\n");
        printf("Your data has been successfully inserted");
    }
    fclose(fp);
    fclose(fs);
}
void read_movie()
{
    FILE *fp;
	fp = fopen("file2.csv","r");
	size1=0;
    if (fp == NULL)
    {
        printf("Error");
        exit(-1);
    }
    else
    {
        while(fgets(buffer,2000,fp) != NULL){
        row++;
        if (row == 1)
            continue;
        strcpy(data[size1].movie,strtok(buffer, ","));
        strcpy(data[size1].time,strtok(NULL, ","));
        strcpy(data[size1].price,strtok(NULL, ","));
        size1++;
        }
    fclose(fp);
    }
}
void update_movie()
{
    FILE *fp;
	fp = fopen("file2.csv","w");
    if (fp == NULL)
    {
        printf("Error");
        exit(-1);
    }
    else
    {
        printf("Enter the name of movie : ");
        scanf("%s",movie_name);
        printf("Enter the price you want to change : ");
        scanf("%s",&new_price);
        fprintf(fp,"Movie_name,Time,Price\n");
        for (i=0;i<size1+1;i++){
            if (strcmp(movie_name,data[i].movie) == 0)
            {
                strcpy(data[i].price,new_price);
                fprintf(fp,"%s,%s,%s\n",data[i].movie,data[i].time,data[i].price);
            }
            else
            {
                fprintf(fp,"%s,%s,%s",data[i].movie,data[i].time,data[i].price);
            }
        }
        printf("The price has been updated");
    }
    fclose(fp);
}

void print_movie()
{
	for(i=0;i<size1+1;i++)
	{
		printf("%s\n",data[i].movie);
	}
}
int admin_main()
{
    int ch;
    printf("\n==================================================================\n");
  	printf("||             1- Add Movie                               ||\n");
  	// printf("||             2- To add movie (only admin)                       ||\n");
  	printf("||             2- Read Movie                              ||\n");
  	// printf("||             4- To cancel the seat                              ||\n");
  	printf("||             3- Update Movie                                     ||\n");
  	printf("%.15s","\n4- Print Movie\n");
  	printf("||================================================================||\n");
    scanf("%d",ch);
	switch(ch)
    {
    	case 1:	add_movie();
    			break;
    	case 2:	read_movie();
    			break;
    	case 3:	update_movie();
    			break;
		case 4:	print_movie();
    			break;		
    	default: printf("Bye");
	}
	
//    add_movie();
//    read_movie();
//    print_movie();
//    update_movie();
    return 0;
}
