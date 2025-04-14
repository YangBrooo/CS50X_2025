#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int check_key(char *argv);

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if(check_key(argv[1]) != 1){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else{//输入的KEY形式正确，根据输入的KEY对明文进行映射修改
        string str = get_string("plaintext:");
        //把argv[]转换成纯大写
        char key_2[26];
        for(int i = 0; i < 26; i++){
            key_2[i] = toupper(argv[1][i]);
        }
        printf("ciphertext:");
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] <= 'z' && str[i] >= 'a'){
                int l = str[i] - 'a';
                printf("%c", tolower(key_2[l]));
            }
            else if(str[i] <= 'Z' && str[i] >= 'A'){
                int q = str[i] - 'A';
                printf("%c", key_2[q]);
            }
            else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
        return 0;
    }
}

int check_key(char *argv){
    int n = 0;
    int i = 0;
    // 修正2：改为单层数组访问
    for(i = 0; argv[i] != '\0'; i++){
        // 修正3：改为比较运算符
        if(isalpha(argv[i]) == 0){
                n++;
        }
    }
    // 保持原有长度检查逻辑
    if(i != 26){
        n++;
    }
    if(n > 0){
        return 0;
    }

    // 修正4：改为字符数组
    char key_1[26];
    for(int j = 0; j < 26; j++){ // 明确循环26次
        key_1[j] = toupper(argv[j]);
    }

    // 修正5：删除无用的key_2
    for(int z = 0; z < 26; z++){ // 明确循环次数
        for(int h = z + 1; h < 26; h++){ // 修正比较范围
            if(key_1[z] == key_1[h]){
                return 0;
            }
        }
    }
    return 1; // 所有检查通过
}
