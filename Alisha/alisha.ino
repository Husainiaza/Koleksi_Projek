int button1 = 16;
int button2 = 17;
int buzzer = 2;

//- istihar pembolehubah data dari sensor
int dataButton1;
int dataButton2;

bool relay1 = false;

unsigned long previousMillis1 = 0;
const unsigned long interval1 = 5000;

void setup() {
 
  pinMode(button1, INPUT);  //-- button
  pinMode(button2, INPUT);

  pinMode(buzzer, OUTPUT); //--  buzzer

//-- istihar fungsi komunikasi Serial.
  Serial.begin(115200);
  
}

void loop(){
 unsigned long currentMillis = millis();
 dataButton2 = digitalRead(button2);
 Serial.print(" bacaan dar dataButton2 : ");
 Serial.println(dataButton2);

  dataButton1 = digitalRead(button1);
  Serial.print(" bacaan dar dataButton1 : ");
 Serial.println(dataButton1);

 if(dataButton1 == 1)
  // no need to check for previous state, in this specific case
    {
        previousMillis1 = currentMillis;
        relay1 = true;
    }

    if( relay1 )
    {
    if (currentMillis - previousMillis1 >= interval1) 
        {
          relay1 = false;
          Serial.print(" ba5 minit : ");
          digitalWrite(buzzer,HIGH);
        }
    } 

    if(dataButton2 == 1){
    digitalWrite(buzzer,LOW);
    }

 //delay(1000);


}
