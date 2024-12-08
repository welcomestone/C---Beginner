#include <iostream>
#include <map>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;
//  容器（二—）
// map  映射        是STL中非常有用的一个模版       使用的方式  键值对
/*
template<
    class Key,      //键的类型
    class T,        //值的类型
    class Compare = std::less<Key>,     //用于比较元素的类
    class Allocator = std::allocator<std::pair<const Key, T>>   //内存分配类
> class map;        //使用复杂度为O(logN)的红黑树实现
*/
//例子
void test1()
{
    map<string , float> prices{{"01苹果",3.0},{"03橘子",5.0},{"02香蕉",2.0}};

    for(const auto& p:prices)   //输出内容是按照键的顺序进行排序
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    cout<<endl;

    //使用迭代器
    for(auto it=prices.cbegin();it!=prices.cend();it++)
        cout<<it->first<<" : "<<it->second<<endl;           //这里使用cbegin 返回的的是常量     而begin返回的是非常量迭代器  输出结果是一样的
    cout<<endl;

    //插入元素  使用下标运算符最简单 
    prices["04桃子"] = 4.5;     //如果这个键已经存在那就修改这个键的值 如果不存在那就插入这个键值对
    auto res = prices.insert((std::make_pair("06菠萝",6.0)));//插入一个键值对    返回的是迭代器   这里是使用了make_pair函数返回的迭代器  返回值第一项是插入的迭代器   第二项是bool类型   表示插入的是否成功
    for(const auto& p:prices)   //输出内容是按照键的顺序进行排序
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    cout<<endl;

    //删除元素
    int n = prices.erase("02香蕉");    //返回的是删除的元素的个数       若是该键值不存在 则返回为0
    cout<<"删除了"<<n<<"个元素"<<endl;
    for(const auto& p:prices)   //输出内容是按照键的顺序进行排序
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    cout<<endl;

    //查找元素
    auto it = prices.find("03橘子");    //返回的是迭代器
    if(it!=prices.end())
        cout<<"找到元素  "<<it->first<<" : "<<it->second<<endl;
    cout<<endl;

    //查找元素的范围
    map<float,string> prices2{{3.1f,"01苹果"},{5.5f,"03橘子"},{2.3f,"02香蕉"},{4.3f,"05桃子"},{6.5f,"07菠萝"}};
    auto upper = prices2.upper_bound(4.2f);      //找到所有小于等于4.2的商品
    
    for(auto it= prices2.begin();it!=upper;it++)
        cout<<it->first<<" : "<<it->second<<endl;
    cout<<endl;

    auto lower = prices2.lower_bound(4.2f);      //找到所有不小于等于4.2的商品
    
    for(auto it= lower;it!=prices2.end();it++)
        cout<<it->first<<" : "<<it->second<<endl;
    cout<<endl;

    //multimap用法
    multimap<float,string> prices3{{3.1f,"01苹果"},{5.5f,"03橘子"},{2.3f,"02香蕉"},{4.3f,"05桃子"},{4.3f,"07菠萝"}};
    prices3.insert({4.3f,"06菠萝"});     //插入一个键值对
    auto r = prices3.equal_range(4.3f);      //

    for(auto it=r.first;it!=r.second;it++)
        cout<<it->first<<" : "<<it->second<<endl;
    cout<<endl;

}
//map的查找 函数        map的键具有唯一性
/*
find
equal_range         //因为唯一性用处不大  
lower_bound         //返回的是迭代器是指向键值不小于所给定值的第一个元素
upper_bound         //返回的是迭代器是指向键值大于所给定值的第一个元素
count               //因为唯一性用处不大 
*/
/*
                          lower_bound（6.5） = "F"     upper_bound（6.5） = "G"

    键      1.0     2.1     3.2     4.3     5.4     6.5      7.6     8.7     9.8     10.9
    值      "A"     "B"     "C"     "D"     "E"     "F"      "G"     "H"     "I"     "J"
                                                  查找键为6.5
*/

//使用std::multimap  同样要包含头文件<map>      与map的区别在于可以有多个相同的键       (同一个键可以有多个值)


//std::set     无重复的 每个元素都是唯一的
/*
template <
  class Key, 
  class Compare = less<Key>, 
  class Allocator = allocator<Key> 
  >class set;
*/
//set 每个元素本身就是键值  与map一样都是使用红黑树实现的，因此很多特性都相同   
//不同的是   由于set没有键只有值 所以set没有重载下标运算符      也是使用compare类进行排序
void test2(void)
{
    set<string> s{"01苹果","02香蕉","03橘子","04橙子","05桃子","06菠萝","07菠萝"};
    for(auto it : s)
        cout<<it<<" ";    //输出内容是按照键的顺序进行排序的
    cout<<endl;

    unordered_set<string> s1{"01苹果","02香蕉","03橘子","04橙子","05桃子","06菠萝","07菠萝"};
    s1.insert("08菠萝");     //插入一个键值对
    s1.erase("07菠萝");      //删除一个键值对

    for(auto it : s1)
        cout<<it<<" ";    //输出内容是按照键的顺序进行排序的
    cout<<endl;
}

//std::unordered_set   无序集合    无序的  无重复的 每个元素都是唯一的      它的查找和插入速度比set快
//unordered_set是hash表实现的


int main(void)
{
    test1();
    test2();
    return 0;
}