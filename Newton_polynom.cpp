#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Исходные данные
vector<vector<float>> coordinates = {
    {1.415, 0.888551},
    {1.420, 0.889599},
    {1.425, 0.890637},
    {1.430, 0.891667},
    {1.435, 0.892687},
    {1.440, 0.893698},
    {1.445, 0.894700},
    {1.450, 0.895693},
    {1.455, 0.896677},
    {1.460, 0.897653},
    {1.465, 0.898619}};

vector<float> argValue = {1.4179, 1.4633, 1.4124, 1.4655};

//Функция: возвращает факториал числа
int getFact(int n)
{
    int res = 1;

    while (n > 1)
    {
        res *= n;
        n--;
    }

    return res;
}

void NewtonPrint(vector<vector<float>> &coordinates, vector<float> &argValue)
{
    cout << '\n';

    cout << "|   x   |   y   |\n";

    for (int i = 0; i < coordinates.size(); i++)
    {
        cout << "|" << setw(7) << setprecision(5)
        << coordinates[i][0] << "|"
        << setw(7) << setprecision(5) << coordinates[i][1] << "|\n";
    }
    cout << "\n";

    cout << '\n';

    cout << " ";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "-------- ";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "   x" << i << "   |";
    }
    cout << '\n';

    cout << " ";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "-------- ";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << setw(8) << setprecision(5) << argValue[i]
        << "|";
    }
    cout << '\n';

    cout << " ";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "-------- ";
    }
    cout << '\n';

}

//Вывод конечных разностей в виде лестницы
void printNewton(vector<vector<float>> &finiteDifferences)
{
    for (int i = 0; i < finiteDifferences.size(); i++)
    {
        if (i < 9)
        {
            cout << "Difference  " << (i + 1) << " order: ";
        }
        else
        {
            cout << "Difference " << (i + 1) << " order: ";
        }

        for (int j = 0; j < finiteDifferences[i].size(); j++)
        {
            cout << "|" << setw(11) << setprecision(5) << finiteDifferences[i][j] << " ";
        }
        cout << '\n';
    }
}

//Вычисление приближенного значения функции при интерполяции
//вперед
float directInterpolation(float &t, vector<vector<float>> &coordinates, vector<vector<float>> &finiteDifferences)
{
    float res = 0.0;

    //К результату прибавляются y0 + t*dy0

    res += coordinates[0][1];
    res += t * finiteDifferences[0][0];

    //Вычисление членов
    for (int i = 1; i < finiteDifferences.size(); i++)
    {
        float temp = 1.0;

        //Промежуточные вычисления знаменателя
        for (int j = 1; j <= i; j++)
        {
            temp *= (t - j);
        }

        //К текущему результату добавляем член вида:
        //(t(t-1)..(t-n+1) * ΔnY0)/n!
        res += temp * t * finiteDifferences[i][0]
        / getFact((i + 1));
    }

    return res;
}

//Вычисление приближенного значения функции при интерполяции назад
float reverseInterpolation(float &t, vector<vector<float>> &coordinates, vector<vector<float>> &finiteDifferences)
{
    float res = 0.0;

    //К результату прибавляются yn + t*dy(n-1)
    res += coordinates[coordinates.size() - 1][1];
    res += t * finiteDifferences[0][(finiteDifferences[0].size() - 1)];

    //Вычисление членов
    for (int i = 1; i < finiteDifferences.size(); i++)
    {
        float temp = 1.0;

        //Промежуточные вычисления знаменателя
        for (int j = 1; j <= i; j++)
        {
            temp *= (t + j);
        }

        //К текущему результату добавляем член вида:
        //(t(t+1)..(t+n-1) * ΔnY(n-1))/n!
        res += t * temp * finiteDifferences[i][(finiteDifferences[i].size() - 1)] / getFact((i + 1));
    }

    return res;
}


int main()
{
    char logo[] =
"**********************************************\n"
"* Nizhny Novgorog State Technical University *\n"
"* Study work number 3. Task number 2.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    cout<< logo <<endl;
    vector<float> result;

    vector<vector<float>> finiteDifferences;

    NewtonPrint(coordinates, argValue);

    cout << '\n';
    //Хранение промежуточных значений
    vector<float> tempVector;

    for (int i = 0; i < coordinates.size() - 1; i++)
    {
        //Вычисление конечных разностей
        tempVector.push_back(coordinates[i + 1][1] - coordinates[i][1]);
    }

    finiteDifferences.push_back(tempVector);
    tempVector.clear();

    //На каждом iом шаге вычисляем значения конченых
    //разностей нового порядка
    for (int i = 0; i < coordinates.size() - 2; i++)
    {
        for (int j = 0; j < finiteDifferences[i].size() - 1; j++)
        {
            //Вычисление конечных разностей
            tempVector.push_back(finiteDifferences[i][j + 1] - finiteDifferences[i][j]);
        }
        finiteDifferences.push_back(tempVector);
        tempVector.clear();
    }

    printNewton(finiteDifferences);

    //Вычисление шага h
    float h = coordinates[1][0] - coordinates[0][0];

    float t;

    //Вычисление середины отрезка переданных X
    float midPoint = (coordinates[0][0] + coordinates[coordinates.size() - 1][0]) / 2;

    //Находим значения функции
    for (int k = 0; k < argValue.size(); k++)
    {
        //Если Xi лежит в промежутке [x0; (x0 + xn) / 2]
        if (argValue[k] < midPoint)
        {
            //t вычисляется как (x - x0)/h
            t = (argValue[k] - coordinates[0][0]) / h;

            //В список ответов заносим значение полученное при интерполяции вперед
            result.push_back(directInterpolation(t, coordinates, finiteDifferences));
        }
        //Иначе Xi лежит в промежутке [(x0 - xn)/2; xn]
        else
        {
            //t вычисляется как (x - xn)/h
            t = (argValue[k] - coordinates[coordinates.size() - 1][0]) / h;

            //В список ответов заносим значение полученное при интерполяции назад
            result.push_back(reverseInterpolation(t, coordinates, finiteDifferences));
        }
    }

    cout << '\n';

    cout << "Answer:\n";
    cout << "-------------------------------------\n";
    cout << "|   y1       y2       y3       y4   |\n";
    cout << "-------------------------------------\n";
    cout << "|" << setw(8) << setprecision(5) << result[0]
         << "|" << setw(8) << setprecision(5) << result[1]
         << "|" << setw(8) << setprecision(5) << result[2]
         << "|" << setw(8) << setprecision(5) << result[3] << "|" << '\n';
    cout << "\n";

    return 0;


}
