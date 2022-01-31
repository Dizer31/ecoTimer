#pragma once

class Timer {
public:
    Timer(unsigned long(*mil)(), void(*func[])(void), uint16_t* delay, uint8_t length) {
        _mainFunc = mil;
        _funcArray = func;
        _delayArray = delay;
        _length = length;
        _mainFlag = (_mainFunc == millis ? 1 : 0);
    }

    void tick() {   //нужно засутунь в loop()
        if (_mainFunc() - _tmr >= (_mainFlag ? 1 : 1000)) {
            _tmr = _mainFunc();
            _counter++;
            for (uint8_t i = 0; i < _length; i++) {
                if (_counter % _delayArray[i] == 0) _funcArray[i]();
            }
        }
    }
private:
    bool _funcFlag;
    bool _mainFlag;
    uint32_t _counter;
    uint16_t _length;

    uint32_t _tmr;
    unsigned long(*_mainFunc)();
    void (**_funcArray)(void);
    uint16_t* _delayArray;
};
