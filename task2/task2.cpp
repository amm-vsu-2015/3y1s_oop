/**

  Задача:
  - Класс-родитель: действительная и мнимая часть
  - Класс-потомок: действительная и мнимая часть
  - В классе-потомке вычислить произведение действительных чисел

  Требования:
  - реализовать конструктор по умолчанию
  - функция формирования строки с информацией об объекте
  - ввод-вывод данных об объекте родителя и потомка

  Входные значения для тестирования:
  3 13 7 17

*/

#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct ComplexResult {
  long double rNum;
  long double iNum;

  ComplexResult(long double realNumber, long double iNumber) {
    rNum = realNumber;
    iNum = iNumber;
  }

  string toString() {
    stringstream stream;
    stream << fixed << setprecision(2) << rNum;
    string rPart = stream.str();

    stream.str(""); // clear stream

    stream << fixed << setprecision(2) << iNum;
    string iPart = stream.str();

    char mark = (iNum >= 0) ? '+' : '-';

    return (rPart + mark + iPart + "i");
  }
};

class Complex {
protected:
  long double rNum, iNum;

public:
  Complex() {
    rNum = 1; iNum = 2;
  }

  Complex(long double realNumber, long double iNumber) {
    rNum = realNumber;
    iNum = iNumber;
  }

  string toString() {
    ComplexResult* result = new ComplexResult(rNum, iNum);
    return result->toString();
  }

  ~Complex() {
    std::cout << "Complex destroyed." << '\n';
  }
};

class ComplexMultiplier: protected Complex {
private:
  long double rNumSec, iNumSec;

public:
  ComplexMultiplier() {
    rNumSec = 1;
    iNumSec = 2;
  }

  ComplexMultiplier(long double realNumber, long double imaginaryNumber, long double secondRealNumber, long double secondImaginaryNumber): Complex(realNumber, imaginaryNumber) {
    rNumSec = secondRealNumber;
    iNumSec = secondImaginaryNumber;
  }

  string toString() {
    return multiply()->toString();
  }

  ComplexResult* multiply() {
    long double realPart = rNum*rNumSec - iNum*iNumSec;
    long double imaginePart = rNum*iNumSec + rNumSec*iNum;
    ComplexResult* result = new ComplexResult(realPart, imaginePart);
    return result;
  }

  ~ComplexMultiplier() {
    std::cout << "ComplexMultiplier destroyed." << '\n';
  }
};

int main(int argc, char const *argv[]) {
  long double rNum1, iNum1, rNum2, iNum2;

  std::cout << "Write Complex Number (parent real num, parent imaginary num, child real num, child imaginary num):" << '\n';
  std::cin >> rNum1 >> iNum1 >> rNum2 >> iNum2;

  Complex* complexParent = new Complex(rNum1, iNum1);
  std::cout << "Complex Number Parent Information: " << complexParent->toString() << '\n';

  ComplexMultiplier* complexMultiplier = new ComplexMultiplier(rNum1, iNum1, rNum2, iNum2);
  std::cout << "ComplexMultiplier Information: " << complexMultiplier->toString() << '\n';


  delete(complexParent);
  complexParent = nullptr;
  delete(complexMultiplier);
  complexMultiplier = nullptr;

  return 0;
}
