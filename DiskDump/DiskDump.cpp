#include <iostream>
#include <fstream>
#include <vector>

void dump_chars_to_disk(const char* chars)
{
    std::ofstream file("c:\\users\\liraz\\desktop\\aramleet.txt");

    file << chars;
    file.close();
}

void func()
{
    // aram133
    std::vector<char> chars{'a', 'r', 'a', 'm', 'e', 'o', 'w'};
    chars.push_back('\0');

    dump_chars_to_disk(chars.data());
}

int main()
{
    func();
    return 0;
}   