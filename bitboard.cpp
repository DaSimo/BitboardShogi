#include "bitboard.h"
#include <sstream>

using namespace std;

BitBoard& BitBoard::operator &=(BitBoard const& rhs) {
    (*this)[0] &= rhs[0];
    (*this)[1] &= rhs[1];
    (*this)[2] &= rhs[2];
    return *this;
}

std::ostream& BitBoard::print(std::ostream& out) const {
    for (int idx=2; idx!=-1; -- idx) {
        for (uint32_t row=0, cp=bb[idx]; row!=3; ++row) {
            for (uint32_t i=0; i!=9; ++i) {
                out << cp/static_cast<uint32_t>(std::pow(2,26));
                cp *= 2;
                cp&=static_cast<uint32_t>(std::pow(2,27)-1);
            }
            out << endl;
        }
    }
    out << endl;
    //out << bb[0] << endl << bb[1] << endl << bb[2] << endl;
    return out;
}

std::string BitBoard::toString() const
{
    std::ostringstream os;
    os << *this;
    return os.str();
}


bool BitBoard::operator ==(BitBoard const& rhs) const {
    return (*this)[0] == rhs[0] and (*this)[1] == rhs[1] and (*this)[2] == rhs[2];
}
bool BitBoard::operator !=(BitBoard const& rhs) const { return not ((*this)==rhs); }
BitBoard BitBoard::operator ~() const {
    BitBoard result;
    result[0] = ~ (*this)[0];
    result[1] = ~ (*this)[1];
    result[2] = ~ (*this)[2];
    result[0] <<= 5;
    result[0] >>= 5;
    result[1] <<= 5;
    result[1] >>= 5;
    result[2] <<= 5;
    result[2] >>= 5;
    return result;
}
BitBoard& BitBoard::operator |=(BitBoard const& rhs) {
    (*this)[0] |= rhs[0];
    (*this)[1] |= rhs[1];
    (*this)[2] |= rhs[2];
    return *this;
}
BitBoard BitBoard::operator |(BitBoard const& rhs) const {
    BitBoard result = *this;
    result |= rhs;
    return result;
}
BitBoard& BitBoard::operator ^=(BitBoard const& rhs) {
    (*this)[0] ^= rhs[0];
    (*this)[1] ^= rhs[1];
    (*this)[2] ^= rhs[2];
    return *this;
}
BitBoard BitBoard::operator ^(BitBoard const& rhs) const {
    BitBoard result = *this;
    result ^= rhs;
    return result;
}
BitBoard BitBoard::operator <<(int i) const {
    assert(i==1);  // Board<<1
    BitBoard result = (*this);
    result[2] <<= 14;
    result[2] >>= 5;
    result[2] += ((*this)[1] >> 18);
    result[1] <<= 14;
    result[1] >>= 5;
    result[1] += ((*this)[0] >> 18);
    result[0] <<= 14;
    result[0] >>= 5;
    return result;
}
BitBoard BitBoard::operator >>(int i) const {
    assert(i==1);
    BitBoard result = (*this);
    result[0] >>= 9;
    result[0] += (((*this)[1]<<23)>>5);
    result[1] >>= 9;
    result[1] += (((*this)[2]<<23)>>5);
    result[2] >>= 9;
    return result;
}
void BitBoard::setBit(int place, int bit)
{
    auto temp = (*this)[place/27];
    (*this)[place/27] = ((((*this)[place/27]>>((place%27)+1))<<1)+bit)<<(place%27); // operator[]
    temp = (temp<<1<<(31-(place%27)))>>((32-(place%27)));
    (*this)[place/27]+=temp;
}
bool BitBoard::getBit(int place)
{
    return ((*this)[place/27] >>(place%27))%2;
}

std::ostream& operator <<(std::ostream& out, BitBoard const& b) { return b.print(out); }

BitBoard mat2bb(std::array<std::array<bool, 9>, 9> const& mat) {
    BitBoard result;
    for (size_t i=0; i!=9; ++i) {
        for (size_t j=0; j!=9; ++j) {
            result[(i)/3] += mat[i][j] * static_cast<uint32_t>(std::pow(2, j+ (i)*9 - 27*((i)/3)));
        }
    }
    return result;
}

BitBoard mat2bb(std::array<std::array<bool, 11>, 11> const& mat) {
    BitBoard result;
    for (size_t i=1; i!=10; ++i) {
        for (size_t j=1; j!=10; ++j) {
            result[(i-1)/3] += mat[i][j] * static_cast<uint32_t>(std::pow(2, j-1+ (i-1)*9 - 27*((i-1)/3)));
        }
    }
    return result;
}

BitBoard mat2bb(std::array<bool, 81> const& mat) {
    BitBoard result;
    for (size_t i_=0; i_!=81; ++i_) {
        size_t i=i_/9, j =i_%9;
        result[(i)/3] += mat[i_] * static_cast<uint32_t>(std::pow(2, j+ (i)*9 - 27*((i)/3)));
    }
    return result;
}
void insert(BitBoard& board,int index)
{

    board[index/27]|=(uint32_t)pow(2,(index%27));
}
