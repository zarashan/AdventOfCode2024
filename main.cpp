#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "Days/one/Advent1_1.h"
#include "Days/two/Advent2.h"

int main()
{
    auto start_time = Clock::now();


    {

        Advent2 advent2;
        advent2.LoadFromFile();

        std::cout << advent2.Part2() << std::endl;

    }


    auto end_time = Clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << std::endl;
    return 0;
}
