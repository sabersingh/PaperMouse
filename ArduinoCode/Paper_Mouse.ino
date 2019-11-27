/*

•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
•                                                                                                                                                                   • 
•                                                                                (*^_^*)                                                                            •
•                                                                                                                                                                   •
•                                                                    [•] USB Paper Gesture Mouse [•]                                                                •
•                                                                        .......................                                                                    •
•                                                                                                                                                                   •
•                                                            Concept by: Simerneet Singh (a.k.a Saber Singh)                                                        •
•                                                                                                                                                                   •
•                                                                                                                                                                   •
•                                                                   Made Under The Domain Of Jugadu.in                                                              •
•                                                                   __________________________________                                                              •
•                                                                                                                                                                   •
•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••

*/

#include <CapacitiveSensor.h>
#include <Mouse.h>

long time = 0;

CapacitiveSensor   csTOP = CapacitiveSensor(4,2);        //1M resistor between pins 4 & 2, Pin 2 is connected to the Top pointer foil.
CapacitiveSensor   csRIGHT = CapacitiveSensor(5,3);        //1M resistor between pins 5 & 3, Pin 3 is connected to the Right pointer foil.
CapacitiveSensor   csLEFT = CapacitiveSensor(8,6);        //1M resistor between pins 8 & 6, Pin 6 is connected to the Left pointer foil.
CapacitiveSensor   csBOTTOM = CapacitiveSensor(9,7);        //1M resistor between pins 9 & 7, Pin 7 is connected to the Bottom pointer foil.
CapacitiveSensor   csSELECT = CapacitiveSensor(15,16);        //1M resistor between pins 15 & 16, Pin 16 is connected to the Select button foil.

void setup()
{
   Mouse.begin();
   Serial.begin(9600);
   csTOP.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...
   csRIGHT.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...
   csLEFT.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...   
   csBOTTOM.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...
   csSELECT.set_CS_AutocaL_Millis(0xFFFFFFFF);  //Calibrate the sensor...
}

void loop()                    
{
    int X = 0, Y = 0;   //Temporary variables for X axis and Y axis.
    
    long sensorTop =  csTOP.capacitiveSensor(30);
    long sensorRight =  csRIGHT.capacitiveSensor(30);
    long sensorLeft =  csLEFT.capacitiveSensor(30);
    long sensorBottom =  csBOTTOM.capacitiveSensor(30);
    long sensorSelect =  csSELECT.capacitiveSensor(30);

    Serial.println(sensorTop);
    Serial.println(sensorRight);
    Serial.println(sensorLeft);
    Serial.println(sensorBottom);
    Serial.println(sensorSelect);
    
    if(sensorTop >= 60){
      Y = -2;
    }
    //if the value of Top capacitive Sensor is more than or equal to 60 then set the value of Y to -2.
    
    if(sensorBottom >= 60){
      Y = 2;
    }
    //if the value of Bottom capacitive Sensor is more than or equal to than 60 then set the value of Y to 2.


    if(sensorRight >= 60){
      X = 2;
    }
    //if the value of Right capacitive Sensor is more than than or equal to 60 then set the value of X to 2.
    
    if(sensorLeft >= 60){
      X = -2;
    }
    //if the value of Left capacitive Sensor is more than than or equal to 60 then set the value of X to -2.
    

    if(sensorSelect >= 60){
      Mouse.press(MOUSE_LEFT);
    }
    //if the value of Select button capacitive Sensor is more than than or equal to 60 then press the Left Mouse Button.
    else{
      Mouse.release(MOUSE_LEFT);
    }
    //else if the value of Select button capacitive Sensor is less than  60 then release the Left Mouse Button.

    Serial.println(millis()-time);
    
    Mouse.move(X , Y , 0);    //Move the Mouse to the X and Y variable position.
    
    Serial.println("Mouse Position: X , Y = ");
    Serial.print(X); Serial.print("\t");    //Print the value of X on the Serial Monitor.
    Serial.print(Y);    //Print the value of Y on the Serial Monitor.
  
}
