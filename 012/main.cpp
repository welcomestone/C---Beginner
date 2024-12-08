#include <iostream>

using namespace std;


//函数重载

float motyply(float a,float b)                  //1
{
    return a*b;
}

float motyply(float a,float b,float c)          //2
{
    return a*b*c;
}

int motyply(int a,int b)                        //3
{
    return a*b;
}

//以上3个函数都正确，在调用时，编译器会根据调用参数的类型来调用函数
/*
float motyply(float a,float b)                  //4
{
    return a*b;
}

int motyply(float a,float b)                    //5
{
    return a*b;
}
*/
//以上4和5不能重置 
/*
float motyply(float a,float b，float c= 1.2)                  //6
{
    return a*b;
}

float motyply(float a,float b)                              //7
{
    return a*b;
}
*/
//以上6和7不能重置 




//内联函数      定义时加关键字 inline   函数声明时不印象   短小且常用的函数用作内连   
inline float mutiply(float a,float b)   //在函数调用时会将函数主题在调用地方替换调用
{
    return a*b;
}
//复杂函数  for if else switch 及递归调用函数不能用在内敛



int main(void)
{

    return 0;
}