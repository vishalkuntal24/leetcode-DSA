class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size() ;
        int carry=1 ;
        int x ;

        for(int i=n-1 ; i>=0 ; i--)
        {
            x = digits[i]+carry ;
            carry=x/10 ;

            digits[i]=x%10 ;

            if(i==0 && carry!=0)
            {
                digits.insert(digits.begin(),carry) ;
            }
        }

        return digits ;
        
    }
};