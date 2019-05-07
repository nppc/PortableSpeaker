// Encoders variables
volatile char encoder0Pos = 0;
volatile byte encoder0Change = 0;
unsigned long encoder0millis = 0;

volatile char encoder1Pos = 0;
volatile byte encoder1Change = 0;
unsigned long encoder1millis = 0;

void doEncoder0() {
    // If interrupts come faster than 5ms, assume it's a bounce and ignore
    if (millis() - encoder0millis > 5) {
        if (!bitRead(PIND,encoder0PinB))
            encoder0Pos++;
        else
            encoder0Pos--;
        }
    encoder0millis = millis();
  // here is code to process encoder change...
  encoder0Change = 1;
}

void doEncoder1() {
    // If interrupts come faster than 5ms, assume it's a bounce and ignore
    if (millis() - encoder1millis > 5) {
        if (!bitRead(PIND,encoder1PinB))
            encoder1Pos++;
        else
            encoder1Pos--;
        }
    encoder1millis = millis();
  // here is code to process encoder change...
  encoder1Change = 1;
}


void encoderInit() {
	pinMode(encoder0PinA, INPUT_PULLUP); 
	pinMode(encoder0PinB, INPUT_PULLUP); 
	pinMode(encoder1PinA, INPUT_PULLUP); 
	pinMode(encoder1PinB, INPUT_PULLUP); 
	pinMode(BUTTON0_PIN, INPUT_PULLUP);
	pinMode(BUTTON1_PIN, INPUT_PULLUP);

	attachInterrupt(0, doEncoder0, FALLING);  // encoder pin on interrupt 0 - pin 2
	attachInterrupt(1, doEncoder1, FALLING);  // encoder pin on interrupt 1 - pin 3	
}