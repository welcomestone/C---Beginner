#include <iostream>
using namespace std;


//宏        预处理指令      不会做语法检查
#define  MAX  100

//也可以没有值
#define  LARGE_ARRAY            //这样也是有意义的  常和以下一起用

#ifdef  LARGE_ARRAY
    #define MAX_SIZE  60
#else
    #define MAX_SIZE  20
#endif



#if  MAX_SIZE>50
    #undef MAX_SIZE                     //undef 取消原来的宏定义
    #define  MAX_SIZE       100         //重新定义
#else
    #undef MAX_SIZE
    #define  MAX_SIZE       15
#endif

//函数宏  （宏函数）
//#define 标识符（参数列表） 替换表达式
#define  MUL(a,b) a*b

#define  MUL1(a,b) (a)*(b)


//以上在C++中可以被内联函数所取代  可以更易调试也不容易错错
inline int mul(int a,int b){return a*b;}

void test()
{
    MUL(3,2);       //为3*2
    MUL(3,1+1);     //会被替换为 3*1+1

    MUL1(3,1+1);     //（3）*（1+1）
}

//#和##   在宏定义中常用的两个操作符

#define PRINT(a)  cout<<#a<<" = "<<(a)<<""         //编译器遇到  #a 时 会将 #a 替换为以字符串表示的参数a

void test2()
{
    float a = 3.0;
    PRINT(a*2+3);       //输出  ：  a*2+3 = 9
}

//##  连接符    将两个表达式连接到一起

#define MEMBER(type,a)  type m_##a

struct Demo{
    MEMBER(int,a);
    MEMBER(float,b);
};

//会被扩展为
/*
struct Demo{
    int m_a;
    float m_b;
};

*/

//若想使用多行的宏定义      需要使用  \  来连接

#define PROPERTY(Type,member) \
    private: \
        Type m_##member; \
    public: \
        const Type& get##member() const{return m_##member;} \
        void set##member(Type m){m_##member = m;}


class Example                   //此处用法并无卵用
{
    PROPERTY(int,Age)
    PROPERTY(string,name)
};
//展开
/*
class Example
{
private:
    int m_Age;
public:
    const int& getAge() const{return m_Age;}
    void setAge(int m)(m_Age = m)
private:
    string m_name;
public:
    const string& getAge() const{return m_name;}
    void setAge(string m)(m_name = m)
};
*/

//预定义宏      常用语调试语句
/*
标识符              类型            说明
__LINE__           整数             源文件行号
__FILE__           字符串           源文件文件名
__DATE__           字符串           编译日期
__TIME__           字符串           编译时间
__cplusplus        整数             编译器版本号
*/

void test3()
{
    cout<< "源文件："<<__FILE__ <<endl;
    cout<< "行号："<<__LINE__ <<endl;
    cout<< "编译开始于"<<__DATE__<<","<< __TIME__<<endl;
    cout<< "编译器的__cplusplus值是:"<<__cplusplus <<endl;
}
//输出
/*
源文件：E:\C++\C++ Beginner\020\mian.cpp
行号：118
编译开始于Dec  4 2024,19:24:17
编译器的__cplusplus值是:201703
*/

//可变参的宏函数
//          ... 使用 __VA_ARGS__来替代，预处理遇到这样的宏定义时 会将 VA_ARGS 用实际的参数替代
#define LOG(o,...)  fprintf(o,"[%s:%d]", __FILE__,__LINE__);\
                    fprintf(o,__VA_ARGS__)

void test4()
{
    LOG(stdout,"%s\n","测试信息;日志001");
    /*
    扩展：
    fprintf(stdout,"[%s:%d]", "E:\\C++\\C++ Beginner\\020\\mian.cpp",137); 
    fprintf(stdout,"%s\n","测试信息，日志001")
    */
}


int main(void)
{
    test3();
    test4();
    return 0;
}
