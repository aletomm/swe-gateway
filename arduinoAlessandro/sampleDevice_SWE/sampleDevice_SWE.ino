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

  Serial.println("{");
  Serial.println("  \"id\":\"1\",");
  Serial.println("  \"sensori\": {");
  
    Serial.println("    \"sensore1\": {");
    Serial.println("      \"id\": \"1\",");
    Serial.print("      \"value\": \"");
    Serial.print(tempSensorVal);
    Serial.println("\" ");
    Serial.println("    },");

    Serial.println("    \"sensore2\": {");
    Serial.println("      \"id\": \"2\",");
    Serial.print("      \"value\": \"");
    Serial.print(voltage);
    Serial.println("\"");
    Serial.println("    },");

    Serial.println("    \"sensore3\": {");
    Serial.println("      \"id\": \"3\",");
    Serial.print("      \"value\": \"");
    Serial.print(temperature);
    Serial.println("\" ");
    Serial.println("    },");

    Serial.println("    \"sensore4\": {");
    Serial.println("      \"id\": \"4\",");
    Serial.print("      \"value\": \"");
    Serial.print(lightSensorVal);
    Serial.println("\" ");
    Serial.println("    },");

    Serial.println("    \"sensore5\": {");
    Serial.println("      \"id\": \"5\",");
    Serial.print("      \"value\": \"");
    Serial.print(potValue);
    Serial.println("\" ");
    Serial.println("    }");
    
  Serial.println("  }");
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
    delay(500);    

}
