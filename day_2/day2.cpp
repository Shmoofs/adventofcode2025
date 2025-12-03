#include <fstream>
#include <iostream>
#include <string>
#include <regex>

void pt1(std::ifstream &input) {
	long long password = 0;
	std::string strInput{};
	std::getline(input, strInput);
	std::regex regex("\\d+");
    auto begin = std::sregex_iterator(strInput.begin(), strInput.end(), regex);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        long long firstId = std::stoll(match.str());
        match = *(++i);
        long long secondId = std::stoll(match.str());
        std::cout << firstId << '-' << secondId << '\n';
        for(long long j = firstId; j <= secondId; j++){
        	std::string s = std::to_string(j);
        	std::string half = s.substr(0, s.length()/2);
        	std::string otherHalf = s.substr(s.length()/2);
         	if (half == otherHalf) {
          		password += j;
          	}
        }
    }
    std::cout << "Part 1:" << password << '\n';
}

void pt2(std::ifstream &input) {
	long long password = 0;
	std::string strInput{};
	std::getline(input, strInput);
	std::regex regex("\\d+");
    auto begin = std::sregex_iterator(strInput.begin(), strInput.end(), regex);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        long long firstId = std::stoll(match.str());
        match = *(++i);
        long long secondId = std::stoll(match.str());
        std::cout << firstId << '-' << secondId << '\n';
        for(long long j = firstId; j <= secondId; j++) {
        	std::string s = std::to_string(j);
         	int strLen = s.length();
         	for(int k = strLen/2; k >= 0; k--) {
         		std::regex regexInner(s.substr(0, k));
           		auto beginInner = std::sregex_iterator(s.begin(), s.end(), regexInner);
             	auto endInner = std::sregex_iterator();
              	int matches = std::distance(beginInner, endInner);
              	if(matches * k == strLen) {
               		password += j;
                 	break;
               	}
          	}
        }
    }
    std::cout << "Part 2:" << password << '\n';
}

int main() {
    // Part 1
    std::ifstream inf1{ "input.txt" };
    if (!inf1) {
        std::cerr << "Uh oh, the file couldn't be opened for reading\n";
        return 1;
    }
    pt1(inf1);
    inf1.close();

    // Part 2
    std::ifstream inf2{ "input.txt" };
    if (!inf2) {
        std::cerr << "Uh oh, the file couldn't be opened for reading\n";
        return 1;
    }
    pt2(inf2);
    inf2.close();

    return 0;
}
