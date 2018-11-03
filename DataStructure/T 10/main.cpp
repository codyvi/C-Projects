#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, string> PhoneList;
    while(n--)
    {
        string funct, name, number;

        cin >> funct;

        if(funct == "add")
        {
            cin >> name;
            cin >> number;

            PhoneList[name] = number;
        }

        else if(funct == "find")
        {
            cin >> number;
            auto it = PhoneList.find(number);
            if (it == PhoneList.end())
            {
                cout << "not found" << endl;
            }
            else
            {
                cout << it->second << endl;
            }
        }

        else if(funct == "del")
        {
            cin >> number;
            auto it = PhoneList.find(number);
            if(it == PhoneList.end())
            {
                //Do nothing
            }
            else
            {
               PhoneList.erase(it);
            }

        }
    }

    return 0;
}

