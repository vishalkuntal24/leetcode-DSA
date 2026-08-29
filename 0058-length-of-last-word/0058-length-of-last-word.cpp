class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int i =0 ;
        int len=0 ;
        int count=0 ;

        while(s[i]!='\0')
        {
            if(s[i]!=' ') count++ ;
            else 
            {
                if(count!=0) len=count ;    // beech me 2 spaces aa gye then 
                count=0 ;
            }

            i++ ;
        }

        if(count!=0) len=count ;

        return len ;
        
    }
};