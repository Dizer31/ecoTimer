//-----settings-----//
#define debugMode 1

//-----define-----//
#if debugMode == 1
#define debug(x) Serial.println(x)
#else
#define debug(x)
#endif
//-----settings-----//

//-----func-----//
//сами функции
void task1() { debug("task1"); }
void task2() { debug("task 2"); }
void task3() { debug("task  3"); }
//-----func-----//

//-----init-----//
#include"Timer.h"
void(*funcArray[])(void) = { task2, task3 }; //массив функций
uint16_t delayArray[] = { 500, 500 };           //массив периодов

//функция millis/micros, массив функций, массив периодов, длина массива
Timer timer(millis, funcArray, delayArray, sizeof(funcArray) / sizeof(funcArray[0]));
//Timer timer1(millis, task1, 1000);
//-----init-----//

void setup() {
#if debugMode == 1
  Serial.begin(9600);
#endif
}

void loop() {
  timer.tick();
  if (Serial.available() > 0) {
    char x = Serial.read();
    debug("q");
    timer.add(1);
    timer.addNext(0);
    //timer.removeIgnore(1);
  }
}
