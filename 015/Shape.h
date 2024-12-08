#pragma once        //防止头文件被重复包含

#include <cmath>
using namespace std;

#define PI 3.1415926

class Shape     //图形基类
{
private:
    /* data */
public:
    virtual float area()=0;         //virtual  虚函数       面积
    virtual float permeter()=0;     //周长
    virtual ~Shape(){};
};



class Revtanggle : public Shape{        //正四边形  作为Shape的派生类
private:
    float m_width;
    float m_height;
public:
    virtual float area(){
        return m_height * m_width;
    }

    virtual float permeter(){
        return (m_height + m_width)*2;
    }

    Revtanggle(float width,float height){
        m_height = height;
        m_width = width;
    }
};

class Circle : public Shape{        //园形  作为Shape的派生类
private:
    float m_r;
public:
    virtual float area(){
        return PI * m_r * m_r;
    }

    virtual float permeter(){
        return PI*m_r*2;
    }

    Circle(float r){
        m_r = r;
    }
};

class Triangle : public Shape{        //三角形  作为Shape的派生类   
private:
    float m_a;
    float m_b;
    float m_c;
public:
    virtual float area(){
        //海伦公式
        float p = (m_a + m_b + m_c) * 2;
        return sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
    }

    virtual float permeter(){
        return m_a + m_b + m_c;
    }

    Triangle(float a,float b,float c){
        m_a = a;
        m_b = b;
        m_c = c;
    }
};
