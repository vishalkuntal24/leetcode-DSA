class Solution {
public:
    int romanToInt(string s) 
    {
        int sum=0 ;
        int i=0 ;

        if(s.empty()) return 0 ;

        while(s[i+1]!='\0'&&s[i]!='\0')
        {
            if(s[i]=='I')
            {
                if(s[i+1]=='V') 
                {
                    sum += 4 ;
                    i++ ;
                }
               
                else if(s[i+1]=='X') 
                {
                    sum += 9 ;
                    i++ ;
                }
                else sum += 1 ;
            }

            else if(s[i]=='X')
            {
                if(s[i+1]=='L') 
                {
                    sum += 40 ;
                    i++ ;
                }
               
                else if(s[i+1]=='C') 
                {
                    sum += 90 ;
                    i++ ;
                }

                else sum += 10 ;
            }

            else if(s[i]=='C')
            {
                if(s[i+1]=='D') 
                {
                    sum += 400 ;
                    i++ ;
                }
               
                else if(s[i+1]=='M') 
                {
                    sum += 900 ;
                    i++ ;
                }
                else sum+=100 ;
            }

            else if(s[i]=='M') sum += 1000 ;
            else if(s[i]=='L') sum+=50 ;
            else if(s[i]=='V') sum+=5 ;
            else sum+=500 ;

            i++ ;
        }

        if(s[i]!='\0')
        {
                switch(s[i])
            {
                case 'I' :
                        sum+=1 ;
                        break ;

                case 'V' :
                        sum+=5 ;
                        break ;
                case 'X' :
                        sum+=10 ;
                        break ;

                case 'L' :
                        sum+=50 ;
                        break ;

                case 'C' :
                        sum+=100 ;
                        break ;

                case 'D' :
                        sum+=500 ;
                        break ;
                default : sum += 1000 ;
            }

        }
        
        return sum ;
    }
};