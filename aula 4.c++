/* Aula 4 robotica parana - Sensor infra red
 *  Turma 3B / 2024 - If Fisica 3 - Robotica 2
 *  Alunos : Brunno 4, Diego 6, Gabriel 9, Jean 14, Joao c 16, Kauane 22, Luiz 24, Nathalia 31, Nicolas 32 
 */

 /* Programa: Semáforo inteligente. */
/* Definições dos pinos para os LEDs e sensor. */
#define PIN_SENSOR 2
#define PIN_LED_VERDE_CAR 3
#define PIN_LED_AMARELO_CAR 4
#define PIN_LED_VERMELHO_CAR 5
#define PIN_LED_VERDE_PED 6
#define PIN_LED_VERMELHO_PED 7
int modo = 0; /* Variável que seleciona o modo de operação do 
semáforo 0: Modo aberto para carros e 1: Modo travessia de 
pedestres. */
void setup()
{
/* Configura o pino do sensor como ENTRADA. */
pinMode(PIN_SENSOR, INPUT);
/* Loop para configurar os pinos 3 a 7 como SAÍDA. */
for (int i = 3; i <= 7; i++) {
 pinMode(i, OUTPUT);
}
/* Ativa a função de interrupção no pino que o sensor está 
ligado. */
attachInterrupt(digitalPinToInterrupt(PIN_SENSOR),
sensorAcionado, FALLING);
}
void loop()
{
/* Switch com dois modos de operação: modo aberto para 
carros e modo travessia de pedestre. Enquanto o sensor 
não detectar um pedestre, o modo de operação permanece 
em 0, ou seja, aberto para a passagem dos carros. Caso o 
sensor detecte um pedestre, a função attachInterrupt irá 
imediatamente alterar o modo de operação para 1, ou seja, 
entrará no modo de travessia dos pedestres. */
switch (modo) {
 case 0:
     modocarros();
 break;
 case 1:
     travessia();
 break;
}
}
/* Após o sensor detectar o pedestre, será executada essa 
função, ela altera o modo de operação do semáforo. */
void sensorAcionado() {
modo = 1;
}
/* Função que ativa os LEDs para o modo “Travessia de 
pedestres” */
void travessia() {
/* Aguarda +1 segundo após o sensor detectar o pedestre */
delay(1000);
/* Aciona o amarelo do semáforo dos carros */
digitalWrite(PIN_LED_VERDE_CAR, LOW);
digitalWrite(PIN_LED_AMARELO_CAR, HIGH);
delay(3000);
/* Abre o semáforo de pedestres. */
digitalWrite(PIN_LED_VERDE_PED, HIGH);
digitalWrite(PIN_LED_VERMELHO_PED, LOW);
digitalWrite(PIN_LED_AMARELO_CAR, LOW);
digitalWrite(PIN_LED_VERMELHO_CAR, HIGH);
delay(5000);
/* Apaga o verde dos pedestres e começa a piscar o 
vermelho, indicando que o tempo de travessia está acabando. 
*/
digitalWrite(PIN_LED_VERDE_PED, LOW);
for (int i = 0; i <= 5; i++)
{
 digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
 delay(300);
 digitalWrite(PIN_LED_VERMELHO_PED, LOW);
 delay(300);
}
modo = 0; /* Após a travessia de pedestre, altera para o 
modo de passagem de carros: 0. */
}
/* Função que ativa os LEDs para o modo “Aberto para carros” 
*/
void modocarros() {
digitalWrite(PIN_LED_VERDE_PED, LOW);
digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
digitalWrite(PIN_LED_VERDE_CAR, HIGH);
digitalWrite(PIN_LED_AMARELO_CAR, LOW);
digitalWrite(PIN_LED_VERMELHO_CAR, LOW);
}
