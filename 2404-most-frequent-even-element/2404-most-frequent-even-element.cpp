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

        int count=0 ;
        for(const auto &[keys,val] : mapp)
        {
            count=max(count,val) ;
        } 

        vector<int>temp ;

        for(const auto &[keys,val]: mapp)
        {
            if(val==count) temp.push_back(keys) ;
        } 

        if(temp.empty()) return -1 ;

        sort(temp.begin(),temp.end()) ;

        return temp[0] ;
    }
};