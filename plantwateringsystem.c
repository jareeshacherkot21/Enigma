#include <DHT.h>  

#define DHTPIN 2      
#define DHTTYPE DHT11 
#define digitalSensor A0
#define pumpPin 8

DHT dht(DHTPIN, DHTTYPE); 
float humidity;

void setup() {
  dht.begin();              
  Serial.begin(9600);       
  pinMode(digitalSensor, INPUT);  
  pinMode(pumpPin, OUTPUT);       
  Serial.println("Humidity Monitor");
}

void loop() {
  if (digitalRead(digitalSensor) == HIGH) {  
    digitalWrite(pumpPin, HIGH);  
    delay(1500);                   
    digitalWrite(pumpPin, LOW);   
    delay(3600000);                
  }

  humidity = dht.readHumidity();

  
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\r\n");

  delay(5000); 
}