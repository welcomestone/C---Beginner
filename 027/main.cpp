#include <iostream>
#include <vector>
#include <array>

using namespace std;
//STL标准模版库   容器（1）
 //常用容器
 /*
 array
 vector
 deque
 list           //前四个都是序列容器        可以按照顺序读取元素
 map
 set            //后两个是关联容器        通过键与值的映射来访问元素
 */
//              类名       动态分配的内存的类
//template <class T,class Alloc = allocator<T> > class vector;
void test()
{
    vector<int> ls = {1,5,2,3,5,6,9,8};
    vector<int> numbers{1,2,3,4,5,7,8};     //等价于vector<int> numbers({1,2,3,4,5,7,8});      这归功于 std::initializer_list

    //也可以使用单个元素来传递参数
    const int size = 5;
    float value = 3.0;
    vector<float> ls2(size,value);        //--->vector<float> ls2{3.0,3.0,3.0,3.0,3.0};
    //可以向数组一样可以使用下标访问元素
    //如果使用at()访问元素  如果下标越界  会抛出异常
    try
    {
        vector<int> ls3;
        for (int i = 0; i < 10; i++)
        {
            ls3.push_back(i);
        }
        ls3.at(10) = 200;           //访问越界  会抛出异常
    }
    catch(out_of_range& e)
    {
        std::cerr << e.what() << endl;
    }

    //容量
    vector<int> ls4;
    cout<<"大小\t容量"<<endl;
    for(int i = 0;i<10;i++)
    {
        ls4.push_back(i);
        //     当前的大小        当前的容量
        cout<<ls4.size()<<"\t"<<ls4.capacity()<<endl;
    }
}

//迭代器 iterator       所有的容器都有迭代器        vector的迭代器指向vector的地址  所以可以像使用指针一样使用迭代器
void test2()
{
    vector<int> ls = {1,5,2,3,5,6,9,8};
    vector<int>::iterator it ;          //定义了迭代器
    for (it = ls.begin();it!=ls.end();++it)         //
    {
        cout<<*it<<" ";     //可以用解引用来访问迭代器指向的元素
    }
    cout<<endl;
    
    for (it = ls.end()-1;it>=ls.begin();--it)
    {
        cout<<*it<<" ";     //可以用解引用来访问迭代器指向的元素
    }
    cout<<endl;

    //也可以使用反向迭代器
    vector<int>::reverse_iterator it2;
    for(it2 = ls.rbegin();it2!=ls.rend();++it2)
    {
        cout<<*it2<<" ";     //可以用解引用来访问迭代器指向的元素
    }
    cout<<endl;

    //通过指针来访问
    auto it3 = ls.begin();
    int *ptr = &(*it3);     //指针指向it3解引用的地址       也就是ls首元素的地址

    for (int i = 0; i < ls.size(); i++)
    {
        *ptr *=2;       //将元素乘以2
        ptr++;
    }

    for (auto n : ls)   
    {
        cout<<n<<" ";
    }
    cout<<endl;
}
//我们可以用insert和push_back来插入元素
//也可以用erase和pop_back来删除元素

//使用insert  可以在元素之前插入一个或者多个元素  如果插入的是单个元素 则返回值是新插入元素的迭代器  如果插入的是多个元素 则返回值是第一个新插入元素的迭代器
//使用push_back 则是在末尾添加一个元素 只能插入一个元素  返回值是新插入元素的迭代器
//使用erase  可以删除一个或者多个元素  如果删除的是单个元素 则返回值是下一个元素的迭代器  如果删除的是多个元素 则返回值是下一个元素的迭代器 
//使用pop_back  可以删除最后一个元素  返回值是前一个元素的迭代器

//插入元素还可以用 emplace  和 enplace_back         插入的对象必须有默认的构造函数
class Complex
{
protected:
    double m_i;
    double m_r;
public:
    Complex(double a,double b):m_i(a),m_r(b){cout<<"构造函数"<<endl;}
    Complex(const Complex& other):m_i(other.m_i),m_r(other.m_r){cout<<"拷贝构造函数"<<endl;}
};
void test3()
{
    vector<Complex> ls;
    //ls.emplace(ls.begin(),0.1,0.2);//插入一个Complex对象          相对insert来说效率更高

    //如果用insert来代替emplace  
    ls.insert(ls.begin(),Complex(0.1,0.2));

//迭代器的失效
    vector<int> numbers = {1,5,2,3,5,6,9,8};
    auto it = numbers.begin();
    numbers.erase(numbers.end()-1);         //加入这行将不会失效        代码 1
    cout<<"插入之前*it = "<<*it<<endl;
    auto it2 = numbers.insert(it,10);       //插入一个元素  返回值是下一个元素的迭代器
    cout<<"插入之后*it = "<<*it<<endl;      // 若没有代码 1 失效
    cout<<"插入之后*it2 = "<<*it2<<endl;
}


//template <typename T,std::size_t N > std::array;
//#include <array>
void test4()
{
    array<float,5> numbers = {1,2,3,4,5};
    for (int i = 0; i < numbers.size(); i++)
    {
        cout<<numbers[i]<<endl;
    }
}



//template <class T,class Alloc = allocator<T> > class deque;       可以在开头和结尾增加或删除数据 且效率最高   其他用法与vector一样
//#include <deque>

//不同的是 deque 的存储不是连续的  是由多组大小固定的内存块组成     扩容的e代驾要小于vector


//template <class T,class Alloc = allocator<T> > class list;        实现的方式是链表 不能像vector那样快速随机访问   只能顺序访问 
//它的迭代器只会在他指定的元素被删除时才会失效 ，其他情况的迭代器不会失效
//# include <list>

int main()
{
    test();
    test2();
    test3();
    test4();
    return 0;
}