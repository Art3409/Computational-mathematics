#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double x = 0.6;
double xn = 1.6;   //Начальные условия для первой задачи
double y = 0.8;
double h = 0.1;

vector<vector<double>> results(2, vector<double>());    //Вектор для хранения результатов вычислений
                                                        //Его используют все три метода решений. После он очищается
                                                        //и вторично используется. Экологично!

//Функции из задания 1
double func(double x, double y)
{
    return x + sin(y / sqrt(10));
}

//Функция для обновления вектора для использования в новом методе
void startVector (vector<vector<double>> &res)
{
    res[0].clear();
    res[1].clear();
    res[0].push_back(x);
    res[1].push_back(y);
}
//Метод Рунге-Кутты

void RungeKutt(vector<vector<double>> &res, double x, double xn, double y)
{

    double K1;
    double K2;
    double K3;
    double K4;

    //по формуле высчитываем все остальные точки
    while (x <= xn)
    {
        K1 = func(x , y);
        K2 = func(x + h / 4.0, y + (h / 4.0) * K1);
        K3 = func(x + h / 2.0, y + (h / 2.0) * K2);
        K4 = func(x + h, y + h * K1 - 2.0 * h * K2 + 2.0 * h * K3);

        y = y + (h * (K1 + 2.0 * K2 + 2.0 * K3 + K4)) / 6.0;
        x += h;

        res[0].push_back(x);
        res[1].push_back(y);
    }
}

//Метод Эйлера

void Euler(vector<vector<double>> &res, double x, double xn, double y)
{

    //по формуле высчитываем все остальные точки
    while (x <= xn)
    {
        y = y + h * func(x, y);
        x += h;

        res[0].push_back(x);
        res[1].push_back(y);
    }
}

//Метод Эйлера с пересчётом

void EulerRecalculation(vector<vector<double>> &res, double x, double xn, double y)
{
    double recalculationY;

    //по формуле высчитываем все остальные точки
    int i = 1;
    while (x <= xn)
    {
        recalculationY = y + h * func(x, y);
        y = y + 0.5 * h * (func(x, y) + func(x, recalculationY));
        x += h;

        res[0].push_back(x);
        res[1].push_back(y);

        i++;
    }
}

//Функция вывода вектора в таблицу
void Print(const vector<vector<double>> &res)
{
    cout << "-------------------------\n";
    cout << "|     x     |     y     |\n";
    cout << "-------------------------\n";
    for (int i = 0; i < res[0].size(); i++)
    {
        cout << "|" << setw(11) << setprecision(5) << res[0][i] << "|" << setw(11) << setprecision(5) << res[1][i] << "|\n";
        cout << "-------------------------\n";
    }
}

int main()
{
    //Начальное заполнение вектора чтобы первому методу было с чем работать
    results[0].push_back(x);
    results[1].push_back(y);

    cout << "1)Euler method:\n";
    Euler(results, x, xn, y);
    Print(results);
    startVector(results);
    cout << '\n';

    cout << "2)Euler Recalculation method:\n";
    EulerRecalculation(results, x, xn, y);
    Print(results);
    startVector(results);
    cout << '\n';

    cout << "3)Runge-Kutt method:\n";
    RungeKutt(results, x, xn, y);
    Print(results);
    startVector(results);
    cout << '\n';

    return 0;
}
