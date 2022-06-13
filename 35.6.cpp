#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <filesystem>

int main() {
    std::vector data = {1, 2, 3, 4, 5, 3, 3, 6};
    // exercise 1
    for(const auto& it : data) std::cout << it << " ";
    std::cout << "\n" << std::endl;

    // exercise 2
    auto func = [](std::vector<int>& _vct) {
        std::unordered_set<int> set (_vct.begin(), _vct.end());
        std::unordered_multiset<int> multiset (_vct.begin(), _vct.end());
        for (const auto& it: set) {
            std::cout << "Count of element " << it << " = " << multiset.count(it) << std::endl;
        }
        return std::make_unique<std::vector<int>>(std::vector<int>(set.begin(), set.end()));
    };

    for(const auto& it : *func(data)) {
        std::cout << it << " ";
    }
    std::cout << "\n" << std::endl;

    // exercise 3
    auto recursiveGetFileNamesByExtension = [](const std::filesystem::path& _path, const std::string& _extension) {
        std::vector<std::string> filenameVct;
        for (const auto& p: std::filesystem::recursive_directory_iterator(_path)){
            if (is_regular_file(p.path()) and p.path().extension() == _extension) {
                filenameVct.push_back(p.path().filename().string());
            }
        }
        return filenameVct;
    };

    std::vector<std::string> filenameVct = recursiveGetFileNamesByExtension("C:\\Program Files\\JetBrains", ".txt");
    for (const auto& it :  filenameVct)
        std::cout << it << std::endl;

}
