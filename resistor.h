#ifndef RESISTOR_H
#define RESISTOR_H


class resistor
{
public:
    resistor();
    ~resistor();
    resistor(double res, unsigned int n = 0);
    resistor(const resistor &parent);
    bool setResistance(double resistance);
    double getResistance() const;
    unsigned int getNum() const;
    void setNum(unsigned int data);
    bool operator == (resistor const & another);
    bool operator != (resistor const & another);
protected:
    double resistance;
private:
    unsigned int num;
};

#endif // RESISTOR_H
