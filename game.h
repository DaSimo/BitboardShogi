#ifndef GAME_H
#define GAME_H
#include "bitboard.h"
#include"MoveGeneration.h"

#include <iosfwd>

class Game
{
  BitBoard Occupied;
  BitBoard Occupied90;
  BitBoard Occupied45;
  BitBoard Occupied_45;

  std::array<std::array<BitBoard,16>,2> OccupiedPieces; // (0,*) sind die schwarzen Figuren (1,*) die weißen

  BitBoard& OccupiedBlack() { return OccupiedPieces[0][0]; }
  BitBoard& OccupiedBlackPawn() { return OccupiedPieces[0][1]; }
  BitBoard& OccupiedBlackKnight() { return OccupiedPieces[0][2]; }
  BitBoard& OccupiedBlackLance() { return OccupiedPieces[0][3]; }
  BitBoard& OccupiedBlackSilver() { return OccupiedPieces[0][4]; }
  BitBoard& OccupiedBlackGold() { return OccupiedPieces[0][5]; }
  BitBoard& OccupiedBlackBishop() { return OccupiedPieces[0][6]; }
  BitBoard& OccupiedBlackRook() { return OccupiedPieces[0][7]; }
  BitBoard& OccupiedBlackKing() { return OccupiedPieces[0][8]; }
  BitBoard& OccupiedBlackPawnUp() { return OccupiedPieces[0][9]; }
  BitBoard& OccupiedBlackKnightUp() { return OccupiedPieces[0][10]; }
  BitBoard& OccupiedBlackLanceUp() { return OccupiedPieces[0][11]; }
  BitBoard& OccupiedBlackSilverUp() { return OccupiedPieces[0][12]; }
  BitBoard& OccupiedBlackGoldUp() { return OccupiedPieces[0][13]; }
  BitBoard& OccupiedBlackBishopUp() { return OccupiedPieces[0][14]; }
  BitBoard& OccupiedBlackRookUp() { return OccupiedPieces[0][15]; }


  BitBoard& OccupiedWhite() { return OccupiedPieces[1][0]; }
  BitBoard& OccupiedWhitePawn() { return OccupiedPieces[1][1]; }
  BitBoard& OccupiedWhiteKnight() { return OccupiedPieces[1][2]; }
  BitBoard& OccupiedWhiteLance() { return OccupiedPieces[1][3]; }
  BitBoard& OccupiedWhiteSilver() { return OccupiedPieces[1][4]; }
  BitBoard& OccupiedWhiteGold() { return OccupiedPieces[1][5]; }
  BitBoard& OccupiedWhiteBishop() { return OccupiedPieces[1][6]; }
  BitBoard& OccupiedWhiteRook() { return OccupiedPieces[1][7]; }
  BitBoard& OccupiedWhiteKing() { return OccupiedPieces[1][8]; }
  BitBoard& OccupiedWhitePawnUp() { return OccupiedPieces[1][9]; }
  BitBoard& OccupiedWhiteKnightUp() { return OccupiedPieces[1][10]; }
  BitBoard& OccupiedWhiteLanceUp() { return OccupiedPieces[1][11]; }
  BitBoard& OccupiedWhiteSilverUp() { return OccupiedPieces[1][12]; }
  BitBoard& OccupiedWhiteGoldUp() { return OccupiedPieces[1][13]; }
  BitBoard& OccupiedWhiteBishopUp() { return OccupiedPieces[1][14]; }
  BitBoard& OccupiedWhiteRookUp() { return OccupiedPieces[1][15]; }

  //todo Bitboards für beförderte Figuren hinzufügen

  std::array<std::array<int,7>,2> CapturedPieces; //Array enthält Anzahl an geschlagenen Figuren
  int move; //Movemarker 1= white; -1 = black

  friend std::ostream & operator <<(std::ostream &, Game &);
public:
    Game();
   // Ein Zug ist ein Tupel der Form (Ursprungsfeld,Ziehlfeld,Promotionsbit)
    void makeMove(int org, int dest , bool up);
    int index(int move_);
    BitBoard getMove(int org, int move);
    BitBoard getMove(int org, int piece, int move);
};



std::ostream & operator <<(std::ostream & out, Game & g);

#endif // GAME_H
