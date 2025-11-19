#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char ma[20];
    char ten[50];
    float giaNhap;
    float giaBan;
    int soLuong;
} SanPham;

SanPham ds[MAX];
int soLuongSP = 0;
float doanhThu = 0;
int timTheoMa(char ma[]) {
    for (int i = 0; i < soLuongSP; i++) {
        if (strcmp(ds[i].ma, ma) == 0)
            return i;
    }
    return -1;
}

void nhapDanhSach() {
    int n;
    printf("Nhap so luong san pham ban dau: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        SanPham sp;
        printf("\n=== San pham %d ===\n", i + 1);
        printf("Ma san pham: "); gets(sp.ma);
        printf("Ten san pham: "); gets(sp.ten);
        printf("Gia nhap: "); scanf("%f", &sp.giaNhap);
        printf("Gia ban: "); scanf("%f", &sp.giaBan);
        printf("So luong: "); scanf("%d", &sp.soLuong);
        getchar();

        ds[soLuongSP++] = sp;
        doanhThu -= sp.soLuong * sp.giaNhap;
    }
}

void hienThi() {
    printf("\n===== DANH SACH SAN PHAM =====\n");
    for (int i = 0; i < soLuongSP; i++) {
        printf("%d. %s - %s | Nhap: %.2f | Ban: %.2f | SL: %d\n",
            i + 1, ds[i].ma, ds[i].ten, ds[i].giaNhap, ds[i].giaBan, ds[i].soLuong);
    }
}

void nhapSanPham() {
    SanPham sp;
    printf("Nhap ma san pham: ");
    getchar();
    gets(sp.ma);
    int index = timTheoMa(sp.ma);

    if (index != -1) {
        int sl;
        printf("San pham da ton tai. Nhap so luong muon them: ");
        scanf("%d", &sl);

        ds[index].soLuong += sl;
        doanhThu -= sl * ds[index].giaNhap;

        printf("Da cap nhat so luong!\n");
    } else {
        printf("Ten san pham: "); gets(sp.ten);
        printf("Gia nhap: "); scanf("%f", &sp.giaNhap);
        printf("Gia ban: "); scanf("%f", &sp.giaBan);
        printf("So luong: "); scanf("%d", &sp.soLuong);
        ds[soLuongSP++] = sp;
        doanhThu -= sp.soLuong * sp.giaNhap;
        printf("Them san pham moi thanh cong!\n");
    }
}

void capNhat() {
    char ma[20];
    printf("Nhap ma san pham can cap nhat: ");
    getchar();
    gets(ma);
    int index = timTheoMa(ma);
    if (index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }
    printf("Nhap ten moi: "); gets(ds[index].ten);
    printf("Nhap gia nhap moi: "); scanf("%f", &ds[index].giaNhap);
    printf("Nhap gia ban moi: "); scanf("%f", &ds[index].giaBan);
    printf("Nhap so luong moi: "); scanf("%d", &ds[index].soLuong);
    printf("Cap nhat thanh cong!\n");
}

void sapXep() {
    int chon;
    printf("1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &chon);

    for (int i = 0; i < soLuongSP - 1; i++) {
        for (int j = i + 1; j < soLuongSP; j++) {
            if ((chon == 1 && ds[i].giaBan > ds[j].giaBan) ||
                (chon == 2 && ds[i].giaBan < ds[j].giaBan)) {
                SanPham temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep xong!\n");
}

void timKiem() {
    char key[50];
    printf("Nhap tu khoa tim kiem: ");
    getchar();
    gets(key);
    printf("\n=== Ket qua tim kiem ===\n");
    for (int i = 0; i < soLuongSP; i++) {
        if (strstr(ds[i].ten, key) || strstr(ds[i].ma, key)) {
            printf("%s - %s | Gia ban: %.2f | So luong: %d\n",
                ds[i].ma, ds[i].ten, ds[i].giaBan, ds[i].soLuong);
        }
    }
}

void banSanPham() {
    char ma[20];
    printf("Nhap ma san pham can ban: ");
    getchar();
    gets(ma);
    int index = timTheoMa(ma);
    if(index == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }

    if (ds[index].soLuong == 0) {
        printf("Het hang!\n");
        return;
    }

    int sl;
    printf("Nhap so luong ban: ");
    scanf("%d", &sl);

    if (sl > ds[index].soLuong) {
        printf("Khong du hang!\n");
        return;
    }

    ds[index].soLuong -= sl;
    doanhThu += sl * ds[index].giaBan;

    printf("Ban thanh cong!\n");
}

int main() {
    int chon;
    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: nhapDanhSach(); break;
            case 2: hienThi(); break;
            case 3: nhapSanPham(); break;
            case 4: capNhat(); break;
            case 5: sapXep(); break;
            case 6: timKiem(); break;
            case 7: banSanPham(); break;
            case 8: printf("Doanh thu hien tai: %.2f\n", doanhThu); break;
            case 9: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (chon != 9);

    return 0;
}

