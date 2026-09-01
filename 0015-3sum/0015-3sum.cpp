class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size() ;
        int target=0 ;

        vector<vector<int>> ans ;
        sort(nums.begin(),nums.end()) ;

        for(int i=0 ; i<n ; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue ;  //make sure to rejects dupliactes of i as well 

            int j=i+1 ;
            int k=n-1 ;
 
            while(j<k)
            {
                long long sum=0 ;
                sum+=nums[i] ;
                sum+=nums[j] ;
                sum+=nums[k] ;
                
                if(sum<target) j++ ;
                else if(sum>target) k-- ;
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]} ;
                    ans.push_back(temp) ;
                    j++ ;
                    k-- ;
                    while(j<k && nums[j]==nums[j-1]) j++ ;
                    while(j<k && nums[k]==nums[k+1]) k-- ;   //here previous of k is k+1 ;;
                }
            }
        }

        return ans ;
        
    }
};