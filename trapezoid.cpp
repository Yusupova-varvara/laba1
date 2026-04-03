#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Проверка, что все стороны положительные
bool isPositive(double a, double b, double c, double d, double h) {
    return (a > 0 && b > 0 && c > 0 && d > 0 && h > 0);
}

// Проверка правила четырех сторон
bool isQuadrilateral(double a, double b, double c, double d) {
    return (a + b + c > d) &&
           (a + b + d > c) &&
           (a + c + d > b) &&
           (b + c + d > a);
}

// Проверка на равнобедренность
bool isIsosceles(double c, double d) {
    return abs(c - d) < 0.0001;
}

int main() {
    double a, b, c, d, h;
    
    cout << "========================================" << endl;
    cout << "Программа для вычисления параметров трапеции" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Примечание: должно выполняться правило четырех сторон." << endl;
    cout << "Сумма любых трех сторон больше четвертой." << endl;
    cout << endl;
    
    cout << "Введите параметры трапеции:" << endl;
    cout << "Верхнее основание a: ";
    cin >> a;
    cout << "Нижнее основание b: ";
    cin >> b;
    cout << "Левая боковая сторона c: ";
    cin >> c;
    cout << "Правая боковая сторона d: ";
    cin >> d;
    cout << "Высота h: ";
    cin >> h;
    
    cout << fixed << setprecision(2);
    cout << "\n========================================" << endl;
    cout << "Параметры трапеции:" << endl;
    cout << "  Верхнее основание a: " << a << endl;
    cout << "  Нижнее основание b: " << b << endl;
    cout << "  Левая боковая сторона c: " << c << endl;
    cout << "  Правая боковая сторона d: " << d << endl;
    cout << "  Высота h: " << h << endl;
    cout << "========================================" << endl;
    
    // Проверки
    if (!isPositive(a, b, c, d, h)) {
        cout << "\nОшибка: все параметры должны быть положительными!" << endl;
    }
    else if (!isQuadrilateral(a, b, c, d)) {
        cout << "\nОшибка: не выполняется правило четырех сторон!" << endl;
        cout << "Сумма любых трех сторон должна быть больше четвертой." << endl;
    }
    else {
        // Вычисления
        double perimeter = a + b + c + d;
        double area = (a + b) / 2.0 * h;
        double midline = (a + b) / 2.0;
        
        cout << "\nРезультаты вычислений:" << endl;
        cout << "  Периметр: " << perimeter << endl;
        cout << "  Площадь: " << area << endl;
        cout << "  Средняя линия: " << midline << endl;
        
        if (isIsosceles(c, d)) {
            cout << "  Трапеция равнобедренная" << endl;
        } else {
            cout << "  Трапеция неравнобедренная" << endl;
        }
    }
    
    return 0;
}
