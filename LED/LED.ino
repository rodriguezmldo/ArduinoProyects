#include <Wire.h>
#include "LiquidCrystal_I2C.h"

<<<<<<< HEAD
// Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F, 16, 2); //

const int inputPin = 7;

int value = 0;

void setup()
{
  // Inicializar el LCD
  lcd.init();

  // Encender la luz de fondo.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("0: 100530248");

  pinMode(inputPin, INPUT); // sets the digital pin 7 as input
}

void loop()
{
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

  value = digitalRead(inputPin);

  if (value)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Limpiando...");
    delay(2000);
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("0: 100530248");
  }
}
=======
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(8000);
  digitalWrite(LED, LOW);
  delay(5000);
}
>>>>>>> d11c04eeeaf74afd052a15eff0689f539af19db7
