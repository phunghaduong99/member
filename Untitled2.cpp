#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ID;
    int MSSV;
    char hoTen[100];
    int Group_id;
}thanhvien;
void Nhap_lo(thanhvien *tv)
{
   
    printf("Nhap ID:\n");
    scanf("%d",&tv->ID);
   
}

int main()
{
   thanhvien tv1[200];
   int i,j,k,h,m,size,dem=0;
   char hoten[30],hoten1[30];
   printf("Nhap vao so thanh vien:\n");
   scanf("%d",&size);
   for(i=0;i<size;i++)
   {
       Nhap_lo(&tv1[i]);
   }
}
