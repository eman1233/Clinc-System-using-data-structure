#include "admin_mode.h"

/*******************************************************************************************************************************/

/*The system asks for password, the default password is 1234. The system allows 3
trails for the password entry, if the entered password was incorrect for 3 consecutive
times, the system shall close.*/

//Enter Password

u8 * EnterPassword(u8 * Password)
{
    printf("Enter PassWord :");
    scanf("%s",Password);
    return Password;
}

//Check Password

u8 * CheckPassword (void)
{
    u8 Password[10];
    u8 * PasswordReturned;
    u8 * PasswordIndecation;

    //the default password is 1234
    u8 * DefultPassword="1234";

    u8 i=0;
    u8 n=0;

    // The system allows 3 trails for the password entry
    while(i<3)
    {
        PasswordReturned=EnterPassword(Password);
        n = strcmp (PasswordReturned,DefultPassword);

        if(n==0)
        {
            PasswordIndecation="Correct Password\nYou can login\n";
            break;
        }
        else
        {
            PasswordIndecation="Wrong Password";
            printf("%s\n",PasswordIndecation);
            i++;
        }

    }

    if(i==3)
    {
        PasswordIndecation="Tries finshed";
    }
    return PasswordIndecation;
}

/*******************************************************************************************************************************/

/*Add new patient record:
To add a new patient, the user shall admin shall enter these basic
information: name, age, gender and ID. The ID shall be unique for the user, if
the entered ID is already exists, the system shall reject the entry*/

// the user shall admin shall enter these basic information: name, age, gender and ID.

u8  EnterInfo ( u8 i )
{

    printf("Enter Name :");

    scanf(" %s",name);

    printf("Enter Age :");

    scanf("%d",&age);

    printf("Enter Gender :");

    scanf("%s",gender);

    printf("Enter ID :");

    scanf("%d",&id[i] );

    return id[i];

}


Patient * AddNewPatientRecord ( Patient * top , u8 n)
{
    //If no patient in clinic

    if(n==0)
    {
        printf("There are no patient today\n");
        return top;
    }
    // If patient in clinic
    else
    {
        id[1] = EnterInfo(1);
        top   = InsertInBeginning( top , name , age , gender , id[1]);
        for ( u8 i=2 ;i <=n;i++)
        {
           id[i] = EnterInfo();
           top   = InsertAtEnd( top , name , age , gender , id[i]);
           for(u8 j = i+1; j<=n ;j++)
           {
               if(id [i] == id [j])
               {
                   printf("This ID exist");
               }
           }
        }


    }
    return top;

   //CheckID ( top);

}


/*******************************************************************************************************************************/

/* Edit patient record:
By entering patient ID the system shall checks if the ID exists, the system
shall allow the user to edit the patient information. If not, the system shall
display incorrect ID message.*/

void  EditInfo ( void )
{
    printf("Enter Edit Name :");

    scanf(" %s",name);

    printf("Enter Edit Age :");

    scanf("%d",&age);

    printf("Enter Edit Gender :");

    scanf("%s",gender);

}

Patient * EditPatientRecord ( Patient * top , u8 id )
{
    Patient * p = top;
    if ( top = NULL)
    {
        printf(" No  Patient ");
    }
    while (p != NULL)
    {
        //if the ID exists, the system shall allow the user to edit the patient information
        if ( p -> ID = id)
        {
            printf("This ID exist\n");
            EditInfo ();

            p -> Name   = name;
            p -> Age    = age;
            p -> Gender = gender;
            return top;

        }
        //If not, the system shall display incorrect ID message.

        else if ( p -> ID != id)
        {
            printf("This ID  not exist\n");
            return top;
        }

        p = p -> link;
    }

}
/*Reserve a slot with the doctor
By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to
3:30pm, 4pm to 4:30pm and 4:30pm to 5pm. Upon opening of this window,
the system shall display the available slots. The admin shall enter the patient
ID and the desired slot. The reserved slot shall not appear again in the next
patient reservation.*/

