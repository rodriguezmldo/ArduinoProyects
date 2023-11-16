#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C de la pantalla LCD
int lcdAddress = 0x27;  // Puedes utilizar un escáner I2C para encontrar la dirección correcta

// Número de columnas y filas del LCD
int lcdColumns = 16;
int lcdRows = 2;

// Pin del botón del joystick
int pinButton = 2;

// Estado del botón en la última iteración
int lastButtonState = HIGH;

// Contador para cambiar el mensaje en la pantalla LCD
int messageCount = 0;

// Brillo actual de la pantalla LCD (inicializado al máximo)
int lcdBrightness = 255;

// Mensajes a mostrar en la pantalla LCD
String messages[] = {
  "202250718", // Antonio Rodriguez
  "202258842", // Francisco Aparicio
  "202256565", // Jorge Vergara
  "202253693", // Luis Santiago
  "202254656", // Uriel Tapia
  "202222988", // Emir Garcia
  // Agrega más mensajes según sea necesario
};

// Inicializa la pantalla LCD
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

void setup() {
  // Inicializa la comunicación I2C
  Wire.begin();
  
  // Inicializa la pantalla LCD
  lcd.begin(lcdColumns, lcdRows);

  // Configura el pin del botón como entrada con resistencia pull-up
  pinMode(pinButton, INPUT_PULLUP);

  // Muestra el primer mensaje al inicio
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Matricula: " + String(messageCount + 1));
}

void loop() {
  // Lee el estado actual del botón
  int buttonState = digitalRead(pinButton);

  // Comprueba si el botón ha cambiado de estado (de presionado a no presionado o viceversa)
  if (buttonState != lastButtonState) {
    // Espera un breve momento para evitar rebotes del botón
    delay(50);

    // Verifica nuevamente el estado del botón después del breve momento
    buttonState = digitalRead(pinButton);

    // Si el botón está presionado, incrementa el contador y muestra el siguiente mensaje
    if (buttonState == LOW) {
      messageCount = (messageCount + 1) % (sizeof(messages) / sizeof(messages[0]));
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Matricula: " + String(messageCount + 1));
    }
  }

  // Actualiza el estado del botón para la próxima iteración
  lastButtonState = buttonState;

  // Ajusta el brillo de la pantalla LCD al máximo
  lcd.setBacklight(255);

  // Muestra el mensaje actual en la segunda línea del LCD
  lcd.setCursor(0, 1);
  lcd.print(messages[messageCount]);
}
