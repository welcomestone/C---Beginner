#include <iostream>

using namespace std;
//模版 
//函数模版      只是描述了函数的外观，并不是真正定义了函数  编译器需要对模版进行实例化  才能成为真正的函数定义
template<class T>
void swap(T& a, T& b)       //函数模版
{
    T temp = a;
    a= b;
    b = temp;
}

//template<class 标识符1， class 标识符2，...>  函数声明；
//template<typename 标识符1， typename 标识符2，...>  函数声明；    typename与class并无区别

/*
template<class T>
T max(T a,T b)
{
    cout<<"mobanhanshu"<<endl;
    return a>b?a:b;
}
void test()
{
    int a=10;
    int b = 11;
    int c = max(a,b);   //此处可以省略<int>         

    float d = 12;
    float e = max<float>(a,d);  //此处不可省略 ，因为两个类型不一样 ，这样编译器会将a自动转换成float类型
    float f = max<float,int>(a,d);
}
*/

template<class T>  
T max(T a, T b)  
{  
    cout << "mobanhanshu" << endl;  
    return a > b ? a : b;  
}  

void test()  
{  
    int a = 10;  
    int b = 11;  
    int c = max(a, b); // 正确，类型推导为 int。  

    float d = 12;  
    float e = max<float>(a, d); // 正确，类型会自动推导为 float。  

    // float f = max<float, int>(a, d); // 错误，不需要指定这两个类型；可以忽略这一行。  
}  


//隐式实例化   编译器在需要的时候才生成对应的函数       通常将函数模版放在头文件中

//显示实例化
template float max<float>(float a,float b);     //在前加入了 template 关键字

//函数模版也可以进行重载

template<class T>
T max(T a,T b,int c)
{
    T temp = a>b?a:b;
    return c>temp?a:temp;
}

//函数模版特化  或者 专用化                 实例化也是特化的一种形式
template<>      //尖括号里没有参数
double max<double>(double a,double b)
{
    return a>b?a:b;
}
//当函数模版和重载函数同时存在时。调用函数又没有显示的指定末班函数参数  若果参数的类型与重载函数完全匹配  编译器会优先使用重载函数  反之优先使用模版实例化的模版函数
//如

float max(float a,float b)
{
    cout<<"chongzaihanshu"<<endl;
    return a>b?a:b;
}

void test1()
{
    float a = 10;
    float b = 12.2;
    int c = 12;
    max(a,b);           //会调用重载函数
    max<float>(a,b);    //会调用模版函数
    max(a,c);           //会调用模版函数
}

int main(void)
{

    return 0;
}