#include <string>
#include <vector>
#include <algorithm>

std::pair<int, int> sample_nam(std::vector<std::string>& sample_names) {
    sample_names.erase(std::remove_if(sample_names.begin(), sample_names.end(), [](const std::string& el) {
        return !(std::isupper(el[0]) && std::all_of(el.begin() + 1, el.end(), [](char c) { return std::islower(c); }));
    }), sample_names.end());
    
    std::string joined;
    for (const auto& name : sample_names) {
        joined += name;
    }
    return {static_cast<int>(joined.length()), 0}; // Return 0 as the second value as it's not specified in the original code.
}
