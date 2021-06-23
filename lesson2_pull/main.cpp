#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

/* ***************************************** Задание 1 *****************************************
 * Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы
 * переназначения имени, изменения возраста и веса. Создать производный класс Student 
 * (студент), имеющий поле года обучения. Определить методы переназначения и увеличения
 * этого значения. Создать счетчик количества созданных студентов. В функции main() создать 
 * несколько студентов. По запросу вывести определенного человека.
 * *********************************************************************************************/

class Person{
protected:
char p_name[25];
unsigned p_age;
char p_gender[6];
unsigned p_weight;

public:
Person(unsigned age = 0, unsigned weight = 0)
:p_age(age), p_weight(weight)
{ }

void setName(char *name){

 strcpy(p_name, name);
}

void setAge(){
  std :: cout << "ENTER AGE: ";
  std :: cin >> p_age;
}

void setGender(char *gender){

  strcpy(p_gender, gender);
}

void setWeight(){
  std :: cout << "ENTER WEIGHT: ";
  std :: cin >> p_weight;
}

};

class Student : public Person
{
private:
unsigned yearStudy;

public:
Student(unsigned studyYear = 0) : yearStudy(studyYear)
{ }

void setYearStudy()
{
  std :: cout << "ENTER YEAR STUDY: ";
  std :: cin >> yearStudy;
}

void print()
{
  std :: cout << std::endl;
  std :: cout << "NAME: " << p_name << std :: endl;
  std :: cout << "AGE: " << p_age << std :: endl;
  std :: cout << "GENDER: " << p_gender << std :: endl;
  std :: cout << "WEIGHT: " << p_weight << std :: endl;
  std :: cout << "YEAR STUDY: " << yearStudy << std :: endl;
}

};

std::vector <Student> student;
int counter = 0;

int program_menu(){

int sel = 0, m_sel = 0;
char sname[25], sgender[6];

do{
std :: cout << std::endl;
std :: cout << "ENTER 1 TO CREATE A NEW STUDENT;" << std :: endl;
std :: cout << "ENTER 2 TO CHANGE THE STUDENT DATA;" << std :: endl;
std :: cout << "ENTER 3 TO DISPLAY THE STUDENT DATA;" << std :: endl;
std :: cout << "ENTER 4 TO EXIT THE PROGRAM." << std :: endl;
std :: cout << "ENTER: ";
std :: cin >> sel;
}while(sel < 0 & sel > 4);

switch (sel)
{
case 1:
  student.resize(++counter);

std :: cout << std::endl;
std :: cout << "ENTER NAME:";
std :: cin >> sname;

  student[counter - 1].setName(sname);
  student[counter - 1].setAge();

std :: cout << "ENTER GENDER (Male Or Female): ";
std :: cin >> sgender;

  student[counter - 1].setGender(sgender);
  student[counter - 1].setWeight();
  student[counter - 1].setYearStudy();

  std :: cout << std::endl; 
  std :: cout << "STUDENT WITH A SERIAL NUMBER " << counter << " CREATED." << std :: endl;
  break;

case 2:
do{
  std :: cout << std::endl;
  std :: cout << "ENTER THE STUDENT'S SERIAL NUMBER" << std :: endl;
  std :: cout << "ENTER: ";
  std :: cin >> sel;
}while(sel < 1 & sel > counter);

do{
  std :: cout << std::endl;
  std :: cout << "1 - CHANGE THE NAME;" << std :: endl;
  std :: cout << "2 - CHANGE THE AGE;" << std :: endl;
  std :: cout << "3 - CHANGE THE WEIGHT;" << std :: endl;
  std :: cout << "ENTER: ";
  std :: cin >> m_sel;
}while(m_sel < 1 & m_sel > 3);

switch (m_sel)
{
case 1:
std :: cout << std::endl;
std :: cout << "ENTER NEW NAME:";
std :: cin >> sname;
  student[sel - 1].setName(sname);
  break;

case 2:
  std :: cout << std::endl;
  student[sel - 1].setAge();
  break;

case 3:
  std :: cout << std::endl;
  student[sel - 1].setWeight();
  break;

default:
  break;
}

  break;

case 3:
do{
  std :: cout << std::endl;
  std :: cout << "ENTER THE STUDENT'S SERIAL NUMBER" << std :: endl;
  std :: cout << "ENTER: ";
  std :: cin >> sel;
}while(sel < 1 & sel > counter);

student[sel - 1].print();
break;

default:
  break;
}

return sel;
}
// *********************************************************************************************

/* ***************************************** Задание 2 *****************************************
 * Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
 * У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс 
 * GrannySmith, который наследует класс Apple.
 * *********************************************************************************************/
class Fruit{
public:
Fruit(std::string name = "", std::string color = ""): fname(name), fcolor(color)
{ }

protected:
std::string fname, fcolor;
};

class Apple: public Fruit{
public:
Apple(std::string color = "green", std::string name = "apple"): acolor(color), aname(name)
{ }

std::string getName() const
{
return aname;
}

std::string getColor() const
{
return acolor;
}

protected:
std::string aname, acolor;
};

class Banana: public Fruit{
public:
Banana(std::string color = "yellow", std::string name = "banana"):bname(name), bcolor(color)
{ }

std::string getName() const
{
return bname;
}

std::string getColor() const
{
return bcolor;
}

private:
std::string bname, bcolor;
};

class GrannySmith: public Apple
{
public:
GrannySmith(std::string color = "green", std::string name = "Granny Smith "):gname(name), gcolor(color)
{ }

std::string getName() const
{
return gname + aname;
}

std::string getColor() const
{
return gcolor;
}

private:
std::string gname, gcolor;
};
// *********************************************************************************************

/* ***************************************** Задание 3 *****************************************
 * Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя 
 * объектно-ориентированное программирование. Сколько будет классов в программе? Какие классы
 * будут базовыми, а какие производными? Продумать реализацию игры с помощью классов и записать 
 * результаты.
 * *********************************************************************************************/
/* Card – Базовый класс в котором описываются свойства игральных карт, а именно номинал карт 
 * (количество очков при получении карты) и наименование карт (Например, А – туз), а так же их
 * количество в колоде.
 * 
 * Player – Производный класс наследуется от базового класса и имеет собственную переменную для 
 * имени игрока, массив с определённым количеством элементов, в который записываются наименования
 * карт полученные игроком, а так же переменную-счётчик очков.
 * 
 * setName – метод класса для записи имени игрока.
 * getPlayerCard – метод класса, который случайным образом выдаёт карту из колоды уменьшая
 * счётчик количества карт и делает соответствующую запись в поле полученных игроком карт,
 * увеличивая при этом счётчик очков игрока.
 * printPlayerCard – метод класса, возвращающий массив полученных игроком карт.
 * getScore - метод класса, возвращающий количество очков игрока.
 * getName - метод класса, возвращающий имя игрока.
 * 
 * gameProcess – Общий метод описывающий игровой процесс.
 * showScreen – Общий метод отвечающий за вывод экран информации необходимой пользователю для
 * игрового процесса.
 ***********************************************************************************************/
int main(const int argc, const char** argv){

//Task1
int menu_item = 0;

while(menu_item != 2){

if(menu_item == 0){
  menu_item = program_menu();
}else{

do{
  std :: cout << "(1 - CONTINUE) OR (2 - EXIT)?" << std::endl;
  std :: cout << "ENTER: ";
  std :: cin >> menu_item;
}while(menu_item < 0 & menu_item > 2);

menu_item == 1 ? program_menu() : 2; 
}

}

student.clear();

//Task2
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
return 0;
}