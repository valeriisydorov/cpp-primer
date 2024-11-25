#include "Dynamic.h"

int main() {
    shared_ptr<vector<int>> vi = createVector();

    readVector(*vi);

    writeVector(*vi);

    return 0;
}
