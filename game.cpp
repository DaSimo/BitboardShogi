#include "game.h"
#include <iomanip>
#include <exception>
#include "util.h"
#include "bitboard.h"

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
//        std::cout<<"Temp "<<temp<<std::endl;
        std::array<int, 81> temp45=temp;
        std::array<int, 81> temp_45=temp;
        for (int i=0;i<81;++i)
        {
            temp45[turnPiFourth(i)]=temp[i];
            temp_45[turnMinusPiFourth(i)] =temp[i];
        }
//        std::cout<<"Temp_45 "<<temp45<<std::endl;
        Occupied45=mat2bb(temp45);
        Occupied_45=mat2bb(temp_45);

    }


    for (int i=9;i!=16;++i){
        OccupiedPieces[0][i]=mat2bb({0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,0,0,0,0,0,0,0,0
    });
    OccupiedPieces[1][i]=mat2bb({0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0
});
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
                CapturedPieces[index(move)][i-1]++;
                break;
            }
            if( OccupiedPieces[index(-move)][i+8].getBit(dest)==1)
            {
                OccupiedPieces[index(-move)][i+8].setBit(dest,0);
                CapturedPieces[index(move)][i-1]++;
                break;
            }

        }
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
    for (int i = 1;i!=16;++i)
    {
        if( OccupiedPieces[index(move)][i].getBit(org)==1)
        {
            OccupiedPieces[index(move)][i].setBit(org,0);
            if(up)
            OccupiedPieces[index(move)][i+8].setBit(dest,1);
            else
            OccupiedPieces[index(move)][i].setBit(dest,1);
            break;
        }
    }
    //todo befördern überprüfen?
    move = -move;
}
BitBoard Game::getMove(int org, int piece, int move){ //todo funktion so schreiben, dass man mögliche Züge einer Figur auch auf Felder anwenden kann auf der besagte Fugir nicht steht.
    switch (piece){
    case 2: //Lanze
//        std::cout << Lance[index(move)][org/9] << std::endl;
        return GeneratingBitBoardsSliding[1][getBlockPattern(Occupied90, org)][org]&Lance[index(move)][org/9]; //todo mit Lanzen BitBoard kombinieren
    case 5: //Turm
        return (GeneratingBitBoardsSliding[1][getBlockPattern(Occupied90, turnPiHalf(org))][org]|GeneratingBitBoardsSliding[0][getBlockPattern(Occupied, org)][org]);
    case 6: //Läufer
    {
//        std::cout <<"BlockPattern45: "<<getBlockPatternPiFourth(Occupied45, org)<<std::endl;
//        std::cout <<"BlockPattern_45: "<<getBlockPatternMinusPiFourth(Occupied_45, org)<<std::endl;


       auto x=(GeneratingBitBoardsSliding[2][getBlockPatternPiFourth(Occupied45, org)][org]|GeneratingBitBoardsSliding[3][getBlockPatternMinusPiFourth(Occupied_45, org)][org]);
//       std::cout << "1"<<std::endl;
//       std::cout<<"2"<<std::endl;
//       std::cout << "3";
       return x;
    }
    default: //non-sliding pieces
        return GeneratingBitBoards[index(move)][piece][org]&(~(OccupiedPieces[index(move)][0]));
    }
}

