#include <iostream>
#include <cassert>
#include "MyStringClass.h"

void testFindNotFound() {
    MyString str("Why do birds suddenly appear?");
    assert(str.find("meow") == -1);
}

void testFindFound() {
    MyString str("Why do birds suddenly appear?");
    assert(str.find("birds") == 7);
}

void testFindNull() {
    MyString str("Why do birds suddenly appear?");
    assert(str.find(nullptr) == -1);
}

void testFindEmpty() {
    MyString str;
    assert(str.find("anything") == -1);
}

void testFindSubstringLongerThanString() {
    MyString str("short");
    assert(str.find("longer substring") == -1);
}

void testAppendAndFind() {
    MyString str("Hello");
    str.append(" World");
    assert(str.find("World") == 6);
}

void testAppendAndFindWithMyString() {
    MyString str1("Why do birds suddenly appear?");
    MyString str2("Everytime you are near");
    str1.append(str2);
    assert(str1.find("Everytime") == 29);
}

void testInsert() {
    MyString str("Why do birds suddenly appear?");
    str.insert("deli", 7);
    assert(str.find("delibirds") == 7);
}

void testInsertWithMyString() {
    MyString str1("Why do birds suddenly appear?");
    MyString str3("deli");
    MyString str4 = str1;
	str4.insert(str3, 7);
    assert(str4.find("delibirds") == 7);
}

void testRemove() {
    MyString str("Why do delibirds suddenly appear?");
    str.remove(0, 7);
    assert(str.find("delibirds") == 0);
}

void testCopyConstructor() {
    MyString str1("meow");
    MyString str2 = str1;
    assert(str2.find("meow") == 0);
}

void testAssignmentOperator() {
    MyString str1("meow");
    MyString str2("woof");
    str2 = str1;
    assert(str2.find("meow") == 0);
}

void tests() {
    testFindNotFound();
    testFindFound();
    testFindNull();
    testFindEmpty();
    testFindSubstringLongerThanString();
    testAppendAndFind();
    testAppendAndFindWithMyString();
    testInsert();
    testInsertWithMyString();
    testRemove();
    testCopyConstructor();
	testAssignmentOperator();

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    tests();
    return 0;
}

