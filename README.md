# gigs

A small C++ library to help you arrange arrays more faster


# Operational Usage

```cpp
#include <iostream>
#include <vector>
#include <map>
#include "arrange.h"

int main() {
  std::vector<std::map<std::string, std::string>> arr = {
    {{"name", "John"}, {"age", "30"}},
    {{"name", "Jane"}, {"age", "25"}},
  };
  std::vector<std::string> keys = {"name", "age"};

  auto result = arrange(arr, keys);
  for (const auto& vec : result) {
    for (const auto& val : vec) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
```
