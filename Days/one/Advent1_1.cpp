//
// Created by zarashane on 12/1/2024.
//

#include "Advent1_1.h"

#include <iostream>


void Advent1_1::LoadFromFile(std::string filename)
{
    std::string data;

    std::ifstream DataFile;
    DataFile.open(filename);

    if(DataFile.fail())
    {
        std::cout << "Failed File Missing";
        return;
    }

    char c;
    std::string currentNumber;
    while(DataFile.get(c))
    {
        if(c == 0x20 && !currentNumber.empty())
        {
            DataLeft.push_back(atoi(currentNumber.c_str()));
            currentNumber = "";
        }
        else if(c == 0xA)
        {
            DataRight.push_back(atoi(currentNumber.c_str()));
            currentNumber = "";
        }
        else if(c > 0x20 && c < 0x7B)
        {
            currentNumber += c;
        }
    }

    if(!currentNumber.empty()) DataRight.push_back(atoi(currentNumber.c_str()));
}

void Advent1_1::SortArrays()
{
    std::sort(DataLeft.begin(), DataLeft.end());
    std::sort(DataRight.begin(), DataRight.end());
}

int Advent1_1::Part1()
{
    SortArrays();

    auto count = 0;

    for(int i = 0; i < DataLeft.size(); ++i)
    {
        count += abs(DataLeft[i] - DataRight[i]);
    }

    return count;
}

int Advent1_1::Part2()
{
    SortArrays();
    auto count = 0;
    std::unordered_map<int, int> Counts;

    for(int i = 0; i < DataLeft.size(); ++i)
    {
        if(Counts.contains(DataLeft[i])) continue;
        Counts.insert({DataLeft[i], 0});

        for(int j = 0; j < DataRight.size(); ++j)
        {
            if(DataRight[j] == DataLeft[i])
            {
                Counts[DataLeft[i]]++;

            }

            if(DataRight[j] > DataLeft[i]) break;
        }
    }

    for(int i = 0; i < DataLeft.size(); ++i)
    {
        count += DataLeft[i] * Counts[DataLeft[i]];
    }

    return count;

}
