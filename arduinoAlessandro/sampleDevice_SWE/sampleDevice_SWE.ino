 const int tempSensorPin = A0;
 const float baselineTemp = 20.0;
 const int lightSensorPin = A1;
 const int potPin = A2;
  
void setup() {
  Serial.begin(9600);
  for(int pinNumber=2; pinNumber<5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);  
  }

}

void loop() {
  int lightSensorVal = analogRead(lightSensorPin);
  int tempSensorVal = analogRead(tempSensorPin);
  int potValue = analogRead(potPin);
  float voltage = (tempSensorVal/1024.0)*5.0;
  //  Converto la tensione in temperatura;
  float temperature = (voltage - .5)*100;

  Serial.print("{");
  Serial.print("\"id\":\"1\",");
  Serial.print("\"sensori\": {");
  
    Serial.print("\"sensore1\": {");
    Serial.print("\"id\": \"1\",");
    Serial.print("\"value\": \"");
    Serial.print(tempSensorVal);
    Serial.print("\"");
    Serial.print("},");

    Serial.print("\"sensore2\": {");
    Serial.print("\"id\": \"2\",");
    Serial.print("\"value\": \"");
    Serial.print(voltage);
    Serial.print("\"");
    Serial.print("},");

    Serial.print("\"sensore3\": {");
    Serial.print("\"id\": \"3\",");
    Serial.print("\"value\": \"");
    Serial.print(temperature);
    Serial.print("\"");
    Serial.print("},");

    Serial.print("\"sensore4\": {");
    Serial.print("\"id\": \"4\",");
    Serial.print("\"value\": \"");
    Serial.print(lightSensorVal);
    Serial.print("\" ");
    Serial.print("},");

    Serial.print("\"sensore5\": {");
    Serial.print(" \"id\": \"5\",");
    Serial.print("\"value\": \"");
    Serial.print(potValue);
    Serial.print("\"");
    Serial.print("}");
    
  Serial.print("}");
  Serial.println("}");


 //Cambio i led in base alla temperatura
  if(temperature < baselineTemp-3){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    }else if(temperature > baselineTemp+2) {
      
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
     }else{
  
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
      }
        
     if(lightSensorVal < 10){
        digitalWrite(2, HIGH);
      }else{
        digitalWrite(2, LOW);
       }   
    delay(200);    

}
