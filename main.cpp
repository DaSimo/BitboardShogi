#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <array>
#include <algorithm>
#include "util.h"

#include "bitboard.h"
#include "MoveGeneration.h"
#include "game.h"
using namespace std;




//--------------------------------------------------------------------------------





using namespace std;

//Testkommentar//



int main()
{
//    auto row = int2row(16);
//    for (auto const& f : row) { cout << f << endl; }
//    cout << endl;
//    auto data = FileAttack();
//    cout << data[4][32] << endl << data[16][10] << endl ;
//    //auto wgg = RankAttack();
//    //cout << wgg[0] << endl << wgg[1] << endl << wgg[50] << endl << wgg[79] << endl << wgg[20] << endl;
//    //BitBoard bb; bb[0] = 4; bb[1]=std::pow(2, 27)-1; bb[2] = std::pow(2, 27)-1;
//    //cout << bb << endl;
//    //cout << getBlockPattern(bb, 5) << endl;
//    cout << "diagonal tests" << endl;
//    cout << DiagonalPiFourthAttack()[9][20] << endl;
//    cout << DiagonalMinusPiFourthAttack()[9][20] << endl;
//    cout << DiagonalPiFourthAttack()[1][3] << endl;
//    cout << DiagonalMinusPiFourthAttack()[1][3] << endl;
//    auto temp = DiagonalMinusPiFourthAttack()[1][3];
//    temp.setBit(11, 1);
//    cout << temp.getBit(10) << endl;

    for (int m=2; m<=2; ++m)
    {
        Game Spiel;
        Spiel.makeMove(80,m,1);
        Spiel.makeMove(0,72,0);
        for(int i =  0;i<81; ++i){
            cout<<"Zeile:" <<i/9<< " Spalte: " << i%9 << " ihhh: " << i <<endl;
            int a = 0;
            cin>>a;
            Game game("9/9/2K6/9/9/9/9/9/9 1");
            insert(game.Occupied, i);
            insert(game.Occupied90, turnPiHalf(i));
            std::cout<<"Züge die der Turm machen kann"<<std::endl;
            std::cout<<game.getMove(i,5,1)<<std::endl;
            std::cout<<getBlockPattern(game.Occupied, i) << std::endl << getBlockPattern(game.Occupied90, turnPiHalf( i)) << std::endl;
            std::cout << "game.Occupied90" << std::endl << game.Occupied90 << std::endl;
        }

  }

//    for (int i = 0;i<((int)pow(2,6));++i){
//        cout << "i: "<<i<<" inverted i: "<< inverted_bits(i)<<endl;
 //   }
//    cout << m<<endl<<Spiel<<endl;
//    cout <<getBlockPatternPiFourth(Spiel.Occupied45,m)<<" : ";
//    for (size_t i=0;i!=11;++i){
//        cout  <<int2row(getBlockPatternPiFourth(Spiel.Occupied45,m))[i] << " | ";
//    }
//    cout <<"\n- "<<getBlockPatternMinusPiFourth(Spiel.Occupied_45,m)<<" : ";
//    for (size_t i=0;i!=11;++i){
//        cout  <<int2row(getBlockPatternMinusPiFourth(Spiel.Occupied_45,m))[i]<< " | ";
//    }
//    cout <<endl;
//    cout <<1238748975;
//    cout <<"bla"<<endl;
//    cout << m<< endl<<Spiel.getMove(m,6,-1)<<endl;
//   cout <<endl;
//    }
//    BitBoard b;
//    b.bb[0]=int(pow(2,27))-1;
//    b.bb[2]=int(pow(2,27))-1;
//    b.bb[1]=int(pow(2,27))-1;
//    cout << b<<endl;
//    cout << "block pattern: " << getBlockPatternPiFourth(b,m)<<endl;
//    for (size_t i=0;i!=11;++i){
//        cout <<int2row(getBlockPatternPiFourth(b,m))[i];
//    }
//    //cout<<endl<<"BlockPattern: "<< getBlockPatternPiFourth(Spiel.Occupied45,42);
//    cout <<endl<<Spiel.Occupied45;
//   cout <<endl;




    return 0;

}

