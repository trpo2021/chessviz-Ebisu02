#include <iostream>
#include <stdio.h>

using namespace std;

bool Flag = false; // true = white, false = black
int board[8][8]
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
        fprintf(html_file, " ");
        break;
    case 1:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9814;</div>");
        break;
    case 2:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9816;</div>");
        break;
    case 3:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9815;</div>");
        break;
    case 4:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9813;</div>");
        break;
    case 5:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9812;</div>");
        break;
    case 6:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9817;</div>");
        break;
    case 7:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9823;</div>");
        break;
    case 8:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9820;</div>");
        break;
    case 9:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9822;</div>");
        break;
    case 10:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9821;</div>");
        break;
    case 11:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9819;</div>");
        break;
    case 12:
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9813;</div>");
        break;
    }
    return;
}

void fillAndSetBoard(int board[8][8])
{
    FILE* html_file;
    html_file = fopen("index.html", "w+");
    fprintf(html_file, "<!DOCTYPE html>\n<html>\n<head>\n\t<title>Шахматы</title>\n\t<meta charset=\"utf-8\">\n\t<title>Chess</title>\n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\" />\n\t<link rel=\"shortcut icon\" href=\"https://image.flaticon.com/icons/png/512/32/32658.png\"/>\n\t<script src=\"\"></script>\n\t</head>\n<body>\n\t");
    for (int i = 0; i < 8; ++i) {
        Flag = !(Flag);
        for (int j = 0; j < 8; ++j) {
            if (Flag == true)
                fprintf(html_file, "\n\t<div class = \"square white\">");
            else
                fprintf(html_file, "\n\t<div class = \"square black\">");
            setFigures(board[i][j], html_file);
            fprintf(html_file, "\n\t</div>");
            Flag = !(Flag);
        }
    }
    fprintf(html_file, "\n</body>\n</html>");
    return;
}

int main()
{
    fillAndSetBoard(board);
    return 0;
}
