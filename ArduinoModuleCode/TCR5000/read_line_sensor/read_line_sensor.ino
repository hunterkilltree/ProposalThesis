
const int pinA5 = A5; // output pin on sensors connect A5 arduino

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinA5, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nAnalog Reading");
  Serial.print(analogRead(pinA5)); // value is 472- 475 in normal condition, 0 - 6 with white card in front of (accept range ( < 3cm)

  delay(500);
}
