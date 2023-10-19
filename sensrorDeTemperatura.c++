// SENSOR DE TEMPERATURA USANDO O LM35

const int sensorDeTemperatura = A0; /* define o pino de dados do sensor */
float temperatura = 0 ; /* variavel que vai armazenar a temperatura medida */

void setup() {
	Serial.begin(9600); /* inicia a comunicação serial*/

	pinMode(sensorDeTemperatura, INPUT); /* Define o pino A0 como ENTRADA. */
}

// funçao que vai ser executada continuamente 

void loop (){
	/* Determina a temperatura a partir da tensão obtida do sensor de temperatura */
  temperatura = (float(analogRead(sensorDeTemperatura)) * 5 / (1023) ) / 0.01 ;
  	Serial.print("Temperatura: "); // vai estar escrito temeperatura e vai mostrar o valor
	Serial.println("°C"); // moatrar os graus em celsos
	delay(2000);
}
