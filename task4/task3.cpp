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

  Входные значения для тестирования:

*/

#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

const int STACK_SIZE = 1024;

enum BracketsType: int { circle = 0, square = 1, braces = 2 };

enum ErrorType: int {
  badClosed, // wrong closing of brackets
  unclosed, // catch if user not closed all of brackets
  overflow, // catch if while stack overflow
  underflow // catch while trying to pop while stack is empty (may be trying to close not opened brackets)
};

struct Brackets {
  BracketsType type;
  int index; // place in current string

  Brackets(BracketsType aType, int aIndex) {
    type = aType;
    index = aIndex;
  }
};

class BracketsStack {
private:
  Brackets* stack[STACK_SIZE];
  int topIndex = -1; // is empty by default

  /// Support methods
  int isOverflow() {
    return (topIndex >= STACK_SIZE);
  }

public:

  /// Operations /w Stack

  void push(BracketsType type, int index) {
    if (!isOverflow()) {
      stack[++topIndex] = new Brackets(type, index);
      std::cout << stack[topIndex]->type << '\n';
    } else {
      cout << "Stack Overflow!" << '\n';
    }
  }

  Brackets* pop() {
    if (!isEmpty()) {
      return stack[topIndex--];
    } else {
      cout << "Stack is empty!" << '\n';
      return nullptr;
    }
  }

  /// Support methods
  int isEmpty() {
    return (topIndex < 0) ? 1 : 0;
  }

  int isEqualLast(BracketsType type) {
    std::cout << "equals "<< (stack[topIndex]->type == type)<< ": " << stack[topIndex]->type << " to " << type << '\n';
    return (stack[topIndex]->type == type);
  }

  /// Output methods
  void printLast() {
    if (!isEmpty()) {
      cout << "Last item of stack: " << char(stack[topIndex]->type) << '\n';
    } else {
      cout << "Stack is empty!" << '\n';
    }
  }

  void printAll() {
    if (!isEmpty()) {
      for (int idx_i = 0; idx_i < topIndex; idx_i++) {
        cout << char(stack[idx_i]->type);
      }
      cout << '\n';
    } else {
      cout << "Stack is empty!" << '\n';
    }
  }
};


class Parser {
private:
  string rawString;
  BracketsStack* bracketsStack;

  // can pop this bracket?
  // send error state
  // find brackets -> check type -> add type to stack
  // enum BracketsType { circle, square, braces };

  int canCloseBracket(char symbol) {
    // -> last stack type == symbol type
    int canClose = 0;

    switch (symbol) {
    case ')':
      canClose = bracketsStack->isEqualLast(circle);
      break;
    case ']':
      canClose = bracketsStack->isEqualLast(square);
      break;
    case '}':
      canClose = bracketsStack->isEqualLast(braces);
      break;
    }

    // std::cout << rawString[idx_i] << " -> "<< canCloseBracket(rawString[idx_i]) << '\n';
    // std::cout << '\n' << '\n';

    std::cout << symbol << " -> "<< canClose << '\n';
    std::cout << '\n' << '\n';

    if (!canClose) {
      // throw badClosed;
    }

    return canClose;
  }

  int isCorrectSymbol(char symbol) {
    return (symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}');
  }

  void fillStack() {
    for (int idx_i = 0; idx_i < rawString.length(); idx_i++) {
      if (isCorrectSymbol(rawString[idx_i])) {
        // std::cout << bracketsStack->printLast << '\n';
        switch (rawString[idx_i]) {
        case '(':
          bracketsStack->push(circle, idx_i);
          break;
        case '[':
          bracketsStack->push(square, idx_i);
          break;
        case '{':
          bracketsStack->push(braces, idx_i);
          break;
        }
      }
    }
  }

  void checkExpression() throw (int) {
    for (int idx_i = 0; idx_i < rawString.length(); idx_i++) {
      if (isCorrectSymbol(rawString[idx_i])) {
        bracketsStack->printAll();
        if (canCloseBracket(rawString[idx_i])) {
            bracketsStack->pop();
        }
      }
    }
  }

public:
  Parser(string raw) {
    rawString = raw;
    bracketsStack = new BracketsStack();
  }

  void parse() {
    fillStack();
  }

  void showStack() {
    bracketsStack->printAll();
  }

  void print() {
    cout << rawString << endl;
  }

};

int main(int argc, char const *argv[]) {
  // Parser* parser = new Parser("129ujasidj1"); // none
  Parser* parser = new Parser("129ujas{{}{{1}241{}4214{()42}idj1"); // unclosed
  // Parser* parser = new Parser("129ujas{}{}{}}{1}241{}4214{()42}idj1"); // underflow
  // Parser* parser = new Parser("129ujas{}{}{}){1}241{}4214{()42}idj1"); // bad closed
  // & overflow
  // Parser* parser = new Parser("129ujas{{}{{1}241{}4214{()42}idj1");
  parser->parse();
  parser->print();
  parser->showStack();
  return 0;
}


























// imitate footer for scrolling of atom redactor
