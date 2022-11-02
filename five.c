#include<stdio.h>
#include<stdlib.h>
#define CHAR_MAX 50

struct Cricket {
    char* name;
    char* team;
    float average;
};

void init_cricket(struct Cricket* player) {
    player->name = (char *) malloc(sizeof(char) * CHAR_MAX);
    player->team = (char *) malloc(sizeof(char) * CHAR_MAX);

    printf("Enter the player name: ");
    scanf("%s", player->name);

    printf("Enter the player team: ");
    scanf("%s", player->team);

    printf("Enter the player average: ");
    scanf("%f", &player->average);
}

void print(struct Cricket player) {
    printf("NAME: %s\n", player.name);
    printf("TEAM: %s\n", player.team);
    printf("AVERAGE: %.2f\n", player.average);
}

//returning the index of max average player
int find_max_average(struct Cricket players[], int length) {
    int max = 0;

    for(int i = 1; i < length; i++) {
        if(players[i].average > players[max].average)
            max = i;
    }

    return max;
}

int main() {
    int n;

    printf("Enter the number of players: ");
    scanf("%d", &n);

    struct Cricket *players;
    players = (struct Cricket *) malloc(sizeof(struct Cricket) * n);

    for(int i = 0; i < n; i++)
        init_cricket(players + i);

    print(players[find_max_average(players, n)]);
    
    return 0;
}