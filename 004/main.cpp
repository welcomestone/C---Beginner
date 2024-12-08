#include <iostream> //ͷ�ļ�
using namespace std;

int main(void)
{
    int a,b;
    cout<<"输入第一个整数"<<endl;
    cin>>a;
    
    cout<<"输入第二个整数"<<endl;
    cin>>b;

    int avg = (a+b)/2;
    int max = a>b?a:b;

    //int res = (a%2)==(b%2) ? avg:max;
    int res = (a&1)==(b&1) ? avg:max;//遇上相等

    cout<<"结果是"<<res<<endl;
    return 0;
}