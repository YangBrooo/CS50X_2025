#include<stdio.h>
#include<string.h>
#include<cs50.h>

int score(char s);
int sum_score(char []);


int main(void){
    string str1 = get_string("Player 1:");
    string str2 = get_string("Player 2:");
    int S1 = sum_score(str1);
    int S2 = sum_score(str2);
    if(S1 > S2){
        printf("Player 1 wins!\n");
    }
    else if(S1 < S2){
        printf("Player 2 wins!\n");
    }
    else{
        printf("Tie!\n");
    }
    return 0;
}

int score(char s){
    if(s == 'a' || s == 'A'|| s == 'e' || s == 'E' || s == 'I' ||s == 'i' || s == 'L' || s == 'l'|| s == 'N'|| s == 'n'|| s == 'O'|| s == 'o'|| s == 'R'|| s == 'r'|| s == 'S'|| s == 's'|| s == 'T'|| s == 't'|| s == 'U'|| s == 'u'){
        return 1;
    }
    else if(s == 'D'|| s == 'd'|| s == 'G'|| s == 'g'){
        return 2;
    }
    else if(s == 'B'|| s == 'b'|| s == 'C'|| s == 'c'|| s == 'M'|| s == 'm'|| s == 'P'|| s == 'p'){
        return 3;
    }
    else if(s == 'F'|| s == 'f'|| s == 'H'|| s == 'h'|| s == 'V'|| s == 'v'|| s == 'W'|| s == 'w'|| s == 'Y'|| s == 'y'){
        return 4;
    }
    else if(s == 'K'|| s == 'k'){
        return 5;
    }
    else if(s == 'J'|| s == 'j'|| s == 'X'|| s == 'x'){
        return 8;
    }
    else if(s == 'Q'|| s == 'q'|| s == 'Z'|| s == 'z'){
        return 10;
    }
    else{
        return 0;
    }
}

int sum_score(char str[]){
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++){
        sum += score(str[i]);
    }
    return sum;
}
