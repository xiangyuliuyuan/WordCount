#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILENAME_LEN 1000
#define LINE_LEN 1000
int count_chars(char *filename);
int count_words(char *filename);
int main(int argc, char *arg[]) {
    char filename[FILENAME_LEN];
    char *parameter;
    int results;
    if (argc != 3) {
        printf("�÷�: %s [-c | -w] [�ļ���]\n", arg[0]);
        return 1;
    }
    parameter = arg[1];
    strcpy(filename, arg[2]);
    if (strcmp(parameter, "-c") == 0) {
        results = count_chars(filename);
        printf("�ַ�����%d\n", results);
    } else if (strcmp(parameter, "-w") == 0) {
        results = count_words(filename);
        printf("��������%d\n", results);
    } else {
        printf("��Ч�Ĳ��� %s\n", parameter);
        return 1;
    }
    return 0;
}
// ͳ�Ƶ�����
int count_words(char *filename) {
    FILE *fp;
    char line[LINE_LEN];
    char *word;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        exit(1);
    }

    while (fgets(line,LINE_LEN,fp) != NULL) {
        word = strtok(line, " ,\t\n"); 
        while (word != NULL) {
            count++;
            word = strtok(NULL, " ,\t\n");
        }
    }
    fclose(fp);
    return count;
}
// ͳ���ַ���
int count_chars(char *filename) {
    FILE *fp;
    char line[LINE_LEN];
    int count =0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        exit(1);
    }

    while (fgets(line, LINE_LEN, fp) != NULL) {
        count += strlen(line);
    }
    fclose(fp);
    return count;
}
