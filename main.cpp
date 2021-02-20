#include <iostream>
#include <stdio.h>

using namespace std;

char board[8][8]
        = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'0', '0', '0', '0', '0', '0', '0', '0'},
           {'0', '0', '0', '0', '0', '0', '0', '0'},// R - ladya, Q - ferz, K - King
           {'0', '0', '0', '0', '0', '0', '0', '0'},// N - Horse, B - slon,
           {'0', '0', '0', '0', '0', '0', '0', '0'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

void setFigures(int numFigure, FILE* html_file)
{
    switch (numFigure) {
    case '0':
        fprintf(html_file, " ");
        break;
    case 'R':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9814;</div>");
        break;
    case 'N':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9816;</div>");
        break;
    case 'B':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9815;</div>");
        break;
    case 'Q':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9813;</div>");
        break;
    case 'K':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9812;</div>");
        break;
    case 'P':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9817;</div>");
        break;
    case 'p':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9823;</div>");
        break;
    case 'r':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9820;</div>");
        break;
    case 'n':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9822;</div>");
        break;
    case 'b':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9821;</div>");
        break;
    case 'q':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9819;</div>");
        break;
    case 'k':
        fprintf(html_file, "\n\t\t<div class = \"figure\">&#9818;</div>");
        break;
    }
    return;
}

void fillAndSetBoard(char board[8][8])
{
    bool BLACK_OR_WHITE = false; // true = white, false = black
    FILE* html_file;
    html_file = fopen("index.html", "w+");
    fprintf(html_file, "<!DOCTYPE html>\n<html>\n<head>\n\t<title>Шахматы</title>\n\t<meta charset=\"utf-8\">\n\t<title>Chess</title>\n\t<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\" />\n\t<link rel=\"shortcut icon\" href=\"https://image.flaticon.com/icons/png/512/32/32658.png\"/>\n\t<script src=\"\"></script>\n\t</head>\n<body>\n\t");
    fprintf(html_file, "\n\t<div class = \"board\">");
    for (int i = 0; i < 8; ++i) {
        BLACK_OR_WHITE = !(BLACK_OR_WHITE);
        for (int j = 0; j < 8; ++j) {
            if (BLACK_OR_WHITE == true)
                fprintf(html_file, "\n\t<div class = \"square white\">");
            else
                fprintf(html_file, "\n\t<div class = \"square black\">");
            setFigures(board[i][j], html_file);
            fprintf(html_file, "\n\t</div>");
            BLACK_OR_WHITE = !(BLACK_OR_WHITE);
        }
    }
    fprintf(html_file, "\n\t</div>\n</body>\n</html>");
    return;
}

int main()
{
    fillAndSetBoard(board);
    return 0;
}
