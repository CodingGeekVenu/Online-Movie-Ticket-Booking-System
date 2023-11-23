#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define NUM_ROWS 5
#define NUM_COLS 10

struct book
{
    char code[20];
    char name[20];
    char date[20];
    int cost;
}b;
int seat = 50 ;
int seats[NUM_ROWS][NUM_COLS];


void initializeSeats() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            seats[i][j] = 0;
        }
    }
}


void displaySeats() {
    printf("\n");
    printf("Seat Arrangement:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (seats[i][j] == 0) {
                printf("O "); 
            } 
            else if (seats[i][j] == 0) {
                printf("R ");
            }else {
                printf("X "); 
            }
        }
        printf("\n");
    }
}


void bookSeat(int row, int col) {
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
        if (seats[row][col] == 0) {
            seats[row][col] = 1;
            printf("\nSeat in row %d, column %d booked successfully!\n", row + 1, col + 1);
        } else {
            printf("\nSeat in row %d, column %d is already booked. Please choose another seat.\n", row + 1, col + 1);
        }
    } else {
        printf("Invalid seat selection. Please choose a valid seat.\n");
    }
}


void insert_details()
{
    FILE *fp;
    struct book b;
    printf("Enter movie code :- "); 
    scanf("%s",b.code);
    printf("Enter  name :- ");  
    scanf("%s",b.name);
    printf("Enter Release Date:- ");    
    scanf("%s",b.date);
    printf("Enter Ticket Price:- ");    
    scanf("%d",&b.cost);
    fp=fopen("data.txt","a");
    if(fp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
        printf("Record insert Sucessfull");
    }
        printf("\n");
    fclose(fp);
}
void find()
{
    struct book b;
    FILE *fp;
    char ch[20];
    printf("Enter movie code :");
    scanf("%s",ch);
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {   
        while(getc(fp) != EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,ch) == 0)
            {
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tmovie name ::%s",b.name);
                printf("\n\t\tmovie date ::%s",b.date);
                printf("\n\t\tprice of ticket ::%d",b.cost);
                break;
            }
        }
    }

    fclose(fp);
}
void viewAll()
{
    char ch;
    FILE *fp;

    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {   
        system("clear");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);        
    }
    fclose(fp);
}
void book_ticket()
{
 struct book b;
    FILE *fp;
    FILE *ufp;
    int total_seat,mobile,total_amount;
    char name[20];
    char ch; 
    char movie_code[20]; 
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {   
        system("cls");
        while( ( ch = fgetc(fp) ) != EOF )
        printf("%c",ch);
    }
    fclose(fp);
    printf("\n For Ticket Booking Choose the Movie (Enter Movie Code First Letter Of Movie)\n");
    printf("\n Enter movie code :");
    scanf("%s",movie_code);
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    {   
        while(getc(fp) != EOF)
        {
            fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
            if(strcmp(b.code,movie_code) == 0)
            {
                printf("\n Record Found\n");
                printf("\n\t\tCode ::%s",b.code);
                printf("\n\t\tMovie name ::%s",b.name);
                printf("\n\t\tdate name ::%s",b.date);
                printf("\n\t\tPrice of ticket::%d",b.cost);
            }
        }
    }
    printf("\n* Fill Deatails  *");
    printf("\n your name :");
    scanf("%s",name);
    printf("\n mobile number :");
    scanf("%d",&mobile);
    printf("\n Total number of tickets :");
    scanf("%d",&total_seat);
    total_amount = b.cost * total_seat;
    printf("\n ***** ENJOY MOVIE ****\n");
    printf("\n\t\tname : %s",name);
    printf("\n\t\tmobile Number : %d",mobile);
    printf("\n\t\tmovie name : %s",b.name);
    printf("\n\t\tTotal seats : %d",total_seat);
    printf("\n\t\tcost per ticket : %d",b.cost);
    printf("\n\t\tTotal Amount : %d",total_amount);
    ufp=fopen("oldTransection.txt","a");
    if(ufp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
        printf("\n Record insert Sucessfull to the old record file");
    }
        printf("\n");
    fclose(ufp);
    fclose(fp);

}
void old_record()
{
    char ch;
    FILE *fp;   
    fp = fopen("oldTransection.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);

    }
    else
    {   
        system("clear");
        while( ( ch = fgetc(fp) ) != EOF )
            printf("%c",ch);
        
    }
    fclose(fp);
}


