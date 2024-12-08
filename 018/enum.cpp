#include <iostream>
using namespace std;

//枚举 （enum）
enum ColorType{
    Red,                //若没有定义值，则默认从 0 开始     
    Blue,
    Yellow,
    Green
};
/*
enum ColorType2{        //在使用时可能会导致编译错误    因为 他们都有  Red  Green
    Red = 1,                
    Black,
    White = 5,
    Green
};
*/

//为避免此类错误  C++中引用了有类的作用域的枚举
enum class ColorType3{
    Red,                
    Blue,
    Yellow,
    Green
};

enum class ColorType4{       
    Red = 1,                
    Black,
    White = 5,
    Green
};




int main(void)
{
    ColorType3 color;
    color = ColorType3::Red;        //使用时加上类名就可以分辨出是哪一个类的了

    //cout<<"color = "<<color<<endl;    //不能这样使用
    return 0;
}
