class Solution {
public:
    
     
 bool isMatched(char a, char b)
    {
        return(a=='(' && b==')'||
               a=='{' && b=='}'||
               a=='[' && b==']');

    }

bool isValid(string & str)
{
stack<char> s;

    for(char x:str)
    {
        if(x == '(' || x=='[' || x=='{')
        {
        s.push(x);
        }
    else
    {
        if(s.empty()==true)
        return false;

        if(isMatched(s.top(),x)==false)
        {
            return false;
        }
        else
            s.pop();
    }
    }
            return (s.empty()==true);
    
   
}
   
    
};