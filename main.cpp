#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;

class BitBoard {
    uint32_t bb[3];
public:
    BitBoard() : bb{0, 0, 0} {}
uint32_t& operator [](size_t i) { return bb[i]; }
uint32_t const& operator [](size_t i) const { return bb[i]; }
BitBoard& operator &=(BitBoard const& rhs) {
    (*this)[0] &= rhs[0];
    (*this)[1] &= rhs[1];
    (*this)[2] &= rhs[2];
    return *this;
}
BitBoard operator &(BitBoard const& rhs) const {
    BitBoard result = *this;
    result &= rhs;
    return result;
}
bool operator ==(BitBoard const& rhs) const {
    return (*this)[0] == rhs[0] and (*this)[1] == rhs[1] and (*this)[2] == rhs[2];
}
bool operator !=(BitBoard const& rhs) const { return not ((*this)==rhs); }

BitBoard operator ~() const {
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
BitBoard& operator |=(BitBoard const& rhs) {
    (*this)[0] |= rhs[0];
    (*this)[1] |= rhs[1];
    (*this)[2] |= rhs[2];
    return *this;
}
BitBoard operator |(BitBoard const& rhs) const {
    BitBoard result = *this;
    result |= rhs;
    return result;
}

BitBoard& operator ^=(BitBoard const& rhs) {
    (*this)[0] ^= rhs[0];
    (*this)[1] ^= rhs[1];
    (*this)[2] ^= rhs[2];
    return *this;
}
BitBoard operator ^(BitBoard const& rhs) const {
    BitBoard result = *this;
    result ^= rhs;
    return result;
}



BitBoard operator <<(int i) const {
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
BitBoard operator >>(int i) const {
    assert(i==1);
    BitBoard result = (*this);
    result[0] >>= 9;
    result[0] += (((*this)[1]<<23)>>5);
    result[1] >>= 9;
    result[1] += (((*this)[2]<<23)>>5);
    result[2] >>= 9;
    return result;
}
std::ostream& print(std::ostream& out) const {
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
};

// links, rechts oben und unten jeweils eins abschneiden
BitBoard mat2bb(std::array<std::array<bool, 11>, 11> const& mat) {
    BitBoard result;
    for (size_t i=1; i!=10; ++i) {
        for (size_t j=1; j!=10; ++j) {
            result[(i-1)/3] += mat[i][j] * static_cast<uint32_t>(std::pow(2, j-1+ (i-1)*9 - 27*((i-1)/3)));
        }
    }
    return result;
}

// Goldgeneral unten nach oben (weiß) -------------------------------------------------------------------------------

std::array<BitBoard, 81> genWGGeneral() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+1][i%9+1+0] = true; // oben
        result1[i/9+1+0][i%9+1+1] = true; // links
        result1[i/9+1+1][i%9+1+1] = true; // oben links
        result1[i/9+1+1][i%9+1-1] = true; // oben rechts
        result1[i/9+1-1][i%9+1+0] = true; // unten
        result1[i/9+1+0][i%9+1-1] = true; // rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& WGGeneral() {
    static const std::array<BitBoard, 81> data = genWGGeneral();
    return data;
}
// gold over out----------------------------------------------------------------------------------------------------------------------
// Goldgeneral oben nach unten (schwarz) -------------------------------------------------------------------------------

std::array<BitBoard, 81> genSGGeneral() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+1][i%9+1+0] = true; // oben
        result1[i/9+1+0][i%9+1+1] = true; // links
        result1[i/9+1-1][i%9+1+1] = true; // unten links
        result1[i/9+1-1][i%9+1-1] = true; // unten rechts
        result1[i/9+1-1][i%9+1+0] = true; // unten
        result1[i/9+1+0][i%9+1-1] = true; // rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& SGGeneral() {
    static const std::array<BitBoard, 81> data = genSGGeneral();
    return data;
}
// gold over out----------------------------------------------------------------------------------------------------------------------
// König (beide Richtungen) ------------------------------------------------------------------------------------------------------

