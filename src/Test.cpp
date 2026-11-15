#include <string>
#include <iostream>

class Test {
public:
    int execute(std::string s, int i, bool b) {
        std::cout << s << " " << i << " " << b << std::endl;
        return i;
    }
};