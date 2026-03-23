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

int tests() {
    testFindNotFound();
    testFindFound();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
 