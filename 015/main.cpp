#include <iostream>
#include <vector>
#include "generator.h"

using namespace std;

//类
/*
class 类名称{
        成员变量0；         //默认 private
    public：                公共
        成员变量1；
        成员函数2（）；
    private:                私有
        成员变量3；
        成员函数4（）；
    protected:              继承
        c成员变量5；
        成员函数6（）；
}；
*/


int main(void)
{  
    vector<ShapeGenerator*> genlist{new RectangleGenerator(),
    new TriangleGenerator(),new CircleGenerator()};

    while (true)
    {
        cout<<"------------------------------"<<endl;
        cout<<"请选择要计算的图形 ";
        int i;
        for(i = 0;i<genlist.size();i++)
        {
            cout<<i<<":";
            cout<<genlist[i]->getShapeName();
            cout<<",";
        }

        cout<<i<<":"<<"退出";

        unsigned int choice;
        cin>>choice;
        if(choice == i)
        {
            return 0;
        }
        if(choice > i)
        {
            cout<<"没有这个选项，请重新选择";
        }

        Shape* pShape = genlist[choice]->createShape();
        float area = pShape->area();
        float perimeter = pShape->permeter();
        cout<<"面积="<<area<<"周长="<<perimeter<<endl;
        cout<<"------------------------------"<<endl;
    }
    

    return 0;
} 