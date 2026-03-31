#include "MyStringClass.h"

MyString::MyString() {
	// CR: I don't know what I think about this as the default values
	data = new char[1];
	data[0] = '\0';
	length = 0;
	occupiedSize = 1;
}

MyString::MyString(const char* s) {
	if(nullptr == s) {
		// CR: do we want to support an asignment of a nullptr? I think this should throw an exception instead
		data = new char[1];
		data[0] = '\0';
		length = 0;
		occupiedSize = 1;
	} else {
		// CR: it's prettier to have the good code in the "happy flow"
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
	// CR: there are some assumptions in this code - what if other.data is null?
	length = other.length;
	occupiedSize = other.occupiedSize;
	data = new char[occupiedSize];
	for(size_t i = 0; i < occupiedSize; i++) {
		data[i] = other.data[i];
	}
}

MyString::~MyString() {
	// CR: you will read this in the future, but you should try catch your dtors, exceptions within exceptions cause for nasty flows
	delete[] data;
}

MyString& MyString::operator=(const MyString& other)
{
	// CR: in the future you will see a pattern called copy and swap, which is better than what's going on here which is dangerous
	if (this == &other) {
		return *this;
	}

	char* newData = nullptr;
	newData = new char[other.occupiedSize];

	for (size_t i = 0; i < other.occupiedSize; i++) {
		newData[i] = other.data[i];
	}

	// CR: memory leak on fail
	delete[] data;
	data = newData;
	length = other.length;
	occupiedSize = other.occupiedSize;

	return *this;
}
	
// CR: This method should be static
size_t MyString::getStrlen(const char* s) const {
	size_t i = 0;
	while(s[i] != '\0') {
		i++;
	}
	return i;
}

int MyString::find(const char* subStr) const {
	if (nullptr == subStr) {
		// CR: in cpp we throw when we see unsupported edge cases
		return -1;
	}

	size_t subStrLen = getStrlen(subStr);

	if (subStrLen == 0) {
		return 0;
	}

	// CR: this should be above the first, and throw
	if (subStrLen > length) {
		return -1;
	}

	// CR: double nested loop is kinda ugly, maybe split into two functions
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
	// CR: good!
	MyString subStrObj(subStr);
	insert(subStrObj, index);
}

void MyString::insert(const MyString& other, size_t index){
	// CR: good, here the assumption other can be null is checked
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

	// CR: char* newData
	// CR: indeed no need to check newData!=nullptr, do you know why?
	char * newData = new char[newOccupiedSize];

	// CR: this strcpy like code is here a lot, maybe it should be a function
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

	// CR: there is some state danger here when stuff might fail
	// if delete fails newdata is leaked, plus the dtor will try to delete this another time
	delete[] data;
	data = newData;
	length = newLength;
	occupiedSize = newOccupiedSize;
}

void MyString::remove(size_t index, size_t count) {
	// CR: maybe this should throw
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
	// CR: why doesn't append just call insert in the last index?
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
