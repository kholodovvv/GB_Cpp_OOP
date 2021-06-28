#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

/* ***************************************** Задание 1 *****************************************
 * Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
 * (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle 
 * (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
 * Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных 
 * классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
 * *********************************************************************************************/

class Figure{
public:
/* Figure(float height = 0, float width = 0): fheight(height), fwidth(width)
 { }*/
Figure()
{ }

virtual float area() = 0;

private:
float fheight, fwidth;
};

class Parallelogram: public Figure{
public:
 Parallelogram(float h = 0, float a = 0): ph(h), pa(a)
 { }

float area() override
{
//Площадь параллелограмма равна произведению его основания (a) на высоту(h).
//S = ah
  return pa * ph;
}
private:
float ph, pa;
};

class Circle: public Figure{
public:
 Circle(float radius = 0): cradius(radius)
 { }

float area() override
{
//Площадь круга равна произведению пи на радиус в квадрате.
//S = pR2
  return pi * pow(cradius, 2);
}

private:
float const pi = 3.1415;
float cradius;
};

class Rectangle : public Parallelogram
{
public:
 Rectangle(float height = 0, float width = 0): rheight(height), rwidth(width)
 { }

float area() override
{
//Площадь прямоугольника равна произведению его длины на его ширину.
//S = hw
  return rheight * rwidth;
}

private:
float rheight, rwidth;
};

class Square : public Parallelogram
{
public:
Square(float width = 0):swidth(width)
{ }

float area() override
{
//Площадь квадрата равна длине любой из его сторон в квадрате.
//S = w2
  return pow(swidth, 2);
}

private:
float swidth;
};

class Rhombus : public Parallelogram
{
public:
Rhombus(float diagonale1, float diagonale2): rdiagonale1(diagonale1), rdiagonale2(diagonale2)
{ }

float area() override
{
//Площадь ромба равна половине произведения его диагоналей.
//S = d1 + d2 / 2
  return (rdiagonale1 * rdiagonale2) / 2;
}

private:
float rdiagonale1, rdiagonale2;
};
//**********************************************************************************************

/* ***************************************** Задание 2 *****************************************
 * Создать класс Car (автомобиль) с полями company (компания) и model (модель).
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов  
 * наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они 
 * выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой 
 * последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
 * *********************************************************************************************/

class Car
{
public:
Car(std::string company = "", std::string model = ""): ccompany(company), cmodel(model)
{ 
  std::cout << "Car: " << "company: " << ccompany << ", model: " << cmodel << ";" << std::endl;
}


protected:
std::string ccompany, cmodel;
};

class PassengerCar: public Car
{
public:
PassengerCar(std::string company = "", std::string model = ""): Car(company, model), pcompany(company), pmodel(model)
{
  std::cout << "PassengerCar: " << "company: " << pcompany << ", model: " << pmodel << ";" << std::endl;
}

private:
std::string pcompany, pmodel;
};

class Bus: public Car
{
public:
Bus(std::string company = "", std::string model = ""): Car(company, model), bcompany(company), bmodel(model)
{
  std::cout << "Bus: " << "company: " << bcompany << ", model: " << bmodel << ";" << std::endl;
}

private:
std::string bcompany, bmodel;
};

class Minivan: public PassengerCar, public Bus
{
public:
Minivan(std::string company = "", std::string model = ""): PassengerCar(company, model), Bus(company, model), mcompany(company), mmodel(model)
{
  std::cout << "Minivan: " << "company: " << mcompany << ", model: " << mmodel << ";" << std::endl;
}

private:
std::string mcompany, mmodel;
};
//**********************************************************************************************

/* ***************************************** Задание 3 *****************************************
 * Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 
 * 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:  
 * ●	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями 
 * ●	унарный оператор (-)
 * ●	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
 * *********************************************************************************************/

class Fraction
{
public:
int fnumerator, fdenominator;

Fraction(int numerator = 0, int denominator = 1): fnumerator(numerator), fdenominator(denominator)
{ }

int getDenominator() const
{
  return fdenominator;
}

int getNumerator() const
{
  return fnumerator;
}
};

Fraction operator+ (const Fraction $f1, const Fraction $f2)
{
  Fraction $f3;
    $f3.fnumerator = $f1.getNumerator();
    $f3.fdenominator = $f1.getDenominator() + $f2.getDenominator();
  return $f3;
}

Fraction operator* (const Fraction $f1, const Fraction $f2)
{
  Fraction $f3;
    $f3.fnumerator = $f1.getNumerator() * $f2.getNumerator();
    $f3.fdenominator = $f1.getDenominator() * $f2.getDenominator();
  return $f3;
}

