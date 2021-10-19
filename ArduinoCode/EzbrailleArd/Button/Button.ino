
int Pin_prev = 2;   //Pin for prev button
//int Pin_next = 1; //Pin for next button
//int Pin_toggle = 7;   // choose the input pin (for a pushbutton)
//int Toggle_value = 0;
//int Next_value = 0;
int Prev_value = 0;


boolean Auto_Read = true; // if true we auto read

void setup() {
  Serial.begin(9600);
  pinMode(Pin_prev, INPUT);    // declare pushbutton as input
//pinMode(Pin_next, INPUT);    // declare pushbutton as input
//pinMode(Pin_toggle, INPUT);    // declare pushbutton as input
  Serial.println("It runs");
}

void loop(){


    //

    //MOTOR MOVEMENT

    //

    int Toggle_value = 0;
    int Next_value = 0;
    Prev_value = 0;

    //BUTTON Loop
    while(true){
        //Toggle_value = digitalRead(Pin_toggle);  // read toggle button input
        //Next_value = digitalRead(Pin_next);  // read next button input
        Prev_value = digitalRead(Pin_prev); // read prev button input
        if (Toggle_value == HIGH) {         // check if the input is HIGH (button released)
            //TOGGLE FILE
            Serial.println("toggle");
            break; //break out of loop
        } else if (Next_value == HIGH){
            //read_next
            Serial.println("nextbutton");
            break;
        } else if (Prev_value == HIGH){
            //read_prev_line
            Serial.println("prevbutton");
            break;
        }

    }

    delay(250);

  
}
