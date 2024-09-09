/*
 * EXT_EEPROM_interface.h
 *
 * Created: 7/7/2024 5:17:02 AM
 *  Author: ahmed
 */ 


#ifndef EXT_EEPROM_INTERFACE_H_
#define EXT_EEPROM_INTERFACE_H_


#define SLAVE_ADDRESS   0b1010000

/********** Function To Write Data on EEPROM **********/

void EEPROM_voidWriteData(u16 copy_u16Address , u8 copy_u8data);

/********** Function To Read Data From  EEPROM **********/

u8 EEPROM_u8ReadData(u16 copy_u16Address);



#endif /* EXT_EEPROM_INTERFACE_H_ */