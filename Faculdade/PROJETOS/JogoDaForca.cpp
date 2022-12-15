#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    string palavra;
    char letra[1], secreta[30];
    int tam, i, chances, acertos;
    bool acerto;
    chances = 6;
    tam = 0;
    i = 0;
    acerto = false;
    acertos = 0;
    printf("/****************/\n");
    printf("/ JOGO DA FORCA */\n");
    printf("/****************/\n\n");
    cout << "FALE PARA O SEU AMIGO TAMPAR OS OLHOS E DIGITE A PALAVRA SECRETA: ";
    while (cin >> palavra)
    {
        system("cls");

        while (palavra[i] != '\0')
        {
            i++;
            tam++;
        }

        for (i = 0; i < palavra.size(); i++)
        {
            secreta[i] = '-';
        }

        while ((chances > 0) && (acertos < tam))
        {
            cout << "CHANCES RESTANTES : " << chances << "\n\n";
            if (!acerto && chances == 6)
            {
                printf("  _______       \n");
                printf(" |/      |      \n");
                printf(" |       O      \n");
                printf(" |     --|--    \n");
                printf(" |      | |     \n");
                printf(" |              \n");
                printf(" |              \n");
                printf("_|___           \n");
                printf("\n\n");
            }
            else
            {
                if (!acerto && chances == 5)
                {
                    printf("  _______       \n");
                    printf(" |/      |      \n");
                    printf(" |       O      \n");
                    printf(" |     --|--    \n");
                    printf(" |      |       \n");
                    printf(" |              \n");
                    printf(" |              \n");
                    printf("_|___           \n");
                    printf("\n\n");
                }
                else
                {
                    if (!acerto && chances == 4)
                    {
                        printf("  _______       \n");
                        printf(" |/      |      \n");
                        printf(" |       O      \n");
                        printf(" |     --|--    \n");
                        printf(" |              \n");
                        printf(" |              \n");
                        printf(" |              \n");
                        printf("_|___           \n");
                        printf("\n\n");
                    }
                    else
                    {
                        if (!acerto && chances == 3)
                        {
                            printf("  _______       \n");
                            printf(" |/      |      \n");
                            printf(" |       O      \n");
                            printf(" |     --|      \n");
                            printf(" |              \n");
                            printf(" |              \n");
                            printf(" |              \n");
                            printf("_|___           \n");
                            printf("\n\n");
                        }
                        else
                        {
                            if (!acerto && chances == 2)
                            {
                                printf("  _______       \n");
                                printf(" |/      |      \n");
                                printf(" |       O      \n");
                                printf(" |       |      \n");
                                printf(" |              \n");
                                printf(" |              \n");
                                printf(" |              \n");
                                printf("_|___           \n");
                                printf("\n\n");
                            }
                            else
                            {
                                if (!acerto && chances == 1)
                                {
                                    printf("  _______       \n");
                                    printf(" |/      |      \n");
                                    printf(" |       O      \n");
                                    printf(" |             \n");
                                    printf(" |              \n");
                                    printf(" |              \n");
                                    printf(" |              \n");
                                    printf("_|___           \n");
                                    printf("\n\n");
                                }
                            }
                        }
                    }
                }
            }

            cout << "PALAVRA SECRETA : ";
            for (i = 0; i < tam; i++)
            {
                cout << secreta[i];
            }
            int X = palavra.size();
            cout << endl;
            cout << X << " letras" << endl;
            cout << "\n\n DIGITE UMA LETRA QUE NAO TENHA SIDO DIGITADA : ";
            cin >> letra[0];
            for (i = 0; i < tam; i++)
            {
                if (palavra[i] == letra[0])
                {
                    acerto = true;
                    secreta[i] = palavra[i];
                    acertos++;
                }
            }
            if (!acerto)
            {
                chances--;
            }
            acerto = false;
            system("cls");
        }
        if (acertos == tam)
        {
            printf("\nPARABENS, VOCE GANHOU!\n\n");

            printf("       ___________      \n");
            printf("      '._==_==_=_.'     \n");
            printf("      .-|:      /-.    \n");
            printf("     | (|:.     |) |    \n");
            printf("      '-|:.     |-'     \n");
            printf("        |::.    /      \n");
            printf("         '::. .'        \n");
            printf("           ) (          \n");
            printf("         _.' '._        \n");
            printf("        '-------'       \n\n");
        }
        else
        {
            printf("\nPUXA,VOCE FOI ENFORCADO!\n");
           cout<<"A PALAVRA ERA : "<<palavra<<endl;

            printf("    _______________         \n");
            printf("   /               |      \n");
            printf("  /                  |     \n");
            printf(" /                    |  \n");
            printf(" |   XXXX     XXXX   |    \n");
            printf(" |   XXXX     XXXX   |     \n");
            printf(" |   XXX       XXX   |      \n");
            printf(" |                   |      \n");
            printf("  |_      XXX      _|       \n");
            printf("   | |    XXX     /|       \n");
            printf("   | |           | |        \n");
            printf("   | I I I I I I I |        \n");
            printf("   |  I I I I I I  |        \n");
            printf("   |_             _/       \n");
            printf("     |_          _/         \n");
            printf("       |________/           \n");
        }
        cout << endl;
        chances = 6;
        tam = 0;
        i = 0;
        acerto = false;
        acertos = 0;
        cout << "FALE PARA O SEU AMIGO TAMPAR OS OLHOS E DIGITE A PALAVRA SECRETA: ";
    }
}
