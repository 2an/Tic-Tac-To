//
//  main.c
//  Tic Tac To
//
//  Created by Tuan Ngo on 09.11.16.
//  Copyright © 2016 Tuan Ngo. All rights reserved.
//

#include <stdio.h>

#define EMPTY 0
#define MAX 3
#define spieler1 1
#define spieler2 2
#define MAXRUNDEN 10
#define schonwasdrin 100
#define win 11

void hilfestellung(){
    printf("\nKleine Hilfe\n");
    printf("    x ->\n");
    printf(" y  0/0 | 1/0 | 2/0  \n");
    printf(" | -----------------\n");
    printf(" v  0/1 | 1/1 | 2/1  \n");
    printf("   -----------------\n");
    printf("    0/2 | 1/2 | 2/2  \n");
    printf("\n");
}

int main(void) {
    int xvalue = 0, yvalue = 0;
    int spielfeld[MAX][MAX];
    int Spielernow = spieler1;
    int count = 1;
    
    // Felder des Spielfelds mit EMPTY vorbelegen
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            spielfeld[i][j] = EMPTY;
        }
    }
    printf("Ein kleines Game zwischendurch\n");
    hilfestellung();
    
    do {
        // Spielzug erfragen
        printf("X-Koordinate: ");
        scanf("%d", &xvalue);
        printf("Y-Koordinate: ");
        scanf("%d", &yvalue);
        
        if (spielfeld[xvalue][yvalue] != 0) {
            xvalue = schonwasdrin;
            yvalue = schonwasdrin;
        }
        
        //Komische Eingaben überprüfen, Vorsicht bei Buchstaben -> Endlosschleife
        if (xvalue >= MAX || xvalue < 0 || yvalue >= MAX || yvalue < 0) {
            printf("Halt Stop, da passt was ned\n");
            printf("Da ist schon was drin\n");
            printf("Nur Zahlen zwischen 0 - 2\n");
        }
        
        //Hier wird entweder X oder 0 im Array gesetzt
        if (xvalue >= 0 && yvalue >= 0 && xvalue < MAX && yvalue < MAX) {
            if (Spielernow == spieler1) {
                spielfeld[xvalue][yvalue] = 'X';
            }
            if (Spielernow == spieler2) {
                spielfeld[xvalue][yvalue] = 'O';
            }

            // Spielerwechsel
            count++;
            
            if (count&1) {
                Spielernow = spieler1;
            }
            else {
                Spielernow = spieler2;
            }

            hilfestellung();
            
        //Spielfeld
            printf("  %c  |  %c  |  %c \n", spielfeld[0][0], spielfeld[1][0], spielfeld[2][0]);
            printf("--------------\n");
            printf("  %c  |  %c  |  %c \n", spielfeld[0][1], spielfeld[1][1], spielfeld[2][1]);
            printf("--------------\n");
            printf("  %c  |  %c  |  %c \n", spielfeld[0][2], spielfeld[1][2], spielfeld[2][2]);
            printf("\n");
            
            
        //Wincondition überprüfen
        
            //vertikal win
            for (int i = 0; i < MAX; i++) {
                if(spielfeld[i][0] == spielfeld[i][1] &&
                   spielfeld[i][0] == spielfeld[i][2] &&
                   spielfeld[i][1] == spielfeld[i][2] &&
                   spielfeld[i][0] != 0 &&
                   spielfeld[i][1] != 0 &&
                   spielfeld[i][2] != 0){
                    count = win;
                    break;
                }
            }
            //horizontal win
            for (int i = 0; i < MAX; i++) {
                if(spielfeld[0][i] == spielfeld[1][i] && spielfeld[0][i] == spielfeld[2][i] && spielfeld[1][i] == spielfeld[2][i] && spielfeld[0][i] != 0 && spielfeld[0][i] != 0 && spielfeld[0][i] != 0){
                    count = win;
                    break;
                }
            }
            //diagonal win
            if (spielfeld[0][0] == spielfeld[1][1] && spielfeld[0][0] == spielfeld[2][2] &&
                spielfeld[0][0] != 0 && spielfeld[1][1] != 0 && spielfeld[2][2] != 0) {
                count = win;
            }
            if (spielfeld[0][2] == spielfeld[1][1] && spielfeld[0][2] == spielfeld[2][0] && spielfeld[0][2] != 0 && spielfeld[1][1] != 0 && spielfeld[2][0] != 0) {
                count = win;
            }
            
        }
    } while(count < MAXRUNDEN);
    
    if(count == MAXRUNDEN){
        printf("It's a draw\n");
        return 0;
    }
    
    printf("You Win\n");
    
    return 0;
}
