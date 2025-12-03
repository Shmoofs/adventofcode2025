#include <fstream>
#include <iostream>

void pt1(std::ifstream &input) {
	char ch;
    int max1 = 0;
    int max2 = 0;
    int password = 0;

    while (input.get(ch)) {
    	if (ch == '\n' || ch == '\0') {
     		password += (max1 * 10) + max2;
       		max1 = 0;
         	max2 = 0;
     	}
     	if (ch >= max1) {
      		max1 = max2;
      		max2 = ch;
      	}
    }

    std::cout << "Part 1:" << password << '\n';
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

    // // Part 2
    // std::ifstream inf2{ "input.txt" };
    // if (!inf2) {
    //     std::cerr << "Uh oh, the file couldn't be opened for reading\n";
    //     return 1;
    // }
    // pt2(inf2);
    // inf2.close();

    return 0;
}
