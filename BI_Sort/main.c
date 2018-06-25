/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: chrisr598
 *
 * Created on 24 de junio de 2018, 12:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

int d[]={9, 6, 0, 4, 13, 11, 14, 1, 7, 12, 45, 128};//arreglo en rango [0..m-1]

int main(int argc, char** argv) {
    int n = sizeof(d)/sizeof(d[0]);
    int m = 129;//limite superior
    int bi[m/32+1];//arreglo de bits 
    
    for(int i=0;i<=m/32;i++)
        bi[i]=0;
    
    int ind = 0;
    int off = 0;
    for(int i=0; i<n; i++){
        ind = d[i]/32;
        off = d[i]%32;        
        bi[ind] = (bi[ind]) | (1<<off);
        //printf("%d\n",bi[0]);
    }
    
    int i= 0;
    for(int j=m/32;j>=0;j--){
        while (bi[j]>0){
            off = 31 - __builtin_clz(bi[j]);
            d[i] = j*32 + off;
            bi[j] -= (1<<off);   
            i++;
        }
    }
    
    for(int i=0; i<n; i++){    
        printf("%d\n ",d[i]);
    }           

    return (EXIT_SUCCESS);
}

