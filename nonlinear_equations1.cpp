#include <iostream>
#include <iomanip>
#include <cmath>
float func(float value)
{
    float answer;
    answer = value*value*value - (0.2*value*value) + (0.3 * value) - 1.2;
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
"* Study work number 1. Task number 1.        *\n"
"* Performed student 21-IVT-2 Kitov A. A.     *\n"
"**********************************************\n";
    std::cout<< logo <<std::endl;
    std::cout<<"F(x)=x^3 - 0.2x^2 + 0.3x -1.2"<<std::endl;
    std::cout << std::setw(16) << "left|" <<std::setw(16) <<"midle|" <<std::setw(16) << "right|"<< std::setw(16) << "f(left)|" << std::setw(16) << "f(right)|"<< std::setw(17) << "|xi+1-xi| "<<std::endl;
    float left=1.0, right=2.0;
    float midle;
    midle=(left+right)/2;
    float x=0;
    while((abc(left,right) - 0.001) > 0.0){
        midle=(left+right)/2;
        if(func(midle)*func(left)<0){
            std::cout << std::setw(15)<< std::setprecision(8) << left << "|"<<std::setw(15)<< std::setprecision(8) << midle << "|"<< std::setw(15) << std::setprecision(8) << right << "|"<< std::setw(15) << std::setprecision(8) << func(left) << "|"<< std::setw(15) << std::setprecision(8) << func(midle) << "|"<< std::setw(15) << std::setprecision(8) << midle-x << "|\n";
            x=midle;
            right=left;
            left=midle;
        }
        if(func(midle)*func(right)<0){
            std::cout << std::setw(15)<< std::setprecision(8) << left << "|"<<std::setw(15)<< std::setprecision(8) << midle << "|"<< std::setw(15) << std::setprecision(8) << right << "|"<< std::setw(15) << std::setprecision(8) << func(midle) << "|"<< std::setw(15) << std::setprecision(8) << func(right) << "|"<< std::setw(15) << std::setprecision(8) << midle-x << "|\n";
            x=midle;
            left=right;
            right=midle;
        }
    }
    return 0;
}