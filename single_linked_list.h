#ifndef __SINGLE_LINKED_LIST__
#define __SINGLE_LINKED_LIST__

/***********************************************Includes*********************************/

#include "platform_types.h"
#include <stdlib.h>
#include <stdio.h>


/************************************************variable*******************************/

typedef struct p
{
    u8       * Name;
    u8         Age;
    u8       * Gender;
    u8         ID ;
    struct p * link;
}Patient;

Patient * InsertInBeginning ( Patient * top , u8 * name , u8 age , u8 * gender ,u8 id );
Patient * InsertAtEnd       ( Patient * top , u8 * name , u8 age , u8 * gender ,u8 id );
void      DisplayID         ( Patient * top );
void DelateEndNode          (Patient * p);
#endif // __SINGLE_LINKED_LIST__
