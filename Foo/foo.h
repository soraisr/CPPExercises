#include <iostream>
#include <vector>

#define NUM_FOOS 40

class Foo
{
public:
    Foo() // default constructor
    {
        s_counter += 5;
    }

    static int s_counter;
};
