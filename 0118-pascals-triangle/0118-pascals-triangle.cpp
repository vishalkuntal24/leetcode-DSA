class Solution {
public:

    long long ncr(int n, int c)
    {
        long long val=1 ;
        for(int i=1 ; i<=c ; i++)
        {
            val=val*(n-i+1) ;
            val=val/i ;
        }

        return val ;
    }

    vector<int>generate_row(int n)
    {
        vector<int>temp ;
        temp.push_back(1) ;

        for(int c=1 ; c<n ; c++)
        {
            int val=ncr(n-1,c) ;
            temp.push_back(val) ;
        }

        return temp ; 
    }

    vector<vector<int>> generate(int numRows) 
    {
        int r=numRows ;
        vector<vector<int>>ans ;

        for(int i=1 ; i<=r ; i++)
        {
            ans.push_back(generate_row(i)) ;
        }

        return ans ;
        
    }
};