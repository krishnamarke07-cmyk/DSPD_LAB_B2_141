/*
Write a program which creates a structure Student which must have the attribute Avg Marks
with 3 more attributes. Sort the list of the students in descending order using Bubble sort.
*/

#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char course[30];
    float avg_marks;
};

int main() {
    int n, i, j;
    struct Student temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Course: ");
        scanf("%s", s[i].course);
        printf("Average Marks: ");
        scanf("%f", &s[i].avg_marks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avg_marks < s[j + 1].avg_marks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Average Marks (Descending):\n");
    printf("Roll No\tName\tCourse\tAverage Marks\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%.2f\n", s[i].roll_no, s[i].name, s[i].course, s[i].avg_marks);
    }

    return 0;
}
