/*
 Name:		ADRF5250.h
 Created:	11/8/2018 4:09:34 PM
 Author:	harri
 Editor:	http://www.visualmicro.com
*/

#ifndef _ADRF5250_h
#define _ADRF5250_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <stdint.h>

class ADRF5250
{
private:

	uint8_t V1_Pin;
	uint8_t V2_Pin;
	uint8_t V3_Pin;

	uint8_t State = 0;

public:

	ADRF5250(uint8_t VControl1, uint8_t VControl2, uint8_t VControl3);

	void operator=(const uint8_t Index);
};


#endif