#pragma once
#include "Shape.h"

class ShapeGenerator{       //图形工厂类
protected:
    string m_shapeName;
public:
    virtual Shape* createShape() = 0;
    const string& getShapeName(){
        return m_shapeName;
    }
};


class RectangleGenerator : public ShapeGenerator{
public:
    RectangleGenerator(){
        m_shapeName = "长方形";
    }

    virtual Shape* createShape(){
        float width,height;
        cout<<"请输入长方形的宽：";
        cin>>width;
        cout<<"请输入长方形的高：";
        cin>>height;

        return new Revtanggle(width,height);
    }
};

class CircleGenerator : public ShapeGenerator{
public:
    CircleGenerator(){
        m_shapeName = "圆形";
    }

    virtual Shape* createShape(){
        float r;
        cout<<"请输入圆的半径：";
        cin>>r;

        return new Circle(r);
    }
};

class TriangleGenerator : public ShapeGenerator{
public:
    TriangleGenerator(){
        m_shapeName = "三角形";
    }

    virtual Shape* createShape(){
        float a,b,c;
        cout<<"请输入三角形的第一条边：";
        cin>>a;
        cout<<"请输入三角形的第二条边：";
        cin>>b;
        cout<<"请输入三角形的第三条边：";
        cin>>c;

        return new Triangle(a,b,c);
    }
};