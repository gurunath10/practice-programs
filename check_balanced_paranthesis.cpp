#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

bool is_expected_brace(stack<char>& s, char cha)
{
    if(s.empty() || s.top() != cha)
    {
        return false;
    }
    s.pop();
    return true;
}
bool checkbrace(const string& str)
{
    stack<char>seq;
    for(const auto& ch: str)
    {
        switch(ch)
        {
            case '(':
               seq.push(')');
               break;
            case '{':
               seq.push('}');
               break;
            case '[':
               seq.push(']');
               break; 
            case ')':
               if(!is_expected_brace(seq, ch))
               {
                   return false;
               }
               break;
            case '}':
               if(!is_expected_brace(seq, ch))
               {
                   return false;
               }
               break;
            case ']':
               if(!is_expected_brace(seq, ch))
               {
                   return false;
               }
               break;
            default:
               continue;
        }
    }
    return true;
}
vector<string> braces(const vector<string>& values)
{
    vector<string>result;
    result.reserve(values.size());
    for(const auto& str: values)
    {
        if(checkbrace(str))
        {
            result.push_back("YES");
        }else{
            result.push_back("NO");
        }
    }
    return result;
}
int main() {
	int value_size;
	vector<string>values;
	cin>> value_size;
	for(int i =0; i<value_size; i++)
	{
	    string str;
	    cin>>str;
	    values.push_back(str);
	}
    std::vector<std::string> results = braces(values);
    for (const auto& element : results)
    {
        std::cout << element << " ";
    }
	return 0;
}