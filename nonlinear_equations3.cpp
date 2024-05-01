#include <iostream>
#include <iomanip>
#include <cmath>
float func(float value)
{
    float answer;
    answer = value*value*value - (0.2*value*value) + (0.3 * value) - 1.2;
    return answer;
}

float pr1(float value)
{
    float answer;
    answer = 3*value*value - (0.4*value) + (0.3);
    return answer;
}
float pr2(float value)
{
    float answer;
    answer = 6*value - (0.4);
    return answer;
}

float abc(float left, float right){
    float a;
    if(left>=right){
        a=left-right;
    }
    else{
        a=right-left;
    }
    return a;
}
int main()
{
    char logo[] =
"**********************************************\n"
"* Nizhny Novgorog State Technical University *\n"
"* Study work number 1. Task number 2.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    std::cout<< logo <<std::endl;
    std::cout<<"F(x)=x^3 - 0.2x^2 + 0.3x -1.2"<<std::endl;
    std::cout<<"F'(x)=3x^2 - 0.4x + 0.3"<<std::endl;
    std::cout<<"F"(x)=6x - 0.4"<<std::endl;
    float left=1.0, right=2.0, Xn, Xpr=0;
    if ((func(left) * pr2(left)) < 0.0)
    {
        std::cout << "Start point is left\n";
        std::cout << "|" << std::setw(12) << "   X(n)|"<< std::setw(20) << "    Func(X(n))|\n";
        Xn = left;
        //Поиск корня
        while (abc(func(Xn),0) > 0.001)
        {
            std::cout << "|" << std::setw(11) << Xn<<"|"<< std::setw(18) << abc(func(Xn),0)<< "|\n";
            Xn = Xn - ((func(Xn) / (func(right)- (func(Xn)))) * (right - Xn));
        }
    }
    if ((func(right) * pr2(right)) < 0.0)
    {
        std::cout << "Start point is right\n";
        std::cout << "|" << std::setw(12) << "   X(n)|"<< std::setw(20) << "    Func(X(n))|\n";
        Xn = right;
        //Поиск корня
        while (abs(func(Xn)) > 0.001)
        {
            std::cout << "|" << std::setw(11) << Xn<<"|"<< std::setw(18) << abc(func(Xn),0)<< "|\n";
            Xn = Xn - ((func(Xn) / (func(Xn)- (func(left)))) * (Xn - left));
        }
    }
    std::cout << "|" << std::setw(11) << Xn<<"|"<< std::setw(18) << abc(func(Xn),0)<< "|\n";
    std::cout<<std::endl<<"x: "<<Xn<<std::endl;
    return 0;
}
