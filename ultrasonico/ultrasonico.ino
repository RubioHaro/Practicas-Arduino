int Foco1 = 2;
int Foco3 = 3;
int tiempoFoco=100;

long distancia;
long tiempo;
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(9, LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo = pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia = int(0.017 * tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.print(distancia);
  Serial.println(" cm");


  if(distancia > 3000){
    tiempoFoco =50;
  }
  
  if(distancia > 0 && distancia < 10){
    tiempoFoco =50;
  }
  if(distancia > 10 && distancia < 50){
    tiempoFoco =100;
  }
  if(distancia > 100){
    tiempoFoco =0;
  }
  
  PrenderyApagarFoquito(Foco1,tiempoFoco);
  PrenderyApagarFoquito(Foco3,tiempoFoco);

}
void PrenderyApagarFoquito(int foco, int tiempofoco) {
  
  digitalWrite(foco, HIGH);
  delay(tiempofoco);
  digitalWrite(foco, LOW);
  delay(tiempofoco);
}
