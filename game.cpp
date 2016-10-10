#include "game.h"
#include <iomanip>

Game::Game() :
    Occupied(mat2bb({1,1,1,1,1,1,1,1,1,
                    0,1,0,0,0,0,0,1,0,
                    1,1,1,1,1,1,1,1,1,
                    0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,
                    1,1,1,1,1,1,1,1,1,
                    0,1,0,0,0,0,0,1,0,
                    1,1,1,1,1,1,1,1,1
                    })),
    Occupied90(mat2bb({  1,0,1,0,0,0,1,0,1,
                      1,1,1,0,0,0,1,1,1,
                      1,0,1,0,0,0,1,0,1,
                      1,0,1,0,0,0,1,0,1,
                      1,0,1,0,0,0,1,0,1,
                      1,0,1,0,0,0,1,0,1,
                      1,0,1,0,0,0,1,0,1,
                      1,1,1,0,0,0,1,1,1,
                      1,0,1,0,0,0,1,0,1
                      })),



    CapturedPieces{{std::array<int,7>{{0,0,0,0,0,0,0}}, std::array<int,7>{{0,0,0,0,0,0,0}}}},
move(1)
{



    {
        std::array<int, 81> temp={1,1,1,1,1,1,1,1,1,
                              0,1,0,0,0,0,0,1,0,
                              1,1,1,1,1,1,1,1,1,
                              0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,
                              1,1,1,1,1,1,1,1,1,
                              0,1,0,0,0,0,0,1,0,
                              1,1,1,1,1,1,1,1,1
                             };
        std::array<int, 81> temp45=temp;
        std::array<int, 81> temp_45=temp;
        for (int i=0;i<81;++i)
        {
            temp45[i]=turnPiFourth(temp[i]);
            temp_45[i] =turnMinusPiFourth(temp[i]);
        }
        Occupied45=mat2bb(temp45);
        Occupied_45=mat2bb(temp_45);

    }

    //todo wo steht schwarz und wo zieht er hin????????????
    OccupiedBlack()=mat2bb({1,1,1,1,1,1,1,1,1,
                           0,1,0,0,0,0,0,1,0,
                           1,1,1,1,1,1,1,1,1,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0
});

OccupiedBlackPawn()=mat2bb({0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           1,1,1,1,1,1,1,1,1,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0
                           });
OccupiedBlackKnight()=mat2bb({0,1,0,0,0,0,0,1,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0
                             });
OccupiedBlackLance()=mat2bb({1,0,0,0,0,0,0,0,1,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0
                            });
OccupiedBlackSilver()=mat2bb({0,0,1,0,0,0,1,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0
                             });
OccupiedBlackGold()=mat2bb({0,0,0,1,0,1,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0
                           });
OccupiedBlackBishop()=mat2bb({0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,1,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0
                             });
OccupiedBlackRook()=mat2bb({   0,0,0,0,0,0,0,0,0,
                             0,1,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0
                             });
OccupiedBlackKing()=mat2bb({   0,0,0,0,1,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0
                           });



OccupiedWhite()=mat2bb({0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,
                       0,1,0,0,0,0,0,1,0,
                       1,1,1,1,1,1,1,1,1
                       });


OccupiedWhitePawn()=mat2bb({0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           1,1,1,1,1,1,1,1,1,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0
                           });
OccupiedWhiteKnight()=mat2bb({0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,1,0,0,0,0,0,1,0
                             });
OccupiedWhiteLance()=mat2bb({0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,
                            1,0,0,0,0,0,0,0,1
                            });
OccupiedWhiteSilver()=mat2bb({0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,1,0,0,0,1,0,0
                             });

OccupiedWhiteGold()=mat2bb({0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,1,0,1,0,0,0
                           });
OccupiedWhiteBishop()=mat2bb({0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,
                             0,1,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0
                             });
OccupiedWhiteRook()=mat2bb({0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,1,0,
                           0,0,0,0,0,0,0,0,0
                           });
OccupiedWhiteKing()=mat2bb({0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,
                           0,0,0,0,1,0,0,0,0
                           });

}

int Game::index(int move_)
{
    return (move_+1)/2;
}

void Game::makeMove(int org, int dest, bool up) // org = Ursprungsfeld, Zahl von 0 bis 80; dest = Zielfeld, Zahl von 0 bis 80, up = Upgrade, true = befördern false = nicht befördern
{
//    OccupiedBlackLance().setBit(0,0);
//    OccupiedBlackLance().setBit(9,1);
    if(OccupiedPieces[index(-move)][0].getBit(dest) == 1)
    {
        OccupiedPieces[index(-move)][0].setBit(dest, 0);
        for(int i=1;i!=8;++i)
        {
            if( OccupiedPieces[index(-move)][i].getBit(dest)==1)
            {
                OccupiedPieces[index(-move)][i].setBit(dest,0);
                CapturedPieces[index(move)][i-1];
                break;
            }

        }
        //todo finde heraus welche figur geschlagen wird ändere die dazugehörigen Bitboards und füge die geschlagene Figur den CapturedPieces hinzu
    }
    Occupied.setBit(org,0);
    Occupied.setBit(dest,1);
    Occupied45.setBit(turnPiFourth(org),0); //todo kontrollieren
    Occupied45.setBit(turnPiFourth(dest),1);
    OccupiedPieces[index(move)][0].setBit(org,0);
    OccupiedPieces[index(move)][0].setBit(dest,1);
    Occupied_45.setBit(turnMinusPiFourth(org),0);
    Occupied_45.setBit(turnMinusPiFourth(dest),1);
    Occupied90.setBit(turnPiHalf(org),0);
    Occupied90.setBit(turnPiHalf(dest),1);
    std::cout<<OccupiedPieces[index(move)][3].getBit(0)<<std::endl;
    for (int i = 1;i!=9;++i)
    {

        if( OccupiedPieces[index(move)][i].getBit(org)==1)
        {
            std::cout<<"Lanze " << i<<std::endl;
            OccupiedPieces[index(move)][i].setBit(org,0);
            OccupiedPieces[index(move)][i].setBit(dest,1);
            break;
        }
    }

    move = -move;
}
std::ostream & operator <<(std::ostream & out, Game & g){
    std::array<std::array<int, 9>, 9> mat{};

    for (int j=0;j!=81;++j)
    {
        for (int i = 1; i!= 9; ++i)
        {
            auto black= g.OccupiedPieces[0][i].getBit(j);
            auto white= g.OccupiedPieces[1][i].getBit(j);
            if(black)
                mat[j/9][j%9]=-i;
            if(white)
                mat[j/9][j%9]=i;
        }
    }

    for(int i =0;i!=9; ++i)
    {
        for (int j=0;j!=9;++j)
        {
            out  << std::setw(4)<< mat[i][j];
        }
        out << std::endl;
    }
    out<<std::endl;
    return out;
}
