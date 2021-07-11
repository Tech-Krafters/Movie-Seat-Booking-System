#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<conio.h>
//#include"frame.c"
#include"admin.c"

typedef struct
{
	int id,scr_id,mid,n_seats;
	float paid;
	//char tseats[10][2];
	int tseats[20];
}ticket;

int seats[100],nseats,mid=2,no_movies,i;
ticket t1;

int strtoint(char a[]);		//string to int
void init_seats(int);		//to initialize seats for new movie
void read_seats(int mid);	//stores (mid)th line from avseats in seats[100]
void show_seats();			//Prints seats NOTE: Follows read_seats()
void write_seats(int);			//Writes seats after removing seats chosen by user

//void show_ticket(ticket);	//Optional ticket print
//void show_seats1(screen *s)	//Optional seats print


void seats_main()
{
	int ind,i=0;		//mid=Movie id as per menu	//if mid>no. of movies, mid->last line/last movie
	read_seats(mid);
	read_movie();
	no_movies = size1;
//	printf("Size: %d",no_movies);
	printf("Enter the no. of seats: ");
	scanf("%d",&nseats);
	t1.n_seats = nseats;
	while(i<nseats)
	{
		//clrscr();		//for turbo
		system("CLS");
		show_seats();
		printf("\nEnter seat no.: ");
		scanf("%d",&ind);
		if(seats[ind-1]==0)
		{
			printf("That seat is unavailable");
			getch();
		}
		else if(seats[ind-1]==2)
		{
			printf("That seat is already chosen");
			getch();
		}
		else
		{
			seats[ind-1]=2;
			t1.tseats[i] = ind;
			i++;
		}
	}
	system("CLS");
	show_seats();
//	for(i=0;i<nseats;i++)
//	printf("%d ",t1.tseats[i]);
	write_seats(mid);
	system("CLS");
	payment_main();

}

int strtoint(char a[6])	// "1234" to 1234
{
	int n=0,i=0;
	while(i<strlen(a))
	{
		if(a[i]<48 && a[i]>57)
		{
			printf("The string does not contain numeric\n");
			break;
		}
		n=n*10+a[i]-48;
		i++;
	}
	return n;
}


void read_seats(int mid)	//mid = movie id
{
	for(i=0;i<100;i++)
	seats[i]=0;
	FILE* fs;
	fs = fopen("avseats.txt","r");
	if (!fs)
        printf("Can't open file\n");

    else {
        char buffer[1024];
		int line,count=0;
		for(line=1;line<=mid;line++)
		fgets(buffer,1024,fs);
		char* value = strtok(buffer, ", ");
        while (value) {
            //printf("%s\n", value);
            seats[strtoint(value)-1]=1;
            value = strtok(NULL, ", ");
            count++;
        }
        fclose(fs);
        printf("No. of available seats: %d\n",count-1);
        t1.id = (count-1)*mid;
    }
}

void show_seats()
{
//	for(i=0;i<size;i++)
//	{
//		if((i%10)==0)
//		printf("\n");
//		if(seats[i]==1)
//		printf("\t1");		//Available; design/"1" can be changed
//		else if(seats[i]==0)
//		printf("\t0");		//Unvailable; design/"0" can be changed
//		else if(seats[i]==0)
//		printf("\tx");		//Chosen; design/"0" can be changed
//	}
	for(i=0;i<100;i++)
	{
		if((i%10)==0)
		printf("\n");
		if(seats[i]==1)
		printf("\t%d",i+1);		//Available; design/"1" can be changed
		else if(seats[i]==0)
		printf("\t0");		//Unvailable; design/"0" can be changed
		else if(seats[i]==2)
		printf("\tx");		//Chosen; design/"0" can be changed
	}
}

void write_seats(int mid)
{
	FILE* fw;
	FILE* fr;
	fr = fopen("avseats.txt","r+");
	fw = fopen("temp.txt","w");
	if (!fr)
        printf("Can't open file\n");
    else
    {
    	char buffer[1024];
		int line;
    	for(line=1;line<mid;line++)
		{
			fgets(buffer,1024,fr);
			fprintf(fw,"%s",buffer);
		}
		fgets(buffer,1024,fr);
		for(i=0;i<100;i++)
		{
			if(seats[i]==1)
			fprintf(fw,"%d, ",i+1);
		}
		fprintf(fw,"\n");
		for(line=mid+1;line<=no_movies+1;line++)
		{
			fgets(buffer,1024,fr);
			fprintf(fw,"%s",buffer);
		}

	}
	fclose(fw);
	fclose(fr);
	remove("avseats.txt");
	rename("temp.txt","avseats.txt");
}


//void show_seats1(screen *s)
//{
//	printf("\t",65+i);
//	for(i=0;i<10;i++)
//	{
//		printf("\t%c",65+i);
//	}
//	for(i=0;i<10;i++)
//	{
//		printf("\n\n\t%d\t",i+1);
//		for(j=0;j<10;j++)
//		if(s->seats[i][j]==0)
//		printf("0\t");
//		else
//		printf("#\t");
//
//	}
//}

//void show_ticket(ticket *t)
//{
//	printf("Ticket ID: %d\nScreen: %d\nMovie ID: %d\nNo. of seats: %d\n",t->id,t->scr_id,t->mid,t->n_seats);
//	for(i=0;i<t->n_seats;i++)
//	{
//		printf("%s",t->tseats[i]);
//	}
//	FILE *fp;
//	fp = fopen("tickets.csv","w");
//	if ( fp == NULL )
//    {
//        printf( "file failed to open." );
//    }
//	fprintf(fp, "%d,%d,%d,%d\n",t->id,t->scr_id,t->mid,t->n_seats);
//	//fprintf(fp, "jaa,12,8:00,300");
//	fclose(fp);
//}
