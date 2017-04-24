#define BOOST_TEST_MODULE Our tests
#include <boost/test/included/unit_test.hpp>
#include "bitboard.h"
#include "game.h"
#include <boost/regex.hpp>


BOOST_AUTO_TEST_SUITE(bitboard_tests)

BOOST_AUTO_TEST_CASE(insert_test)
{
    BitBoard board;
    insert(board, 45);
    BOOST_CHECK( (board[0]==0)&&(board[1]==(uint32_t)pow(2,45-27))&(board[2]==0) );
}

BOOST_AUTO_TEST_CASE(insert_test2)
{
    BitBoard board;
    insert(board, 5);
    BOOST_CHECK( (board[0]==32)&&(board[1]==0)&(board[2]==0) );
}

BOOST_AUTO_TEST_CASE(insert_test3)
{
    BitBoard board;
    insert(board, 75);
    BOOST_CHECK( (board[0]==0)&&(board[2]==(uint32_t)pow(2,75-54))&(board[1]==0) );
}

/*BOOST_AUTO_TEST_CASE(insert_test2)
{
    BitBoard board;
    insert(board, 45);
    boost::regex r("(0\\s?){44}1\\s?(0\\s?){37}");
    BOOST_CHECK( boost::regex_match(board.toString().begin(), board.toString().end(), r ) );

}*/

BOOST_AUTO_TEST_CASE(insert_king)
{
    Game game("9/9/9/4K4/9/9/9/9/9 0 P1");
    std::cout<<game;
    BOOST_CHECK( (game.Occupied[0]==0)&&(game.Occupied[1]==(uint32_t)pow(2,4))&&(game.Occupied[2]==0) );
}

BOOST_AUTO_TEST_CASE(insert_rook)
{
    Game game("rrr6/9/9/4r4/9/9/9/9/6r2 1");
    std::cout<<game;
    BOOST_CHECK( (game.Occupied[0]==7)&&(game.Occupied[1]==(uint32_t)pow(2,4))&&(game.Occupied[2]==(uint32_t)pow(2,24)) );
}


BOOST_AUTO_TEST_CASE(insert_starting_position)
{
    //Game game("LNSGKGSNL/1B5R1/PPPPPPPPP/9/9/9/ppppppppp/1r5b1/lnsgkgsnl 1");
    Game game("9/9/2K6/9/9/9/9/2r6/9 1");
    std::cout<<game;
}

BOOST_AUTO_TEST_CASE(check_rook)
{
    Game game("9/9/2K6/9/9/9/9/2r6/9 1");
    std::cout<<"Züge die der Turm machen kann"<<std::endl;
    std::cout<<game.getMove(56,5,1)<<std::endl;
    std::cout<<getBlockPattern(game.Occupied, 65) << std::endl << getBlockPattern(game.Occupied90, turnPiHalf( 65)) << std::endl;
    std::cout << "game.Occupied90" << std::endl << game.Occupied90 << std::endl;
    std::cout<<game;
}

BOOST_AUTO_TEST_CASE(TestMat2bb)
{
    std::array<bool,81> DummyArray81{};
    std::array<std::array<bool,9>,9> DummyArray9x9{};
    DummyArray81[3]=true;
    DummyArray81[13]=true;
    DummyArray81[23]=true;
    DummyArray81[53]=true;
    DummyArray9x9[0][3]=true;
    DummyArray9x9[1][4]=true;
    DummyArray9x9[2][5]=true;
    DummyArray9x9[5][8]=true;
    auto Dummybb81=mat2bb(DummyArray81);
    auto Dummybb9x9=mat2bb(DummyArray9x9);
    std::cout<<Dummybb81<<std::endl;
    std::cout<<Dummybb9x9<<std::endl;
    BOOST_CHECK(Dummybb81==Dummybb9x9);

}

BOOST_AUTO_TEST_CASE(TestGetBlockPattern)
{
    BitBoard TestBoard();


}

//BOOST_AUTO_TEST_CASE(FindZero)
//{
//    std::cout<<"-------BEGIN FIND ZERO-------------------------------------" <<std::endl;
//    Game game1("K8/9/9/9/9/9/9/9/9 1");
//    std::cout<<game1;
//    std::cout << "game1.Occupied" << std::endl << game1.Occupied << std::endl;

//    Game game2("9/9/9/9/9/9/9/9/8K 1");
//    std::cout<<game2;
//    std::cout << "game2.Occupied" << std::endl << game2.Occupied << std::endl;

//    Game game3("9/9/9/9/9/9/9/9/9 1");
//    insert(game3.OccupiedPieces[1][1],1);
//    std::cout<<game3;
//    std::cout << "game3.Occupied" << std::endl << game3.Occupied << std::endl;





//    std::cout<<"-------END FIND ZERO-------------------------------------" <<std::endl;

//}


BOOST_AUTO_TEST_CASE(second_test)
{

    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(third_test)
{

    BOOST_CHECK( true );
}
