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

int MyString::getStrlen(const char* s) const {
	int i = 0;
	while(s[i] != '\0') {
		i++;
	}
	return i;
}

int MyString::find(const char* subStr) {
	if (nullptr == subStr) {
		return -1;
	}

	size_t subStrLen = getStrlen(subStr);

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

void MyString::insert(size_t index, char* subStr) {
	return;
}

void MyString::remove(size_t index, size_t count) {
	return;
}
const char* MyString::getCString() const{
	return data;
}

void MyString::append(const char* subStr) {
	if (nullptr == subStr) {
		return;
	}

	size_t subStrLen = getStrlen(subStr);
	if (0 == subStrLen) {
		return;
	}

	size_t newLength = length + subStrLen;
	size_t newOccupiedSize = occupiedSize;

	if (newLength + 1 > occupiedSize) {
		newOccupiedSize = newLength + 1;
	}

	char* newData = new char[newOccupiedSize];
	for (size_t i = 0; i < length; i++) {
		newData[i] = data[i];
	}
	for (size_t i = 0; i < subStrLen; i++) {
		newData[length + i] = subStr[i];
	}
	newData[newLength] = '\0';

	delete[] data;
	data = newData;
	length = newLength;
	occupiedSize = newOccupiedSize;
}			