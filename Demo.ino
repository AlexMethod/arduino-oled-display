
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "frames.h"
#include "sounds.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define nullState 0
#define state1 1
#define state2  2
#define state3  3
#define state4  4
#define state5  5
#define state6  6
#define state7  7
#define state8  8
#define state9  9

int inputPinB1 = 10;
int inputPinB2 = 9;
int inputPinB3 = 8;

int Button1 = 0;
int Button2 = 0;
int Button3 = 0;



int currentState = nullState;
bool isStateFinished = false;

void drawImage(const unsigned char image[] PROGMEM, float delaytime){
  display.clearDisplay();
  display.drawBitmap(0,0,image,SCREEN_WIDTH,SCREEN_HEIGHT,WHITE);
  display.display();
  delay(delaytime);
}

void setup() {

  Serial.begin(9600);
  Serial.println("SetUP");
  pinMode(inputPinB1, INPUT);
  pinMode(inputPinB2, INPUT);
  pinMode(inputPinB3, INPUT);

  void drawImage(const unsigned char image[] PROGMEM, float delaytime);

  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();

}

void controlState(){
  Serial.print("CURRENT STATE........................   ");
  Serial.println(currentState);
  
  if(currentState == nullState) currentState = state1;
  
  if(isStateFinished && Button1 == 1 && currentState == state1){
    currentState = state2;
    isStateFinished = false;
  }
  if(isStateFinished && currentState == state2) {
    currentState = state3;
    isStateFinished = false;
  }
  if(isStateFinished && currentState == state3) {
    currentState = state4;
    isStateFinished = false;
  }
  
  if(isStateFinished && Button1 == 1 && currentState == state4) {
    currentState = state9;
    isStateFinished = false;
  }
  
  if(isStateFinished && Button2 == 1 && currentState == state4) {
    currentState = state5;
    isStateFinished = false;
  }
  
  if(isStateFinished && currentState == state5) {
    currentState = state6;
    isStateFinished = false;
  }
  
  if(isStateFinished && Button2 == 1 && currentState == state6) { 
    currentState = state7;
    isStateFinished = false;
  }
  
  if(isStateFinished && currentState == state7) {
    currentState = state3;
    isStateFinished = false;
  }
  
  if(isStateFinished && Button3 == 1 && currentState == state4) {
    currentState = state8;
    isStateFinished = false;
  }
  
  if(isStateFinished && currentState == state8) {
    currentState = state3;
    isStateFinished = false;
  }

  if(isStateFinished && currentState == state9) {
    currentState = state1;
    isStateFinished = false;
    delay(2000);  
  }
  
}

void stateOne(){
  clearDisplay();
  Button1 = digitalRead(inputPinB1);
  Serial.println("STATE UNO");
}

void stateTwo(){
  showIntro();
  delay(2000);
  Serial.println("STATE DOS");
}

void stateThree(){
  showWelcome();
  delay(1000);
  Serial.println("STATE TRES");
}

void stateFour(){
  drawImage(Intro6,500);
  Button1 = digitalRead(inputPinB1);
  Button2 = digitalRead(inputPinB2);
  Button3 = digitalRead(inputPinB3);
  Serial.println("STATE CUATRO");
}

void stateFive(){
   //show dialog1
   cambioDialogo();
   drawImage(Intro4,500);
   delay(1000);
}

void stateSix(){
  Button2 = digitalRead(inputPinB2);
}

void stateSeven(){
  //Show dialog2
  cambioDialogo();
  drawImage(Intro5,500);
  delay(1000);
}

void stateEight(){
  //Show animation
  animacion();
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
   drawImage(Intro1,500);
  drawImage(Intro2,500);
  delay(3000);
}

void stateNine(){
  //Terminar programa
  clearDisplay();
}

void State(){

  switch(currentState){

    case nullState:
      break;
    case state1:
      stateOne();
      break;
    case state2:
      stateTwo();
      break;
    case state3:
      stateThree();
      break;
    case state4:
      stateFour();
      break;
    case state5:
      stateFive();
      break;
    case state6:
      stateSix();
      break;
    case state7:
      stateSeven();
      break;
    case state8:
      stateEight();
      break;
    case state9:
      stateNine();
      break;
    
  }

  isStateFinished = true;
}

void loop() {
  controlState();
  State();  
}

void clearDisplay(){
  display.clearDisplay();
  display.display();
}

void showIntro(){
  drawImage(Intro1,500);
  drawImage(Intro2,500);
  introSong();
  drawImage(Intro3,500);
  drawImage(Intro4,500);
  drawImage(Intro5,500);
  drawImage(Intro6,500);
  drawImage(Intro7,500);
  drawImage(Intro8,500);
  drawImage(Intro9,500);
}

void showWelcome(){
  drawImage(Intro1,500);
  drawImage(Intro2,500);
  drawImage(Intro3,500);
  drawImage(Intro4,500);
  drawImage(Intro5,500);
  drawImage(Intro6,500);
}
