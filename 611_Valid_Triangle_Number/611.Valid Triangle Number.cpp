#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public: 
  int triangleNum(vector<int>&nums)
  {
      //brute-force
      int count = 0;
      if(nums.size()<3)
      {
          return 0;
      }
      for(int i=0;i<nums.size()-2;++i)
      {
          for(int j= i+1;j< nums.size()-1;++j)
          {
              for(int k=j+1;k<nums.size();++k)
              {
                  if(nums[i] + nums[j] >nums[k] && nums[i] + nums[k] > nums[j] && nums[k] + nums[j] > nums[i])
                  {
                      count ++;
                  }
              }
          }
      }
      return count;
  }
};

int main()
{
    int a[19] = {16,24,29,6,48,24,44,27,7,6,17,51,37,19,23,0,20,42,49};

    int counttri;
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
    vector<int> b(a, a+19);
    Solution sol;
    counttri = sol.triangleNum(b);
    cout << counttri << endl;
}