#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*      */
//练习1
//输入一个英文句子 查有多少个单词
int main1(void)
{
    const int maxsize = 255;
    char english[maxsize];
    cout<<"请输入一个英文句子："<<endl;
    //cin>>english; //只能得到第一个单词
    cin.getline(english,maxsize);

    int i = 1;
    //
    for(auto w : english)
    {
        if(w == ' ' )
        {
            //单词结束
            i++;
        }
        if(w == '\0')
            break;
    }
        cout<<i<<endl;

    return 0;
}

//练习2
//输入一个英文句子，查每一个字母出现的次数
int main2(void)
{
    const int maxsize = 255;
    char english[maxsize];
    cout<<"请输入一个英文句子："<<endl;
    cin.getline(english,maxsize);

    for(auto w : english)
    {
        if(w == '\0')
            break;
        
    }


    return 0;
}

//练习3
//对一个整数序列进行排序 ，用户输入序列个数
int main(void)
{
    vector<int> numbers;
    int num;
    cout<<"请输入要排序的整数，整数之间用空格分开："
          "输入；完成输入"<<endl;

    while (cin>>num)
    {
        numbers.push_back(num);
    }

    
    //排序
    for( int i = 0;i<numbers.size();i++) 
    {
        for(int j = i+1;j<numbers.size();j++)
        {
            if(numbers[i] > numbers[j])
            {
                int nums = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = nums;
            }
        }
    }

    // 输出排序后的结果  
    cout << "排序后：\n";  
    for (int number : numbers) {  
        cout << number << " "; // 使用范围for循环输出  
    }  
    cout << endl;  
    
    return 0;
}