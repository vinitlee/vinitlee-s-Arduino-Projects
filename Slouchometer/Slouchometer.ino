#include <ADXL362.h>
#include <SPI.h>


/* Simple "Hello World" example.

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
*/

ADXL362 xl;

int i = 0;

int temp;
int XValue, YValue, ZValue, Temperature;
int X0=0, Y0=0, Z0=0, T0=0;

int t = 5000;

void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
    xl.begin();                   // Setup SPI protocol, issue device soft reset
    xl.beginMeasure();            // Switch ADXL362 to measure mode  
    xl.checkAllControlRegs();     // Burst Read all Control Registers, to check for proper setup
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  analogWrite(4,0);
  
  X0 = xl.readXData();
  Y0 = xl.readYData();
  Z0 = xl.readZData();
}

void loop()
{
//  Serial.println(xl.readXData() - X0);
//  Serial.println(xl.readYData() - Y0);
//  Serial.println(xl.readZData() - Z0);
  
  if (xl.readZData() - Z0 > 5000) {
    t = 200;
    tone(3,201,t/2);
  }
  Serial.println('------');
  delay(t);  // do not print too fast!
  t=5000;
}

