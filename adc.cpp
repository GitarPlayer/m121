/*
  Analog Input
  Das Potentiometer liefert einen analogen Wert (0-5V) an Pin A3.
  Die Blinkfrequenz des Onboard-LED's soll sich entsprechend dem
  ADC-Wert verändern. Beim ADC-Wert 1000 ist die Blinkrate 1 sec,
  beim Wert 500 0.5 sec, etc.
 */

int sensorPin = A3;                        // pin  potentiometer
int ledPin = 13;                           // pin Onboard-LED
int ADCValue = 0;                          // ADC-Wert Potentiometer
float spannung_berechnet = 0.00;
float Referenzspannung = 5.00;             // Systemspannung des Arduino UNO. Kontrollieren Sie
                                           // diese mit dem Multimeter und passen Sie dies
                                           // evtl. an. Vielleicht sind es ja 5.1 V ...


void setup() {
  Serial.begin(9600);
  // ledPin ist ein OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ADCValue = analogRead(sensorPin);   // Lesen des analogen Signals an A3
  spannung_berechnet = (ADCValue*Referenzspannung)/1023;
  Serial.print("ADC-Wert: ");
  Serial.print(ADCValue);
  Serial.print("  Spannung: ");
  Serial.print(spannung_berechnet);
  Serial.println(" Volt");
  // ledPin einschalten
  digitalWrite(ledPin, HIGH);
  // stop des Programms entsprechend dem ADC-Wert
  delay(ADCValue);
  // ledPin ausschalten:
  digitalWrite(ledPin, LOW);
  // stop des Programms entsprechend dem ADC-Wert
  delay(ADCValue);
}
