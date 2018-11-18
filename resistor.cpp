#include "resistor.h"

resistor::resistor()
{
    resistance = 0; // По умолчанию мы - проводник
    num = 0;  //По умолчанию мы без номера. И непонятно зачем этот номер нужен.
}

resistor::resistor(double res, unsigned int n){
    resistance = 0; //for the case resitance is invalid
    setResistance(res);
    num = n;
}

resistor::resistor(const resistor &parent){
    num = parent.getNum();
    resistance = 0;
    setResistance(parent.getResistance());
}

bool resistor::setResistance(double data){
    bool isOk = (data >= 0);    //Resistance cannot be negative
    if (isOk){
            resistance = data;
    };
    return isOk;
}

double resistor::getResistance() const{
    return resistance;
}

void resistor::setNum(unsigned int data){
    num = data;
}

unsigned int resistor::getNum() const{
    return num;
}

bool resistor::operator == (resistor const & another)
{
    return ( another.getNum() == getNum() ) && ( another.getResistance() == getResistance() );
}

bool resistor::operator != (resistor const & another)
{
    return !(this->operator==(another));
}

resistor::~resistor() = default;