std::array<BitBoard, 81> genKing() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+1][i%9+1+0] = true; // oben
        result1[i/9+1+0][i%9+1+1] = true; // links
        result1[i/9+1+1][i%9+1+1] = true; // oben links
        result1[i/9+1+1][i%9+1-1] = true; // oben rechts
        result1[i/9+1-1][i%9+1+0] = true; // unten
        result1[i/9+1+0][i%9+1-1] = true; // rechts
        result1[i/9+1-1][i%9+1+1] = true; // unten links
        result1[i/9+1-1][i%9+1-1] = true; // unten rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& King() {
    static const std::array<BitBoard, 81> data = genKing();
    return data;
}
// king out over ------------------------------------------------------------------------------------------------------------

// silver general von unten nach oben ---------------------------------------------------------------------------------------

std::array<BitBoard, 81> genWSilver() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+1][i%9+1+0] = true; // oben
        result1[i/9+1+1][i%9+1+1] = true; // oben links
        result1[i/9+1+1][i%9+1-1] = true; // oben rechts
        result1[i/9+1-1][i%9+1+1] = true; // unten links
        result1[i/9+1-1][i%9+1-1] = true; // unten rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& WSilver() {
    static const std::array<BitBoard, 81> data = genWSilver();
    return data;
}

//--------------------------------------------------------------------------------------------------------------------------------
// silver general von oben nach unten(schwarz) ---------------------------------------------------------------------------------------

std::array<BitBoard, 81> genSSilver() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1-1][i%9+1+0] = true; // unten
        result1[i/9+1+1][i%9+1+1] = true; // oben links
        result1[i/9+1+1][i%9+1-1] = true; // oben rechts
        result1[i/9+1-1][i%9+1+1] = true; // unten links
        result1[i/9+1-1][i%9+1-1] = true; // unten rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& SSilver() {
    static const std::array<BitBoard, 81> data = genSSilver();
    return data;
}

//--------------------------------------------------------------------------------------------------------------------------------
// pawn von unten nach oben weiss
std::array<BitBoard, 81> genWPawn() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+1][i%9+1+0] = true; // oben
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& WPawn() {
    static const std::array<BitBoard, 81> data = genWPawn();
    return data;
}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
// pawn von oben nach unten (schwarz)
std::array<BitBoard, 81> genSPawn() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1-1][i%9+1+0] = true; // unten
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& SPawn() {
    static const std::array<BitBoard, 81> data = genSPawn();
    return data;
}

//--------------------------------------------------------------------------------

// knight von unten nach oben(weiss) -------------------------------------------------------------------------------------
std::array<BitBoard, 81> genWKnight() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=0; i!=72; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1+2][i%9+1+1] = true; // 2oben links
        result1[i/9+1+2][i%9+1-1] = true; // 2oben rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& WKnight() {
    static const std::array<BitBoard, 81> data = genWKnight();
    return data;
}

//--------------------------------------------------------------------------------

// knight von oben nach unten(schwarz)-------------------------------------------------------------------------------------
std::array<BitBoard, 81> genSKnight() {
    std::array<BitBoard, 81> result;

    std::array<std::array<bool, 11>, 11> result1;


    for (size_t i=9; i!=81; ++i) {
        for (auto &result11 : result1) {
            std::fill(begin(result11), end(result11), false);  // initialisieren mit 0 (false)
        }
        result1[i/9+1-2][i%9+1+1] = true; // 2oben links
        result1[i/9+1-2][i%9+1-1] = true; // 2oben rechts
        result[i] = mat2bb(result1);
    }
    return result;
}

std::array<BitBoard, 81> const& SKnight() {
    static const std::array<BitBoard, 81> data = genSKnight();
    return data;
}

//--------------------------------------------------------------------------------
/*zahl in zeile umwandeln
für jede mögliche zeile und position vom turm:
zulässiges Zugpattern ausgeben. links und rechts wird jeweils eins abgezogen*/
std::array<bool, 11> int2row(int row) {
    std::array<bool, 11> result;
    std::fill(begin(result), end(result), false);
    for (size_t i=8; i!=1; --i) {
        result[i] = (row%2);
        row /= 2;
    }
    return result;
}

