#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> library = {{"Donald Knuth", "The Art of Computer Programming"},
                                                  {"Donald Knuth", "Stable Marriage and Its Relation to Other Combinatorial Problems"},
                                                  {"Edsger Dijkstra", "A Discipline of Programming"},
                                                  {"David Gries", "The Science of Programming"},
                                                  {"Jon Bentley", "Programming Pearls"}};
    std::multimap<std::string, std::string>::key_type author = std::string("Donald Knuth");
    std::multimap<std::string, std::string>::iterator it = library.find(author);
    std::multimap<std::string, std::string>::size_type count = library.count(author);

    while (count) {
        it = library.erase(it);
        --count;
    }

    return 0;
}
