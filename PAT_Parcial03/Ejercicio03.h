#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::pair;
using std::vector;

class TimeMap
{
public:
    TimeMap();

    void set(string key, string value, int timestamp);

    string get(string key, int timestamp);

private:
    std::unordered_map<string, vector<pair<int, string>>> data;
};



