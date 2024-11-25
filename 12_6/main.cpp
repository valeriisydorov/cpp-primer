#include "Dynamic.h"

int main() {
    vector<int>* vi = createVector();

    readVector(vi);

    writeVector(vi);

    delete vi;
    vi = nullptr;

    return 0;
}
