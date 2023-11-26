#include "Ejercicio03.h"
#include <algorithm>

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
	timeMap[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp)
{
	map<int, string> values = timeMap[key];
	string result = "";
	int diff = INT_MAX;

	for (auto value : values)
	{
		if (value.first <= timestamp && timestamp - value.first < diff)
		{
			diff = timestamp - value.first;
			result = value.second;
		}
	}

	return result;
}