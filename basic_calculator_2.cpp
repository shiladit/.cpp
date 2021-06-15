#include <iostream>
#include <map>
#include <stack>
using namespace std;

map <char, int> priority;

int processtack(stack <int> &st)
{
    int answer = 0;

                while(!st.empty())
                {
                    int t= st.top();
                    st.pop();
                    
                    char op = st.top();
                    st.pop();
                    
                    int d = st.top();
                    st.pop();
                    
                    if(op == '-')
                        answer = d - t;
                    else if (op == '+')
                        answer = d + t;
                    else if (op == '*')
                        answer = d * t;
                    else if (op == '/')
                        answer = d / t;
                    
                    if(st.empty())
                        break;
                    else
                        st.push(answer);
                }

                return answer;
}

int calculate(string s)
{
    int last_priority = 0;
    
    priority['-'] = 1;
    priority['+'] = 2;
    priority['*'] = 3;
    priority['/'] = 4;
    
    stack <int> st;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
        {
            if(priority[s[i]] > last_priority)
            {
                last_priority = priority[s[i]];
                st.push(s[i]);
            }
            else
            {
                int answer;

                answer = processtack(st);

                st.push(answer);
                st.push(s[i]);
                last_priority = priority[s[i]];

            }
        }
        else
        {
            if(!isspace(s[i]))
                st.push(s[i] - 48);
        }
    }

    cout << processtack(st) << endl;
}

int main()
{
    string s;
    getline(cin,s);

    calculate(s);

    return 0;
}
