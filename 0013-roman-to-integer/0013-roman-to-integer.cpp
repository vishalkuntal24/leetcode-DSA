class Solution {
public:
    int romanToInt(string s) 
    {
        int sum=0 ;
        int i=0 ;

        static const unordered_map<char, int> map = 
        {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        while(s[i]!='\0')
        {
            if(s[i+1]!='\0')
            {
                if(map.at(s[i])<map.at(s[i+1])) sum-=map.at(s[i]) ;
                else sum+=map.at(s[i]) ;
            }
            else sum+=map.at(s[i]) ;
            i++ ;
        }

        return sum ;
    }
};