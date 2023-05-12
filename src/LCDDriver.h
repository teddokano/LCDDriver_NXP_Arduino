/** LCDDriver operation library for Arduino
 *
 *  @author Tedd OKANO
 *
 *  Released under the MIT license License
 */

#ifndef ARDUINO_LCD_DRIVER_H
#define ARDUINO_LCD_DRIVER_H

#include <Arduino.h>
#include <stdint.h>

#include "I2C_device.h"

/** PCA8561 class
 *	
 *  @class PCA8561
 *
 *	PCA8561 class is a sample code for the PCA8561AHN-ARD
 *	It demonstrates LCD operation by 
 */

class PCA8561 : public I2C_device
{
public:
	/** The number of LCD backplane output */
	static const int N_COM	= 4;

	/** The number of LCD segment output */
	static const int N_SEG	= 18;
	enum reg_num {
		Software_reset, Device_ctrl,
		Display_ctrl_1, Display_ctrl_2,
		COM0_07_00, COM0_15_08, COM0_17_16, COM1_07_00, 
		COM1_15_08, COM1_17_16, COM2_07_00, COM2_15_08, 
		COM2_17_16, COM3_07_00, COM3_15_08, COM3_17_16 
	};

	/** Create a PCA8561 instance with specified address
	 *
	 * @param i2c_address I2C-bus address (default: (0x70>>1))
	 */
	PCA8561( uint8_t i2c_address = (0x70 >> 1) );

	/** Create a PCA8561 instance with specified address
	 *
	 * @param wire TwoWire instance
	 * @param i2c_address I2C-bus address (default: (0x70>>1))
	 */
	PCA8561( TwoWire& wire, uint8_t i2c_address = (0x70 >> 1) );
	virtual ~PCA8561();
	
	/** Begin the device operation
	 *
	 *	This method turns-on the device
	 */
	void begin( void );

	/** Access to a segment
	 *
	 * @param com LCD backplane output select
	 * @param seg LCD segment output select
	 * @param v true for the segment ON
	 */
	void com_seg( int com, int seg, bool v );
	
	/** String output
	 *
	 * @param s A string to display
	 * @param dly Option parameter for scroll effect each character appears with this delay [mili-second] (default: 0)
	 */
	void puts( const char* s, int dly = 0 );
	
	/** Character output
	 *	
	 *	Putting '\n' or '\r' character to clear display in next "putchar()" or "puts()" call
	 *	
	 * @param c A character to display
	 */
#ifdef putchar
#undef putchar
#endif
	void putchar( char c );

	/** Clear display
	 *	
	 * @param no_flush no immidiate display clear (display will be cleared at next "putchar()" or "puts()" call)
	 */
	void clear( bool no_flush = false );

private:
	void	init( void );
	void	flush( void );
	void	char2seg( int pos, int c );
	uint8_t	bf[ 12 ];
	char	str_buffer[ 4 ];
	int		str_pos	= 0;
	static uint16_t char_pattern[61];
};

#endif //	ARDUINO_LCD_DRIVER_H