// rank attack -------------------------------------------------------------------------------------
std::array<std::array<BitBoard, 81>,128> genRankAttack() { // 81 ist die Position der Figur (zweiter Index, einfach "durchzählen")
    // 128 (erster Index) ist das Blockpattern der Zeile der Figur. Es entsteht indem man die 7er Zeile bitweise als Integer iinterpretiert, wobei 1= da steht eine Fugur, 0 sonst.
    std:: array<std::array<BitBoard, 81>,128> result;



    for (int j = 0; j!=81;++j){
        auto currentRow = j/9;
        auto currentCol = j%9;
        for (int pattern=0; pattern!=128; ++pattern) {
            std::array<std::array<bool, 11>, 11> f;
            std::fill(begin(f), end(f), std::array<bool, 11>{false, false, false, false, false, false, false, false, false, false, false});
            auto bitboardPattern = int2row(pattern);
          auto upper = std::find(begin(bitboardPattern)+currentCol+1, end(bitboardPattern), true);
          auto lower = begin(bitboardPattern) + currentCol;
          while (lower!=begin(bitboardPattern)) {
              --lower;
              if (*lower == true) { break; }
          }
            std::fill(begin(bitboardPattern), end(bitboardPattern), false);  // alles false
            std::fill(lower, upper+1, true);  // mittlerer teil ist jetzt true
            f[currentRow+1] = bitboardPattern;
            result[pattern][j] = mat2bb(f);
     }
    }


return result;
}

std::array<std::array<BitBoard, 81>,128> const& RankAttack() {
    static const std:: array<std::array<BitBoard, 81>,128> data = genRankAttack();
    return data;
}


int getBlockPattern(BitBoard const& bb, size_t idx) {
    auto shift = (idx/9)%3;  // zeile in bitboard-drittel
    return bb[idx/27] << (9*(2-shift)+6) >> 25;  // Wollen 7 relevanten Einträge. Shiften dafür abhängig davon, in welcher Zeile wir sind, soweit nach rechts,
    // dass alles unwichtige null ist. Die 6 setzt sich zusammen aus den 5 die immer null sind und zusätzlich dem einen, das wir ignorieren, weil es am Rand ist.
    // Darum auch sieben statt 9 relevanten. Danach shiften wir wieder um 32-7 zurück. Die 7 sind die 7 die wir haben wollen.
}

//--------------------------------------------------------------------------------

size_t turnPiHalf(size_t idx) {  // drehe index (bzw. entsprechende figur) um 90° im Gegenuhrzeigersinn, 0 ursprünglich entspricht rechts unten. das heißt, wenn wir um pi/2 im gegenuhrzeigersinn drehen,
    // dann müsste die 0 rechts oben landen, also auf der 72. Dies erhält man mittels der Matrix wie folgt: Man nimmt einfach den 0. Eintrag des Arrays, und dieser ist, wie man
    // hie rauch sieht, 72 also der Index der Figur auf der gedrehten Position..
    static const std::array<size_t, 81> impl = { 72, 63, 54, 45, 36, 27, 18, 9, 0,
                                           73, 64, 55, 46, 37, 28, 19, 10, 1,
                                           74, 65, 56, 47, 38, 29, 20, 11, 2,
                                           75, 66, 57, 48, 39, 30, 21, 12, 3,
                                           76, 67, 58, 49, 40, 31, 22, 13, 4,
                                           77, 68, 59, 50, 41, 32, 23, 14, 5,
                                           78, 69, 60, 51, 42, 33, 24, 15, 6,
                                           79, 70, 61, 52, 43, 34, 25, 16, 7,
                                           80, 71, 62, 53, 44, 35, 26, 17, 8
                                         };
    return impl[idx];
}





// -°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°-°
// fileAttack
std::array<std::array<BitBoard, 81>,128> genFileAttack() { // 81 ist die Position der Figur (zweiter Index, einfach "durchzählen")
    // 128 (erster Index) ist das Blockpattern der Zeile der Figur. Es entsteht indem man die 7er Zeile bitweise als Integer iinterpretiert, wobei 1= da steht eine Figur, 0 sonst.
    // Wichtig: Das Blockpattern erhält man aus dem um pi/2 gedrehten Bitboard. Ein Beispiel:
    // Sagen wir, wir haben ein ungedrehtes Bitboard, bei dem in der rechtesten Spalte in der zweiten Reihe von unten, also auf Feld 9 eine Figur steht. Unser Turm steht auch in der rechtesten Reihe, sagen auf 18.
    // Nun drehen wir die Spalte und erhalten als Blockpattern, das die Spalte repräsentiert, 0000011 = 3 (inklusive Turm) (nach Abschneiden der beiden Randfelder). Jetzt genau wie rankAttack und am Ende zurückdrehen.
    std:: array<std::array<BitBoard, 81>,128> result;



    for (int j = 0; j!=81;++j){
        auto currentRow = j/9;
        auto currentCol = j%9;
        for (int pattern=0; pattern!=128; ++pattern) {
            std::array<std::array<bool, 11>, 11> f;
            std::fill(begin(f), end(f), std::array<bool, 11>{false, false, false, false, false, false, false, false, false, false, false});
            auto bitboardPattern = int2row(pattern);
          auto upper = std::find(begin(bitboardPattern)+currentCol+1, end(bitboardPattern), true);
          auto lower = begin(bitboardPattern) + currentCol;
          while (lower!=begin(bitboardPattern)) {
              --lower;
              if (*lower == true) { break; }
          }
            std::fill(begin(bitboardPattern), end(bitboardPattern), false);  // alles false
            std::fill(lower, upper+1, true);  // mittlerer teil ist jetzt true

            for (int i = 0 ; i!=11; ++i) // Hier drehen wir im Endeffekt zurück.
            {
                f[i][currentCol+1] = bitboardPattern[10-i];
            }
            result[pattern][j] = mat2bb(f);
     }
    }


return result;
}





