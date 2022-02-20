/*
 * File:   newmain.c
 * Author: thepo
 *
 * Created on 20 Ocak 2022 Per?embe, 20:23
 */

#define _XTAL_FREQ 16000000
#include <xc.h>
#include<stdlib.h>
#include<stdio.h>
#include"LCD.h"
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON   



#define st1 RC2
#define st2 RC1
#define st3 RC0

int tus,sayi[11]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F,0x00};
char a1[]={" KAMIL DIMILILER"};
char b1[]={"507 140 4735"};
char a2[]={" ALI HAYDAR"};
char b2[]={"557 158 4556"};
char a3[]={" IBRAHIM ERSAN"};
char b3[]={"533 580 8964"};
char a4[]={"HATICE AKTORE "};
char b4[]={"523 124 6545"};
char a5[]={" KEZBAN OZLUTAS"};
char b5[]={"568 248 5674"};
char a6[]={" SARA KANDULU"};
char b6[]={"567 770 5755"};
char a7[]={" SALAHI PEHLIVAN"};
char b7[]={"578 160 8335"};
char a8[]={" BUGCE EMINAGA"};
char b8[]={"597 340 6335"};
char a9[]={" WALEED FADEL"};
char b9[]={"586 853 2793"};



void enable(void)
{
    RA2=0;
    __delay_ms(2);
    RA2=1;
    __delay_ms(5);
    RA2=0;
}
char keypad(void)
{
   char ky=255,kk[3]={1,2,4};
   for(char k=0;k<3;k++)
   {
      PORTE=kk[k];
      
      if(RC0==1)
      {
         
         if(k==0) ky=1;
            else if(k==1) ky=2;
               else if(k==2) ky=3;
         }
         else if(RC1==1)
         {

            if(k==0) ky=4;
               else if(k==1) ky=5;
                  else if(k==2) ky=6;
            }
            else if(RC2==1)
            {
   
               if(k==0) ky=7;
                  else if(k==1) ky=8;
                     else if(k==2) ky=9;
                        
               }
               else if(RC3==1)
               {

                  if(k==0) ky=20;
                     else if(k==1) ky=0;
                        else if(k==2) ky=20;
                  }

   }
   if(ky==255) __delay_ms(5); else __delay_ms(400);
   return(ky);
   
}

void main(void) {
    char a=255;
    char n;
    ADCON1=6;
    TRISA=0;
    TRISD=0;
    TRISC=0x0F;
    TRISB=0;
    TRISE=0;
    PORTB=0;
    
    
     
    /*lcd_hazirla();
    lcd_yaz(a4);
    lcd_gotoxy(2,1);
    lcd_yaz(b1);
    __delay_ms(1000);*/
    int c;

  
    
    while(1){
        
        a=keypad();
       
        if(a!=255){
             
            if(a==1){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a1);
                lcd_gotoxy(2,1);
                lcd_yaz(b1);
                    for(int i=0;i<12;i++){
                         if(b1[i]!=' '){
                             c=b1[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
            }
             else if(a==2){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a2);
                lcd_gotoxy(2,1);
                lcd_yaz(b2);
                for(int i=0;i<12;i++){
                         if(b2[i]!=' '){
                             c=b2[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             } 
            
            else if(a==3){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a3);
                lcd_gotoxy(2,1);
                lcd_yaz(b3);
                for(int i=0;i<12;i++){
                         if(b3[i]!=' '){
                             c=b3[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
            else if(a==4){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a4);
                lcd_gotoxy(2,1);
                lcd_yaz(b4);
                for(int i=0;i<12;i++){
                         if(b4[i]!=' '){
                             c=b4[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
            else if(a==5){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a5);
                lcd_gotoxy(2,1);
                lcd_yaz(b5);
                for(int i=0;i<12;i++){
                         if(b5[i]!=' '){
                             c=b5[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
            else if(a==6){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a6);
                lcd_gotoxy(2,1);
                lcd_yaz(b6);
                for(int i=0;i<12;i++){
                         if(b6[i]!=' '){
                             c=b6[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
            else if(a==7){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a7);
                lcd_gotoxy(2,1);
                lcd_yaz(b7);
                for(int i=0;i<12;i++){
                         if(b7[i]!=' '){
                             c=b7[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
            else if(a==8){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a8);
                lcd_gotoxy(2,1);
                lcd_yaz(b8);
                for(int i=0;i<12;i++){
                         if(b8[i]!=' '){
                             c=b8[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
             else if(a==9){
                PORTB=sayi[a];
                lcd_hazirla();
                lcd_yaz(a9);
                lcd_gotoxy(2,1);
                lcd_yaz(b9);
                for(int i=0;i<12;i++){
                         if(b9[i]!=' '){
                             c=b9[i];
                              PORTB=sayi[c-48];
                            __delay_ms(3000);
                              }
                        }
                lcd_hazirla();
                PORTB=0;
             }
             
        
         
         
        }  
    } 
        
      
       
    }    
    
    
    
 
   

