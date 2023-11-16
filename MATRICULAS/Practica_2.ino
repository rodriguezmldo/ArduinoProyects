#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C de la pantalla LCD
int lcdAddress = 0x27;  // Puedes utilizar un escáner I2C para encontrar la dirección correcta

// Número de columnas y filas del LCD
int lcdColumns = 16;
int lcdRows = 2;

// Pin del botón del joystick
int pinButton = 2;
// Pin del eje Y del joystick
int pinJoystickY = A1;

// Estado del botón en la última iteración
int lastButtonState = HIGH;

// Contador para cambiar el mensaje en la pantalla LCD
int messageCount = 0;

// Brillo actual de la pantalla LCD (inicializado al máximo)
int lcdBrightness = 255;

// Mensajes a mostrar en la pantalla LCD
String messages[] = {
  "Francisco",
  "Ztecomani Jr.",
  "José Luis",
  "Antonio",
  "Emir",
  "Stu ",
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
      lcd.print(messages[messageCount]);
    }
  }

  // Actualiza el estado del botón para la próxima iteración
  lastButtonState = buttonState;

  // Lee el valor del eje Y del joystick
  int joystickYValue = analogRead(pinJoystickY);

  // Mapea el valor del joystick Y al rango de brillo de la pantalla LCD (0 a 255)
  lcdBrightness = map(joystickYValue, 0, 1023, 0, 255);

  // Ajusta el brillo de la pantalla LCD
  lcd.setBacklight(lcdBrightness);
}
