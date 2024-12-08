#include <iostream> 
#include <vector>
using namespace std;
//向量 vector
int main(void)
{
    vector<float> nums = {1.1,2.3,3.7};
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(auto w:nums)
    {
        cout<<w<<",";
    }
    
    return 0;
}