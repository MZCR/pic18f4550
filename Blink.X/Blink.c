#pragma config PLLDIV = 2       // PLL Prescaler Selection bits (Divide by 2 (8 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = EC_EC     // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))

#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)

#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)

#define _XTAL_FREQ 4000000
#include <xc.h>

void main(void) {
    
    ADCON1bits.PCFG0 = 0x0F;
    
    TRISB = 0x00;
   // TRISBbits.TRISB1 = 0;
    //TRISBbits.RB2 = 0b00000000;
    
    LATB = 0x00;
    
    while(1)
    {     
        LATBbits.LATB7 = 1;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 1;
        
        __delay_ms(500);
        
        LATBbits.LATB7 = 0;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 0;
        
        __delay_ms(500);
    }
}
