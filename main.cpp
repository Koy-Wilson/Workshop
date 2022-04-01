#include <iostream>
using namespace std;

class String
{
    friend ostream& operator << (ostream& os, String& str);
protected:
    char* strArray;
    int size;
    void strCpy(char* first, char* second, int n);
    int strLen(char* input);
public:
    String();
    String(char* inpStr);
    String(String& inpStr);
    int Size();
    bool operator == (String& inpStr);
    bool operator > (String& inpStr);
    bool operator < (String& inpStr);
    String& operator = (String& inpStr);
    String& operator = (char* inpStr);
};

String::String()
{
    char* temp = new char[1];
    temp[0] = '\0';
    strArray = temp;
    size = 0;
}

String::String(String &inpStr)
{
    //TODO: FINISH WRITING THE CONSTRUCTOR FOR AN INPUT STRING
}

String::String(char *inpStr)
{
    size = strLen(inpStr);

    char* temp = new char[size];

    for(int index = 0; index < size; ++index)
    {
        temp[index] = inpStr[index];
    }

    strArray = temp;
}

int String::Size()
{
    return size;
}

int String::strLen(char *input)
{
    int index = 0;
    while(input[index] != '\0')
    {
        ++index;
    }
    ++index;
    return index;
}

ostream& operator << (ostream& os, String& str)
{
    for(int index = 0; index < str.Size(); ++index)
    {
        os << str.strArray[index];
    }

    return os;
}

void String::strCpy(char *first, char *second, int n)
{
    if(first != nullptr)
    {
        delete [] first;
    }

    char temp[n];
    for(int index = 0; index < n; ++index)
    {
        temp[index] = second[index];
    }

    first = temp;

}

int main() {

    char* test = "This is a test, please don't fail.";

    String first(test);
    String second(first);

    cout << second;
}
