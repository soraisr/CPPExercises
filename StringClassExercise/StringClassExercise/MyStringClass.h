#ifndef MYSTRINGCLASS_H
#define MYSTRINGCLASS_H

class MyString {

private:
	char* data = nullptr;
	size_t length = 0;
	size_t occupiedSize = 0;
	int getStrlen(const char* s) const;

public:
	//Constructor declaration
	MyString();
	MyString(const char* s);

	~MyString() {
		delete[] data;
		length = 0;
		occupiedSize = 0;	
	}	

	//Methods
	int find(const char* subStr);
	void insert(size_t index, char* subStr);
	void remove(size_t index, size_t count);
	const char* getCString() const; //we dont want to change the object
	void append(const char* subStr);
};

#endif // !MYSTRINGCLASS_H
