#include <stdio.h>

// 加法
double add(double a, double b)
{
    return a + b;
}
// 减法
double sub(double a, double b)
{
    return a - b;
}
// 乘法
double mul(double a, double b)
{
    return a * b;
}
// 除法：返回1正常，返回0代表除零错误
int div_calc(double a, double b, double *res)
{
    if (b == 0)
    {
        return 0;
    }
    *res = a / b;
    return 1;
}

int main()
{
    double num1, num2, result;
    char op;
    printf("===== 循环简易计算器 =====\n");
    printf("支持 + - * / 四则运算，输入 q 即可退出\n");

    while (1)  
    {
        printf("\n请输入第一个数字：");
        if (scanf("%lf", &num1) != 1)
        {
            // 清空输入缓冲区
            getchar();
            scanf("%c", &op);
            if (op == 'q' || op == 'Q')
            {
                printf("计算器程序退出！\n");
                break;
            }
            printf("输入错误，请输入数字！\n");
            while (getchar() != '\n');
            continue;
        }

        printf("请输入运算符(+ - * /)：");
        scanf(" %c", &op);
        if (op == 'q' || op == 'Q')
        {
            printf("计算器程序退出！\n");
            break;
        }

        printf("请输入第二个数字：");
        scanf("%lf", &num2);

        // switch-case 匹配运算符
        switch (op)
        {
            case '+':
                result = add(num1, num2);
                printf("结果：%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '-':
                result = sub(num1, num2);
                printf("结果：%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '*':
                result = mul(num1, num2);
                printf("结果：%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '/':
                if (div_calc(num1, num2, &result))
                {
                    printf("结果：%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                else
                {
                    printf("【错误】除数不能为0，计算失败！\n");
                }
                break;
            default:
                printf("【错误】非法运算符，仅支持 + - * /\n");
                break;
        }
    }
    return 0;
}
