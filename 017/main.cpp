#include <iostream>

using namespace std;

//类的静态成员 （static member）
class Demo
{
public:
    void cheer();
private:
    static unsigned int count;      //静态成员          相当于一个全局变量     
    unsigned int a; 
public: 
    static void hello();           //静态函数  
    static void hello1();           //静态函数        
};

//使用静态成员变量时 ，必须单独初始化 如
unsigned int Demo::count = 0;       
//                                      普通成员变量一般会在创建对象时在构造函数中赋初值

//对于静态成员函数 它与普通成员函数构造相同  不一样的是 ，在静态函数中只能访问静态成员，而不能访问非静态成员
//如：
void Demo::hello(){
    count++;        //OK
    a = 2;          //错误  a为非静态成员       这是因为非静态成员变量是依赖类的实例化成员而存在的
}

//但是
void Demo::hello1(){
    count++;
    Demo obj;       //实例化Demo
    obj.a = 2;      //这是对的
}

//在非静态成员函数中可以访问静态成员
void Demo::cheer(){
    count++;        //正确
    a = 2;          //正确
}

int main(void)
{
    //对成员进行访问
    Demo demo;          //OK
    demo.hello();       //OK
    Demo::hello();      //OK
    demo.count++;       //错误      count为非公有  不能在住函数中访问  在类中将Count改为public   则可以通过 类对象 或 者类名 访问   
                                    //需要注意的是 不管使用哪种方式访问静态成员变量  都是访问的同一个变量  只是访问的方式不同而已
                                    //在将count改为public之后 
                                    /*
                                        Demo demo;
                                        demo.count++;
                                        cout<<Demo::count;      //结果等于1
                                    */
    //必须遵循访问权限
    return 0;
}