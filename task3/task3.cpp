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

  string info() {
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

public:
  StudentContractor(string fname, string fty, int crs, int rate, int paid): Student(fname, fty, crs, rate) {
    isPaid = paid;
  }

  virtual int canMoveNextCourse() {
    return (Student::canMoveNextCourse() && isPaid);
  }

  virtual string getGrant() {
    return "0";
  }
};



int main(int argc, char const *argv[]) {
  string fullname, faculty;
  int course, minimalRating;

  Student* student = new Student("default pav", "amm", 1, 4);

  Student* studentContractor1 = new StudentContractor("contractor pav", "amm", 1, 4, 0);
  Student* studentContractor2 = new StudentContractor("contractor pav paid", "amm", 1, 4, 1);

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

  return 0;
}
