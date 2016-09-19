#ifndef GAME_H
#define GAME_H
#include "bitboard.h"
#include"MoveGeneration.h"


class Game
{
  BitBoard Occupied;
  BitBoard Occupied90;
  BitBoard Occupied45;
  BitBoard Occupied_45;

  BitBoard OccupiedBlack;
  BitBoard OccupiedBlackPawn;
  BitBoard OccupiedBlackKnight;
  BitBoard OccupiedBlackLance;
  BitBoard OccupiedBlackSilver;
  BitBoard OccupiedBlackGold;
  BitBoard OccupiedBlackBishop;
  BitBoard OccupiedBlackRook;
  BitBoard OccupiedBlackKing;

  BitBoard OccupiedWhite;
  BitBoard OccupiedWhitePawn;
  BitBoard OccupiedWhiteKnight;
  BitBoard OccupiedWhiteLance;
  BitBoard OccupiedWhiteSilver;
  BitBoard OccupiedWhiteGold;
  BitBoard OccupiedWhiteBishop;
  BitBoard OccupiedWhiteRook;
  BitBoard OccupiedWhiteKing;


public:
    Game();
   // Ein Zug ist ein Tupel der Form (Ursprungsfeld,Ziehlfeld,Promotionsbit)


};

#endif // GAME_H
