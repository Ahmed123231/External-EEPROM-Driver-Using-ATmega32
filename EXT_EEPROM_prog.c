/*
 * EXT_EEPROM_prog.c
 *
 * Created: 7/7/2024 5:17:25 AM
 *  Author: ahmed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "EXT_EEPROM_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>


/********** Function To Write Data on EEPROM **********/

void EEPROM_voidWriteData(u16 copy_u16Address , u8 copy_u8data){
	
	u8 Loc_u8address=0b1010000 | copy_u16Address >>8;
	
	TWI_SendStartCondition();
	TWI_sendSlaveAddressWithWrite(Loc_u8address);
	TWI_MasterSendData((u8)copy_u16Address);
	TWI_MasterSendData(copy_u8data);
	TWI_SendStopCondition();
	_delay_ms(5);
	
	
	
	
	
}

/********** Function To Read Data From  EEPROM **********/

u8 EEPROM_u8ReadData(u16 copy_u16Address){
	
	u8 Loc_u8address=0b1010000 | copy_u16Address >>8;
	u8 Loc_u8val=0;
	TWI_SendStartCondition();
	TWI_sendSlaveAddressWithWrite(Loc_u8address);
	TWI_MasterSendData((u8)copy_u16Address);
	TWI_SendRepeatedStart();
	TWI_sendSlaveAddressWithRead(Loc_u8address);
	TWI_MasterReceiveData(&Loc_u8val);
	TWI_SendStopCondition();
	
	return Loc_u8val;
	
	
}