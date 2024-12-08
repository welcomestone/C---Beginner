#include <iostream>

using namespace std;

//this 指针         直接使用  （作为指针使用）this->member      (*this).member   (作为对象使用)

class Complex{
private:
    float r;
    float i;
public:
    Complex(float r,float i){
        this->r = r;        
        (*this).i = i;      //效果相同
    }
    Complex& add(const Complex& other){
        i+=other.i;
        r+=other.r;
        return *this;       //解引用
    }
    void print()const{
        cout<<r<<"+"<<i<<endl;
    }
};


//在子类中调用父类的函数
class BaseClass{
public:
    virtual void hello(){
        cout<<"Hello from Base"<<endl;
    };
};
class SubClass : public BaseClass{
public:
    void hello(){
        cout<<"Hello from Subclass"<<endl;
        BaseClass::hello();     //
    };
};

//友元  可以让其他类访问这个类的私有和保护成员
class B;

class A{
public:
    A():m_value(0){};
private:
    int m_value;
friend class B;     //将类B设为类A的友元   这样B就可以访问A的私有或保护成员了

friend int increase(A&);

};
class B{
public:
    int inc(A& obj)
    {
        obj.m_value++;
        return obj.m_value;
    }
};

int increase(A& obj)
{
    obj.m_value++;
    return obj.m_value;
}

int main(void)
{
    Complex a(1.0,2), b(2.3,-2), c(1.1,1.3);

    a.add(b).add(c);        //链式调用      等同于  Complex& temp = a.add(b); temp.add(c);
    a.print();
    return 0;
}