std::array<std::array<BitBoard, 81>,128> const& FileAttack() {
    static const std:: array<std::array<BitBoard, 81>,128> data = genFileAttack();
    return data;
}

// End File Attack

//Begin Diagonal Attacks

size_t turnMinusPiFourth(size_t idx) {  // Dieses Array beantwortet im wesentlichen die folgende Frage:
    // Welche Position x wird auf Position y abgebildet durch Drehung um 45 Grad im Uhrzeigersinn.
    // Die Antwort erhält man wie folgt: Will man zum Beispiel wissen welche Zahl auf das erste Feld (wir zählen beim nullten los) abgebildet wird,
    // gucken wir in das erste Feld (wir zählen beim nullten los) der hier angegebenen Matrix, dort steht die 9 drin. Wir wissen also, dass das neunte Feld durch Drehung auf
    // das erste Feld abgebildet wird, was man leicht überprüft. Andersrum gedacht beantwortet dieses Array auch die folgende Frage: Betrachte eine Zahl a \in A. Sagen wir die 2.
    // Diese ist auf Position 5. Dies sagt folgendes aus: Feld zwei wird durch Drehung auf Feld 5 abgebildet.

     std::array<size_t, 81> impl =  { 0,
                                      9,1,
                                      18,10,2,
                                      27,19,11,3,
                                      36,28,20,12,4,
                                      45,37,29,21,13,5,
                                      54,46,38,30,22,14,6,
                                      63,55,47,39,31,23,15,7,
                                      72,64,56,48,40,32,24,16,8,
                                      73,65,57,49,41,33,25,17,
                                      74,66,58,50,42,34,26,
                                      75,67,59,51,43,35,
                                      76,68,60,52,44,
                                      77,69,61,53,
                                      78,70,62,
                                      79,71,
                                      80
                                         };

//     for(int j=0;j!=81;++j)
//     {
//         impl[j] = 80 - impl[j];
//     }
    // impl = {80,80,80,80,80,80,80,80,80,
      //       80,80,80,80,80,80,80,80,80,
        //     80,80,80,80,80,80,80,80,80,
          //   80,80,80,80,80,80,80,80,80,
            // 80,80,80,80,80,80,80,80,80,
            // 80,80,80,80,80,80,80,80,80,
             //80,80,80,80,80,80,80,80,80,
             //80,80,80,80,80,80,80,80,80,
             //80,80,80,80,80,80,80,80,80} - impl;
    return impl[idx];
}


size_t turnPiFourth(size_t idx) {  // drehe index (bzw. entsprechende figur) um 45° im Gegenuhrzeigersinn, 0 ursprünglich entspricht rechts unten.
    static const std::array<size_t, 81> impl = { 8,
                                                 7,17,
                                                 6,16,26,
                                                 5,15,25,35,
                                                 4,14,24,34,44,
                                                 3,13,23,33,43,53,
                                                 2,12,22,32,42,52,62,
                                                 1,11,21,31,41,51,61,71,
                                                 0,10,20,30,40,50,60,70,70,
                                                 9,19,29,39,49,59,69,79,
                                                 18,28,38,48,58,68,78,
                                                 27,37,47,57,67,77,
                                                 36,46,56,66,76,
                                                 45,55,65,75,
                                                 54,64,74,
                                                 63,73,
                                                 72
                                         };

//    for(int j=0;j!=81;++j)
//    {
//        impl[j] = 80 - impl[j];
//    }
    return impl[idx];
}

