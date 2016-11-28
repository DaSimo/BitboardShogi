#ifndef UTIL_H
#define UTIL_H

#include <iosfwd>

template <typename T, size_t N>
std::ostream& operator <<(std::ostream& out, std::array<T, N> const& v) {
    out << "[ ";
    for (auto const& e : v) { out << e << " "; }
    out << "]";
    return out;
}

#endif // UTIL_H
