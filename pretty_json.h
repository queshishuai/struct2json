#pragma once 
#include <iostream>
#include <string>
using namespace std;

/*pretty json format
@chenxin
@2024年3月12日
*/
void pretty_json(std::string &str)
{
  int indentation_length = 2;
  int offset = 0;
  std::string indent;
  for (size_t i = 0;i < str.size()-1;++i)
  {
    cout << str[i];
    switch(str[i])
    {
      case '{':
      case '[':
        offset = indentation_length;
        cout << '\n';
        indent.append(offset,' ');
        cout << indent;
        break;
      case '}':
      case ']':
        if (',' == str[i+1])
        {}
        else
        {
          offset = indentation_length;
          cout << '\n';
          indent.resize(indent.size() - offset);
          cout << indent;
        }
        break;
      case ',':
        cout << '\n';
        cout << indent;
        break;
      default:
        if ((']' == str[i+1]) || ('}' == str[i+1]))
        {
          offset = indentation_length;
          cout << '\n';
          indent.resize(indent.size() - offset);
          cout << indent;
        }
        break;
    }
  }
  cout << '}';
  return;
}