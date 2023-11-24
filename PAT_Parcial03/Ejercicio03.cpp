// Ejercicio03.cpp

#include "Ejercicio03.h"
#include <algorithm>

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
    auto it = data.find(key);
    if (it == data.end()) {
        data[key] = { {timestamp, value} };
    }
    else {
        it->second.push_back({ timestamp, value });
    }
}

string TimeMap::get(string key, int timestamp)
{
    auto it = data.find(key);
    if (it != data.end()) {

        const auto& timestamps = it->second;

        auto it_time = std::lower_bound(timestamps.begin(), timestamps.end(), timestamp,
            [](const pair<int, string>& a, int ts) {
                return a.first < ts;
            });

        if (it_time != timestamps.begin()) {

            size_t index = std::distance(timestamps.begin(), it_time - 1);
            return timestamps[index].second;
        }
    }

    return "";
}

