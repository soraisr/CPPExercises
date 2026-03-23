#include <iostream>
#include "MyStringClass.h"


int main()
{
    MyString str1("Why do birds suddenly appear?");
    MyString str2("Everytime you are near");
    MyString str3("deli");
    MyString str4;

    str1.append("??");
    str1.append(str4.getCString());
    std::cout << str1.getCString() << std::endl;

    std::cout << "Meow\n" << std::endl;
    return 0;
}

