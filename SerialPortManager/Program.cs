using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO.Ports;

namespace SerialPortManager
{
    class Program
    {
        enum eMasterCommands
        {
            //----------------------------------------------------------------------
            // Misc commands

            // The VSG can be in CW (just a sine wave) mode OR vector mod mode.
            // In CW mode, the output power is fixed at a given frequency, and the
            // LO portions of the synthesizer are all stutdown.
            SetVSGToCWMode,

            SetVSGToVectorMode,

            // Turn off the synth for power savings.
            ShutdownSynth,

            //----------------------------------------------------------------------
            // CW Commands

            // Set the filter bank filter for the CW output.
            SetCWFilter,

            // Set the CW output power using the attenuator.
            SetCWPower,

            //----------------------------------------------------------------------
            // LO commands

            // Set the LO power to a given power level using the attenuator.
            SetLOPower,

            //----------------------------------------------------------------------
            // Synthesizer commands

            // Set the frequency output from the synth IC. This effects both CW and
            // LO outputs.
            SetSynthFrequency,

            // Set the output power coming from the synth IC. There are only 4 power
            // levels that can be chosen from.
            SetSynthPower,

            // Mute the RF outputs from the synth IC.
            SynthMuteRF,
        };


        public static SerialPort sp;

        public static string RXData = "";

        private static void SerialPortRX(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            RXData = sp.ReadExisting();

            Console.WriteLine(RXData);
        }

        static void Main(string[] args)
        {
            // Create a serial port object.

            sp = new SerialPort();

            sp.PortName = "COM5";
            sp.BaudRate = 9600;

            sp.Open();

            sp.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(SerialPortRX);


            if(sp.IsOpen)
            {
                while(true)
                {

                    string TheLine = Console.ReadLine();


                    if (TheLine.Equals("exit"))
                    {
                        break;
                    }
                    else
                    {
                        sp.WriteLine(TheLine);
                    }
                }

                sp.Close();
            }
        }
    }
}
