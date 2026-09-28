// 1. Phân tích Input/Output

// Input:
// n: số lượng bệnh nhân ban đầu, 0 <= n <= 100.
// Mã số thứ tự khám.
// Tuổi bệnh nhân, từ 1 đến 120.
// Trạng thái BHYT: 0 hoặc 1.
// K: vị trí bệnh nhân cần hủy.

// Output:
// Danh sách hàng chờ ban đầu.
// Tổng doanh thu dự kiến.
// Số bệnh nhân ưu tiên.
// Danh sách sau khi hủy.
// Tổng doanh thu sau khi hủy.


#include <stdio.h>

#define MAX 100

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bao_hiem[MAX];
    int phi_kham[MAX];

    int n;
    int k;
    int tong_doanh_thu = 0;
    int so_uu_tien = 0;

    // Nhap so luong benh nhan
    do {
        printf("Nhap so luong benh nhan (0-%d): ", MAX);
        scanf("%d", &n);

        if (n < 0 || n > MAX) {
            printf("So luong khong hop le!\n");
        }
    } while (n < 0 || n > MAX);

    // Nhap thong tin benh nhan
    for (int i = 0; i < n; i++) {
        printf("\nBenh nhan %d\n", i + 1);

        printf("Nhap ma so thu tu: ");
        scanf("%d", &ma_so[i]);

        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le!\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Nhap BHYT (0: Khong, 1: Co): ");
            scanf("%d", &bao_hiem[i]);

            if (bao_hiem[i] != 0 && bao_hiem[i] != 1) {
                printf("Trang thai BHYT khong hop le!\n");
            }
        } while (bao_hiem[i] != 0 && bao_hiem[i] != 1);

        // Tinh phi kham
        if (bao_hiem[i] == 1) {
            phi_kham[i] = 30000;
        } else {
            phi_kham[i] = 150000;
        }
    }

    // Tinh tong doanh thu va so benh nhan uu tien
    tong_doanh_thu = 0;
    so_uu_tien = 0;

    for (int i = 0; i < n; i++) {
        tong_doanh_thu += phi_kham[i];

        if (tuoi[i] >= 70) {
            so_uu_tien++;
        }
    }

    // In danh sach ban dau
    printf("\n--- HANG CHO BAN DAU ---\n");

    for (int i = 0; i < n; i++) {
        printf("Index %d: Ma so %d | Tuoi %d | BHYT %d | Phi %d VNĐ",
               i, ma_so[i], tuoi[i], bao_hiem[i], phi_kham[i]);

        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
        } else {
            printf(" | THUONG\n");
        }
    }

    printf("Tong doanh thu du kien: %d VNĐ\n", tong_doanh_thu);
    printf("So benh nhan uu tien: %d\n", so_uu_tien);

    // Nhap vi tri can huy
    if (n == 0) {
        printf("\nHang cho dang rong, khong the huy!\n");
    } else {
        printf("\nNhap chi so K can huy (0-%d): ", n - 1);
        scanf("%d", &k);

        if (k < 0 || k >= n) {
            printf("Vi tri K khong hop le!\n");
        } else {
            // Don mang sang trai
            for (int i = k; i < n - 1; i++) {
                ma_so[i] = ma_so[i + 1];
                tuoi[i] = tuoi[i + 1];
                bao_hiem[i] = bao_hiem[i + 1];
                phi_kham[i] = phi_kham[i + 1];
            }

            n--;

            // Tinh lai doanh thu va so uu tien
            tong_doanh_thu = 0;
            so_uu_tien = 0;

            for (int i = 0; i < n; i++) {
                tong_doanh_thu += phi_kham[i];

                if (tuoi[i] >= 70) {
                    so_uu_tien++;
                }
            }

            // In danh sach sau khi huy
            printf("\n--- HANG CHO SAU KHI HUY ---\n");

            for (int i = 0; i < n; i++) {
                printf("Index %d: Ma so %d | Tuoi %d | BHYT %d | Phi %d VNĐ",
                       i, ma_so[i], tuoi[i], bao_hiem[i], phi_kham[i]);

                if (tuoi[i] >= 70) {
                    printf(" | UU TIEN\n");
                } else {
                    printf(" | THUONG\n");
                }
            }

            printf("Tong doanh thu sau khi huy: %d VNĐ\n", tong_doanh_thu);
            printf("So benh nhan uu tien: %d\n", so_uu_tien);
        }
    }

    return 0;
}

