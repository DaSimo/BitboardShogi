#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <array>
#include <cassert>
#include <iostream>
#include <cmath>

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
};

// links, rechts oben und unten jeweils eins abschneiden
BitBoard mat2bb(std::array<std::array<bool, 11>, 11> const& mat);
BitBoard setBit(int place, int bit);
std::ostream& operator <<(std::ostream& out, BitBoard const& b);
#endif // BITBOARD_H
