#include <bits/stdc++.h>

#include "../shared.hpp"

struct Interval {
    long long start, end, delta;
};

// seed -> soil -> fertilizer -> water -> light -> temperature -> humidity -> location

std::vector<Interval> soil;
std::vector<Interval> fertilizer;
std::vector<Interval> water;
std::vector<Interval> light;
std::vector<Interval> temperature;
std::vector<Interval> humidity;
std::vector<Interval> location;

Interval stringToInterval(std::string in) {
    std::vector<std::string> vec = split(in);

    Interval interval;
    interval.start = std::stoull(vec.at(1));
    interval.end = std::stoull(vec.at(1)) + std::stoull(vec.at(2)) - 1;
    interval.delta = std::stoull(vec.at(0)) - std::stoull(vec.at(1));

    return interval;
}

void save(std::string label, std::vector<std::string> buf) {
    if (label == "seed-to-soil map:") {
        for (std::string str : buf) {
            soil.push_back(stringToInterval(str));
        }
    } else if (label == "soil-to-fertilizer map:") {
        for (std::string str : buf) {
            fertilizer.push_back(stringToInterval(str));
        }
    } else if (label == "fertilizer-to-water map:") {
        for (std::string str : buf) {
            water.push_back(stringToInterval(str));
        }
    } else if (label == "water-to-light map:") {
        for (std::string str : buf) {
            light.push_back(stringToInterval(str));
        }
    } else if (label == "light-to-temperature map:") {
        for (std::string str : buf) {
            temperature.push_back(stringToInterval(str));
        }
    } else if (label == "temperature-to-humidity map:") {
        for (std::string str : buf) {
            humidity.push_back(stringToInterval(str));
        }
    } else if (label == "humidity-to-location map:") {
        for (std::string str : buf) {
            location.push_back(stringToInterval(str));
        }
    }
}

long long evalLocation(long long m_seed) {
    long long m_soil = -1;
    for (Interval i : soil) {
        if (i.start <= m_seed && i.end >= m_seed) {
            m_soil = m_seed + i.delta;
            break;
        }
    }
    if (m_soil == -1) m_soil = m_seed;

    long long m_fertilizer = -1;
    for (Interval i : fertilizer) {
        if (i.start <= m_soil && i.end >= m_soil) {
            m_fertilizer = m_soil + i.delta;
            break;
        }
    }
    if (m_fertilizer == -1) m_fertilizer = m_soil;

    long long m_water = -1;
    for (Interval i : water) {
        if (i.start <= m_fertilizer && i.end >= m_fertilizer) {
            m_water = m_fertilizer + i.delta;
            break;
        }
    }
    if (m_water == -1) m_water = m_fertilizer;

    long long m_light = -1;
    for (Interval i : light) {
        if (i.start <= m_water && i.end >= m_water) {
            m_light = m_water + i.delta;
            break;
        }
    }
    if (m_light == -1) m_light = m_water;

    long long m_temperature = -1;
    for (Interval i : temperature) {
        if (i.start <= m_light && i.end >= m_light) {
            m_temperature = m_light + i.delta;
            break;
        }
    }
    if (m_temperature == -1) m_temperature = m_light;

    long long m_humidity = -1;
    for (Interval i : humidity) {
        if (i.start <= m_temperature && i.end >= m_temperature) {
            m_humidity = m_temperature + i.delta;
            break;
        }
    }
    if (m_humidity == -1) m_humidity = m_temperature;

    long long m_location = -1;
    for (Interval i : location) {
        if (i.start <= m_humidity && i.end >= m_humidity) {
            m_location = m_humidity + i.delta;
            break;
        }
    }
    if (m_location == -1) m_location = m_humidity;

    // std::cout << m_seed << "->" << m_soil << "->" << m_fertilizer << "->" << m_water << "->" << m_light << "->" << m_temperature << "->" << m_humidity << "->" << m_location << std::endl;

    return m_location;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<std::string> seeds = split(data.at(0).substr(7));

    std::string label;
    std::vector<std::string> buf;

    for (std::vector<std::string>::iterator it = data.begin() + 2; it != data.end(); it++) {
        if (*it == "") {
            save(label, buf);
            buf.clear();
            continue;
        }
        if (isalpha((*it).at(0))) {
            label = *it;
        }
        if (isdigit((*it).at(0))) {
            buf.push_back(*it);
        }
    }
    save(label, buf);  // No whitespace at the end of the input document

    long long minLoc = LLONG_MAX;
    long long k = 0;

    for (int i = 0; i < seeds.size(); i++) {
        if (i % 2 == 0) continue;

        long long baseSeed = std::stoull(seeds.at(i));
        long long range = std::stoull(seeds.at(i + 1));

        for (long long seed = baseSeed; seed < baseSeed + range; seed++) {
            minLoc = std::min(minLoc, evalLocation(seed));

            // k++;
            // if (k % 100'000 == 0) {
            //     std::cout << "Evaluated seeds: " << k << std::endl;
            // }
        }
    }

    std::cout << minLoc << std::endl;

    return 0;
}

// Solution: 12634632