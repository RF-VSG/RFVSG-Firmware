

/*
int incomingByte = 0;

void loop()
{
	if (Serial.available() > 0)
	{
		incomingByte = Serial.read();

		// Write the same byte back out,

		Serial.println("I got:");
		Serial.println(incomingByte);
	}

	/*
	// If an event happened then we need to process the event!
	if (I2CInterruptOccured)
	{
		// Set the flag back to false so we only handle it once.
		I2CInterruptOccured = false;

		// Check the command byte first to see what happened.
		switch (I2CPacket[0])
		{
		case eMasterCommands::SetVSGToCWMode:

			// Turn off the LO circuitry.
			// Turn on the CW circuitry.
			// Talk to the digital expander to change the state of the LO/CW circuits.




			break;


		case eMasterCommands::SetVSGToVectorMode:

			// Turn on the LO circuitry.
			// Turn off the CW circuitry.
			// Talk to the digital expander to change the state of the LO/CW circuits.

			break;


		case eMasterCommands::ShutdownSynth:

			// Turn everything off.

			break;


		case eMasterCommands::SetCWFilter:

			// Put the filter index in the first byte.
			LOFilterBankSwitch = I2CPacket[1];

			break;


		case eMasterCommands::SetCWPower:

			// Change the CW power level.
			// This is done by looking up the power level in the LUT and interpolating.

			break;


		case eMasterCommands::SetLOPower:

			break;


		case eMasterCommands::SetSynthFrequency:

			break;


		case eMasterCommands::SetSynthPower:

			break;


		case eMasterCommands::SynthMuteRF:

			break;
		}

	}
	
	// Just hang out and do nothing if no event has happened.
delay(100);
}


// Interrupt handlers
//
// When the master interrupt goes high, it means that the master device
// is trying to send a new command to this device. We should stop what
// we are doing and receive data over I2C.

void MasterInterruptHandler(int NumberOfBytes)
{
	// Read the information from the master device over I2C.
	// The wire library uses a 32 byte buffer so thats all we have.
	int i = 0;

	while (1 < Wire.available())
	{
		I2CPacket[i] = Wire.read();
		i++;
	}

	int x = Wire.read(); // Read the last byte out.

	I2CInterruptOccured = true;
}


void DigitalExpanderInterruptHandler()
{

}


*/
