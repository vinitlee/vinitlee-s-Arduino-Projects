#define HIGHPIN 4
#define LOWPIN 7

bool onLast = false;

int sequence[10];
int length = 0;

int b = -2;

void setup () {
	pinMode(HIGHPIN,OUTPUT);
	pinMode(LOWPIN,OUTPUT);
	Serial.begin(9600);
}
void loop () {
	if (Serial.available() > 0) {
		// read the incoming byte:
		b = Serial.parseInt();
		
		if (b > 0) {
			Serial.print(b);
			sequence[length] = b;
			length++;
			b = -2;
		}
		if (b == -1) {
			if (length%2 == 1) {
				sequence[length] = 0;
				length++;
			}
			for (int i=0; i<length; i++) {
				startVib();
				delay(sequence[i]);
				endVib();
			}
			endVib();
			length = 0;
		}
		if (b == -3) {
			endVib();
			length = 0;
		}
	}
}

void startVib () {
	if (onLast) {
		digitalWrite(HIGHPIN,0);
		digitalWrite(LOWPIN,0);
	}
	else {
		digitalWrite(HIGHPIN,1);
		digitalWrite(LOWPIN,0);	
	}
	onLast = !onLast;
}
void endVib () {
	if (onLast) {
		digitalWrite(HIGHPIN,0);
		digitalWrite(LOWPIN,1);
		delay(10);
	}
	digitalWrite(HIGHPIN,0);
	digitalWrite(LOWPIN,0);
}