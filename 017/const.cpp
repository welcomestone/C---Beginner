#include <iostream>

using namespace std;
//const 成员函数        特性：不能修改成员变量
class ConstExmaple{
private:
    int m_a;
    int hello(){}
public:
    int calculate(int a,int b)  const;
};

int ConstExmaple::calculate(int a,int b)  const
{
    m_a++;      //错的  因为它修改了成员变量
    hello();    //错误  //const成员函数也不能调用非const成员函数        因为编译器会认为这个成员函数可能会修改成员变量
    return a+b;
}
//不能通过const类型的对象调用非const成员函数  例如  实验1



int main(void)
{
    const ConstExmaple obj;     //实验 1
    obj.calculate(1,2);     //OK

    obj.hello();            //错误          //总结：const类型的对象和const成员函数都不能使用非const成员变量及函数

    return 0;
}