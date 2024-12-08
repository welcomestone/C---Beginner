#include <iostream>
using namespace std;

//结构体  联合  枚举  

//结构体        可当做特殊的类
struct Student      //定义
{
    char name[100];
    char id[10];
    short gender;
    time_t birthday;
}student4;                  //可在定义结构体的时候在末尾定义结构体成员      也可初始化如：  student4 = {"Tom","oo1",0,1};

    //使用
struct Student student3 = {"Tom","oo1",0,1};        //C语言中使用

Student student2 = {"Tom","oo1",0,1};               //c++中可省略struct

Student student1 = {};                              //成员都初始化为0；

//咋子C语言中 通常用typedef  来修饰结构体   如
typedef struct _Student{
    char name[100];
    char id[10];
    short gender;
    time_t birthday;
}StudentType;               //将struct _Student  定义为  StudentType 类型 ，这样就可以使用 StudentType 来定义变量了

StudentType student5 = {"Tom","oo1",0,1}; 
//访问对象的成员变量和访问类的额方式相同
void visit(void)
{
    cout<<student5.name<<endl;

    StudentType* pstudent6 = {"Tom","oo1",0,1}; 
    cout<<pstudent6->name<<endl;                //指针引用
    cout<<(*pstudent5).name<<endl;              //解引用    这里成员运算符.  优先级高于间接引用运算符*
}

//嵌套结构
struct Date{
    unsigned short year, mouth , day;
};

struct Class1{
    char name[100];
    char id[10];
    short gender;
    Date birthday;      //嵌套
};

//以上为C语言的结构     结构体的成员类型都为基本类型，可使用二进制直接储存或读取

int test_w(const char* fname)
{
    Class1 student6{"Tom","007",{2001,2,3},1};
    FILE* f = fopen(fname,"wb");
    fwrite(&student6,sizeof(student6),sizeof(char),f);          //写入二进制文件中
    fclose(f);
    return 0;
}
int test_r(const char* fname)
{
    Class1 student7 = {};
    FILE* f = fopen(fname,"rb");
    fread(&student7,sizeof(student7),sizeof(char),f);           //从二进制文件中读取
    fclose(f);

    cout<<student7.name<<","<<student7.id<<",";
    cout<<student7.birthday.year<<"-"<<student7.birthday.mouth<<"-"<<student7.birthday.day<<endl;
    return 0;
}

int main1(void)
{
    Class1* pstudent = new Class1({"Tom","001",0,1});
    test_w("test.bin");
    test_r("test.bin");
    return 0;
}
//但是，在C++中，若结构体成员类型出现了非基本类型  如 String 类型，则无法直接读取   如

struct Class2{
    string name;            //如此无法使用fread来恢复   得做一些转换  叫做  序列化（Serialize）
    char id[10];
    short gender;
    Date birthday;      //嵌套
};

//特殊用法
struct Header{                  //将一个字节或者整型按照比特位分成几部分  每一部分表示一个元素          通常用于面向底层
                                    //    |  7       6    |   5       4       3       2   |    1    |   0   |
    unsigned int flag:1;            //0   |   reserved    |               sn              |   sig   |  flag |
    unsigned int sig:1;             //1   |                               crc                               |
    unsigned int sn:4;              //2   |                                                                 |
    unsigned int reserved:2;        //3   |                                                                 |
    unsigned int crc:8              //
};      //:1 代表占用一个比特位     此结构体占用一个整型变量的大小

struct Header1{            //:1 代表占用一个比特位     此结构体占用一个整型变量的大小       
                                    //    |  7       6    |   5       4       3       2   |    1    |   0   |
    unsigned int flag:1;            //0   |                                                         |  flag |
    bool sig:1;                     //1   |                                                         |       |
    unsigned int sn:4;              //2   |                                                         |       |
    unsigned int reserved:2;        //3   |                                                         |       |
    unsigned int crc:8              //4   |                                                         |  sig  |
};                                  //5   |                                                         |       | 
                                    //6   |                                                         |       | 
                                    //7   |                                                         |       | 
                                    //8   |   crc         |   reserved   |              sn                  |
                                    //9   |               |                     crc                         |
                                    //10  |                                                                 |
                                    //11  |                                                                 |
                                    //所以应该用整型或者字符型大小对其的方式来定义比特位的结构

//带比特位的结构体和普通的结构体用法相同  只是需要注意每个元素的取值范围
int main2(void)
{
    Header head = {0};
    head = {1,1,15,3,255};          //元素的取值范围
    head.flag = 1;
}

//结构体中定义函数与类中定义函数的方式相同  

int main(void)
{

    return 0;
}