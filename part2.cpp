#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

std::vector<int> split(std::string &str){
    std::vector<int> result;
    std::istringstream stream(str);
    std::string word;

    while (stream >> word){
        result.push_back(std::stoi(word));
    }

    return result;
}
int main(){
    int result = 0;
    std::string line;
    std::map<int, std::array<int, 2>> m;

    std::ifstream file("input.txt");
    while (getline(file, line)){
        auto res = split(line);
        auto it = m.find(res[0]);
        auto it2 = m.find(res[1]);

        std::array<int, 2> occ = {1, 0};
        if (it == m.end()){
            m.emplace(std::pair<int, std::array<int, 2>>(res[0], occ));
        }
        else{
            it->second.at(0)++;
        }
        if (it2 != m.end()){
            it2->second.at(1)++;
        }
        else{
            std::array<int, 2> occ = {0, 1};
            m.emplace(std::pair<int, std::array<int, 2>>(res[1], occ));
        }
    }

    for (auto const& x : m){
        result += x.first * x.second.at(0) * x.second.at(1);
    }
    std::cout << result << std::endl;
    file.close();

    return 0;
}