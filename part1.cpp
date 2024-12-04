#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

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
    int lineCount = 0;
    std::vector<int> list;
    std::vector<int> list2;

    std::ifstream file("input.txt");
    while (getline(file, line)){
        auto res = split(line);
        list.push_back(res[0]);
        list2.push_back(res[1]);
        lineCount++;
    }

    std::sort(list.begin(), list.end());
    std::sort(list2.begin(), list2.end());

    for (int i = 0; i<lineCount; i++){
        result += abs(list[i] - list2[i]);
    }

    std::cout << result << std::endl;
    file.close();

    return 0;
}