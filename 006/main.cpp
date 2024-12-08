#include <iostream> 
using namespace std;
//循环用法
int main(void)
{
    int i =0;
    for(;i<0;i++){/**循环体代码 */}     //OK

    int ii,j;
    for(ii = 1,j = 10;i<0;ii++,j--){/**循环体代码 */}     //OK

    for(;;){/**循环体代码 */break; continue;}     //OK  break:跳出循环  continue：跳过该次循环

    int n = 10;
    while（n>0）
    {
        n--;
    }

    int k = 10;
    do
    {
        /* code */
        --k;
    } while (k>0);  //注意分号



//  C++标准
    //for(元素：范围)
    //{}
    int numbers[] = {1,2,3,4,5,6,7,8,};
    for(auto number : numbers)
    {
        cout<<number<<endl;
    }
    

    return 0;
}