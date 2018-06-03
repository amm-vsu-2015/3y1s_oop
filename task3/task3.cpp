/**

  Задача:
  - Класс-родитель: студент (фио, факультет, курс, минимальная оценка)
  - Класс-потомок: контрактор (+ оплатил ли учебу и не может получать стипендию)
  - Вывести одного студента и двух контрактников. Создать метод по переводу на следующий курс.

  Требования:
  - реализовать наследование с виртуальными методами
  - ввод-вывод данных об объекте родителя и потомка

  Входные значения для тестирования:

  1.
  Student("default pav", "amm", 1, 4); // хорошист; должен получать стипендию и перейти на след. курс.
  StudentContractor("contractor pav", "amm", 1, 4, 0); // хорошист, не оплатил учебу; не может перейти на другой курс, стипендию не получает.
  StudentContractor("contractor pav paid", "amm", 1, 4, 1); // хорошист, оплатил учебу; может перейти на другой курс, стипендию не получает.

  2.
  Student("default pav", "amm", 1, 3); // троешник; может перейти на след. курс, стипендию не получает;
  StudentContractor("contractor pav", "amm", 1, 2, 1); // двоешник, оплатил учебу; не может перейти на другой курс, стипендию не получает.
  StudentContractor("contractor pav paid", "amm", 1, 5, 0); // отличник, не оплатил учебу; не может перейти на другой курс, стипендию не получает.

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

public:
  Student(string fname, string fty, int crs, int rate) {
    fullname = fname;
    faculty = fty;
    course = crs;
    minimalRating = rate;
  }

  virtual void moveNextCourse() {
    if (minimalRating >= 3) {
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

    stream.str(""); // clear stream

    stream << fixed << setprecision(0) << minimalRating;
    string rated = stream.str();

    stream.str(""); // clear stream

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

  virtual void moveNextCourse() {
    if (minimalRating >= 3 && isPaid) {
      course++;
    }
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
