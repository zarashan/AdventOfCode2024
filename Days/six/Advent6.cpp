//
// Created by zarashane on 12/1/2024.
//

#include "Advent6.h"

#include <cstring>
#include <iostream>


void Advent6::LoadFromFile()
{
    const auto filename = R"(../Days/six/Data.txt)";
    std::string data;
    std::ifstream DataFile(filename);

    char c;
    std::string currentNumber = "";
    while(DataFile.get(c))
    {
        if(c == 0xA)
        {
            CheckData.push_back(currentNumber);
            currentNumber = "";
        }
        else if(c > 0x20 && c < 0x7B)
        {
            currentNumber += c;
        }
    }
    if(!currentNumber.empty()) CheckData.push_back(currentNumber);

    // std::string currentNumber = "";
    // while(std::getline(DataFile, currentNumber))
    // {
    //     currentNumber = currentNumber.substr(0, currentNumber.length()-1);
    //     CheckData.push_back(currentNumber);
    // }
    // DataFile.close();
}


int Advent6::Part1()
{
    auto total = 0;
    auto pair = std::make_pair(-1, -1);


    for(int i = 0; i < CheckData.size(); ++i)
    {
        auto location = CheckData[i].find('^');
        if(location != std::string::npos)
        {
            pair.first = location;
            pair.second = i;
            break;
        }
    }

    size_t boundX = CheckData[0].length();
    size_t boundY = CheckData.size();
    Direction dir = Direction_Up;

    CheckData[pair.second][pair.first] = 'x';
    while((pair.first > 0 && pair.first < boundX - 1) && (pair.second > 0 && pair.second < boundY - 1))
    {
        switch(dir)
        {
        case Direction_Up:
            if(CheckData[pair.second - 1][pair.first] == '#') dir = Direction_Right;
            else
            {
                pair.second--;
                CheckData[pair.second][pair.first] = 'x';
            }
            break;
        case Direction_Down:
            if(CheckData[pair.second + 1][pair.first] == '#') dir = Direction_Left;
            else
            {
                pair.second++;
                CheckData[pair.second][pair.first] = 'x';
            }
            break;
        case Direction_Left:
            if(CheckData[pair.second][pair.first - 1] == '#') dir = Direction_Up;
            else
            {
                pair.first--;
                CheckData[pair.second][pair.first] = 'x';
            }
            break;
        case Direction_Right:
            if(CheckData[pair.second][pair.first + 1] == '#') dir = Direction_Down;
            else
            {
                pair.first++;
                CheckData[pair.second][pair.first] = 'x';
            }
            break;
        }
    }

    for(int i = 0; i < CheckData.size(); ++i)
    {
        for(int j = 0; j < CheckData.size(); ++j)
        {
            if(CheckData[i][j] == 'x') total++;
        }
    }
    return total;
}


int Advent6::Part2()
{
    auto originalData = CheckData;
    Part1();
    auto runData = CheckData;

    auto total = 0;
    auto pair = std::make_pair(-1, -1);


    for(int i = 0; i < originalData.size(); ++i)
    {
        auto location = originalData[i].find('^');
        if(location != std::string::npos)
        {
            pair.first = location;
            pair.second = i;
            break;
        }
    }

    auto originalLocation = pair;

    size_t boundX = CheckData[0].length();
    size_t boundY = CheckData.size();

    for(int y = 0; y < runData.size(); ++y)
    {
        for(int x = 0; x < runData[y].length(); ++x)
        {
            auto looping = false;
            if(runData[y][x] != 'x') continue;
            CheckData = originalData;
            pair = originalLocation;
            CheckData[y][x] = '#';

            Direction dir = Direction_Up;

            CheckData[pair.second][pair.first] = 'x';
            auto MoveSteps = 0;
            auto lengthMax = CheckData.size() * CheckData[0].length();

            while((pair.first > 0 && pair.first < boundX - 1) && (pair.second > 0 && pair.second < boundY - 1))
            {
                MoveSteps++;
                if(MoveSteps > lengthMax)
                {
                    looping = true;
                    break;
                }
                switch(dir)
                {
                case Direction_Up:
                    if(CheckData[pair.second - 1][pair.first] == '#')
                    {
                        dir = Direction_Right;
                    }
                    else
                    {
                        pair.second--;
                        CheckData[pair.second][pair.first] = 'x';
                    }
                    break;
                case Direction_Down:
                    if(CheckData[pair.second + 1][pair.first] == '#')
                    {
                        dir = Direction_Left;
                    }
                    else
                    {
                        pair.second++;
                        CheckData[pair.second][pair.first] = 'x';
                    }
                    break;
                case Direction_Left:
                    if(CheckData[pair.second][pair.first - 1] == '#')
                    {
                        dir = Direction_Up;
                    }
                    else
                    {
                        pair.first--;
                        CheckData[pair.second][pair.first] = 'x';
                    }
                    break;
                case Direction_Right:
                    if(CheckData[pair.second][pair.first + 1] == '#')
                    {
                        dir = Direction_Down;
                    }
                    else
                    {
                        pair.first++;
                        CheckData[pair.second][pair.first] = 'x';
                    }
                    break;
                }
            }
            if(looping)
                total++;
        }
    }

    return total;
}
