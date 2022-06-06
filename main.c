
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int i,j,main_exit;

void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void closer();


struct date{
    int month,day,year;
};
struct {

    char name[120];
    int age;
    char city[120];
    char mail_id[60];
    char room_no[8];
    char father_name[60];
    int father_phone_no[11];
    int phone_no[11];
    char hostel_name[6];
    char hostel_id[10];
    struct date dob;
    }add,upd,check,rem,sort;


int main()
{

  system("color 0b");
  menu();
  return 0;
}



void menu()
{
system("CLS");
    int choice;
    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> Removing existing account\n\t\t5>> View all students list\n\t\t6>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:closer();
        break;
        default:menu();
    }
}

void new_entry()
{
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.dat","a+");
    hostel_id:

    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your hostel_id:");
    scanf("%s",check.hostel_id);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(check.hostel_id,add.hostel_id)==0)
            {printf("Students hostel_id already in use!");
             goto hostel_id;
        }
    }

    strcpy(add.hostel_id,check.hostel_id);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",add.city);
    printf("\nEnter the phone number:");
    scanf("%s",&add.phone_no);
    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%s",&add.father_phone_no);
    printf("\n Enter your room no.:");
    scanf("%s",add.room_no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",add.hostel_name);

        fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);

        //adding student hostel id. to hostels' list
    if(strcmp(add.hostel_name,"BH-1")==0)
    {
        hostel=fopen("BH-1.dat","a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"BH-2")==0)
    {
        hostel=fopen("BH-2.dat","[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"BH-3")==0)
    {
        hostel=fopen("BH-3.dat","a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"GH-1")==0)
    {
        hostel=fopen("GH-1.dat","[11]");
        fprintf(hostel, "%s\n",add.hostel_id);
        fclose(hostel);
    }
        //----------------------------------------

    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)

        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void view_list()
{
    system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

    printf("\nHOSTEL_ID\tNAME\t\t\tCity\t\t\tROOM ALLOTED\n");

    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t  %s",add.hostel_id,add.name,add.city,add.room_no);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}



void see()
{
    system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Hostel id.\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the hostel id:");
        scanf("%s",check.hostel_id);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.hostel_id,check.hostel_id)==0)
            {
                test=1;

                printf("\nhostel_id:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%s \nRoom No:%s \nHostel:%s \n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
            }
        }
    }


    fclose(ptr);
     if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}


void edit()
{
    system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the hostel id of the student whose info you want to change:");
    scanf("%s",upd.hostel_id);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name)!=EOF)

    {
        if (strcmp(add.hostel_id,upd.hostel_id)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);

            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no, add.hostel_name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&upd.phone_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }

}


void erase()
{
    system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Hostel_id of student whose data you want to delete:");
    scanf("%s",rem.hostel_id);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name)!=EOF)
   {
        if(strcmp(add.hostel_id,rem.hostel_id)!=0)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %s %s %s\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
}


void closer()
{
    system("CLS");
    printf("\n\n\n*THANK YOU*\n\n\n");
}
