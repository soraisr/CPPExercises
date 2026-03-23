#include <iostream>
#include <cassert>
#include "MyStringClass.h"

void testFindNotFound() {
    MyString str1("Why do birds suddenly appear?");
    assert(str1.find("meow") == -1);
}

void testFindFound() {
    MyString str1("Why do birds suddenly appear?");
    assert(str1.find("birds") == 7);
}

void testFindNull() {
    MyString str1("Why do birds suddenly appear?");
    assert(str1.find(nullptr) == -1);
}

void testFindEmpty() {
    MyString str1;
	assert(str1.find("anything") == -1);
}

void testFindSubstringLongerThanString() {
    MyString str1("short");
    assert(str1.find("longer substring") == -1);
}

void testAppendAndFind() {
    MyString str1("Hello");
    str1.append(" World");
	assert(str1.find("World") == 6);
}

int tests() {
    testFindNotFound();
    testFindFound();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
 