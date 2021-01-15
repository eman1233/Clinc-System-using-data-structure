#include "user_mode.h"

/*View patient record.
By entering the patient ID, the system shall show the basic information for the
patient.*/

Patient * ViewPatientRecord (Patient * top , u8 id)
{
    Patient * p = top;
    while (p != NULL)
    {
        //If id exist

        if ( p -> ID == id )
        {
          // the system shall show the basic information for the patient
           printf("Name   : %s \n"  , p -> Name);
           printf("Age    : %d \n"  , p -> Age );
           printf("Gender : %s \n"  , p -> Gender);
           return p;
        }

        // if id not exist

        else
        {
           p = p -> link;
        }

    }
    printf("This ID not Exist\n");
}

/*View today’s reservations.
In this view, the system shall print all reservations with the patient ID attached
to each reservation slot*/


void ViewTodayReservations ( Patient * top)
{
    Patient * p;
    while ( p != NULL)
    {
        printf("ID : %d \n",p -> ID);
        p = p -> link;
    }

}
void ChooseBetweenFuncationUserMode (void)
{
    printf("Enter 1 to choose View patient record                 \n");
    printf("Enter 2 to choose View today’s reservations           \n");
}
void User_Mode (void)
{
    ChooseBetweenFuncationUserMode();
    printf("Enter option do you need :");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        {
            printf("                       You are in  View patient record \n");
            //By entering the patient ID
            printf("Enter ID U want :");
            scanf("%d",&iduser);
           p = ViewPatientRecord (p , iduser);
           break;
        }
    case 2:
        {
          printf("                       You are in View today’s reservations \n");
           ViewTodayReservations(p);
           break;
        }
    }

}
