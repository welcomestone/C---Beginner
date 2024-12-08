 #include <iostream>
 using namespace std;

//类的对象
//override 和 final限定符   c++11引用的     不是保留关键字，只有在特定情况下会被赋予特定的意义，在其他地方可以被用来命名  如实验 3中函数 的1 2 

//override  对父类函数进行重写
//final  则是表示该函数不能被子类重写

class BaseClase
{
public:
    virtual int DoSomeThing(int val)
    {
        cout<<"BaseClase::DoSomeThing("<<val<<")"<<endl;
        return val;
    }

    virtual void NoThing(int val){}
};

//也可以放在类名后面 ，这样这个类将不能被继承
class SubClaseA final : public BaseClase              //继承至  BaseClase
{
public:
    virtual void NoThing(int val)override final{}
};

class SubClaseB : public SubClaseA              //继承至  SubClaseA        错误，不能继承           
{
public:
    virtual void NoThing(int val){}              //这是错误的
};



/*
class SubClase : public BaseClase           //实验 1
{
public:
    virtual int DoSomeThing(int val)        //重写虚函数        按值传递
    {
        cout<<"SubClase::DoSomeThing("<<val<<")"<<endl;
        return val;
    }
};
*/
/*
class SubClase : public BaseClase           //实验 2
{
public:
    virtual int DoSomeThing(int& val)        //重写虚函数       引用    这就不是对基类中虚函数的改写了    在后加override时，编译器会崩我们检查出错误  如实验  3
    {
        cout<<"SubClase::DoSomeThing("<<val<<")"<<endl;
        return val;
    }
};
*/ 

class SubClase : public BaseClase           //实验 3
{
public:
    virtual int DoSomeThing(int& val) override        //重写虚函数       
    {
        cout<<"SubClase::DoSomeThing("<<val<<")"<<endl;
        return val;
    }
    void final(){}                      //1
    void override(){}                   //2
};


 int main(void)
 {
    BaseClase* pObj = new SubClase();
    int a = 10;
    pObj->DoSomeThing(a);

    delete pObj;
    return 0;
 }

//实验 1 结果打印  ：   SubClase::DoSomeThing(10)

//实验 2 结果打印  ：   BaseClase::DoSomeThing(10)

//实验 3 结果打印  ：   BaseClase::DoSomeThing(10)

