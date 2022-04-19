/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "encoderLib.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

int findSign(char bin[33]){                                //function to find sign
    if(bin[0] == '1'){                                     //if first bit is 1 return 1
        return 1;
    }
    else{                                                 //else return 0
        return 0;
    }
}

int findExponent(char bin[33]){                           //function to find exponent
    int exponent = 0;
    char temp[9];
    int j = 0;
    for(int i = 1; i <= 8; i++){                          //cut string to get 8 bits needed for exponent
        temp[j] = bin[i];
        j++;
    }
    j = 0;                                                //sets j to 0 for use of power
    temp[8] = '\0';                                       //adds null terminator to end to temp string
    
    for(int i = 7; i >= 0; i--){                          //convert temp to decimal
       if (temp[i] == '1'){
           exponent = exponent + pow(2,j);
           j = j + 1;
       }
       else{
           j = j + 1;
       }
    }
    return exponent;                                    //return exponent
}

double findFraction(char bin[33]){                      //function to find fraction
    double fraction = 0.0;
    char temp[25];
    int j = 0;
    for(int i = 9; i <= 32; i++){                       //cuts bin string to temp to needed bits for fraction
        temp[j] = bin[i];
        j++;
    }
    j = -1;                                             //sets j to -1 for negative power
    temp[24] = '\0';                                   //adds null terminator to end of string
    
    for(int i = 0; i <= 23; i++){                      //converts temp to decimal
       if (temp[i] == '1'){
           fraction = fraction + pow(2,j);
           j = j - 1;
       }
       else{
           j = j - 1;
       }
    }
    return fraction;                                  //return fraction
}

double findFloat(char bin[33]){                      //function to find floating point number
    double Number = 0.0;
    Number = pow((-1), findSign(&bin[0])) * (1 + findFraction(bin)) * pow(2,(findExponent(bin) -127));          //eq for float point number
    return Number;                                    //return number
}