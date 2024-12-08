#include <iostream> //头文件
using namespace std;//扩展名  使用命名空间std的标识符

/*
 @brief 
 @return 
*/
int main(void)
{
    int a,b;
    cout<<"请输入第一个数："<<endl;
    cin>>a;

    cout<<"请输入第二个数："<<endl;
    cin>>b;

    cout<<"两个数的和 = "<<a + b<<endl;
    cout<<"两个数的差 = "<<a - b<<endl;
    cout<<"两个数的积 = "<<a * b<<endl;
    cout<<"两个数的余 = "<<a % b<<endl;
    
    return 0;
}