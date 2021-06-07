const int plusPin_B = 8;
const int minusPin_B = 9;

const int plusPin_A = 6;
const int minusPin_A = 7;


bool bFlag = true;


void setup() 
{
  // put your setup code here, to run once:

  pinMode(plusPin_A, OUTPUT);
  pinMode(minusPin_A, OUTPUT);

  pinMode(plusPin_B, OUTPUT);
  pinMode(minusPin_B, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:

  if(bFlag == true)
  {
    left_A();
    delay(1000);
    left_B();
    delay(1000);      

    bFlag = false;
  }
  else
  {
    right_A();
    delay(1000);
    right_B();
    delay(1000);
    
    bFlag = true;

  }
}

void left_A()
{
  digitalWrite(plusPin_A, HIGH);
  digitalWrite(minusPin_A, LOW);
}

void right_A()
{
  digitalWrite(plusPin_A, LOW);
  digitalWrite(minusPin_A, HIGH);
}

void left_B()
{
  digitalWrite(plusPin_B, HIGH);
  digitalWrite(minusPin_B, LOW);  
}

void right_B()
{
  digitalWrite(plusPin_B, LOW);
  digitalWrite(minusPin_B, HIGH);  
}
