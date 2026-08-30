class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size() ;
        
        unordered_map<int,int>map ;

        int counter=0 ;
        int pre_sum=0 ;

        map[0]=1 ;

        for (int i=0 ; i<n ; i++)
        {
            pre_sum+=nums[i] ;
            int remove=pre_sum-k ;
            
            counter+=map[remove] ;   //initially all random keys have default val as 0 ;
            map[pre_sum] ++ ;
        }
        
        return counter ;
        
    }
};