// Aula 1 - Robotica 2 2024 3B
// Aula 2 (Robotica Parana) - funcoes
// Autor : Joao carlos Fagundez

int buzzer = 3; /* define a porta do arduino como 3 */


void setup () {
	pinMode(buzzer, OUTPUT); // DEFINE A PORTA COMO SAIDA 
  

}


void loop () {
	/*Acionar o buzzer na frequencia relativa a noda DO em Hz*/
  tone (buzzer, 261);
  
  // Esperar um tempo para deligar
  
  delay(200);
  
  // desligando o buzzer 
	noTone(buzzer);

  
	/*Acionar o buzzer na frequencia relativa a noda RE em Hz*/
  tone (buzzer, 263);
  
  // Esperar um tempo para deligar
  
  delay(200);
  
  // desligando o buzzer 
	noTone(buzzer);
  
  
	/*Acionar o buzzer na frequencia relativa a noda Mi em Hz*/
  tone (buzzer, 330);
  
  // Esperar um tempo para deligar
  
  delay(200);
  
  // desligando o buzzer 
	noTone(buzzer);

 
	/*Acionar o buzzer na frequencia relativa a noda FA em Hz*/
  tone (buzzer, 349);
  
  // Esperar um tempo para deligar
  
  delay(200);
  
  // desligando o buzzer 
	noTone(buzzer);

	
	/*Acionar o buzzer na frequencia relativa a noda SOL em Hz*/
  tone (buzzer, 392);
  
  // Esperar um tempo para deligar
  
  delay(200);
  
  // desligando o buzzer 
	noTone(buzzer);

}
