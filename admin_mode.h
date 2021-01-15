#ifndef __ADMIN_MODE_H__
#define __ADMIN_MODE_H__
/************************************Includes*******************************************************/

#include <stdio.h>
#include "platform_types.h"
#include "single_linked_list.h"
#include "string.h"
/************************************Variable*******************************************************/

u8 name   [10];
u8 age;
u8 gender [10];
u8  id    [10] ;
Patient * p;
u8 * PasswardIndication;
u8 n;
u8 IDEdit;

typedef enum
{
    slot1=0,
    slot2,
    slot3,
    slot4,
    slot5,

}SlotReservation;

SlotReservation Slot;

u8 IDReserve;

u8 option;

u8 IDDelate;
/************************************Funcation Declaration******************************************/
u8 * EnterPassword                     (u8 * Password);
u8 * CheckPassword                     (void);
u8 EnterInfo                           ( u8 i );
void CheckID                           ( Patient * top );
void  EditInfo                         ( void );
Patient * AddNewPatientRecord          ( Patient * top , u8 n);
Patient * EditPatientRecord            ( Patient * top , u8 id );
Patient * InsertInBeginningID          ( Patient * top , u8 id );
void EnterNumSlot                      (void);
void Reseve                            (Patient * top, f32 i , f32 j );
Patient * ReserveSlot                  (Patient * top);
Patient * CancelReservation            (Patient * top , u8 id);
void ChooseBetweenFuncationAdminMode   (void);
void Admin_Mode                        (void);

#endif
