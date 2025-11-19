#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

void inputStudent(struct Student *s) {
    printf("Nhap ten:");
    if (getchar() == '\n') getchar(); 
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;

    printf("Nhap tuoi:");
    scanf("%d", &s->age);

    printf("Nhap diem trung binh:");
    scanf("%f", &s->grade);
}

void printStudent(const struct Student *s) {
    printf("Ten: %s\n", s->name);
    printf("Tuoi: %d\n", s->age);
    printf("Diem trung binh: %.2f\n", s->grade);
}

int findStudentByName(struct Student students[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Student students[5];
    int numStudents = 5;
    printf("Nhap thong tin cho 5 hoc sinh:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nHoc sinh thu %d:\n", i + 1);
        inputStudent(&students[i]);
    }

    char searchName[50];
    printf("\nNhap ten hoc sinh can tim kiem:");
    if (getchar() == '\n') getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    int index = findStudentByName(students, numStudents, searchName);
    if (index != -1) {
        printf("\nTim thay hoc sinh:\n");
        printStudent(&students[index]);
    } else {
        printf("\nKhong tim thay hoc sinh co ten '%s'.\n", searchName);
    }

    return 0;
}

