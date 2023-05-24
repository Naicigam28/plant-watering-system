//Original Code: https://www.instructables.com/Arduino-Plant-Watering-System/
//Amended by Armandus Basson
//For Arduino UNO
//Components / Kit: https://www.robofactory.co.za/home/232-automatic-smart-plant-watering-kit.html
 
int waterPump = 5; //Relay Pin = 5
 
void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
}
 
void loop() {
  int humidityRaw = analogRead(A2);
  int humidityReal = map(humidityRaw, 1023, 0 ,0, 100); //Convert raw sensor data to percentage
   if (humidityReal > 30) //Set threshold when relay must open for pump to feed water
  {
    digitalWrite(waterPump, HIGH);
    
  }else{
    digitalWrite(waterPump, LOW);
  }
  delay(4000); //Delay before next sensor reading. Current set as 4 seconds
}