void book_Multiple_Seats(int numSeats) {
    int row, col;
    int seatsBooked = 0;

    printf("Enter the row and column of the seats you want to book (e.g., 1 3 1 4): ");

    while (seatsBooked < numSeats) {
        scanf("%d %d", &row, &col);

        if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
            if (seats[row - 1][col - 1] == 0) {
                seats[row - 1][col - 1] = 1; 
                printf("\nSeat in row %d, column %d booked successfully!\n", row, col);
                seatsBooked++;
            } else {
                printf("\nSeat in row %d, column %d is already booked. Please choose another seat.\n", row, col);
            
                 seatsBooked++;
            }
        } else {
            printf("\nInvalid seat selection. Please choose a valid seat.\n");
             seatsBooked++;
        }
    }

    printf("\nAll seats booked successfully!\n");
}


void reserveSeats(int num_seats) {
    int count = 0;
    printf("\nEnter the row and column of the first seat you want to reserve (e.g., 1 3): ");
    int row, col;
    scanf("%d %d", &row, &col);

    if (row <= 0 || row > NUM_ROWS || col <= 0 || col > NUM_COLS) {
        printf("\nInvalid seat selection. Please choose a valid seat.\n");
        return;
    }

    row--;
    col--;

    for (int i = row; i < NUM_ROWS; i++) {
        for (int j = col; j < NUM_COLS; j++) {
            if (seats[i][j] == 0) {
                seats[i][j] = 1; 
                count++;
            } else {
                break;
            }

            if (count == num_seats) {
                printf("\n%d seats reserved successfully!\n", count);
                return;
            }
        }
    }

    printf("\nNot enough available seats for the requested quantity.\n");
}


void cancelReservations() {
    int count = 0;
    printf("\nEnter the row and column of the first seat you want to cancel (e.g., 1 3): ");
    int row, col;
    scanf("%d %d", &row, &col);

    if (row <= 0 || row > NUM_ROWS || col <= 0 || col > NUM_COLS) {
        printf("\nInvalid seat selection. Please choose a valid seat.\n");
        return;
    }

    row--; 
    col--;

    for (int i = row; i < NUM_ROWS; i++) {
        for (int j = col; j < NUM_COLS; j++) {
            if (seats[i][j] == 1) {
                seats[i][j] = 0;
                count++;
            } else {
                break;
            }
        }
    }

    if (count > 0) {
        printf("\n%d reservations canceled successfully!\n", count);
    } else {
        printf("\nNo reservations found at the specified seat.\n");
    }
}





void Seat_Booking_System()
{
    int row,col,choice,numSeats,num_seats;
    while (1) {
        printf("\nMovie Theater Seat Booking System\n");
        printf("Press <1> Display Seat Arrangement\n");
        printf("Press <2> Book a Seat\n");
        printf("Press <3> Book Multiple Seat\n");
        printf("Press <4> Reserve Seats (2 or more)\n");
        printf("Press <5> Cancel Reservations\n");
        printf("Press <0> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
            break;

            case 2:
                printf("Enter the row and column of the seat you want to book (e.g., 1 3): ");
                scanf("%d %d", &row, &col);
                bookSeat(row - 1, col - 1); 
            break;
            
            case 3:
                printf("Enter the number of seats you want to book: ");
                scanf("%d", &numSeats);
                if (numSeats >= 2) {
                    book_Multiple_Seats(numSeats);
                } else {
                    printf("\nYou must book at least 2 seats. Please try again.\n");
                }
            break; 
            
            case 4:
                printf("Enter the number of seats to reserve: ");
                scanf("%d", &num_seats);
                if (num_seats >= 2) {
                    reserveSeats(num_seats);
                } else {
                    printf("You must reserve at least 2 seats.\n");
                }
                break;


            case 5:
                cancelReservations();
                break;


            case 0:
                exit(0);
            break;            

            default:
                printf("Wrong choice !");
            break;
            
        }
    }
}



void main()
{
     int ch;
    do{
    printf("\n");   
    printf("\t Movie Ticket Booking ");
    printf("\n");
    printf("\nPress <1> Insert Movie");
    printf("\nPress <2> View All Movies");
    printf("\nPress <3> Find Movie ");
    printf("\nPress <4> Book Ticket");
    printf("\nPress <5> View All Transactions");
    printf("\nPress <6> Seat Booking System");    
    printf("\nPress <0> Exit ");
    printf("\nEnter your Choice ::");
    scanf("%d",&ch);    

    switch (ch)
    {
            case 1 :
            insert_details();
        break;
        case 2:
            viewAll();
        break;
            
        case 3:
            find();
        break;

        case 4:
        book_ticket();
        break;
        
        case 5:
        old_record();
        break;


        case 6:
        Seat_Booking_System();
        break;

        case 0:
        exit(0);
        break;

        default:
        printf("Wrong choice !");
        break;
    }
 }while(ch!=0);
}