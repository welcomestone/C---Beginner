#include <iostream> //ͷ�ļ�
using namespace std;
//输入数，判断奇偶数
int main(void)
{
     int a;
     cout<<"输入一个整数："<<endl;
     cin>>a;
     if(a&1)
        cout<<"这是一个基数"<<endl;
    else
        cout<<"这是一个偶数"<<endl;
    return 0;
}