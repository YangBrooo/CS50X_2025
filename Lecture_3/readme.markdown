CS50X 随堂作业习题集

from caesar.c 

# 如何理解int main(int argc,char *argv[])并灵活运用？

### C语言中 int main(int argc,char *argv[])的两个参数详解

- argc是命令行总的参数个数
	-   argc记录了用户在运行程序的命令行中输入的参数的个数

- argv[]是argc个参数，其中第0个参数是程序的全名，以后的参数。命令行后面跟的用户输入的参数。
	-   char   *argv[]是一个字符数组,其大小是int argc,主要用于命令行参数 argv[] 参数，数组里每个元素代表一个参数
