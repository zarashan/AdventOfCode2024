//
// Created by zarashane on 12/1/2024.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#ifndef ADVENT1_1_H
#define ADVENT1_1_H
#include <string>


class Advent1_1 {
public:
    std::vector<int> DataLeft;
    std::vector<int> DataRight;
    int Part1();
    int Part2();
    void LoadFromFile(std::string FileName);

    void SortArrays();

};



#endif //ADVENT1_1_H
