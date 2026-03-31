// CR: that's very linux, since you are using VS #pragma once is what you want

#ifndef MYSTRINGCLASS_H
#define MYSTRINGCLASS_H

class MyString {

// CR: public before private
private:
	char* data = nullptr;
	size_t length = 0;
	size_t occupiedSize = 0;
	size_t getStrlen(const char* s) const;

public:
	// CR: good seperating ctors and methods, it's more readable to just have them in a different declaration section (see below)
	//Constructor declaration
	MyString();
	MyString(const char* s);
	MyString(const MyString& other);

	~MyString();

	MyString& operator=(const MyString& other);


// CR: aforementioned below
public:
//
	//Methods
	int find(const char* subStr) const;
	// CR: good
	void insert(const char* subStr, size_t index);
	void insert(const MyString& other, size_t index);
	void remove(size_t index, size_t count);

	// CR: you'll read this in one of the CPP books, a better getter name here would just be CString()
	const char* getCString() const; //we dont want to change the object
	void append(const char* subStr);
	void append(const MyString& other);

};

#endif // !MYSTRINGCLASS_H
