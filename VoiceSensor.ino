int num_Measure = 10 ; // Set the number of measurements   
int pinSignal = A0; // pin connected to pin O module sound sensor  
long Sound_signal;    // Store the value read Sound Sensor   
long sum = 0 ; // Store the total value of n measurements   
long avg_Level = 0 ; // Store the average value     
long max_Level = 0 ; // Store the maximum value   
int dB = 0; // dB level 
int number_of_cars = 0; // number of cars for each 10s
int id = 0; // id of each test

 
void setup ()  
{   
  pinMode (pinSignal, INPUT); // Set the signal pin as input   
  Serial.begin (9600); 
}  
   
void loop ()  
{  
  // Performs 128 signal readings   
  for ( int i = 0 ; i <num_Measure; i ++)  
  {  
    Sound_signal = analogRead (pinSignal);  
    dB = (Sound_signal+83.2073) / 11.003;
    sum = sum + dB;
    if(max_Level < dB)
    {
      max_Level = dB;
    }
    if (dB>50)
    {
      number_of_cars ++;
    }
  }  
 
  avg_Level = sum / num_Measure; // Calculate the average value  
  Serial.print("Id: ");
  Serial.print(id);    
  Serial.print("; ");
  Serial.print("AverageSoundLevel: ");
  Serial.print(avg_Level);  
  Serial.print("; ");
  Serial.print("MaximumSoundLevel: ");
  Serial.print(max_Level);   
  Serial.print("; ");
  Serial.print("NumberOfPassedCars: ");
  Serial.print(number_of_cars); 
  Serial.print("\n"); 
  sum = 0;
  max_Level = 0;
  id ++;
  delay(10000);
}