void EnterNumSlot (void)
{
    printf("Enter 1 to reserve from 2pm    to 2:30pm \n");
    printf("Enter 2 to reserve from 2:30pm to 3pm \n");
    printf("Enter 3 to reserve from 3pm    to 3:30pm \n");
    printf("Enter 4 to reserve from 3:30pm to 4pm \n");
    printf("Enter 5 to reserve from 4pm    to 4:30pm\n");
}

Patient * InsertInBeginningID ( Patient * top , u8 id )
{

    Patient * temp = (Patient *) malloc (sizeof (Patient));
    if(temp != NULL)
    {
        temp -> ID     = id;
        temp -> link   = top;
        top            = temp;
    }
    return top;
}


void Reseve ( Patient * top, f32 i , f32 j )
{
     printf("Enter ID :");
     scanf("%d",&id );
     top = InsertInBeginningID ( top , id  );
     printf("This time from %f pm to %f pm \n " , i ,j );
}

Patient * ReserveSlot (Patient * top )
{
    EnterNumSlot();
    printf("Enter slot you need :");
    scanf("%d",&Slot);
    switch (Slot)
    {
    case slot1 :
        {
            Reseve (top , 2 , 2.30  );
            break;
        }
    case slot2 :
        {
            Reseve (top , 2.30 , 3 );
            break;
        }
    case slot3 :
        {
            Reseve (top , 3.30 , 3.30  );
            break;
        }
    case slot4 :
        {
          Reseve (top , 3.30 , 4  );
          break;
        }
    case slot5 :
        {
            Reseve (top , 4 , 4.30  );
            break;
        }

    }
    return top;
}

/*******************************************************************************************************************************/
/*Cancel reservation.
The admin can cancel a reservation by entering the patient ID. This
reservation shall be shown again in the available slots window.*/

Patient * CancelReservation (Patient * top , u8 id )
{
    Patient * temp , * p;
    if (top == NULL)
    {
        printf("There are no patient ");
    }

    //Delate first patient
    if ( top -> ID == id)
    {
        temp = top;
        temp = temp -> link;
        free(temp);
        printf("Slot i free");
        return top;
    }
    //Delate in between or in end
    p = top;
    while ( p -> link != NULL )
    {
        if ( p -> link -> ID == id )
        {
            temp = p -> link;
            break;
        }
        p = p -> link;
    }
    if ( p -> link == NULL)
    {
        printf("This ID dose not exist");
    }
    else
    {
        p -> link = temp -> link;
        free(temp);
        printf("Slot is free");
    }
    return top;
}


/******************************************************************************************************************************/
void ChooseBetweenFuncationAdminMode (void)
{
    printf("Enter 1 to choose Add new patient record       \n");
    printf("Enter 2 to choose Edit patient record           \n");
    printf("Enter 3 to choose Reserve a slot with the doctor \n");
    printf("Enter 4 to choose Cancel reservation              \n");
}

void Admin_Mode (void)
{
    PasswardIndication=CheckPassword();
    printf("%s",PasswardIndication);

    //if the entered password was incorrect for 3 consecutive times, the system shall close
    if ( PasswardIndication == "Tries finshed")
    {
        return 0;
    }

    //If password entered correctly
    else
    {
        ChooseBetweenFuncationAdminMode ();
        printf("Enter option do you need :");
        scanf("%d",&option);
        switch (option)
        {
            case 1 :
            {
                printf("                       You are in Add new patient record option \n");
                printf( "Enter num Patient :");
                scanf("%d",&n);
                p = AddNewPatientRecord( p , n );
                break;
            }

            case 2 :
            {
                printf("                      You are in Edit patient record option \n");
                printf ("Enter ID edit :");
                scanf ("%d",&IDEdit);
                p = EditPatientRecord  ( p , IDEdit );
                break;


            }

            case 3 :
            {
                printf("                       You are in Reserve a slot with the doctor option \n");
                p = ReserveSlot (p );
                break;
            }

            case 4 :
            {
                 printf("                       You are in Cancel reservation \n");
                 printf("Enter ID you want to delate :");
                 scanf("%d",&IDDelate);
                 p = CancelReservation(p ,  id );
                 break;

            }


        }

    }

}
