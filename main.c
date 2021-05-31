//  main.c
//  CSI 333
//  Spring 2019
//  Project2
//  Qin Weiwei
//
//  Created by Weiwei Qin on 2019/3/31.
//  Copyright © 2019 Qin Weiwei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 255
#define NUM 3
#define IN 1
#define OUT 2

int main(int argc,char *argv[]){
    char f1[MAXNUM];  //store the output from the inputfile
    char f2[MAXNUM];  //store the input into the outputfile
    FILE *inputfile,*outputfile;            //a pointer points to the file
    int len1,len2 = 0;             //the length of the characters
    
    strcpy(f1,argv[1]);
    strcat(f1,".txt");
    strcpy(f2,argv[2]);
    strcat(f2,".txt");
    
    //inputfile = fopen("/Volumes/KINGSTON/CSI 333/Project/Project2/Project2/Project2/Inputfile.txt","r");
    //outputfile = fopen("/Volumes/KINGSTON/CSI 333/Project/Project2/Project2/Project2/Outputfile.txt","w");
    inputfile = fopen(f1,"r");
    outputfile = fopen(f2,"w");
    
    if(argc < NUM){
        printf("ERROR.");
        exit(1);
    }
    /*
    if(inputfile == NULL){
        printf("Could not open the file %s .\n",argv[IN]);
        exit(1);
    }
    
    if(outputfile == NULL){
        printf("Could not open the file %s .\n",argv[OUT]);
        exit(1);
    }
     */
    
    /*
     Print the characters from the Inputfile.
     */
    while(fgets(f1,MAXNUM,inputfile) != NULL){
        len1 = strlen(f1) - 1;
        while(len1 >= 0){
            int a = 0;
            int i = 0;
            char c = f1[len1];
            char temp[MAXNUM] = ""; //a buf to store the value
            while(c != '\n' && c != '\t' && c != ' ' && len1 >= 0){
                a = 1;
                temp[i] = c;
                i ++;
                len1 --;
                c = f1[len1];
            }
            if(a == 1){
                len2 = strlen(temp) - 1;
                while(len2 >= 0){
                    putc(temp[len2],outputfile);
                    len2 --;
                }
                putc(' ',outputfile);
            }
            else{
                len1 --;
            }
        }
        putc('\n',outputfile);
    }
    /*
    while(fgets(f1,MAXNUM,inputfile) != NULL)
    {
        len = strlen(f1);
        f1[len - 1] = '\0';
        printf("%s\n",f1);
        
        for(int i = len;i >= 0;i --){
            buf = f1[len];
            fprintf(outputfile,"%s\n",buf);
        }
        
    }
    */
    
    fclose(inputfile);
    fclose(outputfile);
    
    printf("Finish.\n");
    
    return 0;
}
