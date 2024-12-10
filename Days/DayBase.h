//
// Created by zarashane on 12/9/24.
//

#ifndef DAYBASE_H
#define DAYBASE_H
#include <string>
#include <vector>

class day_base
{
public:
    static std::vector<int> string_split(const std::string &s, const char* delimeter)
    {
        size_t currentIndex = 0;
        std::vector<int> returnable;
        do
        {
            auto nextIndex = s.find(delimeter, currentIndex);
            if(nextIndex != std::string::npos)
            {
                returnable.emplace_back(atoi(s.substr(currentIndex, nextIndex).c_str()));

                currentIndex = nextIndex+1;
                continue;
            }

            returnable.emplace_back(atoi(s.substr(currentIndex).c_str()));
            break;
        }
        while(currentIndex != -1);

        return returnable;
    }
};

#endif //DAYBASE_H
