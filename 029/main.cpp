#include <iostream>
#include <functional>
#include <map>

using namespace std;
//STL标准模版库   函数封装与绑定    std::function  std::bind
//template<typename _Signature> class function;     //通用的多态函数封装器      这个在标准库中只做了申明    并没有定义

//常用的
/*
                        可变参数模板
template<typename R, typename ..._Args> 
class function<R(_Args...)>;
*/
//fname 是包装器对象的名字  target是要封装的目标函数指针或函数对象
//function<R(Args...)> fname = target;

double multiply(double a, double b)
{
    return a*b;
}

struct Linear
{   
    Linear(float k,float b):m_k(k),m_b(b){};
    float f(float x){return m_k*x+m_b;};
    float m_k,m_b;
};

void test()
{
    function<double(double, double)> fname = multiply;
    double res = fname(1.2, 3.5);
    cout << res << endl;

    function<float(Linear&,float)> fname2 = &Linear::f;     //封装类的成员函数
    Linear l(2,3);
    float res2 = fname2(l,5);
    cout << res2 << endl;

    function<float(Linear&)> k = &Linear::m_k;          //封装类的成员变量
    cout << k(l) << endl;               
}

//std::function     实现了 类型擦除模式 --》 可以使用单个通用接口来使用各种具体类型
//例子
float add(float a, float b)
{
    return a + b;
}    

struct Substract
{
    float operator()(float a, float b)
    {
        return a - b;
    }   
};

void test2()
{
    std::map<char,std::function<double(double,double)>> calculator{         //返回值是double   ，参数是double double
        {'+',add},
        {'-',Substract()},
        {'*',[](double a, double b)->double {return a*b;}}  //匿名函数   []用于捕获匿名函数中要使用的变量   ()里用于传入的参数  小括号后面箭头用于返回值的类型  {}则是实现的代码
    };

    cout << calculator['+'](1.2,3.5) << endl;
    cout << calculator['-'](1.2,2.5) << endl;
    cout << calculator['*'](3.2,3.5) << endl;
}
//可以通过function来将完全不同的类型按照同一个接口，也就是函数签名  统一封装成一个类型来使用    至于它封装的具体是什么类型就不必要了    以上就是类型擦除

//对于封装类的成员 则可以使用std::mem_fn 更加方便   它的参数是指向类成员的指针  返回值是一个可调用的包装器    
//template<class M,class T>
// /*unspecified*/mem_fn(M T::*p) noexcept; 
/*
struct Foo
{
    float w;
    float calculate(float a,float b){return w*a+b;};
    Foo& operator+=(float a){w+=a;return *this;};
    void print(){cout<<"w = "<<w<<endl;}
};
void test3()
{
    Foo f{1.3}; // 初始化 Foo 对象  

    auto memfn = std::mem_fn(&Foo::calculate);  //memfn是一个可调用的包装器
    float res = memfn(f,1.2,3.5);
    cout <<"res = " <<res << endl;

    auto op_add_assign = std::mem_fn(&Foo::operator+=);     //蹦定了类中的重载类符 加运算符
    auto f2 = op_add_assign(f,1.0);
    f2.print();
}
*/
struct Foo1 
{  
    float w;  

    // 添加构造函数，允许通过 double 初始化  
    Foo1(double value) : w(static_cast<float>(value)) {} // 使用 double 参数 
    // 计算函数  
    float calculate(float a, float b) { return w * a + b; }  

    // 加法赋值运算符  
    Foo1& operator+=(float a) {  
        w += a;  
        return *this; // 返回当前对象的引用  
    }  

    // 打印 w 的值  
    void print() { cout << "w = " << w << endl; }  
};  

void test3() 
{  
    Foo1 f{ 1.3 }; // 初始化 Foo 对象  

    // 使用 std::mem_fn 创建可调用的计算函数  
    auto memfn = std::mem_fn(&Foo1::calculate);  
    float res = memfn(f, 1.2, 3.5);  
    cout << "res = " << res << endl; // 纠正输出语法  

    // 使用 std::mem_fn 创建可调用的 operator+=  
    auto op_add_assign = std::mem_fn(&Foo1::operator+=);  
    op_add_assign(f, 1.0); // 直接对 f 进行操作  
    f.print(); // 打印更新后的结果  
}  

//std::bind  是一个函数模版  用来生成一个函数调用的转发包装器   也就是一个函数对象      调用这个包装器时就相当于调用它所包装的对象或者对象 f 并使用Args作为函数的参数
/*
template<typename F, typename... Args>
  bind(F&& f, Args&&... args);
*/
int sum(int a, int b, int c)
{
    std::cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
    return a + b + c;
}
void test4()
{
    auto f = std::bind(sum, 1, 2, 3);
    int res = f();
    std::cout<<" ,res = "<<res<<endl;

    using namespace std::placeholders;      //引入占位符    必须从_1开始
    auto f1 = std::bind(sum, 1, _1, 3);     //_1是占位符
    int res1 = f1(5);                            //3 会替代 占位符  _1
    std::cout<<" ,res = "<<res1<<endl;

    int n= 5;
    auto f2 = std::bind(sum, 1, 3, n);     
    n = 11;
    int res2 = f2();                            
    std::cout<<" ,res = "<<res2<<endl;      //输出  后 n任然是5，这是因为n是作为值传入的  

    int k = 6;
    auto f3 = std::bind(sum, 1, 3, std::cref(k));     //引用传递
    k = 11;
    int res3 = f3();                            
    std::cout<<" ,res = "<<res3<<endl;      //输出  后 k变成了11
}


int main(void)
{
    cout << "hello world" << endl;
    test();
    test2();
    test3();
    test4();
    return 0;
}