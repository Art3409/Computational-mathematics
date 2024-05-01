#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

//Функция из задания
float func(float x)
{
    return sin(x)/(x+1);
}

//Вторая производная функции
float secondDerivative(float x)
{
    return (cos(x)*x+1 - sin(x))/((x+1)*(x+1));
}

//Третья производная функции
float thirdDerivative(float x)
{
    return ((x+1)*(-sin(x)*(x+1)-cos(x))-cos(x)*(x+1)+2*sin(x))/((x+1)*(x+1)*(x+1));
}


using namespace std;

double a{0.18}, b{0.98};
int n1{8}, n2{20};
double h1{(b - a) / n1}, h2{(b - a) / n2};

//Векторы для решения в 8 итераций
vector<double> h1_x = {};
vector<double> h1_y = {};
vector<double> h1_x_1_2 = {};
vector<double> h1_y_1_2 = {};

//Векторы для решения в 20 итераций
vector<double> h2_x = {};
vector<double> h2_y = {};
vector<double> h2_x_1_2 = {};
vector<double> h2_y_1_2 = {};

//Метод решения по формуле центральных прямоугольников
double Rectangle(vector<double> &h_y_1_2, double h)
{
    double I{0.0};

    for (int i = 0; i < h_y_1_2.size(); i++)
    {
        I += h_y_1_2[i];
    }

    return I * h;
}


//Вычисление погрешности для метода центральных прямоугольников
double RectangleError(vector<double> &h_x, double h)
{
    double res, max(-1.0), temp;

    for (int i = 1; i < h_x.size(); i++)
    {
        temp = secondDerivative(h_x[i]);

        if (abs(temp) > max)
        {
            max = temp;
        }
    }

    res = ((b - a) / 24) * h * h * max;

    return res;
}

//Функция для получения решения и вывода таблиц
void GetSolution()
{
    double temp1{a};
    double temp2{a};
    int i1{0};
    int i2{0};

    cout << "---------------------------------------------------" << endl;
    cout << "|  i  |   x(i)   |   y(i)   | x(i)-0.5 | y(i)-0.5 |" << endl;
    cout << "---------------------------------------------------" << endl;
    do
    {
        h1_x.push_back(temp1);
        h1_y.push_back(func(temp1));
        temp1 += h1;
        if (i1 == 0)
        {
            h1_x_1_2.push_back(0.0);
            h1_y_1_2.push_back(0.0);
        }
        else
        {
            h1_x_1_2.push_back((h1_x[i1 - 1] + h1_x[i1]) / 2);
            h1_y_1_2.push_back(func(h1_x_1_2[i1]));
        }
        cout << "| " << setw(3) << i1 << " | " << setw(8) << h1_x[i1] << " | " << setw(8) << h1_y[i1] << " | " << setw(8) << h1_x_1_2[i1] << " | " << setw(8) << h1_y_1_2[i1] << " | " << endl;
        i1++;
    } while (temp1 <= b);
    cout << "--------------------------------------------------+" << endl
         << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "|  i  |   x(i)   |   y(i)   | x(i)-0.5 | y(i)-0.5 |" << endl;
    cout << "---------------------------------------------------" << endl;
    do
    {
        h2_x.push_back(temp2);
        h2_y.push_back(func(temp2));
        temp2 += h2;
        if (i2 == 0)
        {
            h2_x_1_2.push_back(0.0);
            h2_y_1_2.push_back(0.0);
        }
        else
        {
            h2_x_1_2.push_back((h2_x[i2 - 1] + h2_x[i2]) / 2);
            h2_y_1_2.push_back(func(h2_x_1_2[i2]));
        }
        cout << "| " << setw(3) << i2 << " | " << setw(8) << h2_x[i2] << " | " << setw(8) << h2_y[i2] << " | " << setw(8) << h2_x_1_2[i2] << " | " << setw(8) << h2_y_1_2[i2] << " | " << endl;
        i2++;
    } while (temp2 <= b);

    h2_x.push_back(temp2);
    h2_y.push_back(func(temp2));
    h2_x_1_2.push_back((h2_x[i2 - 1] + h2_x[i2]) / 2);
    h2_y_1_2.push_back(func(h2_x_1_2[i2]));
    cout << "| " << setw(3) << i2 << " | " << setw(8) << h2_x[i2] << " | " << setw(8) << h2_y[i2] << " | " << setw(8) << h2_x_1_2[i2] << " | " << setw(8) << h2_y_1_2[i2] << " | " << endl;
    cout << "---------------------------------------------------" << endl
         << endl;
}

int main()
{
    cout << "\n Central rectangles: \n";
    //Вызов функции получения решения
    GetSolution();

    //Расчёт значений интеграла и погрешностей
    cout << "Value for 8 steps: " << Rectangle(h1_y_1_2, h1) << '\n';
    cout << "Rectangle(8) error: " << RectangleError(h1_x, h1) << '\n' << '\n';
    cout << "Value for 20 steps: " << Rectangle(h2_y_1_2, h2) << '\n';
    cout << "Rectangle(20) error: " << RectangleError(h2_x, h2) << '\n' << '\n';

    return 0;
}
