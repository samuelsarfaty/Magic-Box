#include<Servo.h>

boolean restarted = false;
boolean hasWon = false;

//Number Display


//Servo variables
Servo myServo;
int close = 0;
int open = 90;

//Combination variables
int numbers[] = {2,3,4,5,6,7};
const int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
int solution[4];
const int solutionSize = sizeof(solution) / sizeof(solution[0]);
int guess[4];
const int guessSize = sizeof(guess) / sizeof(guess[0]);

int guessNumber = 0;

//Buttons setup
const int button_2 = 2;
int buttonState_2 = 0;
int lastButtonState_2 = 0;

const int button_3 = 3;
int buttonState_3 = 0;
int lastButtonState_3 = 0;

const int button_4 = 4;
int buttonState_4 = 0;
int lastButtonState_4 = 0;

const int button_5 = 5;
int buttonState_5 = 0;
int lastButtonState_5 = 0;

const int button_6 = 6;
int buttonState_6 = 0;
int lastButtonState_6 = 0;

const int button_7 = 7;
int buttonState_7 = 0;
int lastButtonState_7 = 0;

//Lights setup
const int greenLed_1 = 8;
const int greenLed_2 = 9;
const int greenLed_3 = 10;
const int greenLed_4 = 11;

const int yellowLed_1 = 12;
const int yellowLed_2 = 13;
const int yellowLed_3 = 14;
const int yellowLed_4 = 15;


int greens = 0;
int yellows = 0;

boolean checked = false;

void setup() {

  pinMode(button_2, INPUT);
  digitalWrite(button_2, HIGH);

  pinMode(button_3, INPUT);
  digitalWrite(button_3, HIGH);

  pinMode(button_4, INPUT);
  digitalWrite(button_4, HIGH);

  pinMode(button_5, INPUT);
  digitalWrite(button_5, HIGH);

  pinMode(button_6, INPUT);
  digitalWrite(button_6, HIGH);

  pinMode(button_7, INPUT);
  digitalWrite(button_7, HIGH);

  pinMode(greenLed_1, OUTPUT);
  pinMode(greenLed_2, OUTPUT);
  pinMode(greenLed_3, OUTPUT);
  pinMode(greenLed_4, OUTPUT);

  pinMode(yellowLed_1, OUTPUT);
  pinMode(yellowLed_2, OUTPUT);
  pinMode(yellowLed_3, OUTPUT);
  pinMode(yellowLed_4, OUTPUT);

  myServo.attach(16);
  //myServo.write(close);

  Serial.begin(9600);

  randomSeed(analogRead(5));

  //Shuffle();
  //GenerateSolution();

  Restart();



  /*
  Printing lines to check if the shuffling and solution generation work
  Serial.println(numbers[0]);
  Serial.println(numbers[1]);
  Serial.println(numbers[2]);
  Serial.println(numbers[3]);
  Serial.println(numbers[4]);
  Serial.println(numbers[5]); */





  Serial.println("Welcome to mastermind!");
  Serial.println("guess the right sequence of 4 buttons");
  Serial.println("the numbers don't repeat");

  //GenerateSolution();
}

void loop() {
/*digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
digitalWrite(14, HIGH);
digitalWrite(15, HIGH);*/

    while (guessNumber < guessSize){
      CheckForInput();
      //Serial.println("checking...");
    }
  if(!checked){
    CheckGuess();
    checked = true;
    if (greens >= 4){ //Winning condition
      //restarted = false;
      Serial.println("you guessed right!");
      myServo.write(open);
      hasWon = true;
      //checked = false;

    }
    else {
      delay(8000);
      KillLights();
      guessNumber = 0;
      Serial.println("try again");
      checked = false;
    }
  }

  if (hasWon == true){
    if (digitalRead(button_2) == HIGH && digitalRead(button_7) == HIGH){
    delay(2000);
    Restart();
    hasWon = false;
    checked = false;
    }
  }
}


void Shuffle(){ //Shuffles the elements of numbers[]
  for (int i=0; i < numbersSize; i++) {
   int n = random(0, numbersSize);
   int temp = numbers[n];
   numbers[n] =  numbers[i];
   numbers[i] = temp;
 }
}

void GenerateSolution(){ //Picks the first 4 elements of numbers[] after shuffling
  for (int i = 0; i < solutionSize; i++){
    solution[i] = numbers[i];
  }

  Serial.println(solution[0]);
  Serial.println(solution[1]);
  Serial.println(solution[2]);
  Serial.println(solution[3]);
}

void CheckForInput(){

  buttonState_2 = digitalRead(button_2);
  if (buttonState_2 != lastButtonState_2){
    if(buttonState_2 == LOW){
      guess[guessNumber] = button_2; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_2 = buttonState_2;

  buttonState_3 = digitalRead(button_3);
  if (buttonState_3 != lastButtonState_3){
    if(buttonState_3 == LOW){
      guess[guessNumber] = button_3; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_3 = buttonState_3;

  buttonState_4 = digitalRead(button_4);
  if (buttonState_4 != lastButtonState_4){
    if(buttonState_4 == LOW){
      guess[guessNumber] = button_4; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_4 = buttonState_4;

  buttonState_5 = digitalRead(button_5);
  if (buttonState_5 != lastButtonState_5){
    if(buttonState_5 == LOW){
      guess[guessNumber] = button_5; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_5 = buttonState_5;

  buttonState_6 = digitalRead(button_6);
  if (buttonState_6 != lastButtonState_6){
    if(buttonState_6 == LOW){
      guess[guessNumber] = button_6; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_6 = buttonState_6;

  buttonState_7 = digitalRead(button_7);
  if (buttonState_7 != lastButtonState_7){
    if(buttonState_7 == LOW){
      guess[guessNumber] = button_7; //guess element in position guess number becomes number of button pressed
      Serial.print(guess[guessNumber]);
      guessNumber++;
      delay(50);
      //Serial.println(guessNumber);

    }
  }
  lastButtonState_7 = buttonState_7;

}

void CheckGuess(){
  greens = 0;
  yellows = 0;

  for (int solNum = 0; solNum < solutionSize; solNum++){
    for (int guessNum = 0; guessNum < guessSize; guessNum++){
      if(guess[guessNum] == solution[solNum]){
        if (solNum == guessNum){
          greens++;
        } else {
          yellows++;
        }
      }
    }
  }

  /*Serial.println("");
  Serial.print("Greens:" );
  Serial.println (greens);
  Serial.print("Yellows:" );
  Serial.println (yellows);*/

  for (int i = greenLed_1; i < greenLed_1 + greens; i++){
    Serial.print("green led in pin: ");
    Serial.print(i);
    Serial.println(" is on");

    digitalWrite(i, HIGH);

  }

  for (int i = yellowLed_1; i < yellowLed_1 + yellows; i++){
    Serial.print("yellow led in pin: ");
    Serial.print(i);
    Serial.println(" is on");

    digitalWrite(i, HIGH);

  }

}

void KillLights(){
  for (int i = greenLed_1; i <= yellowLed_4; i++){
    digitalWrite(i, LOW);
  }
}

void Restart(){
  guessNumber = 0;
  Shuffle();
  GenerateSolution();
  KillLights();
  myServo.write(close);

  //restarted = true;
}
