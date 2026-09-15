class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int preproduct=1 ;
        int sufproduct=1 ;

        int maxi=INT_MIN ;

        for(int i=0 ; i<nums.size() ; i++)
        {      
            preproduct*=nums[i] ;
            maxi=max(preproduct,maxi) ;
            if(preproduct==0) preproduct=1 ;
        }

        for(int i=nums.size()-1 ; i>=0 ; i--)
        {
            sufproduct*=nums[i] ;
            maxi=max(sufproduct,maxi) ;
            if(sufproduct==0) sufproduct=1 ;
        }
        
        return maxi ;
    }
};