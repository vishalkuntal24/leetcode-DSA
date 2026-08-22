class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size() ;
        
        int k=0 ;
        int j=-1 ;
        int i=-1 ;

        while(k<n)
        {
            if(nums[k]==0)
            {
                j=k ; break ;
            }
            k++ ;
        }
        i=j+1 ;
        if(j==-1||i==n) return ;

        while(i<n)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]) ;
                j++ ;
            }
            i++ ;
        }
    }
};