#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    struct Book books[3];
    int i;
    
	printf("Nhap thong tin cho 3 quyen sach:\n");

    for (i = 0; i < 3; i++) {
        printf("\n----------Sach thu %d----------\n", i + 1);
        printf("Nhap ten sach:");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;
        printf("Nhap tac gia:");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        printf("Nhap gia:");
        scanf("%f", &books[i].price);
        
        while (getchar() != '\n');
    }

    printf("\n----------Thong tin cac quyen sach da nhap----------\n");

    for (i = 0; i < 3; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia: %.2f\n", books[i].price);
    }

    return 0;
}

