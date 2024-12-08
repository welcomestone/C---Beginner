#include <iostream>

using namespace std;
//命名空间      --》主要作用就是解决名称的冲突

/*
namespace 标识符
{
    //类、对象、变量、函数等  
}; // namespace 标识符

*/
//c.cpp
namespace Mynamespace
{
    void foo(){
        cout<<"名称空间  Mynamespace的 foo"<<endl;
    }
} // namespace Mynamespace
//b.cpp
namespace Mynamespace
{
    int foo1(){
        return 3;
    }
} 
// namespace Mynamespace
//以上两个函数虽然在两个院内文件中定义了函数 ，但两个函数都是Mynamespace 空间中的函数
//使用
void test1()            //此函数没有在命名空间中  所以是全局命名空间
{
    Mynamespace::foo1();
    using Mynamespace::foo;          //在函数中使用using 此using的作用域只限于该函数test1（）       
    foo();
}

void foo()
{
    cout<<"全局foo"<<endl;
}
void test2()            
{
    using Mynamespace::foo;
    foo();  //会优先调用名称空间中的foo;
    ::foo();//会调用全局foo
}

int a=1;
namespace Mynamespace       //这里使用 using namespace Mynamespace 时可能会出错 cout<<"a="<<a<<endl;  时 会出错 因为 此时的a目标不明确
{
    int a= 2;
    namespace A
    {
        int a = 3;
    } // namespace A
    
} // namespace Mynam
void test3()            
{
    cout<<"::a = "<<::a<<endl;
    cout<<"Mynamespace::a = "<<Mynamespace::a<<endl;
    cout<<"Mynamespace::A::a = "<<Mynamespace::A::a<<endl;
}

int main(void)
{
    test1();
    test2();
    test3();
    return 0;
}