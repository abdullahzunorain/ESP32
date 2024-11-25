#define LED_GPIO 2
#define BTN_GPIO 4
 
int BTN_State = 0; // Variable To Store Button State
 
void setup()
{
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BTN_GPIO, INPUT);
}
 
void loop()
{
  // Read The Button State
  BTN_State = digitalRead(BTN_GPIO);
  // Assign The BTN State To The LED Pin
  digitalWrite(LED_GPIO, BTN_State);
}