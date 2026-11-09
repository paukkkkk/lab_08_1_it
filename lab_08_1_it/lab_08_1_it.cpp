#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


int Count(const char* str)
{
    if (strlen(str) < 3)           
        return 0;

    int k = 0;
    for (int i = 1; str[i + 1] != '\0'; i++)    
        if (str[i - 1] == ',' && str[i + 1] == '-')
            k++;
    return k;
}



char* Change(char* str)
{
    size_t len = strlen(str);
    char* tmp = new char[len + 1];  

    size_t i = 0;            
    size_t j = 0;                  
    while (i < len)
    {
        if (i + 2 < len && str[i] == ',' && str[i + 2] == '-')
        {
            tmp[j++] = '*';
            tmp[j++] = '*';
            i += 3;               
        }
        else
            tmp[j++] = str[i++];  
    }
    tmp[j] = '\0';

    strcpy(str, tmp);            
    return tmp;   
}


int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int k = Count(str);
    if (k > 0)
        cout << "String contained " << k << " groups of ', -'" << endl;
    else
        cout << "String contained no groups of ', -'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}