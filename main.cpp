#include <iostream>
#include <string>
#include <cassert>
#include <resistor.h>
using namespace std;

void userinput(){
    string answer;
    do {
        cout << "Add another node?";
        cin >> answer;
    } while (answer == "yes");
}

int main()
{
    //Тестирование конструктора
    auto test = new resistor();
    assert(test->getResistance() == 0);     //Float point to zero, huh
    assert(test->getNum() == 0);
    delete test;
    test = new resistor(4.33,1);
    assert(test->getNum() == 1);
    assert(test->getResistance() == 4.33);
    //Тестирование конструктора копирования
    auto copy = new resistor(*test);
    assert(copy->getNum() == 1);
    assert(copy->getResistance() == 4.33);
    //Тестирование методов сравнения
    assert(*copy == *test);
    copy->setNum(4);
    assert(*copy != *test);
    delete test;
    delete copy;
    test = new resistor(-4);
    assert( test->getNum() == 0 );
    assert( test->getResistance() == 0);
    //Тестирование методов доступа
    test->setNum(10);
    assert(test->getNum() == 10);
    assert(test->setResistance(20) == true);
    assert(test->getResistance() == 20);
    assert(test->setResistance(-5) == false);
    assert(test->getResistance() == 20);
    delete test;
    cout << "Success!";
}