Fraction operator/ (const Fraction $f1, const Fraction $f2)
{
  Fraction $f3;
    $f3.fnumerator = $f1.getNumerator();
    $f3.fdenominator = $f1.getDenominator() * $f2.getNumerator();
  return $f3;
}

Fraction operator- (const Fraction $f1, const Fraction $f2)
{
  Fraction $f3;
    $f3.fnumerator = $f1.getNumerator() - $f2.getNumerator();
    $f3.fdenominator = $f1.getDenominator();
  return $f3;
}

Fraction operator- (const Fraction $f1)
{
  Fraction $f3;
    $f3.fnumerator = -$f1.getNumerator();
    $f3.fdenominator = $f1.getDenominator();
  return $f3;
}

bool operator== (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() == $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}

bool operator!= (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() != $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}

bool operator> (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() > $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}

bool operator< (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() < $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}

bool operator>= (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() > $f2.getNumerator() || $f1.getNumerator() == $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}

bool operator<= (const Fraction $f1, const Fraction $f2)
{
  if($f1.getNumerator() < $f2.getNumerator() || $f1.getNumerator() == $f2.getNumerator())
  {
    return true;
  }else{
    return false;
  }
}
//**********************************************************************************************

/* ***************************************** Задание 4 *****************************************
 * Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
 * поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля  
 * масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в  
 * этом классе должно быть два метода:
 * ●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее 
 * поворачивает лицом вверх, и наоборот.
 * ●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
 * 
 * *********************************************************************************************/
class Card{
public:
Card()
{ }

void Flip()
{
  if(this->position == true)
  {
    this->position = false;
  }else{
    this->position = true;
  }
}

unsigned getValue(char value)
{

 switch (value)
 {
 case 'J':
   return 2;
   break;
 
 case 'Q':
   return 3;
   break;

 case 'K':
   return 4;
   break;

 case 'A':
   return 1;
   break;

 default:
 return 0;
   break;
 } 

}

protected:
enum suit{peaks, worms, diamonds, cross};
enum valueCard {six = 6, seven = 7, eight = 8, nine = 9, ten = 10, J = 2, Q = 3, K = 4, A = 11};
bool position;
};

int main(const int argc, const char** argv){

//Task1
Parallelogram p(3, 8);
Figure *figure1 = &p;

Circle c(4);
Figure *figure2 = &c;

Rectangle r(6.5, 8.5);
Figure *figure3 = &r;

Square s(6);
Figure *figure4 = &s;

Rhombus rh(4, 2);
Figure *figure5 = &rh;

std::cout << "Area Parallelogram = " << figure1->area() << std::endl;
std::cout << "Area Circle = " << figure2->area() << std::endl;
std::cout << "Area Rectangle = " << figure3->area() << std::endl;
std::cout << "Area Square = " << figure4->area() << std::endl;
std::cout << "Area Rhombus = " << figure5->area() << std::endl;
std::cout << std:: endl;

//Task2
Car car_("Nissan", "Xtrail");
PassengerCar pc("Toyota", "Mark2");
Bus b("Nissan", "Legrand");
Minivan m("Toyota", "Alphard");
std::cout << std:: endl;

//Конструкторы выполняются в следующей последовательности:
//1. При обращении к объекту car_  - вызывается конструктор родительского класса Car
//2. При обращении к объекту pc  - вызывается конструктор родительского класса Car, после него конструктор класса PassengerCar
//3. При обращении к объекту b  - вызывается конструктор родительского класса Car, после него конструктор класса Bus
//4. При обращении к объекту m  - вызывается конструктор класса Minivan

//Task3
Fraction f1(1, 2); // 1/2
Fraction f2(1, 2);

Fraction summ = f1 + f2;
std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = " 
<< summ.getNumerator() << "/" << summ.getDenominator() << std::endl;

Fraction summa = f1 * f2;
std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = " 
<< summa.getNumerator() << "/" << summa.getDenominator() << std::endl;

Fraction sum = f1 / f2;
std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = " 
<< sum.getNumerator() << "/" << sum.getDenominator() << std::endl;

Fraction raznost = f1 - f2;
std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " 
<< raznost.getNumerator() << "/" << raznost.getDenominator() << std::endl;

Fraction minus = -f1 - f2;
std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " 
<< minus.getNumerator() << "/" << minus.getDenominator() << std::endl;

std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " == " << f2.getNumerator() << "/" << f2.getDenominator() << " : " 
<< (f1 == f2) << std::endl;

std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " != " << f2.getNumerator() << "/" << f2.getDenominator() << " : " 
<< (f1 != f2) << std::endl;
std::cout << std:: endl;

//Task4
Card car;
std::cout << "J = " << car.getValue('J') << ";" << std::endl;

return 0;
}