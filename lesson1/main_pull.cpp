#include <iostream>
#include <math.h>
#include <cstdint>

/* ***************************************** Задание 1 *****************************************
 * Создать класс Power, который содержит два вещественных числа.
 * Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
 * Еще создать два метода: один с именем set, который позволит присваивать значения переменным,
 * второй — calculate, который будет выводить результат возведения первого числа в степень 
 * второго числа. Задать значения этих двух чисел по умолчанию.
*/

class Power{
private:
    float a = 5, b = 2;

public:
    void set(float first, float second){

        a = first;
        b = second;
    }

    void calculate(){

        std :: cout << a << "^" << b << " = " << pow(a, b) << ";" << std :: endl;
    }
};

//**********************************************************************************************

/* ***************************************** Задание 2 *****************************************
 * Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t:
 * m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
 * Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
 * Создать конструктор со списком инициализации членов, который позволит пользователю передавать
 * значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить
 * значения переменных-членов.
*/

class RGBA{
    private:
    std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;

    public:
    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    void print(){
        std :: cout << "m_red = " << m_red << ";" << std :: endl;
        std :: cout << "m_green = " << m_green << ";" << std :: endl;
        std :: cout << "m_blue = " << m_blue << ";" << std :: endl;
        std :: cout << "m_alpha = " << m_alpha << "." << std :: endl;
    }

};

//**********************************************************************************************

/* ***************************************** Задание 3 *****************************************
 * Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
 * • private-массив целых чисел длиной 10;
 * • private целочисленное значение для отслеживания длины стека;
 * • public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
 * • public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать 
 * значение false, если массив уже заполнен, и true в противном случае;
 * • public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет 
 * значений, то должно выводиться предупреждение;
 * • public-метод с именем print(), который будет выводить все значения стека.
*/

class Stack{
    private:
    int *arr = (int*) calloc(10, sizeof(int));
    int len = 0;

    public:
    Stack(){}

    void reset(){

        if(len != 0){
            for(int i = 0; i < len; i++)
            arr[i] = 0;

        len = 0;
        }
    }

    bool push(int value){

        if(len >= 0 & len < 10){
            for(int i = 0; i <= len; i++){
                if(arr[i] == 0){
                    arr[i] = value;
                    len++;
                    break;
                }
            }
            return true;
        }else{
            return false;
        }
    } 

    int pop(){
    int returnable = 0;

        if(arr[0] != 0){
            returnable = arr[len - 1];
            arr[len--] = 0;
            return returnable;
        }else{
            std :: cout << "The stack is empty!" << std :: endl;
        }
    }

    void print(){

        std :: cout << "(";

        if(len > 0){
            for(int i = 0; i < len; i++){
                std :: cout << arr[i];
            }
        }

        std :: cout << ")" << std :: endl;
    }

 ~Stack(){
     delete arr;
 }

};

//**********************************************************************************************

int main(const int argc, const char** argv){
//Вызов методов задания 1
Power P;

P.set(6, 4);
P.calculate();

std :: cout << std :: endl;
//Вызов методов задания 2
RGBA rgba(6, 7, 9, 100);
rgba.print();

std :: cout << std :: endl;
//Вызов методов задания 3
Stack stack;
stack.reset();
stack.print();

stack.push(3);
stack.push(7);
stack.push(5);
stack.print();

stack.pop();
stack.print();

stack.pop();
stack.pop();
stack.print();

return 0;
}