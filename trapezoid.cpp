
#include <iostream>
 #include <iomanip>
 #include <cmath>
using namespace std;

// Класс для работы с трапецией 
class Trapezoid {
private:
    double a; 
    double b; 
    double c; 
    double d;  
    double h; 

public:
    // Конструктор
    Trapezoid(double top_base, double bottom_base, double left_side, 
              double right_side, double height) {
        a = top_base;
        b = bottom_base;

        c = left_side;
        d = right_side;
        h = height;
    }

      // Проверка , что все стороны положительные
     bool isPositive () {
        return (a > 0 && b > 0 && c > 0 && d > 0 && h > 0);
    }

    bool isQuadrilateral(){
       return (a+b+c>d) && (a+b+d>c) && (a+c+d>b) && (b+c+d>a);
    }
    
    bool isValid(){
       return isPositive() && isQuadrilateral();

     // Вычисление периметра
    double perimeter() {
        return a + b + c + d;
    }
     // Вычисление площади
    double area() {
        return (a + b) / 2.0 * h;
    }
      // Вычисление средней линии
    double midline() {
        return (a + b) / 2.0;
    }
       // Вывод информации о трапеции
    void printInfo() {
        cout << fixed << setprecision(2);
        cout << "\n========================================" << endl;
        cout << "Параметры трапеции:" << endl;
        cout << "Верхнее основание a: " << a << endl;
        cout << "Нижнее основание b: " << b << endl;
        cout << "Левая боковая сторона c: " << c << endl;
        cout << "Правая боковая сторона d: " << d << endl;

        cout << "Высота h: " << h << endl;
        cout << "======================================"<< endl;
        if (!isPositive ()) {
           cout << "\nОшибка : все параметры положительные" << endl;
        } 
        else if (!isQuadrilateral()) {
            cout << "\nОшибка: не выполняется правило четырех сторон!" << endl;
            cout << "Сумма любых трех сторон должна быть больше четвертой." << endl;
            cout << "Проверьте введенные значения." << endl;
        }
        else {
            cout << "\nРезультаты вычислений:" << endl;
            cout << "Периметр трапеции: " << perimeter() << endl;
            cout << "Площадь трапеции: " << area() << endl;
            cout << "Средняя линия: " << midline() << endl;
        } else {
            cout << "\nОшибка: все параметры должны быть положительными!" << endl;
        }
    }
};
// Функция для ввода данных с проверкой
double inputValue(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;
    
    while (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите число: ";
        cin >> value;
    }
    return value;
}
    int main() {
    
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << "Программа для вычисления параметров трапеции" << endl;
    cout << "========================================" << endl;
    cout << endl;
     // Ввод данных
    double a = inputValue("Введите верхнее основание a: ");
    double b = inputValue("Введите нижнее основание b: ");
    double c = inputValue("Введите левую боковую сторону c: ");
    double d = inputValue("Введите правую боковую сторону d: ");
    double h = inputValue("Введите высоту h: ");
    // Создание объекта трапеции
    Trapezoid trapezoid(a, b, c, d, h);
    // Вывод результатов
    trapezoid.printInfo();
    return 0;
}
