#include "Test.h"

int Test::execute(const std::string& sss, int iii, bool bbb) {
    if (!this) {
        return 0;
    }
    std::cout << sss << " " << iii << " " << bbb << "\n";
    return iii;
}