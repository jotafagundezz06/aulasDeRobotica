//sensor de luz aula 27 com buzzer 

int Sensor_LDR = 0; /* Variável que armazenará os dados do
LDR. */
int BuzzerPin = 6 ;
int Pin_LDR = A0; /* Define A0 como pino do LDR. */
int Pin_LED = 5; /* Define 5 como pino do LED. */
void setup() {
  pinMode(BuzzerPin , OUTPUT); // buzzerPin (pino 8) definido como saída
 
pinMode(Pin_LDR, INPUT); /* Define o pino do LDR como
ENTRADA. */
pinMode(Pin_LED, OUTPUT); /* Define o pino do LED como
SAÍDA. */
Serial.begin(9600); /* Inicia a comunicação serial.
*/
}
void loop() {
Sensor_LDR = analogRead(Pin_LDR); /* A variável recebe os
dados lidos no pino A0. */
Serial.println(Sensor_LDR); /* Imprime o valor lido
do LDR (0 a 1023). */
delay(100);
if(Sensor_LDR < 800){ /* Se o valor lido for
menor que 800, */
digitalWrite(Pin_LED, HIGH); /* liga o LED. */
digitalWrite (BuzzerPin , HIGH); 
 
}else{ /* Senão... */
digitalWrite(Pin_LED, LOW); /* desliga o LED. */
digitalWrite (BuzzerPin, LOW );
}
}
