#include <iostream>
#include <fstream>
#include "reflection.h"
#include "pretty_json.h"

using namespace std;
typedef struct mac1
{
  int a[5] = {1,2,3,4,5};
  char b;
  unsigned int c;
  float d;
}mac1;
REFLECTION(mac1,c,a,b,d);

typedef struct mac
{
  int a[10] = {1,2,3,4,5,6,7,8,9,0};
  char b;
  unsigned int c;
  float d;
  mac1 mc[2];
}mac;
REFLECTION(mac,c,a,b,d,mc);
//write to file
void write_txt(std::string &str)
{
  std::string write_file_name = {"./file.json"};
  ofstream os;
  os.open(write_file_name,ios::app);
  if (!os)
  {
    cout << "file open file!\n";
    return;
  }
  os << str;
  os.close();
}
int main()
{
  mac ma;
  ma.c = 45;
  std::string str;
  std::string pretty_str;

  to_json(ma,str);
  cout << str << endl;
  pretty_json(str);
  pretty_json_string(str, pretty_str);
  std::cout << pretty_str << endl;
  return 0;
}
