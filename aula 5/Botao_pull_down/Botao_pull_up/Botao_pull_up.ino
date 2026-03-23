/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Botão com Pull-down e envio serial

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */

const int pin_botaoA = 2;  
bool botaoA = false;       

const int pin_botaoB = 3;  
bool botaoB = false;

const int led_vermelho = 5;  
const int led_verde = 6;     
const int led_amarelo = 7;   
char led;


void setup() {
  pinMode(pin_botaoA, INPUT_PULLUP);  
  pinMode(pin_botaoB, INPUT_PULLUP);  
  Serial.begin(115200);
}

void loop() {
  botaoA = digitalRead(pin_botaoA);            
  botaoB = digitalRead(pin_botaoB);          
  if (botaoA == 0 && botaoB == 0) {
    digitalWrite(led_vermelho, HIGH);  
  }
  else 
  digitalWrite(led_vermelho, LOW);

 if (botaoA == 0 || botaoB == 0) {
    digitalWrite(led_verde, HIGH);  
  }
  else 
  digitalWrite(led_verde, LOW);

if (botaoA == 0 ^ botaoB == 0) {
    digitalWrite(led_amarelo, HIGH);  
  }
  else 
  digitalWrite(led_amarelo, LOW);
  }
  


