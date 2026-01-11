// Passenger's Database Management System

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void gotoxy(int x, int y);
void load(void);
void menu(void);
void add(void);
void view(void);
void search(void);
void modify(void);
void delete_p(void);

struct passenger
{
    char name[30];
    char num[20];
    char gender;
    char country[20];
    char passnum[20];
    char destination[20];
    char date[20];
};

int main()
{
    system("color 0A");
    // gotoxy(90,23);
    // load();

    gotoxy(80, 8);
    printf("<--:Passenger's Database Management System:-->");
    gotoxy(90, 23);
    printf("press any key to start.....");
    getch();
    system("cls");
    gotoxy(90, 23);
    load();
    system("cls");

    menu();
    gotoxy(90, 23);

    return 0;
}

void menu(void)
{

    int choice;

    system("cls");

    gotoxy(90, 17);
    printf("<--:MENU:-->");
    gotoxy(75, 19);
    printf("<<Enter appropriate number to perform following task>>");
    gotoxy(90, 21);
    printf("1 : Add Passenger Details.");
    gotoxy(90, 22);
    printf("2 : View Passenger Details.");
    gotoxy(90, 23);
    printf("3 : Search Passenger Details.");
    gotoxy(90, 24);
    printf("4 : Modify Passenger Details.");
    gotoxy(90, 25);
    printf("5 : Delete Passenger Details.");
    gotoxy(90, 26);
    printf("6 : Exit.");
    gotoxy(90, 27);
    printf("Enter your choice:");
    scanf("%d", &choice);
    system("cls");
    gotoxy(90, 23);
    load();
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        delete_p();
        break;

    case 6:
        system("cls");
        exit(1);
        break;

    default:
        system("cls");
        gotoxy(90, 23);
        printf("Invalid Choice.");
    }
}

