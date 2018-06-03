/**

  Задача:
  Дана символьная строка с некоторым выражением, в котором могут содержаться скобки трех видов: {}, [], ().
  Написать метод проверки правильности расстановки скобок в этой строке.

  Принцип работы алгоритма.

  Для подсчета будет использоваться структура данных Стэк.
  В стэке будет храниться "тип скобки" в порядке их открытия в строке.

  Учитывая условия задачи, необходимо прослеживать правильные закрывания скобок.
  Правильным будет только тот случай, когда закрывается ранее открытая скобка (последняя в стэке)
  Например, скобки в таком порядке:

  (   {   [   (   {   }   )   ]   (   )   }   )
  ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
 in  in  in  in  in  out out out in  out out out -- вхождение и выхождение из стэка "типа скобок"

 Так как по завершению парсинга строки стэк остался пустым, а также не было замечено процедуры out по отношению к другому типу скобки,
 можно заключить, что скобки расставлены верно.


  Требования:
  - использовать классы стека или очереди для реализации задачи
  - ввод-вывод данных об объекте родителя и потомка

  Входные значения для тестирования:

*/

#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const int STACK_SIZE = 1024;

enum BracketsType: char {
  circle = '(',
  square = '[',
  braces = '{'
};

enum ErrorType {
  badClosed, // wrong closing of brackets
  unclosed, // catch if user not closed all of brackets
  overflow, // catch if while stack overflow
  underflow // catch while trying to pop while stack is empty (may be trying to close not opened brackets)
};

class BracketsStack {
private:
  BracketsType stack[STACK_SIZE];
  int topIndex = -1; // is empty by default

  /// Support methods

  int isOverflow() {
    return (topIndex >= STACK_SIZE);
  }

public:

  /// Operations /w Stack

  void push(BracketsType newType) {
    if (!isOverflow()) {
      stack[++topIndex] = newType;
    } else {
      std::cout << "Stack Overflow!" << '\n';
    }
  }

  /// Support methods

  int isEmpty() {
    return (topIndex < 0) ? 1 : 0;
  }

  /// Output methods

  void print() {
    if (isEmpty()) {
      std::cout << "Stack is empty!" << '\n';
    } else {
      std::cout << ": " << char(stack[0]) << '\n';
    }
  }
};


class Parser {
private:
  string rawString;
  BracketsStack* bracketsStack;

  // can pop this bracket?
  // send error state

  // find bracker -> check type -> add type to stack

  int isCorrectSymbol(char symbol) {

    if (symbol == '{' || symbol == '}') {

    }

    return 0;
  }

public:
  Parser(string raw) {
    rawString = raw;

    bracketsStack = new BracketsStack();
  }

  void parse() {
    // fill stack
    // colored output
    // show error if needed
  }

  void print() {
    cout << rawString << endl;
  }

};

int main(int argc, char const *argv[]) {
  Parser* parser = new Parser("129ujasidj1");
  parser->print();
  return 0;
}


























// imitate footer for scrolling of atom redactor
