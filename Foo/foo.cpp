#include "foo.h"

int Foo::s_counter = 0;
void func_section_200_not_222_XD(std::vector<Foo>& foos)
{
        foos.resize(NUM_FOOS);
    
}

int main()
{
    std::vector<Foo> foos;
    func_section_200_not_222_XD(foos);
    std::cout << "s_counter = " << Foo::s_counter << std::endl;

    return 0;
}
