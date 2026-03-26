#include <iostream>
#include <cmath>      // sqrt
#include <iomanip>   
using namespace std;
//ahhahahha
double calculatePerimeter(double a, double b) {
    return  (a + b);
}

double calculateArea(double a, double b) {
    return a * b;
}

double calculateDiagonal(double a, double b) {
    return sqrt(a * a + b * b);
}

bool isValidSides(double a, double b) {
    return (a > 0 && b > 0);

}
void printRectangleParams(double a, double b) {
    cout << "Длина: " << fixed << setprecision(2) << a << " ед." << endl;
    cout << "Ширина: " << fixed << setprecision(2) << b << " ед." << endl;
    cout << "---------------------------------" << endl;
    cout << "Периметр: " << calculatePerimeter(a, b) << " ед." << endl;
    cout << "Площадь: " << calculateArea(a, b) << " кв. ед." << endl;
    cout << "Диагональ: " << calculateDiagonal(a, b) << " ед." << endl;

}
int main() {
    setlocale(LC_ALL, "Russian");  
    double length, width; 

    cout << "\nВведите длину прямоугольника: ";
    cin >> length;

    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    if (isValidSides(length, width)) {
        printRectangleParams(length, width);
    } else {
        cout << "ОШИБКА" << endl;
    }  
    return 0;
}

