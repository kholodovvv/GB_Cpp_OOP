#include <iostream>
#include <vector>
#include <cctype> //Для использования функции isdigit()
#include <string>

/* ***************************************** Задание 1 *****************************************
 * Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
 * если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести
 * сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных
 * строк: rbtrb, nj34njkn, 1n
 * *********************************************************************************************/

void FoolproofProt()
{
std::string str = "";
int fl = 0;

do{

std::cout << "ENTER AN INTEGER: " << std::endl;
std::getline(std::cin, str);

for(auto c : str){
  fl = std::isdigit(c);
  if(!fl){
    std::cerr << "ERROR ENTERING A NUMBER, TRY AGAIN!" << std::endl;
    break;
  }
}

}while(fl < 1);

}

// *********************************************************************************************

/* ***************************************** Задание 2 *****************************************
 * Создать собственный манипулятор endll для стандартного потока вывода, который выводит
 * два перевода строки и сбрасывает буфер.
 * *********************************************************************************************/

class Endll
{
public:
Endll()
{ }

friend std::ostream& operator<< (std::ostream& out, const Endll &endll);

};

std::ostream& operator<< (std::ostream& out, const Endll &endll)
{
  out << "\n" << "\n";
  out.flush();

  return out;
}

// *********************************************************************************************

/* ***************************************** Задание 3 *****************************************
 * Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4
 * метода:
 * ●	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
 * Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя
 * в виде true или false.
 * ●	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
 * ●	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
 * ●	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
 * *********************************************************************************************/

class Player: public GenericPlayer
{
public:
~Player()
{ }

virtual bool IsHitting() const
{
  char *answer;
  std::cout << "TAKE A CARD? (Y / N): " << std::endl;
  std::cin >> answer;

return (answer == "Y" || answer == "y");

}

void Win() const
{
  std::cout << "THE GAMER " << m_Name << " WON!" << std::endl;
}

void Lose() const
{
  std::cout << "THE GAMER " << m_Name << " LOST!" << std::endl;
}

void Push() const
{
  std::cout << "THE GAMER " << m_Name << " PLAYED A DRAW!" << std::endl;
}

};

// *********************************************************************************************

/* ***************************************** Задание 4 *****************************************
 * Реализовать класс House, который представляет дилера. Этот класс наследует от класса
 * GenericPlayer. У него есть 2 метода:
 * ●	virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если 
 * у дилера не больше 16 очков, то он берет еще одну карту.
 * ●	void FlipFirstCard() - метод переворачивает первую карту дилера.
 * *********************************************************************************************/

class House:public GenericPlayer
{
public:

virtual bool IsHitting() const
{
    return (GetTotal() <= 16) ? true : false;
}

void FlipFirstCard()
{
  int value = 0;
  Card *first = *(m_Cards.begin());

  value = first->GetValue();

  if(!value)
    first->Flip();
}

};
// *********************************************************************************************

/* ***************************************** Задание 5 *****************************************
 * Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой
 * вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
 * Также для класса GenericPlayer написать перегрузку оператора вывода, который должен 
 * отображать имя игрока и его карты, а также общую сумму очков его карт.
 * *********************************************************************************************/

//Естественно в классе метод объявлен будет как friend
//friend std::ostream& operator<< (std::ostream& out, const Card &card);

std::ostream& operator<< (std::ostream& out, const Card &card)
{
  int value = card.GetValue();
  
  if(!value)
  {
    out << "XX";
  }
  else{
    out << value << " " << card.m_Suit;
  }

  return out;
}

//Код для решения этого пункта задачи приведён в методичке, скопировал и задача выполнена (так что ли ;))
std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";
    
    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        
        
        if (aGenericPlayer.GetTotal() != 0)
        {
            std::cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    
    return os;
}



int main(const int argc, const char** argv){

//Task1
FoolproofProt();

//Task2
Endll endll;
std::cout << endll;

return 0;
}