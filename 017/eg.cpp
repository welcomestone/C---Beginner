#include <iostream>

using namespace std;
//类的静态使用 之一------》 单例（Singleton）----->一个类只能存在一个类对象
//例如：
class Singleton{                //该类不能被主动创建且只能存在一个实例对象
private:
    static Singleton* m_instance;
    Singleton() {}                  //将构造函数与析构函数改为私有成员  这样外部就不能在外部创建该类的实例化对象 或获得对象
    ~Singleton() { delete(m_instance);}

public:
    Singleton(const Singleton& obj) = delete;           //删除了拷贝构造函数        
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance(){                //只能通过调用该函数来获得该类对象
        if(!m_instance)
            m_instance = new Singleton();

        return m_instance;
    }
private:
    string m_name;
public:
    void setName(const string& name) {m_name = name;}

    const string& getName(){return m_name;}
};

Singleton* Singleton::m_instance = NULL;


//使用
int main(void)
{
    Singleton* s1 = Singleton::getInstance();
    s1->setName("hello");
    cout<<"s1 name = "<<s1->getName()<<endl;

    Singleton* s2 = Singleton::getInstance();   //此时s1与s2指向的是同一个实例对象
    cout<<"s2 name = "<<s2->getName()<<endl;
    s2->setName("nihao");
    cout<<"s1 name = "<<s1->getName()<<endl;
    cout<<"s2 name = "<<s2->getName()<<endl;

    return 0;
}