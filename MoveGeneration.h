#ifndef MOVEGENERATION_H
#define MOVEGENERATION_H

#include <array>

#include "bitboard.h"

// Goldgeneral unten nach oben (weiß) -------------------------------------------------------------------------------

std::array<BitBoard, 81> genWGGeneral();

inline std::array<BitBoard, 81> const& WGGeneral() {
    static const std::array<BitBoard, 81> data = genWGGeneral();
    return data;
}
// gold over out----------------------------------------------------------------------------------------------------------------------
// Goldgeneral oben nach unten (schwarz) -------------------------------------------------------------------------------

std::array<BitBoard, 81> genSGGeneral();

inline std::array<BitBoard, 81> const& SGGeneral() {
    static const std::array<BitBoard, 81> data = genSGGeneral();
    return data;
}
// gold over out----------------------------------------------------------------------------------------------------------------------
// König (beide Richtungen) ------------------------------------------------------------------------------------------------------

std::array<BitBoard, 81> genKing();

inline std::array<BitBoard, 81> const& King() {
    static const std::array<BitBoard, 81> data = genKing();
    return data;
}
// king out over ------------------------------------------------------------------------------------------------------------

// silver general von unten nach oben ---------------------------------------------------------------------------------------

std::array<BitBoard, 81> genWSilver();

inline std::array<BitBoard, 81> const& WSilver() {
    static const std::array<BitBoard, 81> data = genWSilver();
    return data;
}

//--------------------------------------------------------------------------------------------------------------------------------
// silver general von oben nach unten(schwarz) ---------------------------------------------------------------------------------------

std::array<BitBoard, 81> genSSilver();

inline std::array<BitBoard, 81> const& SSilver() {
    static const std::array<BitBoard, 81> data = genSSilver();
    return data;
}

//--------------------------------------------------------------------------------------------------------------------------------
// pawn von unten nach oben weiss
std::array<BitBoard, 81> genWPawn();

inline std::array<BitBoard, 81> const& WPawn() {
    static const std::array<BitBoard, 81> data = genWPawn();
    return data;
}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
// pawn von oben nach unten (schwarz)
std::array<BitBoard, 81> genSPawn();

inline std::array<BitBoard, 81> const& SPawn() {
    static const std::array<BitBoard, 81> data = genSPawn();
    return data;
}

//--------------------------------------------------------------------------------

// knight von unten nach oben(weiss) -------------------------------------------------------------------------------------
std::array<BitBoard, 81> genWKnight();

inline std::array<BitBoard, 81> const& WKnight() {
    static const std::array<BitBoard, 81> data = genWKnight();
    return data;
}

//--------------------------------------------------------------------------------

// knight von oben nach unten(schwarz)-------------------------------------------------------------------------------------
std::array<BitBoard, 81> genSKnight();

inline std::array<BitBoard, 81> const& SKnight() {
    static const std::array<BitBoard, 81> data = genSKnight();
    return data;
}
std::array<bool, 11> int2row(int row);
std::array<std::array<BitBoard, 81>,128> genRankAttack();
std::array<std::array<BitBoard, 81>,128> const& RankAttack();
int getBlockPattern(BitBoard const& bb, size_t idx);
size_t turnPiHalf(size_t idx);
std::array<std::array<BitBoard, 81>,128> genFileAttack();
std::array<std::array<BitBoard, 81>,128> const& FileAttack();
size_t turnMinusPiFourth(size_t idx);
size_t turnPiFourth(size_t idx);
size_t getRightShift(size_t idx);
size_t getLeftShift(size_t idx);
size_t getBitboardNumber(size_t idx);
int getBlockPatternPiFourth(BitBoard const& bb, size_t idx);
int getBlockPatternMinusPiFourth(BitBoard const& bb, size_t idx);
std::array<std::array<BitBoard, 81>,128> genDiagonalPiFourthAttack();
std::array<std::array<BitBoard, 81>,128> genDiagonalMinusPiFourthAttack();
std::array<std::array<BitBoard, 81>,128> const& DiagonalPiFourthAttack();
std::array<std::array<BitBoard, 81>,128> const& DiagonalMinusPiFourthAttack();

#endif // MOVEGENERATION_H
