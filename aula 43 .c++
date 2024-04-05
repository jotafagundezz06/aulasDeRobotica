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
int sensorValue = 0; // Variable to store the sensor value

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

sensorValue = digitalRead(PIN_SENSOR);

/* Switch with two modes of operation: mode open for cars and mode pedestrian crossing. While the sensor does not detect a pedestrian, the mode of operation remains at 0, that is, open for the passage of cars. If the sensor detects a pedestrian, the attachInterrupt function will immediately change the mode of operation to 1, that is, it will enter the pedestrian crossing mode. */
switch (modo) {
 case 0:
     modocarros();
 break;
 case 1:
     travessia();
 break;
}
}

void sensorAcionado() {
modo = 1;
}

void travessia() {
delay(1000);
digitalWrite(PIN_LED_VERDE_CAR, LOW);
digitalWrite(PIN_LED_AMARELO_CAR, HIGH);
delay(3000);
digitalWrite(PIN_LED_VERDE_PED, HIGH);
digitalWrite(PIN_LED_VERMELHO_PED, LOW);
digitalWrite(PIN_LED_AMARELO_CAR, LOW);
digitalWrite(PIN_LED_VERMELHO_CAR, HIGH);
delay(5000);
digitalWrite(PIN_LED_VERDE_PED, LOW);
for (int i = 0; i <= 5; i++)
{
 digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
 delay(300);
 digitalWrite(PIN_LED_VERMELHO_PED, LOW);
 delay(300);
}
modo = 0; /* After the pedestrian crossing, changes to the mode of passage of cars: 0. */
}

/* Function that activates the LEDs for the mode "Open for cars" */
void modocarros() {
digitalWrite(PIN_LED_VERDE_PED, LOW);
digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
digitalWrite(PIN_LED_VERDE_CAR, HIGH);
digitalWrite(PIN_LED_AMARELO_CAR, LOW);
digitalWrite(PIN_LED_VERMELHO_CAR, LOW);
}
