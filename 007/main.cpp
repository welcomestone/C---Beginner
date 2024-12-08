#include <iostream> 
#include <string>       //C++
#include <cstring>      //C

using namespace std;
//数组与向量  数组（Array）
int main(void)
{
    //将数组中所有元素初始化为0
    //float a[5] = {0};         //OK
    //float a[5] = {};          //OK


    //将数组中所有元素初始化
    //float a[] = {2.1,1.3,1.5,2.4,3.0，-1.2,2,14};         //OK
    //float a[8] = {2.1,1.3,1.5,2.4,3.0，-1.2,2,14};        //OK
    //float a[8]{2.1,1.3,1.5,2.4,3.0，-1.2,2,14};           //OK  C++方式

    //数组初始化
    //float a[5] = {2.1, 4.2};          //OK 只初始化前两个数

     //字符串和chart数组
     char hello[]="Hello";

     char word[20] = "Word";

     char nihao[] = {'n','i','h','a','o',0};//字符串数组结尾必加   0   =   '\0'

    char you[] = {'y','o','u'};         //没有 0 结尾，不能作为字符串使用 可以用在字符数组

    //在C语言中
    //数组比较
    //不能直接作比较   如  char a[2]={} , b[2]={} ; if(a==b){};      错误   因为if中数组名a,b表示的是两个数组的地址，而两个数组的地址不同
    
    //如何做比较呢，对数组元素进行1：1比较
    char name1[] = "zhangsan";
    char name2[] = "zhangsan";
    if(strcmp(name1,name2)== 0 )
    {
        cout<<"name1 与name2 相同"<<endl;
    }
    else
    {
        cout<<"name1 与name2 不同"<<endl;
    }

    //在C++中       #include <string>   using namespace std;
    string stone1("stone");
    string stone2("stone");

    if(stone1 == stone2)
    {
        cout<<"stone1 stone2 相同"<<endl;
    }
    else
    {
        cout<<"stone1 stone2 不同"<<endl;
    }


    return 0;
}