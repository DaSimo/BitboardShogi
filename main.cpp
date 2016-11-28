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
    int m=44;
    Spiel.makeMove(80,m,1);
    //Spiel.makeMove(0,72,0);
    cout << Spiel<<endl;
    cout << Spiel.getMove(m,6,-1)<<endl;
    for (size_t i=0;i!=11;++i){
        cout <<int2row(getBlockPatternPiFourth(Spiel.Occupied45,m))[i];
    }
    cout <<endl;
    BitBoard b;
    b.bb[0]=int(pow(2,27))-1;
    b.bb[2]=int(pow(2,27))-1;
    b.bb[1]=int(pow(2,27))-1;
    cout << b<<endl;
    cout << "block pattern: " << getBlockPatternPiFourth(b,m)<<endl;
    for (size_t i=0;i!=11;++i){
        cout <<int2row(getBlockPatternPiFourth(b,m))[i];
    }
    //cout<<endl<<"BlockPattern: "<< getBlockPatternPiFourth(Spiel.Occupied45,42);
    cout <<endl<<Spiel.Occupied45;
   cout <<endl;




    return 0;

}

