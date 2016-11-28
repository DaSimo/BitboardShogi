#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <array>
#include <algorithm>

#include "bitboard.h"
#include "MoveGeneration.h"
#include "game.h"
using namespace std;




//--------------------------------------------------------------------------------





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
    cout << "diagonal tests" << endl;
    cout << DiagonalPiFourthAttack()[9][20] << endl;
    cout << DiagonalMinusPiFourthAttack()[9][20] << endl;
    cout << DiagonalPiFourthAttack()[1][3] << endl;
    cout << DiagonalMinusPiFourthAttack()[1][3] << endl;
    auto temp = DiagonalMinusPiFourthAttack()[1][3];
    temp.setBit(11, 1);
    cout << temp.getBit(10) << endl;
    Game Spiel;
    Spiel.makeMove(80,42,1);
    //Spiel.makeMove(0,72,0);
    cout << Spiel<<endl;
    cout << Spiel.getMove(42,6,-1)<<endl;
    for (size_t i=0;i!=11;++i){
        cout <<int2row(getBlockPatternMinusPiFourth(Spiel.Occupied_45,42))[i];
    }
    cout<<endl<< getBlockPatternMinusPiFourth(Spiel.Occupied_45,42);
    cout <<endl<<Spiel.Occupied_45;
   cout <<endl;




    return 0;

}

