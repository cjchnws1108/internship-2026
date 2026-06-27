#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // 1. 判断命令行参数是否传入文件名
    if (argc != 2)
    {
        printf("用法：%s 待统计的文本文件名.txt\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    // 处理文件不存在异常
    if (in == NULL)
    {
        printf("错误：文件 %s 不存在，打开失败！\n", argv[1]);
        return 1;
    }

    FILE *out = fopen("result.txt", "w");
    if (out == NULL)
    {
        printf("错误：无法创建result.txt结果文件！\n");
        fclose(in);
        return 1;
    }

    long chars = 0;    // 总字符数（含空格换行）
    long lines = 0;    // 总行数
    long words = 0;    // 单词数（空格/换行分隔）
    char ch;
    int in_word = 0;   // 标记当前是否处于单词内

    while ((ch = fgetc(in)) != EOF)
    {
        chars++;

        // 换行，行数+1
        if (ch == '\n')
            lines++;

        // 判断是否为分隔符
        if (isspace(ch))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            // 遇到非空格，新单词
            words++;
            in_word = 1;
        }
    }

    fclose(in);

    // 屏幕输出结果
    printf("======== 文件统计结果 ========\n");
    printf("文件名：%s\n", argv[1]);
    printf("总行数：%ld\n", lines);
    printf("总字符数：%ld\n", chars);
    printf("总单词数：%ld\n", words);

    // 写入result.txt
    fprintf(out, "======== 文件统计结果 ========\n");
    fprintf(out, "文件名：%s\n", argv[1]);
    fprintf(out, "总行数：%ld\n", lines);
    fprintf(out, "总字符数：%ld\n", chars);
    fprintf(out, "总单词数：%ld\n", words);
    fclose(out);

    printf("\n统计数据已保存至 result.txt\n");
    return 0;
}
