class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        map<int , int> mapp ;
        int n=nums.size() ;

        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]%2==0)
            {
                mapp[nums[i]] ++ ;
            }
        }  

        int max_count=0 ; int element=-1 ;
        for(const auto &[keys,freq]:mapp)
        {
            if(freq>max_count)
            {
                element=keys ;
                max_count=freq ;
            }
        }

        return element ;
    }
};