#pragma once

#include <map>
#include <string>
#include <utility>

using std::map;
using std::string;
using std::make_pair;

class TimeMap
{
public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);

private:
	map<string, map<int, string>> timeMap;
};



