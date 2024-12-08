#include <iostream>
#include <vector>
using namespace std;

//运算符的重载
int test(void)
{
    int a = 3;
    a = a<<3;                   //此时的  <<  是 移位运算符

    cout<<"Hello,World";        //此时的  <<  是 插入运算符         这里是把  <<  作为一个函数  对这个函数进行重载  如展示1
    return 0;
}

//    返回类型 operator<<(参数1， 参数2)        展示 1
//    参数1 << 参数2

//一个运算符的重载   只能是不同的参数类型  而不能改变参数的数量     虽然重载的参数类型和返回值类型可以任意定义  但还是最好遵循内置运算符的特性      使其功能复合人的习惯

//    cout<<a<<b<<endl;     


//使用
//对  <<  进行重载
/**
 * ostream& o                       标准字符引用
 * const vector<int>& numbers       vector<int>  引用
 */
ostream& operator<<(ostream& o,const vector<int>& numbers){
    o<<"[";

    unsigned int last = numbers.size() - 1;
    for(int i = 0;i<last;i++)
        o<<numbers[i]<<",";
    o<<numbers[last]<<"]";
    return o;
}

int main(void)
{
    vector<int> numbers{1,2,3,4,5,7,8};
    cout<<numbers;        //若没有进行重载  则会报错，因为  <<  没有实现
    //上一条语句实际上是这条语句  
    operator<<(cout,numbers);       //调用了  <<  的重载函数
    return 0;
}

//以上是作为类外的非成员函数重载
//运算符也可以作为类的成员函数重载
class Complex{      //定义一个复数类
private:
    float r;
    float i;
public:
    Complex(float real,float imaginary):r(real),i(imaginary){};

    Complex operator+(const Complex& other)const{               //重载了加法运算符  +
        return Complex(this->r + other.r , this->i + other.i);
    }
    
    Complex operator+(float r)const{                            //重载了加法运算符  +   用于实现复数和浮点实数的加法   重载1 
        return Complex(this->r + r , this->i);
    }
    

    friend Complex operator+(float a, const Complex& b){       // 此处将友元函数写在类中  但该函数并不是该类的成员函数 而是类的外部函数 重载2
        return b + a;
    }
};

void test2()
{
    Complex a(0.1,2);
    Complex b(0.4,-2.5);
    Complex c = a + b;      //等效于 c = a.operator+(b);

    a = a + 1;      //定义了重载 1 后  可行 
    a = 1 + a;      // 重载1 无法实现浮点数加复数       此时需要重载内外的运算符函数        将重载1 改为重载2
}

//++或-- 重载
//前缀方式 ：  T operator++()           不需要参数
//后缀方式 ：  T operator++(int)        需要参数    (该参数仅起指示作用 用于区分前缀和后缀)
class ExampleClass
{
private:
    int m_a;

    //前缀增量运算符
    ExampleClass& operator++()
    {
        m_a++;
        return *this;
    }
    
    //后缀增量运算符
    ExampleClass operator++(int)
    {
        ExampleClass temp = *this;
        operator++();
        return temp;
    }
};


//以下只能作为成员函数重载的运算符
/*
赋值运算符  =
函数调用运算符  （）
间接引用运算符  ->          返回值必须是一个指针 或 一个对象 或 对象的引用   并且这个对象的间接引用符也被重载了
下标运算符      []
*/

//如函数调用运算符  （）
struct LinearFunction       //线性方程
{
    double k;
    double b;
    double operator()(double x)const{
        return k*x+b;
    }
};

void test3()
{
    LinearFunction f{1.5,3};
    cout<<"f(0) = "<<f(0)<<endl;
    cout<<"f(3) = "<<f(3)<<endl;
}

//间接引用运算符  -> 
struct Complex2{
    float r,i;
};

class LocalPtr{
private:
    Complex2* m_ptr;
public:
    LocalPtr(Complex2* p):m_ptr(p){}

    Complex2* operator->(){return m_ptr;}
    ~LocalPtr(){
        if(m_ptr)
            delete m_ptr;
    }
    //为了放在多个对象的m_ptr成员指向同一个地址     并在析构函数中释放同一块内存区域
    LocalPtr(const LocalPtr&) = delete;                 //删除了拷贝构造函数
    LocalPtr& operator=(const LocalPtr&) = delete;      //删除了 赋值运算符
};  

void test4()
{
    LocalPtr pComplex11(new Complex2({0.1,0.5}));
    pComplex11->i++;
}


//下标运算符      []    可以让对象像访问数组一样 访问其元素    可以是任意类型 

class Array{
private:
    vector<float> numbers;
public:
    Array(vector<float> n):numbers(n){};
    float operator[](int i)                 //重载了下标运算符   实现了Python的访问规则 下表为正时 正向访问  下表为负时 反向访问    即-1为最后一个元素
    {
        int size = numbers.size();
        assert(i<size && i>-size);

        if(i<0)
            return numbers[size+i];

        return numbers[i];
    }
};

void test5()
{
    Array arr(vector<float){1,2,3,4,5,6,7,8,9,10};

    cout<<arr[1]<<endl;         //正向      打印1
    cout<<arr[-1]<<endl;        //反向      打印10  
}

//类型转换运算符 
//  operator 转换类型();    返回值类型就是要转换的类型
class MyType{
public:
    float r;
    float i;

    MyType(float real,float imaginary):r(real),i(imaginary){};

    MyType operator+(const MyType& other)const{               //重载了加法运算符  +
        return MyType(this->r + other.r , this->i + other.i);
    }

    operator float() const{
        return r;
    }
};

void test6()
{
    MyType a(0.1,2);

    cout<<float(c)<<endl;        
}

//不能重载的运算符
/*
成员运算符  .
函数指针成员运算符  .*
域解析运算符 ::
三元运算符  ? =
sizeof
typeid
*/

//只包含基本类型（int ,float等）的类外运算符函数类外不能重载