// TODO
// verkürzte Diagonalen müssen nicht aufgefüllt werden!
int getBlockPatternDiagonal(BitBoard const& bb, size_t idx) {
    auto shift = (idx/9)%3;  // zeile in bitboard-drittel
    return bb[idx/27] << (9*(2-shift)+6) >> 25;  // Wollen 7 relevanten Einträge. Shiften dafür abhängig davon, in welcher Zeile wir sind, soweit nach rechts,
    // dass alles unwichtige null ist. Die 6 setzt sich zusammen aus den 5 die immer null sind und zusätzlich dem einen, das wir ignorieren, weil es am Rand ist.
    // Darum auch sieben statt 9 relevanten. Danach shiften wir wieder um 32-7 zurück. Die 7 sind die 7 die wir haben wollen.
}



// diagonalRankAttack
std::array<std::array<BitBoard, 81>,128> genDiagonalLAttack() { // 81 ist die Position der Figur (zweiter Index, einfach "durchzählen")
    // 128 (erster Index) ist das Blockpattern der Zeile der Figur. Es entsteht indem man die 7er Zeile bitweise als Integer iinterpretiert, wobei 1= da steht eine Figur, 0 sonst.
    // Wichtig: Das Blockpattern erhält man aus dem um pi/2 gedrehten Bitboard. Ein Beispiel:
    // Sagen wir, wir haben ein ungedrehtes Bitboard, bei dem in der rechtesten Spalte in der zweiten Reihe von unten, also auf Feld 9 eine Figur steht. Unser Turm steht auch in der rechtesten Reihe, sagen auf 18.
    // Nun drehen wir die Spalte und erhalten als Blockpattern, das die Spalte repräsentiert, 0000011 = 3 (inklusive Turm) (nach Abschneiden der beiden Randfelder). Jetzt genau wie rankAttack und am Ende zurückdrehen.
    std:: array<std::array<BitBoard, 81>,128> result;



    for (int j = 0; j!=81;++j){  // die  position
        for (int pattern=0; pattern!=128; ++pattern) {  // das Diagonal-Pattern
            std::array<std::array<bool, 11>, 11> f;
            std::fill(begin(f), end(f), std::array<bool, 11>{false, false, false, false, false, false, false, false, false, false, false});
            auto bitboardPattern = int2row(pattern);
            auto diagIdx = min(j/9, j%9)+1;
            // upper und lower sind der nächstgrößere bzw nächstkleinere besetzte index
            auto upper = std::find(begin(bitboardPattern)+diagIdx+1, end(bitboardPattern), true);
            auto lower = begin(bitboardPattern) + diagIdx;
            while (lower!=begin(bitboardPattern)) {
                --lower;
                if (*lower == true) { break; }
            }
            std::fill(begin(bitboardPattern), end(bitboardPattern), false);  // alles false
            std::fill(lower, upper+1, true);  // mittlerer teil ist jetzt true

            // copy to diagonal
            for (int col=max(0, j%9-j/9), row=max(0, j/9-j%9), i=0 ; col!=11 and row!=11; ++col, ++row, ++i) // Hier drehen wir im Endeffekt zurück.
            {
                f[row][col] = bitboardPattern[i];
            }
            result[pattern][j] = mat2bb(f);
     }
    }


return result;
}


std::array<std::array<BitBoard, 81>,128> const& DiagonalLAttack() {
    const static auto data = genDiagonalLAttack();
    return data;
}


std::ostream& operator <<(std::ostream& out, BitBoard const& b) { return b.print(out); }

using namespace std;

//Testkommentar//



int main()
{
    auto row = int2row(16);
    for (auto const& f : row) { cout << f << endl; }
    cout << endl;
    auto data = FileAttack();
    cout << data[4][32] << endl << data[16][10] << endl ;
    //auto wgg = RankAttack();
    //cout << wgg[0] << endl << wgg[1] << endl << wgg[50] << endl << wgg[79] << endl << wgg[20] << endl;
    //BitBoard bb; bb[0] = 4; bb[1]=std::pow(2, 27)-1; bb[2] = std::pow(2, 27)-1;
    //cout << bb << endl;
    //cout << getBlockPattern(bb, 5) << endl;
    return 0;
}

