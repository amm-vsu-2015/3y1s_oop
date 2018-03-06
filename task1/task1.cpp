/**

	Дан вектор на плоскости с координатами (x1, y1, x2, y2).

  Задача:
  - Вычислить длину вектора

  Требования:
  - реализовать конструктор по умолчанию
  - [операторы перегрузки]
  - реализовать деструктор
  - функция формирования строки с информацией об объекте

*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Vector {
private:
  int x1, y1, x2, y2;

  double getArea() {
    int tmp_x = abs(x2 - x1);
		int tmp_y = abs(y2 - y1);

		return sqrt(pow(tmp_x, 2) + pow(tmp_y, 2));
  }

public:
  Vector() {
    x1 = 1; y1 = 1;
    x2 = 5; y2 = 5;
  }

  Vector(int X1, int Y1, int X2, int Y2) {
    x1 = X1; y1 = Y1;
    x2 = X2; y2 = Y2;
  }

  string toString() {
    return (to_string(getArea()));
  }

  ~Vector() {
    std::cout << "Vector destroyed." << '\n';
  }
};

int main(int argc, char const *argv[]) {
  int x1, y1, x2, y2;

  std::cout << "write Vector coordinates (x1, y1, x2, y2):" << '\n';
  std::cin >> x1 >> y1 >> x2 >> y2;

  Vector* vector = new Vector(x1, y1, x2, y2);
  std::cout << "Vector length equals " << vector->toString() << '\n';

  delete(vector);
  vector = nullptr;

  return 0;
}
