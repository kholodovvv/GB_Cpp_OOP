#include <iostream>
#include <stdlib.h>
#include <string.h>
/* ***************************************** Задание 1 *****************************************
 * Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные
 * одного типа парами. 
 * *********************************************************************************************/

template <class T>

class Pair1
{
public:

Pair1(T f, T s): c_f(f), c_s(s)
{ }

T first() const
{
  return c_f;
}

T second() const
{
  return c_s;
}

private:
T c_f, c_s;
};
// *********************************************************************************************

/* ***************************************** Задание 2 *****************************************
 * Реализовать класс Pair, который позволяет использовать разные типы данных в
 * передаваемых парах. 
 * *********************************************************************************************/

template <typename T, typename S>

class Pair
{
public:

Pair(T f, S s): c_f(f), c_s(s)
{ }

T first() const
{
  return c_f;
}

S second() const
{
  return c_s;
}

private:
T c_f;
S c_s;
};
// *********************************************************************************************

/* ***************************************** Задание 3 *****************************************
 * Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а
 * второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс
 * Pair, в котором первый параметр — string, а второй — любого типа данных.
 * *********************************************************************************************/
template<typename T>
class Pair2
{ 
  public:
  Pair2(std::string s, T tt):c_s(s), c_t(tt)
  { }

  protected:
  std::string c_s;
  T c_t;
};

template<typename T>
class StringValuePair:public Pair2<T>
{
  public:
  StringValuePair(std::string s, T tt):Pair2<T>(s, tt), c_s(s), c_t(tt)
  { }

std::string first() const
{
  return c_s;
}

T second() const
{
  return c_t;
}

  T c_t;
  std::string c_s;
};
// *********************************************************************************************

/* ***************************************** Задание 4 *****************************************
 * Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand
 * наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет
 * два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить
 * поле name - имя игрока. Также добавить 3 метода:
 * ●	IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
 * ●	IsBoosted() - возвращает bool значение, есть ли у игрока перебор.
 * ●	Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
 * *********************************************************************************************/

class GenericPlayer:public Hand
{
public:
GenericPlayer(std::string name): nm(name)
{ }

virtual bool IsHitting() const //true - если нужна ещё одна карта (вернее, может ли игрок взять ещё одну карту), false - не нужна
{ 
  return (GetTotal() < 21) ? true : false;
}

bool IsBoosted() const //если сумма очков игрока больше 21, то соответственно возвращается true (перебор)
{
  return (GetTotal() > 21) ? true : false;
}

void Bust()
{
  std::cout << "THE PLAYER HAS " << nm << " OVERFLOW!" << std::endl;
}

private:
std::string nm;
};
// *********************************************************************************************

int main(const int argc, const char** argv){

//Task1

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

//Task2

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

//Task3

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';


return 0;
}