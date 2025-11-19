#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[5];
    float totalValue = 0.0;
    printf("Nhap thong tin cho 5 san pham:\n");
    for (int i = 0; i < 5; i++) {
        printf("\n--- San pham thu %d ---\n", i + 1);
        printf("Nhap ten san pham: ");
        scanf("%s", products[i].name);
        printf("Nhap gia: ");
        scanf("%f", &products[i].price);
        printf("Nhap so luong: ");
        scanf("%d", &products[i].quantity);
    }

    for (int i = 0; i < 5; i++) {
        totalValue += products[i].price * products[i].quantity;
    }

    printf("\nTong gia tri tat ca san pham la: %.2f\n", totalValue);

    return 0;
}

