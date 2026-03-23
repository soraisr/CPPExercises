#include "MyStringClass.h"

MyString::MyString() {
	data = new char[1];
	data[0] = '\0';
	length = 0;
	occupiedSize = 1;
}

MyString::MyString(const char* s) {
	if(nullptr == s) {
		data = new char[1];
		data[0] = '\0';
		length = 0;
		occupiedSize = 1;
	} else {
		length = getStrlen(s);
		occupiedSize = length + 1;
		data = new char[occupiedSize];
		for(size_t i = 0; i < occupiedSize; i++) {
			data[i] = s[i];
		}
	}
}

MyString::MyString(const MyString& other)
{
	length = other.length;
	occupiedSize = other.occupiedSize;
	data = new char[occupiedSize];
	for(size_t i = 0; i < occupiedSize; i++) {
		data[i] = other.data[i];
	}
}

MyString::~MyString() {
	delete[] data;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other) {
		return *this;
	}

	char* newData = nullptr;
	newData = new char[other.occupiedSize];

	for (size_t i = 0; i < other.occupiedSize; i++) {
		newData[i] = other.data[i];
	}

	delete[] data;
	data = newData;
	length = other.length;
	occupiedSize = other.occupiedSize;

	return *this;
}
	

size_t MyString::getStrlen(const char* s) const {
	size_t i = 0;
	while(s[i] != '\0') {
		i++;
	}
	return i;
}

int MyString::find(const char* subStr) const {
	if (nullptr == subStr) {
		return -1;
	}

	size_t subStrLen = getStrlen(subStr);

	if (subStrLen == 0) {
		return 0;
	}

	if (subStrLen > length) {
		return -1;
	}

	for (size_t i = 0; i <= length - subStrLen; i++) {
		size_t j = 0;
		while (j < subStrLen && data[i + j] == subStr[j]) {
			j++;
		}
		if (j == subStrLen) {
			return i;
		}
	}
	return -1;
}


void MyString::insert(const char* subStr, size_t index) {
	if (nullptr == subStr) {
		return;
	}
	MyString subStrObj(subStr);
	insert(subStrObj, index);
}

void MyString::insert(const MyString& other, size_t index){
	if (nullptr == other.data) {
		return;
	}

	if (index > length) {
		return;
	}


	size_t newLength = length + other.length;
	size_t newOccupiedSize = occupiedSize;

	if (newLength + 1 > occupiedSize) {
		newOccupiedSize = newLength + 1;
	}

	char * newData = new char[newOccupiedSize];


	for (size_t i = 0; i < index; i++) {
		newData[i] = data[i];
	}

	for (size_t i = 0; i < other.length; i++) {
		newData[index + i] = other.data[i];
	}

	for (size_t i = index; i < length; i++) {
		newData[other.length + i] = data[i];
	}

	newData[newLength] = '\0';

	delete[] data;
	data = newData;
	length = newLength;
	occupiedSize = newOccupiedSize;
}

void MyString::remove(size_t index, size_t count) {
	if (index >= length) {
		return;
	}

	if (count > length - index) {
		count = length - index;
	}
	for (size_t i = index; i < length - count; i++) {
		data[i] = data[i + count];
	}
	length -= count;

	for (size_t i = length; i < occupiedSize; i++) {
		data[i] = '\0';
	}
}

const char* MyString::getCString() const{
	return data;
}

void MyString::append(const char* subStr) {
	if (nullptr == subStr) {
		return;
	}

	MyString subStrObj(subStr);
	append(subStrObj);
}

void MyString::append(const MyString& other)
{
	if (nullptr == other.data) {
		return;
	}

	size_t newLength = length + other.length;
	size_t newOccupiedSize = occupiedSize;

	if (newLength + 1 > occupiedSize) {
		newOccupiedSize = newLength + 1;
	}

	char* newData = new char[newOccupiedSize];

	for (size_t i = 0; i < length; i++) {
		newData[i] = data[i];
	}
	for (size_t i = 0; i < other.length; i++) {
		newData[length + i] = other.data[i];
	}
	newData[newLength] = '\0';

	delete[] data;
	data = newData;
	length = newLength;
	occupiedSize = newOccupiedSize;
}
