//
// Created by zarashane on 12/1/2024.
//

#include "Advent2.h"

#include <iostream>


void Advent2::LoadFromFile()
{
    const auto filename = R"(../Days/two/Data.txt)";
    std::string data;

    std::ifstream DataFile;
    DataFile.open(filename);

    if (DataFile.fail())
    {
        std::cout << "Failed File Missing";
        throw std::runtime_error("Failed File Missing");
        return;
    }

    char c;
    std::string currentNumber;
    std::vector<int> v;
    CheckData.push_back(v);
    while (DataFile.get(c))
    {
        if (c == 0x20)
        {
            CheckData.back().push_back(atoi(currentNumber.c_str()));
            currentNumber = "";
        }
        else if (c == 0xA)
        {
            CheckData.back().push_back(atoi(currentNumber.c_str()));

            std::vector<int> v;
            CheckData.push_back(v);
            currentNumber = "";
        }
        else if (c > 0x20 && c < 0x7B)
        {
            currentNumber += c;
        }
    }

    if (!currentNumber.empty()) CheckData.back().push_back(atoi(currentNumber.c_str()));
}


int Advent2::Part1()
{
    auto sum = 0;
    for (const auto& i : CheckData)
    {
        if (CheckPart(i)) sum++;
    }
    return sum;
}

int Advent2::Part2()
{
    auto sum = 0;

    for (int i = 0; i < CheckData.size(); i++)
    {
        for (int x = 0; x < CheckData[i].size(); x++)
        {
            std::vector<int> v = CheckData[i];
            v.erase(v.begin() + x);
            if (CheckPart(v))
            {
                sum++;
                break;
            }
        }
    }
    return sum;
}

bool Advent2::CheckPart(const std::vector<int>& d)
{
    auto first = d[0];
    auto second = d[1];
    auto checked = true;
    auto isDesending = first > second;

    for (int j = 0; j < d.size() - 1; j++)
    {
        first = d[j];
        second = d[j + 1];

        auto diff = first - second;

        if (diff >= -3 && diff < 0 && !isDesending || diff <= 3 && diff > 0 && isDesending) continue;
        //if ((diff <= 3 && diff > 0) && ((isDesending && first > second) || (!isDesending && first < second))) break;

        return false;
    }

    return true;
}
