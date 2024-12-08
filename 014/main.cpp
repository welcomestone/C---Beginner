#include <iostream>

using namespace std;
//指针
//应用
//应用运算符&（取地址运算符）
/*
int a = 3;
int &b = a;
b++;
cout<<"a="<<a<<endl;        //此时a = 4
//用于函数中
//int swap(int &a,int &b);  
*/
//引用变量
/*
int numbers[] = {1,2,3,4,5,6,7,8};

for(auto n : numbers)       //方法1
{
    n++;
}

for(auto &n : numbers)       //方法2  加上&符
{
    n++;
}

for(auto n : numbers)
    cout<<" "<<n;            //使用方法1 -> 1 2 3 4 5 6 7 8  数组中的值并没有变化
                             //使用方法2 -> 2 3 4 5 6 7 8 9  数组中的值发生改变

*/

//常量应用
/*
int a = 3;
const int& b  = a;  //此时无法对 b 进行增量操作
b++;//此时错误，系统发报错
//用途
flaoat calculate(vector<float> values);     //按值传递    只是传递复制  会带来内存和运算的开销

flaoat calculate(vector<float>& values);    //应用  省去了复制  节省内存的使用  但可能会在函数中改变应用的数据

flaoat calculate(const vector<float>& values);  //表示这是一个只读的变量引用  函数中不会对引用数据修改
*/

//指针和地址
/*
char a = 'A';
char* p = &a;   //获得变量a的地址

*p = 'B';       //此时a = 'B'

int numbers[] = {0,1,2,3,4,5,6,7};
int *p = numbers;   //也可以这样写  int *p = (int*)&numbers;    效果也是一样的
p[3] = p[2]*2;   //此时numbers[3] = 4;

p++;
cout<<*p;   //输出1， int占4个字节 p++每次向上加4个字节  此时 *p  = numbers[1] ,也就是第二个值 1

cout<<*(p+3)//输出4 ，注意，对指针的操作不能越界，不能超过数组的范围，否则会导致程序异常
*/

/*
int numbers[] = {0,1,2,3,4,5,6,7};
int *p = (int*)&numbers; 
char* pChar = (char*)p;

p++;
pChar++;

cout<<hex<<(long long)p<<endl;          //输出  0x5ffe74        这是因为 int 占用 4 字节 ，p++ 一次 加4字节     按类型的大小对内存的增加
cout<<hex<<(long long)pChar<<endl;      //输出  0x5ffe71        这是因为 chart 占用 1 字节 ，p++ 一次 加1字节
*/
//new运算符    动态分配内存     在函数退出后，内存任然存在
/*
char*  p1 = new char;                   //动态分配char类型内存 p1的值未知
int*   p2 = new int(2) ;                //动态分配int类型内存 p2的值为2
char*  p3 = new char[5];                //动态分配char数组类型内存 p3的大小为5，数组中的值未知
char*  p4 = new char[5]{1,2,3,4,5};     //动态分配char数组类型内存 p4的大小为5，数组中的值{1,2,3,4,5}

//delete 运算符
delete p1;
delete p2;
delete []p3;    //数组
delete []p4;
*/

//常量指针
/*
int a = 13;
const int *p3 = &a; //或
const int *p3 = (const int*)&a;

*p3 = 4;//错误，系统会异常报错 

const int a = 11;
const int *p3 = &a; 
int *p3 = &a;       //错误  不能使用普通指针指向常量
*/

//指针常量
/*
int a[] = {13,12,11,10};
int* const p = a;

p[0] = 100; //OK
*p = 101;   //OK

p++;//错误，p存的是数组a的地址作为常量 不能被改变
*/

//智能指针
/*
#include <memory>

shared_ptr<int> pInt(new int(2));   //智能分配一个指针 pInt 在不使用时会自动销毁
cout<<*pInt;    //可像一般指针一样使用
*/



int main(void)
{  
    return 0;
} 