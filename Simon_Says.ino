/*
 Simon Says
 Simple Simon says clone I made for the arduino uno platform.
 */

int pinBlue = 11;
int pinGreen = 10;
int pinYellow = 9;
int pinRed = 8;
int right = 7;
int up = 6;
int left = 5;
int down = 4;
int sayLength[15];
int playLength[15];
int pos = 0;

bool play = 0;
bool wait = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinRed, OUTPUT);
  pinMode(right, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  // Bit used for creation of the random number sequence to be used for the lighting of leds and game logic.
  
  for(int i=0; i<15; i = i+=1)
  {
    randomSeed(analogRead(0));
    sayLength[i] = random(4);
  }
  // Get confirmation to play
  if(digitalRead(down) == LOW)
  {
    play = 1;
  }
  
  while(play)
  {
    // Play the led sequence in the part of the loop the game is at
    for(int i=0; i <= pos; i+=1)
    {
      switch(sayLength[i]){
        case 0:
          digitalWrite(pinBlue, HIGH);
          delay(1000);
          digitalWrite(pinBlue, LOW);
          delay(500);
          break;
        case 1:
          digitalWrite(pinGreen, HIGH);
          delay(1000);
          digitalWrite(pinGreen, LOW);
          delay(500);
          break;
        case 2:
          digitalWrite(pinRed, HIGH);
          delay(1000);
          digitalWrite(pinRed,LOW);
          delay(500);
          break;
        case 3:
          digitalWrite(pinYellow, HIGH);
          delay(1000);
          digitalWrite(pinYellow, LOW);
          delay(500);
          break;
        play = 0;
      }
    }
    // Set the boolean to wait for inputs
    wait = 1;
    // Run the loop that looks for inputs
    while(wait)
    {
      if(digitalRead(down) == LOW && digitalRead(left) == LOW)
      {
        wait = 0;
        delay(2000);
      }
      
    }
  }
}

/*void inputconv()
{
  for
    if(digitalRead(up) == LOW)
    {
      playLength[in] = 0
    }
}*/

