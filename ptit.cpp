#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

struct SinhVien
{
    int id;
    char ten[30];
    char email[50];
    char phone[11];
    char bill[50];
};

typedef SinhVien SV;

void printLine(int n);
void nhapThongTinSV(SV &sv, int id);
void nhapSV(SV a[], int id, int n);
void capNhatThongTinSV(SV &sv);
void capNhatSV(SV a[], int id, int n);
int xoaTheoID(SV a[], int id, int n);
void timKiemTheoTen(SV a[], char ten[], int n);
void tinhDTB(SV &sv);
void xeploai(SV &sv);
int idLonNhat(SV a[], int n);
void sapxepTheoDTB(SV a[], int n);
void sapXepTheoTen(SV a[], int n);
void showStudent(SV a[], int n);
int docFile(SV a[], char fileName[]);
void ghiFile(SV a[], int n, char fileName[]);
void pressAnyKey();

int main()
{
    int key;
    char fileName[] = "sinhvien.txt";
    SV arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;

    // nhap danh sach sinh vien tu file
    soluongSV = docFile(arraySV, fileName);
    idCount = idLonNhat(arraySV, soluongSV);

    while (true)
    {
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Cap nhat thong tin sinh vien boi ID.          **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  5. Sap xep sinh vien theo ten.                   **\n";
        cout << "**  6. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  7. Ghi danh sach sinh vien vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "\n1. Them sinh vien.";
            idCount++;
            nhapSV(arraySV, idCount, soluongSV);
            printf("\nThem sinh vien thanh cong!");
            soluongSV++;
            pressAnyKey();
            break;
        case 2:
            if (soluongSV > 0)
            {
                int id;
                cout << "\n2. Cap nhat thong tin sinh vien. ";
                cout << "\n Nhap ID: ";
                cin >> id;
                capNhatSV(arraySV, id, soluongSV);
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 3:
            if (soluongSV > 0)
            {
                int id;
                cout << "\n3. Xoa sinh vien.";
                cout << "\n Nhap ID: ";
                cin >> id;
                if (xoaTheoID(arraySV, id, soluongSV) == 1)
                {
                    printf("\nSinh vien co id = %d da bi xoa.", &id);
                    soluongSV--;
                }
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 4:
            if (soluongSV > 0)
            {
                cout << "\n4. Tim kiem sinh vien theo ten.";
                char strTen[30];
                cout << "\nNhap ten de tim kiem: ";
                fflush(stdin);
                gets(strTen);
                timKiemTheoTen(arraySV, strTen, soluongSV);
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 5:
            if (soluongSV > 0)
            {
                cout << "\n5. Sap xep sinh vien theo ten.";
                sapXepTheoTen(arraySV, soluongSV);
                showStudent(arraySV, soluongSV);
            }
            else
            {
                cout << "\nSanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 6:
            if (soluongSV > 0)
            {
                cout << "\n6. Hien thi danh sach sinh vien.";
                showStudent(arraySV, soluongSV);
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            pressAnyKey();
            break;
        case 7:
            if (soluongSV > 0)
            {
                cout << "\n7. Ghi danh sach sinh vien vao file.";
                ghiFile(arraySV, soluongSV, fileName);
            }
            else
            {
                cout << "\nDanh sach sinh vien trong!";
            }
            printf("\nGhi danh sach sinh vien vao file %s thanh cong!", fileName);
            pressAnyKey();
            break;
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            getch();
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    }
}

void nhapThongTinSV(SV &sv, int id)
{
    cout << "\n Nhap ten: ";
    fflush(stdin);
    gets(sv.ten);
    cout << " Nhap email: ";
    gets(sv.email);
    cout << " Nhap SDT: ";
    gets(sv.phone);
    cout << " Nhap Bill: ";
    gets(sv.bill);
    sv.id = id;
}

void nhapSV(SV a[], int id, int n)
{
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n], id);
    printLine(40);
}

void capNhatThongTinSV(SV &sv)
{
    cout << "\n Nhap ten: ";
    fflush(stdin);
    gets(sv.ten);
    cout << " Nhap email: ";
    gets(sv.email);
    cout << " Nhap SDT: ";
    gets(sv.phone);
    cout << " Nhap Bill: ";
    gets(sv.bill);
}

void capNhatSV(SV a[], int id, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == id)
        {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co ID = " << id;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0)
    {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
    }
}

int xoaTheoID(SV a[], int id, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == id)
        {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            printLine(40);
            break;
        }
    }
    if (found == 0)
    {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    }
    else
    {
        return 1;
    }
}

void timKiemTheoTen(SV a[], char ten[], int n)
{
    SV arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        strcpy(tenSV, a[i].ten);
        if (strstr(strupr(tenSV), strupr(ten)))
        {
            arrayFound[found] = a[i];
            found++;
        }
    }
    showStudent(arrayFound, found);
}

void showStudent(SV a[], int n)
{
    printLine(100);
    cout << "ID\tHo va ten\tEmail\t\t\tSDT\tBill";
    for (int i = 0; i < n; i++)
    {
        // in sinh vien thu i ra man hinh
        printf("\n");
        printf("%d", a[i].id);
        printf("\t%s", a[i].ten);
        printf("\t%s", a[i].email);
        printf("\t%s", a[i].phone);
        printf("\t%s", a[i].bill);
    }
    printLine(100);
}

void sapXepTheoTen(SV a[], int n)
{
    // Sap xep sinh vien theo ten theo thu tu tang dan
    SV tmp;
    char tenSV1[30];
    char tenSV2[30];
    for (int i = 0; i < n; i++)
    {
        strcpy(tenSV1, a[i].ten);
        for (int j = i + 1; j < n; j++)
        {
            strcpy(tenSV2, a[j].ten);
            if (strcmp(strupr(tenSV1), strupr(tenSV2)) > 0)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int idLonNhat(SV a[], int n)
{
    int idMax = 0;
    if (n > 0)
    {
        idMax = a[0].id;
        for (int i = 0; i < n; i++)
        {
            if (a[i].id > idMax)
            {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}

int docFile(SV a[], char fileName[])
{
    FILE *fp;
    int i = 0;
    fp = fopen(fileName, "r");
    cout << "Chuan bi doc file: ";
    puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%d%10s%10s%10s%10s\n", &a[i].id, &a[i].ten, &a[i].email, &a[i].phone, &a[i].bill) != EOF)
    {
        i++;
        cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    fclose(fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}

void ghiFile(SV a[], int n, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d%10s%10s%10s%10s\n", a[i].id, a[i].ten, a[i].email, a[i].phone, a[i].bill);
    }
    fclose(fp);
}
void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey()
{
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
