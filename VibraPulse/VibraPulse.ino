int pin0 = 9;
int pin1 = 10;

void setup() {
  pinMode(pin0,OUTPUT);
  pinMode(pin1,OUTPUT);
}
void loop() {
  pulse(70,80,50);
  pulse(90,80,200);
}
void pos(int d) {
  digitalWrite(pin0,1);
  digitalWrite(pin1,0);
  delay(d);
}
void neg(int d) {
  digitalWrite(pin0,0);
  digitalWrite(pin1,1);
  delay(d);
}
void none(int d) {
  digitalWrite(pin0,0);
  digitalWrite(pin1,0);
  delay(d);
}
void pulse(int d1, int d2, int d3) {
  pos(d1);
  neg(d2);
  none(d3);  
}
