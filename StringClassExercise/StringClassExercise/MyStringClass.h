#ifndef MYSTRINGCLASS_H
#define MYSTRINGCLASS_H

class MyString {

private:
	char* data = nullptr;
	size_t length = 0;
	size_t occupiedSize = 0;
	size_t getStrlen(const char* s) const;

public:
	//Constructor declaration
	MyString();
	MyString(const char* s);
	MyString(const MyString& other);

	~MyString();

	MyString& operator=(const MyString& other);

	//Methods
	int find(const char* subStr) const;
	void insert(const char* subStr, size_t index);
	void insert(const MyString& other, size_t index);
	void remove(size_t index, size_t count);
	const char* getCString() const; //we dont want to change the object
	void append(const char* subStr);
	void append(const MyString& other);

};

#endif // !MYSTRINGCLASS_H
