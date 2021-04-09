// constants won't change. They're used here to set pin numbers:
const int irSwitch = 12;     // the number of the pushbutton pin
const int limitSwitchTop = 8;     // the number of the pushbutton pin
const int limitSwitchBottom = 7;     // the number of the pushbutton pin
const int motorPin =  4;      // the number of the LED pin
const int motorPin2 =  5;      // the number of the LED pin
int enA = 6;

// variables will change:
boolean buttonState = 0;        // variable for reading the pushbutton status
boolean buttonState2 = 0;       // variable for reading the pushbutton status
boolean buttonState3 = 0;       // variable for reading the pushbutton status
bool initial_state_of_lift = 0 ; //this is the very initail state of 
                                // lift. flase for inital state is down
                                // true if initail state is up.
/**
    setup inputs for switches and outs for motor pins
    serial begin to read the switches to test for errors
*/
void setup() {
  // initialize the pin as an inputs:
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(irSwitch, INPUT);
  pinMode(limitSwitchTop, INPUT);
  pinMode(limitSwitchBottom, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
/*  buttonState = digitalRead(irSwitch);
  buttonState2 = digitalRead(limitSwitchTop);
  buttonState3 = digitalRead(limitSwitchBottom);

  while (buttonState == LOW)
    {Serial.println("Triggered lift up");
  liftUp();
  delay(100);}
  if (buttonState2 == HIGH)
  {
    liftStop();
    Serial.println("lift stop");
  }
  while (buttonState == HIGH)
    {delay(100);
  liftDown();
  delay(100);}
  Serial.println("lift down");
  if (buttonState3 == HIGH)
  {
    liftStop();
    Serial.println("lift stop");

  }
  */

  if  (!initial_state_of_lift)  // if the lift is down then these 
       {                         // action has to be taken
        ir_read_false();
        ir_read_true();
        
        while  (!digitalRead (limitSwitchTop)){
          delay (100);
          liftUp();
        }
        liftStop();
        initial_state_of_lift = true; // the lift is now reached
                                      // on top. so now we have to quit from this case
       }
  else{
        ir_read_false();
        ir_read_true();
        
        while  (!digitalRead (limitSwitchBottom)){
          delay (100);
          liftDown();
        }
        liftStop();
        initial_state_of_lift = false; // the lift is now reached
                           
       }
}


  void liftUp() {
    // turn motor foward:
    digitalWrite(motorPin, LOW);
    digitalWrite(motorPin2, HIGH);
    analogWrite(enA, 200);
  }

  void liftDown() {
    // turn motor in other direction:
    digitalWrite(motorPin, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(enA, 200);
  }

  void liftStop() {
    // stop motor:
    digitalWrite(motorPin, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(enA, 0);
  }

void ir_read_true (){
    while (true){           // this is safity loop of ir switch
          int temp_counter = 0;
          if (!digitalRead (irSwitch)){
            temp_counter++;
            //delay (100);
            if (temp_counter >= 5);{  // change the value if you want to check ir value for more the 0.5 sec
              break;
            }
          }
          else
            temp_counter = 0;
          delay (100);
        }
  }

 void ir_read_false (){
     while (true){           // this is safity loop of ir switch
          int temp_counter = 0;
          if (digitalRead (irSwitch)){
            temp_counter++;
            //delay (100);
            if (temp_counter >= 5);{  // change the value if you want to check ir value for more the 0.5 sec
              break;
            }
          }
          else
            temp_counter = 0;
          delay (100);
        }
  }
