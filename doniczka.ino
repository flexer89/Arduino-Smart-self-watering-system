// Define the pins for the pumps and moisture sensors
int pump1 = 5;
int pump2 = 6;
int pump3 = 7;
int moistureSensor1 = A0;
int moistureSensor2 = A1;
int moistureSensor3 = A2;

// Define the moisture level that triggers watering
int moistureThreshold = 500;

void setup() 
{
  // Set the pump pins as outputs
  Serial.begin(9600);
  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  pinMode(pump3, OUTPUT);

  digitalWrite(pump1, HIGH);
  digitalWrite(pump2, HIGH);
  digitalWrite(pump3, HIGH);

  // Set the sensor pins as inputs
  pinMode(moistureSensor1, INPUT);
  pinMode(moistureSensor2, INPUT);
  pinMode(moistureSensor3, INPUT);
}

void loop() {
  // Read the moisture levels of each sensor
  int moistureLevel1 = analogRead(moistureSensor1);
  int moistureLevel2 = analogRead(moistureSensor2);
  int moistureLevel3 = analogRead(moistureSensor3);

  Serial.print("Wilgotnosc 1 ");
  Serial.println(moistureLevel1);
  Serial.print("Wilgotnosc 2 ");
  Serial.println(moistureLevel2);
  Serial.print("Wilgotnosc 3 ");
  Serial.println(moistureLevel3);
  Serial.println();
  delay(1000);

  // Check if the moisture level is below the threshold for each sensor and turn on the corresponding pump if it is
  if (moistureLevel1 > moistureThreshold) 
  {
    digitalWrite(pump1, LOW);
    delay(2000);
    digitalWrite(pump1, HIGH);
  } 
  else 
  {
    digitalWrite(pump1, HIGH);
  }



  if (moistureLevel2 > moistureThreshold) 
  {
    digitalWrite(pump2, LOW);
    delay(2000);
    digitalWrite(pump2, HIGH);
  } 
  else 
  {
    digitalWrite(pump2, HIGH);
  }



  if (moistureLevel3 > moistureThreshold) 
  {
    digitalWrite(pump3, LOW);
    delay(2000);
    digitalWrite(pump3, HIGH);
  } 
  else 
  {
    digitalWrite(pump3, HIGH);
  }

  // Delay for a short period before checking the moisture levels again
  delay(120000);
}
