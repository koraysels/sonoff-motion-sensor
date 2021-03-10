int gpio_13_led = 13;
int gpio_14_sensor = 14;
int gpio_12_relay = 12;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  pinMode(gpio_13_led, OUTPUT);
  pinMode(gpio_12_relay, OUTPUT);
  pinMode(gpio_14_sensor, INPUT);
}

bool inflating = false;
void loop() {
  long state = digitalRead(gpio_14_sensor);
  if (state == HIGH) {
    Serial.println("Motion detected!, starting to inflate for 30 seconds");
    inflating = true;
    digitalWrite(gpio_13_led, LOW); // LOW will turn on the LED
    digitalWrite(gpio_12_relay, HIGH);  // HIGH will turn on relay
    delay(30 * 1000); //start inflating for 30 seconds
  }

  digitalWrite(gpio_13_led, HIGH); // HIGH will turn off the LED
  digitalWrite(gpio_12_relay, LOW);  // LOW will turn off relay

  if (inflating) {
    Serial.println("Waiting 60 seconds to deflate.");
    delay(60 * 1000);
    inflating = false; //make sure the state is as before
  } else {
    delay(300);
  }
}
