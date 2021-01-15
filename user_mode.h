#ifndef __USER_MODE_H__
#define __USER_MODE_H__

/************************************Includes*******************************************************/

#include <stdio.h>
#include "platform_types.h"
#include "single_linked_list.h"

/************************************Variable*******************************************************/
u8 iduser;
Patient * p;
u8 option;

/************************************Funcation Declaration******************************************/

Patient * ViewPatientRecord         ( Patient * top , u8 id );
void ViewTodayReservations          ( Patient * top);
void ChooseBetweenFuncationUserMode (void);
void User_Mode                      (void);

#endif // __USER_MODE_H__
