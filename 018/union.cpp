#include <iostream>
using namespace std;

//联合 （union）
union MyUnionType{
    unsigned long l;                //占4个字节
    unsigned char c[8];             //8个字节
    struct{
        unsigned char i;
        unsigned char o;
        unsigned short v;
    }s;                           //4个字节
};
//联合在内存中所占的大小为成员类型中最大的一种所决定        在此   sizeof(MyUnionType)  等于 8
//联合在某一时刻只能使用其中的一种类型

int main(void)
{
    MyUnionType data1,data2,data3;
    data1.c[0] = 'a';
    data2.l = 0x3EUL;
    data3.s.i = 'f';

    MyUnionType data{};
    data.l =  0x3EUL;
    data.s = {'F','s',12};          //此时该语句会覆盖  data.l =  0x3EUL;   的结果

    return 0;
}