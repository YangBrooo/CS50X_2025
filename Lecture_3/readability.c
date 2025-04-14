#include<stdio.h>
#include<cs50.h>
#include<string.h>

//至少包含一个单词，不会以空格开头或结尾，不会有多余的连续空格

int get_c_num(char []);
int get_j_num(char []);
int get_z_num(char []);

int main(void){
    string str = get_string("Text:");
    int words = get_c_num(str);
    float L = (get_z_num(str) * 100.0f) / words;
    float S = (get_j_num(str) * 100.0f) / words;
    int index = (int)(0.0588*L - 0.296*S -15.8 + 0.5);
    if(index >= 16){
        printf("Grade 16+\n");
    }
    else if(index < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %d\n", index);
    }
    return 0;
}

//统计文本中单词的数量
int get_c_num(char str[]){
    int num = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            num ++;
        }
    }
    return num + 1;
}

//统计文本中句子的数量  Congratulations! Today is your day. You're off to Great Places! You're off and away!
int get_j_num(char str[]){
    int NUM = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '.' || str[i] == '?' || str[i] == '!'){
            NUM ++;
        }
    }
    if(NUM == 0){
        NUM = 1;
    }
    return NUM;
}

//统计文本中字母的数量
int get_z_num(char str[]){
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if((str[i] <= 'Z' && str[i] >= 'A') || (str[i] <= 'z' && str[i] >='a')){
            sum ++;
        }
    }
    return sum;
}
