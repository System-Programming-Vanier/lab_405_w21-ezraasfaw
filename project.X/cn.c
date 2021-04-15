//#include <cn.h>
#include <xc.h>
#include <sys/attribs.h>

/* Initializes the CN interrupt for CN15 pins */
void initCN15(){
    __builtin_disable_interrupts();   // disable all interrupts
    CNENbits.CNEN15 = 1; // Enable CN15 pins
    CNCONbits.ON= 1; // turn on Change Notification
    IPC6bits.CNIP=1; //Chooses  priority 1   
    IFS1bits.CNIF=0; //Clears the interrupt flag     
    INTCONbits.MVEC=1;  // enable multi-vector mode
    IEC1bits.CNIE=1; //enables the Change Notification general int 
    __builtin_enable_interrupts();   // enable all interrupts}
}
void __ISR(_CHANGE_NOTICE_VECTOR, IPL1SOFT) CNInterrupt( void){ 
    
//IFS1bits.CNIF = 0; //Clear the CN flag// Do something

LATAbits.LATA3 = LATAbits.LATA3 ^ 1; // //toggles through
}