void add()
{
    FILE *fp;
    struct passenger p;
    char again = 'y';
    system("cls");

    fp = fopen("passenger.csv", "ab+");
    if (fp == NULL)
    {
        gotoxy(90, 5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while (again == 'y')
    {
        gotoxy(90, 17);
        printf("<--:ADD TO DATABASE:-->");
        gotoxy(90, 19);
        printf("Enter Details of Passenger.");
        gotoxy(90, 21);
        printf("Enter Name : ");
        gets(p.name);
        gotoxy(90, 22);
        printf("Enter Phone Number: ");
        gets(p.num);
        gotoxy(90, 23);
        printf("Enter Gender(M/F): ");
        scanf("%c", &p.gender);
        fflush(stdin);
        gotoxy(90, 24);
        printf("Enter Country Name : ");
        gets(p.country);
        gotoxy(90, 25);
        printf("Enter Passport Number : ");
        gets(p.passnum);
        gotoxy(90, 26);
        printf("Enter Destination : ");
        gets(p.destination);
        gotoxy(90, 27);
        printf("Enter Date of Travelling(DD-MM-YY): ");
        gets(p.date);

        fwrite(&p, sizeof(p), 1, fp);
        // fprintf(fp,"%s %s %c %s %s %s %s\n",p.name,p.num,p.gender,p.country,p.destination,p.date)
        gotoxy(90, 29);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        // fflush(stdin);
        again = getch();
        system("cls");

        gotoxy(90, 23);
        load();
        system("cls");
        // fflush(stdin);
    }
    fclose(fp);
    // gotoxy(90,31);
    // printf("Press any key to continue...");
    // getch();

    menu();
}

void view()
{
    FILE *fp;
    int i = 1, j;
    struct passenger p;
    system("cls");
    gotoxy(90, 3);
    printf("<--:VIEW DATABASE:-->");
    gotoxy(30, 5);
    printf("S.No     Name of passenger      Mobile No      Gender    Country         Passport No.         Destination     Date(DD-MM-YY)");
    gotoxy(30, 6);
    printf("----------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("passenger.csv", "rb+");
    if (fp == NULL)
    {
        gotoxy(30, 8);
        printf("Error opening file.");
        exit(1);
    }
    j = 8;
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        gotoxy(30, j);
        printf("%-9d%-23s%-17s%-8c%-16s%-21s%-17s%-7s", i, p.name, p.num, p.gender, p.country, p.passnum, p.destination, p.date);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(30, j + 3);
    printf("Press any key to continue...");
    getch();
    system("cls");
    gotoxy(90, 23);
    load();

    menu();
}

void search()
{
    FILE *fp;
    struct passenger p;
    char passenger_name[20];
    system("cls");
    gotoxy(90, 17);
    printf("<--:SEARCH  ON DATABASE:-->");
    gotoxy(90, 19);
    printf("Enter name of the Passenger : ");
    fflush(stdin);
    gets(passenger_name);
    fp = fopen("passenger.csv", "rb+");
    if (fp == NULL)
    {
        gotoxy(90, 20);
        printf("Error opening file");
        exit(1);
    }

    int flag = 1;
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (strcmp(passenger_name, p.name) == 0)
        {
            gotoxy(90, 22);
            printf("Name : %s", p.name);
            gotoxy(90, 23);
            printf("Phone Number : %s", p.num);
            gotoxy(90, 24);
            printf("Gender : %c", p.gender);
            gotoxy(90, 25);
            printf("Country : %s", p.country);
            gotoxy(90, 26);
            printf("Passport Number : %s", p.passnum);
            gotoxy(90, 27);
            printf("Destination : %s", p.destination);
            gotoxy(90, 28);
            printf("Date(DD-MM-YY) : %s", p.date);
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {

        gotoxy(90, 22);
        printf("[Passenger not found.]\n");
    }

    fclose(fp);
    gotoxy(90, 30);
    printf("Press any key to continue...");
    getch();
    system("cls");
    gotoxy(90, 23);
    load();
    menu();
}

void modify()
{
    char passenger_name[20];
    FILE *fp;
    struct passenger p;
    system("cls");
    gotoxy(90, 17);
    printf("<--:MODIFY DATABASE:-->");
    gotoxy(90, 19);
    printf("Enter name of passenger to modify: ");
    fflush(stdin);
    gets(passenger_name);
    fp = fopen("passenger.csv", "rb+");
    if (fp == NULL)
    {
        gotoxy(90, 20);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp); // starting from beginning of the file
    fflush(stdin);

    int flag = 0;

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (strcmp(passenger_name, p.name) == 0)
        {
            gotoxy(90, 21);
            printf("Enter Name : ");
            gets(p.name);
            gotoxy(90, 22);
            printf("Enter Phone Number: ");
            gets(p.num);
            gotoxy(90, 23);
            printf("Enter Gender(M/F): ");
            scanf("%c", &p.gender);
            fflush(stdin);
            gotoxy(90, 24);
            printf("Enter Country Name : ");
            gets(p.country);
            gotoxy(90, 25);
            printf("Enter Passport Number : ");
            gets(p.passnum);
            gotoxy(90, 26);
            printf("Enter Destination : ");
            gets(p.destination);
            gotoxy(90, 27);
            printf("Enter Date of Travelling(DD-MM-YY): ");
            gets(p.date);
            fseek(fp, -static_cast<long int>(sizeof(p)), SEEK_CUR); // seeking the cursor of the file to the location where that particular passengers information started to over write there
            fwrite(&p, sizeof(p), 1, fp);                           // overwriting the previous information
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {

        gotoxy(90, 22);
        printf("[Passenger Not Found]");
    }

    fclose(fp);
    gotoxy(90, 32);
    printf("Press any key to continue...");
    getch();
    system("cls");
    gotoxy(90, 23);
    load();
    menu();
}

void delete_p()
{
    char passenger_name[20];
    FILE *fp, *ft;
    struct passenger p;
    system("cls");
    gotoxy(97, 17);
    printf("<--:DELETE FROM DATABASE:-->");
    gotoxy(90, 19);
    printf("Enter name of the passenger to delete his details : ");
    fflush(stdin);
    gets(passenger_name);
    fp = fopen("passenger.csv", "rb+");
    if (fp == NULL)
    {
        gotoxy(90, 20);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.csv", "wb+");
    if (ft == NULL)
    {
        gotoxy(90, 20);
        printf("Error opening file");
        exit(1);
    }
    int flag = 1;
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        if (strcmp(passenger_name, p.name) != 0)
        {
            fwrite(&p, sizeof(p), 1, ft);
            flag = 0;
        }
        else
        {
            flag++;
        }
    }
    if (flag == 0)
    {

        gotoxy(90, 22);
        printf("[Passenger Not Found]");
    }
    else if (flag > 0)
    {
        gotoxy(90, 22);
        printf("[Passenger's Information Has Been Deleted]");
    }

    fclose(fp);
    fclose(ft);
    remove("passenger.csv");
    rename("temp.csv", "passenger.csv");

    gotoxy(90, 24);
    printf("Press any key to continue...");
    getch();
    system("cls");
    gotoxy(90, 23);
    load();
    menu();
}

void gotoxy(int x, int y)
{
    COORD crd;
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

void load(void)
{
    int i;
    printf("LOADING");
    for (i = 0; i < 20; i++)
    {
        printf("%c", 254);
        Sleep(100);
    }
}
