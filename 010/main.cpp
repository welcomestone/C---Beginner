#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*    
//练习1
//输入一个英文句子 查有多少个单词
int main1(void)
{
    const int maxsize = 255;
    char english[maxsize];
    cout<<"请输入一个英文句子："<<endl;
    cin.getline(english,maxsize);

    char c;
    int i = 0;
    bool flag = false;
    int count = 0;
    while (c = english[i])
    {
        if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c=='-')
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                flag = false;
                count++;
            }
        }
        ++i;
    }
    if(flag)
    {
        count++;
    }
    cout<<"共有"<<count<<"个单词"<<endl;
    
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

    int count[26] = {};
    char c;
    int idx = 0;

    for(int i = 0;c= english[i];i++)
    {
        if(c>='a' && c<='z')
        {
            idx = c-'a';
        }
        else if(c>='A' && c<='Z')
        {
            idx = c-'A';
        }
        else
        {
            continue;
        }
        count[idx]++;
    }

    for(int i=0;i<26;i++)
    {
        if(count[i])
        {
            cout<<char('a'+i)<<":"<<count[i]<<endl;
        }
    }

    return 0;
}
  */
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