std::ostream & operator <<(std::ostream & out, Game & g){
    std::array<std::array<int, 9>, 9> mat = {0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0,
                                             0,0,0,0,0,0,0,0,0
                                            };

    for (int j=0;j!=81;++j)
    {
        for (int i = 1; i!= 16; ++i)
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
            out  << std::setw(4)<< mat[8-i][8-j];
        }
        out << std::endl;
    }
    out<<std::endl;
    int i = 0;
    out << "Captured Pieces:"<<std::endl;
    for (auto const& player : g.CapturedPieces) {  // gleichbedeutend mit auto it1=begin(g...); it2=end(g...); for (; it1!=it2; ++it1) { player = *it1; ... }
        if(i==0)
        out << "Schwarz"<<std::endl;
        else
            out << "Weiß"<<std::endl;
        ++i;
        for (auto n : player) {
            out << n << " ";
        }
        out << std::endl;
    }

    return out;
}

    Game::Game(const std::string& fenString)
    {
        // K König, P Bauer, N Springer, B Läufer, R Turm, S Silber General, G Gold General, L Lanze,
        // leere Felder werden mit Zahlen angegeben
        // klein für schwarz groß für weiß
        // + als Präfix für Upgegraded
        // Zeilenseperator ist /
        // erster Suffix, mit Leer gerennt, ist 0 für Weiß am Zug und 1 für Schwarz am Zug
        // zweiter Suffix sind die geschlagenen Figuren wieder mit Leer getrennt, dargestellt wird das durch
        // Figurenmarker gefolgt von der Anzahl an geschlagenen Figuren, z.B P3 heißt weiß hat 3 geschlagene
        // Bauern, l1 heißt Schwarz hat eine geschlagene Lanze
        // andere Suffixe kommen noch

        auto tokens = split(fenString);







        if (tokens.size() < 2) { throw std::invalid_argument("fen string is too short"); }

        handlefenstring0(tokens[0]);
        handlefenstring1(tokens[1]);
        if (tokens.size()>=3) { handlefenstring2(tokens[2]); }
        else { CapturedPieces = {}; }








    }



    void Game::handlefenstring0(std::string s)
    {
        auto rows = split(s,'/');
        for (int row=0; row < rows.size(); ++row)
        {

            int count = 0;
            for(int j=0; j < rows[row].size(); ++j)
            {   int bbn = count + row * 9;
                BitBoard *piece = 0;
                BitBoard *color = 0;
                switch(rows[row][j])
                {
                case 'K':
                    piece = &(OccupiedWhiteKing());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'P':
                    piece = &(OccupiedWhitePawn());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'N':
                    piece = &(OccupiedWhiteKnight());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'L':
                    piece = &(OccupiedWhiteLance());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'B':
                    piece = &(OccupiedWhiteBishop());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'S':
                    piece = &(OccupiedWhiteSilver());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'G':
                    piece = &(OccupiedWhiteGold());
                    color = &(OccupiedWhite());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'R':
                    piece = &(OccupiedWhiteRook() );
                   color = &(OccupiedWhite());
                    break;

                case 'k':
                    piece = &(OccupiedBlackKing());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'p':
                    piece = &(OccupiedBlackPawn());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'n':
                    piece = &(OccupiedBlackKnight());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'l':
                    piece = &(OccupiedBlackLance());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'b':
                    piece = &(OccupiedBlackBishop());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 's':
                    piece = &(OccupiedBlackSilver());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'g':
                    piece = &(OccupiedBlackGold());
                    color = &(OccupiedBlack());
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'r':
                    piece = &(OccupiedBlackRook() );
                   color = &(OccupiedBlack());
                    break;

                case '+':
                    ++j;
                    switch(rows[row][j])
                    {
                    case 'P':
                        piece = &(OccupiedWhitePawnUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'N':
                        piece = &(OccupiedWhiteKnightUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'L':
                        piece = &(OccupiedWhiteLanceUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'B':
                        piece = &(OccupiedWhiteBishopUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'S':
                        piece = &(OccupiedWhiteSilverUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'G':
                        piece = &(OccupiedWhiteGoldUp());
                        color = &(OccupiedWhite());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'R':
                        piece = &(OccupiedWhiteRookUp() );
                       color = &(OccupiedWhite());
                        break;

                    case 'p':
                        piece = &(OccupiedBlackPawnUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'n':
                        piece = &(OccupiedBlackKnightUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'l':
                        piece = &(OccupiedBlackLanceUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'b':
                        piece = &(OccupiedBlackBishopUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 's':
                        piece = &(OccupiedBlackSilverUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'g':
                        piece = &(OccupiedBlackGoldUp());
                        color = &(OccupiedBlack());
                        //todo rotierte BitBoards hinzufügen
                        break;

                    case 'r':
                        piece = &(OccupiedBlackRookUp() );
                       color = &(OccupiedBlack());
                        break;

                    default: throw std::invalid_argument("Invalid fen string!");

                    }

                    break;


                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9': count += rows[row][j]-'0';
                    break;

                default: throw "Invalid fen string!";
                }


                if(piece){
                insert(*piece,bbn   );
                insert(*color,bbn);
                insert(Occupied, bbn);
                insert(Occupied90, turnPiHalf(bbn));
                insert(Occupied45, turnPiFourth(bbn));
                insert(Occupied_45, turnMinusPiFourth(bbn));
                ++count;
                }
            }
        }
    }

    void Game::handlefenstring1(std::string s)
    {
        switch(s.front()){
        case '0':
            move=1;
            break;
        case '1':
            move=-1;
            break;

        }
    }

    void Game::handlefenstring2(std::string s)
    {
        CapturedPieces = {};
        for (unsigned j=0; j<s.size(); j+=2) {

            int piece = 0;
            int color = 0;
            int number = 0;
            switch(s[j]){

                case 'P':
                    piece = 0;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'N':
                    piece = 1;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'L':
                    piece = 2;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'B':
                    piece = 5;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'S':
                    piece = 3;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'G':
                    piece = 4;
                    color = 1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'R':
                    piece = 6;
                   color = 1;
                   number = s[j+1]-'0';
                    break;

                case 'p':
                    piece = 0;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'n':
                    piece = 1;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'l':
                    piece = 2;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'b':
                    piece = 5;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 's':
                    piece = 3;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'g':
                    piece = 4;
                    color = -1;
                    number = s[j+1]-'0';
                    //todo rotierte BitBoards hinzufügen
                    break;

                case 'r':
                    piece = 6;
                   color = -1;
                   number = s[j+1]-'0';
                    break;


                default: throw std::invalid_argument("Invalid fen string!");
                }


            CapturedPieces[index(color)][piece] = number;
            }

    }
