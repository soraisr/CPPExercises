#include <array>
#include <iostream>
#include <stdexcept>
#include <cassert>

template<size_t size>
using IntArray = std::array<int, size>;

template<size_t size>
using CharArray = std::array<char, size>;


// Exercise 2.1: Sum of first and last
namespace Ex2_1 {
    template<class ArrayType>
    int func(const ArrayType& intsArray) {
        return intsArray.front() + intsArray.back();
    }
}


// Exercise 2.2: Middle element(s)
namespace Ex2_2 {
    template<class ArrayType>
    int func(const ArrayType& intsArray) {
        size_t size = intsArray.size();
        if (1 == size % 2) {
            return intsArray[size / 2];
        } else {
            return intsArray[(size / 2) - 1] + intsArray[size / 2];
        }
    }
}

// Exercise 2.3: Conditional returns (priority chain)
namespace Ex2_3 {
    template<class ArrayType>
    int func(const ArrayType& intsArray) {
        if (intsArray.empty()) return 1;
        if (intsArray.front() == intsArray.back()) return 2;
        if (6 == intsArray.size()) return 3;
        return 4;
    }
}


// Exercise 2.4: Element at index, return -1 if out of bounds
namespace Ex2_4 {
    template<class ArrayType>
    int func(const ArrayType& intsArray, size_t index) {
        if (index >= intsArray.size()) return -1;
        return intsArray[index];
    }
}


// Exercise 2.5: Element at index, throw if out of bounds
namespace Ex2_5 {
    template<class ArrayType>
    char func(const ArrayType& charsArray, size_t index) {
        return charsArray.at(index);
    }
}

int main() {
    std::cout << "Exercise 2.1:" ;
    assert(Ex2_1::func(IntArray<3>{1, 2, 3}) == 4);       
    assert(Ex2_1::func(IntArray<1>{7}) == 14);            
    std::cout << "  PASSED" << std::endl;


    std::cout << "Exercise 2.2:";
    assert(Ex2_2::func(IntArray<3>{10, 20, 30}) == 20);      
    assert(Ex2_2::func(IntArray<4>{10, 20, 30, 40}) == 50);        
    std::cout << "  PASSED" << std::endl;


    std::cout << "Exercise 2.3:";
    assert(Ex2_3::func(IntArray<0>{}) == 1);                      
    assert(Ex2_3::func(IntArray<4>{1, 3, 4, 1}) == 2);            
    assert(Ex2_3::func(IntArray<6>{1, 2, 3, 4, 5, 6}) == 3);     
    std::cout << "  PASSED" << std::endl;


    std::cout << "Exercise 2.4:";
    assert(Ex2_4::func(IntArray<3>{5, 6, 7}, 2) == 7);
    assert(Ex2_4::func(IntArray<3>{5, 6, 7}, 0) == 5);
    assert(Ex2_4::func(IntArray<3>{5, 6, 7}, 100) == -1);
    std::cout << "  PASSED" << std::endl;


    std::cout << "Exercise 2.5:";
    assert(Ex2_5::func(CharArray<4>{'a', 'r','a', 'm'}, 2) == 'a');
    bool threw = false;
    try {
        Ex2_5::func(CharArray<4>{'a', 'r', 'a', 'm'}, 100);
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);
    std::cout << "  PASSED" << std::endl;

}