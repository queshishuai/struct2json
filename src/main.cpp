#include <iostream>
#include <string>
#include <fstream>
#include "../inc/reflection.h"
#include "../inc/pretty_json.h"

/*自定义头文件*/

using namespace std;
/* for test */
typedef struct mac
{
    int a[2];
    char b;
    unsigned int c;
    float d;
    // mac1 mc;
} mac;
REFLECTION(mac, c, a, b, d);



// write to file
void write_txt(std::string &str)
{
    std::string write_file_name = {"./file.json"};
    ofstream os;
    os.open(write_file_name, ios::app);
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

    std::string str;
    std::string pretty_str;

    to_json(ma, str);
    cout << str << endl;
    pretty_json(str);
    pretty_json_string(str, pretty_str);
    std::cout << pretty_str << endl;

    return 0;
}