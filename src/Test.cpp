#include "Test.h"

int Test::execute(const std::string& sss, int iii, bool bbb) { // NOLINT(readability-convert-member-functions-to-static)
    if (!this) {
        return 0;
    }
    std::cout << sss << " " << iii << " " << bbb << "\n";
    return iii;
}