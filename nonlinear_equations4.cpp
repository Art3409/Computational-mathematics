#include <iostream>
#include <iomanip>
#include <cmath>
float func(float value)
{
    float answer;
    answer = value*value*value - (0.2*value*value) + (0.3 * value) - 1.2;
    return answer;
}

float gFunc(float x)
{
float g;
g = x - 0.5 * func(x);
return g;
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
"* Study work number 1. Task number 4.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    std::cout<< logo <<std::endl;
    std::cout<<"F(x)=x^3 - 0.2x^2 + 0.3x -1.2"<<std::endl;
    std::cout<<"g'(x)<1 on[1.0,2.0]"<<std::endl;
    std::cout << "|" << std::setw(12) << "   X(n)|"<< std::setw(20) << "    Func(X(n))|\n";
    float left=1.0, right=2.0, Xn=1.0, X1, X2;
    X1=1.0;
    while(Xn > 0.001){
        X2 = gFunc(X1);
        Xn = abc(X2 , X1);
        X1 = X2;
        std::cout << "|" << std::setw(11) << X1<<"|"<< std::setw(18) << Xn<< "|\n";
    }

    std::cout<<std::endl<<"x: "<<X2<<std::endl;
    return 0;
}