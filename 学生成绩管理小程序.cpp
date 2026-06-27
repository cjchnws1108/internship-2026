#include <stdio.h>
#include <string.h>

#define STU_NUM 5   
#define COURSE_NUM 3 

struct Student {
    char name[20];
    int score[COURSE_NUM];
    int total;
    double avg;
};

// 输入学生信息
void inputStu(struct Student stu[]) {
    int i, j;
    for (i = 0; i < STU_NUM; i++) {
        printf("请输入第%d位学生姓名：", i + 1);
        scanf("%s", stu[i].name);
        stu[i].total = 0;
        printf("请输入3门课程成绩：");
        for (j = 0; j < COURSE_NUM; j++) {
            scanf("%d", &stu[i].score[j]);
            stu[i].total += stu[i].score[j];
        }
        stu[i].avg = stu[i].total / 3.0;
    }
}

// 按总分降序排序
void sortByTotal(struct Student stu[]) {
    int i, j;
    struct Student temp;
    for (i = 0; i < STU_NUM - 1; i++) {
        for (j = 0; j < STU_NUM - 1 - i; j++) {
            if (stu[j].total < stu[j + 1].total) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

// 输出排序后的学生信息
void printAll(struct Student stu[]) {
    int i, j;
    printf("\n=====按总分降序排序结果=====\n");
    printf("姓名\t课程1\t课程2\t课程3\t总分\t平均分\n");
    for (i = 0; i < STU_NUM; i++) {
        printf("%s\t", stu[i].name);
        for (j = 0; j < COURSE_NUM; j++) {
            printf("%d\t", stu[i].score[j]);
        }
        printf("%d\t%.2f\n", stu[i].total, stu[i].avg);
    }
}

// 查找每门课最高分学生并输出
void findMaxScore(struct Student stu[]) {
    int i, j, maxVal;
    char maxName[20];
    printf("\n=====每门课程最高分学生=====\n");
    for (j = 0; j < COURSE_NUM; j++) {
        maxVal = stu[0].score[j];
        strcpy(maxName, stu[0].name);
        for (i = 1; i < STU_NUM; i++) {
            if (stu[i].score[j] > maxVal) {
                maxVal = stu[i].score[j];
                strcpy(maxName, stu[i].name);
            }
        }
        printf("第%d门课最高分：%d，学生：%s\n", j + 1, maxVal, maxName);
    }
}

int main() {
    struct Student stu[STU_NUM];
    inputStu(stu);
    sortByTotal(stu);
    printAll(stu);
    findMaxScore(stu);
    return 0;
}
