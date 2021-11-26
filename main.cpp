#include <iostream>
#include <map>

std::map<char, int> getFrequencyMap(std::string &input) {
    std::map<char, int> freq;
    for (int i = 0; i < input.length(); i++) {
        if (!freq.contains(input[i])) {
            freq.insert({input[i], 1});
        } else {
            freq[input[i]] += 1;
        }
    }
    return freq;
}


int main() {
    std::string first, last;
    std::cin >> first >> last;

    auto firstMap = getFrequencyMap(first);
    auto lastMap = getFrequencyMap(last);

    bool equal = false;

    for (const auto&[key, value]: firstMap) {
        if (lastMap.contains(key)) {
            if (lastMap[key] == value) {
                equal = true;
            } else {
                equal = false;
                break;
            }
        } else {
            equal = false;
            break;
        }
    }

    if (equal) {

        for (const auto&[key, value]: lastMap) {
            if (firstMap.contains(key)) {
                if (firstMap[key] == value) {
                    equal = true;
                } else {
                    equal = false;
                    break;
                }
            } else {
                equal = false;
                break;
            }
        }
    }

    if (equal) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}