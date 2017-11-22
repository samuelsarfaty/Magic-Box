#include<Servo.h>

boolean restarted = false;
boolean hasWon = false;

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

//Display setup
int D1 = 15;
int D2 = 16;

int pA = 8;
int pB = 9;
int pC = 10;
int pD = 11;
int pE = 12;
int pF = 13;
int pG = 14;


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

  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);
  pinMode(pE, OUTPUT);
  pinMode(pF, OUTPUT);
  pinMode(pG, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);

  myServo.attach(17);
  //myServo.write(close);

  Serial.begin(9600);

  randomSeed(analogRead(5));

  Restart();

  Serial.println("Welcome to mastermind!");
  Serial.println("guess the right sequence of 4 buttons");
  Serial.println("the numbers don't repeat");

  //GenerateSolution();
}

void loop() {

    while (guessNumber < guessSize){
      CheckForInput();
      //Serial.println("checking...");
    }
  if(!checked){
    CheckGuess();
    checked = true;
    if (greens >= 4){ //Winning condition

      Serial.println("you guessed right!");
      myServo.write(open);
      hasWon = true;

      //Show the numbers for some time
      ShowLights(8000);
      //checked = false;

    }
    else {
      ShowLights(8000);
      //delay(8000);
      guessNumber = 0;
      Serial.println("try again");
      checked = false;
    }
  }

  if (hasWon == true){
    if (digitalRead(button_2) == LOW && digitalRead(button_7) == LOW){
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
}

void KillLights(){

  for (int i = pA; i <= pG; i++){
    digitalWrite(i, HIGH);
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

void ShowLights(int delay){
  long startTime = millis();
  long endTime = startTime;

  while ((endTime - startTime) <= delay){
    lightGreens(greens);
    lightYellows(yellows);
    endTime = millis();
  }
  KillLights();

}

void lightGreens(int greens){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);

  switch(greens){
    case 0:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, LOW);
      digitalWrite(pG, HIGH);
      break;
    case 1:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;
    case 2:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, LOW);
      break;
    case 3:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, LOW);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, LOW);
      break;
    case 4:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, LOW);
      digitalWrite(pG, LOW);
      break;
  }
  delay(10);

}

void lightYellows(int yellows){
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);

  switch(yellows){
    case 0:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, LOW);
      digitalWrite(pG, HIGH);
      break;
    case 1:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, HIGH);
      break;
    case 2:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, HIGH);
      digitalWrite(pD, LOW);
      digitalWrite(pE, LOW);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, LOW);
      break;
    case 3:
      digitalWrite(pA, LOW);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, LOW);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, HIGH);
      digitalWrite(pG, LOW);
      break;
    case 4:
      digitalWrite(pA, HIGH);
      digitalWrite(pB, LOW);
      digitalWrite(pC, LOW);
      digitalWrite(pD, HIGH);
      digitalWrite(pE, HIGH);
      digitalWrite(pF, LOW);
      digitalWrite(pG, LOW);
      break;
  }
  delay(10);
}
