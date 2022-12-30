#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

/**
 * Arranges the items in arr by the keys specified in keys.
 *
 * @param arr A vector of maps, where each map contains a key-value pair.
 * @param keys A vector of keys that should be used to arrange the items in arr.
 * @return A vector of vectors, where each inner vector contains the values
 *         corresponding to the keys in keys.
 */
std::vector<std::vector<std::string>> arrange(const std::vector<std::map<std::string, std::string>>& arr, const std::vector<std::string>& keys) {
  if (arr.empty()) {
    throw std::invalid_argument("There are no items to arrange");
  }

  if (keys.empty()) {
    throw std::invalid_argument("keys must be an array");
  }

  std::vector<std::vector<std::string>> result;
  for (auto key : keys) {
    std::vector<std::string> values;
    for (auto item : arr) {
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

int main() {
  std::vector<std::map<std::string, std::string>> arr = {
    {{"name", "John"}, {"age", "30"}},
    {{"name", "Jane"}, {"age", "25"}},
  };
  std::vector<std::string> keys = {"name", "age"};

  try {
    auto result = arrange(arr, keys);
    for (const auto& vec : result) {
      for (const auto& val : vec) {
        std::cout << val << " ";
      }
      std::cout << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
