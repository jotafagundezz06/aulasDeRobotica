// aula potenciometro

#define PIN_POT A0 
#define LED 3

int dados_POT;
int pwm;

void setup (){
 /* definindo pinos como entrada */
  pinMode(PIN_POT, INPUT);
  /* definindo pinos como saida */
  pinMode(LED, OUTPUT);
  /* funçao para fazer leitura pela a porta usb infiormando a taxa em bauds*/
  Serial.begin(9600);
    
}
void loop (){
  /* ler o potenciometro e guardar na variavel dos dados_pot e 
  manda para o serial*/
  dados_POT = analogRead(PIN_POT);
  /* a FUNÇAO map exige 5 parametros */
  /* 1 de onde vem os dados */
  /* 2 e 3 qual é a escala de inicio e fim*/
  /* 4 e 5 qual escal de inicio de fim */
  pwm = map (dados_POT, 0, 1023,0,255);
  
  /* escrevendi no monitor serial*/
  Serial.println(pwm);
  Serial.println(dados_POT);
  /* funçao analogWrite exige dois parametros*/
  /*pino de saida  e valores entre a e 255*/
  analogWrite(LED, pwm);
  delay(100);
  
}
