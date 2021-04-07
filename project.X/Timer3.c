/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#include <xc.h>
#include <sys/attribs.h>

void initT3(void){
    
T3CONbits.ON = 0; // turn off Timer3
T3CONbits.TGATE = 0; // not gated input (the default)
T3CONbits.TCS = 0; // PCBLK input (the default)
T3CONbits.TCKPS = 0b000; // set prescaler 1:1
TMR3 = 0x00; // Clear timer register
PR3 = 100-1; // Load the period value
INTCONbits.MVEC=1; //SystemMultiVectored
__builtin_disable_interrupts();   // disable interrupts
IPC3bits.T3IP=1;  
IFS0bits.T3IF=0;  
IEC0bits.T3IE=1;
__builtin_enable_interrupts();   // enable interrupts
T3CONbits.ON = 1; // turn on Timer3
}

void __ISR( _TIMER_3_VECTOR, IPL1SOFT) T3InterruptHandler(void) {

    //Interrupt service routine//
    IFS0bits.T3IF=0;
    LATAbits.LATA7 ^=1;

}