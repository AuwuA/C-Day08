    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 非空字符个数
int getLettersNumNoSpace(char *str)
{
    int num = 0;
    while(*str) {
        if (*str != ' ') {
            num++;
        }
        str++;
    }
    return num;
}
void test01()
{
    char *str = "ni chou sha chou ni za di";
    printf("the num isn't \" \" is %d\n", getLettersNumNoSpace(str));
}

// 字符串逆置
void myStrrev(char *str)
{
    if (NULL == str) {
        return;
    }
    unsigned long long startIndex = 0;
    unsigned long long indexEnd = strlen(str) - 1;
    while(startIndex < indexEnd) {
        str[startIndex] ^= str[indexEnd];
        str[indexEnd] ^= str[startIndex];
        str[startIndex] ^= str[indexEnd];
        startIndex++;
        indexEnd--;
    }
}

void test02()
{
    char str[] = "ni chou sha chou ni za di";
    myStrrev(str);
    puts(str);
}

// 判断字符串是不是回文
int isPalindrome(char *str)
{
    char *endP = str + strlen(str) - 1;
    while(str < endP) {
        if (*str != *endP) {
            return 0;
        }
        str++;
        endP--;
    }
    return 1;
}

void test03()
{
    char str[] = "abcnncba";

    int ret = isPalindrome(str);

    if (ret == 0)
        printf("Isn't palindrome\n");
    else if (ret == 1)
        printf("Is palindrome\n");
}

// strcpy
void test04()
{
    char src[] = "abc efg zhangsan wangwu ";
    char dest[100] = {0};
    char *p = strcpy(dest, src);// 字符串src 拷贝给dest
    puts(p);
}

// strncpy 默认不添加'\0'
void test05()
{
    char src[] = "abc efg zhangsan wangwu ";
    char dest[100] = {0};
    char *p = strncpy(dest, src, 6);// 字符串src 拷贝给dest
    puts(p);
}

// 字符串拼接
void test06()
{
    char src[] = "world";
    char dest[] = "helloglcsnghntiooruptoypja4to[aotkrpoaejgtrhrsopkhrjoh[ypjpjk";
    char *p = strcat(dest, src);
    printf("p = %s\n", p);
    printf("dest = %s\n", dest);
}

void test07()
{
    char src[] = "world";
    char dest[6] = "hello";

    char *p = strncat(dest, src, 3);

    printf("p = %s\n", p);
    printf("dest = %s\n", dest);

    printf("%d\n", strlen(dest));
}

// strcmp
void test08()
{
    char *str1 = "helloworld";
    char *str2 = "helloz";

    printf("ret = %d\n", strcmp(str1, str2));
}

// strncmp
void test09()
{
    char *str1 = "helloworld";
    char *str2 = "helloz";

    printf("ret = %d\n", strncmp(str1, str2, 8));
}

// sprintf
void test10()
{
    char buf[100] = {0}; //buffer  string str  source src
    sprintf(buf, "%d%c%d=%d\n", 10, '+', 34, 10+34);
    puts(buf);
}

// sscanf
void test11()
{
    char buf[100] = { 0 }; //buffer  string str  source src
    int a, b, c;
    char str[] = "13+56=89";
    sscanf(str, "%d+%d=%d", &a, &b, &c);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
}

// strtok

void test12()
{
    char str[] = "www.itcast.cn.com.net";  // www itcast cn
    char des[100] = "";
    char *p = strtok(str, ".");
    while(p != NULL) {
        puts(p);
        p = strtok(NULL, ".");
    }
}

// atoi
void test13()
{
    char str[] = "abc345";
    int num = atoi(str);
    printf("num = %d\n", num);

    char str1[] = "     -10";
    int num1 = atoi(str1);
    printf("num1 = %d\n", num1);

    char str2[] = "0.123f";
    double num2 = atof(str2);
    printf("num2 = %.2lf\n", num2);

    char str3[] = "123L";
    long num3 = atol(str3);
    printf("num3 = %ld\n", num3);
}

// strchr
void test14()
{
    char *strchr(const char *s, int c);
    printf("%s\n", strchr("hehehahahoho", 'a'));
}

// strrchr
void test15()
{
    char *strrchr(const char *s, int c);
    printf("%s\n", strrchr("hehehahahoho", 'a'));
}

void test16()
{
    char str[] = "www.itcast.cn$This is a strtok$test";

    char *p = strtok(str, "$ .");

    while (p != NULL)
    {
        printf("p = %s\n", p);
        p = strtok(NULL, ". $");
    }
}

// 局部变量和全局变量 静态全局变量作用域会被限定在本文件内 不允许通过声明导出到其他文件
void  test17()
{
    int  a = 10;
    printf("a = %d\n", a);

}

// static局部变量 之定义一次在全局位置但是作用于在局部
void test18()
{
    for (int var = 0; var < 10; ++var) {
        static int b = 10;
        printf("b = %d\n", ++b);
    }
}

// 静态函数 只能在本文件中使用,其他文件即使声明也无法使用

// 生命周期 作用域

// 申请堆空间
void test19()
{
    int *p = (int *)malloc(sizeof(int) * 10);
    if (NULL == p) {
        printf("malloc error\n");
        return;
    }
    for (int var = 0; var < 10; ++var) {
        *(p + var) = var + 10;
    }
    // 读出malloc空间中的数据
    for (int var = 0; var < 10; ++var) {
        printf("%d\n", p[var]);
    }
    free(p);
    p = NULL;
}

// 二级指针malloc空间
void test20()
{
    int **pp = (int **)malloc(sizeof(int *) * 3);
    for (int var = 0; var < 3; ++var) {
        *(pp + var) = malloc(sizeof(int) * 5);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            pp[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d\n", *(*(pp + i) + j));
        }
    }

    for (int var = 0; var < 3; ++var) {
         free(*(pp + var));
         *(pp + var) = NULL;
    }
    free(pp);
    pp = NULL;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
//    test09();
//    test10();
//    test11();
//    test12();
//    test13();
//    test14();
//    test15();
//    test16();
//    test18();
//    test19();
    test20();

    return 0;
}
