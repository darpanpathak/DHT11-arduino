#include<dht.h>
dht DHT;

// if you require to change the pin number, Edit the pin with your arduino pin.

#define DHT11_PIN 2

void setup() {
  Serial.begin(9600);
}

void loop() { // READ DATA

int chk = DHT.read11(DHT11_PIN);

  String humidity =String(int(DHT.humidity))+ "."+String(getDecimal(DHT.humidity));
  String temp = String(int(DHT.temperature))+ "."+String(getDecimal(DHT.temperature));
  Serial.println(humidity + "-" + temp);

  delay(1500);

}

long getDecimal(float val)
{
  int intPart = int(val);
  long decPart = 1000*(val-intPart); //I am multiplying by 1000 assuming that the foat values will have a maximum of 3 decimal places. 
                                    //Change to match the number of decimal places you need
  if(decPart>0)return(decPart);           //return the decimal part of float number if it is available 
  else if(decPart<0)return((-1)*decPart); //if negative, multiply by -1
  else if(decPart=0)return(00);           //return 0 if decimal part of float number is not available
}
