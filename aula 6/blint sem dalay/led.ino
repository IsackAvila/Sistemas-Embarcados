************************ */

const int botao = 2;        //cria a variavel botao e diz que ta na entrada 2
bool estadoBotao = HIGH;    // cria a variavel do "estadp atual do botão" e atribui como high
                            //pega o valor dado do "presente"
bool leituraAntiga = HIGH;  // cria uma variavel pra primeira leitura do botão pra conseguir comparar e fazer o debouce
                            // debounce vai ser quaqnod a gente fildtra o tempo de estabelização do botao pro valor "certo" dele
                            //espera ele parar de tremer e dai varios sinais e pega o definitivo dando um tempo pra poder ler o valor
unsigned long tempo = 0;    //// cria uma variavel pra guardar o momento em que a mudança aconteceu
const int debounce = 50;    // cria uma constante pra definir um tempo de estabiliziação do debounce

const int led_verde = 13;

void setup() {
  pinMode(botao, INPUT_PULLUP);  // configura o botão como pullup
  pinMode(led_verde, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int leitura = digitalRead(botao);  // cria umaq variavel chamada leitura e dai atribui a ela o valor do botao (no caso é a variavel da leitura do valor do botao)

  if (leitura != leituraAntiga) {  // se a leitura (valor do botao) for difente do ultimo valor lido
    tempo = millis();              // guarda o mili segundo exato da mudança de estado do botao
  }

  if (millis() - tempo > debounce) {  // verifica se ja passou o tempo do debouce
    estadoBotao = leitura;            // se millis - tempo for maior que debounce confirmq que a leitura é confiavel (no caso o valormlido)
                                      //Se do valor do tempo que passou desde a mudança de valor - tempo
                                      //o valor de "timer" e o resultado for maior que o tempo definido no "debouncetimer"
  }
    if (estadoBotao == LOW) {         // se o etsado do botao for pressionado a 13 liga
      digitalWrite(led_verde, HIGH);  // se n n liga
    } else {
      digitalWrite(led_verde, LOW);
    }
  }
    leituraAntiga = leitura;  // a leitura antiga agr vau ter i valor atribuido da leitura desse ciclo de maquina
    // fica dentro do loop
}