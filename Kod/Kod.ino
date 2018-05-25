bool isSitting = false;
int digitalButton = 2;
int ledPin = 13;
int initialSittingMoment; // in seconds
int initialStandingMoment; // in seconds

int maxSittingDuration = 5; // in seconds
int maxStandingDuration = 10; // in seconds

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(digitalButton,INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Serial.println(millis()/1000);
  if(digitalRead(digitalButton)==HIGH && !isSitting){
    // a person is sitting on the chair
    initialSittingMoment = millis()/1000;
    isSitting = true;
    digitalWrite(ledPin,HIGH);
  }
  if(digitalRead(digitalButton)==LOW && isSitting) {
    // a person is standing
    initialStandingMoment = millis()/1000;
    isSitting = false;
    digitalWrite(ledPin,LOW);
  }
  //Serial.print("initialSittingMoment : ");
  //Serial.println(initialSittingMoment);
  //Serial.print("initialStandingMoment : ");
  //Serial.println(initialStandingMoment);

  int durationPassed = millis() / 1000;

  if((durationPassed - initialSittingMoment > maxSittingDuration) && isSitting){
    //the moment we should tell the person to leave
    Serial.println("Goodbye darling");
  }

  if((durationPassed - initialStandingMoment > maxStandingDuration) && !isSitting){
    //the moment we should tell the person to come
    Serial.println("Come back darling");
  }
  
  delay(500);
  
}
