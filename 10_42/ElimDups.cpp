#include "ElimDups.h"

void elimDups(list<string>& words) {
    words.sort();
    words.unique();
}