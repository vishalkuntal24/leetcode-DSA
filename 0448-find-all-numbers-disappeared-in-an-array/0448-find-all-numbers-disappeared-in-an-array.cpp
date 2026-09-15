class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<int> hashArr(n+1,0) ;

        vector<int> ans ;

        for (int i=0 ; i<n ; i++)
        {
            hashArr[nums[i]] ++ ;
        }

        for(int i=1 ; i<=n ; i++)
        {
            if(hashArr[i]==0) ans.push_back(i) ;
        }

        return ans ;
        
    }
};