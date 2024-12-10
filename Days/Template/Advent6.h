//
// Created by zarashane on 12/1/2024.
//


#ifndef ADVENT6_H
#define ADVENT6_H

#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "../DayBase.h"


class Advent6 : day_base
{
public:
    std::vector<std::vector<int>> CheckData;
    int Part1();
    int Part2();
    void LoadFromFile();
};


#endif //ADVENT6_H
