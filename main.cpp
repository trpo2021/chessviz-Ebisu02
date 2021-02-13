#include <iostream>
#include <stdio.h>

using namespace std;

bool Flag = false; // true = white, false = black
int board[][]
        = {{1, 2, 3, 4, 5, 3, 2, 1},
           {6, 6, 6, 6, 6, 6, 6, 6},
           {0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0},
           {0, 0, 0, 0, 0, 0, 0, 0},
           {7, 7, 7, 7, 7, 7, 7, 7},
           {8, 9, 10, 11, 12, 10, 9, 8}};

void setFigures(int numFigure, FILE* html_file)
{
    switch (numFigure) {
    case 0:
        fprintf(html_file, "");
        break;
    case 1:
        fprintf(html_file, "&#9814");
        break case 2 : fprintf(html_file, "&#9816");
        break;
    case 3:
        fprintf(html_file, "&#9815");
        break;
    case 4:
        fprintf(html_file, "&#9813");
        break;
    case 5:
        fprintf(html_file, "&#9812");
        break;
    case 6:
        fprintf(html_file, "&#9817");
        break;
    case 7:
        fprintf(html_file, "&#9823");
        break;
    case 8:
        fprintf(html_file, "&#9820");
        break;
    case 9:
        fprintf(html_file, "&#9822");
        break;
    case 10:
        fprintf(html_file, "&#9821");
        break;
    case 11:
        fprintf(html_file, "&#9819");
        break;
    case 12:
        fprintf(html_file, "&#9813");
        break;
    }
    return;
}

void fillAndSetBoard(int board[8][8])
{
    FILE* html_file;
    html_file = fopen("index.html", "w+");
    for (int i = 0; i < 8; ++i) {
        Flag = !(Flag);
        for (int j = 0; j < 8; ++j) {
            if (Flag == true)
                fprintf(html_file, "<div class = \"square white\">");
            else
                fprintf(html_file, "<div class = \"square black\">");
            setFigures(board[i][j], html_file);
            fprintf(html_file, "</div>");
            Flag = !(Flag);
        }
    }
    return;
}

int main()
{
    fillAndSetBoard(board[8][8]);
    return 0;
}
