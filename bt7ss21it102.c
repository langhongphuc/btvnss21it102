#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char maSach[20];
    char tenSach[50];
    char tacGia[50];
    float gia;
    char theLoai[30];
} Sach;

void nhapSach(Sach *s) {
    printf("Nhap ma sach: "); fflush(stdin); gets(s->maSach);
    printf("Nhap ten sach: "); fflush(stdin); gets(s->tenSach);
    printf("Nhap tac gia: "); fflush(stdin); gets(s->tacGia);
    printf("Nhap gia tien: "); scanf("%f", &s->gia);
    printf("Nhap the loai: "); fflush(stdin); gets(s->theLoai);
}

void hienThiSach(Sach s) {
    printf("\n%-15s %-20s %-20s %-10.2f %-15s",
           s.maSach, s.tenSach, s.tacGia, s.gia, s.theLoai);
}

int timTheoMa(Sach a[], int n, char ma[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].maSach, ma) == 0)
            return i;
    return -1;
}

void themSachViTri(Sach a[], int *n) {
    int vt;
    Sach s;
    printf("Nhap vi tri muon them (0 -> %d): ", *n);
    scanf("%d", &vt);

    if (vt < 0 || vt > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap thong tin sach muon them:\n");
    nhapSach(&s);

    for (int i = *n; i > vt; i--)
        a[i] = a[i - 1];

    a[vt] = s;
    (*n)++;

    printf("Da them sach thanh cong!\n");
}

void xoaSach(Sach a[], int *n) {
    char ma[20];
    printf("Nhap ma sach can xoa: ");
    fflush(stdin); gets(ma);

    int vt = timTheoMa(a, *n, ma);

    if (vt == -1) {
        printf("Khong tim thay ma sach!\n");
        return;
    }

    for (int i = vt; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
    printf("Da xoa sach thanh cong!\n");
}

void capNhatSach(Sach a[], int n) {
    char ma[20];
    printf("Nhap ma sach can cap nhat:");
    fflush(stdin); gets(ma);

    int vt = timTheoMa(a, n, ma);

    if(vt == -1) {
        printf("Khong tim thay ma sach!\n");
        return;
    }

    printf("Nhap thong tin moi cho sach:\n");
    nhapSach(&a[vt]);
    printf("Cap nhat thanh cong!\n");
}

void sapXepGia(Sach a[], int n, int tang) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((tang && a[i].gia > a[j].gia) ||
                (!tang && a[i].gia < a[j].gia)) {
                Sach temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Da sap xep danh sach sach!\n");
}

void timKiemTen(Sach a[], int n) {
    char ten[50];
    printf("Nhap ten sach can tim: ");
    fflush(stdin); gets(ten);

    printf("\nKET QUA TIM KIEM:\n");
    printf("%-15s %-20s %-20s %-10s %-15s\n",
           "Ma Sach", "Ten Sach", "Tac Gia", "Gia", "The Loai");

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strstr(a[i].tenSach, ten) != NULL) {
            hienThiSach(a[i]);
            found = 1;
        }
    }

    if (!found)
        printf("Khong tim thay sach!\n");
}

int main() {
    Sach ds[MAX];
    int n = 0;
    int chon;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Cap nhat sach theo ma\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nNhap sach thu %d:\n", i + 1);
                    nhapSach(&ds[i]);
                }
                break;

            case 2:
                printf("\n%-15s %-20s %-20s %-10s %-15s\n",
                       "Ma Sach", "Ten Sach", "Tac Gia", "Gia", "The Loai");
                for (int i = 0; i < n; i++)
                    hienThiSach(ds[i]);
                printf("\n");
                break;

            case 3:
                themSachViTri(ds, &n);
                break;

            case 4:
                xoaSach(ds, &n);
                break;

            case 5:
                capNhatSach(ds, n);
                break;

            case 6: {
                int t;
                printf("1. Tang dan\n2. Giam dan\nChon: ");
                scanf("%d", &t);
                sapXepGia(ds, n, (t == 1));
                break;
            }

            case 7:
                timKiemTen(ds, n);
                break;

            case 0:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}

