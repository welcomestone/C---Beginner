#include <iostream>

using namespace std;

//交换
void swap(int &a,int &b)
{
    a = a^b;                //a = a^b = 1^2
    b = a^b;                //b = a^b = 1^2^2 = 1
    a = a^b;                //a = a^b = 1^2^1 = 1^1^2 = 2
}

void swap(float &a,float &b)
{
    float ret = a;
    a = b;
    b = ret;
}

int main(void)
{
    int a = 1,b=2;
    float c=1.1,d=2.2;

    swap(a,b);
    swap(c,d);

    cout<<a<<","<<b<<endl;
    cout<<c<<","<<d<<endl;

    return 0;
}