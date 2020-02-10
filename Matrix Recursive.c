#include<stdio.h>

void input(int *baris, int *kolom, int *a, int *b);
void bikin_m1(int M[30][30], int baris, int kolom, int a, int b);
void bikin_m2(int M[30][30], int baris, int kolom, int a, int b, int nilai);
void cetak_m(int M[30][30],int baris, int kolom);

int main()
{
    int M[30][30], baris, kolom, a, b;

    input(&baris,&kolom, &a, &b);
    bikin_m1(M, baris,kolom, a-1, b-1);
    bikin_m2(M, baris,kolom, a-1, b-1, 2);
    cetak_m(M, baris, kolom);
}
void input(int *baris, int *kolom, int *a, int *b)
{
    printf("baris: ");
    scanf("%d",&*baris);
    printf("kolom: ");
    scanf("%d",&*kolom);
    printf("lokasi baris: ");
    scanf("%d",&*a);
    printf("lokasi kolom: ");
    scanf("%d",&*b);
}
void bikin_m1(int M[30][30], int baris, int kolom, int a, int b)
{
    for(int i=0;i<baris;i++)
    {
        for(int j=0;j<kolom;j++)
        {
            M[i][j] = 0;

            if(i == a && j == b)
            {
                M[i][j] = 1;
            }
        }
    }
}
void bikin_m2(int M[30][30], int baris, int kolom, int a, int b, int nilai)
{
    int i, T, B, L, R;
    T = a - (nilai-1);
    B = a + (nilai-1);
    L = b - (nilai-1);
    R = b + (nilai-1);

    if(T<0)T=0;
    if(B>baris-1)B=baris-1;
    if(L<0)L=0;
    if(R>kolom-1)R=kolom-1;

    for(i = L;i<=R;i++)
        if(M[T][i] == 0)M[T][i] = nilai;
    for(i = T;i<=B;i++)
        if(M[i][R] == 0)M[i][R] = nilai;
    for(i = R;i>=L;i--)
        if(M[B][i] == 0)M[B][i] = nilai;
    for(i = B;i>=T;i--)
        if(M[i][L] == 0)M[i][L] = nilai;

    nilai++;
    if(T==0 && B==baris-1 && L==0 && R==kolom-1)return;
    bikin_m2(M, baris, kolom, a, b, nilai);
}
void cetak_m(int M[30][30],int baris, int kolom)
{
    for(int i=0;i<baris;i++)
    {
        for(int j=0; j<kolom; j++)
        {
            printf("%3d ",M[i][j]);
        }
        printf("\n");
    }
}

