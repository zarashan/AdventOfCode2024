//
// Created by zarashane on 12/1/2024.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#ifndef ADVENT2_H
#define ADVENT2_H
#include <string>


class Advent2 {
public:
    std::vector<std::vector<int>> CheckData;
    int Part1();
    int Part2();
    static bool CheckPart(const std::vector<int>& d);
    void LoadFromFile();

};



#endif //ADVENT2_H
