//
// Created by zarashane on 12/1/2024.
//

#include "Advent4.h"

#include <cstring>
#include <iostream>


void Advent4::LoadFromFile()
{
    const auto filename = R"(../Days/four/Data.txt)";
    std::string data;
    std::ifstream DataFile(filename);


    CheckData.push_back("");
    CheckData.push_back("");
    CheckData.push_back("");


    char c;
    std::string currentNumber = "...";
    while(DataFile.get(c))
    {
        if(c == 0xA)
        {
            currentNumber += "...";
            CheckData.push_back(currentNumber);
            currentNumber = "...";
        }
        else if(c > 0x20 && c < 0x7B)
        {
            currentNumber += c;
        }
    }
    if(!currentNumber.empty()) CheckData.push_back(currentNumber + "...");
    DataFile.close();

    std::string arr = "";
    for(int i = 0; i < currentNumber.length(); ++i)
    {
        arr += ".";
    }
    CheckData[0] = arr;
    CheckData[1] = arr;
    CheckData[2] = arr;
    CheckData.push_back(arr);
    CheckData.push_back(arr);
    CheckData.push_back(arr);
}


int Advent4::Part1()
{
    auto total = 0;
    auto xtotal = 0;
    const auto checkedLetters = "XMAS";
    for(auto i = 3; i < CheckData.size() - 3; i++)
    {
        for(int j = 3; j < CheckData[i].length() - 3; ++j)
        {
            auto tempData = CheckData[i];
            if(CheckData[i][j] == 'X')
            {
                xtotal++;
                bool checked[8];
                std::fill(std::begin(checked), std::end(checked), true);
                for(int q = 1; q < std::strlen(checkedLetters); ++q)
                {
                    //top left
                    if(checked[0] && CheckData[i - q][j - q] != checkedLetters[q])
                    {
                        checked[0] = false;
                    }
                    //top center
                    if(checked[1] && CheckData[i - q][j] != checkedLetters[q])
                    {
                        checked[1] = false;
                    }
                    //top right
                    if(checked[2] && CheckData[i - q][j + q] != checkedLetters[q])
                    {
                        checked[2] = false;
                    }
                    //left
                    if(checked[3] && CheckData[i][j - q] != checkedLetters[q])
                    {
                        checked[3] = false;
                    }
                    //right
                    if(checked[4] && CheckData[i][j + q] != checkedLetters[q])
                    {
                        checked[4] = false;
                    }
                    //bottom left
                    if(checked[5] && CheckData[i + q][j - q] != checkedLetters[q])
                    {
                        checked[5] = false;
                    }
                    //bottom center
                    if(checked[6] && CheckData[i + q][j] != checkedLetters[q])
                    {
                        checked[6] = false;
                    }
                    //bottom right
                    if(checked[7] && CheckData[i + q][j + q] != checkedLetters[q])
                    {
                        checked[7] = false;
                    }
                }

                for(int r = 0; r < 8; ++r)
                {
                    if(checked[r]) total++;
                }
            }
        }
    }
    return total;
}

int Advent4::Part2()
{
    auto total = 0;
    for(auto i = 3; i < CheckData.size() - 3; i++)
    {
        for(int j = 3; j < CheckData[i].length() - 3; ++j)
        {
            auto tempData = CheckData[i];
            auto s = 0;
            auto m = 0;
            if(CheckData[i][j] == 'A')
            {
                char data[4];
                data[0] = CheckData[i - 1][j - 1];
                data[1] = CheckData[i + 1][j + 1];
                data[2] = CheckData[i - 1][j + 1];
                data[3] = CheckData[i + 1][j - 1];
                for(int x = 0; x < std::strlen(data); ++x)
                {
                    if(data[x] == 'S') s++;
                    else if(data[x] == 'M') m++;
                }

                if(s == 2 && m == 2)
                {
                    auto c = 3;
                    if((data[0] == 'M' && data[1] == 'S') || (data[0] == 'S' && data[1] == 'M'))
                    {
                        total++;
                    }
                }
            }
        }
    }
    return total;
}
