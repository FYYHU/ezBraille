
int Pin_prev = 2;   //Pin for prev button
int Pin_next = 1; //Pin for next button
int Pin_toggle = 7;   // choose the input pin (for a pushbutton)

void setup() {
  pinMode(inPin, INPUT);    // declare pushbutton as input
}

void loop(){


    //

    //MOTOR MOVEMENT

    //


    int Toggle_value = 0;
    int Next_value = 0;
    int Prev_value = 0;
    //BUTTON Loop
    While(True){
        Toggle_value = digitalRead(Pin_toggle);  // read toggle button input
        Next_value = digitalRead(Pin_next);  // read next button input
        Prev_value = digitalRead(Pin_prev); // read prev button input
        if (Toggle_value == HIGH) {         // check if the input is HIGH (button released)
            //TOGGLE FILE
            break; //break out of loop
        } else if (Next_value == HIGH){
            //read_next
            break;
        } else if (Prev_value == HIGH){
            //read_prev_line
            break;
        }

    }

  
}