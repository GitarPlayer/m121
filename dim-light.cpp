#define NORMALER_PIN 11
#define BESONDERER_PIN 10

void setup()
{
  pinMode(NORMALER_PIN, OUTPUT);
  pinMode(BESONDERER_PIN, OUTPUT);
 }
 
 void loop()
 {
  digitalWrite(NORMALER_PIN, HIGH);
  
  digitalWrite(BESONDERER_PIN, HIGH);
  delay(10);
  digitalWrite(BESONDERER_PIN, LOW);
  delay(10);
}
