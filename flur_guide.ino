

int led_pin1 = 2;
int btn_pin1 = 3;

int led_pin2 = 4;
int btn_pin2 = 5;

int led_pin3 = 6;
int btn_pin3 = 7;

int led_pin4 = 8;
int btn_pin4 = 9;

int led_pin5 = 10;
int btn_pin5 = 11;

int counter = 0;
int active_led = 0;


void setup() {

  Serial.begin(9600);


  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);

  pinMode(btn_pin1, INPUT_PULLUP);
  pinMode(btn_pin2, INPUT_PULLUP);
  pinMode(btn_pin3, INPUT_PULLUP);
  pinMode(btn_pin4, INPUT_PULLUP);
  pinMode(btn_pin5, INPUT_PULLUP);

}

void loop() {


    bool btn_status1 = digitalRead(btn_pin1);
    bool btn_status2 = digitalRead(btn_pin2);
    bool btn_status3 = digitalRead(btn_pin3);
    bool btn_status4 = digitalRead(btn_pin4);
    bool btn_status5 = digitalRead(btn_pin5);

  //Detect button press, set the active led accordingly and reset the counter.
  if (btn_status1 == LOW){
    Serial.println("BTN1 pressed");
    active_led = 1;
    counter = 0;

  }

  if (btn_status2 == LOW){
    Serial.println("BTN2 pressed");
    active_led = 2;
    counter = 0;
  }

    if (btn_status3 == LOW){
    Serial.println("BTN3 pressed");
    active_led = 3;
    counter = 0;
  }

  if (btn_status4 == LOW){
    Serial.println("BTN4 pressed");
    active_led = 4;
    counter = 0;
  }

  if (btn_status5 == LOW){
    Serial.println("BTN5 pressed");
    active_led = 5;
    counter = 0;
  }

  //if the loop has run 1000 times, reset active led and counter.
  if(counter >= 1000){

    active_led = 0;
    counter = 0;


  }else if(counter < 1000 && active_led > 0){

    counter++;
  }

  //Turn on active led, turn off every other led.
  if(active_led == 0){
    digitalWrite (led_pin1, LOW);
    digitalWrite (led_pin2, LOW);
    digitalWrite (led_pin3, LOW);
    digitalWrite (led_pin4, LOW);
    digitalWrite (led_pin5, LOW);
  }
  else if(active_led == 1){
    digitalWrite (led_pin1, HIGH);
    digitalWrite (led_pin2, LOW);
    digitalWrite (led_pin3, LOW);
    digitalWrite (led_pin4, LOW);
    digitalWrite (led_pin5, LOW);
  }
  else if(active_led == 2){
    digitalWrite (led_pin1, LOW);
    digitalWrite (led_pin2, HIGH);
    digitalWrite (led_pin3, LOW);
    digitalWrite (led_pin4, LOW);
    digitalWrite (led_pin5, LOW);
  }
  else if(active_led == 3){
    digitalWrite (led_pin1, LOW);
    digitalWrite (led_pin2, LOW);
    digitalWrite (led_pin3, HIGH);
    digitalWrite (led_pin4, LOW);
    digitalWrite (led_pin5, LOW);
  }
  else if(active_led == 4){
    digitalWrite (led_pin1, LOW);
    digitalWrite (led_pin2, LOW);
    digitalWrite (led_pin3, LOW);
    digitalWrite (led_pin4, HIGH);
    digitalWrite (led_pin5, LOW);
  }
  else if(active_led == 5){
    digitalWrite (led_pin1, LOW);
    digitalWrite (led_pin2, LOW);
    digitalWrite (led_pin3, LOW);
    digitalWrite (led_pin4, LOW);
    digitalWrite (led_pin5, HIGH);
  }

  
  Serial.println(counter);
  
  
}
