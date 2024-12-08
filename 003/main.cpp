#include <iostream> //头文件
using namespace std;

int main(void)
{
    int duration;

    cout<<"请输入以秒为单位的时长："<<endl;
    cin>>duration;

    int hours,minutes,seconds;
    hours = duration/3600;


    int r;
    r = duration%3600;
    minutes = r/60;
    seconds = r%60;

    cout<<"时长为 "<<hours<<"小时"<<minutes<<"分钟"<<seconds<<"秒"<<endl;
    return 0;
}