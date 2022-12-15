
class Fichas
{
public:
    char Players[4] = {'1', '2', '3', '4'};
    char Cards[5] = {'A', 'V', 'R', 'B', 'P'};
    char Towers[6] = {'1', '2', '3', '4', '5', '6'};
    char Play;
    char Card;
    char Tower;

public:
    void set_ficha(char Po, char C, char T)
    {
        Play = Po;
        Card = C;
        Tower = T;
    }

};
