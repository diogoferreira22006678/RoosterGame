#include <stdio.h>
#define DIM 3

void makeMenu(void) {
  printf("\nWelcome to Rooster Game\n1 - Start New Game\n0 - Exit Game\n\n");
}

void makeBoard(void) {
  int coluna, linha;
  char tabuleiro[DIM][DIM] = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

  for (linha = 0; linha < DIM; linha++) {
    for (coluna = 0; coluna < DIM; coluna++) {
      printf(" %c ", tabuleiro[linha][coluna]);
      if (coluna != DIM - 1) {
        printf("|");
      }
    }
    printf("\n");
    if (linha != DIM - 1) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

int drawGame(int turn) {
  if (turn >= 8) {
    return 1;
  } else {
    return 0;
  }
}

int horizontalGame(char tabuleiro[][DIM]) {
  int linha, coluna;
  char letra;

  for (coluna = 0; coluna < DIM; coluna++) {
    for (linha = 0; linha < DIM; linha++) {
      letra = tabuleiro[linha][0];
      if (tabuleiro[linha][coluna] != letra) {
        break;
      } else if (tabuleiro[linha][2] == letra && tabuleiro[linha][1] == letra) {
        return 1;
      }
    }
  }
  return 0;
}

int verticalGame(char tabuleiro[][DIM]) {
  int linha, coluna;
  char letra;

  for (linha = 0; linha < DIM; linha++) {
    for (coluna = 0; coluna < DIM; coluna++) {
      letra = tabuleiro[0][coluna];
      if (tabuleiro[linha][coluna] != letra) {
        break;
      } else if (tabuleiro[2][coluna] == letra &&
                 tabuleiro[1][coluna] == letra) {
        return 1;
      }
    }
  }
  return 0;
}

int diagonalGame(char tabuleiro[][DIM]) {
  int linha, coluna;
  char letra;

  for (linha = 0, coluna = 0; linha < DIM && coluna < DIM; linha++, coluna++) {
    letra = tabuleiro[0][0];
    if (tabuleiro[linha][coluna] != letra) {
      break;
    } else if (tabuleiro[2][2] == letra && tabuleiro[1][1] == letra) {
      return 1;
    }
  }

  for (linha = 0, coluna = 2; linha < DIM && coluna >= 0; linha++, coluna--) {
    letra = tabuleiro[0][2];
    if (tabuleiro[linha][coluna] != letra) {
      break;
    } else if (tabuleiro[2][0] == letra && tabuleiro[1][1] == letra) {
      return 1;
    }
  }
  return 0;
}

int endGame(char tabuleiro[][DIM], int turn, char Player1[100],
            char Player2[100]) {
  if (horizontalGame(tabuleiro)) {
    if (turn % 2 == 0) {
      printf("Congratulations,%s won the game!\n", Player1);
      return 1;
    } else {
      printf("Congratulations,%s won the game!\n", Player2);
      return 1;
    }
  }
  if (verticalGame(tabuleiro)) {
    if (turn % 2 == 0) {
      printf("Congratulations,%s won the game!\n", Player1);
      return 1;
    } else {
      printf("Congratulations,%s won the game!\n", Player2);
      return 1;
    }
  }

  if (diagonalGame(tabuleiro)) {
    if (turn % 2 == 0) {
      printf("Congratulations,%s won the game!\n", Player1);
      return 1;
    } else {
      printf("Congratulations,%s won the game!\n", Player2);
      return 1;
    }
  }
  if (drawGame(turn)) {
    printf("Nobody won, better luck next time!\n");
    return 1;
  }
  return 0;
}

int main(void) {

  int opcao;
  char nomePlayer1[100], nomePlayer2[100];
  int jogada = 1;
  int turn = 0;
  char tabuleiro[DIM][DIM] = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  int linha, coluna;
  int useCase[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

  makeMenu();
  scanf("%d", &opcao);

  while (opcao < 0 || opcao > 1) {
    printf("\nUnfounded Parameter\n\n");
    makeMenu();
    scanf("%d", &opcao);
  }

 if (opcao == 1) {
    printf("\nWhats your name Player 1?\n");
    scanf("%s", nomePlayer1);
    printf("\nWhats your name Player 2?\n");
    scanf("%s", nomePlayer2);
    printf("\n");

    makeBoard();

    while (jogada != 0) {
      do {
        do {
          if (turn % 2 == 0) {
            printf("%s choose position: ", nomePlayer1);
          } else {
            printf("%s choose position: ", nomePlayer2);
          }

          scanf("%d", &jogada);
          puts("\n");

          if (useCase[jogada - 1] == 0) {
            printf("Invalid Position\n\n");
          }
        } while (useCase[jogada - 1] == 0);

        switch (jogada) {
        case 1:
          if (turn % 2 == 0) {
            tabuleiro[0][0] = 'X';
          } else {
            tabuleiro[0][0] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 2:
          if (turn % 2 == 0) {
            tabuleiro[0][1] = 'X';
          } else {
            tabuleiro[0][1] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 3:
          if (turn % 2 == 0) {
            tabuleiro[0][2] = 'X';
          } else {
            tabuleiro[0][2] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 4:
          if (turn % 2 == 0) {
            tabuleiro[1][0] = 'X';
          } else {
            tabuleiro[1][0] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 5:
          if (turn % 2 == 0) {
            tabuleiro[1][1] = 'X';
          } else {
            tabuleiro[1][1] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 6:
          if (turn % 2 == 0) {
            tabuleiro[1][2] = 'X';
          } else {
            tabuleiro[1][2] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 7:
          if (turn % 2 == 0) {
            tabuleiro[2][0] = 'X';
          } else {
            tabuleiro[2][0] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 8:
          if (turn % 2 == 0) {
            tabuleiro[2][1] = 'X';
          } else {
            tabuleiro[2][1] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        case 9:
          if (turn % 2 == 0) {
            tabuleiro[2][2] = 'X';
          } else {
            tabuleiro[2][2] = 'O';
          }
          useCase[jogada - 1] = 0;
          break;
        default:
          printf("Invalid Position\n\n");
        }
      } while (jogada > 9 || jogada < 1);

      for (linha = 0; linha < DIM; linha++) {
        for (coluna = 0; coluna < DIM; coluna++) {
          printf(" %c ", tabuleiro[linha][coluna]);
          if (coluna != DIM - 1) {
            printf("|");
          }
        }
        printf("\n");

        if (linha != DIM - 1) {
          printf("---+---+---\n");
        }
      }
      printf("\n");
      if (endGame(tabuleiro, turn, nomePlayer1, nomePlayer2)) {
        return 0;
      }
      turn++;
    }

  } else if (opcao == 0) {
  }
  return 0;
}
