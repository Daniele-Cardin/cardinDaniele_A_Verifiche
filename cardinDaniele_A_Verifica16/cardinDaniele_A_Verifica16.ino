  int ledRosso = 10;
  int ledGiallo = 8;
  int ledBianco = 6;
  int ledVerde = 4;
  int numeroCicli = 0;
  int durataSpegnimento = 0;
  String valoreInserito = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBianco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
  Serial.println("seriale attivata");
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Quanti cicli deve fare?");
  while (Serial.available() == 0); 
  valoreInserito = Serial.readString();
  numeroCicli = valoreInserito.toInt();
  Serial.print("Il ciclo si ripete: ");
  Serial.println(numeroCicli);
  while (numeroCicli == 0);
  digitalWrite(ledRosso, HIGH);
  digitalWrite(ledGiallo, HIGH);
  digitalWrite(ledBianco, HIGH);
  digitalWrite(ledVerde, HIGH);
  durataSpegnimento = random(1, 10);
  durataSpegnimento = durataSpegnimento * 1000;
  Serial.print("I led stanno spenti per: ");
  Serial.println(durataSpegnimento);
  for(int i = 0; i < numeroCicli; i++){
  digitalWrite(ledRosso, LOW);
  digitalWrite(ledGiallo, LOW);
  delay(durataSpegnimento);
  digitalWrite(ledRosso, HIGH);
  digitalWrite(ledGiallo, HIGH);
  digitalWrite(ledBianco, LOW);
  digitalWrite(ledVerde, LOW);
  delay(durataSpegnimento);
  digitalWrite(ledBianco, HIGH);
  digitalWrite(ledVerde, HIGH); 
  Serial.print("Eseguito il ciclo: ");
  Serial.println(i + 1);   
  }
  
  
}
