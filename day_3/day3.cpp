#include <fstream>
#include <iostream>
#include <cmath>

long generalSolution(std::ifstream &input, int digits) {
    std::string strInput{};
    long password = 0;

    while (std::getline(input, strInput)) {
        int index = 0;
        int length = strInput.length();

        for(int times = digits-1; times >= 0; times--){
            long max = 0;

            for(int i = index; i < length-times; i++) {
                // The - '0' is there because the char digits
                // start at '0' which is usually, but not always, 48
                if( (strInput[i] - '0') > max) {
                    max = strInput[i] - '0';
                    index = i+1;
                }
                if (strInput[i] == '9')
                    break;
                // No need to keep looping
            }
            password += max * pow(10, times);
        }
    }

    return password;
}

void pt1(std::ifstream &input) {
    long password = generalSolution(input, 2);
    std::cout << "Part 1:" << password << '\n';
}

void pt2(std::ifstream &input) {
    long password = generalSolution(input, 12);
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
