#include <iostream>

using namespace std;
//类型转换
//隐式转换
void test()     //基本类型的隐式转换
{
    int a = 2;
    float b = a;        //可能导致精度的降低

    double c = 3.5e39;
    b = c;
    cout<<b<<endl;      //这里b的职位无穷大 inf 因为浮点型的值域远小于双精度的值域范围
}
//类对象的隐式转换
class BaseClass{
protected:
    int m_a;
public:
    BaseClass():m_a(0){};
};
class SubClass:public BaseClass{
public:
    SubClass(){};
};


class ClassA{};
class ClassB{
protected:
    int m_a;
public:
    ClassB(const ClassA& a){}
};
void test1()     //lei的隐式转换
{
    SubClass * pSub = new SubClass();   
    BaseClass * pBase = pSub;           //将指向派生类的指针转换为基类的指针    要求是  相互转换的内容是兼容的

    //ClassB *pB = pSub;//错误  他们之间没有继承关系  或其他关系

    ClassA a;
    ClassB b = a;       //这里是正确的 与拷贝构造函数 相识   其实 拷贝构造函数 是 转换构造函数的一种特例

    delete pSub;
    //delete pBase;
    //delete *pB;
}

//显示转换
void test2()     //基本类型的显示转换
{
    int a = 2;
    float b = (float)a;        //或者  
          b = float(a);
}

/*
dynamic_cast        <转换类型>(表达式)      动态转换            只能用于 对 对象的指针 和 引用 的转换       完成多肽类 的转换  也就是 基类向 派生类的转换  也可向上转换
static_cast         <转换类型>(表达式)      静态转换
reinterpret_cast    <转换类型>(表达式)      重解释转换
const_cast          <转换类型>(表达式)      常量转换
*/

//dynamic cast
class CBase{
public:
    void echo(){cout<<"Base Class"<<endl;}

    virtual ~CBase(){}      //函数1
};

class CDerived:public CBase{
private:
    int m_value;
public:
    int getValue(){return m_value;};
};

void test3()     //基本类型的显示转换       派生类-->基类 是一定能成功的
{
    /*
    CDerived obj;
    CBase *ptr = dynamic_cast<CBase *>(&obj);       //1
    CBase& ref = dynamic_cast<CBase &>(obj);        //2
    ref.echo;
    delete *ptr;
    */
    //虽然  1 2 是可以成功的  但dynamic_cast的开销较大  不如以下的方式
    CDerived obj;
    CBase *ptr = (CBase *)&obj;       //1
    CBase& ref = (CBase &)obj;        //2
    ref.echo();
    delete ptr;
} 

//基类 --> 派生类
//dynamic_cast  会检查两次  分别是 编译时 和 运行时 
//编译时会检查被转换的基类是否是多态类 （多态类 --》 类中至少有一个虚函数） ，否则语法检查时会报错
void test4()
{
    CBase obj;
    CDerived *ptr = dynamic_cast<CDerived *>(&obj);     //若无函数1  错误  因为CBase 不是一个多态类 
                                                        //虽然没有语法错发 但运行时会动态检查 以保证真的是要转换的派生类对象
                                                        //此CBase中并没有CDerived的成员  所以并不能转换为CDerived 的对象 返回空指针
    if(!ptr)
        cout<<"无法将指针转换成CDerived";

    CBase *pobj = new CDerived();                       //指向派生类
    CDerived * ptr1 = dynamic_cast<CDerived *>(&obj);             //这样可以
    if(ptr1)
        cout<<"成功将指针转换成CDerived";

    delete ptr;
    delete ptr1;
    delete pobj;

    try{
        CDerived derive = dynamic_cast<CDerived &>(obj);     //若无法转换 会抛出
    }
    catch(bad_cast){
        cout<<"无法将对象转换成CDerived";
    }
}
//static_cast         <转换类型>(表达式)      静态转换      只在编译时检查      不需要是多态类   只需要保证两个要转换的类是兼容的
class COther{};

void test5()
{
    CBase *p;
    CDerived *p1;
    COther other;
    CDerived obj;

    p = static_cast<CBase*>(&obj);
    p1 = static_cast<CDerived*>(&obj);

    //p = static_cast<CBase*>(&other);      //错误
    //p1 = static_cast<CDerived*>(&other);  //cuowu 

    //所有的隐式转换都可以用静态转换来替代
    float m = 1.2;
    double n=m;

    n = static_cast<double>(m);

    ClassA a;
    ClassB b = a;
    b = static_cast<ClassB>(a);
}
//重解释转换
//reinterpret_cast    <转换类型>(表达式)      重解释转换        可以将一个类指针转换成另一个类指针 而不会检查转换的类是否有效
void test6()
{
    CBase *p;
    CDerived *p1;
    COther other;

    p1 = reinterpret_cast<CDerived*>(0xEFL);        //
    //long address = reinterpret_cast<long>(&other);  //编译时会出错  转换会丢失精度
    long long address = reinterpret_cast<long long>(&other);  //ok   二进制转换
}
//const_cast          <转换类型>(表达式)      常量转换  用于常量类型育肥场两类型之间的相互转换      转换的类型必须是指针或引用
int Hello(char* str)
{
    cout<<"hello, "<<str<<endl;
};
void test7()
{
    const char* str = "world!";     //传入的指针所指向的内存区域是不可修改的   所以传入后 也不可修改内容
    //Hello(str);//会报错

    Hello(const_cast<char*>(str));      //OK
}


int main(void)
{
    //test();
    //test1();
    test4();
    test5();
    test7();
    return 0;
}