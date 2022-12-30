#ifndef ARRANGE_H
#define ARRANGE_H

#include <vector>
#include <map>
#include <string>
#include <stdexcept>

std::vector<std::vector<std::string>> arrange(const std::vector<std::map<std::string, std::string>>& arr, const std::vector<std::string>& keys) {
  if (keys.empty()) {
    throw std::invalid_argument("keys must be an array");
  }

  std::vector<std::vector<std::string>> result;
  for (const auto& key : keys) {
    std::vector<std::string> values;
    for (const auto& item : arr) {
      if (item.count(key) > 0) {
        values.push_back(item.at(key));
      } else {
        throw std::invalid_argument("Property " + key + " not found in item");
      }
    }
    result.push_back(values);
  }
  return result;
}

#endif
