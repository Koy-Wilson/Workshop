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
    strArray = new char[0];
    size = 0;
}

String::String(String &inpStr)
{
    size = strLen(inpStr.strArray);

    char* temp = new char[size];

    for(int index = 0; index < size; ++index)
    {
        temp[index] = inpStr.strArray[index];
    }

    strArray = temp;
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
    delete [] first;

    char temp[n];
    for(int index = 0; index < n; ++index)
    {
        temp[index] = second[index];
    }

    first = temp;

}

bool String::operator==(String &inpStr)
{
    if(strLen(inpStr.strArray) != strLen(this->strArray))
    {
        return false;
    }

    for(int index = 0; index < size; ++index)
    {
        if(inpStr.strArray[index] != strArray[index])
        {
            return false;
        }
    }

    return true;
}

String& String::operator=(String &inpStr)
{
    if(this == &inpStr)
        return *this;

    delete [] strArray;
    size = strLen(inpStr.strArray);

    char* temp;
    for(int index = 0; index < size; ++index)
    {
        temp[index] = inpStr.strArray[index];
    }

    strArray = temp;
    return *this;
}

String& String::operator=(char* inpStr)
{
    delete [] strArray;
    char* temp = new char[strLen(inpStr)];

    for(int index = 0; index < strLen(inpStr); ++index)
    {
        temp[index] = inpStr[index];
    }

    size = strLen(temp);
    strArray = new char[size];
    strArray = temp;
    return *this;
}

bool String::operator<(String &inpStr)
{
    if(this == &inpStr)
    {
        return false;
    }
    else
    {
        for(int index = 0; index < min(size, inpStr.size); ++index)
        {
            if(strArray[index] > inpStr.strArray[index])
            {
                return false;
            }
        }

        return true;
    }

}

bool String::operator>(String &inpStr)
{
    if(this == &inpStr)
    {
        return false;
    }
    else
    {
        for(int index = 0; index < min(size, inpStr.size); ++index)
        {
            if(strArray[index] < inpStr.strArray[index])
            {
                return false;
            }
        }

        return true;
    }
}

int main()
{

    return 0;
}
