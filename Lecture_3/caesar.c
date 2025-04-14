// #include<stdio.h>
// #include<cs50.h>
// #include<string.h>
// #include<stdlib.h>

// int identity(char []);
// char trans(char [], int);


// int main(int argc, char *argv[]){
//     //当命令行中元素大于两个时，自动结束进程；当命令行中元素只有一个时，自动结束进程；当命令行中元素等于两个，但是第二个元素中不是纯数字（num < 1）时，自动结束进程
//     if(argv[1] == '\0' || argc > 2 || identity(argv[1]) < 1){
//         printf("Usage: ./caesar key\n");
//     }
//     //命令行中内容输入正确，可以进行下一步操作
//     else{
//         string str = get_string("plaintext:  ");
//         //把argv[1]内的字符串内容转变成整型变量
//         int key = atoi(argv[1]);
//         printf("ciphertext: ");
//         //调用转换函数并判断是否需要密文转换，完成输出
//         for(int i = 0; str[i] != '\0'; i++){
//             if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
//                 char c = trans(str[i]);
//                 printf("%c", c);
//             }
//             else{
//                 printf("%c", str[i]);
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }

// //判断输入的key里是不是纯数字,纯数字返回1，如果有其他类型元素，返回0（当然，输入的是负数的时候检测结果也是0）
// int identity(char argv[]){
//     int num = 1;
//     for(int i = 0; argv[][i] != '\0'; i++){
//         if(argv[][i] >= '0' && argv[][i] <= '9'){
//         }
//         else{
//             num = 0;
//         }
//     }
//     return num;
// }

// //转换密文
// char trans(char str[], int key){
//     int n =0, m = 0;
//     char c;
//     if(str[i] >= 'A' && str[i] <= 'Z'){
//         n = 'str[i]' - 'A';
//         n = (n + key) % 26;
//         c = 'A' + n;
//         return c;
//     }
//     else if(str[i] >= 'a' && str[i] <= 'z'){
//         m = 'str[i]' - 'a';
//         n = (n + key) % 26;
//         c = 'a' + n;
//         return c;
//     }
// }


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int identity(char *argv);      // 修改参数类型为 char*
char trans(char c, int key);   // 修正参数为单个字符和密钥

int main(int argc, char *argv[]) {
    // 检查参数数量是否为2，且密钥合法
    if (argc != 2 || identity(argv[1]) != 1) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string str = get_string("plaintext:  ");
    int key = atoi(argv[1]);
    printf("ciphertext: ");

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            printf("%c", trans(str[i], key)); // 传递字符和密钥
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}

// 检查密钥是否全为数字
int identity(char *argv) {
    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] < '0' || argv[i] > '9') { // 发现非数字字符立即返回0
            return 0;
        }
    }
    return 1;
}

// 字符转换函数
char trans(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        // 大写字母处理
        return 'A' + (c - 'A' + key) % 26;
    } else if (c >= 'a' && c <= 'z') {
        // 小写字母处理
        return 'a' + (c - 'a' + key) % 26;
    }
    return c; // 非字母字符直接返回
}
