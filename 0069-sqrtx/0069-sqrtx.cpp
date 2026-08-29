class Solution {
public:
    int mySqrt(int x) 
    {
        int last=0 ;
        if(x==0) return 0 ;
        if(x==1) return 1 ;

        for(int i=1 ; i<=x/2 ; i++)
        {
            int sq=i*i ;

            if(sq<=x) last=i ;
            else break ;
        }

        return last ;
        
    }
};