#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::pair<std::string, int>> count_common(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> word_counts;
    for (const auto& word : words) {
        word_counts[word]++;
    }

    // Create a vector of pairs from the unordered_map
    std::vector<std::pair<std::string, int>> word_vector(word_counts.begin(), word_counts.end());
    
    // Sort the vector based on the counts in descending order
    std::sort(word_vector.begin(), word_vector.end(), 
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    // Get the top four
    if (word_vector.size() > 4) {
        word_vector.resize(4);
    }

    return word_vector;
}
