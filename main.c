/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: loganmead
 *
 * Created on February 13, 2021, 4:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "encoderLib.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char bin[32];
    if (strcmp(argv[1], "-v") != 0){
        perror("ERROR incorrect Argument");
    }
    else if(argc > 2){                                               //error checking if too many arguments
        perror("ERROR: Too many Arguments!");
    }
    else{
        while(!feof(stdin)){                                        //runs until end of file
            int n = fscanf(stdin,"%s", &bin);                       //int of number of times ran
            if (n > 0){
                int sign = 0;        
                int exponent = 0;
                double fraction = 0.0;
                double Number = 0.0;
                
                if(strcmp(argv[1], "-v") == 0 ){                    //runs if user enters -v 
                    fprintf(stdout, "%s \n", &bin);                 //prints whats in binary.txt and the conversion
                    Number = findFloat(bin);
                    fprintf(stdout,"%lf \n", Number);   
                }
                else{                                               //runs if user does not put -v
                    Number = findFloat(bin);                        //just prints conversion
                    fprintf(stdout,"%lf \n", Number);
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}

