//
// Created by zarashane on 12/1/2024.
//


#ifndef ADVENT6_H
#define ADVENT6_H

#include <fstream>
#include <vector>
#include <string>

#include "../DayBase.h"
enum Direction {
    Direction_Up,
    Direction_Down,
    Direction_Left,
    Direction_Right
  };

class Advent6 : day_base
{
public:
    std::vector<std::string> CheckData;
    int Part1();
    int Part2();
    void LoadFromFile();
    void RunMap();
};


#endif //ADVENT6_H
