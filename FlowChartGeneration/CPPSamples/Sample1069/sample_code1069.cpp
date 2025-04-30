#include <iostream>
#include <map>
#include <string>

bool check_dict_case(const std::map<std::string, int>& dict) {
    if (dict.empty()) {
        return false;
    } else {
        std::string state = "start";
        for (const auto& pair : dict) {
            const std::string& key = pair.first;

            if (!std::all_of(key.begin(), key.end(), ::isalpha)) {
                state = "mixed";
                break;
            }
            if (state == "start") {
                if (std::all_of(key.begin(), key.end(), ::isupper)) {
                    state = "upper";
                } else if (std::all_of(key.begin(), key.end(), ::islower)) {
                    state = "lower";
                } else {
                    break;
                }
            } else if ((state == "upper" && !std::all_of(key.begin(), key.end(), ::isupper)) || 
                       (state == "lower" && !std::all_of(key.begin(), key.end(), ::islower))) {
                state = "mixed";
                break;
            } else {
                break;
            }
        }
        return state == "upper" || state == "lower";
    }
}
