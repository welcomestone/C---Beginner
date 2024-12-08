#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//函数指针      指针是用来代表内存地址的标识符  变量  数组等都可以储存在地址
 void test()        //打印数组的内存地址
 {
    int numbers[] = {1,2,3,4,5};
    cout<<hex<<(unsigned long long)numbers<<endl;

    int *ptr = numbers;     //用指针的形式
    cout<<hex<<(unsigned long long)ptr<<endl;

    //delete ptr;//此处错误 
 }

//函数指针
//          返回类型 （*函数指针名称）（参数列表）;       //申明方式
double multiply(double a, double b)
{
    return a*b;
}
double add(double a, double b)      //与上函数的接口形式一样
{
    return a+b;
}


double (*ptr)(double, double);      //声明

typedef double (*ptr22)(double, double);      // typedef 定义函数的别名     此时ptr22 不再是一个变量 ，而是一个类型别名 为了与指针区分 建议使用大写
typedef double (Ptr33)(double, double);       //没有指针的函数类型别名
void test1() {  
    // 赋值给先前声明的指针  
    ptr = multiply; // 使用 ptr 指向 multiply 函数  
    double res = ptr(1.3, 2.5); // 调用 multiply 函数  
    cout << res << endl; // 输出结果  

    double (*ptr11)(double, double) = multiply;     //声明          第一次初始化时是将函数指针赋值给指针    没有取地址符
    res = ptr11(1.3, 3.5); // 调用 multiply 函数  
    cout << res << endl; // 输出结果  

    res = (*ptr)(1.2,5.1);  //解引用的方式      若没有小括号  *ptr(1.2,5.1)   则实际执行的是  *(ptr(1.2,5.1))       是对结果解引用
    cout << res << endl; // 输出结果  

    ptr11 = &add;           //接口形式一样   可以将指针换指向另一哥函数     第二次初始化 ，是将函数add的地址赋值给指针      用了取地址符  两种方式都可以
    res = ptr11(2.3,1.8);   
    cout << res << endl; // 输出结果  

    //别名用法
    ptr22 ptr2 = multiply;      //ptr2是函数multiply的别名
    res = ptr2(1.3, 2.5); // 调用 multiply 函数  
    cout << res << endl; // 输出结果

    Ptr33* ptr3 = multiply;      //ptr3是函数multiply的别名
    res = ptr3(4,1); // 调用 multiply 函数  
    cout << res << endl; // 输出结果

    //使用auto  会自行判断类型      局限性在于只能在初始化单个变量时使用        当定义一个函数指针的数组时  无法使用auto
    auto funcPtr = add;      //ptr4是函数multiply的别名
    res = funcPtr(4.2,1); // 调用 add 函数  
    cout << res << endl; // 输出结果

    //auto Ptr[2] = {multiply,add};      //会产生语法错误 
    ptr22 Ptr[2] = {multiply,add};      //正确
    Ptr[0](4.2,1); // 调用 multiply 函数
}   
//应用场景      1、作为函数的参数  2、回电函数
bool compare(float a, float b) {
    return a < b;
}
//使用类重写
// 使用结构体重写比较  
struct Compare {  
    bool operator()(float a, float b) const { // 定义为可调用对象（仿函数）  
        return a < b; // 比较逻辑  
    }  
};  


void test2() {
    vector<float> numbers{1, 2, 3, 4, 5 ,0,-3 ,0,0.3,100,-13};
    sort(numbers.begin(), numbers.end(), compare);      //这样函数就可以使用传入的比较函数的指针来判断两个元素的大小

    for(auto i : numbers) {
        cout << i << " , ";
    }
    cout <<endl;
    sort(numbers.begin(), numbers.end(), Compare());        //结构体名可当做函数来使用
     for(auto i : numbers) {
        cout << i << " , ";
    }
}

//类成员函数指针
//              返回值类型 (类名::*成员函数指针名)(形参列表);
 class Democlass {
     public:
        double add(double a, double b){return a+b;}
        double multiply(double a, double b){return a*b;}
 };
void test3() {
    double (Democlass::*ptr)(double, double);
    ptr = Democlass::add;

    Democlass obj;
    double res = (obj.*ptr)(1.2,3.5);       
    cout << res << endl;

    Democlass* pobj;
    ptr = Democlass::multiply;
    res = (pobj->*ptr)(1.2,3.5);
    cout << res << endl;
}
//函数指针类继承
class BaseClass {
    public:
        virtual void print() {cout << "BaseClass" << endl;}
};
class DerivedClass : public BaseClass {
    public:
        void print() override {cout << "DerivedClass" << endl;}      //进行重写虚函数
};
void test4() {
    void (BaseClass::*ptr)() = BaseClass::print;

    BaseClass *pObj = new DerivedClass();
    (pObj->*ptr)();     //会调用DerivedClass重写的print函数

    delete pObj;
}


int main(void)
{
    test();
    test1();
    test2();
    test3();
    test4();
    return 0;
}