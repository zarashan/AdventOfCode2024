#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "Days/one/Advent1_1.h"
#include "Days/two/Advent2.h"
#include "Days/three/Advent3.h"

int main()
{
    Advent3 advent;
    advent.LoadFromFile();

    std::cout << advent.Part2() << std::endl;
    return 0;
}
