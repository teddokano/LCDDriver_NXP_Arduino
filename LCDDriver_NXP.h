/** TempSensor operation library for Arduino
 *
 *  @class  TempSensor
 *  @author Tedd OKANO
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_LCD_DRIVER_H
#define ARDUINO_LCD_DRIVER_H

#include <Arduino.h>
#include <stdint.h>

#include "I2C_device.h"

/** TempSensor class
 *	
 *  @class TempSensor
 *
 *	TempSensor class is a base class for all temperature sensors
 *	All actual device class will be inherited from this class
 */

class PCA8561 : public I2C_device
{
public:
	enum reg_num {
		Software_reset, Device_ctrl,
		Display_ctrl_1, Display_ctrl_2,
		COM0_07_00, COM0_15_08, COM0_17_16,COM1_07_00, 
		COM1_15_08, COM1_17_16, COM2_07_00, COM2_15_08, 
		COM2_17_16, COM3_07_00, COM3_15_08, COM3_17_16 
	};

	PCA8561( uint8_t i2c_address = (0x70 >> 1) );
	virtual ~PCA8561();

	void com_seg( int com, int seg, bool v );
	void puts( char* s );
	void lcdputchar( char c );
	void flush( void );
	void clear( void );

private:
	void	char2seg( int pos, int c );
	uint8_t	bf[ 12 ];
	char	str_buffer[ 4 ];
	int		str_pos	= 0;
	static uint16_t char_pattern[61];
};

#endif //	ARDUINO_LCD_DRIVER_H
