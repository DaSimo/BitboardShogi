#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <array>
#include <cassert>
#include <iostream>
#include <cmath>
#include <initializer_list>
#include <algorithm>

class BitBoard {
    uint32_t bb[3];
public:
    BitBoard() : bb{0, 0, 0} {}
uint32_t& operator [](size_t i) { return bb[i]; }
uint32_t const& operator [](size_t i) const { return bb[i]; }
BitBoard& operator &=(BitBoard const& rhs);
BitBoard operator &(BitBoard const& rhs) const {
    BitBoard result = *this;
    result &= rhs;
    return result;
}
bool operator ==(BitBoard const& rhs) const;
bool operator !=(BitBoard const& rhs) const;
BitBoard operator ~() const;
BitBoard& operator |=(BitBoard const& rhs);
BitBoard operator |(BitBoard const& rhs) const ;

BitBoard& operator ^=(BitBoard const& rhs);
BitBoard operator ^(BitBoard const& rhs) const;



BitBoard operator <<(int i) const;
BitBoard operator >>(int i) const;
std::ostream& print(std::ostream& out) const ;
void setBit(int place, int bit);
bool getBit(int place);
std::string toString() const;
};



BitBoard mat2bb(std::array<bool, 81> const& mat);
template <typename I>
inline BitBoard mat2bb(std::array<I, 81> const& mat);
BitBoard mat2bb(std::array<bool, 81> const& mat);
template <typename T>
BitBoard mat2bb(std::initializer_list<T> ints) {
    std::array<bool, 81> result;
    std::copy(begin(ints), end(ints), begin(result));
    return mat2bb(result);
}
BitBoard mat2bb(std::array<std::array<bool, 9>, 9> const& mat);
// links, rechts oben und unten jeweils eins abschneiden
BitBoard mat2bb(std::array<std::array<bool, 11>, 11> const& mat);
std::ostream& operator <<(std::ostream& out, BitBoard const& b);


template <typename I>
inline BitBoard mat2bb(std::array<I, 81> const& mat) {
    BitBoard result;
    for (size_t i_=0; i_!=81; ++i_) {
        size_t i=i_/9, j =i_%9;
        result[(i)/3] += static_cast<bool>(mat[i_]) * static_cast<uint32_t>(std::pow(2, j+ (i)*9 - 27*((i)/3)));
    }
    return result;
}

//todo insert funktion schreiben
void insert(BitBoard& board,int index);

#endif // BITBOARD_H
