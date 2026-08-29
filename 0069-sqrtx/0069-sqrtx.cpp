class Solution {
public:
    int mySqrt(int x) 
    {
        int last ;
        int sq_root ;
        if(x==0) return 0 ;
        if(x==1) return 1 ;

        int i=x/2 ;
        int start ;
        while(i>0)
        {
            long long sq = 1LL*i*i ;
            if(sq==x) return i ;
            else if(sq>x) last=i ;
            else 
            {
                start=i ;
                break ;
            }

            i=i/2 ;
        }

        for (int j=start ; j<=last ; j++)
        {
            long long y = 1LL*j*j ;
            if(y<=x) sq_root=j ;
            else break ;
        }

        return sq_root  ;
        
    }
};