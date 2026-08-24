class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        long long sum =0 ;
        long long mini = LONG_MIN ;

        for (int i=0 ; i<nums.size() ; i++)
        {
            sum=sum+nums[i] ;
            mini=max(mini,sum) ;

            if(sum<0)
            {
                sum=0 ;
            }

        }
        
        return mini ;
    }
};