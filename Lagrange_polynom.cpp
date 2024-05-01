#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Исходные данные

vector<vector<float>> coordinates = {
    {0.68, 0.80866},
    {0.73, 0.89492},
    {0.80, 1.02964},
    {0.88, 1.20966},
    {0.93, 1.34087},
    {0.99, 1.52368}};

vector<float> argValue = {0.812, 0.777};

void LagrangianPrint(vector<vector<float>> &coordinates, vector<float> &argValue, vector<float> &result)
{
    cout << '\n';
    cout << "+-------+-------+\n"
         << "|   x   |   y   |\n"
         << "+-------+-------+\n";

    for (int i = 0; i < coordinates.size(); i++)
    {
        cout << "|" << setw(7) << setprecision(5) << coordinates[i][0] << "|" << setw(7) << setprecision(5) << coordinates[i][1] << "|\n";
    }
    cout << "+-------+-------+\n";
    cout << '\n';
    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "   x" << i << "   |";
    }
    cout << '\n';

    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << setw(8) << setprecision(5) << argValue[i]
        << "|";
    }
    cout << '\n';

    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';

    cout << '\n';

    cout << "Answer:\n";

    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "   y" << i << "   |";
    }
    cout << '\n';

    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';

    cout << "|";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << setw(8) << setprecision(5) << result[i] << "|";
    }
    cout << '\n';

    cout << "+";
    for (int i = 0; i < argValue.size(); i++)
    {
        cout << "--------+";
    }
    cout << '\n';
}

int main()
{
    char logo[] =
"**********************************************\n"
"* Nizhny Novgorog State Technical University *\n"
"* Study work number 3. Task number 1.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    cout<< logo <<endl;
    vector<float> result;
    for (int k = 0; k < argValue.size(); k++)
    {
        float stepResult = 0.0;
        cout<<setw(13)<<"Y"<<"|"<<setw(12)<<"SUM"<<"|"<<setw(12)<<"yi"<<"|"<<endl;
        for (int i = 0; i < coordinates.size(); i++)
        {
            float temp = 1.0;

            for (int j = 0; j < coordinates.size(); j++)
            {
                if (i != j)
                {
                    temp *= (argValue[k] - coordinates[j][0]) / (coordinates[i][0] - coordinates[j][0]);
                }
            }

            stepResult += temp * coordinates[i][1];
            cout<<"|"<<setw(12)<<stepResult<<"|"<<setw(12)<<temp<<"|"<<setw(12)<<coordinates[i][1]<<"|"<<endl;
        }
        result.push_back(stepResult);
        cout<<k+1<<"-result: "<<stepResult<<endl;
    }

    LagrangianPrint(coordinates, argValue, result);
    return 0;

}
