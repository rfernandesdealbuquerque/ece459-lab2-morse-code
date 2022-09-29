/*
 * File:   main.c
 * Author: rodri
 *
 * Created on September 29, 2022, 12:43 PM
 */


#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <htc.h>

#include <pic.h>

#define _XTAL_FREQ 4000000

// PIC16F883 Configuration Bit Settings

 

// 'C' source line config statements

 

// CONFIG1

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)

#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)

#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)

#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)

#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)

#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)

#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

 

// CONFIG2

#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)

#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

 

// #pragma config statements should precede project file includes.

// Use project enums instead of #define for ON and OFF.

 

void display_symbol(char sequenceReceived[]){

    unsigned char ZERO = 0b01110111;
    unsigned char ONE = 0b01000001;
    unsigned char TWO = 0b00111011;
    unsigned char THREE = 0b01101011;
    unsigned char FOUR = 0b01001101;
    unsigned char FIVE = 0b01101110;
    unsigned char SIX = 0b01111110;
    unsigned char SEVEN = 0b01000011;
    unsigned char EIGHT = 0b01111111;
    unsigned char NINE = 0b01001111;
    unsigned char A = 0b01011111;
    unsigned char b = 0b01111100;
    unsigned char C = 0b00110110;
    unsigned char d = 0b01111001;
    unsigned char E = 0b00111110;
    unsigned char F = 0b00011110;
    
    char ZERO_morse[] = "- - - - -";
    char ONE_morse[] = ". - - - -";
    char TWO_morse[] = ". . - - -";
    char THREE_morse[] = ". . . - -";
    char FOUR_morse[] = ". . . . -";
    char FIVE_morse[] = ". . . . .";
    char SIX_morse[] = "- . . . .";
    char SEVEN_morse[] = "- - . . .";
    char EIGHT_morse[] = "- - - . .";
    char NINE_morse[] = "- - - - .";
    char A_morse[] = ". -";
    char b_morse[] = "- . . .";
    char C_morse[] = "- . - .";
    char d_morse[] = "- . .";
    char E_morse[] = ".";
    char F_morse[] = ". . - .";
    
    if(!strcmp(sequenceReceived, ZERO_morse)){
        PORTA = 0b00000001;
        PORTC = ZERO; 
    }
    
    else if(!strcmp(sequenceReceived, ONE_morse)){
        PORTA = 0b00000001;
        PORTC = ONE;
    }
    
    else if(!strcmp(sequenceReceived, TWO_morse)){
        PORTA = 0b00000001;
        PORTC = TWO;
    }
    
    else if(!strcmp(sequenceReceived, THREE_morse)){
        PORTA = 0b00000001;
        PORTC = THREE;
    }
    
    else if(!strcmp(sequenceReceived, FOUR_morse)){
        PORTA = 0b00000001;
        PORTC = FOUR;
    }
    
    else if(!strcmp(sequenceReceived, FIVE_morse)){
        PORTA = 0b00000001;
        PORTC = FIVE;
    }
    
    else if(!strcmp(sequenceReceived, SIX_morse)){
        PORTA = 0b00000001;
        PORTC = SIX;
    }
    
    else if(!strcmp(sequenceReceived, SEVEN_morse)){
        PORTA = 0b00000001;
        PORTC = SEVEN;
    }
    
    else if(!strcmp(sequenceReceived, EIGHT_morse)){
        PORTA = 0b00000001;
        PORTC = EIGHT;
    }
    
    else if(!strcmp(sequenceReceived, NINE_morse)){
        PORTA = 0b00000001;
        PORTC = NINE;
    }
    
    else if(!strcmp(sequenceReceived, A_morse)){
        PORTA = 0b00000001;
        PORTC = A;
    }
    else if(!strcmp(sequenceReceived, b_morse)){
        PORTA = 0b00000001;
        PORTC = b;
    }
    else if(!strcmp(sequenceReceived, C_morse)){
        PORTA = 0b00000001;
        PORTC = C;
    }
    else if(!strcmp(sequenceReceived, d_morse)){
        PORTA = 0b00000001;
        PORTC = d;
    }
    else if(!strcmp(sequenceReceived, E_morse)){
        PORTA = 0b00000001;
        PORTC = E;
    }
    else if(!strcmp(sequenceReceived, F_morse)){
        PORTA = 0b00000001;
        PORTC = F;
    }
     
}

 void initializeTimer(){

    TMRICS = 0; // 4MHz/4 = 1 MHz

    TMRIGE = 0;

    TICKPS = 0x11;

    TMRIIE = 0;

    TMRION = 0;

    

    time_value = (TMRIH << 8) | TMRIL;

   

 

}

 

 

int main(void) {

   

TRISA = 0x00; //op

TRISB = 0x03; //op

TRISC = 0x00;

ANSEL = 0x00;

ANSELH = 0x00;

 

INTCONbits.GIE = 1;

INTCONbits.RBIE = 1;

IOCB = 0x03;

initializeTimer();

//enable timer ?

      

while(1){

   

    display_symbol()

 

}

}

 

void __interrupt() isr(void){

    if(INTCONbits.RBIF == 1){

       

       if(PORTBbits.RB0 == 1){

          

       }

       else if(PORTBbits.RB1 == 1){

 

       }

      

    INTCONbits.RBIF = 0; // reset the external interrupt flag

    }

 

}

