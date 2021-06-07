const int plusPin = 8;
const int minusPin = 9;

bool bFlag = true;

void setup() 
{
//  Serial.begin(9600);
 
  pinMode(plusPin, OUTPUT);
  pinMode(minusPin, OUTPUT);

}

void loop() 
{
  int frequency = 500;                                  // Hz
  long period_us = (long)(1.0f / frequency * 1000000);  // us

  float operating_cycle_time = 3.0f;                    // sec

  long iter = (long)(operating_cycle_time * 1000000.0f / period_us);

//  Serial.println(iter);

  float on_percent;
  
  for(int i=0; i<iter; i++)
  {
    on_percent = (float)i / iter;
        
    duty_on();
    delayMicroseconds((int)(period_us * on_percent));

    duty_off();
    delayMicroseconds((int)(period_us * (1-on_percent)));
  }

  for(int i=iter; i>0; i--)
  {
    on_percent = (float)i / iter;

    duty_on();
    delayMicroseconds((int)(period_us * on_percent));

    duty_off();
    delayMicroseconds((int)(period_us * (1-on_percent)));
  }  
}

void duty_on()
{
  digitalWrite(plusPin, HIGH);
  digitalWrite(minusPin, LOW);
}

void duty_off()
{
  digitalWrite(plusPin, LOW);
  digitalWrite(minusPin, HIGH);
}
