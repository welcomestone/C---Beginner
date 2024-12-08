#include <iostream>
#include <memory> // 包含智能指针

using namespace std;

//异常  （Eception）
/*
try  {}  //用于检查他大括号中的代码块所产生的异常
catch(type){}   //用来捕获和处理上诉代码块产生的异常
throw exception  //用于在try代码块 或 catch代码块中  用于抛出异常
*/

//上例子
float devide(float a,float b){
    if(b == 0)
        throw runtime_error(" Divided by zero!");       //异常类  描述异常
    return a/b;
}
void test()
{
    try{
        int c = devide(3.1,0);
        cout<<"c = "<<c<<endl;
    }
    catch(runtime_error& e){
        cout<<"exception: "<<e.what()<<endl;
    }
}
//throw
//捕获字符串指针
void test1()
{
    try{
        throw "这是一个字符串异常";
    }
    catch(const char* e){
        cout<<e<<endl;
    }
    try{
        throw 23;       //整型
    }
    catch(int e){
        cout<<e<<endl;
    }
}

//自定义类
struct my_exception
{
    string mess;
    unsigned int erroe;
};
void test2()
{
    try{
        throw my_exception{"my exception",1000};
    }
    catch(my_exception& e){
        cout<<e.mess<<":"<<e.erroe<<endl;
    }
}
//抛出函数指针
string exception_func()
{
    return "这是一个异常函数";
}
void test3()
{
    try{
        throw exception_func;
    }
    catch(string (*e)() ){
        cout<<e()<<endl;
    }
}
//自定义异常继承至标准异常类

struct my_exception1:public exception
{
private:
    string reason;
    unsigned int error_code;
public:
    my_exception1(const string& message,int code):reason(message),error_code(code){};
    virtual const char* what() const noexcept override                                  //重写what()
    {
        return reason.c_str();
    };
};
void test4()
{
    try{
        throw my_exception1("自定义异常",1000);
    }
    catch(my_exception1& e){            //1
        cout<<e.what()<<endl;
    }
    catch(my_exception1& e){       //同样能捕获到该类的子类抛出的异常   2          若将 1 放在 2 的后面 ，那么将不可能在到达派生类的处理中  也就不会执行 1 的异常处理
        cout<<e.what()<<endl;
    }
    //可以跟多个catch  当然 月专用的异常越放在前面处理 越通用的异常越放在后面处理  
    catch(...)              //处理未知异常的抛出  用 ... 代替   不建议捕获
    {
        cout<<"未知异常..."<<endl;
        throw;                      //将处理不了的异常再次抛出
    }     
}
//异常的内存问题
//对于自动创建的对象  在异常抛出时会自动清理该对象的内存
class MYResource
{
private:
    string m_name;
public:
    MYResource(const char* name):m_name(name){cout<<"MYResource Construct"<<m_name<<endl;};
    virtual ~MYResource(){cout<<"MYResource Destruct"<<m_name<<endl;};
};

void doSomething(){
    MYResource res("[doSomething]");        //在抛出后会被自动释放

    //MYResource * pres = new MYResource("[doSomething]");     //得处理该对象正确释放内存

    //正确处理   使用智能指针
    shared_ptr<MYResource> pRes( new MYResource("[doSomething]"));  //在抛出后会被自动释放内存      该方式叫 RAII（资源获取及初始化）

    cout<<"doSomething()"<<endl;
    throw runtime_error("doSomething error");
    //delete *pres;                               //抛出后并没有被释放    在此将delete放在 throw之前虽然可以释放 但实际情况可能更加复杂 比如如果在delete前有其他函数抛出时就不会释放
}
void test5()
{
    try{
        MYResource res("[main]");
        doSomething();
    }
    catch(runtime_error& e)
    {
        cout<<e.what()<<endl;
    }
}


int main(void)
{
    test();
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}