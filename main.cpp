#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <array>
#include <algorithm>

#include "bitboard.h"
#include "MoveGeneration.h"

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
    return 0;
}

