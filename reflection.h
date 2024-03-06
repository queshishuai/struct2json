#include <string>
#include <iostream>

std::string str_render(char val)
{
  return std::to_string(val);
}
std::string str_render(unsigned char val)
{
  return std::to_string(val);
}
std::string str_render(int val)
{
  return std::to_string(val);
}
std::string str_render(unsigned int val)
{
  return std::to_string(val);
}
std::string str_render(float val)
{
  return std::to_string(val);
}
std::string str_render(double val)
{
  return std::to_string(val);
}

template <typename T>
std::string str_render(T &arr)
{
  std::string str;
  str.push_back('[');
  for (auto i:arr)
  {
    str.append(str_render(i));
    str.push_back(',');
  }
  str.pop_back();
  str.push_back(']');
  return str;
} 

#define COUT(o,mem) \
  s.push_back('"'); \
  s.append(#mem); \
  s.push_back('"'); \
  s.push_back(':'); \
  s.append(str_render(o.mem)); \
  s.push_back(',');

#define FUNC1(o,mem) COUT(o,mem) 
#define FUNC2(o,v1,v2) FUNC1(o,v1) FUNC1(o,v2)
#define FUNC3(o,v1,v2,v3) FUNC2(o,v1,v2) FUNC1(o,v3)
#define FUNC4(o,v1,v2,v3,v4) FUNC3(o,v1,v2,v3) FUNC1(o,v4)
#define FUNC5(o,v1,v2,v3,v4,v5) FUNC4(o,v1,v2,v3,v4) FUNC1(o,v5)

#define GET(_1,_2,_3,_4,_5,_6,NAME,...) NAME  

#define PASTE(...) GET(__VA_ARGS__,FUNC5,FUNC4,FUNC3,FUNC2,FUNC1,PLACEHOLDER) (__VA_ARGS__)

#define REFLECTION(struct_name,...)  \
std::string str_render(struct_name &m) \
{ \
  std::string s; \
  s.push_back('{'); \
  PASTE(m,__VA_ARGS__) \
  s.pop_back(); \
  s.push_back('}'); \
  return s; \
} 

template<typename T>
void to_json(T &t,std::string &str)
{
  str.append(str_render(t));
  return;
}

