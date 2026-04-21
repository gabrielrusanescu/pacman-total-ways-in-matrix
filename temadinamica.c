/*
Grupa: 161
Problema: 5
Nume: Rusănescu Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MODULO 16561

int calculeaza_trasee(int n, int m){
    if(n<=0 || m<=0) return 0;
    int **dp=(int **)malloc(n * sizeof(int *));
    if(dp==NULL) return 0;
    for(int i=0; i<n; i++){
        dp[i]=(int *)malloc(m * sizeof(int));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }else{
                dp[i][j]=(dp[i-1][j] + dp[i][j-1]) % MODULO;
            }
        }
    }
    int rezultat=dp[n-1][m-1];
    for(int i=0; i<n; i++){
        free(dp[i]);
    }
    free(dp);
    return rezultat;
}

int main(){
    FILE *f;
    int n, m, rezultat;
    //Test1
    f=fopen("pacman.in", "w");
    if(f!=NULL){
        fprintf(f, "2 2");
        fclose(f);
    }
    f=fopen("pacman.in", "r");
    if(f!=NULL){
        fscanf(f, "%d %d", &n, &m);
        fclose(f);
    }
    rezultat=calculeaza_trasee(n, m);
    printf("Test1 (n=%d, m=%d). Rezultat=%d\n", n, m, rezultat);
    assert(rezultat==2);
    
    //Test2
    f=fopen("pacman.in", "w");
    if(f!=NULL){
        fprintf(f, "2 3");
        fclose(f);
    }
    f=fopen("pacman.in", "r");
    if(f!=NULL) {
        fscanf(f, "%d %d", &n, &m);
        fclose(f);
    }
    rezultat=calculeaza_trasee(n, m);
    printf("Test2 (n=%d, m=%d). Rezultat=%d\n", n, m, rezultat);
    assert(rezultat==3);

    //Test3
    f=fopen("pacman.in", "w");
    if(f!=NULL){
        fprintf(f, "3 3");
        fclose(f);
    }
    f=fopen("pacman.in", "r");
    if(f!=NULL){
        fscanf(f, "%d %d", &n, &m);
        fclose(f);
    }
    rezultat=calculeaza_trasee(n, m);
    printf("Test3 (n=%d, m=%d). Rezultat=%d\n", n, m, rezultat);
    assert(rezultat==6);
    printf("\nToate cele 3 teste (cu verificari assert) au fost cu succes!\n");
    return 0;
}
