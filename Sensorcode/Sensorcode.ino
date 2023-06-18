#include <Adafruit_NeoPixel.h>

#define PIN 2 //D2 used to connect NeoPixel to Arduino Board
#define PIXELNUM 4 // No. of LED in NeoPixel Strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELNUM, PIN, NEO_GRB + NEO_KHZ800);
int sensorPin = 0;


int r = 0;
int g =  0;
int b = 0;

int delayVal = 1000; // Delay Value

void setup(){
  pixels.begin();
  Serial.begin(9600);
}

void loop(){

  int n = PIXELNUM;

  int reading  = analogRead(sensorPin); // Taking input from the sensor
  float voltage = (reading * 4.62)/1024; // converting the reading to voltage form
  int temp = (voltage -0.5)* 100; // converting the voltage to temp *C 

//Displays colour according to the temperature recorded.
  if(temp >= 0 && temp < 25){
    r = 0, g = 0, b = 225;
    for(int i = 0; i<n;i++)
      pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
  }
  else if(temp >= 25 && temp < 50){
    r = 225, g = 225, b = 0;
    for(int i = 0; i<n;i++)
      pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
  }
  else if(temp >= 50 && temp < 75){
    r = 225, g = 165, b = 0;
    for(int i = 0; i<n;i++)
      pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
  }
  else{
    r = 225, g = 0, b = 0;
    for(int i = 0; i<n;i++)
      pixels.setPixelColor(i, pixels.Color(r,g,b));
    pixels.show();
  }
// Prints the temperature 
  Serial.println("The Temp is:");
  Serial.print(temp);
  Serial.println(" C");

  delay(delayVal);
}