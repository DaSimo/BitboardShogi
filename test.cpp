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
    Game game("9/9/9/4K4/9/9/9/9/9");
    std::cout<<game;
    BOOST_CHECK( (game.Occupied[0]==0)&&(game.Occupied[1]==(uint32_t)pow(2,4))&&(game.Occupied[2]==0) );
}

BOOST_AUTO_TEST_CASE(insert_rook)
{
    Game game("rrr6/9/9/4r4/9/9/9/9/6r2");
    std::cout<<game;
    BOOST_CHECK( (game.Occupied[0]==7)&&(game.Occupied[1]==(uint32_t)pow(2,4))&&(game.Occupied[2]==(uint32_t)pow(2,24)) );
}


BOOST_AUTO_TEST_CASE(second_test)
{

    BOOST_CHECK( true );
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(third_test)
{

    BOOST_CHECK( true );
}
