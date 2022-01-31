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
void task2() { debug("task2"); }
void task3() { debug("task 3"); }
//-----func-----//

//-----init-----//
#include"Timer.h"
void(*funcArray[])(void) = {  task2, task3 }; //массив функций
uint16_t delayArray[] = {  500, 1000 };           //массив периодов

//функция millis/micros, массив функций, массив периодов, длина массива
Timer timer(millis, funcArray, delayArray, sizeof(funcArray) / sizeof(funcArray[0]));
//-----init-----//


void setup() {
#if debugMode == 1
    Serial.begin(9600);
#endif
}

void loop() {
    timer.tick();
}
