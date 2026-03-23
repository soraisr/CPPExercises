#include <iostream>
#include <vector>
#include <set>

std::vector<int> remove_duplicates(const std::vector<int>& vector)
{
    std::set<int> setInput(vector.begin(), vector.end());
    std::vector<int> uniqueVector(setInput.begin(), setInput.end());
    return uniqueVector;
}

int main()
{ 
    std::vector<int> input{1,3,3,7};
    std::vector<int> unique = remove_duplicates(input);
    std::cout << "Unique elements: ";
    for (int num : unique) {
        std::cout << num << " ";
    }
    return 0;
}