#include <Wire.h> 
#include "SSD1306.h"
#include <DHT.h>



#define dataPin1 D2
#define dataPin2 D1
#define dataPin3 D6
#define dataPin4 D5
    
#define DHTTYPE1 DHT11
#define DHTTYPE2 DHT11
#define DHTTYPE3 DHT11 
#define DHTTYPE4 DHT11      

SSD1306  display(0x3C, D3, D4);   // D3 -> SDA,D4 -> SCL
DHT dht1(dataPin1, DHTTYPE1);
DHT dht2(dataPin2, DHTTYPE2);
DHT dht3(dataPin3, DHTTYPE3);
DHT dht4(dataPin4, DHTTYPE4);


void setup(){
  Serial.begin(115200); // or 9600 tak 
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  dht1.begin(); // initialize dht
  dht2.begin();
  dht3.begin();
  dht4.begin();

}
void displayWeather1 ()
{ display.clear();
  float h = dht1.readHumidity();
  // Read temperature as Celsius
  float t = dht1.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht1.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 1 Failed!");
    return;
  }
 
  display.clear();

  display.drawString(30, 0, "DTH 1 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
}

void displayWeather2(){ //Creating a function to read and display temperature and humidity on OLED display
  float h = dht2.readHumidity();
  // Read temperature as Celsius
  float t = dht2.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht2.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 2 Failed!");
    return;
  }
 Serial.println(h);
 Serial.println(t);
  display.clear();

  display.drawString(30, 0, "DTH 2");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 

}

void displayWeather3 ()
{ display.clear();
  float h = dht3.readHumidity();
  // Read temperature as Celsius
  float t = dht3.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht3.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 3 Failed!");
    return;
  }

 
  display.clear();

  display.drawString(30, 0, "DTH 3 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
}

void displayWeather4 ()
{ display.clear();
  float h = dht4.readHumidity();
  // Read temperature as Celsius
  float t = dht4.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht4.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "DHT 4 Failed!");
    return;
  }
  
  display.clear();

  display.drawString(30, 0, "DTH 4 ");
  display.drawString(0, 20, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 40, "Temp: " + String(t) + "°C"); 
  
  
  //display.drawString(0, 40, "Temp: " + String(f) + "°F"); 
}
void loop(){

  displayWeather1(); //Calling back the displayWeather function
  display.display();
  delay (5000);
  displayWeather2();
  display.display();
  delay (5000);
  displayWeather3();
  display.display();
  delay (5000);
  displayWeather4();
  display.display();
  delay (5000);
}
