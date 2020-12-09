int buzzer = 11;
int pitch = 0;

#define A 3900 + pitch
#define B 5400 + pitch
#define C 5200 + pitch
#define D 4100 + pitch
#define E 4200 + pitch
#define Tono1 2700
#define Tono2 3000
#define Tono3 3500
#define Tono4 4000
#define Tono5 4500
#define X  5000
#define Y 4500
#define Z 3500
#define T1 222
#define T2 89 
#define T3 111
#define T4 70
#define T5 40

void introSong(){
  tone(buzzer,A,T1);
  delay(T1);
  tone(buzzer,B,T2);
  delay(T2);
  tone(buzzer,A,T1);
  delay(T1);
  tone(buzzer,B,T2);
  delay(T2);
  tone(buzzer,C,T2);
  delay(T2);
  tone(buzzer,A,T1);
  delay(T1);
  tone(buzzer,D,T2);
  delay(T2);
  delay(T3);
  tone(buzzer,E,T2);
  delay(T2);
  tone(buzzer,D,T2);
  delay(T2);
  delay(T3);
  tone(buzzer,E,T2);
  delay(T2);
  tone(buzzer,D,T2);
  delay(T2);
  tone(buzzer,A,T1);
  delay(T1);
  delay(T3);
}

void cambioDialogo(){
  tone(buzzer,Tono1,T4);
  delay(T4);
  tone(buzzer,Tono2,T4);
  delay(T4);
  tone(buzzer,Tono3,T4);
  delay(T4);
  tone(buzzer,Tono4,T4);
  delay(T4);
  tone(buzzer,Tono5,T4);
  delay(T4);
}

void animacion(){
  tone(buzzer,X,T5);
  delay(T5);
  tone(buzzer,Y,T5);
  delay(T5);
  tone(buzzer,Z,T1);
  delay(T1);
}
