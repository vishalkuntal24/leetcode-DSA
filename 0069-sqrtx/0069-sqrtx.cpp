class Solution {
public:
    int mySqrt(int x) 
    {
        if(x==0) return 0 ;
        if(x==1) return 1 ;

        int low = 1 ;
        int high = x/2 ;

        while (low<=high)
        {
            int mid = low+(high-low)/2 ;
            long long sq = 1LL*mid*mid ;

            if(sq==x) return mid ;
            else if (sq<x)
            {
                low=mid+1 ;
            }
            else
            {
                high=mid-1 ;
            }
        }

        return high ;    //jb sqaure ki val x se kam aayii tohh meine low ko mid+1 kr diya but usi case me wo sq. x se jyada ho jaata hi .. thats why high ko return krna pdega .. yua fir last mid .. but that last mid is current high 
        
    }
};