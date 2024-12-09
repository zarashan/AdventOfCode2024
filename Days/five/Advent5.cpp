//
// Created by zarashane on 12/1/2024.
//

#include "Advent5.h"

#include <cstring>
#include <iostream>


void Advent5::LoadFromFile()
{
    const auto filename = R"(../Days/five/Data.txt)";
    std::string data;
    std::ifstream DataFile(filename);

    char c;
    std::string currentNumber = "";
    while(std::getline(DataFile, currentNumber))
    {
        if(currentNumber.length() > 1) AddEntry(currentNumber);
    }

    // while(DataFile.get(c))
    // {
    //     if(c == "\n")
    //     {
    //         if(!currentNumber.empty())
    //         {
    //             AddEntry(currentNumber);
    //             currentNumber = "";
    //         }
    //     }
    //     else if(c > 0x20 && c < 0x7F)
    //     {
    //         currentNumber += c;
    //     }
    // }
    //if(!currentNumber.empty()) CheckData.push_back(currentNumber + "...");
    //DataFile.close();
}


int Advent5::Part1()
{
    auto total = 0;

    for(auto & i : CheckData)
    {
        if(CheckPages(i) == -1)
            total+= i[i.size()/2];
    }

    return total;
}


int Advent5::CheckPages(std::vector<int>& data)
{

    int isFoundIndex = -1;
    for(int j = 1; j < data.size(); ++j)
    {
        for(int x = 0; x < j; ++x)
        {
            auto rule = Rules[data[j]];
            if(std::ranges::find(rule, data[x]) == rule.end())
            {
                continue;
            }

            auto temp = data[j];
            data[j] = data[x];
            data[x] = temp;
            isFoundIndex = j;
            return isFoundIndex;
        }
    }

    return isFoundIndex;
}

int Advent5::Part2()
{
    auto total = 0;

    for(auto & i : CheckData)
    {
        if(CheckPages(i) > -1)
            total += FixPages(i);
    }

    return total;
}

int Advent5::FixPages(std::vector<int>& data)
{
    std::vector<int> returnable;

    int BadPagesIndex = CheckPages(data);
    while(BadPagesIndex != -1)
    {
        BadPagesIndex = CheckPages(data);
    }

    return data[data.size()/2];
}

void Advent5::AddEntry(const std::string& s)
{
    int indexOfBar = s.find('|');
    if(indexOfBar > -1)
    {
        auto key = atoi(s.substr(0, indexOfBar).c_str());
        auto data = atoi(s.substr(indexOfBar + 1, s.length()).c_str());

        if(!Rules.contains(key))
        {
            std::vector<int> temp;
            temp.push_back(data);
            Rules.emplace(key, temp);
        }
        else
        {
            Rules[key].emplace_back(data);
        }
    }
    else
    {
        CheckData.emplace_back(string_split(s, ","));
    }
}
