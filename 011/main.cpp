#include <iostream>

using namespace std;


//函数
//按值传递
int sum(int a)
{
    a++;
    return a;
}

//按引用传递
int inc(int &a)
{
    a++;
    return a;
}

//有默认值参数的函数
int demofun(int a,int b,int c=0,int d=0)
{
    int ret = (a*b)+c-d;
    return ret;
}
//不能这样定义函数
//int demofun1(int a,int b=0,int c,int d)       //需从右向左连续定义

int main(void)
{
    int num = 3;
    int res = 0;
    res = sum(num);     //num = 3,res = 4

    res = inc(num);     //num = 3,res = 4

    int rr = 0;
    rr = demofun(1,2);      //后两个值使用默认值
    rr = demofun(1,2,3);    //后一个值使用默认值
    rr = demofun(1,2,3,4);  //使用传递的值

    cout<<rr<<endl;
    return 0;
}