typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para comparação de tamanho
} nomePecas; //peça

typedef struct
{
    nomePecas pecasPlayers[7]; //7 peças
} players; //jogadores

nomePecas pecas[28]; //peças totais
players player1; //jogador 1 com 7 peças
players player2; //jogador 2 com 7 peças
