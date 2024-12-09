//
// Created by zarashane on 12/1/2024.
//


#ifndef ADVENT5_H
#define ADVENT5_H

#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "../DayBase.h"


class Advent5 : day_base
{
public:
    std::unordered_map<int, std::vector<int>> Rules;
    std::vector<std::vector<int>> CheckData;
    int Part1();
    int FixPages(std::vector<int>& data);
    int CheckPages(std::vector<int>& data);
    int Part2();
    void AddEntry(const std::string& s);
    void LoadFromFile();
};


#endif //ADVENT5_H
