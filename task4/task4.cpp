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
#include <string>

using namespace std;

const int STACK_SIZE = 1024;

enum BracketsType: char { circle = '(', square = '[', braces = '{' };

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
  int isError = 0;

  /// Support methods
  int isOverflow() {
    return (topIndex >= STACK_SIZE);
  }

public:

  /// Operations /w Stack

  void push(BracketsType type, int index) {
    if (!isOverflow()) {
      stack[++topIndex] = new Brackets(type, index);
    } else {
      cout << "Stack Overflow!" << '\n';
      isError = 1;
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

  int isErrored() {
    return isError;
  }

  int isEqualLast(BracketsType type) {
      if (isEmpty()) {
        cout << "You can't close unopen brackets!" << '\n';
        isError = 1;
        return 0;
      }
      return (stack[topIndex]->type == type);
  }

  /// Output methods
  void printAll() {
    if (!isEmpty()) {
      for (int idx_i = 0; idx_i <= topIndex; idx_i++) {
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
  int completedProcess; // string fully parsed

  int isOpenBracket(char symbol) {
    return (symbol == '(' || symbol == '[' || symbol == '{');
  }

  int canCloseBracket(char symbol) {
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

    return canClose;
  }

  int isCorrectSymbol(char symbol) {
    return (symbol == '(' || symbol == ')' || symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}');
  }

  void checkExpression() {
    completedProcess = false;
    for (int idx_i = 0; idx_i < rawString.length(); idx_i++) {
      char currentSymbol = rawString[idx_i];

      if (isCorrectSymbol(currentSymbol)) {

        if (isOpenBracket(currentSymbol)) {
          pushToStack(currentSymbol, idx_i);
        } else if (canCloseBracket(currentSymbol)) {
          popFromStack(currentSymbol, idx_i);
        }
      }

      if (bracketsStack->isErrored()) {
        break;
      }
    }

    // completedProcess = idx_i == rawString.length() - 1;
    completedProcess = !bracketsStack->isErrored();
  }

  void pushToStack(char symbol, int index) {
    switch (symbol) {
    case '(':
      bracketsStack->push(circle, index);
      break;
    case '[':
      bracketsStack->push(square, index);
      break;
    case '{':
      bracketsStack->push(braces, index);
      break;
    }
  }

  void popFromStack(char symbol, int index) {
    if (canCloseBracket(symbol)) {
      bracketsStack->pop();
    } else {
      cout << "Bad close! at " << index << '\n';
    }
  }

public:
  Parser(string raw) {
    rawString = raw;
    completedProcess = false;
    bracketsStack = new BracketsStack();
  }

  void parse() {
    checkExpression();
  }

  void showStack() {
    bracketsStack->printAll();
  }

  void print() {
    cout << rawString << endl;
  }

  int check() {
    if (!bracketsStack->isEmpty()) {
      cout << "You didn't close all brackets!" << '\n';
    }

    return (bracketsStack->isEmpty() && completedProcess);
  }

};

int main(int argc, char const *argv[]) {
  // Parser* parser = new Parser("129ujasidj1"); // none / success
  // Parser* parser = new Parser("129ujas{{}{{1}241{}4214{()42}idj1"); // unclosed
  // Parser* parser = new Parser("129ujas{}{}{}}{1}241{}4214{()42}idj1"); // underflow
  // Parser* parser = new Parser("129ujas{}{}{}){1}241{}4214{()42}idj1"); // bad closed
  // Parser* parser = new Parser("129ujas{}{}{}{1}241{}4214{()42}idj1"); // success

  string userString;
  std::getline(cin, userString);
  Parser* parser = new Parser(userString); // success
  parser->parse();

  if (parser->check()) {
    cout << "Successful" << '\n';
  } else {
    cout << "Failure" << '\n';
  }

  return 0;
}


























// imitate footer for scrolling of atom redactor
