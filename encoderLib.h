/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   encoderLib.h
 * Author: loganmead
 *
 * Created on February 18, 2021, 6:17 PM
 */

#ifndef ENCODERLIB_H
#define ENCODERLIB_H

#ifdef __cplusplus
extern "C" {
#endif
//header for functions
int findSign(char bin[33]);                     
int findExponent(char bin[33]);
double findFraction(char bin[33]);
double findFloat(char bin[33]);

#ifdef __cplusplus
}
#endif

#endif /* ENCODERLIB_H */

