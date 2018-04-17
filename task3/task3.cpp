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

class Student {
protected:
  string fullname;
  string faculty;

  int course;
  int minimalRating;

  virtual int canMoveNextCourse() {
    return (minimalRating >= 3);
  }

public:
  Student(string fname, string fty, int crs, int rate) {
    fullname = fname;
    faculty = fty;
    course = crs;
    minimalRating = rate;
  }

  // return bool
  virtual void moveNextCourse() {
    if (canMoveNextCourse()) {
      course++;
    }
  }

  virtual string getGrant() {
    long double grant = 0;

    if (minimalRating == 5) {
      grant = 300;
    } else if (minimalRating == 4) {
      grant = 200;
    }

    stringstream stream;
    stream << fixed << setprecision(0) << grant;
    string result = stream.str();

    return result;
  }

  virtual string info() {
    stringstream stream;
    stream << fixed << setprecision(0) << course;
    string crs = stream.str();

    stream.str("");

    stream << fixed << setprecision(0) << minimalRating;
    string rated = stream.str();

    stream.str("");

    stream << fixed << setprecision(0) << getGrant();
    string granted = stream.str();

    return (fullname + ", faculty: " + faculty + ", course: " + crs + ", rating: " + rated + ", grant: " + granted);
  }
};

class StudentContractor: public Student {
protected:
  int isPaid = 0;

  virtual int canMoveNextCourse() {
    return (Student::canMoveNextCourse() && isPaid);
  }
public:
  StudentContractor(string fname, string fty, int crs, int rate, int paid): Student(fname, fty, crs, rate) {
    isPaid = paid;
  }
};



int main(int argc, char const *argv[]) {
  /// long double rNum1, iNum1, rNum2, iNum2;
  string fullname, faculty;
  int course, minimalRating;

  Student* student = new Student("1", "amm", 1, 4);

  StudentContractor* studentContractor1 = new StudentContractor("2", "amm", 1, 4, 0);
  StudentContractor* studentContractor2 = new StudentContractor("3", "amm", 1, 4, 1);

  std::cout << student->info() << '\n';
  std::cout << studentContractor1->info() << '\n';
  std::cout << studentContractor2->info() << '\n';

  student->moveNextCourse();
  studentContractor1->moveNextCourse();
  studentContractor2->moveNextCourse();

  std::cout << '\n';
  std::cout << student->info() << '\n';
  std::cout << studentContractor1->info() << '\n';
  std::cout << studentContractor2->info() << '\n';

  // std::cout << "Write Complex Number (parent real num, parent imaginary num, child real num, child imaginary num):" << '\n';
  // std::cin >> rNum1 >> iNum1 >> rNum2 >> iNum2;
  //
  // Complex* complexParent = new Complex(rNum1, iNum1);
  // std::cout << "Complex Number Parent Information: " << complexParent->toString() << '\n';
  //
  // ComplexMultiplier* complexMultiplier = new ComplexMultiplier(rNum1, iNum1, rNum2, iNum2);
  // std::cout << "ComplexMultiplier Information: " << complexMultiplier->toString() << '\n';

  //
  // delete(complexParent);
  // complexParent = nullptr;
  // delete(complexMultiplier);
  // complexMultiplier = nullptr;

  return 0;
}
