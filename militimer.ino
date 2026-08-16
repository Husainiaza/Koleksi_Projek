const int PB_1 = 2; // Button1
const int RLY_1 = 7; //relay 1
const int PB_2 = 3; // Button2
const int RLY_2 = 8; //relay 2


//VARIABLES
int buttonState1 = 0; 
    // current state of the button
bool relay1 = false;
int buttonState2 = 0; 
    // current state of the button
bool relay2 = false;

//MILLIS
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
const unsigned long interval1 = 5000;
const unsigned long interval2 = 8000;




void setup()
{
  pinMode(PB_1, INPUT);
  digitalWrite(PB_1, HIGH); // pull-up
  pinMode(PB_2, INPUT);
  digitalWrite(PB_2, HIGH); // pull-up
  pinMode(RLY_1, OUTPUT);
  digitalWrite(RLY_1, LOW);
  pinMode(RLY_2, OUTPUT);
  digitalWrite(RLY_2, LOW);
  Serial.begin(9600);
 }


void loop(){

    // read the pushbutton input pin:
    buttonState1 = digitalRead(PB_1);
    buttonState2 = digitalRead(PB_2);
    unsigned long currentMillis = millis();

    // if button is pressed, turn relay on (if it wasn't already on), and reset the timer
    if( buttonState1==HIGH ) // no need to check for previous state, in this specific case
    {
        previousMillis1 = currentMillis;
        digitalWrite(RLY_1, HIGH);
        
        relay1 = true;
    }

     if( relay1 )
    {
        // turn red led on, if close to turning off the relay
        
        // if enough time has elapsed, turn of the relay
        if (currentMillis - previousMillis1 >= interval1) 
        {
            // .. turn of relay
            digitalWrite(RLY_1, LOW);
            relay1 = false;
        }
    } 

if( buttonState2==HIGH ) // no need to check for previous state, in this specific case
    {
        previousMillis2 = currentMillis;
        digitalWrite(RLY_2, HIGH);
        
        relay2 = true;
    }

     if( relay2 )
    {
        // turn red led on, if close to turning off the relay
        
        // if enough time has elapsed, turn of the relay
        if (currentMillis - previousMillis2 >= interval2) 
        {
            // .. turn of relay
            digitalWrite(RLY_2, LOW);
            relay2 = false;
        }
    }
   
    } 
