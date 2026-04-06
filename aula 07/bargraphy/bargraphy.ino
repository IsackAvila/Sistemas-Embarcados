int pin_sensor = A0;
int valor_sensor = 0;
int ledvm = 9;
int ledam = 10;
int ledvd = 11;

void setup() {
  pinMode(pin_sensor, INPUT);
  pinMode(ledvm, OUTPUT);
  pinMode(ledam, OUTPUT);
  pinMode(ledvd, OUTPUT);
  }

void loop() { 
valor_sensor = analogRead(pin_sensor);
float valor_tensao = (valor_sensor * 5.0/1023);
 Serial.print ("Valor tensao = ");
  Serial.println(valor_tensao);
  delay(200);

  if (valor_tensao < 1) {                   
      digitalWrite(ledvm, 0);  
      digitalWrite(ledam, 0);  
      digitalWrite(ledvd, 0);
}
if (valor_tensao >=1 ) {                   
      digitalWrite(ledvm, 1);  
      digitalWrite(ledam, 0);  
      digitalWrite(ledvd, 0);
}

if (valor_tensao >=2 ) {                   
      digitalWrite(ledvm, 0);  
      digitalWrite(ledam, 1);  
      digitalWrite(ledvd, 0);
}

if (valor_tensao >=3 ) {                   
      digitalWrite(ledvm, 0);  
      digitalWrite(ledam, 0);  
      digitalWrite(ledvd, 1);
}

if (valor_tensao >=4 ) {                   
      digitalWrite(ledvm, 1);  
      digitalWrite(ledam, 1);  
      digitalWrite(ledvd, 1);
}
}