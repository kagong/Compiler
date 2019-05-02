#ifndef SCAN_H
#define SCAN_H
#define MAXTOKENLEN 40
char tokenString[MAXTOKENLEN+1];
char prev[MAXTOKENLEN+1];
TokenType getToken();
#endif
