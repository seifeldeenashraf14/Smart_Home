/*
 * App.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Yasmen
 */

#ifndef APP_H_
#define APP_H_


#define  NO_KEY   0XFF

#define OPEN_SYSTEM_MODE         1
#define CHANGE_PASS_MODE         2
#define ADD_USER_MODE            3



#define YASMEEN     1
#define ABEER       2
#define ALAA        3

#define WRONG_ENTRY     4

typedef enum
{
	WRONG_PASS,
	CORRECT_PASS,
}Pass_State_t;



typedef struct {
	u8 pass_eeprom[4];
	u8 ID;
}user_t;


void Write_Pass_Eeprom(u8* data);
void entry_option_fun(void);  //intro(open add change)
u8 Get_Option_key(void);
void Enter_User_ID(void);  //enter your id and check
u8 get_and_check_pass(u8 *eeprom_pass);
void get_pass(user_t * new_user);
#endif /* APP_H_ */
