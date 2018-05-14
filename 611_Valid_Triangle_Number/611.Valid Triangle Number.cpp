#include <iostream>
#include <vector>
# include <algorithm>
using namespace std;
class Solution 
{

public: 
  int triangleNum_brute_force(vector<int>&nums)
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
  int binarySearch(vector<int>&nums,int l,int r,int x)
  {
      while(r >= l && r < nums.size())
      {
          int mid = (l+r)/2;
          if(nums[mid] >= x)
          {
              r = mid -1;
          }
          else 
          {
              l = mid + 1;
          }
      }
      return l;
  }
  int triangleNumber_binarysearch(vector<int> &nums)
  {
      //将数组按照从小到大的顺序排序
      //for i,j 选取j.然后判断 
      //nums[i] + nums[j] > nums[k] 的个数
      int count = 0;
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size()-2;++i)
      {
          int k = i+2;
          for (int j=i+1;j<nums.size()-1 && nums[i] !=0;++j)
          {
              k = binarySearch(nums,k,nums.size()-1,nums[i]+nums[j]);
              count += k - j -1;
          }
      }
      return count;
  }
  int triangleNumber_linear_scan(vector<int> &nums)
  {
      int count = 0;
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size()-2;++i)
      {
          int k = i+2;
          for (int j=i+1;j<nums.size()-1 && nums[i] !=0;++j)
          {
              while(k < nums.size() && nums[i] + nums[j] > nums[k])
              {
                  k++;
              }
              count += k - j -1;
          }
      }
      return count;
  }
//pass in leetcode
  int triangleNumber(vector<int>& nums) 
      {
        int ret = 0;
        if (nums.size() > 2) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++) {
                int j = i + 1;
                while (j < nums.size() - 1) {
                    int sum=nums[i] + nums[j];
                    int left=j+1, right=nums.size();   //right不能取nums.size()-1, 因为left=rigth+1 并且nums[left] 和nums[right] 同时满足条件时时，就无法取到right了 
                    if(sum>nums[left]){
                        while (left +1 < right ) {
                            int mid=(left+right)/2;

                            if(nums[mid]>=sum) right=mid;
                            else left=mid;
                        }
                        ret+=(left-j);
                    } 
                    j++;
                }
            }
        }
    return ret;
    }
};

int main()
{
    int a[19] = {16,24,29,6,48,24,44,27,7,6,17,51,37,19,23,0,20,42,49};

    int counttri;
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
    vector<int> b(a, a+19);
    Solution sol;
    //counttri = sol.triangleNum_brute_force(b);
    //counttri = sol.triangleNumber_binarysearch(b);
    //counttri = sol.triangleNumber_linear_scan(b);
    counttri = sol.triangleNumber(b);
    cout << counttri << endl;
}