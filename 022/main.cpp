#include <iostream>
#include <vector>
#include <set>

using namespace std;
//模版 
//类模版
template<typename T>            //定义一个 类模版       使用和函数模版移植  
class Vector3
{
private:
    T m_vec[3];
public:
    Vector3(T v1, T v2, T v3){
        m_vec[0] = v1;
        m_vec[1] = v2;
        m_vec[2] = v3;
    };
    T getMax();
};
template<typename T>            
T Vector3<T>::getMax()          //定义与函数模版相似  只不过 多加了   类名<>::
{
    T temp = m_vec[0]>m_vec[1] ? m_vec[0]:m_vec[1];
    return temp>m_vec[2] ? temp:m_vec[2];
} 
 
void test1()
{
    cout<<"类模版使用！"<<endl;
    Vector3<int> vec1(1,2,3);
    Vector3<float> vec2(1.1,2.1,3.1);
    
    cout<<"<int> vec1  "<<vec1.getMax()<<endl;
    cout<<"<float> vec2  "<<vec2.getMax()<<endl;
}

//类模板的特化
template<>                  //尖括号里没有参数
class Vector3<char>         //尖括号里写要特化的类型
{
private:
    char m_vec[4];
public:
    Vector3(char v1, char v2, char v3){     //类定义里也要讲模板的参数换成实际的参数
        m_vec[0] = v1;
        m_vec[1] = v2;
        m_vec[2] = v3;
        m_vec[3] = 0;
    };
    const char* asString() const{
        return m_vec;
    };
};          //在特化类模板时， 原有类模版中的所有成员都要重新定义一遍才能使用       此特化中没有定义类模板的 getMax();函数 ，所以无法调用这个函数
            //也就是说 类模板的特化不能继承类模版的成员

void test2()
{
    cout<<"类模版的特化使用！"<<endl;
    Vector3<char> vecchar('a','b','c');
    
    cout<<"<char> vecchar  "<<vecchar.asString()<<endl;
    //vecchar.getMax();//错误

}

//对于模版有多个类型时，可部分特化  如
template<typename T1,typename T2>
class MyPair
{
private:
    T1 first;
    T2 second;
public:
    MyPair(T1 a,T2 b):first(a),second(b){};
    void print(){
        cout<<"通用类模版"<<endl;
    }
};
//部分特化模版
template<typename T2>
class MyPair<int,T2>
{
private:
    int first;
    T2 second;
public:
    MyPair(int a,T2 b):first(a),second(b){};
    void print(){
        cout<<"部分特化：MyPair<int,T2>"<<endl;
    }
};
//部分特化模版
template<typename T1>
class MyPair<T1,float>
{
private:
    T1 first;
    float second;
public:
    MyPair(T1 a,float b):first(a),second(b){};
    void print(){
        cout<<"部分特化：MyPair<T1,float>"<<endl;
    }
};
template<>       //特化 3
class MyPair<int,float>
{
private:
    int first;
    float second;
public:
    MyPair(int a,float b):first(a),second(b){};
    void print(){
        cout<<"部分特化：MyPair<int,float>"<<endl;
    }
};
//针对指针类型的特化
template<typename T1,typename T2>       //特化 3
class MyPair<T1*,T2*>
{
private:
    T1* first;
    T2* second;
public:
    MyPair(T1* a,T2* b):first(a),second(b){};
    void print(){
        cout<<"部分特化：MyPair<T1*,T2*>"<<endl;
    }
};

void test3()
{
    cout<<"类模版的部分特化使用！"<<endl;
    MyPair<int,double> partill(3,1.2);
    MyPair<double,float> partil2(1.2,1);
    
    partill.print();
    partil2.print();

    MyPair<int,float> partil3(1.2,1);       //编译器会无法区分 ，会报错     但在定义了特化3后就不会报错
    partil3.print();

    //MyPair<float*,float*> partil4(pA,pB);
    //partil4.print();
} 

//模版除了可以使用类型参数外，还可以使用非类型参数
//非类型参数包括  整型常量、枚举以及指针            而浮点数，变量以及用户定义的其他类型是不能作为非类型参数使用的
template<typename T,int N>      //T 是类型名  N 是整型常量          在使用这个模版时 ，N 只能是常量 不能是变量
class Vector4{
private:
    T m_values[N];              //N 可以用来定义数组的大小
public:
    Vector4(T values[N]){
        for(int i = 0;i<N;i++)
        {
            m_values[i] = values[i];
        }
    }
    T getMax(){
        T maxvalue = m_values[0];
        for(T v:m_values)
            maxvalue = maxvalue>v?maxvalue:v;
        return maxvalue;
    }
};
void test4()
{
    cout<<"非类型参数类模版使用！"<<endl;
    float values[5] = {1.0f,-0.3f,0.4f,0.5f,1.5f};
    Vector4<float,5> vector5(values);
    cout<<vector5.getMax()<<endl;

    const int n = 5;
    Vector4<float,n> vector6(values);   //正确

     int k = 5;
    //Vector4<float,k> vector7(values);   //错误
} 

//还可以给末班参数设置默认值
template<typename T = float,int N = 5>      //T 设置默认类型为float  N 设置默认值为5         在使用这个模版时 ，N 只能是常量 不能是变量
class Vector5{
private:
    T m_values[N];              //N 可以用来定义数组的大小
public:
    Vector5(T values[N]){
        for(int i = 0;i<N;i++)
        {
            m_values[i] = values[i];
        }
    }
    T getMax(){
        T maxvalue = m_values[0];
        for(T v:m_values)
            maxvalue = maxvalue>v?maxvalue:v;
        return maxvalue;
    }
};

void test5()
{
    cout<<"非类型参数类模版 设置默认值的使用！"<<endl;
    float values[5] = {1.0f,-0.3f,0.4f,0.5f,1.5f};
    Vector5<> vector5(values);          //此处省略了尖括号的内容
    cout<<vector5.getMax()<<endl;

    double values1[5] = {1.0f,-0.3f,0.4f,0.5f,1.5f};
    Vector5<double> vector6(values1);   //正确      这样定义了5个双精度的向量
} 

//类模板的参数还可以是模版
/** 
template<template <typename T>typename 参数名>
class 类名{
    ...
};
template<typename 参数名>
class 类名{
    ...
};
*/
template<template <typename> typename Container,typename T>
class Wrapper{
private:
    Container<T> m_values;
public:
    Wrapper(const Container<T>& o):m_values(o){}
    void print(){
        for(auto v : m_values) cout<<v<<endl;
    }
};
void test6()
{
    cout<<"非类型参数类模版 模版参数的使用！"<<endl;
    vector<int> ls = {1,5,2,3,5,6,9,8};
    Wrapper<vector,int> example(ls);
    example.print();

    set<int> ls1 = {1,5,2,3,5,6,9,8};
    Wrapper<set,int> example1(ls1);
    example1.print();

} 

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}