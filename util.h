#ifndef UTIL_H
#define UTIL_H

#include <iosfwd>
#include <sstream>
#include <string>
#include <vector>

template <typename T, size_t N>
std::ostream& operator <<(std::ostream& out, std::array<T, N> const& v) {
    out << "[ ";
    for (auto const& e : v) { out << e << " "; }
    out << "]";
    return out;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim=' ') {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

#endif // UTIL_H
