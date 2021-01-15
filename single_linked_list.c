#include "single_linked_list.h"

// Insert in begainning

Patient * InsertInBeginning ( Patient * top , u8 * name , u8 age , u8 * gender ,u8 id )
{
    Patient * temp = (Patient *) malloc (sizeof (Patient));
    if(temp != NULL)
    {
        temp -> Name   = name;
        temp -> Age    = age;
        temp -> Gender = gender;
        temp -> ID     = id;
        temp -> link   = top;
        top            = temp;
    }
    return top;
}

//Insert at end

Patient * InsertAtEnd ( Patient * top , u8 * name , u8 age , u8 * gender ,u8 id )
{
    Patient * p ;
    Patient * temp = (Patient *) malloc (sizeof (Patient));
    if(temp != NULL)
    {
        temp -> Name   = name;
        temp -> Age    = age;
        temp -> Gender = gender;
        temp -> ID     = id;
        p              = top;
        while (p -> link != NULL)
        {
            p = p -> link;
        }
        p    -> link = temp;
        temp -> link = NULL;
    }
    return top;
}



