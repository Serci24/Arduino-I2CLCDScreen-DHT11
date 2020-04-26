#include <DHT.h> //Required libraries
#include <LiquidCrystal_I2C.h> //Required libraries

#define dhtTip DHT11 //sensor pin and sensor type

byte  btnPin = 4; //this is button pin
int  sensorPin = 2;//this is sensor pin

LiquidCrystal_I2C lcd(0x3f, 16, 2); //We created a LCD Screen Object.We will use this object when using the screen. LCD type and IIC protocol code. (0x3f or 0x27)
DHT dht(sensorPin, dhtTip); //We created a object. This object is dht. We will use this object when we read the temperature .We have defined the sensor type and which pin the sensor is.

void setup() {
  lcd.begin(); //lcd is start
  dht.begin();//DHT is start
  pinMode(sensorPin, INPUT); // sensor pin is INPUT
  pinMode(btnPin, INPUT);  // botton pin is INPUT
}

void loop() {
  sensorPin = dht.readTemperature(); //DHT 11 Sensor temperature reading function
  int hum = dht.readHumidity(); //DHT 11 Sensor humidity reading function
  delay(300);
  btnPin = digitalRead(4);

  if (btnPin == 1) {
    lcd.display(); //Screen on.
    lcd.backlight();//Backlight on.
    lcd.home();
    lcd.print("Temperature :"); //print "Temperature :"
    lcd.setCursor(14, 0); //We came to line 14.
    lcd.print(sensorPin);//We write the Temperature.
    lcd.setCursor(0, 1);//We went to the bottom column
    lcd.print("Humidity :"); //We write the "Humidity :"
    lcd.setCursor(11, 1); //We came to line 11 bottom column.
    lcd.print("%");
    lcd.print(hum);//print humidity.
    delay(5000); //wait 5 second.
  }
  else {
    lcd.clear(); //lcd screen clear function.
    lcd.noBacklight();//off the backlight.
    lcd.noDisplay(); // off the display.
  }
}
