class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size() ;
        int index=-1 ;

        int low=0 , high=n-1 ;

        while(low<=high)
        {
            int mid=low+(high-low)/2 ;
            if(nums[mid]==target) 
            {
                index=mid ;
                break ;
            }
            if(nums[mid]>target) high=mid-1 ;
            else low=mid+1 ;
        }

        return index ;
        
    }
};