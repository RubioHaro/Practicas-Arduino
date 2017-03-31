int Foco1 = 2;
//int Foco2 = 0;
int Foco3 = 3;

void setup() {
  Serial.write(9600);
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);  
  // put your setup code here, to run once:

}

void loop() {
   PrenderyApagarFoquito(Foco1);
   PrenderyApagarFoquito(Foco3);
  
}
void PrenderyApagarFoquito(int foco,int tiempo){
  digitalWrite(foco,HIGH);
  delay(50); 
  digitalWrite(foco,LOW);
  delay(50); 
}
