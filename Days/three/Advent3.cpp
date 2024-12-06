//
// Created by zarashane on 12/1/2024.
//

#include "Advent3.h"

#include <iostream>


void Advent3::LoadFromFile()
{
    const auto filename = R"(../Days/three/Data.txt)";
    std::string data;
    std::ifstream DataFile(filename);
    std::stringstream buffer;
    buffer << DataFile.rdbuf();
    CheckData = buffer.str();
    DataFile.close();
}


int Advent3::Part1()
{
    auto total = 0;

    std::regex word_regex(R"(mul\(\d{1,3}\,\d{1,3}\))");

    auto words_begin = std::sregex_iterator(CheckData.cbegin(), CheckData.cend(), word_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();

        auto state = 0;
        std::string currentWord1 = "";
        std::string currentWord2 = "";
        for (auto j = 0; j != match_str.length(); ++j)
        {
            if (state == 0 && match_str[j] == '(')
            {
                state = 1;
            }
            else if (state == 1 && match_str[j] == ',')
            {
                state = 2;
            }
            else if (state == 2 && match_str[j] == ')')
            {
                total += atoi(currentWord1.c_str()) * atoi(currentWord2.c_str());
            }
            else
            {
                if (state == 1) currentWord1 += match_str[j];
                else if (state == 2) currentWord2 += match_str[j];
            }
        }
    }
    return total;
}

int Advent3::Part2()
{
    auto total = 0;

    std::regex word_regex(R"((mul\(\d{1,3}\,\d{1,3}\)|do\(\)|don't\(\)))");

    auto words_begin = std::sregex_iterator(CheckData.cbegin(), CheckData.cend(), word_regex);
    auto words_end = std::sregex_iterator();
    auto lastState = true;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();

        if (match_str == "do()") lastState = true;
        else if (match_str == "don't()") lastState = false;

        if (!lastState) continue;

        auto state = 0;
        std::string currentWord1 = "";
        std::string currentWord2 = "";
        for (auto j = 0; j != match_str.length(); ++j)
        {
            if (state == 0 && match_str[j] == '(')
            {
                state = 1;
            }
            else if (state == 1 && match_str[j] == ',')
            {
                state = 2;
            }
            else if (state == 2 && match_str[j] == ')')
            {
                total += atoi(currentWord1.c_str()) * atoi(currentWord2.c_str());
            }
            else
            {
                if (state == 1) currentWord1 += match_str[j];
                else if (state == 2) currentWord2 += match_str[j];
            }
        }
    }
    return total;
}
