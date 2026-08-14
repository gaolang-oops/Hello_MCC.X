;==========================================================================
;  PIC33EP128MC506 Standard Assembly Include File
; 
;  (c) Copyright 2023 Microchip Technology, All rights reserved
;  Part support version 2.10.A(27-Mar-2023)
; 
 ; This software is developed by Microchip Technology Inc. and its
 ; subsidiaries ("Microchip").
 ; 
 ; Redistribution and use in source and binary forms, with or without
 ; modification, are permitted provided that the following conditions are 
 ; met:
 ; 
 ; 1.      Redistributions of source code must retain the above copyright
 ;         notice, this list of conditions and the following disclaimer.
 ; 2.      Redistributions in binary form must reproduce the above 
 ;         copyright notice, this list of conditions and the following 
 ;         disclaimer in the documentation and/or other materials provided 
 ;         with the distribution. Publication is not required when
 ;         this file is used in an embedded application.
 ; 3.      Microchip's name may not be used to endorse or promote products
 ;         derived from this software without specific prior written 
 ;         permission.
 ; 
 ; THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 ; WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 ; MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 ; SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 ; EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 ; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 ; OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 ; WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 ; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ; ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ; 
 ;

.ifndef __33EP128MC506_INC
.equ __33EP128MC506_INC,1
.NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC33EP128MC506 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\> pic30-as file.s -p33EP128MC506
;       2. Placing a ".equ" directive before the ".include":
;               .equ __33EP128MC506, 1
;               .include "p33EP128MC506.inc"
;       3. Setting the processor in the MPLAB IDE Project Dialog
;==========================================================================

;==========================================================================
;
;       Verify Processor
;
;==========================================================================

.IFNDEF __33EP128MC506
   .ERROR "Include file does not match processor setting."
.ENDIF


;==========================================================================
;
;       Register Definitions
;
;==========================================================================

;----- Register Equates (Low Byte, High Byte) -----------------------------

        .extern WREG0
        .equiv  WREG0L, _WREG0
        .equiv  WREG0H, _WREG0+1

        .extern WREG1
        .equiv  WREG1L, _WREG1
        .equiv  WREG1H, _WREG1+1

        .extern WREG2
        .equiv  WREG2L, _WREG2
        .equiv  WREG2H, _WREG2+1

        .extern WREG3
        .equiv  WREG3L, _WREG3
        .equiv  WREG3H, _WREG3+1

        .extern WREG4
        .equiv  WREG4L, _WREG4
        .equiv  WREG4H, _WREG4+1

        .extern WREG5
        .equiv  WREG5L, _WREG5
        .equiv  WREG5H, _WREG5+1

        .extern WREG6
        .equiv  WREG6L, _WREG6
        .equiv  WREG6H, _WREG6+1

        .extern WREG7
        .equiv  WREG7L, _WREG7
        .equiv  WREG7H, _WREG7+1

        .extern WREG8
        .equiv  WREG8L, _WREG8
        .equiv  WREG8H, _WREG8+1

        .extern WREG9
        .equiv  WREG9L, _WREG9
        .equiv  WREG9H, _WREG9+1

        .extern WREG10
        .equiv  WREG10L, _WREG10
        .equiv  WREG10H, _WREG10+1

        .extern WREG11
        .equiv  WREG11L, _WREG11
        .equiv  WREG11H, _WREG11+1

        .extern WREG12
        .equiv  WREG12L, _WREG12
        .equiv  WREG12H, _WREG12+1

        .extern WREG13
        .equiv  WREG13L, _WREG13
        .equiv  WREG13H, _WREG13+1

        .extern WREG14
        .equiv  WREG14L, _WREG14
        .equiv  WREG14H, _WREG14+1

        .extern WREG15
        .equiv  WREG15L, _WREG15
        .equiv  WREG15H, _WREG15+1

        .extern SPLIM
        .equiv  SPLIML, _SPLIM
        .equiv  SPLIMH, _SPLIM+1

        .extern ACCAL
        .equiv  ACCALL, _ACCAL
        .equiv  ACCALH, _ACCAL+1

        .extern ACCAH
        .equiv  ACCAHL, _ACCAH
        .equiv  ACCAHH, _ACCAH+1

        .extern ACCAU
        .equiv  ACCAUL, _ACCAU
        .equiv  ACCAUH, _ACCAU+1

        .extern ACCBL
        .equiv  ACCBLL, _ACCBL
        .equiv  ACCBLH, _ACCBL+1

        .extern ACCBH
        .equiv  ACCBHL, _ACCBH
        .equiv  ACCBHH, _ACCBH+1

        .extern ACCBU
        .equiv  ACCBUL, _ACCBU
        .equiv  ACCBUH, _ACCBU+1

        .extern PCL
        .equiv  PCLL, _PCL
        .equiv  PCLH, _PCL+1

        .extern PCH
        .equiv  PCHL, _PCH
        .equiv  PCHH, _PCH+1

        .extern DSRPAG
        .equiv  DSRPAGL, _DSRPAG
        .equiv  DSRPAGH, _DSRPAG+1

        .extern DSWPAG
        .equiv  DSWPAGL, _DSWPAG
        .equiv  DSWPAGH, _DSWPAG+1

        .extern RCOUNT
        .equiv  RCOUNTL, _RCOUNT
        .equiv  RCOUNTH, _RCOUNT+1

        .extern DCOUNT
        .equiv  DCOUNTL, _DCOUNT
        .equiv  DCOUNTH, _DCOUNT+1

        .extern DOSTARTL
        .equiv  DOSTARTLL, _DOSTARTL
        .equiv  DOSTARTLH, _DOSTARTL+1

        .extern DOSTARTH
        .equiv  DOSTARTHL, _DOSTARTH
        .equiv  DOSTARTHH, _DOSTARTH+1

        .extern DOENDL
        .equiv  DOENDLL, _DOENDL
        .equiv  DOENDLH, _DOENDL+1

        .extern DOENDH
        .equiv  DOENDHL, _DOENDH
        .equiv  DOENDHH, _DOENDH+1

        .extern SR
        .equiv  SRL, _SR
        .equiv  SRH, _SR+1

        .extern CORCON
        .equiv  CORCONL, _CORCON
        .equiv  CORCONH, _CORCON+1

        .extern MODCON
        .equiv  MODCONL, _MODCON
        .equiv  MODCONH, _MODCON+1

        .extern XMODSRT
        .equiv  XMODSRTL, _XMODSRT
        .equiv  XMODSRTH, _XMODSRT+1

        .extern XMODEND
        .equiv  XMODENDL, _XMODEND
        .equiv  XMODENDH, _XMODEND+1

        .extern YMODSRT
        .equiv  YMODSRTL, _YMODSRT
        .equiv  YMODSRTH, _YMODSRT+1

        .extern YMODEND
        .equiv  YMODENDL, _YMODEND
        .equiv  YMODENDH, _YMODEND+1

        .extern XBREV
        .equiv  XBREVL, _XBREV
        .equiv  XBREVH, _XBREV+1

        .extern DISICNT
        .equiv  DISICNTL, _DISICNT
        .equiv  DISICNTH, _DISICNT+1

        .extern TBLPAG
        .equiv  TBLPAGL, _TBLPAG
        .equiv  TBLPAGH, _TBLPAG+1

        .extern MSTRPR
        .equiv  MSTRPRL, _MSTRPR
        .equiv  MSTRPRH, _MSTRPR+1

        .extern TMR1
        .equiv  TMR1L, _TMR1
        .equiv  TMR1H, _TMR1+1

        .extern PR1
        .equiv  PR1L, _PR1
        .equiv  PR1H, _PR1+1

        .extern T1CON
        .equiv  T1CONL, _T1CON
        .equiv  T1CONH, _T1CON+1

        .extern TMR2
        .equiv  TMR2L, _TMR2
        .equiv  TMR2H, _TMR2+1

        .extern TMR3HLD
        .equiv  TMR3HLDL, _TMR3HLD
        .equiv  TMR3HLDH, _TMR3HLD+1

        .extern TMR3
        .equiv  TMR3L, _TMR3
        .equiv  TMR3H, _TMR3+1

        .extern PR2
        .equiv  PR2L, _PR2
        .equiv  PR2H, _PR2+1

        .extern PR3
        .equiv  PR3L, _PR3
        .equiv  PR3H, _PR3+1

        .extern T2CON
        .equiv  T2CONL, _T2CON
        .equiv  T2CONH, _T2CON+1

        .extern T3CON
        .equiv  T3CONL, _T3CON
        .equiv  T3CONH, _T3CON+1

        .extern TMR4
        .equiv  TMR4L, _TMR4
        .equiv  TMR4H, _TMR4+1

        .extern TMR5HLD
        .equiv  TMR5HLDL, _TMR5HLD
        .equiv  TMR5HLDH, _TMR5HLD+1

        .extern TMR5
        .equiv  TMR5L, _TMR5
        .equiv  TMR5H, _TMR5+1

        .extern PR4
        .equiv  PR4L, _PR4
        .equiv  PR4H, _PR4+1

        .extern PR5
        .equiv  PR5L, _PR5
        .equiv  PR5H, _PR5+1

        .extern T4CON
        .equiv  T4CONL, _T4CON
        .equiv  T4CONH, _T4CON+1

        .extern T5CON
        .equiv  T5CONL, _T5CON
        .equiv  T5CONH, _T5CON+1

        .extern IC1CON1
        .equiv  IC1CON1L, _IC1CON1
        .equiv  IC1CON1H, _IC1CON1+1

        .extern IC1CON2
        .equiv  IC1CON2L, _IC1CON2
        .equiv  IC1CON2H, _IC1CON2+1

        .extern IC1BUF
        .equiv  IC1BUFL, _IC1BUF
        .equiv  IC1BUFH, _IC1BUF+1

        .extern IC1TMR
        .equiv  IC1TMRL, _IC1TMR
        .equiv  IC1TMRH, _IC1TMR+1

        .extern IC2CON1
        .equiv  IC2CON1L, _IC2CON1
        .equiv  IC2CON1H, _IC2CON1+1

        .extern IC2CON2
        .equiv  IC2CON2L, _IC2CON2
        .equiv  IC2CON2H, _IC2CON2+1

        .extern IC2BUF
        .equiv  IC2BUFL, _IC2BUF
        .equiv  IC2BUFH, _IC2BUF+1

        .extern IC2TMR
        .equiv  IC2TMRL, _IC2TMR
        .equiv  IC2TMRH, _IC2TMR+1

        .extern IC3CON1
        .equiv  IC3CON1L, _IC3CON1
        .equiv  IC3CON1H, _IC3CON1+1

        .extern IC3CON2
        .equiv  IC3CON2L, _IC3CON2
        .equiv  IC3CON2H, _IC3CON2+1

        .extern IC3BUF
        .equiv  IC3BUFL, _IC3BUF
        .equiv  IC3BUFH, _IC3BUF+1

        .extern IC3TMR
        .equiv  IC3TMRL, _IC3TMR
        .equiv  IC3TMRH, _IC3TMR+1

        .extern IC4CON1
        .equiv  IC4CON1L, _IC4CON1
        .equiv  IC4CON1H, _IC4CON1+1

        .extern IC4CON2
        .equiv  IC4CON2L, _IC4CON2
        .equiv  IC4CON2H, _IC4CON2+1

        .extern IC4BUF
        .equiv  IC4BUFL, _IC4BUF
        .equiv  IC4BUFH, _IC4BUF+1

        .extern IC4TMR
        .equiv  IC4TMRL, _IC4TMR
        .equiv  IC4TMRH, _IC4TMR+1

        .extern QEI1CON
        .equiv  QEI1CONL, _QEI1CON
        .equiv  QEI1CONH, _QEI1CON+1

        .extern QEI1IOC
        .equiv  QEI1IOCL, _QEI1IOC
        .equiv  QEI1IOCH, _QEI1IOC+1

        .extern QEI1STAT
        .equiv  QEI1STATL, _QEI1STAT
        .equiv  QEI1STATH, _QEI1STAT+1

        .extern POS1CNTL
        .equiv  POS1CNTLL, _POS1CNTL
        .equiv  POS1CNTLH, _POS1CNTL+1

        .extern POS1CNTH
        .equiv  POS1CNTHL, _POS1CNTH
        .equiv  POS1CNTHH, _POS1CNTH+1

        .extern POS1HLD
        .equiv  POS1HLDL, _POS1HLD
        .equiv  POS1HLDH, _POS1HLD+1

        .extern VEL1CNT
        .equiv  VEL1CNTL, _VEL1CNT
        .equiv  VEL1CNTH, _VEL1CNT+1

        .extern INT1TMRL
        .equiv  INT1TMRLL, _INT1TMRL
        .equiv  INT1TMRLH, _INT1TMRL+1

        .extern INT1TMRH
        .equiv  INT1TMRHL, _INT1TMRH
        .equiv  INT1TMRHH, _INT1TMRH+1

        .extern INT1HLDL
        .equiv  INT1HLDLL, _INT1HLDL
        .equiv  INT1HLDLH, _INT1HLDL+1

        .extern INT1HLDH
        .equiv  INT1HLDHL, _INT1HLDH
        .equiv  INT1HLDHH, _INT1HLDH+1

        .extern INDX1CNTL
        .equiv  INDX1CNTLL, _INDX1CNTL
        .equiv  INDX1CNTLH, _INDX1CNTL+1

        .extern INDX1CNTH
        .equiv  INDX1CNTHL, _INDX1CNTH
        .equiv  INDX1CNTHH, _INDX1CNTH+1

        .extern INDX1HLD
        .equiv  INDX1HLDL, _INDX1HLD
        .equiv  INDX1HLDH, _INDX1HLD+1

        .extern QEI1GECL
        .equiv  QEI1GECLL, _QEI1GECL
        .equiv  QEI1GECLH, _QEI1GECL+1

        .extern QEI1ICL
        .equiv  QEI1ICLL, _QEI1ICL
        .equiv  QEI1ICLH, _QEI1ICL+1

        .extern QEI1GECH
        .equiv  QEI1GECHL, _QEI1GECH
        .equiv  QEI1GECHH, _QEI1GECH+1

        .extern QEI1ICH
        .equiv  QEI1ICHL, _QEI1ICH
        .equiv  QEI1ICHH, _QEI1ICH+1

        .extern QEI1LECL
        .equiv  QEI1LECLL, _QEI1LECL
        .equiv  QEI1LECLH, _QEI1LECL+1

        .extern QEI1LECH
        .equiv  QEI1LECHL, _QEI1LECH
        .equiv  QEI1LECHH, _QEI1LECH+1

        .extern I2C1RCV
        .equiv  I2C1RCVL, _I2C1RCV
        .equiv  I2C1RCVH, _I2C1RCV+1

        .extern I2C1TRN
        .equiv  I2C1TRNL, _I2C1TRN
        .equiv  I2C1TRNH, _I2C1TRN+1

        .extern I2C1BRG
        .equiv  I2C1BRGL, _I2C1BRG
        .equiv  I2C1BRGH, _I2C1BRG+1

        .extern I2C1CON
        .equiv  I2C1CONL, _I2C1CON
        .equiv  I2C1CONH, _I2C1CON+1

        .extern I2C1STAT
        .equiv  I2C1STATL, _I2C1STAT
        .equiv  I2C1STATH, _I2C1STAT+1

        .extern I2C1ADD
        .equiv  I2C1ADDL, _I2C1ADD
        .equiv  I2C1ADDH, _I2C1ADD+1

        .extern I2C1MSK
        .equiv  I2C1MSKL, _I2C1MSK
        .equiv  I2C1MSKH, _I2C1MSK+1

        .extern I2C2RCV
        .equiv  I2C2RCVL, _I2C2RCV
        .equiv  I2C2RCVH, _I2C2RCV+1

        .extern I2C2TRN
        .equiv  I2C2TRNL, _I2C2TRN
        .equiv  I2C2TRNH, _I2C2TRN+1

        .extern I2C2BRG
        .equiv  I2C2BRGL, _I2C2BRG
        .equiv  I2C2BRGH, _I2C2BRG+1

        .extern I2C2CON
        .equiv  I2C2CONL, _I2C2CON
        .equiv  I2C2CONH, _I2C2CON+1

        .extern I2C2STAT
        .equiv  I2C2STATL, _I2C2STAT
        .equiv  I2C2STATH, _I2C2STAT+1

        .extern I2C2ADD
        .equiv  I2C2ADDL, _I2C2ADD
        .equiv  I2C2ADDH, _I2C2ADD+1

        .extern I2C2MSK
        .equiv  I2C2MSKL, _I2C2MSK
        .equiv  I2C2MSKH, _I2C2MSK+1

        .extern U1MODE
        .equiv  U1MODEL, _U1MODE
        .equiv  U1MODEH, _U1MODE+1

        .extern U1STA
        .equiv  U1STAL, _U1STA
        .equiv  U1STAH, _U1STA+1

        .extern U1TXREG
        .equiv  U1TXREGL, _U1TXREG
        .equiv  U1TXREGH, _U1TXREG+1

        .extern U1RXREG
        .equiv  U1RXREGL, _U1RXREG
        .equiv  U1RXREGH, _U1RXREG+1

        .extern U1BRG
        .equiv  U1BRGL, _U1BRG
        .equiv  U1BRGH, _U1BRG+1

        .extern U2MODE
        .equiv  U2MODEL, _U2MODE
        .equiv  U2MODEH, _U2MODE+1

        .extern U2STA
        .equiv  U2STAL, _U2STA
        .equiv  U2STAH, _U2STA+1

        .extern U2TXREG
        .equiv  U2TXREGL, _U2TXREG
        .equiv  U2TXREGH, _U2TXREG+1

        .extern U2RXREG
        .equiv  U2RXREGL, _U2RXREG
        .equiv  U2RXREGH, _U2RXREG+1

        .extern U2BRG
        .equiv  U2BRGL, _U2BRG
        .equiv  U2BRGH, _U2BRG+1

        .extern SPI1STAT
        .equiv  SPI1STATL, _SPI1STAT
        .equiv  SPI1STATH, _SPI1STAT+1

        .extern SPI1CON1
        .equiv  SPI1CON1L, _SPI1CON1
        .equiv  SPI1CON1H, _SPI1CON1+1

        .extern SPI1CON2
        .equiv  SPI1CON2L, _SPI1CON2
        .equiv  SPI1CON2H, _SPI1CON2+1

        .extern SPI1BUF
        .equiv  SPI1BUFL, _SPI1BUF
        .equiv  SPI1BUFH, _SPI1BUF+1

        .extern SPI2STAT
        .equiv  SPI2STATL, _SPI2STAT
        .equiv  SPI2STATH, _SPI2STAT+1

        .extern SPI2CON1
        .equiv  SPI2CON1L, _SPI2CON1
        .equiv  SPI2CON1H, _SPI2CON1+1

        .extern SPI2CON2
        .equiv  SPI2CON2L, _SPI2CON2
        .equiv  SPI2CON2H, _SPI2CON2+1

        .extern SPI2BUF
        .equiv  SPI2BUFL, _SPI2BUF
        .equiv  SPI2BUFH, _SPI2BUF+1

        .extern ADC1BUF0
        .equiv  ADC1BUF0L, _ADC1BUF0
        .equiv  ADC1BUF0H, _ADC1BUF0+1

        .extern ADC1BUF1
        .equiv  ADC1BUF1L, _ADC1BUF1
        .equiv  ADC1BUF1H, _ADC1BUF1+1

        .extern ADC1BUF2
        .equiv  ADC1BUF2L, _ADC1BUF2
        .equiv  ADC1BUF2H, _ADC1BUF2+1

        .extern ADC1BUF3
        .equiv  ADC1BUF3L, _ADC1BUF3
        .equiv  ADC1BUF3H, _ADC1BUF3+1

        .extern ADC1BUF4
        .equiv  ADC1BUF4L, _ADC1BUF4
        .equiv  ADC1BUF4H, _ADC1BUF4+1

        .extern ADC1BUF5
        .equiv  ADC1BUF5L, _ADC1BUF5
        .equiv  ADC1BUF5H, _ADC1BUF5+1

        .extern ADC1BUF6
        .equiv  ADC1BUF6L, _ADC1BUF6
        .equiv  ADC1BUF6H, _ADC1BUF6+1

        .extern ADC1BUF7
        .equiv  ADC1BUF7L, _ADC1BUF7
        .equiv  ADC1BUF7H, _ADC1BUF7+1

        .extern ADC1BUF8
        .equiv  ADC1BUF8L, _ADC1BUF8
        .equiv  ADC1BUF8H, _ADC1BUF8+1

        .extern ADC1BUF9
        .equiv  ADC1BUF9L, _ADC1BUF9
        .equiv  ADC1BUF9H, _ADC1BUF9+1

        .extern ADC1BUFA
        .equiv  ADC1BUFAL, _ADC1BUFA
        .equiv  ADC1BUFAH, _ADC1BUFA+1

        .extern ADC1BUFB
        .equiv  ADC1BUFBL, _ADC1BUFB
        .equiv  ADC1BUFBH, _ADC1BUFB+1

        .extern ADC1BUFC
        .equiv  ADC1BUFCL, _ADC1BUFC
        .equiv  ADC1BUFCH, _ADC1BUFC+1

        .extern ADC1BUFD
        .equiv  ADC1BUFDL, _ADC1BUFD
        .equiv  ADC1BUFDH, _ADC1BUFD+1

        .extern ADC1BUFE
        .equiv  ADC1BUFEL, _ADC1BUFE
        .equiv  ADC1BUFEH, _ADC1BUFE+1

        .extern ADC1BUFF
        .equiv  ADC1BUFFL, _ADC1BUFF
        .equiv  ADC1BUFFH, _ADC1BUFF+1

        .extern AD1CON1
        .equiv  AD1CON1L, _AD1CON1
        .equiv  AD1CON1H, _AD1CON1+1

        .extern AD1CON2
        .equiv  AD1CON2L, _AD1CON2
        .equiv  AD1CON2H, _AD1CON2+1

        .extern AD1CON3
        .equiv  AD1CON3L, _AD1CON3
        .equiv  AD1CON3H, _AD1CON3+1

        .extern AD1CHS123
        .equiv  AD1CHS123L, _AD1CHS123
        .equiv  AD1CHS123H, _AD1CHS123+1

        .extern AD1CHS0
        .equiv  AD1CHS0L, _AD1CHS0
        .equiv  AD1CHS0H, _AD1CHS0+1

        .extern AD1CSSH
        .equiv  AD1CSSHL, _AD1CSSH
        .equiv  AD1CSSHH, _AD1CSSH+1

        .extern AD1CSSL
        .equiv  AD1CSSLL, _AD1CSSL
        .equiv  AD1CSSLH, _AD1CSSL+1

        .extern AD1CON4
        .equiv  AD1CON4L, _AD1CON4
        .equiv  AD1CON4H, _AD1CON4+1

        .extern CTMUCON1
        .equiv  CTMUCON1L, _CTMUCON1
        .equiv  CTMUCON1H, _CTMUCON1+1

        .extern CTMUCON2
        .equiv  CTMUCON2L, _CTMUCON2
        .equiv  CTMUCON2H, _CTMUCON2+1

        .extern CTMUICON
        .equiv  CTMUICONL, _CTMUICON
        .equiv  CTMUICONH, _CTMUICON+1

        .extern C1CTRL1
        .equiv  C1CTRL1L, _C1CTRL1
        .equiv  C1CTRL1H, _C1CTRL1+1

        .extern C1CTRL2
        .equiv  C1CTRL2L, _C1CTRL2
        .equiv  C1CTRL2H, _C1CTRL2+1

        .extern C1VEC
        .equiv  C1VECL, _C1VEC
        .equiv  C1VECH, _C1VEC+1

        .extern C1FCTRL
        .equiv  C1FCTRLL, _C1FCTRL
        .equiv  C1FCTRLH, _C1FCTRL+1

        .extern C1FIFO
        .equiv  C1FIFOL, _C1FIFO
        .equiv  C1FIFOH, _C1FIFO+1

        .extern C1INTF
        .equiv  C1INTFL, _C1INTF
        .equiv  C1INTFH, _C1INTF+1

        .extern C1INTE
        .equiv  C1INTEL, _C1INTE
        .equiv  C1INTEH, _C1INTE+1

        .extern C1EC
        .equiv  C1ECL, _C1EC
        .equiv  C1ECH, _C1EC+1

        .extern C1RERRCNT
        .equiv  C1RERRCNTL, _C1RERRCNT
        .equiv  C1RERRCNTH, _C1RERRCNT+1

        .extern C1TERRCNT
        .equiv  C1TERRCNTL, _C1TERRCNT
        .equiv  C1TERRCNTH, _C1TERRCNT+1

        .extern C1CFG1
        .equiv  C1CFG1L, _C1CFG1
        .equiv  C1CFG1H, _C1CFG1+1

        .extern C1CFG2
        .equiv  C1CFG2L, _C1CFG2
        .equiv  C1CFG2H, _C1CFG2+1

        .extern C1FEN1
        .equiv  C1FEN1L, _C1FEN1
        .equiv  C1FEN1H, _C1FEN1+1

        .extern C1FMSKSEL1
        .equiv  C1FMSKSEL1L, _C1FMSKSEL1
        .equiv  C1FMSKSEL1H, _C1FMSKSEL1+1

        .extern C1FMSKSEL2
        .equiv  C1FMSKSEL2L, _C1FMSKSEL2
        .equiv  C1FMSKSEL2H, _C1FMSKSEL2+1

        .extern C1BUFPNT1
        .equiv  C1BUFPNT1L, _C1BUFPNT1
        .equiv  C1BUFPNT1H, _C1BUFPNT1+1

        .extern C1RXFUL1
        .equiv  C1RXFUL1L, _C1RXFUL1
        .equiv  C1RXFUL1H, _C1RXFUL1+1

        .extern C1BUFPNT2
        .equiv  C1BUFPNT2L, _C1BUFPNT2
        .equiv  C1BUFPNT2H, _C1BUFPNT2+1

        .extern C1RXFUL2
        .equiv  C1RXFUL2L, _C1RXFUL2
        .equiv  C1RXFUL2H, _C1RXFUL2+1

        .extern C1BUFPNT3
        .equiv  C1BUFPNT3L, _C1BUFPNT3
        .equiv  C1BUFPNT3H, _C1BUFPNT3+1

        .extern C1BUFPNT4
        .equiv  C1BUFPNT4L, _C1BUFPNT4
        .equiv  C1BUFPNT4H, _C1BUFPNT4+1

        .extern C1RXOVF1
        .equiv  C1RXOVF1L, _C1RXOVF1
        .equiv  C1RXOVF1H, _C1RXOVF1+1

        .extern C1RXOVF2
        .equiv  C1RXOVF2L, _C1RXOVF2
        .equiv  C1RXOVF2H, _C1RXOVF2+1

        .extern C1RXM0SID
        .equiv  C1RXM0SIDL, _C1RXM0SID
        .equiv  C1RXM0SIDH, _C1RXM0SID+1

        .extern C1TR01CON
        .equiv  C1TR01CONL, _C1TR01CON
        .equiv  C1TR01CONH, _C1TR01CON+1

        .extern C1RXM0EID
        .equiv  C1RXM0EIDL, _C1RXM0EID
        .equiv  C1RXM0EIDH, _C1RXM0EID+1

        .extern C1TR23CON
        .equiv  C1TR23CONL, _C1TR23CON
        .equiv  C1TR23CONH, _C1TR23CON+1

        .extern C1RXM1SID
        .equiv  C1RXM1SIDL, _C1RXM1SID
        .equiv  C1RXM1SIDH, _C1RXM1SID+1

        .extern C1TR45CON
        .equiv  C1TR45CONL, _C1TR45CON
        .equiv  C1TR45CONH, _C1TR45CON+1

        .extern C1RXM1EID
        .equiv  C1RXM1EIDL, _C1RXM1EID
        .equiv  C1RXM1EIDH, _C1RXM1EID+1

        .extern C1TR67CON
        .equiv  C1TR67CONL, _C1TR67CON
        .equiv  C1TR67CONH, _C1TR67CON+1

        .extern C1RXM2SID
        .equiv  C1RXM2SIDL, _C1RXM2SID
        .equiv  C1RXM2SIDH, _C1RXM2SID+1

        .extern C1RXM2EID
        .equiv  C1RXM2EIDL, _C1RXM2EID
        .equiv  C1RXM2EIDH, _C1RXM2EID+1

        .extern C1RXD
        .equiv  C1RXDL, _C1RXD
        .equiv  C1RXDH, _C1RXD+1

        .extern C1RXF0SID
        .equiv  C1RXF0SIDL, _C1RXF0SID
        .equiv  C1RXF0SIDH, _C1RXF0SID+1

        .extern C1RXF0EID
        .equiv  C1RXF0EIDL, _C1RXF0EID
        .equiv  C1RXF0EIDH, _C1RXF0EID+1

        .extern C1TXD
        .equiv  C1TXDL, _C1TXD
        .equiv  C1TXDH, _C1TXD+1

        .extern C1RXF1SID
        .equiv  C1RXF1SIDL, _C1RXF1SID
        .equiv  C1RXF1SIDH, _C1RXF1SID+1

        .extern C1RXF1EID
        .equiv  C1RXF1EIDL, _C1RXF1EID
        .equiv  C1RXF1EIDH, _C1RXF1EID+1

        .extern C1RXF2SID
        .equiv  C1RXF2SIDL, _C1RXF2SID
        .equiv  C1RXF2SIDH, _C1RXF2SID+1

        .extern C1RXF2EID
        .equiv  C1RXF2EIDL, _C1RXF2EID
        .equiv  C1RXF2EIDH, _C1RXF2EID+1

        .extern C1RXF3SID
        .equiv  C1RXF3SIDL, _C1RXF3SID
        .equiv  C1RXF3SIDH, _C1RXF3SID+1

        .extern C1RXF3EID
        .equiv  C1RXF3EIDL, _C1RXF3EID
        .equiv  C1RXF3EIDH, _C1RXF3EID+1

        .extern C1RXF4SID
        .equiv  C1RXF4SIDL, _C1RXF4SID
        .equiv  C1RXF4SIDH, _C1RXF4SID+1

        .extern C1RXF4EID
        .equiv  C1RXF4EIDL, _C1RXF4EID
        .equiv  C1RXF4EIDH, _C1RXF4EID+1

        .extern C1RXF5SID
        .equiv  C1RXF5SIDL, _C1RXF5SID
        .equiv  C1RXF5SIDH, _C1RXF5SID+1

        .extern C1RXF5EID
        .equiv  C1RXF5EIDL, _C1RXF5EID
        .equiv  C1RXF5EIDH, _C1RXF5EID+1

        .extern C1RXF6SID
        .equiv  C1RXF6SIDL, _C1RXF6SID
        .equiv  C1RXF6SIDH, _C1RXF6SID+1

        .extern C1RXF6EID
        .equiv  C1RXF6EIDL, _C1RXF6EID
        .equiv  C1RXF6EIDH, _C1RXF6EID+1

        .extern C1RXF7SID
        .equiv  C1RXF7SIDL, _C1RXF7SID
        .equiv  C1RXF7SIDH, _C1RXF7SID+1

        .extern C1RXF7EID
        .equiv  C1RXF7EIDL, _C1RXF7EID
        .equiv  C1RXF7EIDH, _C1RXF7EID+1

        .extern C1RXF8SID
        .equiv  C1RXF8SIDL, _C1RXF8SID
        .equiv  C1RXF8SIDH, _C1RXF8SID+1

        .extern C1RXF8EID
        .equiv  C1RXF8EIDL, _C1RXF8EID
        .equiv  C1RXF8EIDH, _C1RXF8EID+1

        .extern C1RXF9SID
        .equiv  C1RXF9SIDL, _C1RXF9SID
        .equiv  C1RXF9SIDH, _C1RXF9SID+1

        .extern C1RXF9EID
        .equiv  C1RXF9EIDL, _C1RXF9EID
        .equiv  C1RXF9EIDH, _C1RXF9EID+1

        .extern C1RXF10SID
        .equiv  C1RXF10SIDL, _C1RXF10SID
        .equiv  C1RXF10SIDH, _C1RXF10SID+1

        .extern C1RXF10EID
        .equiv  C1RXF10EIDL, _C1RXF10EID
        .equiv  C1RXF10EIDH, _C1RXF10EID+1

        .extern C1RXF11SID
        .equiv  C1RXF11SIDL, _C1RXF11SID
        .equiv  C1RXF11SIDH, _C1RXF11SID+1

        .extern C1RXF11EID
        .equiv  C1RXF11EIDL, _C1RXF11EID
        .equiv  C1RXF11EIDH, _C1RXF11EID+1

        .extern C1RXF12SID
        .equiv  C1RXF12SIDL, _C1RXF12SID
        .equiv  C1RXF12SIDH, _C1RXF12SID+1

        .extern C1RXF12EID
        .equiv  C1RXF12EIDL, _C1RXF12EID
        .equiv  C1RXF12EIDH, _C1RXF12EID+1

        .extern C1RXF13SID
        .equiv  C1RXF13SIDL, _C1RXF13SID
        .equiv  C1RXF13SIDH, _C1RXF13SID+1

        .extern C1RXF13EID
        .equiv  C1RXF13EIDL, _C1RXF13EID
        .equiv  C1RXF13EIDH, _C1RXF13EID+1

        .extern C1RXF14SID
        .equiv  C1RXF14SIDL, _C1RXF14SID
        .equiv  C1RXF14SIDH, _C1RXF14SID+1

        .extern C1RXF14EID
        .equiv  C1RXF14EIDL, _C1RXF14EID
        .equiv  C1RXF14EIDH, _C1RXF14EID+1

        .extern C1RXF15SID
        .equiv  C1RXF15SIDL, _C1RXF15SID
        .equiv  C1RXF15SIDH, _C1RXF15SID+1

        .extern C1RXF15EID
        .equiv  C1RXF15EIDL, _C1RXF15EID
        .equiv  C1RXF15EIDH, _C1RXF15EID+1

        .extern CRCCON1
        .equiv  CRCCON1L, _CRCCON1
        .equiv  CRCCON1H, _CRCCON1+1

        .extern CRCCON2
        .equiv  CRCCON2L, _CRCCON2
        .equiv  CRCCON2H, _CRCCON2+1

        .extern CRCXORL
        .equiv  CRCXORLL, _CRCXORL
        .equiv  CRCXORLH, _CRCXORL+1

        .extern CRCXORH
        .equiv  CRCXORHL, _CRCXORH
        .equiv  CRCXORHH, _CRCXORH+1

        .extern CRCDAT

        .extern CRCDATL
        .equiv  CRCDATLL, _CRCDATL
        .equiv  CRCDATLH, _CRCDATL+1

        .extern CRCDATH
        .equiv  CRCDATHL, _CRCDATH
        .equiv  CRCDATHH, _CRCDATH+1

        .extern CRCWDAT

        .extern CRCWDATL
        .equiv  CRCWDATLL, _CRCWDATL
        .equiv  CRCWDATLH, _CRCWDATL+1

        .extern CRCWDATH
        .equiv  CRCWDATHL, _CRCWDATH
        .equiv  CRCWDATHH, _CRCWDATH+1

        .extern RPOR0
        .equiv  RPOR0L, _RPOR0
        .equiv  RPOR0H, _RPOR0+1

        .extern RPOR1
        .equiv  RPOR1L, _RPOR1
        .equiv  RPOR1H, _RPOR1+1

        .extern RPOR2
        .equiv  RPOR2L, _RPOR2
        .equiv  RPOR2H, _RPOR2+1

        .extern RPOR3
        .equiv  RPOR3L, _RPOR3
        .equiv  RPOR3H, _RPOR3+1

        .extern RPOR4
        .equiv  RPOR4L, _RPOR4
        .equiv  RPOR4H, _RPOR4+1

        .extern RPOR5
        .equiv  RPOR5L, _RPOR5
        .equiv  RPOR5H, _RPOR5+1

        .extern RPOR6
        .equiv  RPOR6L, _RPOR6
        .equiv  RPOR6H, _RPOR6+1

        .extern RPOR7
        .equiv  RPOR7L, _RPOR7
        .equiv  RPOR7H, _RPOR7+1

        .extern RPOR8
        .equiv  RPOR8L, _RPOR8
        .equiv  RPOR8H, _RPOR8+1

        .extern RPOR9
        .equiv  RPOR9L, _RPOR9
        .equiv  RPOR9H, _RPOR9+1

        .extern RPINR0
        .equiv  RPINR0L, _RPINR0
        .equiv  RPINR0H, _RPINR0+1

        .extern RPINR1
        .equiv  RPINR1L, _RPINR1
        .equiv  RPINR1H, _RPINR1+1

        .extern RPINR3
        .equiv  RPINR3L, _RPINR3
        .equiv  RPINR3H, _RPINR3+1

        .extern RPINR7
        .equiv  RPINR7L, _RPINR7
        .equiv  RPINR7H, _RPINR7+1

        .extern RPINR8
        .equiv  RPINR8L, _RPINR8
        .equiv  RPINR8H, _RPINR8+1

        .extern RPINR11
        .equiv  RPINR11L, _RPINR11
        .equiv  RPINR11H, _RPINR11+1

        .extern RPINR12
        .equiv  RPINR12L, _RPINR12
        .equiv  RPINR12H, _RPINR12+1

        .extern RPINR14
        .equiv  RPINR14L, _RPINR14
        .equiv  RPINR14H, _RPINR14+1

        .extern RPINR15
        .equiv  RPINR15L, _RPINR15
        .equiv  RPINR15H, _RPINR15+1

        .extern RPINR18
        .equiv  RPINR18L, _RPINR18
        .equiv  RPINR18H, _RPINR18+1

        .extern RPINR19
        .equiv  RPINR19L, _RPINR19
        .equiv  RPINR19H, _RPINR19+1

        .extern RPINR22
        .equiv  RPINR22L, _RPINR22
        .equiv  RPINR22H, _RPINR22+1

        .extern RPINR23
        .equiv  RPINR23L, _RPINR23
        .equiv  RPINR23H, _RPINR23+1

        .extern RPINR26
        .equiv  RPINR26L, _RPINR26
        .equiv  RPINR26H, _RPINR26+1

        .extern RPINR37
        .equiv  RPINR37L, _RPINR37
        .equiv  RPINR37H, _RPINR37+1

        .extern RPINR38
        .equiv  RPINR38L, _RPINR38
        .equiv  RPINR38H, _RPINR38+1

        .extern RPINR39
        .equiv  RPINR39L, _RPINR39
        .equiv  RPINR39H, _RPINR39+1

        .extern NVMCON
        .equiv  NVMCONL, _NVMCON
        .equiv  NVMCONH, _NVMCON+1

        .extern NVMADR
        .equiv  NVMADRL, _NVMADR
        .equiv  NVMADRH, _NVMADR+1

        .extern NVMADRU
        .equiv  NVMADRUL, _NVMADRU
        .equiv  NVMADRUH, _NVMADRU+1

        .extern NVMKEY
        .equiv  NVMKEYL, _NVMKEY
        .equiv  NVMKEYH, _NVMKEY+1

        .extern RCON
        .equiv  RCONL, _RCON
        .equiv  RCONH, _RCON+1

        .extern OSCCON

        .extern OSCCONL
        .equiv  OSCCONLL, _OSCCONL
        .equiv  OSCCONLH, _OSCCONL+1

        .extern OSCCONH
        .equiv  OSCCONHL, _OSCCONH
        .equiv  OSCCONHH, _OSCCONH+1

        .extern CLKDIV
        .equiv  CLKDIVL, _CLKDIV
        .equiv  CLKDIVH, _CLKDIV+1

        .extern PLLFBD
        .equiv  PLLFBDL, _PLLFBD
        .equiv  PLLFBDH, _PLLFBD+1

        .extern OSCTUN
        .equiv  OSCTUNL, _OSCTUN
        .equiv  OSCTUNH, _OSCTUN+1

        .extern REFOCON
        .equiv  REFOCONL, _REFOCON
        .equiv  REFOCONH, _REFOCON+1

        .extern PMD1
        .equiv  PMD1L, _PMD1
        .equiv  PMD1H, _PMD1+1

        .extern PMD2
        .equiv  PMD2L, _PMD2
        .equiv  PMD2H, _PMD2+1

        .extern PMD3
        .equiv  PMD3L, _PMD3
        .equiv  PMD3H, _PMD3+1

        .extern PMD4
        .equiv  PMD4L, _PMD4
        .equiv  PMD4H, _PMD4+1

        .extern PMD6
        .equiv  PMD6L, _PMD6
        .equiv  PMD6H, _PMD6+1

        .extern PMD7
        .equiv  PMD7L, _PMD7
        .equiv  PMD7H, _PMD7+1

        .extern IFS0
        .equiv  IFS0L, _IFS0
        .equiv  IFS0H, _IFS0+1

        .extern IFS1
        .equiv  IFS1L, _IFS1
        .equiv  IFS1H, _IFS1+1

        .extern IFS2
        .equiv  IFS2L, _IFS2
        .equiv  IFS2H, _IFS2+1

        .extern IFS3
        .equiv  IFS3L, _IFS3
        .equiv  IFS3H, _IFS3+1

        .extern IFS4
        .equiv  IFS4L, _IFS4
        .equiv  IFS4H, _IFS4+1

        .extern IFS5
        .equiv  IFS5L, _IFS5
        .equiv  IFS5H, _IFS5+1

        .extern IFS6
        .equiv  IFS6L, _IFS6
        .equiv  IFS6H, _IFS6+1

        .extern IFS8
        .equiv  IFS8L, _IFS8
        .equiv  IFS8H, _IFS8+1

        .extern IFS9
        .equiv  IFS9L, _IFS9
        .equiv  IFS9H, _IFS9+1

        .extern IEC0
        .equiv  IEC0L, _IEC0
        .equiv  IEC0H, _IEC0+1

        .extern IEC1
        .equiv  IEC1L, _IEC1
        .equiv  IEC1H, _IEC1+1

        .extern IEC2
        .equiv  IEC2L, _IEC2
        .equiv  IEC2H, _IEC2+1

        .extern IEC3
        .equiv  IEC3L, _IEC3
        .equiv  IEC3H, _IEC3+1

        .extern IEC4
        .equiv  IEC4L, _IEC4
        .equiv  IEC4H, _IEC4+1

        .extern IEC5
        .equiv  IEC5L, _IEC5
        .equiv  IEC5H, _IEC5+1

        .extern IEC6
        .equiv  IEC6L, _IEC6
        .equiv  IEC6H, _IEC6+1

        .extern IEC8
        .equiv  IEC8L, _IEC8
        .equiv  IEC8H, _IEC8+1

        .extern IEC9
        .equiv  IEC9L, _IEC9
        .equiv  IEC9H, _IEC9+1

        .extern IPC0
        .equiv  IPC0L, _IPC0
        .equiv  IPC0H, _IPC0+1

        .extern IPC1
        .equiv  IPC1L, _IPC1
        .equiv  IPC1H, _IPC1+1

        .extern IPC2
        .equiv  IPC2L, _IPC2
        .equiv  IPC2H, _IPC2+1

        .extern IPC3
        .equiv  IPC3L, _IPC3
        .equiv  IPC3H, _IPC3+1

        .extern IPC4
        .equiv  IPC4L, _IPC4
        .equiv  IPC4H, _IPC4+1

        .extern IPC5
        .equiv  IPC5L, _IPC5
        .equiv  IPC5H, _IPC5+1

        .extern IPC6
        .equiv  IPC6L, _IPC6
        .equiv  IPC6H, _IPC6+1

        .extern IPC7
        .equiv  IPC7L, _IPC7
        .equiv  IPC7H, _IPC7+1

        .extern IPC8
        .equiv  IPC8L, _IPC8
        .equiv  IPC8H, _IPC8+1

        .extern IPC9
        .equiv  IPC9L, _IPC9
        .equiv  IPC9H, _IPC9+1

        .extern IPC12
        .equiv  IPC12L, _IPC12
        .equiv  IPC12H, _IPC12+1

        .extern IPC14
        .equiv  IPC14L, _IPC14
        .equiv  IPC14H, _IPC14+1

        .extern IPC16
        .equiv  IPC16L, _IPC16
        .equiv  IPC16H, _IPC16+1

        .extern IPC17
        .equiv  IPC17L, _IPC17
        .equiv  IPC17H, _IPC17+1

        .extern IPC19
        .equiv  IPC19L, _IPC19
        .equiv  IPC19H, _IPC19+1

        .extern IPC23
        .equiv  IPC23L, _IPC23
        .equiv  IPC23H, _IPC23+1

        .extern IPC24
        .equiv  IPC24L, _IPC24
        .equiv  IPC24H, _IPC24+1

        .extern IPC35
        .equiv  IPC35L, _IPC35
        .equiv  IPC35H, _IPC35+1

        .extern IPC36
        .equiv  IPC36L, _IPC36
        .equiv  IPC36H, _IPC36+1

        .extern IPC37
        .equiv  IPC37L, _IPC37
        .equiv  IPC37H, _IPC37+1

        .extern INTCON1
        .equiv  INTCON1L, _INTCON1
        .equiv  INTCON1H, _INTCON1+1

        .extern INTCON2
        .equiv  INTCON2L, _INTCON2
        .equiv  INTCON2H, _INTCON2+1

        .extern INTCON3
        .equiv  INTCON3L, _INTCON3
        .equiv  INTCON3H, _INTCON3+1

        .extern INTCON4
        .equiv  INTCON4L, _INTCON4
        .equiv  INTCON4H, _INTCON4+1

        .extern INTTREG
        .equiv  INTTREGL, _INTTREG
        .equiv  INTTREGH, _INTTREG+1

        .extern OC1CON1
        .equiv  OC1CON1L, _OC1CON1
        .equiv  OC1CON1H, _OC1CON1+1

        .extern OC1CON2
        .equiv  OC1CON2L, _OC1CON2
        .equiv  OC1CON2H, _OC1CON2+1

        .extern OC1RS
        .equiv  OC1RSL, _OC1RS
        .equiv  OC1RSH, _OC1RS+1

        .extern OC1R
        .equiv  OC1RL, _OC1R
        .equiv  OC1RH, _OC1R+1

        .extern OC1TMR
        .equiv  OC1TMRL, _OC1TMR
        .equiv  OC1TMRH, _OC1TMR+1

        .extern OC2CON1
        .equiv  OC2CON1L, _OC2CON1
        .equiv  OC2CON1H, _OC2CON1+1

        .extern OC2CON2
        .equiv  OC2CON2L, _OC2CON2
        .equiv  OC2CON2H, _OC2CON2+1

        .extern OC2RS
        .equiv  OC2RSL, _OC2RS
        .equiv  OC2RSH, _OC2RS+1

        .extern OC2R
        .equiv  OC2RL, _OC2R
        .equiv  OC2RH, _OC2R+1

        .extern OC2TMR
        .equiv  OC2TMRL, _OC2TMR
        .equiv  OC2TMRH, _OC2TMR+1

        .extern OC3CON1
        .equiv  OC3CON1L, _OC3CON1
        .equiv  OC3CON1H, _OC3CON1+1

        .extern OC3CON2
        .equiv  OC3CON2L, _OC3CON2
        .equiv  OC3CON2H, _OC3CON2+1

        .extern OC3RS
        .equiv  OC3RSL, _OC3RS
        .equiv  OC3RSH, _OC3RS+1

        .extern OC3R
        .equiv  OC3RL, _OC3R
        .equiv  OC3RH, _OC3R+1

        .extern OC3TMR
        .equiv  OC3TMRL, _OC3TMR
        .equiv  OC3TMRH, _OC3TMR+1

        .extern OC4CON1
        .equiv  OC4CON1L, _OC4CON1
        .equiv  OC4CON1H, _OC4CON1+1

        .extern OC4CON2
        .equiv  OC4CON2L, _OC4CON2
        .equiv  OC4CON2H, _OC4CON2+1

        .extern OC4RS
        .equiv  OC4RSL, _OC4RS
        .equiv  OC4RSH, _OC4RS+1

        .extern OC4R
        .equiv  OC4RL, _OC4R
        .equiv  OC4RH, _OC4R+1

        .extern OC4TMR
        .equiv  OC4TMRL, _OC4TMR
        .equiv  OC4TMRH, _OC4TMR+1

        .extern CMSTAT
        .equiv  CMSTATL, _CMSTAT
        .equiv  CMSTATH, _CMSTAT+1

        .extern CVRCON
        .equiv  CVRCONL, _CVRCON
        .equiv  CVRCONH, _CVRCON+1

        .extern CM1CON
        .equiv  CM1CONL, _CM1CON
        .equiv  CM1CONH, _CM1CON+1

        .extern CM1MSKSRC
        .equiv  CM1MSKSRCL, _CM1MSKSRC
        .equiv  CM1MSKSRCH, _CM1MSKSRC+1

        .extern CM1MSKCON
        .equiv  CM1MSKCONL, _CM1MSKCON
        .equiv  CM1MSKCONH, _CM1MSKCON+1

        .extern CM1FLTR
        .equiv  CM1FLTRL, _CM1FLTR
        .equiv  CM1FLTRH, _CM1FLTR+1

        .extern CM2CON
        .equiv  CM2CONL, _CM2CON
        .equiv  CM2CONH, _CM2CON+1

        .extern CM2MSKSRC
        .equiv  CM2MSKSRCL, _CM2MSKSRC
        .equiv  CM2MSKSRCH, _CM2MSKSRC+1

        .extern CM2MSKCON
        .equiv  CM2MSKCONL, _CM2MSKCON
        .equiv  CM2MSKCONH, _CM2MSKCON+1

        .extern CM2FLTR
        .equiv  CM2FLTRL, _CM2FLTR
        .equiv  CM2FLTRH, _CM2FLTR+1

        .extern CM3CON
        .equiv  CM3CONL, _CM3CON
        .equiv  CM3CONH, _CM3CON+1

        .extern CM3MSKSRC
        .equiv  CM3MSKSRCL, _CM3MSKSRC
        .equiv  CM3MSKSRCH, _CM3MSKSRC+1

        .extern CM3MSKCON
        .equiv  CM3MSKCONL, _CM3MSKCON
        .equiv  CM3MSKCONH, _CM3MSKCON+1

        .extern CM3FLTR
        .equiv  CM3FLTRL, _CM3FLTR
        .equiv  CM3FLTRH, _CM3FLTR+1

        .extern CM4CON
        .equiv  CM4CONL, _CM4CON
        .equiv  CM4CONH, _CM4CON+1

        .extern CM4MSKSRC
        .equiv  CM4MSKSRCL, _CM4MSKSRC
        .equiv  CM4MSKSRCH, _CM4MSKSRC+1

        .extern CM4MSKCON
        .equiv  CM4MSKCONL, _CM4MSKCON
        .equiv  CM4MSKCONH, _CM4MSKCON+1

        .extern CM4FLTR
        .equiv  CM4FLTRL, _CM4FLTR
        .equiv  CM4FLTRH, _CM4FLTR+1

        .extern PTGCST
        .equiv  PTGCSTL, _PTGCST
        .equiv  PTGCSTH, _PTGCST+1

        .extern PTGCON
        .equiv  PTGCONL, _PTGCON
        .equiv  PTGCONH, _PTGCON+1

        .extern PTGBTE
        .equiv  PTGBTEL, _PTGBTE
        .equiv  PTGBTEH, _PTGBTE+1

        .extern PTGHOLD
        .equiv  PTGHOLDL, _PTGHOLD
        .equiv  PTGHOLDH, _PTGHOLD+1

        .extern PTGT0LIM
        .equiv  PTGT0LIML, _PTGT0LIM
        .equiv  PTGT0LIMH, _PTGT0LIM+1

        .extern PTGT1LIM
        .equiv  PTGT1LIML, _PTGT1LIM
        .equiv  PTGT1LIMH, _PTGT1LIM+1

        .extern PTGSDLIM
        .equiv  PTGSDLIML, _PTGSDLIM
        .equiv  PTGSDLIMH, _PTGSDLIM+1

        .extern PTGC0LIM
        .equiv  PTGC0LIML, _PTGC0LIM
        .equiv  PTGC0LIMH, _PTGC0LIM+1

        .extern PTGC1LIM
        .equiv  PTGC1LIML, _PTGC1LIM
        .equiv  PTGC1LIMH, _PTGC1LIM+1

        .extern PTGADJ
        .equiv  PTGADJL, _PTGADJ
        .equiv  PTGADJH, _PTGADJ+1

        .extern PTGL0
        .equiv  PTGL0L, _PTGL0
        .equiv  PTGL0H, _PTGL0+1

        .extern PTGQPTR
        .equiv  PTGQPTRL, _PTGQPTR
        .equiv  PTGQPTRH, _PTGQPTR+1

        .extern PTGQUE0
        .equiv  PTGQUE0L, _PTGQUE0
        .equiv  PTGQUE0H, _PTGQUE0+1

        .extern PTGQUE1
        .equiv  PTGQUE1L, _PTGQUE1
        .equiv  PTGQUE1H, _PTGQUE1+1

        .extern PTGQUE2
        .equiv  PTGQUE2L, _PTGQUE2
        .equiv  PTGQUE2H, _PTGQUE2+1

        .extern PTGQUE3
        .equiv  PTGQUE3L, _PTGQUE3
        .equiv  PTGQUE3H, _PTGQUE3+1

        .extern PTGQUE4
        .equiv  PTGQUE4L, _PTGQUE4
        .equiv  PTGQUE4H, _PTGQUE4+1

        .extern PTGQUE5
        .equiv  PTGQUE5L, _PTGQUE5
        .equiv  PTGQUE5H, _PTGQUE5+1

        .extern PTGQUE6
        .equiv  PTGQUE6L, _PTGQUE6
        .equiv  PTGQUE6H, _PTGQUE6+1

        .extern PTGQUE7
        .equiv  PTGQUE7L, _PTGQUE7
        .equiv  PTGQUE7H, _PTGQUE7+1

        .extern DMA0CON
        .equiv  DMA0CONL, _DMA0CON
        .equiv  DMA0CONH, _DMA0CON+1

        .extern DMA0REQ
        .equiv  DMA0REQL, _DMA0REQ
        .equiv  DMA0REQH, _DMA0REQ+1

        .extern DMA0STAL
        .equiv  DMA0STALL, _DMA0STAL
        .equiv  DMA0STALH, _DMA0STAL+1

        .extern DMA0STAH
        .equiv  DMA0STAHL, _DMA0STAH
        .equiv  DMA0STAHH, _DMA0STAH+1

        .extern DMA0STBL
        .equiv  DMA0STBLL, _DMA0STBL
        .equiv  DMA0STBLH, _DMA0STBL+1

        .extern DMA0STBH
        .equiv  DMA0STBHL, _DMA0STBH
        .equiv  DMA0STBHH, _DMA0STBH+1

        .extern DMA0PAD
        .equiv  DMA0PADL, _DMA0PAD
        .equiv  DMA0PADH, _DMA0PAD+1

        .extern DMA0CNT
        .equiv  DMA0CNTL, _DMA0CNT
        .equiv  DMA0CNTH, _DMA0CNT+1

        .extern DMA1CON
        .equiv  DMA1CONL, _DMA1CON
        .equiv  DMA1CONH, _DMA1CON+1

        .extern DMA1REQ
        .equiv  DMA1REQL, _DMA1REQ
        .equiv  DMA1REQH, _DMA1REQ+1

        .extern DMA1STAL
        .equiv  DMA1STALL, _DMA1STAL
        .equiv  DMA1STALH, _DMA1STAL+1

        .extern DMA1STAH
        .equiv  DMA1STAHL, _DMA1STAH
        .equiv  DMA1STAHH, _DMA1STAH+1

        .extern DMA1STBL
        .equiv  DMA1STBLL, _DMA1STBL
        .equiv  DMA1STBLH, _DMA1STBL+1

        .extern DMA1STBH
        .equiv  DMA1STBHL, _DMA1STBH
        .equiv  DMA1STBHH, _DMA1STBH+1

        .extern DMA1PAD
        .equiv  DMA1PADL, _DMA1PAD
        .equiv  DMA1PADH, _DMA1PAD+1

        .extern DMA1CNT
        .equiv  DMA1CNTL, _DMA1CNT
        .equiv  DMA1CNTH, _DMA1CNT+1

        .extern DMA2CON
        .equiv  DMA2CONL, _DMA2CON
        .equiv  DMA2CONH, _DMA2CON+1

        .extern DMA2REQ
        .equiv  DMA2REQL, _DMA2REQ
        .equiv  DMA2REQH, _DMA2REQ+1

        .extern DMA2STAL
        .equiv  DMA2STALL, _DMA2STAL
        .equiv  DMA2STALH, _DMA2STAL+1

        .extern DMA2STAH
        .equiv  DMA2STAHL, _DMA2STAH
        .equiv  DMA2STAHH, _DMA2STAH+1

        .extern DMA2STBL
        .equiv  DMA2STBLL, _DMA2STBL
        .equiv  DMA2STBLH, _DMA2STBL+1

        .extern DMA2STBH
        .equiv  DMA2STBHL, _DMA2STBH
        .equiv  DMA2STBHH, _DMA2STBH+1

        .extern DMA2PAD
        .equiv  DMA2PADL, _DMA2PAD
        .equiv  DMA2PADH, _DMA2PAD+1

        .extern DMA2CNT
        .equiv  DMA2CNTL, _DMA2CNT
        .equiv  DMA2CNTH, _DMA2CNT+1

        .extern DMA3CON
        .equiv  DMA3CONL, _DMA3CON
        .equiv  DMA3CONH, _DMA3CON+1

        .extern DMA3REQ
        .equiv  DMA3REQL, _DMA3REQ
        .equiv  DMA3REQH, _DMA3REQ+1

        .extern DMA3STAL
        .equiv  DMA3STALL, _DMA3STAL
        .equiv  DMA3STALH, _DMA3STAL+1

        .extern DMA3STAH
        .equiv  DMA3STAHL, _DMA3STAH
        .equiv  DMA3STAHH, _DMA3STAH+1

        .extern DMA3STBL
        .equiv  DMA3STBLL, _DMA3STBL
        .equiv  DMA3STBLH, _DMA3STBL+1

        .extern DMA3STBH
        .equiv  DMA3STBHL, _DMA3STBH
        .equiv  DMA3STBHH, _DMA3STBH+1

        .extern DMA3PAD
        .equiv  DMA3PADL, _DMA3PAD
        .equiv  DMA3PADH, _DMA3PAD+1

        .extern DMA3CNT
        .equiv  DMA3CNTL, _DMA3CNT
        .equiv  DMA3CNTH, _DMA3CNT+1

        .extern DMAPWC
        .equiv  DMAPWCL, _DMAPWC
        .equiv  DMAPWCH, _DMAPWC+1

        .extern DMARQC
        .equiv  DMARQCL, _DMARQC
        .equiv  DMARQCH, _DMARQC+1

        .extern DMAPPS
        .equiv  DMAPPSL, _DMAPPS
        .equiv  DMAPPSH, _DMAPPS+1

        .extern DMALCA
        .equiv  DMALCAL, _DMALCA
        .equiv  DMALCAH, _DMALCA+1

        .extern DSADRL
        .equiv  DSADRLL, _DSADRL
        .equiv  DSADRLH, _DSADRL+1

        .extern DSADRH
        .equiv  DSADRHL, _DSADRH
        .equiv  DSADRHH, _DSADRH+1

        .extern PTCON
        .equiv  PTCONL, _PTCON
        .equiv  PTCONH, _PTCON+1

        .extern PTCON2
        .equiv  PTCON2L, _PTCON2
        .equiv  PTCON2H, _PTCON2+1

        .extern PTPER
        .equiv  PTPERL, _PTPER
        .equiv  PTPERH, _PTPER+1

        .extern SEVTCMP
        .equiv  SEVTCMPL, _SEVTCMP
        .equiv  SEVTCMPH, _SEVTCMP+1

        .extern MDC
        .equiv  MDCL, _MDC
        .equiv  MDCH, _MDC+1

        .extern CHOP
        .equiv  CHOPL, _CHOP
        .equiv  CHOPH, _CHOP+1

        .extern PWMKEY
        .equiv  PWMKEYL, _PWMKEY
        .equiv  PWMKEYH, _PWMKEY+1

        .extern PWMCON1
        .equiv  PWMCON1L, _PWMCON1
        .equiv  PWMCON1H, _PWMCON1+1

        .extern IOCON1
        .equiv  IOCON1L, _IOCON1
        .equiv  IOCON1H, _IOCON1+1

        .extern FCLCON1
        .equiv  FCLCON1L, _FCLCON1
        .equiv  FCLCON1H, _FCLCON1+1

        .extern PDC1
        .equiv  PDC1L, _PDC1
        .equiv  PDC1H, _PDC1+1

        .extern PHASE1
        .equiv  PHASE1L, _PHASE1
        .equiv  PHASE1H, _PHASE1+1

        .extern DTR1
        .equiv  DTR1L, _DTR1
        .equiv  DTR1H, _DTR1+1

        .extern ALTDTR1
        .equiv  ALTDTR1L, _ALTDTR1
        .equiv  ALTDTR1H, _ALTDTR1+1

        .extern TRIG1
        .equiv  TRIG1L, _TRIG1
        .equiv  TRIG1H, _TRIG1+1

        .extern TRGCON1
        .equiv  TRGCON1L, _TRGCON1
        .equiv  TRGCON1H, _TRGCON1+1

        .extern LEBCON1
        .equiv  LEBCON1L, _LEBCON1
        .equiv  LEBCON1H, _LEBCON1+1

        .extern LEBDLY1
        .equiv  LEBDLY1L, _LEBDLY1
        .equiv  LEBDLY1H, _LEBDLY1+1

        .extern AUXCON1
        .equiv  AUXCON1L, _AUXCON1
        .equiv  AUXCON1H, _AUXCON1+1

        .extern PWMCON2
        .equiv  PWMCON2L, _PWMCON2
        .equiv  PWMCON2H, _PWMCON2+1

        .extern IOCON2
        .equiv  IOCON2L, _IOCON2
        .equiv  IOCON2H, _IOCON2+1

        .extern FCLCON2
        .equiv  FCLCON2L, _FCLCON2
        .equiv  FCLCON2H, _FCLCON2+1

        .extern PDC2
        .equiv  PDC2L, _PDC2
        .equiv  PDC2H, _PDC2+1

        .extern PHASE2
        .equiv  PHASE2L, _PHASE2
        .equiv  PHASE2H, _PHASE2+1

        .extern DTR2
        .equiv  DTR2L, _DTR2
        .equiv  DTR2H, _DTR2+1

        .extern ALTDTR2
        .equiv  ALTDTR2L, _ALTDTR2
        .equiv  ALTDTR2H, _ALTDTR2+1

        .extern TRIG2
        .equiv  TRIG2L, _TRIG2
        .equiv  TRIG2H, _TRIG2+1

        .extern TRGCON2
        .equiv  TRGCON2L, _TRGCON2
        .equiv  TRGCON2H, _TRGCON2+1

        .extern LEBCON2
        .equiv  LEBCON2L, _LEBCON2
        .equiv  LEBCON2H, _LEBCON2+1

        .extern LEBDLY2
        .equiv  LEBDLY2L, _LEBDLY2
        .equiv  LEBDLY2H, _LEBDLY2+1

        .extern AUXCON2
        .equiv  AUXCON2L, _AUXCON2
        .equiv  AUXCON2H, _AUXCON2+1

        .extern PWMCON3
        .equiv  PWMCON3L, _PWMCON3
        .equiv  PWMCON3H, _PWMCON3+1

        .extern IOCON3
        .equiv  IOCON3L, _IOCON3
        .equiv  IOCON3H, _IOCON3+1

        .extern FCLCON3
        .equiv  FCLCON3L, _FCLCON3
        .equiv  FCLCON3H, _FCLCON3+1

        .extern PDC3
        .equiv  PDC3L, _PDC3
        .equiv  PDC3H, _PDC3+1

        .extern PHASE3
        .equiv  PHASE3L, _PHASE3
        .equiv  PHASE3H, _PHASE3+1

        .extern DTR3
        .equiv  DTR3L, _DTR3
        .equiv  DTR3H, _DTR3+1

        .extern ALTDTR3
        .equiv  ALTDTR3L, _ALTDTR3
        .equiv  ALTDTR3H, _ALTDTR3+1

        .extern TRIG3
        .equiv  TRIG3L, _TRIG3
        .equiv  TRIG3H, _TRIG3+1

        .extern TRGCON3
        .equiv  TRGCON3L, _TRGCON3
        .equiv  TRGCON3H, _TRGCON3+1

        .extern LEBCON3
        .equiv  LEBCON3L, _LEBCON3
        .equiv  LEBCON3H, _LEBCON3+1

        .extern LEBDLY3
        .equiv  LEBDLY3L, _LEBDLY3
        .equiv  LEBDLY3H, _LEBDLY3+1

        .extern AUXCON3
        .equiv  AUXCON3L, _AUXCON3
        .equiv  AUXCON3H, _AUXCON3+1

        .extern TRISA
        .equiv  TRISAL, _TRISA
        .equiv  TRISAH, _TRISA+1

        .extern PORTA
        .equiv  PORTAL, _PORTA
        .equiv  PORTAH, _PORTA+1

        .extern LATA
        .equiv  LATAL, _LATA
        .equiv  LATAH, _LATA+1

        .extern ODCA
        .equiv  ODCAL, _ODCA
        .equiv  ODCAH, _ODCA+1

        .extern CNENA
        .equiv  CNENAL, _CNENA
        .equiv  CNENAH, _CNENA+1

        .extern CNPUA
        .equiv  CNPUAL, _CNPUA
        .equiv  CNPUAH, _CNPUA+1

        .extern CNPDA
        .equiv  CNPDAL, _CNPDA
        .equiv  CNPDAH, _CNPDA+1

        .extern ANSELA
        .equiv  ANSELAL, _ANSELA
        .equiv  ANSELAH, _ANSELA+1

        .extern TRISB
        .equiv  TRISBL, _TRISB
        .equiv  TRISBH, _TRISB+1

        .extern PORTB
        .equiv  PORTBL, _PORTB
        .equiv  PORTBH, _PORTB+1

        .extern LATB
        .equiv  LATBL, _LATB
        .equiv  LATBH, _LATB+1

        .extern ODCB
        .equiv  ODCBL, _ODCB
        .equiv  ODCBH, _ODCB+1

        .extern CNENB
        .equiv  CNENBL, _CNENB
        .equiv  CNENBH, _CNENB+1

        .extern CNPUB
        .equiv  CNPUBL, _CNPUB
        .equiv  CNPUBH, _CNPUB+1

        .extern CNPDB
        .equiv  CNPDBL, _CNPDB
        .equiv  CNPDBH, _CNPDB+1

        .extern ANSELB
        .equiv  ANSELBL, _ANSELB
        .equiv  ANSELBH, _ANSELB+1

        .extern TRISC
        .equiv  TRISCL, _TRISC
        .equiv  TRISCH, _TRISC+1

        .extern PORTC
        .equiv  PORTCL, _PORTC
        .equiv  PORTCH, _PORTC+1

        .extern LATC
        .equiv  LATCL, _LATC
        .equiv  LATCH, _LATC+1

        .extern ODCC
        .equiv  ODCCL, _ODCC
        .equiv  ODCCH, _ODCC+1

        .extern CNENC
        .equiv  CNENCL, _CNENC
        .equiv  CNENCH, _CNENC+1

        .extern CNPUC
        .equiv  CNPUCL, _CNPUC
        .equiv  CNPUCH, _CNPUC+1

        .extern CNPDC
        .equiv  CNPDCL, _CNPDC
        .equiv  CNPDCH, _CNPDC+1

        .extern ANSELC
        .equiv  ANSELCL, _ANSELC
        .equiv  ANSELCH, _ANSELC+1

        .extern TRISD
        .equiv  TRISDL, _TRISD
        .equiv  TRISDH, _TRISD+1

        .extern PORTD
        .equiv  PORTDL, _PORTD
        .equiv  PORTDH, _PORTD+1

        .extern LATD
        .equiv  LATDL, _LATD
        .equiv  LATDH, _LATD+1

        .extern ODCD
        .equiv  ODCDL, _ODCD
        .equiv  ODCDH, _ODCD+1

        .extern CNEND
        .equiv  CNENDL, _CNEND
        .equiv  CNENDH, _CNEND+1

        .extern CNPUD
        .equiv  CNPUDL, _CNPUD
        .equiv  CNPUDH, _CNPUD+1

        .extern CNPDD
        .equiv  CNPDDL, _CNPDD
        .equiv  CNPDDH, _CNPDD+1

        .extern TRISE
        .equiv  TRISEL, _TRISE
        .equiv  TRISEH, _TRISE+1

        .extern PORTE
        .equiv  PORTEL, _PORTE
        .equiv  PORTEH, _PORTE+1

        .extern LATE
        .equiv  LATEL, _LATE
        .equiv  LATEH, _LATE+1

        .extern ODCE
        .equiv  ODCEL, _ODCE
        .equiv  ODCEH, _ODCE+1

        .extern CNENE
        .equiv  CNENEL, _CNENE
        .equiv  CNENEH, _CNENE+1

        .extern CNPUE
        .equiv  CNPUEL, _CNPUE
        .equiv  CNPUEH, _CNPUE+1

        .extern CNPDE
        .equiv  CNPDEL, _CNPDE
        .equiv  CNPDEH, _CNPDE+1

        .extern ANSELE
        .equiv  ANSELEL, _ANSELE
        .equiv  ANSELEH, _ANSELE+1

        .extern TRISF
        .equiv  TRISFL, _TRISF
        .equiv  TRISFH, _TRISF+1

        .extern PORTF
        .equiv  PORTFL, _PORTF
        .equiv  PORTFH, _PORTF+1

        .extern LATF
        .equiv  LATFL, _LATF
        .equiv  LATFH, _LATF+1

        .extern ODCF
        .equiv  ODCFL, _ODCF
        .equiv  ODCFH, _ODCF+1

        .extern CNENF
        .equiv  CNENFL, _CNENF
        .equiv  CNENFH, _CNENF+1

        .extern CNPUF
        .equiv  CNPUFL, _CNPUF
        .equiv  CNPUFH, _CNPUF+1

        .extern CNPDF
        .equiv  CNPDFL, _CNPDF
        .equiv  CNPDFH, _CNPDF+1

        .extern TRISG
        .equiv  TRISGL, _TRISG
        .equiv  TRISGH, _TRISG+1

        .extern PORTG
        .equiv  PORTGL, _PORTG
        .equiv  PORTGH, _PORTG+1

        .extern LATG
        .equiv  LATGL, _LATG
        .equiv  LATGH, _LATG+1

        .extern ODCG
        .equiv  ODCGL, _ODCG
        .equiv  ODCGH, _ODCG+1

        .extern CNENG
        .equiv  CNENGL, _CNENG
        .equiv  CNENGH, _CNENG+1

        .extern CNPUG
        .equiv  CNPUGL, _CNPUG
        .equiv  CNPUGH, _CNPUG+1

        .extern CNPDG
        .equiv  CNPDGL, _CNPDG
        .equiv  CNPDGH, _CNPDG+1

        .extern _APPO
        .equiv  _APPOL, __APPO
        .equiv  _APPOH, __APPO+1

        .extern _APPIN
        .equiv  _APPINL, __APPIN
        .equiv  _APPINH, __APPIN+1

        .extern APPS
        .equiv  APPSL, _APPS
        .equiv  APPSH, _APPS+1

        .extern STROUTL
        .equiv  STROUTLL, _STROUTL
        .equiv  STROUTLH, _STROUTL+1

        .extern STROUTH
        .equiv  STROUTHL, _STROUTH
        .equiv  STROUTHH, _STROUTH+1

        .extern STROVCNT
        .equiv  STROVCNTL, _STROVCNT
        .equiv  STROVCNTH, _STROVCNT+1

        .extern JDATAH
        .equiv  JDATAHL, _JDATAH
        .equiv  JDATAHH, _JDATAH+1

        .extern JDATAL
        .equiv  JDATALL, _JDATAL
        .equiv  JDATALH, _JDATAL+1

;----- DSRPAG Bits -----------------------------------------------------
        .equiv  DSRPAG, 0x0000
        .equiv  DSRPAG_WIDTH, 0x000A
        .equiv  DSRPAG_MASK, 0x03FF

;----- DSWPAG Bits -----------------------------------------------------
        .equiv  DSWPAG, 0x0000
        .equiv  DSWPAG_WIDTH, 0x0009
        .equiv  DSWPAG_MASK, 0x01FF

;----- SR Bits -----------------------------------------------------
        .equiv  SR_C, 0x0000
        .equiv  SR_C_WIDTH, 0x0001
        .equiv  SR_C_MASK, 0x0001
        .equiv  C, 0x0000

        .equiv  SR_Z, 0x0001
        .equiv  SR_Z_WIDTH, 0x0001
        .equiv  SR_Z_MASK, 0x0002
        .equiv  Z, 0x0001

        .equiv  SR_OV, 0x0002
        .equiv  SR_OV_WIDTH, 0x0001
        .equiv  SR_OV_MASK, 0x0004
        .equiv  OV, 0x0002

        .equiv  SR_N, 0x0003
        .equiv  SR_N_WIDTH, 0x0001
        .equiv  SR_N_MASK, 0x0008
        .equiv  N, 0x0003

        .equiv  SR_RA, 0x0004
        .equiv  SR_RA_WIDTH, 0x0001
        .equiv  SR_RA_MASK, 0x0010
        .equiv  RA, 0x0004

        .equiv  SR_IPL, 0x0005
        .equiv  SR_IPL_WIDTH, 0x0003
        .equiv  SR_IPL_MASK, 0x00E0

        .equiv  SR_DC, 0x0008
        .equiv  SR_DC_WIDTH, 0x0001
        .equiv  SR_DC_MASK, 0x0100
        .equiv  DC, 0x0008

        .equiv  SR_DA, 0x0009
        .equiv  SR_DA_WIDTH, 0x0001
        .equiv  SR_DA_MASK, 0x0200
        .equiv  DA, 0x0009

        .equiv  SR_SAB, 0x000A
        .equiv  SR_SAB_WIDTH, 0x0001
        .equiv  SR_SAB_MASK, 0x0400
        .equiv  SAB, 0x000A

        .equiv  SR_OAB, 0x000B
        .equiv  SR_OAB_WIDTH, 0x0001
        .equiv  SR_OAB_MASK, 0x0800
        .equiv  OAB, 0x000B

        .equiv  SR_SB, 0x000C
        .equiv  SR_SB_WIDTH, 0x0001
        .equiv  SR_SB_MASK, 0x1000
        .equiv  SB, 0x000C

        .equiv  SR_SA, 0x000D
        .equiv  SR_SA_WIDTH, 0x0001
        .equiv  SR_SA_MASK, 0x2000
        .equiv  SA, 0x000D

        .equiv  SR_OB, 0x000E
        .equiv  SR_OB_WIDTH, 0x0001
        .equiv  SR_OB_MASK, 0x4000
        .equiv  OB, 0x000E

        .equiv  SR_OA, 0x000F
        .equiv  SR_OA_WIDTH, 0x0001
        .equiv  SR_OA_MASK, 0x8000
        .equiv  OA, 0x000F

        .equiv  SR_IPL0, 0x0005
        .equiv  SR_IPL0_WIDTH, 0x0001
        .equiv  SR_IPL0_MASK, 0x0020
        .equiv  IPL0, 0x0005

        .equiv  SR_IPL1, 0x0006
        .equiv  SR_IPL1_WIDTH, 0x0001
        .equiv  SR_IPL1_MASK, 0x0040
        .equiv  IPL1, 0x0006

        .equiv  SR_IPL2, 0x0007
        .equiv  SR_IPL2_WIDTH, 0x0001
        .equiv  SR_IPL2_MASK, 0x0080
        .equiv  IPL2, 0x0007

;----- CORCON Bits -----------------------------------------------------
        .equiv  CORCON_IF, 0x0000
        .equiv  CORCON_IF_WIDTH, 0x0001
        .equiv  CORCON_IF_MASK, 0x0001
        .equiv  IF, 0x0000

        .equiv  CORCON_RND, 0x0001
        .equiv  CORCON_RND_WIDTH, 0x0001
        .equiv  CORCON_RND_MASK, 0x0002
        .equiv  RND, 0x0001

        .equiv  CORCON_SFA, 0x0002
        .equiv  CORCON_SFA_WIDTH, 0x0001
        .equiv  CORCON_SFA_MASK, 0x0004
        .equiv  SFA, 0x0002

        .equiv  CORCON_IPL3, 0x0003
        .equiv  CORCON_IPL3_WIDTH, 0x0001
        .equiv  CORCON_IPL3_MASK, 0x0008
        .equiv  IPL3, 0x0003

        .equiv  CORCON_ACCSAT, 0x0004
        .equiv  CORCON_ACCSAT_WIDTH, 0x0001
        .equiv  CORCON_ACCSAT_MASK, 0x0010
        .equiv  ACCSAT, 0x0004

        .equiv  CORCON_SATDW, 0x0005
        .equiv  CORCON_SATDW_WIDTH, 0x0001
        .equiv  CORCON_SATDW_MASK, 0x0020
        .equiv  SATDW, 0x0005

        .equiv  CORCON_SATB, 0x0006
        .equiv  CORCON_SATB_WIDTH, 0x0001
        .equiv  CORCON_SATB_MASK, 0x0040
        .equiv  SATB, 0x0006

        .equiv  CORCON_SATA, 0x0007
        .equiv  CORCON_SATA_WIDTH, 0x0001
        .equiv  CORCON_SATA_MASK, 0x0080
        .equiv  SATA, 0x0007

        .equiv  CORCON_DL, 0x0008
        .equiv  CORCON_DL_WIDTH, 0x0003
        .equiv  CORCON_DL_MASK, 0x0700

        .equiv  CORCON_EDT, 0x000B
        .equiv  CORCON_EDT_WIDTH, 0x0001
        .equiv  CORCON_EDT_MASK, 0x0800
        .equiv  EDT, 0x000B

        .equiv  CORCON_US, 0x000C
        .equiv  CORCON_US_WIDTH, 0x0002
        .equiv  CORCON_US_MASK, 0x3000

        .equiv  CORCON_VAR, 0x000F
        .equiv  CORCON_VAR_WIDTH, 0x0001
        .equiv  CORCON_VAR_MASK, 0x8000
        .equiv  VAR, 0x000F

        .equiv  CORCON_DL0, 0x0008
        .equiv  CORCON_DL0_WIDTH, 0x0001
        .equiv  CORCON_DL0_MASK, 0x0100
        .equiv  DL0, 0x0008

        .equiv  CORCON_DL1, 0x0009
        .equiv  CORCON_DL1_WIDTH, 0x0001
        .equiv  CORCON_DL1_MASK, 0x0200
        .equiv  DL1, 0x0009

        .equiv  CORCON_DL2, 0x000A
        .equiv  CORCON_DL2_WIDTH, 0x0001
        .equiv  CORCON_DL2_MASK, 0x0400
        .equiv  DL2, 0x000A

        .equiv  CORCON_US0, 0x000C
        .equiv  CORCON_US0_WIDTH, 0x0001
        .equiv  CORCON_US0_MASK, 0x1000
        .equiv  US0, 0x000C

        .equiv  CORCON_US1, 0x000D
        .equiv  CORCON_US1_WIDTH, 0x0001
        .equiv  CORCON_US1_MASK, 0x2000
        .equiv  US1, 0x000D

;----- MODCON Bits -----------------------------------------------------
        .equiv  MODCON_XWM, 0x0000
        .equiv  MODCON_XWM_WIDTH, 0x0004
        .equiv  MODCON_XWM_MASK, 0x000F

        .equiv  MODCON_YWM, 0x0004
        .equiv  MODCON_YWM_WIDTH, 0x0004
        .equiv  MODCON_YWM_MASK, 0x00F0

        .equiv  MODCON_BWM, 0x0008
        .equiv  MODCON_BWM_WIDTH, 0x0004
        .equiv  MODCON_BWM_MASK, 0x0F00

        .equiv  MODCON_YMODEN, 0x000E
        .equiv  MODCON_YMODEN_WIDTH, 0x0001
        .equiv  MODCON_YMODEN_MASK, 0x4000
        .equiv  YMODEN, 0x000E

        .equiv  MODCON_XMODEN, 0x000F
        .equiv  MODCON_XMODEN_WIDTH, 0x0001
        .equiv  MODCON_XMODEN_MASK, 0x8000
        .equiv  XMODEN, 0x000F

        .equiv  MODCON_XWM0, 0x0000
        .equiv  MODCON_XWM0_WIDTH, 0x0001
        .equiv  MODCON_XWM0_MASK, 0x0001
        .equiv  XWM0, 0x0000

        .equiv  MODCON_XWM1, 0x0001
        .equiv  MODCON_XWM1_WIDTH, 0x0001
        .equiv  MODCON_XWM1_MASK, 0x0002
        .equiv  XWM1, 0x0001

        .equiv  MODCON_XWM2, 0x0002
        .equiv  MODCON_XWM2_WIDTH, 0x0001
        .equiv  MODCON_XWM2_MASK, 0x0004
        .equiv  XWM2, 0x0002

        .equiv  MODCON_XWM3, 0x0003
        .equiv  MODCON_XWM3_WIDTH, 0x0001
        .equiv  MODCON_XWM3_MASK, 0x0008
        .equiv  XWM3, 0x0003

        .equiv  MODCON_YWM0, 0x0004
        .equiv  MODCON_YWM0_WIDTH, 0x0001
        .equiv  MODCON_YWM0_MASK, 0x0010
        .equiv  YWM0, 0x0004

        .equiv  MODCON_YWM1, 0x0005
        .equiv  MODCON_YWM1_WIDTH, 0x0001
        .equiv  MODCON_YWM1_MASK, 0x0020
        .equiv  YWM1, 0x0005

        .equiv  MODCON_YWM2, 0x0006
        .equiv  MODCON_YWM2_WIDTH, 0x0001
        .equiv  MODCON_YWM2_MASK, 0x0040
        .equiv  YWM2, 0x0006

        .equiv  MODCON_YWM3, 0x0007
        .equiv  MODCON_YWM3_WIDTH, 0x0001
        .equiv  MODCON_YWM3_MASK, 0x0080
        .equiv  YWM3, 0x0007

        .equiv  MODCON_BWM0, 0x0008
        .equiv  MODCON_BWM0_WIDTH, 0x0001
        .equiv  MODCON_BWM0_MASK, 0x0100
        .equiv  BWM0, 0x0008

        .equiv  MODCON_BWM1, 0x0009
        .equiv  MODCON_BWM1_WIDTH, 0x0001
        .equiv  MODCON_BWM1_MASK, 0x0200
        .equiv  BWM1, 0x0009

        .equiv  MODCON_BWM2, 0x000A
        .equiv  MODCON_BWM2_WIDTH, 0x0001
        .equiv  MODCON_BWM2_MASK, 0x0400
        .equiv  BWM2, 0x000A

        .equiv  MODCON_BWM3, 0x000B
        .equiv  MODCON_BWM3_WIDTH, 0x0001
        .equiv  MODCON_BWM3_MASK, 0x0800
        .equiv  BWM3, 0x000B

;----- XBREV Bits -----------------------------------------------------
        .equiv  XBREV_XB, 0x0000
        .equiv  XBREV_XB_WIDTH, 0x000F
        .equiv  XBREV_XB_MASK, 0x7FFF

        .equiv  XBREV_BREN, 0x000F
        .equiv  XBREV_BREN_WIDTH, 0x0001
        .equiv  XBREV_BREN_MASK, 0x8000
        .equiv  BREN, 0x000F

        .equiv  XBREV_XB0, 0x0000
        .equiv  XBREV_XB0_WIDTH, 0x0001
        .equiv  XBREV_XB0_MASK, 0x0001
        .equiv  XB0, 0x0000

        .equiv  XBREV_XB1, 0x0001
        .equiv  XBREV_XB1_WIDTH, 0x0001
        .equiv  XBREV_XB1_MASK, 0x0002
        .equiv  XB1, 0x0001

        .equiv  XBREV_XB2, 0x0002
        .equiv  XBREV_XB2_WIDTH, 0x0001
        .equiv  XBREV_XB2_MASK, 0x0004
        .equiv  XB2, 0x0002

        .equiv  XBREV_XB3, 0x0003
        .equiv  XBREV_XB3_WIDTH, 0x0001
        .equiv  XBREV_XB3_MASK, 0x0008
        .equiv  XB3, 0x0003

        .equiv  XBREV_XB4, 0x0004
        .equiv  XBREV_XB4_WIDTH, 0x0001
        .equiv  XBREV_XB4_MASK, 0x0010
        .equiv  XB4, 0x0004

        .equiv  XBREV_XB5, 0x0005
        .equiv  XBREV_XB5_WIDTH, 0x0001
        .equiv  XBREV_XB5_MASK, 0x0020
        .equiv  XB5, 0x0005

        .equiv  XBREV_XB6, 0x0006
        .equiv  XBREV_XB6_WIDTH, 0x0001
        .equiv  XBREV_XB6_MASK, 0x0040
        .equiv  XB6, 0x0006

        .equiv  XBREV_XB7, 0x0007
        .equiv  XBREV_XB7_WIDTH, 0x0001
        .equiv  XBREV_XB7_MASK, 0x0080
        .equiv  XB7, 0x0007

        .equiv  XBREV_XB8, 0x0008
        .equiv  XBREV_XB8_WIDTH, 0x0001
        .equiv  XBREV_XB8_MASK, 0x0100
        .equiv  XB8, 0x0008

        .equiv  XBREV_XB9, 0x0009
        .equiv  XBREV_XB9_WIDTH, 0x0001
        .equiv  XBREV_XB9_MASK, 0x0200
        .equiv  XB9, 0x0009

        .equiv  XBREV_XB10, 0x000A
        .equiv  XBREV_XB10_WIDTH, 0x0001
        .equiv  XBREV_XB10_MASK, 0x0400
        .equiv  XB10, 0x000A

        .equiv  XBREV_XB11, 0x000B
        .equiv  XBREV_XB11_WIDTH, 0x0001
        .equiv  XBREV_XB11_MASK, 0x0800
        .equiv  XB11, 0x000B

        .equiv  XBREV_XB12, 0x000C
        .equiv  XBREV_XB12_WIDTH, 0x0001
        .equiv  XBREV_XB12_MASK, 0x1000
        .equiv  XB12, 0x000C

        .equiv  XBREV_XB13, 0x000D
        .equiv  XBREV_XB13_WIDTH, 0x0001
        .equiv  XBREV_XB13_MASK, 0x2000
        .equiv  XB13, 0x000D

        .equiv  XBREV_XB14, 0x000E
        .equiv  XBREV_XB14_WIDTH, 0x0001
        .equiv  XBREV_XB14_MASK, 0x4000
        .equiv  XB14, 0x000E

;----- TBLPAG Bits -----------------------------------------------------
        .equiv  TBLPAG, 0x0000
        .equiv  TBLPAG_WIDTH, 0x0008
        .equiv  TBLPAG_MASK, 0x00FF

;----- T1CON Bits -----------------------------------------------------
        .equiv  T1CON_TCS, 0x0001
        .equiv  T1CON_TCS_WIDTH, 0x0001
        .equiv  T1CON_TCS_MASK, 0x0002
        .equiv  TCS, 0x0001

        .equiv  T1CON_TSYNC, 0x0002
        .equiv  T1CON_TSYNC_WIDTH, 0x0001
        .equiv  T1CON_TSYNC_MASK, 0x0004
        .equiv  TSYNC, 0x0002

        .equiv  T1CON_TCKPS, 0x0004
        .equiv  T1CON_TCKPS_WIDTH, 0x0002
        .equiv  T1CON_TCKPS_MASK, 0x0030

        .equiv  T1CON_TGATE, 0x0006
        .equiv  T1CON_TGATE_WIDTH, 0x0001
        .equiv  T1CON_TGATE_MASK, 0x0040
        .equiv  TGATE, 0x0006

        .equiv  T1CON_TSIDL, 0x000D
        .equiv  T1CON_TSIDL_WIDTH, 0x0001
        .equiv  T1CON_TSIDL_MASK, 0x2000
        .equiv  TSIDL, 0x000D

        .equiv  T1CON_TON, 0x000F
        .equiv  T1CON_TON_WIDTH, 0x0001
        .equiv  T1CON_TON_MASK, 0x8000
        .equiv  TON, 0x000F

        .equiv  T1CON_TCKPS0, 0x0004
        .equiv  T1CON_TCKPS0_WIDTH, 0x0001
        .equiv  T1CON_TCKPS0_MASK, 0x0010
        .equiv  TCKPS0, 0x0004

        .equiv  T1CON_TCKPS1, 0x0005
        .equiv  T1CON_TCKPS1_WIDTH, 0x0001
        .equiv  T1CON_TCKPS1_MASK, 0x0020
        .equiv  TCKPS1, 0x0005

;----- T2CON Bits -----------------------------------------------------
        .equiv  T2CON_TCS, 0x0001
        .equiv  T2CON_TCS_WIDTH, 0x0001
        .equiv  T2CON_TCS_MASK, 0x0002

        .equiv  T2CON_T32, 0x0003
        .equiv  T2CON_T32_WIDTH, 0x0001
        .equiv  T2CON_T32_MASK, 0x0008
        .equiv  T32, 0x0003

        .equiv  T2CON_TCKPS, 0x0004
        .equiv  T2CON_TCKPS_WIDTH, 0x0002
        .equiv  T2CON_TCKPS_MASK, 0x0030

        .equiv  T2CON_TGATE, 0x0006
        .equiv  T2CON_TGATE_WIDTH, 0x0001
        .equiv  T2CON_TGATE_MASK, 0x0040

        .equiv  T2CON_TSIDL, 0x000D
        .equiv  T2CON_TSIDL_WIDTH, 0x0001
        .equiv  T2CON_TSIDL_MASK, 0x2000

        .equiv  T2CON_TON, 0x000F
        .equiv  T2CON_TON_WIDTH, 0x0001
        .equiv  T2CON_TON_MASK, 0x8000

        .equiv  T2CON_TCKPS0, 0x0004
        .equiv  T2CON_TCKPS0_WIDTH, 0x0001
        .equiv  T2CON_TCKPS0_MASK, 0x0010

        .equiv  T2CON_TCKPS1, 0x0005
        .equiv  T2CON_TCKPS1_WIDTH, 0x0001
        .equiv  T2CON_TCKPS1_MASK, 0x0020

;----- T3CON Bits -----------------------------------------------------
        .equiv  T3CON_TCS, 0x0001
        .equiv  T3CON_TCS_WIDTH, 0x0001
        .equiv  T3CON_TCS_MASK, 0x0002

        .equiv  T3CON_TCKPS, 0x0004
        .equiv  T3CON_TCKPS_WIDTH, 0x0002
        .equiv  T3CON_TCKPS_MASK, 0x0030

        .equiv  T3CON_TGATE, 0x0006
        .equiv  T3CON_TGATE_WIDTH, 0x0001
        .equiv  T3CON_TGATE_MASK, 0x0040

        .equiv  T3CON_TSIDL, 0x000D
        .equiv  T3CON_TSIDL_WIDTH, 0x0001
        .equiv  T3CON_TSIDL_MASK, 0x2000

        .equiv  T3CON_TON, 0x000F
        .equiv  T3CON_TON_WIDTH, 0x0001
        .equiv  T3CON_TON_MASK, 0x8000

        .equiv  T3CON_TCKPS0, 0x0004
        .equiv  T3CON_TCKPS0_WIDTH, 0x0001
        .equiv  T3CON_TCKPS0_MASK, 0x0010

        .equiv  T3CON_TCKPS1, 0x0005
        .equiv  T3CON_TCKPS1_WIDTH, 0x0001
        .equiv  T3CON_TCKPS1_MASK, 0x0020

;----- T4CON Bits -----------------------------------------------------
        .equiv  T4CON_TCS, 0x0001
        .equiv  T4CON_TCS_WIDTH, 0x0001
        .equiv  T4CON_TCS_MASK, 0x0002

        .equiv  T4CON_T32, 0x0003
        .equiv  T4CON_T32_WIDTH, 0x0001
        .equiv  T4CON_T32_MASK, 0x0008

        .equiv  T4CON_TCKPS, 0x0004
        .equiv  T4CON_TCKPS_WIDTH, 0x0002
        .equiv  T4CON_TCKPS_MASK, 0x0030

        .equiv  T4CON_TGATE, 0x0006
        .equiv  T4CON_TGATE_WIDTH, 0x0001
        .equiv  T4CON_TGATE_MASK, 0x0040

        .equiv  T4CON_TSIDL, 0x000D
        .equiv  T4CON_TSIDL_WIDTH, 0x0001
        .equiv  T4CON_TSIDL_MASK, 0x2000

        .equiv  T4CON_TON, 0x000F
        .equiv  T4CON_TON_WIDTH, 0x0001
        .equiv  T4CON_TON_MASK, 0x8000

        .equiv  T4CON_TCKPS0, 0x0004
        .equiv  T4CON_TCKPS0_WIDTH, 0x0001
        .equiv  T4CON_TCKPS0_MASK, 0x0010

        .equiv  T4CON_TCKPS1, 0x0005
        .equiv  T4CON_TCKPS1_WIDTH, 0x0001
        .equiv  T4CON_TCKPS1_MASK, 0x0020

;----- T5CON Bits -----------------------------------------------------
        .equiv  T5CON_TCS, 0x0001
        .equiv  T5CON_TCS_WIDTH, 0x0001
        .equiv  T5CON_TCS_MASK, 0x0002

        .equiv  T5CON_TCKPS, 0x0004
        .equiv  T5CON_TCKPS_WIDTH, 0x0002
        .equiv  T5CON_TCKPS_MASK, 0x0030

        .equiv  T5CON_TGATE, 0x0006
        .equiv  T5CON_TGATE_WIDTH, 0x0001
        .equiv  T5CON_TGATE_MASK, 0x0040

        .equiv  T5CON_TSIDL, 0x000D
        .equiv  T5CON_TSIDL_WIDTH, 0x0001
        .equiv  T5CON_TSIDL_MASK, 0x2000

        .equiv  T5CON_TON, 0x000F
        .equiv  T5CON_TON_WIDTH, 0x0001
        .equiv  T5CON_TON_MASK, 0x8000

        .equiv  T5CON_TCKPS0, 0x0004
        .equiv  T5CON_TCKPS0_WIDTH, 0x0001
        .equiv  T5CON_TCKPS0_MASK, 0x0010

        .equiv  T5CON_TCKPS1, 0x0005
        .equiv  T5CON_TCKPS1_WIDTH, 0x0001
        .equiv  T5CON_TCKPS1_MASK, 0x0020

;----- IC1CON1 Bits -----------------------------------------------------
        .equiv  IC1CON1_ICM, 0x0000
        .equiv  IC1CON1_ICM_WIDTH, 0x0003
        .equiv  IC1CON1_ICM_MASK, 0x0007

        .equiv  IC1CON1_ICBNE, 0x0003
        .equiv  IC1CON1_ICBNE_WIDTH, 0x0001
        .equiv  IC1CON1_ICBNE_MASK, 0x0008
        .equiv  ICBNE, 0x0003

        .equiv  IC1CON1_ICOV, 0x0004
        .equiv  IC1CON1_ICOV_WIDTH, 0x0001
        .equiv  IC1CON1_ICOV_MASK, 0x0010
        .equiv  ICOV, 0x0004

        .equiv  IC1CON1_ICI, 0x0005
        .equiv  IC1CON1_ICI_WIDTH, 0x0002
        .equiv  IC1CON1_ICI_MASK, 0x0060

        .equiv  IC1CON1_ICTSEL, 0x000A
        .equiv  IC1CON1_ICTSEL_WIDTH, 0x0003
        .equiv  IC1CON1_ICTSEL_MASK, 0x1C00

        .equiv  IC1CON1_ICSIDL, 0x000D
        .equiv  IC1CON1_ICSIDL_WIDTH, 0x0001
        .equiv  IC1CON1_ICSIDL_MASK, 0x2000
        .equiv  ICSIDL, 0x000D

        .equiv  IC1CON1_ICM0, 0x0000
        .equiv  IC1CON1_ICM0_WIDTH, 0x0001
        .equiv  IC1CON1_ICM0_MASK, 0x0001
        .equiv  ICM0, 0x0000

        .equiv  IC1CON1_ICM1, 0x0001
        .equiv  IC1CON1_ICM1_WIDTH, 0x0001
        .equiv  IC1CON1_ICM1_MASK, 0x0002
        .equiv  ICM1, 0x0001

        .equiv  IC1CON1_ICM2, 0x0002
        .equiv  IC1CON1_ICM2_WIDTH, 0x0001
        .equiv  IC1CON1_ICM2_MASK, 0x0004
        .equiv  ICM2, 0x0002

        .equiv  IC1CON1_ICI0, 0x0005
        .equiv  IC1CON1_ICI0_WIDTH, 0x0001
        .equiv  IC1CON1_ICI0_MASK, 0x0020
        .equiv  ICI0, 0x0005

        .equiv  IC1CON1_ICI1, 0x0006
        .equiv  IC1CON1_ICI1_WIDTH, 0x0001
        .equiv  IC1CON1_ICI1_MASK, 0x0040
        .equiv  ICI1, 0x0006

        .equiv  IC1CON1_ICTSEL0, 0x000A
        .equiv  IC1CON1_ICTSEL0_WIDTH, 0x0001
        .equiv  IC1CON1_ICTSEL0_MASK, 0x0400
        .equiv  ICTSEL0, 0x000A

        .equiv  IC1CON1_ICTSEL1, 0x000B
        .equiv  IC1CON1_ICTSEL1_WIDTH, 0x0001
        .equiv  IC1CON1_ICTSEL1_MASK, 0x0800
        .equiv  ICTSEL1, 0x000B

        .equiv  IC1CON1_ICTSEL2, 0x000C
        .equiv  IC1CON1_ICTSEL2_WIDTH, 0x0001
        .equiv  IC1CON1_ICTSEL2_MASK, 0x1000
        .equiv  ICTSEL2, 0x000C

;----- IC1CON2 Bits -----------------------------------------------------
        .equiv  IC1CON2_SYNCSEL, 0x0000
        .equiv  IC1CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  IC1CON2_SYNCSEL_MASK, 0x001F

        .equiv  IC1CON2_TRIGSTAT, 0x0006
        .equiv  IC1CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  IC1CON2_TRIGSTAT_MASK, 0x0040
        .equiv  TRIGSTAT, 0x0006

        .equiv  IC1CON2_ICTRIG, 0x0007
        .equiv  IC1CON2_ICTRIG_WIDTH, 0x0001
        .equiv  IC1CON2_ICTRIG_MASK, 0x0080
        .equiv  ICTRIG, 0x0007

        .equiv  IC1CON2_IC32, 0x0008
        .equiv  IC1CON2_IC32_WIDTH, 0x0001
        .equiv  IC1CON2_IC32_MASK, 0x0100
        .equiv  IC32, 0x0008

        .equiv  IC1CON2_SYNCSEL0, 0x0000
        .equiv  IC1CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  IC1CON2_SYNCSEL0_MASK, 0x0001
        .equiv  SYNCSEL0, 0x0000

        .equiv  IC1CON2_SYNCSEL1, 0x0001
        .equiv  IC1CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  IC1CON2_SYNCSEL1_MASK, 0x0002
        .equiv  SYNCSEL1, 0x0001

        .equiv  IC1CON2_SYNCSEL2, 0x0002
        .equiv  IC1CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  IC1CON2_SYNCSEL2_MASK, 0x0004
        .equiv  SYNCSEL2, 0x0002

        .equiv  IC1CON2_SYNCSEL3, 0x0003
        .equiv  IC1CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  IC1CON2_SYNCSEL3_MASK, 0x0008
        .equiv  SYNCSEL3, 0x0003

        .equiv  IC1CON2_SYNCSEL4, 0x0004
        .equiv  IC1CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  IC1CON2_SYNCSEL4_MASK, 0x0010
        .equiv  SYNCSEL4, 0x0004

;----- IC2CON1 Bits -----------------------------------------------------
        .equiv  IC2CON1_ICM, 0x0000
        .equiv  IC2CON1_ICM_WIDTH, 0x0003
        .equiv  IC2CON1_ICM_MASK, 0x0007

        .equiv  IC2CON1_ICBNE, 0x0003
        .equiv  IC2CON1_ICBNE_WIDTH, 0x0001
        .equiv  IC2CON1_ICBNE_MASK, 0x0008

        .equiv  IC2CON1_ICOV, 0x0004
        .equiv  IC2CON1_ICOV_WIDTH, 0x0001
        .equiv  IC2CON1_ICOV_MASK, 0x0010

        .equiv  IC2CON1_ICI, 0x0005
        .equiv  IC2CON1_ICI_WIDTH, 0x0002
        .equiv  IC2CON1_ICI_MASK, 0x0060

        .equiv  IC2CON1_ICTSEL, 0x000A
        .equiv  IC2CON1_ICTSEL_WIDTH, 0x0003
        .equiv  IC2CON1_ICTSEL_MASK, 0x1C00

        .equiv  IC2CON1_ICSIDL, 0x000D
        .equiv  IC2CON1_ICSIDL_WIDTH, 0x0001
        .equiv  IC2CON1_ICSIDL_MASK, 0x2000

        .equiv  IC2CON1_ICM0, 0x0000
        .equiv  IC2CON1_ICM0_WIDTH, 0x0001
        .equiv  IC2CON1_ICM0_MASK, 0x0001

        .equiv  IC2CON1_ICM1, 0x0001
        .equiv  IC2CON1_ICM1_WIDTH, 0x0001
        .equiv  IC2CON1_ICM1_MASK, 0x0002

        .equiv  IC2CON1_ICM2, 0x0002
        .equiv  IC2CON1_ICM2_WIDTH, 0x0001
        .equiv  IC2CON1_ICM2_MASK, 0x0004

        .equiv  IC2CON1_ICI0, 0x0005
        .equiv  IC2CON1_ICI0_WIDTH, 0x0001
        .equiv  IC2CON1_ICI0_MASK, 0x0020

        .equiv  IC2CON1_ICI1, 0x0006
        .equiv  IC2CON1_ICI1_WIDTH, 0x0001
        .equiv  IC2CON1_ICI1_MASK, 0x0040

        .equiv  IC2CON1_ICTSEL0, 0x000A
        .equiv  IC2CON1_ICTSEL0_WIDTH, 0x0001
        .equiv  IC2CON1_ICTSEL0_MASK, 0x0400

        .equiv  IC2CON1_ICTSEL1, 0x000B
        .equiv  IC2CON1_ICTSEL1_WIDTH, 0x0001
        .equiv  IC2CON1_ICTSEL1_MASK, 0x0800

        .equiv  IC2CON1_ICTSEL2, 0x000C
        .equiv  IC2CON1_ICTSEL2_WIDTH, 0x0001
        .equiv  IC2CON1_ICTSEL2_MASK, 0x1000

;----- IC2CON2 Bits -----------------------------------------------------
        .equiv  IC2CON2_SYNCSEL, 0x0000
        .equiv  IC2CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  IC2CON2_SYNCSEL_MASK, 0x001F

        .equiv  IC2CON2_TRIGSTAT, 0x0006
        .equiv  IC2CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  IC2CON2_TRIGSTAT_MASK, 0x0040

        .equiv  IC2CON2_ICTRIG, 0x0007
        .equiv  IC2CON2_ICTRIG_WIDTH, 0x0001
        .equiv  IC2CON2_ICTRIG_MASK, 0x0080

        .equiv  IC2CON2_IC32, 0x0008
        .equiv  IC2CON2_IC32_WIDTH, 0x0001
        .equiv  IC2CON2_IC32_MASK, 0x0100

        .equiv  IC2CON2_SYNCSEL0, 0x0000
        .equiv  IC2CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  IC2CON2_SYNCSEL0_MASK, 0x0001

        .equiv  IC2CON2_SYNCSEL1, 0x0001
        .equiv  IC2CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  IC2CON2_SYNCSEL1_MASK, 0x0002

        .equiv  IC2CON2_SYNCSEL2, 0x0002
        .equiv  IC2CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  IC2CON2_SYNCSEL2_MASK, 0x0004

        .equiv  IC2CON2_SYNCSEL3, 0x0003
        .equiv  IC2CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  IC2CON2_SYNCSEL3_MASK, 0x0008

        .equiv  IC2CON2_SYNCSEL4, 0x0004
        .equiv  IC2CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  IC2CON2_SYNCSEL4_MASK, 0x0010

;----- IC3CON1 Bits -----------------------------------------------------
        .equiv  IC3CON1_ICM, 0x0000
        .equiv  IC3CON1_ICM_WIDTH, 0x0003
        .equiv  IC3CON1_ICM_MASK, 0x0007

        .equiv  IC3CON1_ICBNE, 0x0003
        .equiv  IC3CON1_ICBNE_WIDTH, 0x0001
        .equiv  IC3CON1_ICBNE_MASK, 0x0008

        .equiv  IC3CON1_ICOV, 0x0004
        .equiv  IC3CON1_ICOV_WIDTH, 0x0001
        .equiv  IC3CON1_ICOV_MASK, 0x0010

        .equiv  IC3CON1_ICI, 0x0005
        .equiv  IC3CON1_ICI_WIDTH, 0x0002
        .equiv  IC3CON1_ICI_MASK, 0x0060

        .equiv  IC3CON1_ICTSEL, 0x000A
        .equiv  IC3CON1_ICTSEL_WIDTH, 0x0003
        .equiv  IC3CON1_ICTSEL_MASK, 0x1C00

        .equiv  IC3CON1_ICSIDL, 0x000D
        .equiv  IC3CON1_ICSIDL_WIDTH, 0x0001
        .equiv  IC3CON1_ICSIDL_MASK, 0x2000

        .equiv  IC3CON1_ICM0, 0x0000
        .equiv  IC3CON1_ICM0_WIDTH, 0x0001
        .equiv  IC3CON1_ICM0_MASK, 0x0001

        .equiv  IC3CON1_ICM1, 0x0001
        .equiv  IC3CON1_ICM1_WIDTH, 0x0001
        .equiv  IC3CON1_ICM1_MASK, 0x0002

        .equiv  IC3CON1_ICM2, 0x0002
        .equiv  IC3CON1_ICM2_WIDTH, 0x0001
        .equiv  IC3CON1_ICM2_MASK, 0x0004

        .equiv  IC3CON1_ICI0, 0x0005
        .equiv  IC3CON1_ICI0_WIDTH, 0x0001
        .equiv  IC3CON1_ICI0_MASK, 0x0020

        .equiv  IC3CON1_ICI1, 0x0006
        .equiv  IC3CON1_ICI1_WIDTH, 0x0001
        .equiv  IC3CON1_ICI1_MASK, 0x0040

        .equiv  IC3CON1_ICTSEL0, 0x000A
        .equiv  IC3CON1_ICTSEL0_WIDTH, 0x0001
        .equiv  IC3CON1_ICTSEL0_MASK, 0x0400

        .equiv  IC3CON1_ICTSEL1, 0x000B
        .equiv  IC3CON1_ICTSEL1_WIDTH, 0x0001
        .equiv  IC3CON1_ICTSEL1_MASK, 0x0800

        .equiv  IC3CON1_ICTSEL2, 0x000C
        .equiv  IC3CON1_ICTSEL2_WIDTH, 0x0001
        .equiv  IC3CON1_ICTSEL2_MASK, 0x1000

;----- IC3CON2 Bits -----------------------------------------------------
        .equiv  IC3CON2_SYNCSEL, 0x0000
        .equiv  IC3CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  IC3CON2_SYNCSEL_MASK, 0x001F

        .equiv  IC3CON2_TRIGSTAT, 0x0006
        .equiv  IC3CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  IC3CON2_TRIGSTAT_MASK, 0x0040

        .equiv  IC3CON2_ICTRIG, 0x0007
        .equiv  IC3CON2_ICTRIG_WIDTH, 0x0001
        .equiv  IC3CON2_ICTRIG_MASK, 0x0080

        .equiv  IC3CON2_IC32, 0x0008
        .equiv  IC3CON2_IC32_WIDTH, 0x0001
        .equiv  IC3CON2_IC32_MASK, 0x0100

        .equiv  IC3CON2_SYNCSEL0, 0x0000
        .equiv  IC3CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  IC3CON2_SYNCSEL0_MASK, 0x0001

        .equiv  IC3CON2_SYNCSEL1, 0x0001
        .equiv  IC3CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  IC3CON2_SYNCSEL1_MASK, 0x0002

        .equiv  IC3CON2_SYNCSEL2, 0x0002
        .equiv  IC3CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  IC3CON2_SYNCSEL2_MASK, 0x0004

        .equiv  IC3CON2_SYNCSEL3, 0x0003
        .equiv  IC3CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  IC3CON2_SYNCSEL3_MASK, 0x0008

        .equiv  IC3CON2_SYNCSEL4, 0x0004
        .equiv  IC3CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  IC3CON2_SYNCSEL4_MASK, 0x0010

;----- IC4CON1 Bits -----------------------------------------------------
        .equiv  IC4CON1_ICM, 0x0000
        .equiv  IC4CON1_ICM_WIDTH, 0x0003
        .equiv  IC4CON1_ICM_MASK, 0x0007

        .equiv  IC4CON1_ICBNE, 0x0003
        .equiv  IC4CON1_ICBNE_WIDTH, 0x0001
        .equiv  IC4CON1_ICBNE_MASK, 0x0008

        .equiv  IC4CON1_ICOV, 0x0004
        .equiv  IC4CON1_ICOV_WIDTH, 0x0001
        .equiv  IC4CON1_ICOV_MASK, 0x0010

        .equiv  IC4CON1_ICI, 0x0005
        .equiv  IC4CON1_ICI_WIDTH, 0x0002
        .equiv  IC4CON1_ICI_MASK, 0x0060

        .equiv  IC4CON1_ICTSEL, 0x000A
        .equiv  IC4CON1_ICTSEL_WIDTH, 0x0003
        .equiv  IC4CON1_ICTSEL_MASK, 0x1C00

        .equiv  IC4CON1_ICSIDL, 0x000D
        .equiv  IC4CON1_ICSIDL_WIDTH, 0x0001
        .equiv  IC4CON1_ICSIDL_MASK, 0x2000

        .equiv  IC4CON1_ICM0, 0x0000
        .equiv  IC4CON1_ICM0_WIDTH, 0x0001
        .equiv  IC4CON1_ICM0_MASK, 0x0001

        .equiv  IC4CON1_ICM1, 0x0001
        .equiv  IC4CON1_ICM1_WIDTH, 0x0001
        .equiv  IC4CON1_ICM1_MASK, 0x0002

        .equiv  IC4CON1_ICM2, 0x0002
        .equiv  IC4CON1_ICM2_WIDTH, 0x0001
        .equiv  IC4CON1_ICM2_MASK, 0x0004

        .equiv  IC4CON1_ICI0, 0x0005
        .equiv  IC4CON1_ICI0_WIDTH, 0x0001
        .equiv  IC4CON1_ICI0_MASK, 0x0020

        .equiv  IC4CON1_ICI1, 0x0006
        .equiv  IC4CON1_ICI1_WIDTH, 0x0001
        .equiv  IC4CON1_ICI1_MASK, 0x0040

        .equiv  IC4CON1_ICTSEL0, 0x000A
        .equiv  IC4CON1_ICTSEL0_WIDTH, 0x0001
        .equiv  IC4CON1_ICTSEL0_MASK, 0x0400

        .equiv  IC4CON1_ICTSEL1, 0x000B
        .equiv  IC4CON1_ICTSEL1_WIDTH, 0x0001
        .equiv  IC4CON1_ICTSEL1_MASK, 0x0800

        .equiv  IC4CON1_ICTSEL2, 0x000C
        .equiv  IC4CON1_ICTSEL2_WIDTH, 0x0001
        .equiv  IC4CON1_ICTSEL2_MASK, 0x1000

;----- IC4CON2 Bits -----------------------------------------------------
        .equiv  IC4CON2_SYNCSEL, 0x0000
        .equiv  IC4CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  IC4CON2_SYNCSEL_MASK, 0x001F

        .equiv  IC4CON2_TRIGSTAT, 0x0006
        .equiv  IC4CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  IC4CON2_TRIGSTAT_MASK, 0x0040

        .equiv  IC4CON2_ICTRIG, 0x0007
        .equiv  IC4CON2_ICTRIG_WIDTH, 0x0001
        .equiv  IC4CON2_ICTRIG_MASK, 0x0080

        .equiv  IC4CON2_IC32, 0x0008
        .equiv  IC4CON2_IC32_WIDTH, 0x0001
        .equiv  IC4CON2_IC32_MASK, 0x0100

        .equiv  IC4CON2_SYNCSEL0, 0x0000
        .equiv  IC4CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  IC4CON2_SYNCSEL0_MASK, 0x0001

        .equiv  IC4CON2_SYNCSEL1, 0x0001
        .equiv  IC4CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  IC4CON2_SYNCSEL1_MASK, 0x0002

        .equiv  IC4CON2_SYNCSEL2, 0x0002
        .equiv  IC4CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  IC4CON2_SYNCSEL2_MASK, 0x0004

        .equiv  IC4CON2_SYNCSEL3, 0x0003
        .equiv  IC4CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  IC4CON2_SYNCSEL3_MASK, 0x0008

        .equiv  IC4CON2_SYNCSEL4, 0x0004
        .equiv  IC4CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  IC4CON2_SYNCSEL4_MASK, 0x0010

;----- QEI1CON Bits -----------------------------------------------------
        .equiv  QEI1CON_CCM, 0x0000
        .equiv  QEI1CON_CCM_WIDTH, 0x0002
        .equiv  QEI1CON_CCM_MASK, 0x0003

        .equiv  QEI1CON_GATEN, 0x0002
        .equiv  QEI1CON_GATEN_WIDTH, 0x0001
        .equiv  QEI1CON_GATEN_MASK, 0x0004
        .equiv  GATEN, 0x0002

        .equiv  QEI1CON_CNTPOL, 0x0003
        .equiv  QEI1CON_CNTPOL_WIDTH, 0x0001
        .equiv  QEI1CON_CNTPOL_MASK, 0x0008
        .equiv  CNTPOL, 0x0003

        .equiv  QEI1CON_INTDIV, 0x0004
        .equiv  QEI1CON_INTDIV_WIDTH, 0x0003
        .equiv  QEI1CON_INTDIV_MASK, 0x0070

        .equiv  QEI1CON_IMV, 0x0008
        .equiv  QEI1CON_IMV_WIDTH, 0x0002
        .equiv  QEI1CON_IMV_MASK, 0x0300

        .equiv  QEI1CON_PIMOD, 0x000A
        .equiv  QEI1CON_PIMOD_WIDTH, 0x0003
        .equiv  QEI1CON_PIMOD_MASK, 0x1C00

        .equiv  QEI1CON_QEISIDL, 0x000D
        .equiv  QEI1CON_QEISIDL_WIDTH, 0x0001
        .equiv  QEI1CON_QEISIDL_MASK, 0x2000
        .equiv  QEISIDL, 0x000D

        .equiv  QEI1CON_QEIEN, 0x000F
        .equiv  QEI1CON_QEIEN_WIDTH, 0x0001
        .equiv  QEI1CON_QEIEN_MASK, 0x8000
        .equiv  QEIEN, 0x000F

;----- QEI1IOC Bits -----------------------------------------------------
        .equiv  QEI1IOC_QEA, 0x0000
        .equiv  QEI1IOC_QEA_WIDTH, 0x0001
        .equiv  QEI1IOC_QEA_MASK, 0x0001
        .equiv  QEA, 0x0000

        .equiv  QEI1IOC_QEB, 0x0001
        .equiv  QEI1IOC_QEB_WIDTH, 0x0001
        .equiv  QEI1IOC_QEB_MASK, 0x0002
        .equiv  QEB, 0x0001

        .equiv  QEI1IOC_INDEX, 0x0002
        .equiv  QEI1IOC_INDEX_WIDTH, 0x0001
        .equiv  QEI1IOC_INDEX_MASK, 0x0004
        .equiv  INDEX, 0x0002

        .equiv  QEI1IOC_HOME, 0x0003
        .equiv  QEI1IOC_HOME_WIDTH, 0x0001
        .equiv  QEI1IOC_HOME_MASK, 0x0008
        .equiv  HOME, 0x0003

        .equiv  QEI1IOC_QEAPOL, 0x0004
        .equiv  QEI1IOC_QEAPOL_WIDTH, 0x0001
        .equiv  QEI1IOC_QEAPOL_MASK, 0x0010
        .equiv  QEAPOL, 0x0004

        .equiv  QEI1IOC_QEBPOL, 0x0005
        .equiv  QEI1IOC_QEBPOL_WIDTH, 0x0001
        .equiv  QEI1IOC_QEBPOL_MASK, 0x0020
        .equiv  QEBPOL, 0x0005

        .equiv  QEI1IOC_IDXPOL, 0x0006
        .equiv  QEI1IOC_IDXPOL_WIDTH, 0x0001
        .equiv  QEI1IOC_IDXPOL_MASK, 0x0040
        .equiv  IDXPOL, 0x0006

        .equiv  QEI1IOC_HOMPOL, 0x0007
        .equiv  QEI1IOC_HOMPOL_WIDTH, 0x0001
        .equiv  QEI1IOC_HOMPOL_MASK, 0x0080
        .equiv  HOMPOL, 0x0007

        .equiv  QEI1IOC_SWPAB, 0x0008
        .equiv  QEI1IOC_SWPAB_WIDTH, 0x0001
        .equiv  QEI1IOC_SWPAB_MASK, 0x0100
        .equiv  SWPAB, 0x0008

        .equiv  QEI1IOC_OUTFNC, 0x0009
        .equiv  QEI1IOC_OUTFNC_WIDTH, 0x0002
        .equiv  QEI1IOC_OUTFNC_MASK, 0x0600

        .equiv  QEI1IOC_QFDIV, 0x000B
        .equiv  QEI1IOC_QFDIV_WIDTH, 0x0003
        .equiv  QEI1IOC_QFDIV_MASK, 0x3800

        .equiv  QEI1IOC_FLTREN, 0x000E
        .equiv  QEI1IOC_FLTREN_WIDTH, 0x0001
        .equiv  QEI1IOC_FLTREN_MASK, 0x4000
        .equiv  FLTREN, 0x000E

        .equiv  QEI1IOC_QCAPEN, 0x000F
        .equiv  QEI1IOC_QCAPEN_WIDTH, 0x0001
        .equiv  QEI1IOC_QCAPEN_MASK, 0x8000
        .equiv  QCAPEN, 0x000F

;----- QEI1STAT Bits -----------------------------------------------------
        .equiv  QEI1STAT_IDXIEN, 0x0000
        .equiv  QEI1STAT_IDXIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_IDXIEN_MASK, 0x0001
        .equiv  IDXIEN, 0x0000

        .equiv  QEI1STAT_IDXIRQ, 0x0001
        .equiv  QEI1STAT_IDXIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_IDXIRQ_MASK, 0x0002
        .equiv  IDXIRQ, 0x0001

        .equiv  QEI1STAT_HOMIEN, 0x0002
        .equiv  QEI1STAT_HOMIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_HOMIEN_MASK, 0x0004
        .equiv  HOMIEN, 0x0002

        .equiv  QEI1STAT_HOMIRQ, 0x0003
        .equiv  QEI1STAT_HOMIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_HOMIRQ_MASK, 0x0008
        .equiv  HOMIRQ, 0x0003

        .equiv  QEI1STAT_VELOVIEN, 0x0004
        .equiv  QEI1STAT_VELOVIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_VELOVIEN_MASK, 0x0010
        .equiv  VELOVIEN, 0x0004

        .equiv  QEI1STAT_VELOVIRQ, 0x0005
        .equiv  QEI1STAT_VELOVIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_VELOVIRQ_MASK, 0x0020
        .equiv  VELOVIRQ, 0x0005

        .equiv  QEI1STAT_PCIIEN, 0x0006
        .equiv  QEI1STAT_PCIIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_PCIIEN_MASK, 0x0040
        .equiv  PCIIEN, 0x0006

        .equiv  QEI1STAT_PCIIRQ, 0x0007
        .equiv  QEI1STAT_PCIIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_PCIIRQ_MASK, 0x0080
        .equiv  PCIIRQ, 0x0007

        .equiv  QEI1STAT_POSOVIEN, 0x0008
        .equiv  QEI1STAT_POSOVIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_POSOVIEN_MASK, 0x0100
        .equiv  POSOVIEN, 0x0008

        .equiv  QEI1STAT_POSOVIRQ, 0x0009
        .equiv  QEI1STAT_POSOVIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_POSOVIRQ_MASK, 0x0200
        .equiv  POSOVIRQ, 0x0009

        .equiv  QEI1STAT_PCLEQIEN, 0x000A
        .equiv  QEI1STAT_PCLEQIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_PCLEQIEN_MASK, 0x0400
        .equiv  PCLEQIEN, 0x000A

        .equiv  QEI1STAT_PCLEQIRQ, 0x000B
        .equiv  QEI1STAT_PCLEQIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_PCLEQIRQ_MASK, 0x0800
        .equiv  PCLEQIRQ, 0x000B

        .equiv  QEI1STAT_PCHEQIEN, 0x000C
        .equiv  QEI1STAT_PCHEQIEN_WIDTH, 0x0001
        .equiv  QEI1STAT_PCHEQIEN_MASK, 0x1000
        .equiv  PCHEQIEN, 0x000C

        .equiv  QEI1STAT_PCHEQIRQ, 0x000D
        .equiv  QEI1STAT_PCHEQIRQ_WIDTH, 0x0001
        .equiv  QEI1STAT_PCHEQIRQ_MASK, 0x2000
        .equiv  PCHEQIRQ, 0x000D

;----- I2C1CON Bits -----------------------------------------------------
        .equiv  I2C1CON_SEN, 0x0000
        .equiv  I2C1CON_SEN_WIDTH, 0x0001
        .equiv  I2C1CON_SEN_MASK, 0x0001
        .equiv  SEN, 0x0000

        .equiv  I2C1CON_RSEN, 0x0001
        .equiv  I2C1CON_RSEN_WIDTH, 0x0001
        .equiv  I2C1CON_RSEN_MASK, 0x0002
        .equiv  RSEN, 0x0001

        .equiv  I2C1CON_PEN, 0x0002
        .equiv  I2C1CON_PEN_WIDTH, 0x0001
        .equiv  I2C1CON_PEN_MASK, 0x0004
        .equiv  PEN, 0x0002

        .equiv  I2C1CON_RCEN, 0x0003
        .equiv  I2C1CON_RCEN_WIDTH, 0x0001
        .equiv  I2C1CON_RCEN_MASK, 0x0008
        .equiv  RCEN, 0x0003

        .equiv  I2C1CON_ACKEN, 0x0004
        .equiv  I2C1CON_ACKEN_WIDTH, 0x0001
        .equiv  I2C1CON_ACKEN_MASK, 0x0010
        .equiv  ACKEN, 0x0004

        .equiv  I2C1CON_ACKDT, 0x0005
        .equiv  I2C1CON_ACKDT_WIDTH, 0x0001
        .equiv  I2C1CON_ACKDT_MASK, 0x0020
        .equiv  ACKDT, 0x0005

        .equiv  I2C1CON_STREN, 0x0006
        .equiv  I2C1CON_STREN_WIDTH, 0x0001
        .equiv  I2C1CON_STREN_MASK, 0x0040
        .equiv  STREN, 0x0006

        .equiv  I2C1CON_GCEN, 0x0007
        .equiv  I2C1CON_GCEN_WIDTH, 0x0001
        .equiv  I2C1CON_GCEN_MASK, 0x0080
        .equiv  GCEN, 0x0007

        .equiv  I2C1CON_SMEN, 0x0008
        .equiv  I2C1CON_SMEN_WIDTH, 0x0001
        .equiv  I2C1CON_SMEN_MASK, 0x0100
        .equiv  SMEN, 0x0008

        .equiv  I2C1CON_DISSLW, 0x0009
        .equiv  I2C1CON_DISSLW_WIDTH, 0x0001
        .equiv  I2C1CON_DISSLW_MASK, 0x0200
        .equiv  DISSLW, 0x0009

        .equiv  I2C1CON_A10M, 0x000A
        .equiv  I2C1CON_A10M_WIDTH, 0x0001
        .equiv  I2C1CON_A10M_MASK, 0x0400
        .equiv  A10M, 0x000A

        .equiv  I2C1CON_IPMIEN, 0x000B
        .equiv  I2C1CON_IPMIEN_WIDTH, 0x0001
        .equiv  I2C1CON_IPMIEN_MASK, 0x0800
        .equiv  IPMIEN, 0x000B

        .equiv  I2C1CON_SCLREL, 0x000C
        .equiv  I2C1CON_SCLREL_WIDTH, 0x0001
        .equiv  I2C1CON_SCLREL_MASK, 0x1000
        .equiv  SCLREL, 0x000C

        .equiv  I2C1CON_I2CSIDL, 0x000D
        .equiv  I2C1CON_I2CSIDL_WIDTH, 0x0001
        .equiv  I2C1CON_I2CSIDL_MASK, 0x2000
        .equiv  I2CSIDL, 0x000D

        .equiv  I2C1CON_I2CEN, 0x000F
        .equiv  I2C1CON_I2CEN_WIDTH, 0x0001
        .equiv  I2C1CON_I2CEN_MASK, 0x8000
        .equiv  I2CEN, 0x000F

;----- I2C1STAT Bits -----------------------------------------------------
        .equiv  I2C1STAT_TBF, 0x0000
        .equiv  I2C1STAT_TBF_WIDTH, 0x0001
        .equiv  I2C1STAT_TBF_MASK, 0x0001
        .equiv  TBF, 0x0000

        .equiv  I2C1STAT_RBF, 0x0001
        .equiv  I2C1STAT_RBF_WIDTH, 0x0001
        .equiv  I2C1STAT_RBF_MASK, 0x0002
        .equiv  RBF, 0x0001

        .equiv  I2C1STAT_R_W, 0x0002
        .equiv  I2C1STAT_R_W_WIDTH, 0x0001
        .equiv  I2C1STAT_R_W_MASK, 0x0004
        .equiv  R_W, 0x0002

        .equiv  I2C1STAT_S, 0x0003
        .equiv  I2C1STAT_S_WIDTH, 0x0001
        .equiv  I2C1STAT_S_MASK, 0x0008
        .equiv  S, 0x0003

        .equiv  I2C1STAT_P, 0x0004
        .equiv  I2C1STAT_P_WIDTH, 0x0001
        .equiv  I2C1STAT_P_MASK, 0x0010
        .equiv  P, 0x0004

        .equiv  I2C1STAT_D_A, 0x0005
        .equiv  I2C1STAT_D_A_WIDTH, 0x0001
        .equiv  I2C1STAT_D_A_MASK, 0x0020
        .equiv  D_A, 0x0005

        .equiv  I2C1STAT_I2COV, 0x0006
        .equiv  I2C1STAT_I2COV_WIDTH, 0x0001
        .equiv  I2C1STAT_I2COV_MASK, 0x0040
        .equiv  I2COV, 0x0006

        .equiv  I2C1STAT_IWCOL, 0x0007
        .equiv  I2C1STAT_IWCOL_WIDTH, 0x0001
        .equiv  I2C1STAT_IWCOL_MASK, 0x0080
        .equiv  IWCOL, 0x0007

        .equiv  I2C1STAT_ADD10, 0x0008
        .equiv  I2C1STAT_ADD10_WIDTH, 0x0001
        .equiv  I2C1STAT_ADD10_MASK, 0x0100
        .equiv  ADD10, 0x0008

        .equiv  I2C1STAT_GCSTAT, 0x0009
        .equiv  I2C1STAT_GCSTAT_WIDTH, 0x0001
        .equiv  I2C1STAT_GCSTAT_MASK, 0x0200
        .equiv  GCSTAT, 0x0009

        .equiv  I2C1STAT_BCL_I2C1STAT, 0x000A
        .equiv  I2C1STAT_BCL_I2C1STAT_WIDTH, 0x0001
        .equiv  I2C1STAT_BCL_I2C1STAT_MASK, 0x0400
        .equiv  BCL_I2C1STAT, 0x000A

        .equiv  I2C1STAT_TRSTAT, 0x000E
        .equiv  I2C1STAT_TRSTAT_WIDTH, 0x0001
        .equiv  I2C1STAT_TRSTAT_MASK, 0x4000
        .equiv  TRSTAT, 0x000E

        .equiv  I2C1STAT_ACKSTAT, 0x000F
        .equiv  I2C1STAT_ACKSTAT_WIDTH, 0x0001
        .equiv  I2C1STAT_ACKSTAT_MASK, 0x8000
        .equiv  ACKSTAT, 0x000F

;----- I2C2CON Bits -----------------------------------------------------
        .equiv  I2C2CON_SEN, 0x0000
        .equiv  I2C2CON_SEN_WIDTH, 0x0001
        .equiv  I2C2CON_SEN_MASK, 0x0001

        .equiv  I2C2CON_RSEN, 0x0001
        .equiv  I2C2CON_RSEN_WIDTH, 0x0001
        .equiv  I2C2CON_RSEN_MASK, 0x0002

        .equiv  I2C2CON_PEN, 0x0002
        .equiv  I2C2CON_PEN_WIDTH, 0x0001
        .equiv  I2C2CON_PEN_MASK, 0x0004

        .equiv  I2C2CON_RCEN, 0x0003
        .equiv  I2C2CON_RCEN_WIDTH, 0x0001
        .equiv  I2C2CON_RCEN_MASK, 0x0008

        .equiv  I2C2CON_ACKEN, 0x0004
        .equiv  I2C2CON_ACKEN_WIDTH, 0x0001
        .equiv  I2C2CON_ACKEN_MASK, 0x0010

        .equiv  I2C2CON_ACKDT, 0x0005
        .equiv  I2C2CON_ACKDT_WIDTH, 0x0001
        .equiv  I2C2CON_ACKDT_MASK, 0x0020

        .equiv  I2C2CON_STREN, 0x0006
        .equiv  I2C2CON_STREN_WIDTH, 0x0001
        .equiv  I2C2CON_STREN_MASK, 0x0040

        .equiv  I2C2CON_GCEN, 0x0007
        .equiv  I2C2CON_GCEN_WIDTH, 0x0001
        .equiv  I2C2CON_GCEN_MASK, 0x0080

        .equiv  I2C2CON_SMEN, 0x0008
        .equiv  I2C2CON_SMEN_WIDTH, 0x0001
        .equiv  I2C2CON_SMEN_MASK, 0x0100

        .equiv  I2C2CON_DISSLW, 0x0009
        .equiv  I2C2CON_DISSLW_WIDTH, 0x0001
        .equiv  I2C2CON_DISSLW_MASK, 0x0200

        .equiv  I2C2CON_A10M, 0x000A
        .equiv  I2C2CON_A10M_WIDTH, 0x0001
        .equiv  I2C2CON_A10M_MASK, 0x0400

        .equiv  I2C2CON_IPMIEN, 0x000B
        .equiv  I2C2CON_IPMIEN_WIDTH, 0x0001
        .equiv  I2C2CON_IPMIEN_MASK, 0x0800

        .equiv  I2C2CON_SCLREL, 0x000C
        .equiv  I2C2CON_SCLREL_WIDTH, 0x0001
        .equiv  I2C2CON_SCLREL_MASK, 0x1000

        .equiv  I2C2CON_I2CSIDL, 0x000D
        .equiv  I2C2CON_I2CSIDL_WIDTH, 0x0001
        .equiv  I2C2CON_I2CSIDL_MASK, 0x2000

        .equiv  I2C2CON_I2CEN, 0x000F
        .equiv  I2C2CON_I2CEN_WIDTH, 0x0001
        .equiv  I2C2CON_I2CEN_MASK, 0x8000

;----- I2C2STAT Bits -----------------------------------------------------
        .equiv  I2C2STAT_TBF, 0x0000
        .equiv  I2C2STAT_TBF_WIDTH, 0x0001
        .equiv  I2C2STAT_TBF_MASK, 0x0001

        .equiv  I2C2STAT_RBF, 0x0001
        .equiv  I2C2STAT_RBF_WIDTH, 0x0001
        .equiv  I2C2STAT_RBF_MASK, 0x0002

        .equiv  I2C2STAT_R_W, 0x0002
        .equiv  I2C2STAT_R_W_WIDTH, 0x0001
        .equiv  I2C2STAT_R_W_MASK, 0x0004

        .equiv  I2C2STAT_S, 0x0003
        .equiv  I2C2STAT_S_WIDTH, 0x0001
        .equiv  I2C2STAT_S_MASK, 0x0008

        .equiv  I2C2STAT_P, 0x0004
        .equiv  I2C2STAT_P_WIDTH, 0x0001
        .equiv  I2C2STAT_P_MASK, 0x0010

        .equiv  I2C2STAT_D_A, 0x0005
        .equiv  I2C2STAT_D_A_WIDTH, 0x0001
        .equiv  I2C2STAT_D_A_MASK, 0x0020

        .equiv  I2C2STAT_I2COV, 0x0006
        .equiv  I2C2STAT_I2COV_WIDTH, 0x0001
        .equiv  I2C2STAT_I2COV_MASK, 0x0040

        .equiv  I2C2STAT_IWCOL, 0x0007
        .equiv  I2C2STAT_IWCOL_WIDTH, 0x0001
        .equiv  I2C2STAT_IWCOL_MASK, 0x0080

        .equiv  I2C2STAT_ADD10, 0x0008
        .equiv  I2C2STAT_ADD10_WIDTH, 0x0001
        .equiv  I2C2STAT_ADD10_MASK, 0x0100

        .equiv  I2C2STAT_GCSTAT, 0x0009
        .equiv  I2C2STAT_GCSTAT_WIDTH, 0x0001
        .equiv  I2C2STAT_GCSTAT_MASK, 0x0200

        .equiv  I2C2STAT_BCL_I2C2STAT, 0x000A
        .equiv  I2C2STAT_BCL_I2C2STAT_WIDTH, 0x0001
        .equiv  I2C2STAT_BCL_I2C2STAT_MASK, 0x0400
        .equiv  BCL_I2C2STAT, 0x000A

        .equiv  I2C2STAT_TRSTAT, 0x000E
        .equiv  I2C2STAT_TRSTAT_WIDTH, 0x0001
        .equiv  I2C2STAT_TRSTAT_MASK, 0x4000

        .equiv  I2C2STAT_ACKSTAT, 0x000F
        .equiv  I2C2STAT_ACKSTAT_WIDTH, 0x0001
        .equiv  I2C2STAT_ACKSTAT_MASK, 0x8000

;----- U1MODE Bits -----------------------------------------------------
        .equiv  U1MODE_STSEL, 0x0000
        .equiv  U1MODE_STSEL_WIDTH, 0x0001
        .equiv  U1MODE_STSEL_MASK, 0x0001
        .equiv  STSEL, 0x0000

        .equiv  U1MODE_PDSEL, 0x0001
        .equiv  U1MODE_PDSEL_WIDTH, 0x0002
        .equiv  U1MODE_PDSEL_MASK, 0x0006

        .equiv  U1MODE_BRGH, 0x0003
        .equiv  U1MODE_BRGH_WIDTH, 0x0001
        .equiv  U1MODE_BRGH_MASK, 0x0008
        .equiv  BRGH, 0x0003

        .equiv  U1MODE_URXINV, 0x0004
        .equiv  U1MODE_URXINV_WIDTH, 0x0001
        .equiv  U1MODE_URXINV_MASK, 0x0010
        .equiv  URXINV, 0x0004

        .equiv  U1MODE_ABAUD, 0x0005
        .equiv  U1MODE_ABAUD_WIDTH, 0x0001
        .equiv  U1MODE_ABAUD_MASK, 0x0020
        .equiv  ABAUD, 0x0005

        .equiv  U1MODE_LPBACK, 0x0006
        .equiv  U1MODE_LPBACK_WIDTH, 0x0001
        .equiv  U1MODE_LPBACK_MASK, 0x0040
        .equiv  LPBACK, 0x0006

        .equiv  U1MODE_WAKE, 0x0007
        .equiv  U1MODE_WAKE_WIDTH, 0x0001
        .equiv  U1MODE_WAKE_MASK, 0x0080
        .equiv  WAKE, 0x0007

        .equiv  U1MODE_UEN, 0x0008
        .equiv  U1MODE_UEN_WIDTH, 0x0002
        .equiv  U1MODE_UEN_MASK, 0x0300

        .equiv  U1MODE_RTSMD, 0x000B
        .equiv  U1MODE_RTSMD_WIDTH, 0x0001
        .equiv  U1MODE_RTSMD_MASK, 0x0800
        .equiv  RTSMD, 0x000B

        .equiv  U1MODE_IREN, 0x000C
        .equiv  U1MODE_IREN_WIDTH, 0x0001
        .equiv  U1MODE_IREN_MASK, 0x1000
        .equiv  IREN, 0x000C

        .equiv  U1MODE_USIDL, 0x000D
        .equiv  U1MODE_USIDL_WIDTH, 0x0001
        .equiv  U1MODE_USIDL_MASK, 0x2000
        .equiv  USIDL, 0x000D

        .equiv  U1MODE_UARTEN, 0x000F
        .equiv  U1MODE_UARTEN_WIDTH, 0x0001
        .equiv  U1MODE_UARTEN_MASK, 0x8000
        .equiv  UARTEN, 0x000F

        .equiv  U1MODE_PDSEL0, 0x0001
        .equiv  U1MODE_PDSEL0_WIDTH, 0x0001
        .equiv  U1MODE_PDSEL0_MASK, 0x0002
        .equiv  PDSEL0, 0x0001

        .equiv  U1MODE_PDSEL1, 0x0002
        .equiv  U1MODE_PDSEL1_WIDTH, 0x0001
        .equiv  U1MODE_PDSEL1_MASK, 0x0004
        .equiv  PDSEL1, 0x0002

        .equiv  U1MODE_RXINV, 0x0004
        .equiv  U1MODE_RXINV_WIDTH, 0x0001
        .equiv  U1MODE_RXINV_MASK, 0x0010
        .equiv  RXINV, 0x0004

        .equiv  U1MODE_UEN0, 0x0008
        .equiv  U1MODE_UEN0_WIDTH, 0x0001
        .equiv  U1MODE_UEN0_MASK, 0x0100
        .equiv  UEN0, 0x0008

        .equiv  U1MODE_UEN1, 0x0009
        .equiv  U1MODE_UEN1_WIDTH, 0x0001
        .equiv  U1MODE_UEN1_MASK, 0x0200
        .equiv  UEN1, 0x0009

;----- U1STA Bits -----------------------------------------------------
        .equiv  U1STA_URXDA, 0x0000
        .equiv  U1STA_URXDA_WIDTH, 0x0001
        .equiv  U1STA_URXDA_MASK, 0x0001
        .equiv  URXDA, 0x0000

        .equiv  U1STA_OERR, 0x0001
        .equiv  U1STA_OERR_WIDTH, 0x0001
        .equiv  U1STA_OERR_MASK, 0x0002
        .equiv  OERR, 0x0001

        .equiv  U1STA_FERR, 0x0002
        .equiv  U1STA_FERR_WIDTH, 0x0001
        .equiv  U1STA_FERR_MASK, 0x0004
        .equiv  FERR, 0x0002

        .equiv  U1STA_PERR, 0x0003
        .equiv  U1STA_PERR_WIDTH, 0x0001
        .equiv  U1STA_PERR_MASK, 0x0008
        .equiv  PERR, 0x0003

        .equiv  U1STA_RIDLE, 0x0004
        .equiv  U1STA_RIDLE_WIDTH, 0x0001
        .equiv  U1STA_RIDLE_MASK, 0x0010
        .equiv  RIDLE, 0x0004

        .equiv  U1STA_ADDEN, 0x0005
        .equiv  U1STA_ADDEN_WIDTH, 0x0001
        .equiv  U1STA_ADDEN_MASK, 0x0020
        .equiv  ADDEN, 0x0005

        .equiv  U1STA_URXISEL, 0x0006
        .equiv  U1STA_URXISEL_WIDTH, 0x0002
        .equiv  U1STA_URXISEL_MASK, 0x00C0

        .equiv  U1STA_TRMT, 0x0008
        .equiv  U1STA_TRMT_WIDTH, 0x0001
        .equiv  U1STA_TRMT_MASK, 0x0100
        .equiv  TRMT, 0x0008

        .equiv  U1STA_UTXBF, 0x0009
        .equiv  U1STA_UTXBF_WIDTH, 0x0001
        .equiv  U1STA_UTXBF_MASK, 0x0200
        .equiv  UTXBF, 0x0009

        .equiv  U1STA_UTXEN, 0x000A
        .equiv  U1STA_UTXEN_WIDTH, 0x0001
        .equiv  U1STA_UTXEN_MASK, 0x0400
        .equiv  UTXEN, 0x000A

        .equiv  U1STA_UTXBRK, 0x000B
        .equiv  U1STA_UTXBRK_WIDTH, 0x0001
        .equiv  U1STA_UTXBRK_MASK, 0x0800
        .equiv  UTXBRK, 0x000B

        .equiv  U1STA_UTXISEL0, 0x000D
        .equiv  U1STA_UTXISEL0_WIDTH, 0x0001
        .equiv  U1STA_UTXISEL0_MASK, 0x2000
        .equiv  UTXISEL0, 0x000D

        .equiv  U1STA_UTXINV, 0x000E
        .equiv  U1STA_UTXINV_WIDTH, 0x0001
        .equiv  U1STA_UTXINV_MASK, 0x4000
        .equiv  UTXINV, 0x000E

        .equiv  U1STA_UTXISEL1, 0x000F
        .equiv  U1STA_UTXISEL1_WIDTH, 0x0001
        .equiv  U1STA_UTXISEL1_MASK, 0x8000
        .equiv  UTXISEL1, 0x000F

        .equiv  U1STA_URXISEL0, 0x0006
        .equiv  U1STA_URXISEL0_WIDTH, 0x0001
        .equiv  U1STA_URXISEL0_MASK, 0x0040
        .equiv  URXISEL0, 0x0006

        .equiv  U1STA_URXISEL1, 0x0007
        .equiv  U1STA_URXISEL1_WIDTH, 0x0001
        .equiv  U1STA_URXISEL1_MASK, 0x0080
        .equiv  URXISEL1, 0x0007

        .equiv  U1STA_TXINV, 0x000E
        .equiv  U1STA_TXINV_WIDTH, 0x0001
        .equiv  U1STA_TXINV_MASK, 0x4000
        .equiv  TXINV, 0x000E

;----- U2MODE Bits -----------------------------------------------------
        .equiv  U2MODE_STSEL, 0x0000
        .equiv  U2MODE_STSEL_WIDTH, 0x0001
        .equiv  U2MODE_STSEL_MASK, 0x0001

        .equiv  U2MODE_PDSEL, 0x0001
        .equiv  U2MODE_PDSEL_WIDTH, 0x0002
        .equiv  U2MODE_PDSEL_MASK, 0x0006

        .equiv  U2MODE_BRGH, 0x0003
        .equiv  U2MODE_BRGH_WIDTH, 0x0001
        .equiv  U2MODE_BRGH_MASK, 0x0008

        .equiv  U2MODE_URXINV, 0x0004
        .equiv  U2MODE_URXINV_WIDTH, 0x0001
        .equiv  U2MODE_URXINV_MASK, 0x0010

        .equiv  U2MODE_ABAUD, 0x0005
        .equiv  U2MODE_ABAUD_WIDTH, 0x0001
        .equiv  U2MODE_ABAUD_MASK, 0x0020

        .equiv  U2MODE_LPBACK, 0x0006
        .equiv  U2MODE_LPBACK_WIDTH, 0x0001
        .equiv  U2MODE_LPBACK_MASK, 0x0040

        .equiv  U2MODE_WAKE, 0x0007
        .equiv  U2MODE_WAKE_WIDTH, 0x0001
        .equiv  U2MODE_WAKE_MASK, 0x0080

        .equiv  U2MODE_UEN, 0x0008
        .equiv  U2MODE_UEN_WIDTH, 0x0002
        .equiv  U2MODE_UEN_MASK, 0x0300

        .equiv  U2MODE_RTSMD, 0x000B
        .equiv  U2MODE_RTSMD_WIDTH, 0x0001
        .equiv  U2MODE_RTSMD_MASK, 0x0800

        .equiv  U2MODE_IREN, 0x000C
        .equiv  U2MODE_IREN_WIDTH, 0x0001
        .equiv  U2MODE_IREN_MASK, 0x1000

        .equiv  U2MODE_USIDL, 0x000D
        .equiv  U2MODE_USIDL_WIDTH, 0x0001
        .equiv  U2MODE_USIDL_MASK, 0x2000

        .equiv  U2MODE_UARTEN, 0x000F
        .equiv  U2MODE_UARTEN_WIDTH, 0x0001
        .equiv  U2MODE_UARTEN_MASK, 0x8000

        .equiv  U2MODE_PDSEL0, 0x0001
        .equiv  U2MODE_PDSEL0_WIDTH, 0x0001
        .equiv  U2MODE_PDSEL0_MASK, 0x0002

        .equiv  U2MODE_PDSEL1, 0x0002
        .equiv  U2MODE_PDSEL1_WIDTH, 0x0001
        .equiv  U2MODE_PDSEL1_MASK, 0x0004

        .equiv  U2MODE_RXINV, 0x0004
        .equiv  U2MODE_RXINV_WIDTH, 0x0001
        .equiv  U2MODE_RXINV_MASK, 0x0010

        .equiv  U2MODE_UEN0, 0x0008
        .equiv  U2MODE_UEN0_WIDTH, 0x0001
        .equiv  U2MODE_UEN0_MASK, 0x0100

        .equiv  U2MODE_UEN1, 0x0009
        .equiv  U2MODE_UEN1_WIDTH, 0x0001
        .equiv  U2MODE_UEN1_MASK, 0x0200

;----- U2STA Bits -----------------------------------------------------
        .equiv  U2STA_URXDA, 0x0000
        .equiv  U2STA_URXDA_WIDTH, 0x0001
        .equiv  U2STA_URXDA_MASK, 0x0001

        .equiv  U2STA_OERR, 0x0001
        .equiv  U2STA_OERR_WIDTH, 0x0001
        .equiv  U2STA_OERR_MASK, 0x0002

        .equiv  U2STA_FERR, 0x0002
        .equiv  U2STA_FERR_WIDTH, 0x0001
        .equiv  U2STA_FERR_MASK, 0x0004

        .equiv  U2STA_PERR, 0x0003
        .equiv  U2STA_PERR_WIDTH, 0x0001
        .equiv  U2STA_PERR_MASK, 0x0008

        .equiv  U2STA_RIDLE, 0x0004
        .equiv  U2STA_RIDLE_WIDTH, 0x0001
        .equiv  U2STA_RIDLE_MASK, 0x0010

        .equiv  U2STA_ADDEN, 0x0005
        .equiv  U2STA_ADDEN_WIDTH, 0x0001
        .equiv  U2STA_ADDEN_MASK, 0x0020

        .equiv  U2STA_URXISEL, 0x0006
        .equiv  U2STA_URXISEL_WIDTH, 0x0002
        .equiv  U2STA_URXISEL_MASK, 0x00C0

        .equiv  U2STA_TRMT, 0x0008
        .equiv  U2STA_TRMT_WIDTH, 0x0001
        .equiv  U2STA_TRMT_MASK, 0x0100

        .equiv  U2STA_UTXBF, 0x0009
        .equiv  U2STA_UTXBF_WIDTH, 0x0001
        .equiv  U2STA_UTXBF_MASK, 0x0200

        .equiv  U2STA_UTXEN, 0x000A
        .equiv  U2STA_UTXEN_WIDTH, 0x0001
        .equiv  U2STA_UTXEN_MASK, 0x0400

        .equiv  U2STA_UTXBRK, 0x000B
        .equiv  U2STA_UTXBRK_WIDTH, 0x0001
        .equiv  U2STA_UTXBRK_MASK, 0x0800

        .equiv  U2STA_UTXISEL0, 0x000D
        .equiv  U2STA_UTXISEL0_WIDTH, 0x0001
        .equiv  U2STA_UTXISEL0_MASK, 0x2000

        .equiv  U2STA_UTXINV, 0x000E
        .equiv  U2STA_UTXINV_WIDTH, 0x0001
        .equiv  U2STA_UTXINV_MASK, 0x4000

        .equiv  U2STA_UTXISEL1, 0x000F
        .equiv  U2STA_UTXISEL1_WIDTH, 0x0001
        .equiv  U2STA_UTXISEL1_MASK, 0x8000

        .equiv  U2STA_URXISEL0, 0x0006
        .equiv  U2STA_URXISEL0_WIDTH, 0x0001
        .equiv  U2STA_URXISEL0_MASK, 0x0040

        .equiv  U2STA_URXISEL1, 0x0007
        .equiv  U2STA_URXISEL1_WIDTH, 0x0001
        .equiv  U2STA_URXISEL1_MASK, 0x0080

        .equiv  U2STA_TXINV, 0x000E
        .equiv  U2STA_TXINV_WIDTH, 0x0001
        .equiv  U2STA_TXINV_MASK, 0x4000

;----- SPI1STAT Bits -----------------------------------------------------
        .equiv  SPI1STAT_SPIRBF, 0x0000
        .equiv  SPI1STAT_SPIRBF_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIRBF_MASK, 0x0001
        .equiv  SPIRBF, 0x0000

        .equiv  SPI1STAT_SPITBF, 0x0001
        .equiv  SPI1STAT_SPITBF_WIDTH, 0x0001
        .equiv  SPI1STAT_SPITBF_MASK, 0x0002
        .equiv  SPITBF, 0x0001

        .equiv  SPI1STAT_SISEL, 0x0002
        .equiv  SPI1STAT_SISEL_WIDTH, 0x0003
        .equiv  SPI1STAT_SISEL_MASK, 0x001C

        .equiv  SPI1STAT_SRXMPT, 0x0005
        .equiv  SPI1STAT_SRXMPT_WIDTH, 0x0001
        .equiv  SPI1STAT_SRXMPT_MASK, 0x0020
        .equiv  SRXMPT, 0x0005

        .equiv  SPI1STAT_SPIROV, 0x0006
        .equiv  SPI1STAT_SPIROV_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIROV_MASK, 0x0040
        .equiv  SPIROV, 0x0006

        .equiv  SPI1STAT_SRMPT, 0x0007
        .equiv  SPI1STAT_SRMPT_WIDTH, 0x0001
        .equiv  SPI1STAT_SRMPT_MASK, 0x0080
        .equiv  SRMPT, 0x0007

        .equiv  SPI1STAT_SPIBEC, 0x0008
        .equiv  SPI1STAT_SPIBEC_WIDTH, 0x0003
        .equiv  SPI1STAT_SPIBEC_MASK, 0x0700

        .equiv  SPI1STAT_SPISIDL, 0x000D
        .equiv  SPI1STAT_SPISIDL_WIDTH, 0x0001
        .equiv  SPI1STAT_SPISIDL_MASK, 0x2000
        .equiv  SPISIDL, 0x000D

        .equiv  SPI1STAT_SPIEN, 0x000F
        .equiv  SPI1STAT_SPIEN_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIEN_MASK, 0x8000
        .equiv  SPIEN, 0x000F

        .equiv  SPI1STAT_SISEL0, 0x0002
        .equiv  SPI1STAT_SISEL0_WIDTH, 0x0001
        .equiv  SPI1STAT_SISEL0_MASK, 0x0004
        .equiv  SISEL0, 0x0002

        .equiv  SPI1STAT_SISEL1, 0x0003
        .equiv  SPI1STAT_SISEL1_WIDTH, 0x0001
        .equiv  SPI1STAT_SISEL1_MASK, 0x0008
        .equiv  SISEL1, 0x0003

        .equiv  SPI1STAT_SISEL2, 0x0004
        .equiv  SPI1STAT_SISEL2_WIDTH, 0x0001
        .equiv  SPI1STAT_SISEL2_MASK, 0x0010
        .equiv  SISEL2, 0x0004

        .equiv  SPI1STAT_SPIBEC0, 0x0008
        .equiv  SPI1STAT_SPIBEC0_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIBEC0_MASK, 0x0100
        .equiv  SPIBEC0, 0x0008

        .equiv  SPI1STAT_SPIBEC1, 0x0009
        .equiv  SPI1STAT_SPIBEC1_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIBEC1_MASK, 0x0200
        .equiv  SPIBEC1, 0x0009

        .equiv  SPI1STAT_SPIBEC2, 0x000A
        .equiv  SPI1STAT_SPIBEC2_WIDTH, 0x0001
        .equiv  SPI1STAT_SPIBEC2_MASK, 0x0400
        .equiv  SPIBEC2, 0x000A

;----- SPI1CON1 Bits -----------------------------------------------------
        .equiv  SPI1CON1_PPRE, 0x0000
        .equiv  SPI1CON1_PPRE_WIDTH, 0x0002
        .equiv  SPI1CON1_PPRE_MASK, 0x0003

        .equiv  SPI1CON1_SPRE, 0x0002
        .equiv  SPI1CON1_SPRE_WIDTH, 0x0003
        .equiv  SPI1CON1_SPRE_MASK, 0x001C

        .equiv  SPI1CON1_MSTEN, 0x0005
        .equiv  SPI1CON1_MSTEN_WIDTH, 0x0001
        .equiv  SPI1CON1_MSTEN_MASK, 0x0020
        .equiv  MSTEN, 0x0005

        .equiv  SPI1CON1_CKP, 0x0006
        .equiv  SPI1CON1_CKP_WIDTH, 0x0001
        .equiv  SPI1CON1_CKP_MASK, 0x0040
        .equiv  CKP, 0x0006

        .equiv  SPI1CON1_SSEN, 0x0007
        .equiv  SPI1CON1_SSEN_WIDTH, 0x0001
        .equiv  SPI1CON1_SSEN_MASK, 0x0080
        .equiv  SSEN, 0x0007

        .equiv  SPI1CON1_CKE, 0x0008
        .equiv  SPI1CON1_CKE_WIDTH, 0x0001
        .equiv  SPI1CON1_CKE_MASK, 0x0100
        .equiv  CKE, 0x0008

        .equiv  SPI1CON1_SMP, 0x0009
        .equiv  SPI1CON1_SMP_WIDTH, 0x0001
        .equiv  SPI1CON1_SMP_MASK, 0x0200
        .equiv  SMP, 0x0009

        .equiv  SPI1CON1_MODE16, 0x000A
        .equiv  SPI1CON1_MODE16_WIDTH, 0x0001
        .equiv  SPI1CON1_MODE16_MASK, 0x0400
        .equiv  MODE16, 0x000A

        .equiv  SPI1CON1_DISSDO, 0x000B
        .equiv  SPI1CON1_DISSDO_WIDTH, 0x0001
        .equiv  SPI1CON1_DISSDO_MASK, 0x0800
        .equiv  DISSDO, 0x000B

        .equiv  SPI1CON1_DISSCK, 0x000C
        .equiv  SPI1CON1_DISSCK_WIDTH, 0x0001
        .equiv  SPI1CON1_DISSCK_MASK, 0x1000
        .equiv  DISSCK, 0x000C

        .equiv  SPI1CON1_PPRE0, 0x0000
        .equiv  SPI1CON1_PPRE0_WIDTH, 0x0001
        .equiv  SPI1CON1_PPRE0_MASK, 0x0001
        .equiv  PPRE0, 0x0000

        .equiv  SPI1CON1_PPRE1, 0x0001
        .equiv  SPI1CON1_PPRE1_WIDTH, 0x0001
        .equiv  SPI1CON1_PPRE1_MASK, 0x0002
        .equiv  PPRE1, 0x0001

        .equiv  SPI1CON1_SPRE0, 0x0002
        .equiv  SPI1CON1_SPRE0_WIDTH, 0x0001
        .equiv  SPI1CON1_SPRE0_MASK, 0x0004
        .equiv  SPRE0, 0x0002

        .equiv  SPI1CON1_SPRE1, 0x0003
        .equiv  SPI1CON1_SPRE1_WIDTH, 0x0001
        .equiv  SPI1CON1_SPRE1_MASK, 0x0008
        .equiv  SPRE1, 0x0003

        .equiv  SPI1CON1_SPRE2, 0x0004
        .equiv  SPI1CON1_SPRE2_WIDTH, 0x0001
        .equiv  SPI1CON1_SPRE2_MASK, 0x0010
        .equiv  SPRE2, 0x0004

;----- SPI1CON2 Bits -----------------------------------------------------
        .equiv  SPI1CON2_SPIBEN, 0x0000
        .equiv  SPI1CON2_SPIBEN_WIDTH, 0x0001
        .equiv  SPI1CON2_SPIBEN_MASK, 0x0001
        .equiv  SPIBEN, 0x0000

        .equiv  SPI1CON2_FRMDLY, 0x0001
        .equiv  SPI1CON2_FRMDLY_WIDTH, 0x0001
        .equiv  SPI1CON2_FRMDLY_MASK, 0x0002
        .equiv  FRMDLY, 0x0001

        .equiv  SPI1CON2_FRMPOL, 0x000D
        .equiv  SPI1CON2_FRMPOL_WIDTH, 0x0001
        .equiv  SPI1CON2_FRMPOL_MASK, 0x2000
        .equiv  FRMPOL, 0x000D

        .equiv  SPI1CON2_SPIFSD, 0x000E
        .equiv  SPI1CON2_SPIFSD_WIDTH, 0x0001
        .equiv  SPI1CON2_SPIFSD_MASK, 0x4000
        .equiv  SPIFSD, 0x000E

        .equiv  SPI1CON2_FRMEN, 0x000F
        .equiv  SPI1CON2_FRMEN_WIDTH, 0x0001
        .equiv  SPI1CON2_FRMEN_MASK, 0x8000
        .equiv  FRMEN, 0x000F

;----- SPI2STAT Bits -----------------------------------------------------
        .equiv  SPI2STAT_SPIRBF, 0x0000
        .equiv  SPI2STAT_SPIRBF_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIRBF_MASK, 0x0001

        .equiv  SPI2STAT_SPITBF, 0x0001
        .equiv  SPI2STAT_SPITBF_WIDTH, 0x0001
        .equiv  SPI2STAT_SPITBF_MASK, 0x0002

        .equiv  SPI2STAT_SISEL, 0x0002
        .equiv  SPI2STAT_SISEL_WIDTH, 0x0003
        .equiv  SPI2STAT_SISEL_MASK, 0x001C

        .equiv  SPI2STAT_SRXMPT, 0x0005
        .equiv  SPI2STAT_SRXMPT_WIDTH, 0x0001
        .equiv  SPI2STAT_SRXMPT_MASK, 0x0020

        .equiv  SPI2STAT_SPIROV, 0x0006
        .equiv  SPI2STAT_SPIROV_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIROV_MASK, 0x0040

        .equiv  SPI2STAT_SRMPT, 0x0007
        .equiv  SPI2STAT_SRMPT_WIDTH, 0x0001
        .equiv  SPI2STAT_SRMPT_MASK, 0x0080

        .equiv  SPI2STAT_SPIBEC, 0x0008
        .equiv  SPI2STAT_SPIBEC_WIDTH, 0x0003
        .equiv  SPI2STAT_SPIBEC_MASK, 0x0700

        .equiv  SPI2STAT_SPISIDL, 0x000D
        .equiv  SPI2STAT_SPISIDL_WIDTH, 0x0001
        .equiv  SPI2STAT_SPISIDL_MASK, 0x2000

        .equiv  SPI2STAT_SPIEN, 0x000F
        .equiv  SPI2STAT_SPIEN_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIEN_MASK, 0x8000

        .equiv  SPI2STAT_SISEL0, 0x0002
        .equiv  SPI2STAT_SISEL0_WIDTH, 0x0001
        .equiv  SPI2STAT_SISEL0_MASK, 0x0004

        .equiv  SPI2STAT_SISEL1, 0x0003
        .equiv  SPI2STAT_SISEL1_WIDTH, 0x0001
        .equiv  SPI2STAT_SISEL1_MASK, 0x0008

        .equiv  SPI2STAT_SISEL2, 0x0004
        .equiv  SPI2STAT_SISEL2_WIDTH, 0x0001
        .equiv  SPI2STAT_SISEL2_MASK, 0x0010

        .equiv  SPI2STAT_SPIBEC0, 0x0008
        .equiv  SPI2STAT_SPIBEC0_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIBEC0_MASK, 0x0100

        .equiv  SPI2STAT_SPIBEC1, 0x0009
        .equiv  SPI2STAT_SPIBEC1_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIBEC1_MASK, 0x0200

        .equiv  SPI2STAT_SPIBEC2, 0x000A
        .equiv  SPI2STAT_SPIBEC2_WIDTH, 0x0001
        .equiv  SPI2STAT_SPIBEC2_MASK, 0x0400

;----- SPI2CON1 Bits -----------------------------------------------------
        .equiv  SPI2CON1_PPRE, 0x0000
        .equiv  SPI2CON1_PPRE_WIDTH, 0x0002
        .equiv  SPI2CON1_PPRE_MASK, 0x0003

        .equiv  SPI2CON1_SPRE, 0x0002
        .equiv  SPI2CON1_SPRE_WIDTH, 0x0003
        .equiv  SPI2CON1_SPRE_MASK, 0x001C

        .equiv  SPI2CON1_MSTEN, 0x0005
        .equiv  SPI2CON1_MSTEN_WIDTH, 0x0001
        .equiv  SPI2CON1_MSTEN_MASK, 0x0020

        .equiv  SPI2CON1_CKP, 0x0006
        .equiv  SPI2CON1_CKP_WIDTH, 0x0001
        .equiv  SPI2CON1_CKP_MASK, 0x0040

        .equiv  SPI2CON1_SSEN, 0x0007
        .equiv  SPI2CON1_SSEN_WIDTH, 0x0001
        .equiv  SPI2CON1_SSEN_MASK, 0x0080

        .equiv  SPI2CON1_CKE, 0x0008
        .equiv  SPI2CON1_CKE_WIDTH, 0x0001
        .equiv  SPI2CON1_CKE_MASK, 0x0100

        .equiv  SPI2CON1_SMP, 0x0009
        .equiv  SPI2CON1_SMP_WIDTH, 0x0001
        .equiv  SPI2CON1_SMP_MASK, 0x0200

        .equiv  SPI2CON1_MODE16, 0x000A
        .equiv  SPI2CON1_MODE16_WIDTH, 0x0001
        .equiv  SPI2CON1_MODE16_MASK, 0x0400

        .equiv  SPI2CON1_DISSDO, 0x000B
        .equiv  SPI2CON1_DISSDO_WIDTH, 0x0001
        .equiv  SPI2CON1_DISSDO_MASK, 0x0800

        .equiv  SPI2CON1_DISSCK, 0x000C
        .equiv  SPI2CON1_DISSCK_WIDTH, 0x0001
        .equiv  SPI2CON1_DISSCK_MASK, 0x1000

        .equiv  SPI2CON1_PPRE0, 0x0000
        .equiv  SPI2CON1_PPRE0_WIDTH, 0x0001
        .equiv  SPI2CON1_PPRE0_MASK, 0x0001

        .equiv  SPI2CON1_PPRE1, 0x0001
        .equiv  SPI2CON1_PPRE1_WIDTH, 0x0001
        .equiv  SPI2CON1_PPRE1_MASK, 0x0002

        .equiv  SPI2CON1_SPRE0, 0x0002
        .equiv  SPI2CON1_SPRE0_WIDTH, 0x0001
        .equiv  SPI2CON1_SPRE0_MASK, 0x0004

        .equiv  SPI2CON1_SPRE1, 0x0003
        .equiv  SPI2CON1_SPRE1_WIDTH, 0x0001
        .equiv  SPI2CON1_SPRE1_MASK, 0x0008

        .equiv  SPI2CON1_SPRE2, 0x0004
        .equiv  SPI2CON1_SPRE2_WIDTH, 0x0001
        .equiv  SPI2CON1_SPRE2_MASK, 0x0010

;----- SPI2CON2 Bits -----------------------------------------------------
        .equiv  SPI2CON2_SPIBEN, 0x0000
        .equiv  SPI2CON2_SPIBEN_WIDTH, 0x0001
        .equiv  SPI2CON2_SPIBEN_MASK, 0x0001

        .equiv  SPI2CON2_FRMDLY, 0x0001
        .equiv  SPI2CON2_FRMDLY_WIDTH, 0x0001
        .equiv  SPI2CON2_FRMDLY_MASK, 0x0002

        .equiv  SPI2CON2_FRMPOL, 0x000D
        .equiv  SPI2CON2_FRMPOL_WIDTH, 0x0001
        .equiv  SPI2CON2_FRMPOL_MASK, 0x2000

        .equiv  SPI2CON2_SPIFSD, 0x000E
        .equiv  SPI2CON2_SPIFSD_WIDTH, 0x0001
        .equiv  SPI2CON2_SPIFSD_MASK, 0x4000

        .equiv  SPI2CON2_FRMEN, 0x000F
        .equiv  SPI2CON2_FRMEN_WIDTH, 0x0001
        .equiv  SPI2CON2_FRMEN_MASK, 0x8000

;----- AD1CON1 Bits -----------------------------------------------------
        .equiv  AD1CON1_DONE, 0x0000
        .equiv  AD1CON1_DONE_WIDTH, 0x0001
        .equiv  AD1CON1_DONE_MASK, 0x0001
        .equiv  DONE, 0x0000

        .equiv  AD1CON1_SAMP, 0x0001
        .equiv  AD1CON1_SAMP_WIDTH, 0x0001
        .equiv  AD1CON1_SAMP_MASK, 0x0002
        .equiv  SAMP, 0x0001

        .equiv  AD1CON1_ASAM, 0x0002
        .equiv  AD1CON1_ASAM_WIDTH, 0x0001
        .equiv  AD1CON1_ASAM_MASK, 0x0004
        .equiv  ASAM, 0x0002

        .equiv  AD1CON1_SIMSAM, 0x0003
        .equiv  AD1CON1_SIMSAM_WIDTH, 0x0001
        .equiv  AD1CON1_SIMSAM_MASK, 0x0008
        .equiv  SIMSAM, 0x0003

        .equiv  AD1CON1_SSRCG, 0x0004
        .equiv  AD1CON1_SSRCG_WIDTH, 0x0001
        .equiv  AD1CON1_SSRCG_MASK, 0x0010
        .equiv  SSRCG, 0x0004

        .equiv  AD1CON1_SSRC, 0x0005
        .equiv  AD1CON1_SSRC_WIDTH, 0x0003
        .equiv  AD1CON1_SSRC_MASK, 0x00E0

        .equiv  AD1CON1_FORM, 0x0008
        .equiv  AD1CON1_FORM_WIDTH, 0x0002
        .equiv  AD1CON1_FORM_MASK, 0x0300

        .equiv  AD1CON1_AD12B, 0x000A
        .equiv  AD1CON1_AD12B_WIDTH, 0x0001
        .equiv  AD1CON1_AD12B_MASK, 0x0400
        .equiv  AD12B, 0x000A

        .equiv  AD1CON1_ADDMABM, 0x000C
        .equiv  AD1CON1_ADDMABM_WIDTH, 0x0001
        .equiv  AD1CON1_ADDMABM_MASK, 0x1000
        .equiv  ADDMABM, 0x000C

        .equiv  AD1CON1_ADSIDL, 0x000D
        .equiv  AD1CON1_ADSIDL_WIDTH, 0x0001
        .equiv  AD1CON1_ADSIDL_MASK, 0x2000
        .equiv  ADSIDL, 0x000D

        .equiv  AD1CON1_ADON, 0x000F
        .equiv  AD1CON1_ADON_WIDTH, 0x0001
        .equiv  AD1CON1_ADON_MASK, 0x8000
        .equiv  ADON, 0x000F

        .equiv  AD1CON1_SSRC0, 0x0005
        .equiv  AD1CON1_SSRC0_WIDTH, 0x0001
        .equiv  AD1CON1_SSRC0_MASK, 0x0020
        .equiv  SSRC0, 0x0005

        .equiv  AD1CON1_SSRC1, 0x0006
        .equiv  AD1CON1_SSRC1_WIDTH, 0x0001
        .equiv  AD1CON1_SSRC1_MASK, 0x0040
        .equiv  SSRC1, 0x0006

        .equiv  AD1CON1_SSRC2, 0x0007
        .equiv  AD1CON1_SSRC2_WIDTH, 0x0001
        .equiv  AD1CON1_SSRC2_MASK, 0x0080
        .equiv  SSRC2, 0x0007

        .equiv  AD1CON1_FORM0, 0x0008
        .equiv  AD1CON1_FORM0_WIDTH, 0x0001
        .equiv  AD1CON1_FORM0_MASK, 0x0100
        .equiv  FORM0, 0x0008

        .equiv  AD1CON1_FORM1, 0x0009
        .equiv  AD1CON1_FORM1_WIDTH, 0x0001
        .equiv  AD1CON1_FORM1_MASK, 0x0200
        .equiv  FORM1, 0x0009

;----- AD1CON2 Bits -----------------------------------------------------
        .equiv  AD1CON2_ALTS, 0x0000
        .equiv  AD1CON2_ALTS_WIDTH, 0x0001
        .equiv  AD1CON2_ALTS_MASK, 0x0001
        .equiv  ALTS, 0x0000

        .equiv  AD1CON2_BUFM, 0x0001
        .equiv  AD1CON2_BUFM_WIDTH, 0x0001
        .equiv  AD1CON2_BUFM_MASK, 0x0002
        .equiv  BUFM, 0x0001

        .equiv  AD1CON2_SMPI, 0x0002
        .equiv  AD1CON2_SMPI_WIDTH, 0x0005
        .equiv  AD1CON2_SMPI_MASK, 0x007C

        .equiv  AD1CON2_BUFS, 0x0007
        .equiv  AD1CON2_BUFS_WIDTH, 0x0001
        .equiv  AD1CON2_BUFS_MASK, 0x0080
        .equiv  BUFS, 0x0007

        .equiv  AD1CON2_CHPS, 0x0008
        .equiv  AD1CON2_CHPS_WIDTH, 0x0002
        .equiv  AD1CON2_CHPS_MASK, 0x0300

        .equiv  AD1CON2_CSCNA, 0x000A
        .equiv  AD1CON2_CSCNA_WIDTH, 0x0001
        .equiv  AD1CON2_CSCNA_MASK, 0x0400
        .equiv  CSCNA, 0x000A

        .equiv  AD1CON2_VCFG, 0x000D
        .equiv  AD1CON2_VCFG_WIDTH, 0x0003
        .equiv  AD1CON2_VCFG_MASK, 0xE000

        .equiv  AD1CON2_SMPI0, 0x0002
        .equiv  AD1CON2_SMPI0_WIDTH, 0x0001
        .equiv  AD1CON2_SMPI0_MASK, 0x0004
        .equiv  SMPI0, 0x0002

        .equiv  AD1CON2_SMPI1, 0x0003
        .equiv  AD1CON2_SMPI1_WIDTH, 0x0001
        .equiv  AD1CON2_SMPI1_MASK, 0x0008
        .equiv  SMPI1, 0x0003

        .equiv  AD1CON2_SMPI2, 0x0004
        .equiv  AD1CON2_SMPI2_WIDTH, 0x0001
        .equiv  AD1CON2_SMPI2_MASK, 0x0010
        .equiv  SMPI2, 0x0004

        .equiv  AD1CON2_SMPI3, 0x0005
        .equiv  AD1CON2_SMPI3_WIDTH, 0x0001
        .equiv  AD1CON2_SMPI3_MASK, 0x0020
        .equiv  SMPI3, 0x0005

        .equiv  AD1CON2_SMPI4, 0x0006
        .equiv  AD1CON2_SMPI4_WIDTH, 0x0001
        .equiv  AD1CON2_SMPI4_MASK, 0x0040
        .equiv  SMPI4, 0x0006

        .equiv  AD1CON2_CHPS0, 0x0008
        .equiv  AD1CON2_CHPS0_WIDTH, 0x0001
        .equiv  AD1CON2_CHPS0_MASK, 0x0100
        .equiv  CHPS0, 0x0008

        .equiv  AD1CON2_CHPS1, 0x0009
        .equiv  AD1CON2_CHPS1_WIDTH, 0x0001
        .equiv  AD1CON2_CHPS1_MASK, 0x0200
        .equiv  CHPS1, 0x0009

        .equiv  AD1CON2_VCFG0, 0x000D
        .equiv  AD1CON2_VCFG0_WIDTH, 0x0001
        .equiv  AD1CON2_VCFG0_MASK, 0x2000
        .equiv  VCFG0, 0x000D

        .equiv  AD1CON2_VCFG1, 0x000E
        .equiv  AD1CON2_VCFG1_WIDTH, 0x0001
        .equiv  AD1CON2_VCFG1_MASK, 0x4000
        .equiv  VCFG1, 0x000E

        .equiv  AD1CON2_VCFG2, 0x000F
        .equiv  AD1CON2_VCFG2_WIDTH, 0x0001
        .equiv  AD1CON2_VCFG2_MASK, 0x8000
        .equiv  VCFG2, 0x000F

;----- AD1CON3 Bits -----------------------------------------------------
        .equiv  AD1CON3_ADCS, 0x0000
        .equiv  AD1CON3_ADCS_WIDTH, 0x0008
        .equiv  AD1CON3_ADCS_MASK, 0x00FF

        .equiv  AD1CON3_SAMC, 0x0008
        .equiv  AD1CON3_SAMC_WIDTH, 0x0005
        .equiv  AD1CON3_SAMC_MASK, 0x1F00

        .equiv  AD1CON3_ADRC, 0x000F
        .equiv  AD1CON3_ADRC_WIDTH, 0x0001
        .equiv  AD1CON3_ADRC_MASK, 0x8000
        .equiv  ADRC, 0x000F

        .equiv  AD1CON3_ADCS0, 0x0000
        .equiv  AD1CON3_ADCS0_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS0_MASK, 0x0001
        .equiv  ADCS0, 0x0000

        .equiv  AD1CON3_ADCS1, 0x0001
        .equiv  AD1CON3_ADCS1_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS1_MASK, 0x0002
        .equiv  ADCS1, 0x0001

        .equiv  AD1CON3_ADCS2, 0x0002
        .equiv  AD1CON3_ADCS2_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS2_MASK, 0x0004
        .equiv  ADCS2, 0x0002

        .equiv  AD1CON3_ADCS3, 0x0003
        .equiv  AD1CON3_ADCS3_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS3_MASK, 0x0008
        .equiv  ADCS3, 0x0003

        .equiv  AD1CON3_ADCS4, 0x0004
        .equiv  AD1CON3_ADCS4_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS4_MASK, 0x0010
        .equiv  ADCS4, 0x0004

        .equiv  AD1CON3_ADCS5, 0x0005
        .equiv  AD1CON3_ADCS5_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS5_MASK, 0x0020
        .equiv  ADCS5, 0x0005

        .equiv  AD1CON3_ADCS6, 0x0006
        .equiv  AD1CON3_ADCS6_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS6_MASK, 0x0040
        .equiv  ADCS6, 0x0006

        .equiv  AD1CON3_ADCS7, 0x0007
        .equiv  AD1CON3_ADCS7_WIDTH, 0x0001
        .equiv  AD1CON3_ADCS7_MASK, 0x0080
        .equiv  ADCS7, 0x0007

        .equiv  AD1CON3_SAMC0, 0x0008
        .equiv  AD1CON3_SAMC0_WIDTH, 0x0001
        .equiv  AD1CON3_SAMC0_MASK, 0x0100
        .equiv  SAMC0, 0x0008

        .equiv  AD1CON3_SAMC1, 0x0009
        .equiv  AD1CON3_SAMC1_WIDTH, 0x0001
        .equiv  AD1CON3_SAMC1_MASK, 0x0200
        .equiv  SAMC1, 0x0009

        .equiv  AD1CON3_SAMC2, 0x000A
        .equiv  AD1CON3_SAMC2_WIDTH, 0x0001
        .equiv  AD1CON3_SAMC2_MASK, 0x0400
        .equiv  SAMC2, 0x000A

        .equiv  AD1CON3_SAMC3, 0x000B
        .equiv  AD1CON3_SAMC3_WIDTH, 0x0001
        .equiv  AD1CON3_SAMC3_MASK, 0x0800
        .equiv  SAMC3, 0x000B

        .equiv  AD1CON3_SAMC4, 0x000C
        .equiv  AD1CON3_SAMC4_WIDTH, 0x0001
        .equiv  AD1CON3_SAMC4_MASK, 0x1000
        .equiv  SAMC4, 0x000C

;----- AD1CHS123 Bits -----------------------------------------------------
        .equiv  AD1CHS123_CH123SA, 0x0000
        .equiv  AD1CHS123_CH123SA_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123SA_MASK, 0x0001
        .equiv  CH123SA, 0x0000

        .equiv  AD1CHS123_CH123NA, 0x0001
        .equiv  AD1CHS123_CH123NA_WIDTH, 0x0002
        .equiv  AD1CHS123_CH123NA_MASK, 0x0006

        .equiv  AD1CHS123_CH123SB, 0x0008
        .equiv  AD1CHS123_CH123SB_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123SB_MASK, 0x0100
        .equiv  CH123SB, 0x0008

        .equiv  AD1CHS123_CH123NB, 0x0009
        .equiv  AD1CHS123_CH123NB_WIDTH, 0x0002
        .equiv  AD1CHS123_CH123NB_MASK, 0x0600

        .equiv  AD1CHS123_CH123NA0, 0x0001
        .equiv  AD1CHS123_CH123NA0_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123NA0_MASK, 0x0002
        .equiv  CH123NA0, 0x0001

        .equiv  AD1CHS123_CH123NA1, 0x0002
        .equiv  AD1CHS123_CH123NA1_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123NA1_MASK, 0x0004
        .equiv  CH123NA1, 0x0002

        .equiv  AD1CHS123_CH123NB0, 0x0009
        .equiv  AD1CHS123_CH123NB0_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123NB0_MASK, 0x0200
        .equiv  CH123NB0, 0x0009

        .equiv  AD1CHS123_CH123NB1, 0x000A
        .equiv  AD1CHS123_CH123NB1_WIDTH, 0x0001
        .equiv  AD1CHS123_CH123NB1_MASK, 0x0400
        .equiv  CH123NB1, 0x000A

;----- AD1CHS0 Bits -----------------------------------------------------
        .equiv  AD1CHS0_CH0SA, 0x0000
        .equiv  AD1CHS0_CH0SA_WIDTH, 0x0005
        .equiv  AD1CHS0_CH0SA_MASK, 0x001F

        .equiv  AD1CHS0_CH0NA, 0x0007
        .equiv  AD1CHS0_CH0NA_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0NA_MASK, 0x0080
        .equiv  CH0NA, 0x0007

        .equiv  AD1CHS0_CH0SB, 0x0008
        .equiv  AD1CHS0_CH0SB_WIDTH, 0x0005
        .equiv  AD1CHS0_CH0SB_MASK, 0x1F00

        .equiv  AD1CHS0_CH0NB, 0x000F
        .equiv  AD1CHS0_CH0NB_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0NB_MASK, 0x8000
        .equiv  CH0NB, 0x000F

        .equiv  AD1CHS0_CH0SA0, 0x0000
        .equiv  AD1CHS0_CH0SA0_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SA0_MASK, 0x0001
        .equiv  CH0SA0, 0x0000

        .equiv  AD1CHS0_CH0SA1, 0x0001
        .equiv  AD1CHS0_CH0SA1_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SA1_MASK, 0x0002
        .equiv  CH0SA1, 0x0001

        .equiv  AD1CHS0_CH0SA2, 0x0002
        .equiv  AD1CHS0_CH0SA2_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SA2_MASK, 0x0004
        .equiv  CH0SA2, 0x0002

        .equiv  AD1CHS0_CH0SA3, 0x0003
        .equiv  AD1CHS0_CH0SA3_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SA3_MASK, 0x0008
        .equiv  CH0SA3, 0x0003

        .equiv  AD1CHS0_CH0SA4, 0x0004
        .equiv  AD1CHS0_CH0SA4_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SA4_MASK, 0x0010
        .equiv  CH0SA4, 0x0004

        .equiv  AD1CHS0_CH0SB0, 0x0008
        .equiv  AD1CHS0_CH0SB0_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SB0_MASK, 0x0100
        .equiv  CH0SB0, 0x0008

        .equiv  AD1CHS0_CH0SB1, 0x0009
        .equiv  AD1CHS0_CH0SB1_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SB1_MASK, 0x0200
        .equiv  CH0SB1, 0x0009

        .equiv  AD1CHS0_CH0SB2, 0x000A
        .equiv  AD1CHS0_CH0SB2_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SB2_MASK, 0x0400
        .equiv  CH0SB2, 0x000A

        .equiv  AD1CHS0_CH0SB3, 0x000B
        .equiv  AD1CHS0_CH0SB3_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SB3_MASK, 0x0800
        .equiv  CH0SB3, 0x000B

        .equiv  AD1CHS0_CH0SB4, 0x000C
        .equiv  AD1CHS0_CH0SB4_WIDTH, 0x0001
        .equiv  AD1CHS0_CH0SB4_MASK, 0x1000
        .equiv  CH0SB4, 0x000C

;----- AD1CSSH Bits -----------------------------------------------------
        .equiv  AD1CSSH_CSS24, 0x0008
        .equiv  AD1CSSH_CSS24_WIDTH, 0x0001
        .equiv  AD1CSSH_CSS24_MASK, 0x0100
        .equiv  CSS24, 0x0008

        .equiv  AD1CSSH_CSS25, 0x0009
        .equiv  AD1CSSH_CSS25_WIDTH, 0x0001
        .equiv  AD1CSSH_CSS25_MASK, 0x0200
        .equiv  CSS25, 0x0009

        .equiv  AD1CSSH_CSS26, 0x000A
        .equiv  AD1CSSH_CSS26_WIDTH, 0x0001
        .equiv  AD1CSSH_CSS26_MASK, 0x0400
        .equiv  CSS26, 0x000A

        .equiv  AD1CSSH_CSS30, 0x000E
        .equiv  AD1CSSH_CSS30_WIDTH, 0x0001
        .equiv  AD1CSSH_CSS30_MASK, 0x4000
        .equiv  CSS30, 0x000E

        .equiv  AD1CSSH_CSS31, 0x000F
        .equiv  AD1CSSH_CSS31_WIDTH, 0x0001
        .equiv  AD1CSSH_CSS31_MASK, 0x8000
        .equiv  CSS31, 0x000F

;----- AD1CSSL Bits -----------------------------------------------------
        .equiv  AD1CSSL_CSS0, 0x0000
        .equiv  AD1CSSL_CSS0_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS0_MASK, 0x0001
        .equiv  CSS0, 0x0000

        .equiv  AD1CSSL_CSS1, 0x0001
        .equiv  AD1CSSL_CSS1_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS1_MASK, 0x0002
        .equiv  CSS1, 0x0001

        .equiv  AD1CSSL_CSS2, 0x0002
        .equiv  AD1CSSL_CSS2_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS2_MASK, 0x0004
        .equiv  CSS2, 0x0002

        .equiv  AD1CSSL_CSS3, 0x0003
        .equiv  AD1CSSL_CSS3_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS3_MASK, 0x0008
        .equiv  CSS3, 0x0003

        .equiv  AD1CSSL_CSS4, 0x0004
        .equiv  AD1CSSL_CSS4_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS4_MASK, 0x0010
        .equiv  CSS4, 0x0004

        .equiv  AD1CSSL_CSS5, 0x0005
        .equiv  AD1CSSL_CSS5_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS5_MASK, 0x0020
        .equiv  CSS5, 0x0005

        .equiv  AD1CSSL_CSS6, 0x0006
        .equiv  AD1CSSL_CSS6_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS6_MASK, 0x0040
        .equiv  CSS6, 0x0006

        .equiv  AD1CSSL_CSS7, 0x0007
        .equiv  AD1CSSL_CSS7_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS7_MASK, 0x0080
        .equiv  CSS7, 0x0007

        .equiv  AD1CSSL_CSS8, 0x0008
        .equiv  AD1CSSL_CSS8_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS8_MASK, 0x0100
        .equiv  CSS8, 0x0008

        .equiv  AD1CSSL_CSS9, 0x0009
        .equiv  AD1CSSL_CSS9_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS9_MASK, 0x0200
        .equiv  CSS9, 0x0009

        .equiv  AD1CSSL_CSS10, 0x000A
        .equiv  AD1CSSL_CSS10_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS10_MASK, 0x0400
        .equiv  CSS10, 0x000A

        .equiv  AD1CSSL_CSS11, 0x000B
        .equiv  AD1CSSL_CSS11_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS11_MASK, 0x0800
        .equiv  CSS11, 0x000B

        .equiv  AD1CSSL_CSS12, 0x000C
        .equiv  AD1CSSL_CSS12_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS12_MASK, 0x1000
        .equiv  CSS12, 0x000C

        .equiv  AD1CSSL_CSS13, 0x000D
        .equiv  AD1CSSL_CSS13_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS13_MASK, 0x2000
        .equiv  CSS13, 0x000D

        .equiv  AD1CSSL_CSS14, 0x000E
        .equiv  AD1CSSL_CSS14_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS14_MASK, 0x4000
        .equiv  CSS14, 0x000E

        .equiv  AD1CSSL_CSS15, 0x000F
        .equiv  AD1CSSL_CSS15_WIDTH, 0x0001
        .equiv  AD1CSSL_CSS15_MASK, 0x8000
        .equiv  CSS15, 0x000F

;----- AD1CON4 Bits -----------------------------------------------------
        .equiv  AD1CON4_DMABL, 0x0000
        .equiv  AD1CON4_DMABL_WIDTH, 0x0003
        .equiv  AD1CON4_DMABL_MASK, 0x0007

        .equiv  AD1CON4_ADDMAEN, 0x0008
        .equiv  AD1CON4_ADDMAEN_WIDTH, 0x0001
        .equiv  AD1CON4_ADDMAEN_MASK, 0x0100
        .equiv  ADDMAEN, 0x0008

        .equiv  AD1CON4_DMABL0, 0x0000
        .equiv  AD1CON4_DMABL0_WIDTH, 0x0001
        .equiv  AD1CON4_DMABL0_MASK, 0x0001
        .equiv  DMABL0, 0x0000

        .equiv  AD1CON4_DMABL1, 0x0001
        .equiv  AD1CON4_DMABL1_WIDTH, 0x0001
        .equiv  AD1CON4_DMABL1_MASK, 0x0002
        .equiv  DMABL1, 0x0001

        .equiv  AD1CON4_DMABL2, 0x0002
        .equiv  AD1CON4_DMABL2_WIDTH, 0x0001
        .equiv  AD1CON4_DMABL2_MASK, 0x0004
        .equiv  DMABL2, 0x0002

;----- CTMUCON1 Bits -----------------------------------------------------
        .equiv  CTMUCON1_CTTRIG, 0x0008
        .equiv  CTMUCON1_CTTRIG_WIDTH, 0x0001
        .equiv  CTMUCON1_CTTRIG_MASK, 0x0100
        .equiv  CTTRIG, 0x0008

        .equiv  CTMUCON1_IDISSEN, 0x0009
        .equiv  CTMUCON1_IDISSEN_WIDTH, 0x0001
        .equiv  CTMUCON1_IDISSEN_MASK, 0x0200
        .equiv  IDISSEN, 0x0009

        .equiv  CTMUCON1_EDGSEQEN, 0x000A
        .equiv  CTMUCON1_EDGSEQEN_WIDTH, 0x0001
        .equiv  CTMUCON1_EDGSEQEN_MASK, 0x0400
        .equiv  EDGSEQEN, 0x000A

        .equiv  CTMUCON1_EDGEN, 0x000B
        .equiv  CTMUCON1_EDGEN_WIDTH, 0x0001
        .equiv  CTMUCON1_EDGEN_MASK, 0x0800
        .equiv  EDGEN, 0x000B

        .equiv  CTMUCON1_TGEN, 0x000C
        .equiv  CTMUCON1_TGEN_WIDTH, 0x0001
        .equiv  CTMUCON1_TGEN_MASK, 0x1000
        .equiv  TGEN, 0x000C

        .equiv  CTMUCON1_CTMUSIDL, 0x000D
        .equiv  CTMUCON1_CTMUSIDL_WIDTH, 0x0001
        .equiv  CTMUCON1_CTMUSIDL_MASK, 0x2000
        .equiv  CTMUSIDL, 0x000D

        .equiv  CTMUCON1_CTMUEN, 0x000F
        .equiv  CTMUCON1_CTMUEN_WIDTH, 0x0001
        .equiv  CTMUCON1_CTMUEN_MASK, 0x8000
        .equiv  CTMUEN, 0x000F

;----- CTMUCON2 Bits -----------------------------------------------------
        .equiv  CTMUCON2_EDG2SEL, 0x0002
        .equiv  CTMUCON2_EDG2SEL_WIDTH, 0x0004
        .equiv  CTMUCON2_EDG2SEL_MASK, 0x003C

        .equiv  CTMUCON2_EDG2POL, 0x0006
        .equiv  CTMUCON2_EDG2POL_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2POL_MASK, 0x0040
        .equiv  EDG2POL, 0x0006

        .equiv  CTMUCON2_EDG2MOD, 0x0007
        .equiv  CTMUCON2_EDG2MOD_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2MOD_MASK, 0x0080
        .equiv  EDG2MOD, 0x0007

        .equiv  CTMUCON2_EDG1STAT, 0x0008
        .equiv  CTMUCON2_EDG1STAT_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1STAT_MASK, 0x0100
        .equiv  EDG1STAT, 0x0008

        .equiv  CTMUCON2_EDG2STAT, 0x0009
        .equiv  CTMUCON2_EDG2STAT_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2STAT_MASK, 0x0200
        .equiv  EDG2STAT, 0x0009

        .equiv  CTMUCON2_EDG1SEL, 0x000A
        .equiv  CTMUCON2_EDG1SEL_WIDTH, 0x0004
        .equiv  CTMUCON2_EDG1SEL_MASK, 0x3C00

        .equiv  CTMUCON2_EDG1POL, 0x000E
        .equiv  CTMUCON2_EDG1POL_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1POL_MASK, 0x4000
        .equiv  EDG1POL, 0x000E

        .equiv  CTMUCON2_EDG1MOD, 0x000F
        .equiv  CTMUCON2_EDG1MOD_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1MOD_MASK, 0x8000
        .equiv  EDG1MOD, 0x000F

        .equiv  CTMUCON2_EDG2SEL0, 0x0002
        .equiv  CTMUCON2_EDG2SEL0_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2SEL0_MASK, 0x0004
        .equiv  EDG2SEL0, 0x0002

        .equiv  CTMUCON2_EDG2SEL1, 0x0003
        .equiv  CTMUCON2_EDG2SEL1_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2SEL1_MASK, 0x0008
        .equiv  EDG2SEL1, 0x0003

        .equiv  CTMUCON2_EDG2SEL2, 0x0004
        .equiv  CTMUCON2_EDG2SEL2_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2SEL2_MASK, 0x0010
        .equiv  EDG2SEL2, 0x0004

        .equiv  CTMUCON2_EDG2SEL3, 0x0005
        .equiv  CTMUCON2_EDG2SEL3_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG2SEL3_MASK, 0x0020
        .equiv  EDG2SEL3, 0x0005

        .equiv  CTMUCON2_EDG1SEL0, 0x000A
        .equiv  CTMUCON2_EDG1SEL0_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1SEL0_MASK, 0x0400
        .equiv  EDG1SEL0, 0x000A

        .equiv  CTMUCON2_EDG1SEL1, 0x000B
        .equiv  CTMUCON2_EDG1SEL1_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1SEL1_MASK, 0x0800
        .equiv  EDG1SEL1, 0x000B

        .equiv  CTMUCON2_EDG1SEL2, 0x000C
        .equiv  CTMUCON2_EDG1SEL2_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1SEL2_MASK, 0x1000
        .equiv  EDG1SEL2, 0x000C

        .equiv  CTMUCON2_EDG1SEL3, 0x000D
        .equiv  CTMUCON2_EDG1SEL3_WIDTH, 0x0001
        .equiv  CTMUCON2_EDG1SEL3_MASK, 0x2000
        .equiv  EDG1SEL3, 0x000D

;----- CTMUICON Bits -----------------------------------------------------
        .equiv  CTMUICON_IRNG, 0x0008
        .equiv  CTMUICON_IRNG_WIDTH, 0x0002
        .equiv  CTMUICON_IRNG_MASK, 0x0300

        .equiv  CTMUICON_ITRIM, 0x000A
        .equiv  CTMUICON_ITRIM_WIDTH, 0x0006
        .equiv  CTMUICON_ITRIM_MASK, 0xFC00

        .equiv  CTMUICON_IRNG0, 0x0008
        .equiv  CTMUICON_IRNG0_WIDTH, 0x0001
        .equiv  CTMUICON_IRNG0_MASK, 0x0100
        .equiv  IRNG0, 0x0008

        .equiv  CTMUICON_IRNG1, 0x0009
        .equiv  CTMUICON_IRNG1_WIDTH, 0x0001
        .equiv  CTMUICON_IRNG1_MASK, 0x0200
        .equiv  IRNG1, 0x0009

        .equiv  CTMUICON_ITRIM0, 0x000A
        .equiv  CTMUICON_ITRIM0_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM0_MASK, 0x0400
        .equiv  ITRIM0, 0x000A

        .equiv  CTMUICON_ITRIM1, 0x000B
        .equiv  CTMUICON_ITRIM1_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM1_MASK, 0x0800
        .equiv  ITRIM1, 0x000B

        .equiv  CTMUICON_ITRIM2, 0x000C
        .equiv  CTMUICON_ITRIM2_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM2_MASK, 0x1000
        .equiv  ITRIM2, 0x000C

        .equiv  CTMUICON_ITRIM3, 0x000D
        .equiv  CTMUICON_ITRIM3_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM3_MASK, 0x2000
        .equiv  ITRIM3, 0x000D

        .equiv  CTMUICON_ITRIM4, 0x000E
        .equiv  CTMUICON_ITRIM4_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM4_MASK, 0x4000
        .equiv  ITRIM4, 0x000E

        .equiv  CTMUICON_ITRIM5, 0x000F
        .equiv  CTMUICON_ITRIM5_WIDTH, 0x0001
        .equiv  CTMUICON_ITRIM5_MASK, 0x8000
        .equiv  ITRIM5, 0x000F

;----- C1CTRL1 Bits -----------------------------------------------------
        .equiv  C1CTRL1_WIN, 0x0000
        .equiv  C1CTRL1_WIN_WIDTH, 0x0001
        .equiv  C1CTRL1_WIN_MASK, 0x0001
        .equiv  WIN, 0x0000

        .equiv  C1CTRL1_CANCAP, 0x0003
        .equiv  C1CTRL1_CANCAP_WIDTH, 0x0001
        .equiv  C1CTRL1_CANCAP_MASK, 0x0008
        .equiv  CANCAP, 0x0003

        .equiv  C1CTRL1_OPMODE_C1CTRL1, 0x0005
        .equiv  C1CTRL1_OPMODE_C1CTRL1_WIDTH, 0x0003
        .equiv  C1CTRL1_OPMODE_C1CTRL1_MASK, 0x00E0

        .equiv  C1CTRL1_REQOP, 0x0008
        .equiv  C1CTRL1_REQOP_WIDTH, 0x0003
        .equiv  C1CTRL1_REQOP_MASK, 0x0700

        .equiv  C1CTRL1_CANCKS, 0x000B
        .equiv  C1CTRL1_CANCKS_WIDTH, 0x0001
        .equiv  C1CTRL1_CANCKS_MASK, 0x0800
        .equiv  CANCKS, 0x000B

        .equiv  C1CTRL1_ABAT, 0x000C
        .equiv  C1CTRL1_ABAT_WIDTH, 0x0001
        .equiv  C1CTRL1_ABAT_MASK, 0x1000
        .equiv  ABAT, 0x000C

        .equiv  C1CTRL1_CSIDL, 0x000D
        .equiv  C1CTRL1_CSIDL_WIDTH, 0x0001
        .equiv  C1CTRL1_CSIDL_MASK, 0x2000
        .equiv  CSIDL, 0x000D

        .equiv  C1CTRL1_OPMODE0, 0x0005
        .equiv  C1CTRL1_OPMODE0_WIDTH, 0x0001
        .equiv  C1CTRL1_OPMODE0_MASK, 0x0020
        .equiv  OPMODE0, 0x0005

        .equiv  C1CTRL1_OPMODE1, 0x0006
        .equiv  C1CTRL1_OPMODE1_WIDTH, 0x0001
        .equiv  C1CTRL1_OPMODE1_MASK, 0x0040
        .equiv  OPMODE1, 0x0006

        .equiv  C1CTRL1_OPMODE2, 0x0007
        .equiv  C1CTRL1_OPMODE2_WIDTH, 0x0001
        .equiv  C1CTRL1_OPMODE2_MASK, 0x0080
        .equiv  OPMODE2, 0x0007

        .equiv  C1CTRL1_REQOP0, 0x0008
        .equiv  C1CTRL1_REQOP0_WIDTH, 0x0001
        .equiv  C1CTRL1_REQOP0_MASK, 0x0100
        .equiv  REQOP0, 0x0008

        .equiv  C1CTRL1_REQOP1, 0x0009
        .equiv  C1CTRL1_REQOP1_WIDTH, 0x0001
        .equiv  C1CTRL1_REQOP1_MASK, 0x0200
        .equiv  REQOP1, 0x0009

        .equiv  C1CTRL1_REQOP2, 0x000A
        .equiv  C1CTRL1_REQOP2_WIDTH, 0x0001
        .equiv  C1CTRL1_REQOP2_MASK, 0x0400
        .equiv  REQOP2, 0x000A

;----- C1CTRL2 Bits -----------------------------------------------------
        .equiv  C1CTRL2_DNCNT, 0x0000
        .equiv  C1CTRL2_DNCNT_WIDTH, 0x0005
        .equiv  C1CTRL2_DNCNT_MASK, 0x001F

        .equiv  C1CTRL2_DNCNT0, 0x0000
        .equiv  C1CTRL2_DNCNT0_WIDTH, 0x0001
        .equiv  C1CTRL2_DNCNT0_MASK, 0x0001
        .equiv  DNCNT0, 0x0000

        .equiv  C1CTRL2_DNCNT1, 0x0001
        .equiv  C1CTRL2_DNCNT1_WIDTH, 0x0001
        .equiv  C1CTRL2_DNCNT1_MASK, 0x0002
        .equiv  DNCNT1, 0x0001

        .equiv  C1CTRL2_DNCNT2, 0x0002
        .equiv  C1CTRL2_DNCNT2_WIDTH, 0x0001
        .equiv  C1CTRL2_DNCNT2_MASK, 0x0004
        .equiv  DNCNT2, 0x0002

        .equiv  C1CTRL2_DNCNT3, 0x0003
        .equiv  C1CTRL2_DNCNT3_WIDTH, 0x0001
        .equiv  C1CTRL2_DNCNT3_MASK, 0x0008
        .equiv  DNCNT3, 0x0003

        .equiv  C1CTRL2_DNCNT4, 0x0004
        .equiv  C1CTRL2_DNCNT4_WIDTH, 0x0001
        .equiv  C1CTRL2_DNCNT4_MASK, 0x0010
        .equiv  DNCNT4, 0x0004

;----- C1VEC Bits -----------------------------------------------------
        .equiv  C1VEC_ICODE, 0x0000
        .equiv  C1VEC_ICODE_WIDTH, 0x0007
        .equiv  C1VEC_ICODE_MASK, 0x007F

        .equiv  C1VEC_FILHIT, 0x0008
        .equiv  C1VEC_FILHIT_WIDTH, 0x0005
        .equiv  C1VEC_FILHIT_MASK, 0x1F00

        .equiv  C1VEC_ICODE0, 0x0000
        .equiv  C1VEC_ICODE0_WIDTH, 0x0001
        .equiv  C1VEC_ICODE0_MASK, 0x0001
        .equiv  ICODE0, 0x0000

        .equiv  C1VEC_ICODE1, 0x0001
        .equiv  C1VEC_ICODE1_WIDTH, 0x0001
        .equiv  C1VEC_ICODE1_MASK, 0x0002
        .equiv  ICODE1, 0x0001

        .equiv  C1VEC_ICODE2, 0x0002
        .equiv  C1VEC_ICODE2_WIDTH, 0x0001
        .equiv  C1VEC_ICODE2_MASK, 0x0004
        .equiv  ICODE2, 0x0002

        .equiv  C1VEC_ICODE3, 0x0003
        .equiv  C1VEC_ICODE3_WIDTH, 0x0001
        .equiv  C1VEC_ICODE3_MASK, 0x0008
        .equiv  ICODE3, 0x0003

        .equiv  C1VEC_ICODE4, 0x0004
        .equiv  C1VEC_ICODE4_WIDTH, 0x0001
        .equiv  C1VEC_ICODE4_MASK, 0x0010
        .equiv  ICODE4, 0x0004

        .equiv  C1VEC_ICODE5, 0x0005
        .equiv  C1VEC_ICODE5_WIDTH, 0x0001
        .equiv  C1VEC_ICODE5_MASK, 0x0020
        .equiv  ICODE5, 0x0005

        .equiv  C1VEC_ICODE6, 0x0006
        .equiv  C1VEC_ICODE6_WIDTH, 0x0001
        .equiv  C1VEC_ICODE6_MASK, 0x0040
        .equiv  ICODE6, 0x0006

        .equiv  C1VEC_FILHIT0, 0x0008
        .equiv  C1VEC_FILHIT0_WIDTH, 0x0001
        .equiv  C1VEC_FILHIT0_MASK, 0x0100
        .equiv  FILHIT0, 0x0008

        .equiv  C1VEC_FILHIT1, 0x0009
        .equiv  C1VEC_FILHIT1_WIDTH, 0x0001
        .equiv  C1VEC_FILHIT1_MASK, 0x0200
        .equiv  FILHIT1, 0x0009

        .equiv  C1VEC_FILHIT2, 0x000A
        .equiv  C1VEC_FILHIT2_WIDTH, 0x0001
        .equiv  C1VEC_FILHIT2_MASK, 0x0400
        .equiv  FILHIT2, 0x000A

        .equiv  C1VEC_FILHIT3, 0x000B
        .equiv  C1VEC_FILHIT3_WIDTH, 0x0001
        .equiv  C1VEC_FILHIT3_MASK, 0x0800
        .equiv  FILHIT3, 0x000B

        .equiv  C1VEC_FILHIT4, 0x000C
        .equiv  C1VEC_FILHIT4_WIDTH, 0x0001
        .equiv  C1VEC_FILHIT4_MASK, 0x1000
        .equiv  FILHIT4, 0x000C

;----- C1FCTRL Bits -----------------------------------------------------
        .equiv  C1FCTRL_FSA, 0x0000
        .equiv  C1FCTRL_FSA_WIDTH, 0x0005
        .equiv  C1FCTRL_FSA_MASK, 0x001F

        .equiv  C1FCTRL_DMABS, 0x000D
        .equiv  C1FCTRL_DMABS_WIDTH, 0x0003
        .equiv  C1FCTRL_DMABS_MASK, 0xE000

        .equiv  C1FCTRL_FSA0, 0x0000
        .equiv  C1FCTRL_FSA0_WIDTH, 0x0001
        .equiv  C1FCTRL_FSA0_MASK, 0x0001
        .equiv  FSA0, 0x0000

        .equiv  C1FCTRL_FSA1, 0x0001
        .equiv  C1FCTRL_FSA1_WIDTH, 0x0001
        .equiv  C1FCTRL_FSA1_MASK, 0x0002
        .equiv  FSA1, 0x0001

        .equiv  C1FCTRL_FSA2, 0x0002
        .equiv  C1FCTRL_FSA2_WIDTH, 0x0001
        .equiv  C1FCTRL_FSA2_MASK, 0x0004
        .equiv  FSA2, 0x0002

        .equiv  C1FCTRL_FSA3, 0x0003
        .equiv  C1FCTRL_FSA3_WIDTH, 0x0001
        .equiv  C1FCTRL_FSA3_MASK, 0x0008
        .equiv  FSA3, 0x0003

        .equiv  C1FCTRL_FSA4, 0x0004
        .equiv  C1FCTRL_FSA4_WIDTH, 0x0001
        .equiv  C1FCTRL_FSA4_MASK, 0x0010
        .equiv  FSA4, 0x0004

        .equiv  C1FCTRL_DMABS0, 0x000D
        .equiv  C1FCTRL_DMABS0_WIDTH, 0x0001
        .equiv  C1FCTRL_DMABS0_MASK, 0x2000
        .equiv  DMABS0, 0x000D

        .equiv  C1FCTRL_DMABS1, 0x000E
        .equiv  C1FCTRL_DMABS1_WIDTH, 0x0001
        .equiv  C1FCTRL_DMABS1_MASK, 0x4000
        .equiv  DMABS1, 0x000E

        .equiv  C1FCTRL_DMABS2, 0x000F
        .equiv  C1FCTRL_DMABS2_WIDTH, 0x0001
        .equiv  C1FCTRL_DMABS2_MASK, 0x8000
        .equiv  DMABS2, 0x000F

;----- C1FIFO Bits -----------------------------------------------------
        .equiv  C1FIFO_FNRB, 0x0000
        .equiv  C1FIFO_FNRB_WIDTH, 0x0006
        .equiv  C1FIFO_FNRB_MASK, 0x003F

        .equiv  C1FIFO_FBP, 0x0008
        .equiv  C1FIFO_FBP_WIDTH, 0x0006
        .equiv  C1FIFO_FBP_MASK, 0x3F00

        .equiv  C1FIFO_FNRB0, 0x0000
        .equiv  C1FIFO_FNRB0_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB0_MASK, 0x0001
        .equiv  FNRB0, 0x0000

        .equiv  C1FIFO_FNRB1, 0x0001
        .equiv  C1FIFO_FNRB1_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB1_MASK, 0x0002
        .equiv  FNRB1, 0x0001

        .equiv  C1FIFO_FNRB2, 0x0002
        .equiv  C1FIFO_FNRB2_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB2_MASK, 0x0004
        .equiv  FNRB2, 0x0002

        .equiv  C1FIFO_FNRB3, 0x0003
        .equiv  C1FIFO_FNRB3_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB3_MASK, 0x0008
        .equiv  FNRB3, 0x0003

        .equiv  C1FIFO_FNRB4, 0x0004
        .equiv  C1FIFO_FNRB4_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB4_MASK, 0x0010
        .equiv  FNRB4, 0x0004

        .equiv  C1FIFO_FNRB5, 0x0005
        .equiv  C1FIFO_FNRB5_WIDTH, 0x0001
        .equiv  C1FIFO_FNRB5_MASK, 0x0020
        .equiv  FNRB5, 0x0005

        .equiv  C1FIFO_FBP0, 0x0008
        .equiv  C1FIFO_FBP0_WIDTH, 0x0001
        .equiv  C1FIFO_FBP0_MASK, 0x0100
        .equiv  FBP0, 0x0008

        .equiv  C1FIFO_FBP1, 0x0009
        .equiv  C1FIFO_FBP1_WIDTH, 0x0001
        .equiv  C1FIFO_FBP1_MASK, 0x0200
        .equiv  FBP1, 0x0009

        .equiv  C1FIFO_FBP2, 0x000A
        .equiv  C1FIFO_FBP2_WIDTH, 0x0001
        .equiv  C1FIFO_FBP2_MASK, 0x0400
        .equiv  FBP2, 0x000A

        .equiv  C1FIFO_FBP3, 0x000B
        .equiv  C1FIFO_FBP3_WIDTH, 0x0001
        .equiv  C1FIFO_FBP3_MASK, 0x0800
        .equiv  FBP3, 0x000B

        .equiv  C1FIFO_FBP4, 0x000C
        .equiv  C1FIFO_FBP4_WIDTH, 0x0001
        .equiv  C1FIFO_FBP4_MASK, 0x1000
        .equiv  FBP4, 0x000C

        .equiv  C1FIFO_FBP5, 0x000D
        .equiv  C1FIFO_FBP5_WIDTH, 0x0001
        .equiv  C1FIFO_FBP5_MASK, 0x2000
        .equiv  FBP5, 0x000D

;----- C1INTF Bits -----------------------------------------------------
        .equiv  C1INTF_TBIF, 0x0000
        .equiv  C1INTF_TBIF_WIDTH, 0x0001
        .equiv  C1INTF_TBIF_MASK, 0x0001
        .equiv  TBIF, 0x0000

        .equiv  C1INTF_RBIF, 0x0001
        .equiv  C1INTF_RBIF_WIDTH, 0x0001
        .equiv  C1INTF_RBIF_MASK, 0x0002
        .equiv  RBIF, 0x0001

        .equiv  C1INTF_RBOVIF, 0x0002
        .equiv  C1INTF_RBOVIF_WIDTH, 0x0001
        .equiv  C1INTF_RBOVIF_MASK, 0x0004
        .equiv  RBOVIF, 0x0002

        .equiv  C1INTF_FIFOIF, 0x0003
        .equiv  C1INTF_FIFOIF_WIDTH, 0x0001
        .equiv  C1INTF_FIFOIF_MASK, 0x0008
        .equiv  FIFOIF, 0x0003

        .equiv  C1INTF_ERRIF, 0x0005
        .equiv  C1INTF_ERRIF_WIDTH, 0x0001
        .equiv  C1INTF_ERRIF_MASK, 0x0020
        .equiv  ERRIF, 0x0005

        .equiv  C1INTF_WAKIF, 0x0006
        .equiv  C1INTF_WAKIF_WIDTH, 0x0001
        .equiv  C1INTF_WAKIF_MASK, 0x0040
        .equiv  WAKIF, 0x0006

        .equiv  C1INTF_IVRIF, 0x0007
        .equiv  C1INTF_IVRIF_WIDTH, 0x0001
        .equiv  C1INTF_IVRIF_MASK, 0x0080
        .equiv  IVRIF, 0x0007

        .equiv  C1INTF_EWARN, 0x0008
        .equiv  C1INTF_EWARN_WIDTH, 0x0001
        .equiv  C1INTF_EWARN_MASK, 0x0100
        .equiv  EWARN, 0x0008

        .equiv  C1INTF_RXWAR, 0x0009
        .equiv  C1INTF_RXWAR_WIDTH, 0x0001
        .equiv  C1INTF_RXWAR_MASK, 0x0200
        .equiv  RXWAR, 0x0009

        .equiv  C1INTF_TXWAR, 0x000A
        .equiv  C1INTF_TXWAR_WIDTH, 0x0001
        .equiv  C1INTF_TXWAR_MASK, 0x0400
        .equiv  TXWAR, 0x000A

        .equiv  C1INTF_RXBP, 0x000B
        .equiv  C1INTF_RXBP_WIDTH, 0x0001
        .equiv  C1INTF_RXBP_MASK, 0x0800
        .equiv  RXBP, 0x000B

        .equiv  C1INTF_TXBP, 0x000C
        .equiv  C1INTF_TXBP_WIDTH, 0x0001
        .equiv  C1INTF_TXBP_MASK, 0x1000
        .equiv  TXBP, 0x000C

        .equiv  C1INTF_TXBO, 0x000D
        .equiv  C1INTF_TXBO_WIDTH, 0x0001
        .equiv  C1INTF_TXBO_MASK, 0x2000
        .equiv  TXBO, 0x000D

;----- C1INTE Bits -----------------------------------------------------
        .equiv  C1INTE_TBIE, 0x0000
        .equiv  C1INTE_TBIE_WIDTH, 0x0001
        .equiv  C1INTE_TBIE_MASK, 0x0001
        .equiv  TBIE, 0x0000

        .equiv  C1INTE_RBIE, 0x0001
        .equiv  C1INTE_RBIE_WIDTH, 0x0001
        .equiv  C1INTE_RBIE_MASK, 0x0002
        .equiv  RBIE, 0x0001

        .equiv  C1INTE_RBOVIE, 0x0002
        .equiv  C1INTE_RBOVIE_WIDTH, 0x0001
        .equiv  C1INTE_RBOVIE_MASK, 0x0004
        .equiv  RBOVIE, 0x0002

        .equiv  C1INTE_FIFOIE, 0x0003
        .equiv  C1INTE_FIFOIE_WIDTH, 0x0001
        .equiv  C1INTE_FIFOIE_MASK, 0x0008
        .equiv  FIFOIE, 0x0003

        .equiv  C1INTE_ERRIE, 0x0005
        .equiv  C1INTE_ERRIE_WIDTH, 0x0001
        .equiv  C1INTE_ERRIE_MASK, 0x0020
        .equiv  ERRIE, 0x0005

        .equiv  C1INTE_WAKIE, 0x0006
        .equiv  C1INTE_WAKIE_WIDTH, 0x0001
        .equiv  C1INTE_WAKIE_MASK, 0x0040
        .equiv  WAKIE, 0x0006

        .equiv  C1INTE_IVRIE, 0x0007
        .equiv  C1INTE_IVRIE_WIDTH, 0x0001
        .equiv  C1INTE_IVRIE_MASK, 0x0080
        .equiv  IVRIE, 0x0007

;----- C1EC Bits -----------------------------------------------------
        .equiv  C1EC_RERRCNT, 0x0000
        .equiv  C1EC_RERRCNT_WIDTH, 0x0008
        .equiv  C1EC_RERRCNT_MASK, 0x00FF

        .equiv  C1EC_TERRCNT, 0x0008
        .equiv  C1EC_TERRCNT_WIDTH, 0x0008
        .equiv  C1EC_TERRCNT_MASK, 0xFF00

;----- C1CFG1 Bits -----------------------------------------------------
        .equiv  C1CFG1_BRP, 0x0000
        .equiv  C1CFG1_BRP_WIDTH, 0x0006
        .equiv  C1CFG1_BRP_MASK, 0x003F

        .equiv  C1CFG1_SJW, 0x0006
        .equiv  C1CFG1_SJW_WIDTH, 0x0002
        .equiv  C1CFG1_SJW_MASK, 0x00C0

        .equiv  C1CFG1_BRP0, 0x0000
        .equiv  C1CFG1_BRP0_WIDTH, 0x0001
        .equiv  C1CFG1_BRP0_MASK, 0x0001
        .equiv  BRP0, 0x0000

        .equiv  C1CFG1_BRP1, 0x0001
        .equiv  C1CFG1_BRP1_WIDTH, 0x0001
        .equiv  C1CFG1_BRP1_MASK, 0x0002
        .equiv  BRP1, 0x0001

        .equiv  C1CFG1_BRP2, 0x0002
        .equiv  C1CFG1_BRP2_WIDTH, 0x0001
        .equiv  C1CFG1_BRP2_MASK, 0x0004
        .equiv  BRP2, 0x0002

        .equiv  C1CFG1_BRP3, 0x0003
        .equiv  C1CFG1_BRP3_WIDTH, 0x0001
        .equiv  C1CFG1_BRP3_MASK, 0x0008
        .equiv  BRP3, 0x0003

        .equiv  C1CFG1_BRP4, 0x0004
        .equiv  C1CFG1_BRP4_WIDTH, 0x0001
        .equiv  C1CFG1_BRP4_MASK, 0x0010
        .equiv  BRP4, 0x0004

        .equiv  C1CFG1_BRP5, 0x0005
        .equiv  C1CFG1_BRP5_WIDTH, 0x0001
        .equiv  C1CFG1_BRP5_MASK, 0x0020
        .equiv  BRP5, 0x0005

        .equiv  C1CFG1_SJW0, 0x0006
        .equiv  C1CFG1_SJW0_WIDTH, 0x0001
        .equiv  C1CFG1_SJW0_MASK, 0x0040
        .equiv  SJW0, 0x0006

        .equiv  C1CFG1_SJW1, 0x0007
        .equiv  C1CFG1_SJW1_WIDTH, 0x0001
        .equiv  C1CFG1_SJW1_MASK, 0x0080
        .equiv  SJW1, 0x0007

;----- C1CFG2 Bits -----------------------------------------------------
        .equiv  C1CFG2_PRSEG, 0x0000
        .equiv  C1CFG2_PRSEG_WIDTH, 0x0003
        .equiv  C1CFG2_PRSEG_MASK, 0x0007

        .equiv  C1CFG2_SEG1PH, 0x0003
        .equiv  C1CFG2_SEG1PH_WIDTH, 0x0003
        .equiv  C1CFG2_SEG1PH_MASK, 0x0038

        .equiv  C1CFG2_SAM, 0x0006
        .equiv  C1CFG2_SAM_WIDTH, 0x0001
        .equiv  C1CFG2_SAM_MASK, 0x0040
        .equiv  SAM, 0x0006

        .equiv  C1CFG2_SEG2PHTS, 0x0007
        .equiv  C1CFG2_SEG2PHTS_WIDTH, 0x0001
        .equiv  C1CFG2_SEG2PHTS_MASK, 0x0080
        .equiv  SEG2PHTS, 0x0007

        .equiv  C1CFG2_SEG2PH, 0x0008
        .equiv  C1CFG2_SEG2PH_WIDTH, 0x0003
        .equiv  C1CFG2_SEG2PH_MASK, 0x0700

        .equiv  C1CFG2_WAKFIL, 0x000E
        .equiv  C1CFG2_WAKFIL_WIDTH, 0x0001
        .equiv  C1CFG2_WAKFIL_MASK, 0x4000
        .equiv  WAKFIL, 0x000E

        .equiv  C1CFG2_PRSEG0, 0x0000
        .equiv  C1CFG2_PRSEG0_WIDTH, 0x0001
        .equiv  C1CFG2_PRSEG0_MASK, 0x0001
        .equiv  PRSEG0, 0x0000

        .equiv  C1CFG2_PRSEG1, 0x0001
        .equiv  C1CFG2_PRSEG1_WIDTH, 0x0001
        .equiv  C1CFG2_PRSEG1_MASK, 0x0002
        .equiv  PRSEG1, 0x0001

        .equiv  C1CFG2_PRSEG2, 0x0002
        .equiv  C1CFG2_PRSEG2_WIDTH, 0x0001
        .equiv  C1CFG2_PRSEG2_MASK, 0x0004
        .equiv  PRSEG2, 0x0002

        .equiv  C1CFG2_SEG1PH0, 0x0003
        .equiv  C1CFG2_SEG1PH0_WIDTH, 0x0001
        .equiv  C1CFG2_SEG1PH0_MASK, 0x0008
        .equiv  SEG1PH0, 0x0003

        .equiv  C1CFG2_SEG1PH1, 0x0004
        .equiv  C1CFG2_SEG1PH1_WIDTH, 0x0001
        .equiv  C1CFG2_SEG1PH1_MASK, 0x0010
        .equiv  SEG1PH1, 0x0004

        .equiv  C1CFG2_SEG1PH2, 0x0005
        .equiv  C1CFG2_SEG1PH2_WIDTH, 0x0001
        .equiv  C1CFG2_SEG1PH2_MASK, 0x0020
        .equiv  SEG1PH2, 0x0005

        .equiv  C1CFG2_SEG2PH0, 0x0008
        .equiv  C1CFG2_SEG2PH0_WIDTH, 0x0001
        .equiv  C1CFG2_SEG2PH0_MASK, 0x0100
        .equiv  SEG2PH0, 0x0008

        .equiv  C1CFG2_SEG2PH1, 0x0009
        .equiv  C1CFG2_SEG2PH1_WIDTH, 0x0001
        .equiv  C1CFG2_SEG2PH1_MASK, 0x0200
        .equiv  SEG2PH1, 0x0009

        .equiv  C1CFG2_SEG2PH2, 0x000A
        .equiv  C1CFG2_SEG2PH2_WIDTH, 0x0001
        .equiv  C1CFG2_SEG2PH2_MASK, 0x0400
        .equiv  SEG2PH2, 0x000A

;----- C1FEN1 Bits -----------------------------------------------------
        .equiv  C1FEN1_FLTEN0, 0x0000
        .equiv  C1FEN1_FLTEN0_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN0_MASK, 0x0001
        .equiv  FLTEN0, 0x0000

        .equiv  C1FEN1_FLTEN1, 0x0001
        .equiv  C1FEN1_FLTEN1_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN1_MASK, 0x0002
        .equiv  FLTEN1, 0x0001

        .equiv  C1FEN1_FLTEN2, 0x0002
        .equiv  C1FEN1_FLTEN2_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN2_MASK, 0x0004
        .equiv  FLTEN2, 0x0002

        .equiv  C1FEN1_FLTEN3, 0x0003
        .equiv  C1FEN1_FLTEN3_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN3_MASK, 0x0008
        .equiv  FLTEN3, 0x0003

        .equiv  C1FEN1_FLTEN4, 0x0004
        .equiv  C1FEN1_FLTEN4_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN4_MASK, 0x0010
        .equiv  FLTEN4, 0x0004

        .equiv  C1FEN1_FLTEN5, 0x0005
        .equiv  C1FEN1_FLTEN5_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN5_MASK, 0x0020
        .equiv  FLTEN5, 0x0005

        .equiv  C1FEN1_FLTEN6, 0x0006
        .equiv  C1FEN1_FLTEN6_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN6_MASK, 0x0040
        .equiv  FLTEN6, 0x0006

        .equiv  C1FEN1_FLTEN7, 0x0007
        .equiv  C1FEN1_FLTEN7_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN7_MASK, 0x0080
        .equiv  FLTEN7, 0x0007

        .equiv  C1FEN1_FLTEN8, 0x0008
        .equiv  C1FEN1_FLTEN8_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN8_MASK, 0x0100
        .equiv  FLTEN8, 0x0008

        .equiv  C1FEN1_FLTEN9, 0x0009
        .equiv  C1FEN1_FLTEN9_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN9_MASK, 0x0200
        .equiv  FLTEN9, 0x0009

        .equiv  C1FEN1_FLTEN10, 0x000A
        .equiv  C1FEN1_FLTEN10_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN10_MASK, 0x0400
        .equiv  FLTEN10, 0x000A

        .equiv  C1FEN1_FLTEN11, 0x000B
        .equiv  C1FEN1_FLTEN11_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN11_MASK, 0x0800
        .equiv  FLTEN11, 0x000B

        .equiv  C1FEN1_FLTEN12, 0x000C
        .equiv  C1FEN1_FLTEN12_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN12_MASK, 0x1000
        .equiv  FLTEN12, 0x000C

        .equiv  C1FEN1_FLTEN13, 0x000D
        .equiv  C1FEN1_FLTEN13_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN13_MASK, 0x2000
        .equiv  FLTEN13, 0x000D

        .equiv  C1FEN1_FLTEN14, 0x000E
        .equiv  C1FEN1_FLTEN14_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN14_MASK, 0x4000
        .equiv  FLTEN14, 0x000E

        .equiv  C1FEN1_FLTEN15, 0x000F
        .equiv  C1FEN1_FLTEN15_WIDTH, 0x0001
        .equiv  C1FEN1_FLTEN15_MASK, 0x8000
        .equiv  FLTEN15, 0x000F

;----- C1FMSKSEL1 Bits -----------------------------------------------------
        .equiv  C1FMSKSEL1_F0MSK, 0x0000
        .equiv  C1FMSKSEL1_F0MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F0MSK_MASK, 0x0003

        .equiv  C1FMSKSEL1_F1MSK, 0x0002
        .equiv  C1FMSKSEL1_F1MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F1MSK_MASK, 0x000C

        .equiv  C1FMSKSEL1_F2MSK, 0x0004
        .equiv  C1FMSKSEL1_F2MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F2MSK_MASK, 0x0030

        .equiv  C1FMSKSEL1_F3MSK, 0x0006
        .equiv  C1FMSKSEL1_F3MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F3MSK_MASK, 0x00C0

        .equiv  C1FMSKSEL1_F4MSK, 0x0008
        .equiv  C1FMSKSEL1_F4MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F4MSK_MASK, 0x0300

        .equiv  C1FMSKSEL1_F5MSK, 0x000A
        .equiv  C1FMSKSEL1_F5MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F5MSK_MASK, 0x0C00

        .equiv  C1FMSKSEL1_F6MSK, 0x000C
        .equiv  C1FMSKSEL1_F6MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F6MSK_MASK, 0x3000

        .equiv  C1FMSKSEL1_F7MSK, 0x000E
        .equiv  C1FMSKSEL1_F7MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL1_F7MSK_MASK, 0xC000

        .equiv  C1FMSKSEL1_F0MSK0, 0x0000
        .equiv  C1FMSKSEL1_F0MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F0MSK0_MASK, 0x0001
        .equiv  F0MSK0, 0x0000

        .equiv  C1FMSKSEL1_F0MSK1, 0x0001
        .equiv  C1FMSKSEL1_F0MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F0MSK1_MASK, 0x0002
        .equiv  F0MSK1, 0x0001

        .equiv  C1FMSKSEL1_F1MSK0, 0x0002
        .equiv  C1FMSKSEL1_F1MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F1MSK0_MASK, 0x0004
        .equiv  F1MSK0, 0x0002

        .equiv  C1FMSKSEL1_F1MSK1, 0x0003
        .equiv  C1FMSKSEL1_F1MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F1MSK1_MASK, 0x0008
        .equiv  F1MSK1, 0x0003

        .equiv  C1FMSKSEL1_F2MSK0, 0x0004
        .equiv  C1FMSKSEL1_F2MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F2MSK0_MASK, 0x0010
        .equiv  F2MSK0, 0x0004

        .equiv  C1FMSKSEL1_F2MSK1, 0x0005
        .equiv  C1FMSKSEL1_F2MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F2MSK1_MASK, 0x0020
        .equiv  F2MSK1, 0x0005

        .equiv  C1FMSKSEL1_F3MSK0, 0x0006
        .equiv  C1FMSKSEL1_F3MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F3MSK0_MASK, 0x0040
        .equiv  F3MSK0, 0x0006

        .equiv  C1FMSKSEL1_F3MSK1, 0x0007
        .equiv  C1FMSKSEL1_F3MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F3MSK1_MASK, 0x0080
        .equiv  F3MSK1, 0x0007

        .equiv  C1FMSKSEL1_F4MSK0, 0x0008
        .equiv  C1FMSKSEL1_F4MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F4MSK0_MASK, 0x0100
        .equiv  F4MSK0, 0x0008

        .equiv  C1FMSKSEL1_F4MSK1, 0x0009
        .equiv  C1FMSKSEL1_F4MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F4MSK1_MASK, 0x0200
        .equiv  F4MSK1, 0x0009

        .equiv  C1FMSKSEL1_F5MSK0, 0x000A
        .equiv  C1FMSKSEL1_F5MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F5MSK0_MASK, 0x0400
        .equiv  F5MSK0, 0x000A

        .equiv  C1FMSKSEL1_F5MSK1, 0x000B
        .equiv  C1FMSKSEL1_F5MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F5MSK1_MASK, 0x0800
        .equiv  F5MSK1, 0x000B

        .equiv  C1FMSKSEL1_F6MSK0, 0x000C
        .equiv  C1FMSKSEL1_F6MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F6MSK0_MASK, 0x1000
        .equiv  F6MSK0, 0x000C

        .equiv  C1FMSKSEL1_F6MSK1, 0x000D
        .equiv  C1FMSKSEL1_F6MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F6MSK1_MASK, 0x2000
        .equiv  F6MSK1, 0x000D

        .equiv  C1FMSKSEL1_F7MSK0, 0x000E
        .equiv  C1FMSKSEL1_F7MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F7MSK0_MASK, 0x4000
        .equiv  F7MSK0, 0x000E

        .equiv  C1FMSKSEL1_F7MSK1, 0x000F
        .equiv  C1FMSKSEL1_F7MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL1_F7MSK1_MASK, 0x8000
        .equiv  F7MSK1, 0x000F

;----- C1FMSKSEL2 Bits -----------------------------------------------------
        .equiv  C1FMSKSEL2_F8MSK, 0x0000
        .equiv  C1FMSKSEL2_F8MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F8MSK_MASK, 0x0003

        .equiv  C1FMSKSEL2_F9MSK, 0x0002
        .equiv  C1FMSKSEL2_F9MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F9MSK_MASK, 0x000C

        .equiv  C1FMSKSEL2_F10MSK, 0x0004
        .equiv  C1FMSKSEL2_F10MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F10MSK_MASK, 0x0030

        .equiv  C1FMSKSEL2_F11MSK, 0x0006
        .equiv  C1FMSKSEL2_F11MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F11MSK_MASK, 0x00C0

        .equiv  C1FMSKSEL2_F12MSK, 0x0008
        .equiv  C1FMSKSEL2_F12MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F12MSK_MASK, 0x0300

        .equiv  C1FMSKSEL2_F13MSK, 0x000A
        .equiv  C1FMSKSEL2_F13MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F13MSK_MASK, 0x0C00

        .equiv  C1FMSKSEL2_F14MSK, 0x000C
        .equiv  C1FMSKSEL2_F14MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F14MSK_MASK, 0x3000

        .equiv  C1FMSKSEL2_F15MSK, 0x000E
        .equiv  C1FMSKSEL2_F15MSK_WIDTH, 0x0002
        .equiv  C1FMSKSEL2_F15MSK_MASK, 0xC000

        .equiv  C1FMSKSEL2_F8MSK0, 0x0000
        .equiv  C1FMSKSEL2_F8MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F8MSK0_MASK, 0x0001
        .equiv  F8MSK0, 0x0000

        .equiv  C1FMSKSEL2_F8MSK1, 0x0001
        .equiv  C1FMSKSEL2_F8MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F8MSK1_MASK, 0x0002
        .equiv  F8MSK1, 0x0001

        .equiv  C1FMSKSEL2_F9MSK0, 0x0002
        .equiv  C1FMSKSEL2_F9MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F9MSK0_MASK, 0x0004
        .equiv  F9MSK0, 0x0002

        .equiv  C1FMSKSEL2_F9MSK1, 0x0003
        .equiv  C1FMSKSEL2_F9MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F9MSK1_MASK, 0x0008
        .equiv  F9MSK1, 0x0003

        .equiv  C1FMSKSEL2_F10MSK0, 0x0004
        .equiv  C1FMSKSEL2_F10MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F10MSK0_MASK, 0x0010
        .equiv  F10MSK0, 0x0004

        .equiv  C1FMSKSEL2_F10MSK1, 0x0005
        .equiv  C1FMSKSEL2_F10MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F10MSK1_MASK, 0x0020
        .equiv  F10MSK1, 0x0005

        .equiv  C1FMSKSEL2_F11MSK0, 0x0006
        .equiv  C1FMSKSEL2_F11MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F11MSK0_MASK, 0x0040
        .equiv  F11MSK0, 0x0006

        .equiv  C1FMSKSEL2_F11MSK1, 0x0007
        .equiv  C1FMSKSEL2_F11MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F11MSK1_MASK, 0x0080
        .equiv  F11MSK1, 0x0007

        .equiv  C1FMSKSEL2_F12MSK0, 0x0008
        .equiv  C1FMSKSEL2_F12MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F12MSK0_MASK, 0x0100
        .equiv  F12MSK0, 0x0008

        .equiv  C1FMSKSEL2_F12MSK1, 0x0009
        .equiv  C1FMSKSEL2_F12MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F12MSK1_MASK, 0x0200
        .equiv  F12MSK1, 0x0009

        .equiv  C1FMSKSEL2_F13MSK0, 0x000A
        .equiv  C1FMSKSEL2_F13MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F13MSK0_MASK, 0x0400
        .equiv  F13MSK0, 0x000A

        .equiv  C1FMSKSEL2_F13MSK1, 0x000B
        .equiv  C1FMSKSEL2_F13MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F13MSK1_MASK, 0x0800
        .equiv  F13MSK1, 0x000B

        .equiv  C1FMSKSEL2_F14MSK0, 0x000C
        .equiv  C1FMSKSEL2_F14MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F14MSK0_MASK, 0x1000
        .equiv  F14MSK0, 0x000C

        .equiv  C1FMSKSEL2_F14MSK1, 0x000D
        .equiv  C1FMSKSEL2_F14MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F14MSK1_MASK, 0x2000
        .equiv  F14MSK1, 0x000D

        .equiv  C1FMSKSEL2_F15MSK0, 0x000E
        .equiv  C1FMSKSEL2_F15MSK0_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F15MSK0_MASK, 0x4000
        .equiv  F15MSK0, 0x000E

        .equiv  C1FMSKSEL2_F15MSK1, 0x000F
        .equiv  C1FMSKSEL2_F15MSK1_WIDTH, 0x0001
        .equiv  C1FMSKSEL2_F15MSK1_MASK, 0x8000
        .equiv  F15MSK1, 0x000F

;----- C1BUFPNT1 Bits -----------------------------------------------------
        .equiv  C1BUFPNT1_F0BP, 0x0000
        .equiv  C1BUFPNT1_F0BP_WIDTH, 0x0004
        .equiv  C1BUFPNT1_F0BP_MASK, 0x000F

        .equiv  C1BUFPNT1_F1BP, 0x0004
        .equiv  C1BUFPNT1_F1BP_WIDTH, 0x0004
        .equiv  C1BUFPNT1_F1BP_MASK, 0x00F0

        .equiv  C1BUFPNT1_F2BP, 0x0008
        .equiv  C1BUFPNT1_F2BP_WIDTH, 0x0004
        .equiv  C1BUFPNT1_F2BP_MASK, 0x0F00

        .equiv  C1BUFPNT1_F3BP, 0x000C
        .equiv  C1BUFPNT1_F3BP_WIDTH, 0x0004
        .equiv  C1BUFPNT1_F3BP_MASK, 0xF000

        .equiv  C1BUFPNT1_F0BP0, 0x0000
        .equiv  C1BUFPNT1_F0BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F0BP0_MASK, 0x0001
        .equiv  F0BP0, 0x0000

        .equiv  C1BUFPNT1_F0BP1, 0x0001
        .equiv  C1BUFPNT1_F0BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F0BP1_MASK, 0x0002
        .equiv  F0BP1, 0x0001

        .equiv  C1BUFPNT1_F0BP2, 0x0002
        .equiv  C1BUFPNT1_F0BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F0BP2_MASK, 0x0004
        .equiv  F0BP2, 0x0002

        .equiv  C1BUFPNT1_F0BP3, 0x0003
        .equiv  C1BUFPNT1_F0BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F0BP3_MASK, 0x0008
        .equiv  F0BP3, 0x0003

        .equiv  C1BUFPNT1_F1BP0, 0x0004
        .equiv  C1BUFPNT1_F1BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F1BP0_MASK, 0x0010
        .equiv  F1BP0, 0x0004

        .equiv  C1BUFPNT1_F1BP1, 0x0005
        .equiv  C1BUFPNT1_F1BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F1BP1_MASK, 0x0020
        .equiv  F1BP1, 0x0005

        .equiv  C1BUFPNT1_F1BP2, 0x0006
        .equiv  C1BUFPNT1_F1BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F1BP2_MASK, 0x0040
        .equiv  F1BP2, 0x0006

        .equiv  C1BUFPNT1_F1BP3, 0x0007
        .equiv  C1BUFPNT1_F1BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F1BP3_MASK, 0x0080
        .equiv  F1BP3, 0x0007

        .equiv  C1BUFPNT1_F2BP0, 0x0008
        .equiv  C1BUFPNT1_F2BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F2BP0_MASK, 0x0100
        .equiv  F2BP0, 0x0008

        .equiv  C1BUFPNT1_F2BP1, 0x0009
        .equiv  C1BUFPNT1_F2BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F2BP1_MASK, 0x0200
        .equiv  F2BP1, 0x0009

        .equiv  C1BUFPNT1_F2BP2, 0x000A
        .equiv  C1BUFPNT1_F2BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F2BP2_MASK, 0x0400
        .equiv  F2BP2, 0x000A

        .equiv  C1BUFPNT1_F2BP3, 0x000B
        .equiv  C1BUFPNT1_F2BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F2BP3_MASK, 0x0800
        .equiv  F2BP3, 0x000B

        .equiv  C1BUFPNT1_F3BP0, 0x000C
        .equiv  C1BUFPNT1_F3BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F3BP0_MASK, 0x1000
        .equiv  F3BP0, 0x000C

        .equiv  C1BUFPNT1_F3BP1, 0x000D
        .equiv  C1BUFPNT1_F3BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F3BP1_MASK, 0x2000
        .equiv  F3BP1, 0x000D

        .equiv  C1BUFPNT1_F3BP2, 0x000E
        .equiv  C1BUFPNT1_F3BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F3BP2_MASK, 0x4000
        .equiv  F3BP2, 0x000E

        .equiv  C1BUFPNT1_F3BP3, 0x000F
        .equiv  C1BUFPNT1_F3BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT1_F3BP3_MASK, 0x8000
        .equiv  F3BP3, 0x000F

;----- C1RXFUL1 Bits -----------------------------------------------------
        .equiv  C1RXFUL1_RXFUL0, 0x0000
        .equiv  C1RXFUL1_RXFUL0_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL0_MASK, 0x0001
        .equiv  RXFUL0, 0x0000

        .equiv  C1RXFUL1_RXFUL1, 0x0001
        .equiv  C1RXFUL1_RXFUL1_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL1_MASK, 0x0002
        .equiv  RXFUL1, 0x0001

        .equiv  C1RXFUL1_RXFUL2, 0x0002
        .equiv  C1RXFUL1_RXFUL2_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL2_MASK, 0x0004
        .equiv  RXFUL2, 0x0002

        .equiv  C1RXFUL1_RXFUL3, 0x0003
        .equiv  C1RXFUL1_RXFUL3_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL3_MASK, 0x0008
        .equiv  RXFUL3, 0x0003

        .equiv  C1RXFUL1_RXFUL4, 0x0004
        .equiv  C1RXFUL1_RXFUL4_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL4_MASK, 0x0010
        .equiv  RXFUL4, 0x0004

        .equiv  C1RXFUL1_RXFUL5, 0x0005
        .equiv  C1RXFUL1_RXFUL5_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL5_MASK, 0x0020
        .equiv  RXFUL5, 0x0005

        .equiv  C1RXFUL1_RXFUL6, 0x0006
        .equiv  C1RXFUL1_RXFUL6_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL6_MASK, 0x0040
        .equiv  RXFUL6, 0x0006

        .equiv  C1RXFUL1_RXFUL7, 0x0007
        .equiv  C1RXFUL1_RXFUL7_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL7_MASK, 0x0080
        .equiv  RXFUL7, 0x0007

        .equiv  C1RXFUL1_RXFUL8, 0x0008
        .equiv  C1RXFUL1_RXFUL8_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL8_MASK, 0x0100
        .equiv  RXFUL8, 0x0008

        .equiv  C1RXFUL1_RXFUL9, 0x0009
        .equiv  C1RXFUL1_RXFUL9_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL9_MASK, 0x0200
        .equiv  RXFUL9, 0x0009

        .equiv  C1RXFUL1_RXFUL10, 0x000A
        .equiv  C1RXFUL1_RXFUL10_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL10_MASK, 0x0400
        .equiv  RXFUL10, 0x000A

        .equiv  C1RXFUL1_RXFUL11, 0x000B
        .equiv  C1RXFUL1_RXFUL11_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL11_MASK, 0x0800
        .equiv  RXFUL11, 0x000B

        .equiv  C1RXFUL1_RXFUL12, 0x000C
        .equiv  C1RXFUL1_RXFUL12_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL12_MASK, 0x1000
        .equiv  RXFUL12, 0x000C

        .equiv  C1RXFUL1_RXFUL13, 0x000D
        .equiv  C1RXFUL1_RXFUL13_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL13_MASK, 0x2000
        .equiv  RXFUL13, 0x000D

        .equiv  C1RXFUL1_RXFUL14, 0x000E
        .equiv  C1RXFUL1_RXFUL14_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL14_MASK, 0x4000
        .equiv  RXFUL14, 0x000E

        .equiv  C1RXFUL1_RXFUL15, 0x000F
        .equiv  C1RXFUL1_RXFUL15_WIDTH, 0x0001
        .equiv  C1RXFUL1_RXFUL15_MASK, 0x8000
        .equiv  RXFUL15, 0x000F

;----- C1BUFPNT2 Bits -----------------------------------------------------
        .equiv  C1BUFPNT2_F4BP, 0x0000
        .equiv  C1BUFPNT2_F4BP_WIDTH, 0x0004
        .equiv  C1BUFPNT2_F4BP_MASK, 0x000F

        .equiv  C1BUFPNT2_F5BP, 0x0004
        .equiv  C1BUFPNT2_F5BP_WIDTH, 0x0004
        .equiv  C1BUFPNT2_F5BP_MASK, 0x00F0

        .equiv  C1BUFPNT2_F6BP, 0x0008
        .equiv  C1BUFPNT2_F6BP_WIDTH, 0x0004
        .equiv  C1BUFPNT2_F6BP_MASK, 0x0F00

        .equiv  C1BUFPNT2_F7BP, 0x000C
        .equiv  C1BUFPNT2_F7BP_WIDTH, 0x0004
        .equiv  C1BUFPNT2_F7BP_MASK, 0xF000

        .equiv  C1BUFPNT2_F4BP0, 0x0000
        .equiv  C1BUFPNT2_F4BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F4BP0_MASK, 0x0001
        .equiv  F4BP0, 0x0000

        .equiv  C1BUFPNT2_F4BP1, 0x0001
        .equiv  C1BUFPNT2_F4BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F4BP1_MASK, 0x0002
        .equiv  F4BP1, 0x0001

        .equiv  C1BUFPNT2_F4BP2, 0x0002
        .equiv  C1BUFPNT2_F4BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F4BP2_MASK, 0x0004
        .equiv  F4BP2, 0x0002

        .equiv  C1BUFPNT2_F4BP3, 0x0003
        .equiv  C1BUFPNT2_F4BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F4BP3_MASK, 0x0008
        .equiv  F4BP3, 0x0003

        .equiv  C1BUFPNT2_F5BP0, 0x0004
        .equiv  C1BUFPNT2_F5BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F5BP0_MASK, 0x0010
        .equiv  F5BP0, 0x0004

        .equiv  C1BUFPNT2_F5BP1, 0x0005
        .equiv  C1BUFPNT2_F5BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F5BP1_MASK, 0x0020
        .equiv  F5BP1, 0x0005

        .equiv  C1BUFPNT2_F5BP2, 0x0006
        .equiv  C1BUFPNT2_F5BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F5BP2_MASK, 0x0040
        .equiv  F5BP2, 0x0006

        .equiv  C1BUFPNT2_F5BP3, 0x0007
        .equiv  C1BUFPNT2_F5BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F5BP3_MASK, 0x0080
        .equiv  F5BP3, 0x0007

        .equiv  C1BUFPNT2_F6BP0, 0x0008
        .equiv  C1BUFPNT2_F6BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F6BP0_MASK, 0x0100
        .equiv  F6BP0, 0x0008

        .equiv  C1BUFPNT2_F6BP1, 0x0009
        .equiv  C1BUFPNT2_F6BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F6BP1_MASK, 0x0200
        .equiv  F6BP1, 0x0009

        .equiv  C1BUFPNT2_F6BP2, 0x000A
        .equiv  C1BUFPNT2_F6BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F6BP2_MASK, 0x0400
        .equiv  F6BP2, 0x000A

        .equiv  C1BUFPNT2_F6BP3, 0x000B
        .equiv  C1BUFPNT2_F6BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F6BP3_MASK, 0x0800
        .equiv  F6BP3, 0x000B

        .equiv  C1BUFPNT2_F7BP0, 0x000C
        .equiv  C1BUFPNT2_F7BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F7BP0_MASK, 0x1000
        .equiv  F7BP0, 0x000C

        .equiv  C1BUFPNT2_F7BP1, 0x000D
        .equiv  C1BUFPNT2_F7BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F7BP1_MASK, 0x2000
        .equiv  F7BP1, 0x000D

        .equiv  C1BUFPNT2_F7BP2, 0x000E
        .equiv  C1BUFPNT2_F7BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F7BP2_MASK, 0x4000
        .equiv  F7BP2, 0x000E

        .equiv  C1BUFPNT2_F7BP3, 0x000F
        .equiv  C1BUFPNT2_F7BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT2_F7BP3_MASK, 0x8000
        .equiv  F7BP3, 0x000F

;----- C1RXFUL2 Bits -----------------------------------------------------
        .equiv  C1RXFUL2_RXFUL16, 0x0000
        .equiv  C1RXFUL2_RXFUL16_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL16_MASK, 0x0001
        .equiv  RXFUL16, 0x0000

        .equiv  C1RXFUL2_RXFUL17, 0x0001
        .equiv  C1RXFUL2_RXFUL17_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL17_MASK, 0x0002
        .equiv  RXFUL17, 0x0001

        .equiv  C1RXFUL2_RXFUL18, 0x0002
        .equiv  C1RXFUL2_RXFUL18_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL18_MASK, 0x0004
        .equiv  RXFUL18, 0x0002

        .equiv  C1RXFUL2_RXFUL19, 0x0003
        .equiv  C1RXFUL2_RXFUL19_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL19_MASK, 0x0008
        .equiv  RXFUL19, 0x0003

        .equiv  C1RXFUL2_RXFUL20, 0x0004
        .equiv  C1RXFUL2_RXFUL20_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL20_MASK, 0x0010
        .equiv  RXFUL20, 0x0004

        .equiv  C1RXFUL2_RXFUL21, 0x0005
        .equiv  C1RXFUL2_RXFUL21_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL21_MASK, 0x0020
        .equiv  RXFUL21, 0x0005

        .equiv  C1RXFUL2_RXFUL22, 0x0006
        .equiv  C1RXFUL2_RXFUL22_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL22_MASK, 0x0040
        .equiv  RXFUL22, 0x0006

        .equiv  C1RXFUL2_RXFUL23, 0x0007
        .equiv  C1RXFUL2_RXFUL23_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL23_MASK, 0x0080
        .equiv  RXFUL23, 0x0007

        .equiv  C1RXFUL2_RXFUL24, 0x0008
        .equiv  C1RXFUL2_RXFUL24_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL24_MASK, 0x0100
        .equiv  RXFUL24, 0x0008

        .equiv  C1RXFUL2_RXFUL25, 0x0009
        .equiv  C1RXFUL2_RXFUL25_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL25_MASK, 0x0200
        .equiv  RXFUL25, 0x0009

        .equiv  C1RXFUL2_RXFUL26, 0x000A
        .equiv  C1RXFUL2_RXFUL26_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL26_MASK, 0x0400
        .equiv  RXFUL26, 0x000A

        .equiv  C1RXFUL2_RXFUL27, 0x000B
        .equiv  C1RXFUL2_RXFUL27_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL27_MASK, 0x0800
        .equiv  RXFUL27, 0x000B

        .equiv  C1RXFUL2_RXFUL28, 0x000C
        .equiv  C1RXFUL2_RXFUL28_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL28_MASK, 0x1000
        .equiv  RXFUL28, 0x000C

        .equiv  C1RXFUL2_RXFUL29, 0x000D
        .equiv  C1RXFUL2_RXFUL29_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL29_MASK, 0x2000
        .equiv  RXFUL29, 0x000D

        .equiv  C1RXFUL2_RXFUL30, 0x000E
        .equiv  C1RXFUL2_RXFUL30_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL30_MASK, 0x4000
        .equiv  RXFUL30, 0x000E

        .equiv  C1RXFUL2_RXFUL31, 0x000F
        .equiv  C1RXFUL2_RXFUL31_WIDTH, 0x0001
        .equiv  C1RXFUL2_RXFUL31_MASK, 0x8000
        .equiv  RXFUL31, 0x000F

;----- C1BUFPNT3 Bits -----------------------------------------------------
        .equiv  C1BUFPNT3_F8BP, 0x0000
        .equiv  C1BUFPNT3_F8BP_WIDTH, 0x0004
        .equiv  C1BUFPNT3_F8BP_MASK, 0x000F

        .equiv  C1BUFPNT3_F9BP, 0x0004
        .equiv  C1BUFPNT3_F9BP_WIDTH, 0x0004
        .equiv  C1BUFPNT3_F9BP_MASK, 0x00F0

        .equiv  C1BUFPNT3_F10BP, 0x0008
        .equiv  C1BUFPNT3_F10BP_WIDTH, 0x0004
        .equiv  C1BUFPNT3_F10BP_MASK, 0x0F00

        .equiv  C1BUFPNT3_F11BP, 0x000C
        .equiv  C1BUFPNT3_F11BP_WIDTH, 0x0004
        .equiv  C1BUFPNT3_F11BP_MASK, 0xF000

        .equiv  C1BUFPNT3_F8BP0, 0x0000
        .equiv  C1BUFPNT3_F8BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F8BP0_MASK, 0x0001
        .equiv  F8BP0, 0x0000

        .equiv  C1BUFPNT3_F8BP1, 0x0001
        .equiv  C1BUFPNT3_F8BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F8BP1_MASK, 0x0002
        .equiv  F8BP1, 0x0001

        .equiv  C1BUFPNT3_F8BP2, 0x0002
        .equiv  C1BUFPNT3_F8BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F8BP2_MASK, 0x0004
        .equiv  F8BP2, 0x0002

        .equiv  C1BUFPNT3_F8BP3, 0x0003
        .equiv  C1BUFPNT3_F8BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F8BP3_MASK, 0x0008
        .equiv  F8BP3, 0x0003

        .equiv  C1BUFPNT3_F9BP0, 0x0004
        .equiv  C1BUFPNT3_F9BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F9BP0_MASK, 0x0010
        .equiv  F9BP0, 0x0004

        .equiv  C1BUFPNT3_F9BP1, 0x0005
        .equiv  C1BUFPNT3_F9BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F9BP1_MASK, 0x0020
        .equiv  F9BP1, 0x0005

        .equiv  C1BUFPNT3_F9BP2, 0x0006
        .equiv  C1BUFPNT3_F9BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F9BP2_MASK, 0x0040
        .equiv  F9BP2, 0x0006

        .equiv  C1BUFPNT3_F9BP3, 0x0007
        .equiv  C1BUFPNT3_F9BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F9BP3_MASK, 0x0080
        .equiv  F9BP3, 0x0007

        .equiv  C1BUFPNT3_F10BP0, 0x0008
        .equiv  C1BUFPNT3_F10BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F10BP0_MASK, 0x0100
        .equiv  F10BP0, 0x0008

        .equiv  C1BUFPNT3_F10BP1, 0x0009
        .equiv  C1BUFPNT3_F10BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F10BP1_MASK, 0x0200
        .equiv  F10BP1, 0x0009

        .equiv  C1BUFPNT3_F10BP2, 0x000A
        .equiv  C1BUFPNT3_F10BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F10BP2_MASK, 0x0400
        .equiv  F10BP2, 0x000A

        .equiv  C1BUFPNT3_F10BP3, 0x000B
        .equiv  C1BUFPNT3_F10BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F10BP3_MASK, 0x0800
        .equiv  F10BP3, 0x000B

        .equiv  C1BUFPNT3_F11BP0, 0x000C
        .equiv  C1BUFPNT3_F11BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F11BP0_MASK, 0x1000
        .equiv  F11BP0, 0x000C

        .equiv  C1BUFPNT3_F11BP1, 0x000D
        .equiv  C1BUFPNT3_F11BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F11BP1_MASK, 0x2000
        .equiv  F11BP1, 0x000D

        .equiv  C1BUFPNT3_F11BP2, 0x000E
        .equiv  C1BUFPNT3_F11BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F11BP2_MASK, 0x4000
        .equiv  F11BP2, 0x000E

        .equiv  C1BUFPNT3_F11BP3, 0x000F
        .equiv  C1BUFPNT3_F11BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT3_F11BP3_MASK, 0x8000
        .equiv  F11BP3, 0x000F

;----- C1BUFPNT4 Bits -----------------------------------------------------
        .equiv  C1BUFPNT4_F12BP, 0x0000
        .equiv  C1BUFPNT4_F12BP_WIDTH, 0x0004
        .equiv  C1BUFPNT4_F12BP_MASK, 0x000F

        .equiv  C1BUFPNT4_F13BP, 0x0004
        .equiv  C1BUFPNT4_F13BP_WIDTH, 0x0004
        .equiv  C1BUFPNT4_F13BP_MASK, 0x00F0

        .equiv  C1BUFPNT4_F14BP, 0x0008
        .equiv  C1BUFPNT4_F14BP_WIDTH, 0x0004
        .equiv  C1BUFPNT4_F14BP_MASK, 0x0F00

        .equiv  C1BUFPNT4_F15BP, 0x000C
        .equiv  C1BUFPNT4_F15BP_WIDTH, 0x0004
        .equiv  C1BUFPNT4_F15BP_MASK, 0xF000

        .equiv  C1BUFPNT4_F12BP0, 0x0000
        .equiv  C1BUFPNT4_F12BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F12BP0_MASK, 0x0001
        .equiv  F12BP0, 0x0000

        .equiv  C1BUFPNT4_F12BP1, 0x0001
        .equiv  C1BUFPNT4_F12BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F12BP1_MASK, 0x0002
        .equiv  F12BP1, 0x0001

        .equiv  C1BUFPNT4_F12BP2, 0x0002
        .equiv  C1BUFPNT4_F12BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F12BP2_MASK, 0x0004
        .equiv  F12BP2, 0x0002

        .equiv  C1BUFPNT4_F12BP3, 0x0003
        .equiv  C1BUFPNT4_F12BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F12BP3_MASK, 0x0008
        .equiv  F12BP3, 0x0003

        .equiv  C1BUFPNT4_F13BP0, 0x0004
        .equiv  C1BUFPNT4_F13BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F13BP0_MASK, 0x0010
        .equiv  F13BP0, 0x0004

        .equiv  C1BUFPNT4_F13BP1, 0x0005
        .equiv  C1BUFPNT4_F13BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F13BP1_MASK, 0x0020
        .equiv  F13BP1, 0x0005

        .equiv  C1BUFPNT4_F13BP2, 0x0006
        .equiv  C1BUFPNT4_F13BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F13BP2_MASK, 0x0040
        .equiv  F13BP2, 0x0006

        .equiv  C1BUFPNT4_F13BP3, 0x0007
        .equiv  C1BUFPNT4_F13BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F13BP3_MASK, 0x0080
        .equiv  F13BP3, 0x0007

        .equiv  C1BUFPNT4_F14BP0, 0x0008
        .equiv  C1BUFPNT4_F14BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F14BP0_MASK, 0x0100
        .equiv  F14BP0, 0x0008

        .equiv  C1BUFPNT4_F14BP1, 0x0009
        .equiv  C1BUFPNT4_F14BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F14BP1_MASK, 0x0200
        .equiv  F14BP1, 0x0009

        .equiv  C1BUFPNT4_F14BP2, 0x000A
        .equiv  C1BUFPNT4_F14BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F14BP2_MASK, 0x0400
        .equiv  F14BP2, 0x000A

        .equiv  C1BUFPNT4_F14BP3, 0x000B
        .equiv  C1BUFPNT4_F14BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F14BP3_MASK, 0x0800
        .equiv  F14BP3, 0x000B

        .equiv  C1BUFPNT4_F15BP0, 0x000C
        .equiv  C1BUFPNT4_F15BP0_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F15BP0_MASK, 0x1000
        .equiv  F15BP0, 0x000C

        .equiv  C1BUFPNT4_F15BP1, 0x000D
        .equiv  C1BUFPNT4_F15BP1_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F15BP1_MASK, 0x2000
        .equiv  F15BP1, 0x000D

        .equiv  C1BUFPNT4_F15BP2, 0x000E
        .equiv  C1BUFPNT4_F15BP2_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F15BP2_MASK, 0x4000
        .equiv  F15BP2, 0x000E

        .equiv  C1BUFPNT4_F15BP3, 0x000F
        .equiv  C1BUFPNT4_F15BP3_WIDTH, 0x0001
        .equiv  C1BUFPNT4_F15BP3_MASK, 0x8000
        .equiv  F15BP3, 0x000F

;----- C1RXOVF1 Bits -----------------------------------------------------
        .equiv  C1RXOVF1_RXOVF0, 0x0000
        .equiv  C1RXOVF1_RXOVF0_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF0_MASK, 0x0001
        .equiv  RXOVF0, 0x0000

        .equiv  C1RXOVF1_RXOVF1, 0x0001
        .equiv  C1RXOVF1_RXOVF1_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF1_MASK, 0x0002
        .equiv  RXOVF1, 0x0001

        .equiv  C1RXOVF1_RXOVF2, 0x0002
        .equiv  C1RXOVF1_RXOVF2_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF2_MASK, 0x0004
        .equiv  RXOVF2, 0x0002

        .equiv  C1RXOVF1_RXOVF3, 0x0003
        .equiv  C1RXOVF1_RXOVF3_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF3_MASK, 0x0008
        .equiv  RXOVF3, 0x0003

        .equiv  C1RXOVF1_RXOVF4, 0x0004
        .equiv  C1RXOVF1_RXOVF4_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF4_MASK, 0x0010
        .equiv  RXOVF4, 0x0004

        .equiv  C1RXOVF1_RXOVF5, 0x0005
        .equiv  C1RXOVF1_RXOVF5_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF5_MASK, 0x0020
        .equiv  RXOVF5, 0x0005

        .equiv  C1RXOVF1_RXOVF6, 0x0006
        .equiv  C1RXOVF1_RXOVF6_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF6_MASK, 0x0040
        .equiv  RXOVF6, 0x0006

        .equiv  C1RXOVF1_RXOVF7, 0x0007
        .equiv  C1RXOVF1_RXOVF7_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF7_MASK, 0x0080
        .equiv  RXOVF7, 0x0007

        .equiv  C1RXOVF1_RXOVF8, 0x0008
        .equiv  C1RXOVF1_RXOVF8_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF8_MASK, 0x0100
        .equiv  RXOVF8, 0x0008

        .equiv  C1RXOVF1_RXOVF9, 0x0009
        .equiv  C1RXOVF1_RXOVF9_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF9_MASK, 0x0200
        .equiv  RXOVF9, 0x0009

        .equiv  C1RXOVF1_RXOVF10, 0x000A
        .equiv  C1RXOVF1_RXOVF10_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF10_MASK, 0x0400
        .equiv  RXOVF10, 0x000A

        .equiv  C1RXOVF1_RXOVF11, 0x000B
        .equiv  C1RXOVF1_RXOVF11_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF11_MASK, 0x0800
        .equiv  RXOVF11, 0x000B

        .equiv  C1RXOVF1_RXOVF12, 0x000C
        .equiv  C1RXOVF1_RXOVF12_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF12_MASK, 0x1000
        .equiv  RXOVF12, 0x000C

        .equiv  C1RXOVF1_RXOVF13, 0x000D
        .equiv  C1RXOVF1_RXOVF13_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF13_MASK, 0x2000
        .equiv  RXOVF13, 0x000D

        .equiv  C1RXOVF1_RXOVF14, 0x000E
        .equiv  C1RXOVF1_RXOVF14_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF14_MASK, 0x4000
        .equiv  RXOVF14, 0x000E

        .equiv  C1RXOVF1_RXOVF15, 0x000F
        .equiv  C1RXOVF1_RXOVF15_WIDTH, 0x0001
        .equiv  C1RXOVF1_RXOVF15_MASK, 0x8000
        .equiv  RXOVF15, 0x000F

;----- C1RXOVF2 Bits -----------------------------------------------------
        .equiv  C1RXOVF2_RXOVF16, 0x0000
        .equiv  C1RXOVF2_RXOVF16_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF16_MASK, 0x0001
        .equiv  RXOVF16, 0x0000

        .equiv  C1RXOVF2_RXOVF17, 0x0001
        .equiv  C1RXOVF2_RXOVF17_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF17_MASK, 0x0002
        .equiv  RXOVF17, 0x0001

        .equiv  C1RXOVF2_RXOVF18, 0x0002
        .equiv  C1RXOVF2_RXOVF18_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF18_MASK, 0x0004
        .equiv  RXOVF18, 0x0002

        .equiv  C1RXOVF2_RXOVF19, 0x0003
        .equiv  C1RXOVF2_RXOVF19_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF19_MASK, 0x0008
        .equiv  RXOVF19, 0x0003

        .equiv  C1RXOVF2_RXOVF20, 0x0004
        .equiv  C1RXOVF2_RXOVF20_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF20_MASK, 0x0010
        .equiv  RXOVF20, 0x0004

        .equiv  C1RXOVF2_RXOVF21, 0x0005
        .equiv  C1RXOVF2_RXOVF21_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF21_MASK, 0x0020
        .equiv  RXOVF21, 0x0005

        .equiv  C1RXOVF2_RXOVF22, 0x0006
        .equiv  C1RXOVF2_RXOVF22_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF22_MASK, 0x0040
        .equiv  RXOVF22, 0x0006

        .equiv  C1RXOVF2_RXOVF23, 0x0007
        .equiv  C1RXOVF2_RXOVF23_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF23_MASK, 0x0080
        .equiv  RXOVF23, 0x0007

        .equiv  C1RXOVF2_RXOVF24, 0x0008
        .equiv  C1RXOVF2_RXOVF24_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF24_MASK, 0x0100
        .equiv  RXOVF24, 0x0008

        .equiv  C1RXOVF2_RXOVF25, 0x0009
        .equiv  C1RXOVF2_RXOVF25_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF25_MASK, 0x0200
        .equiv  RXOVF25, 0x0009

        .equiv  C1RXOVF2_RXOVF26, 0x000A
        .equiv  C1RXOVF2_RXOVF26_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF26_MASK, 0x0400
        .equiv  RXOVF26, 0x000A

        .equiv  C1RXOVF2_RXOVF27, 0x000B
        .equiv  C1RXOVF2_RXOVF27_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF27_MASK, 0x0800
        .equiv  RXOVF27, 0x000B

        .equiv  C1RXOVF2_RXOVF28, 0x000C
        .equiv  C1RXOVF2_RXOVF28_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF28_MASK, 0x1000
        .equiv  RXOVF28, 0x000C

        .equiv  C1RXOVF2_RXOVF29, 0x000D
        .equiv  C1RXOVF2_RXOVF29_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF29_MASK, 0x2000
        .equiv  RXOVF29, 0x000D

        .equiv  C1RXOVF2_RXOVF30, 0x000E
        .equiv  C1RXOVF2_RXOVF30_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF30_MASK, 0x4000
        .equiv  RXOVF30, 0x000E

        .equiv  C1RXOVF2_RXOVF31, 0x000F
        .equiv  C1RXOVF2_RXOVF31_WIDTH, 0x0001
        .equiv  C1RXOVF2_RXOVF31_MASK, 0x8000
        .equiv  RXOVF31, 0x000F

;----- C1RXM0SID Bits -----------------------------------------------------
        .equiv  C1RXM0SID_EID16, 0x0000
        .equiv  C1RXM0SID_EID16_WIDTH, 0x0001
        .equiv  C1RXM0SID_EID16_MASK, 0x0001
        .equiv  EID16, 0x0000

        .equiv  C1RXM0SID_EID17, 0x0001
        .equiv  C1RXM0SID_EID17_WIDTH, 0x0001
        .equiv  C1RXM0SID_EID17_MASK, 0x0002
        .equiv  EID17, 0x0001

        .equiv  C1RXM0SID_MIDE, 0x0003
        .equiv  C1RXM0SID_MIDE_WIDTH, 0x0001
        .equiv  C1RXM0SID_MIDE_MASK, 0x0008
        .equiv  MIDE, 0x0003

        .equiv  C1RXM0SID_SID0, 0x0005
        .equiv  C1RXM0SID_SID0_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID0_MASK, 0x0020
        .equiv  SID0, 0x0005

        .equiv  C1RXM0SID_SID1, 0x0006
        .equiv  C1RXM0SID_SID1_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID1_MASK, 0x0040
        .equiv  SID1, 0x0006

        .equiv  C1RXM0SID_SID2, 0x0007
        .equiv  C1RXM0SID_SID2_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID2_MASK, 0x0080
        .equiv  SID2, 0x0007

        .equiv  C1RXM0SID_SID3, 0x0008
        .equiv  C1RXM0SID_SID3_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID3_MASK, 0x0100
        .equiv  SID3, 0x0008

        .equiv  C1RXM0SID_SID4, 0x0009
        .equiv  C1RXM0SID_SID4_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID4_MASK, 0x0200
        .equiv  SID4, 0x0009

        .equiv  C1RXM0SID_SID5, 0x000A
        .equiv  C1RXM0SID_SID5_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID5_MASK, 0x0400
        .equiv  SID5, 0x000A

        .equiv  C1RXM0SID_SID6, 0x000B
        .equiv  C1RXM0SID_SID6_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID6_MASK, 0x0800
        .equiv  SID6, 0x000B

        .equiv  C1RXM0SID_SID7, 0x000C
        .equiv  C1RXM0SID_SID7_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID7_MASK, 0x1000
        .equiv  SID7, 0x000C

        .equiv  C1RXM0SID_SID8, 0x000D
        .equiv  C1RXM0SID_SID8_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID8_MASK, 0x2000
        .equiv  SID8, 0x000D

        .equiv  C1RXM0SID_SID9, 0x000E
        .equiv  C1RXM0SID_SID9_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID9_MASK, 0x4000
        .equiv  SID9, 0x000E

        .equiv  C1RXM0SID_SID10, 0x000F
        .equiv  C1RXM0SID_SID10_WIDTH, 0x0001
        .equiv  C1RXM0SID_SID10_MASK, 0x8000
        .equiv  SID10, 0x000F

        .equiv  C1RXM0SID_EID, 0x0000
        .equiv  C1RXM0SID_EID_WIDTH, 0x0002
        .equiv  C1RXM0SID_EID_MASK, 0x0003

        .equiv  C1RXM0SID_EXIDE, 0x0003
        .equiv  C1RXM0SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXM0SID_EXIDE_MASK, 0x0008
        .equiv  EXIDE, 0x0003

        .equiv  C1RXM0SID_SID, 0x0005
        .equiv  C1RXM0SID_SID_WIDTH, 0x000B
        .equiv  C1RXM0SID_SID_MASK, 0xFFE0

;----- C1TR01CON Bits -----------------------------------------------------
        .equiv  C1TR01CON_TX0PRI, 0x0000
        .equiv  C1TR01CON_TX0PRI_WIDTH, 0x0002
        .equiv  C1TR01CON_TX0PRI_MASK, 0x0003

        .equiv  C1TR01CON_RTREN0, 0x0002
        .equiv  C1TR01CON_RTREN0_WIDTH, 0x0001
        .equiv  C1TR01CON_RTREN0_MASK, 0x0004
        .equiv  RTREN0, 0x0002

        .equiv  C1TR01CON_TXREQ0, 0x0003
        .equiv  C1TR01CON_TXREQ0_WIDTH, 0x0001
        .equiv  C1TR01CON_TXREQ0_MASK, 0x0008
        .equiv  TXREQ0, 0x0003

        .equiv  C1TR01CON_TXERR0, 0x0004
        .equiv  C1TR01CON_TXERR0_WIDTH, 0x0001
        .equiv  C1TR01CON_TXERR0_MASK, 0x0010
        .equiv  TXERR0, 0x0004

        .equiv  C1TR01CON_TXLARB0, 0x0005
        .equiv  C1TR01CON_TXLARB0_WIDTH, 0x0001
        .equiv  C1TR01CON_TXLARB0_MASK, 0x0020
        .equiv  TXLARB0, 0x0005

        .equiv  C1TR01CON_TXABT0, 0x0006
        .equiv  C1TR01CON_TXABT0_WIDTH, 0x0001
        .equiv  C1TR01CON_TXABT0_MASK, 0x0040
        .equiv  TXABT0, 0x0006

        .equiv  C1TR01CON_TXEN0, 0x0007
        .equiv  C1TR01CON_TXEN0_WIDTH, 0x0001
        .equiv  C1TR01CON_TXEN0_MASK, 0x0080
        .equiv  TXEN0, 0x0007

        .equiv  C1TR01CON_TX1PRI, 0x0008
        .equiv  C1TR01CON_TX1PRI_WIDTH, 0x0002
        .equiv  C1TR01CON_TX1PRI_MASK, 0x0300

        .equiv  C1TR01CON_RTREN1, 0x000A
        .equiv  C1TR01CON_RTREN1_WIDTH, 0x0001
        .equiv  C1TR01CON_RTREN1_MASK, 0x0400
        .equiv  RTREN1, 0x000A

        .equiv  C1TR01CON_TXREQ1, 0x000B
        .equiv  C1TR01CON_TXREQ1_WIDTH, 0x0001
        .equiv  C1TR01CON_TXREQ1_MASK, 0x0800
        .equiv  TXREQ1, 0x000B

        .equiv  C1TR01CON_TXERR1, 0x000C
        .equiv  C1TR01CON_TXERR1_WIDTH, 0x0001
        .equiv  C1TR01CON_TXERR1_MASK, 0x1000
        .equiv  TXERR1, 0x000C

        .equiv  C1TR01CON_TXLARB1, 0x000D
        .equiv  C1TR01CON_TXLARB1_WIDTH, 0x0001
        .equiv  C1TR01CON_TXLARB1_MASK, 0x2000
        .equiv  TXLARB1, 0x000D

        .equiv  C1TR01CON_TXABT1, 0x000E
        .equiv  C1TR01CON_TXABT1_WIDTH, 0x0001
        .equiv  C1TR01CON_TXABT1_MASK, 0x4000
        .equiv  TXABT1, 0x000E

        .equiv  C1TR01CON_TXEN1, 0x000F
        .equiv  C1TR01CON_TXEN1_WIDTH, 0x0001
        .equiv  C1TR01CON_TXEN1_MASK, 0x8000
        .equiv  TXEN1, 0x000F

        .equiv  C1TR01CON_TX0PRI0, 0x0000
        .equiv  C1TR01CON_TX0PRI0_WIDTH, 0x0001
        .equiv  C1TR01CON_TX0PRI0_MASK, 0x0001
        .equiv  TX0PRI0, 0x0000

        .equiv  C1TR01CON_TX0PRI1, 0x0001
        .equiv  C1TR01CON_TX0PRI1_WIDTH, 0x0001
        .equiv  C1TR01CON_TX0PRI1_MASK, 0x0002
        .equiv  TX0PRI1, 0x0001

        .equiv  C1TR01CON_TX1PRI0, 0x0008
        .equiv  C1TR01CON_TX1PRI0_WIDTH, 0x0001
        .equiv  C1TR01CON_TX1PRI0_MASK, 0x0100
        .equiv  TX1PRI0, 0x0008

        .equiv  C1TR01CON_TX1PRI1, 0x0009
        .equiv  C1TR01CON_TX1PRI1_WIDTH, 0x0001
        .equiv  C1TR01CON_TX1PRI1_MASK, 0x0200
        .equiv  TX1PRI1, 0x0009

;----- C1RXM0EID Bits -----------------------------------------------------
        .equiv  C1RXM0EID_EID0, 0x0000
        .equiv  C1RXM0EID_EID0_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID0_MASK, 0x0001
        .equiv  EID0, 0x0000

        .equiv  C1RXM0EID_EID1, 0x0001
        .equiv  C1RXM0EID_EID1_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID1_MASK, 0x0002
        .equiv  EID1, 0x0001

        .equiv  C1RXM0EID_EID2, 0x0002
        .equiv  C1RXM0EID_EID2_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID2_MASK, 0x0004
        .equiv  EID2, 0x0002

        .equiv  C1RXM0EID_EID3, 0x0003
        .equiv  C1RXM0EID_EID3_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID3_MASK, 0x0008
        .equiv  EID3, 0x0003

        .equiv  C1RXM0EID_EID4, 0x0004
        .equiv  C1RXM0EID_EID4_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID4_MASK, 0x0010
        .equiv  EID4, 0x0004

        .equiv  C1RXM0EID_EID5, 0x0005
        .equiv  C1RXM0EID_EID5_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID5_MASK, 0x0020
        .equiv  EID5, 0x0005

        .equiv  C1RXM0EID_EID6, 0x0006
        .equiv  C1RXM0EID_EID6_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID6_MASK, 0x0040
        .equiv  EID6, 0x0006

        .equiv  C1RXM0EID_EID7, 0x0007
        .equiv  C1RXM0EID_EID7_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID7_MASK, 0x0080
        .equiv  EID7, 0x0007

        .equiv  C1RXM0EID_EID8, 0x0008
        .equiv  C1RXM0EID_EID8_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID8_MASK, 0x0100
        .equiv  EID8, 0x0008

        .equiv  C1RXM0EID_EID9, 0x0009
        .equiv  C1RXM0EID_EID9_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID9_MASK, 0x0200
        .equiv  EID9, 0x0009

        .equiv  C1RXM0EID_EID10, 0x000A
        .equiv  C1RXM0EID_EID10_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID10_MASK, 0x0400
        .equiv  EID10, 0x000A

        .equiv  C1RXM0EID_EID11, 0x000B
        .equiv  C1RXM0EID_EID11_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID11_MASK, 0x0800
        .equiv  EID11, 0x000B

        .equiv  C1RXM0EID_EID12, 0x000C
        .equiv  C1RXM0EID_EID12_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID12_MASK, 0x1000
        .equiv  EID12, 0x000C

        .equiv  C1RXM0EID_EID13, 0x000D
        .equiv  C1RXM0EID_EID13_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID13_MASK, 0x2000
        .equiv  EID13, 0x000D

        .equiv  C1RXM0EID_EID14, 0x000E
        .equiv  C1RXM0EID_EID14_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID14_MASK, 0x4000
        .equiv  EID14, 0x000E

        .equiv  C1RXM0EID_EID15, 0x000F
        .equiv  C1RXM0EID_EID15_WIDTH, 0x0001
        .equiv  C1RXM0EID_EID15_MASK, 0x8000
        .equiv  EID15, 0x000F

        .equiv  C1RXM0EID_EID, 0x0000
        .equiv  C1RXM0EID_EID_WIDTH, 0x0010
        .equiv  C1RXM0EID_EID_MASK, 0xFFFF

;----- C1TR23CON Bits -----------------------------------------------------
        .equiv  C1TR23CON_TX2PRI, 0x0000
        .equiv  C1TR23CON_TX2PRI_WIDTH, 0x0002
        .equiv  C1TR23CON_TX2PRI_MASK, 0x0003

        .equiv  C1TR23CON_RTREN2, 0x0002
        .equiv  C1TR23CON_RTREN2_WIDTH, 0x0001
        .equiv  C1TR23CON_RTREN2_MASK, 0x0004
        .equiv  RTREN2, 0x0002

        .equiv  C1TR23CON_TXREQ2, 0x0003
        .equiv  C1TR23CON_TXREQ2_WIDTH, 0x0001
        .equiv  C1TR23CON_TXREQ2_MASK, 0x0008
        .equiv  TXREQ2, 0x0003

        .equiv  C1TR23CON_TXERR2, 0x0004
        .equiv  C1TR23CON_TXERR2_WIDTH, 0x0001
        .equiv  C1TR23CON_TXERR2_MASK, 0x0010
        .equiv  TXERR2, 0x0004

        .equiv  C1TR23CON_TXLARB2, 0x0005
        .equiv  C1TR23CON_TXLARB2_WIDTH, 0x0001
        .equiv  C1TR23CON_TXLARB2_MASK, 0x0020
        .equiv  TXLARB2, 0x0005

        .equiv  C1TR23CON_TXABT2, 0x0006
        .equiv  C1TR23CON_TXABT2_WIDTH, 0x0001
        .equiv  C1TR23CON_TXABT2_MASK, 0x0040
        .equiv  TXABT2, 0x0006

        .equiv  C1TR23CON_TXEN2, 0x0007
        .equiv  C1TR23CON_TXEN2_WIDTH, 0x0001
        .equiv  C1TR23CON_TXEN2_MASK, 0x0080
        .equiv  TXEN2, 0x0007

        .equiv  C1TR23CON_TX3PRI, 0x0008
        .equiv  C1TR23CON_TX3PRI_WIDTH, 0x0002
        .equiv  C1TR23CON_TX3PRI_MASK, 0x0300

        .equiv  C1TR23CON_RTREN3, 0x000A
        .equiv  C1TR23CON_RTREN3_WIDTH, 0x0001
        .equiv  C1TR23CON_RTREN3_MASK, 0x0400
        .equiv  RTREN3, 0x000A

        .equiv  C1TR23CON_TXREQ3, 0x000B
        .equiv  C1TR23CON_TXREQ3_WIDTH, 0x0001
        .equiv  C1TR23CON_TXREQ3_MASK, 0x0800
        .equiv  TXREQ3, 0x000B

        .equiv  C1TR23CON_TXERR3, 0x000C
        .equiv  C1TR23CON_TXERR3_WIDTH, 0x0001
        .equiv  C1TR23CON_TXERR3_MASK, 0x1000
        .equiv  TXERR3, 0x000C

        .equiv  C1TR23CON_TXLARB3, 0x000D
        .equiv  C1TR23CON_TXLARB3_WIDTH, 0x0001
        .equiv  C1TR23CON_TXLARB3_MASK, 0x2000
        .equiv  TXLARB3, 0x000D

        .equiv  C1TR23CON_TXABT3, 0x000E
        .equiv  C1TR23CON_TXABT3_WIDTH, 0x0001
        .equiv  C1TR23CON_TXABT3_MASK, 0x4000
        .equiv  TXABT3, 0x000E

        .equiv  C1TR23CON_TXEN3, 0x000F
        .equiv  C1TR23CON_TXEN3_WIDTH, 0x0001
        .equiv  C1TR23CON_TXEN3_MASK, 0x8000
        .equiv  TXEN3, 0x000F

        .equiv  C1TR23CON_TX2PRI0, 0x0000
        .equiv  C1TR23CON_TX2PRI0_WIDTH, 0x0001
        .equiv  C1TR23CON_TX2PRI0_MASK, 0x0001
        .equiv  TX2PRI0, 0x0000

        .equiv  C1TR23CON_TX2PRI1, 0x0001
        .equiv  C1TR23CON_TX2PRI1_WIDTH, 0x0001
        .equiv  C1TR23CON_TX2PRI1_MASK, 0x0002
        .equiv  TX2PRI1, 0x0001

        .equiv  C1TR23CON_TX3PRI0, 0x0008
        .equiv  C1TR23CON_TX3PRI0_WIDTH, 0x0001
        .equiv  C1TR23CON_TX3PRI0_MASK, 0x0100
        .equiv  TX3PRI0, 0x0008

        .equiv  C1TR23CON_TX3PRI1, 0x0009
        .equiv  C1TR23CON_TX3PRI1_WIDTH, 0x0001
        .equiv  C1TR23CON_TX3PRI1_MASK, 0x0200
        .equiv  TX3PRI1, 0x0009

;----- C1RXM1SID Bits -----------------------------------------------------
        .equiv  C1RXM1SID_EID16, 0x0000
        .equiv  C1RXM1SID_EID16_WIDTH, 0x0001
        .equiv  C1RXM1SID_EID16_MASK, 0x0001

        .equiv  C1RXM1SID_EID17, 0x0001
        .equiv  C1RXM1SID_EID17_WIDTH, 0x0001
        .equiv  C1RXM1SID_EID17_MASK, 0x0002

        .equiv  C1RXM1SID_MIDE, 0x0003
        .equiv  C1RXM1SID_MIDE_WIDTH, 0x0001
        .equiv  C1RXM1SID_MIDE_MASK, 0x0008

        .equiv  C1RXM1SID_SID0, 0x0005
        .equiv  C1RXM1SID_SID0_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID0_MASK, 0x0020

        .equiv  C1RXM1SID_SID1, 0x0006
        .equiv  C1RXM1SID_SID1_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID1_MASK, 0x0040

        .equiv  C1RXM1SID_SID2, 0x0007
        .equiv  C1RXM1SID_SID2_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID2_MASK, 0x0080

        .equiv  C1RXM1SID_SID3, 0x0008
        .equiv  C1RXM1SID_SID3_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID3_MASK, 0x0100

        .equiv  C1RXM1SID_SID4, 0x0009
        .equiv  C1RXM1SID_SID4_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID4_MASK, 0x0200

        .equiv  C1RXM1SID_SID5, 0x000A
        .equiv  C1RXM1SID_SID5_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID5_MASK, 0x0400

        .equiv  C1RXM1SID_SID6, 0x000B
        .equiv  C1RXM1SID_SID6_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID6_MASK, 0x0800

        .equiv  C1RXM1SID_SID7, 0x000C
        .equiv  C1RXM1SID_SID7_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID7_MASK, 0x1000

        .equiv  C1RXM1SID_SID8, 0x000D
        .equiv  C1RXM1SID_SID8_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID8_MASK, 0x2000

        .equiv  C1RXM1SID_SID9, 0x000E
        .equiv  C1RXM1SID_SID9_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID9_MASK, 0x4000

        .equiv  C1RXM1SID_SID10, 0x000F
        .equiv  C1RXM1SID_SID10_WIDTH, 0x0001
        .equiv  C1RXM1SID_SID10_MASK, 0x8000

        .equiv  C1RXM1SID_EID, 0x0000
        .equiv  C1RXM1SID_EID_WIDTH, 0x0002
        .equiv  C1RXM1SID_EID_MASK, 0x0003

        .equiv  C1RXM1SID_SID, 0x0005
        .equiv  C1RXM1SID_SID_WIDTH, 0x000B
        .equiv  C1RXM1SID_SID_MASK, 0xFFE0

;----- C1TR45CON Bits -----------------------------------------------------
        .equiv  C1TR45CON_TX4PRI, 0x0000
        .equiv  C1TR45CON_TX4PRI_WIDTH, 0x0002
        .equiv  C1TR45CON_TX4PRI_MASK, 0x0003

        .equiv  C1TR45CON_RTREN4, 0x0002
        .equiv  C1TR45CON_RTREN4_WIDTH, 0x0001
        .equiv  C1TR45CON_RTREN4_MASK, 0x0004
        .equiv  RTREN4, 0x0002

        .equiv  C1TR45CON_TXREQ4, 0x0003
        .equiv  C1TR45CON_TXREQ4_WIDTH, 0x0001
        .equiv  C1TR45CON_TXREQ4_MASK, 0x0008
        .equiv  TXREQ4, 0x0003

        .equiv  C1TR45CON_TXERR4, 0x0004
        .equiv  C1TR45CON_TXERR4_WIDTH, 0x0001
        .equiv  C1TR45CON_TXERR4_MASK, 0x0010
        .equiv  TXERR4, 0x0004

        .equiv  C1TR45CON_TXLARB4, 0x0005
        .equiv  C1TR45CON_TXLARB4_WIDTH, 0x0001
        .equiv  C1TR45CON_TXLARB4_MASK, 0x0020
        .equiv  TXLARB4, 0x0005

        .equiv  C1TR45CON_TXABT4, 0x0006
        .equiv  C1TR45CON_TXABT4_WIDTH, 0x0001
        .equiv  C1TR45CON_TXABT4_MASK, 0x0040
        .equiv  TXABT4, 0x0006

        .equiv  C1TR45CON_TXEN4, 0x0007
        .equiv  C1TR45CON_TXEN4_WIDTH, 0x0001
        .equiv  C1TR45CON_TXEN4_MASK, 0x0080
        .equiv  TXEN4, 0x0007

        .equiv  C1TR45CON_TX5PRI, 0x0008
        .equiv  C1TR45CON_TX5PRI_WIDTH, 0x0002
        .equiv  C1TR45CON_TX5PRI_MASK, 0x0300

        .equiv  C1TR45CON_RTREN5, 0x000A
        .equiv  C1TR45CON_RTREN5_WIDTH, 0x0001
        .equiv  C1TR45CON_RTREN5_MASK, 0x0400
        .equiv  RTREN5, 0x000A

        .equiv  C1TR45CON_TXREQ5, 0x000B
        .equiv  C1TR45CON_TXREQ5_WIDTH, 0x0001
        .equiv  C1TR45CON_TXREQ5_MASK, 0x0800
        .equiv  TXREQ5, 0x000B

        .equiv  C1TR45CON_TXERR5, 0x000C
        .equiv  C1TR45CON_TXERR5_WIDTH, 0x0001
        .equiv  C1TR45CON_TXERR5_MASK, 0x1000
        .equiv  TXERR5, 0x000C

        .equiv  C1TR45CON_TXLARB5, 0x000D
        .equiv  C1TR45CON_TXLARB5_WIDTH, 0x0001
        .equiv  C1TR45CON_TXLARB5_MASK, 0x2000
        .equiv  TXLARB5, 0x000D

        .equiv  C1TR45CON_TXABT5, 0x000E
        .equiv  C1TR45CON_TXABT5_WIDTH, 0x0001
        .equiv  C1TR45CON_TXABT5_MASK, 0x4000
        .equiv  TXABT5, 0x000E

        .equiv  C1TR45CON_TXEN5, 0x000F
        .equiv  C1TR45CON_TXEN5_WIDTH, 0x0001
        .equiv  C1TR45CON_TXEN5_MASK, 0x8000
        .equiv  TXEN5, 0x000F

        .equiv  C1TR45CON_TX4PRI0, 0x0000
        .equiv  C1TR45CON_TX4PRI0_WIDTH, 0x0001
        .equiv  C1TR45CON_TX4PRI0_MASK, 0x0001
        .equiv  TX4PRI0, 0x0000

        .equiv  C1TR45CON_TX4PRI1, 0x0001
        .equiv  C1TR45CON_TX4PRI1_WIDTH, 0x0001
        .equiv  C1TR45CON_TX4PRI1_MASK, 0x0002
        .equiv  TX4PRI1, 0x0001

        .equiv  C1TR45CON_TX5PRI0, 0x0008
        .equiv  C1TR45CON_TX5PRI0_WIDTH, 0x0001
        .equiv  C1TR45CON_TX5PRI0_MASK, 0x0100
        .equiv  TX5PRI0, 0x0008

        .equiv  C1TR45CON_TX5PRI1, 0x0009
        .equiv  C1TR45CON_TX5PRI1_WIDTH, 0x0001
        .equiv  C1TR45CON_TX5PRI1_MASK, 0x0200
        .equiv  TX5PRI1, 0x0009

;----- C1RXM1EID Bits -----------------------------------------------------
        .equiv  C1RXM1EID_EID0, 0x0000
        .equiv  C1RXM1EID_EID0_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID0_MASK, 0x0001

        .equiv  C1RXM1EID_EID1, 0x0001
        .equiv  C1RXM1EID_EID1_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID1_MASK, 0x0002

        .equiv  C1RXM1EID_EID2, 0x0002
        .equiv  C1RXM1EID_EID2_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID2_MASK, 0x0004

        .equiv  C1RXM1EID_EID3, 0x0003
        .equiv  C1RXM1EID_EID3_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID3_MASK, 0x0008

        .equiv  C1RXM1EID_EID4, 0x0004
        .equiv  C1RXM1EID_EID4_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID4_MASK, 0x0010

        .equiv  C1RXM1EID_EID5, 0x0005
        .equiv  C1RXM1EID_EID5_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID5_MASK, 0x0020

        .equiv  C1RXM1EID_EID6, 0x0006
        .equiv  C1RXM1EID_EID6_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID6_MASK, 0x0040

        .equiv  C1RXM1EID_EID7, 0x0007
        .equiv  C1RXM1EID_EID7_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID7_MASK, 0x0080

        .equiv  C1RXM1EID_EID8, 0x0008
        .equiv  C1RXM1EID_EID8_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID8_MASK, 0x0100

        .equiv  C1RXM1EID_EID9, 0x0009
        .equiv  C1RXM1EID_EID9_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID9_MASK, 0x0200

        .equiv  C1RXM1EID_EID10, 0x000A
        .equiv  C1RXM1EID_EID10_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID10_MASK, 0x0400

        .equiv  C1RXM1EID_EID11, 0x000B
        .equiv  C1RXM1EID_EID11_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID11_MASK, 0x0800

        .equiv  C1RXM1EID_EID12, 0x000C
        .equiv  C1RXM1EID_EID12_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID12_MASK, 0x1000

        .equiv  C1RXM1EID_EID13, 0x000D
        .equiv  C1RXM1EID_EID13_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID13_MASK, 0x2000

        .equiv  C1RXM1EID_EID14, 0x000E
        .equiv  C1RXM1EID_EID14_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID14_MASK, 0x4000

        .equiv  C1RXM1EID_EID15, 0x000F
        .equiv  C1RXM1EID_EID15_WIDTH, 0x0001
        .equiv  C1RXM1EID_EID15_MASK, 0x8000

        .equiv  C1RXM1EID_EID, 0x0000
        .equiv  C1RXM1EID_EID_WIDTH, 0x0010
        .equiv  C1RXM1EID_EID_MASK, 0xFFFF

;----- C1TR67CON Bits -----------------------------------------------------
        .equiv  C1TR67CON_TX6PRI, 0x0000
        .equiv  C1TR67CON_TX6PRI_WIDTH, 0x0002
        .equiv  C1TR67CON_TX6PRI_MASK, 0x0003

        .equiv  C1TR67CON_RTREN6, 0x0002
        .equiv  C1TR67CON_RTREN6_WIDTH, 0x0001
        .equiv  C1TR67CON_RTREN6_MASK, 0x0004
        .equiv  RTREN6, 0x0002

        .equiv  C1TR67CON_TXREQ6, 0x0003
        .equiv  C1TR67CON_TXREQ6_WIDTH, 0x0001
        .equiv  C1TR67CON_TXREQ6_MASK, 0x0008
        .equiv  TXREQ6, 0x0003

        .equiv  C1TR67CON_TXERR6, 0x0004
        .equiv  C1TR67CON_TXERR6_WIDTH, 0x0001
        .equiv  C1TR67CON_TXERR6_MASK, 0x0010
        .equiv  TXERR6, 0x0004

        .equiv  C1TR67CON_TXLARB6, 0x0005
        .equiv  C1TR67CON_TXLARB6_WIDTH, 0x0001
        .equiv  C1TR67CON_TXLARB6_MASK, 0x0020
        .equiv  TXLARB6, 0x0005

        .equiv  C1TR67CON_TXABT6, 0x0006
        .equiv  C1TR67CON_TXABT6_WIDTH, 0x0001
        .equiv  C1TR67CON_TXABT6_MASK, 0x0040
        .equiv  TXABT6, 0x0006

        .equiv  C1TR67CON_TXEN6, 0x0007
        .equiv  C1TR67CON_TXEN6_WIDTH, 0x0001
        .equiv  C1TR67CON_TXEN6_MASK, 0x0080
        .equiv  TXEN6, 0x0007

        .equiv  C1TR67CON_TX7PRI, 0x0008
        .equiv  C1TR67CON_TX7PRI_WIDTH, 0x0002
        .equiv  C1TR67CON_TX7PRI_MASK, 0x0300

        .equiv  C1TR67CON_RTREN7, 0x000A
        .equiv  C1TR67CON_RTREN7_WIDTH, 0x0001
        .equiv  C1TR67CON_RTREN7_MASK, 0x0400
        .equiv  RTREN7, 0x000A

        .equiv  C1TR67CON_TXREQ7, 0x000B
        .equiv  C1TR67CON_TXREQ7_WIDTH, 0x0001
        .equiv  C1TR67CON_TXREQ7_MASK, 0x0800
        .equiv  TXREQ7, 0x000B

        .equiv  C1TR67CON_TXERR7, 0x000C
        .equiv  C1TR67CON_TXERR7_WIDTH, 0x0001
        .equiv  C1TR67CON_TXERR7_MASK, 0x1000
        .equiv  TXERR7, 0x000C

        .equiv  C1TR67CON_TXLARB7, 0x000D
        .equiv  C1TR67CON_TXLARB7_WIDTH, 0x0001
        .equiv  C1TR67CON_TXLARB7_MASK, 0x2000
        .equiv  TXLARB7, 0x000D

        .equiv  C1TR67CON_TXABT7, 0x000E
        .equiv  C1TR67CON_TXABT7_WIDTH, 0x0001
        .equiv  C1TR67CON_TXABT7_MASK, 0x4000
        .equiv  TXABT7, 0x000E

        .equiv  C1TR67CON_TXEN7, 0x000F
        .equiv  C1TR67CON_TXEN7_WIDTH, 0x0001
        .equiv  C1TR67CON_TXEN7_MASK, 0x8000
        .equiv  TXEN7, 0x000F

        .equiv  C1TR67CON_TX6PRI0, 0x0000
        .equiv  C1TR67CON_TX6PRI0_WIDTH, 0x0001
        .equiv  C1TR67CON_TX6PRI0_MASK, 0x0001
        .equiv  TX6PRI0, 0x0000

        .equiv  C1TR67CON_TX6PRI1, 0x0001
        .equiv  C1TR67CON_TX6PRI1_WIDTH, 0x0001
        .equiv  C1TR67CON_TX6PRI1_MASK, 0x0002
        .equiv  TX6PRI1, 0x0001

        .equiv  C1TR67CON_TX7PRI0, 0x0008
        .equiv  C1TR67CON_TX7PRI0_WIDTH, 0x0001
        .equiv  C1TR67CON_TX7PRI0_MASK, 0x0100
        .equiv  TX7PRI0, 0x0008

        .equiv  C1TR67CON_TX7PRI1, 0x0009
        .equiv  C1TR67CON_TX7PRI1_WIDTH, 0x0001
        .equiv  C1TR67CON_TX7PRI1_MASK, 0x0200
        .equiv  TX7PRI1, 0x0009

;----- C1RXM2SID Bits -----------------------------------------------------
        .equiv  C1RXM2SID_EID16, 0x0000
        .equiv  C1RXM2SID_EID16_WIDTH, 0x0001
        .equiv  C1RXM2SID_EID16_MASK, 0x0001

        .equiv  C1RXM2SID_EID17, 0x0001
        .equiv  C1RXM2SID_EID17_WIDTH, 0x0001
        .equiv  C1RXM2SID_EID17_MASK, 0x0002

        .equiv  C1RXM2SID_MIDE, 0x0003
        .equiv  C1RXM2SID_MIDE_WIDTH, 0x0001
        .equiv  C1RXM2SID_MIDE_MASK, 0x0008

        .equiv  C1RXM2SID_SID0, 0x0005
        .equiv  C1RXM2SID_SID0_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID0_MASK, 0x0020

        .equiv  C1RXM2SID_SID1, 0x0006
        .equiv  C1RXM2SID_SID1_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID1_MASK, 0x0040

        .equiv  C1RXM2SID_SID2, 0x0007
        .equiv  C1RXM2SID_SID2_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID2_MASK, 0x0080

        .equiv  C1RXM2SID_SID3, 0x0008
        .equiv  C1RXM2SID_SID3_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID3_MASK, 0x0100

        .equiv  C1RXM2SID_SID4, 0x0009
        .equiv  C1RXM2SID_SID4_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID4_MASK, 0x0200

        .equiv  C1RXM2SID_SID5, 0x000A
        .equiv  C1RXM2SID_SID5_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID5_MASK, 0x0400

        .equiv  C1RXM2SID_SID6, 0x000B
        .equiv  C1RXM2SID_SID6_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID6_MASK, 0x0800

        .equiv  C1RXM2SID_SID7, 0x000C
        .equiv  C1RXM2SID_SID7_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID7_MASK, 0x1000

        .equiv  C1RXM2SID_SID8, 0x000D
        .equiv  C1RXM2SID_SID8_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID8_MASK, 0x2000

        .equiv  C1RXM2SID_SID9, 0x000E
        .equiv  C1RXM2SID_SID9_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID9_MASK, 0x4000

        .equiv  C1RXM2SID_SID10, 0x000F
        .equiv  C1RXM2SID_SID10_WIDTH, 0x0001
        .equiv  C1RXM2SID_SID10_MASK, 0x8000

        .equiv  C1RXM2SID_EID, 0x0000
        .equiv  C1RXM2SID_EID_WIDTH, 0x0002
        .equiv  C1RXM2SID_EID_MASK, 0x0003

        .equiv  C1RXM2SID_SID, 0x0005
        .equiv  C1RXM2SID_SID_WIDTH, 0x000B
        .equiv  C1RXM2SID_SID_MASK, 0xFFE0

;----- C1RXM2EID Bits -----------------------------------------------------
        .equiv  C1RXM2EID_EID0, 0x0000
        .equiv  C1RXM2EID_EID0_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID0_MASK, 0x0001

        .equiv  C1RXM2EID_EID1, 0x0001
        .equiv  C1RXM2EID_EID1_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID1_MASK, 0x0002

        .equiv  C1RXM2EID_EID2, 0x0002
        .equiv  C1RXM2EID_EID2_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID2_MASK, 0x0004

        .equiv  C1RXM2EID_EID3, 0x0003
        .equiv  C1RXM2EID_EID3_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID3_MASK, 0x0008

        .equiv  C1RXM2EID_EID4, 0x0004
        .equiv  C1RXM2EID_EID4_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID4_MASK, 0x0010

        .equiv  C1RXM2EID_EID5, 0x0005
        .equiv  C1RXM2EID_EID5_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID5_MASK, 0x0020

        .equiv  C1RXM2EID_EID6, 0x0006
        .equiv  C1RXM2EID_EID6_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID6_MASK, 0x0040

        .equiv  C1RXM2EID_EID7, 0x0007
        .equiv  C1RXM2EID_EID7_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID7_MASK, 0x0080

        .equiv  C1RXM2EID_EID8, 0x0008
        .equiv  C1RXM2EID_EID8_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID8_MASK, 0x0100

        .equiv  C1RXM2EID_EID9, 0x0009
        .equiv  C1RXM2EID_EID9_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID9_MASK, 0x0200

        .equiv  C1RXM2EID_EID10, 0x000A
        .equiv  C1RXM2EID_EID10_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID10_MASK, 0x0400

        .equiv  C1RXM2EID_EID11, 0x000B
        .equiv  C1RXM2EID_EID11_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID11_MASK, 0x0800

        .equiv  C1RXM2EID_EID12, 0x000C
        .equiv  C1RXM2EID_EID12_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID12_MASK, 0x1000

        .equiv  C1RXM2EID_EID13, 0x000D
        .equiv  C1RXM2EID_EID13_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID13_MASK, 0x2000

        .equiv  C1RXM2EID_EID14, 0x000E
        .equiv  C1RXM2EID_EID14_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID14_MASK, 0x4000

        .equiv  C1RXM2EID_EID15, 0x000F
        .equiv  C1RXM2EID_EID15_WIDTH, 0x0001
        .equiv  C1RXM2EID_EID15_MASK, 0x8000

        .equiv  C1RXM2EID_EID, 0x0000
        .equiv  C1RXM2EID_EID_WIDTH, 0x0010
        .equiv  C1RXM2EID_EID_MASK, 0xFFFF

;----- C1RXF0SID Bits -----------------------------------------------------
        .equiv  C1RXF0SID_EID16, 0x0000
        .equiv  C1RXF0SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF0SID_EID16_MASK, 0x0001

        .equiv  C1RXF0SID_EID17, 0x0001
        .equiv  C1RXF0SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF0SID_EID17_MASK, 0x0002

        .equiv  C1RXF0SID_EXIDE, 0x0003
        .equiv  C1RXF0SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF0SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF0SID_SID0, 0x0005
        .equiv  C1RXF0SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID0_MASK, 0x0020

        .equiv  C1RXF0SID_SID1, 0x0006
        .equiv  C1RXF0SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID1_MASK, 0x0040

        .equiv  C1RXF0SID_SID2, 0x0007
        .equiv  C1RXF0SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID2_MASK, 0x0080

        .equiv  C1RXF0SID_SID3, 0x0008
        .equiv  C1RXF0SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID3_MASK, 0x0100

        .equiv  C1RXF0SID_SID4, 0x0009
        .equiv  C1RXF0SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID4_MASK, 0x0200

        .equiv  C1RXF0SID_SID5, 0x000A
        .equiv  C1RXF0SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID5_MASK, 0x0400

        .equiv  C1RXF0SID_SID6, 0x000B
        .equiv  C1RXF0SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID6_MASK, 0x0800

        .equiv  C1RXF0SID_SID7, 0x000C
        .equiv  C1RXF0SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID7_MASK, 0x1000

        .equiv  C1RXF0SID_SID8, 0x000D
        .equiv  C1RXF0SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID8_MASK, 0x2000

        .equiv  C1RXF0SID_SID9, 0x000E
        .equiv  C1RXF0SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID9_MASK, 0x4000

        .equiv  C1RXF0SID_SID10, 0x000F
        .equiv  C1RXF0SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF0SID_SID10_MASK, 0x8000

        .equiv  C1RXF0SID_EID, 0x0000
        .equiv  C1RXF0SID_EID_WIDTH, 0x0002
        .equiv  C1RXF0SID_EID_MASK, 0x0003

        .equiv  C1RXF0SID_SID, 0x0005
        .equiv  C1RXF0SID_SID_WIDTH, 0x000B
        .equiv  C1RXF0SID_SID_MASK, 0xFFE0

;----- C1RXF0EID Bits -----------------------------------------------------
        .equiv  C1RXF0EID_EID0, 0x0000
        .equiv  C1RXF0EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID0_MASK, 0x0001

        .equiv  C1RXF0EID_EID1, 0x0001
        .equiv  C1RXF0EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID1_MASK, 0x0002

        .equiv  C1RXF0EID_EID2, 0x0002
        .equiv  C1RXF0EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID2_MASK, 0x0004

        .equiv  C1RXF0EID_EID3, 0x0003
        .equiv  C1RXF0EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID3_MASK, 0x0008

        .equiv  C1RXF0EID_EID4, 0x0004
        .equiv  C1RXF0EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID4_MASK, 0x0010

        .equiv  C1RXF0EID_EID5, 0x0005
        .equiv  C1RXF0EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID5_MASK, 0x0020

        .equiv  C1RXF0EID_EID6, 0x0006
        .equiv  C1RXF0EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID6_MASK, 0x0040

        .equiv  C1RXF0EID_EID7, 0x0007
        .equiv  C1RXF0EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID7_MASK, 0x0080

        .equiv  C1RXF0EID_EID8, 0x0008
        .equiv  C1RXF0EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID8_MASK, 0x0100

        .equiv  C1RXF0EID_EID9, 0x0009
        .equiv  C1RXF0EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID9_MASK, 0x0200

        .equiv  C1RXF0EID_EID10, 0x000A
        .equiv  C1RXF0EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID10_MASK, 0x0400

        .equiv  C1RXF0EID_EID11, 0x000B
        .equiv  C1RXF0EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID11_MASK, 0x0800

        .equiv  C1RXF0EID_EID12, 0x000C
        .equiv  C1RXF0EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID12_MASK, 0x1000

        .equiv  C1RXF0EID_EID13, 0x000D
        .equiv  C1RXF0EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID13_MASK, 0x2000

        .equiv  C1RXF0EID_EID14, 0x000E
        .equiv  C1RXF0EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID14_MASK, 0x4000

        .equiv  C1RXF0EID_EID15, 0x000F
        .equiv  C1RXF0EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF0EID_EID15_MASK, 0x8000

        .equiv  C1RXF0EID_EID, 0x0000
        .equiv  C1RXF0EID_EID_WIDTH, 0x0010
        .equiv  C1RXF0EID_EID_MASK, 0xFFFF

;----- C1RXF1SID Bits -----------------------------------------------------
        .equiv  C1RXF1SID_EID16, 0x0000
        .equiv  C1RXF1SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF1SID_EID16_MASK, 0x0001

        .equiv  C1RXF1SID_EID17, 0x0001
        .equiv  C1RXF1SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF1SID_EID17_MASK, 0x0002

        .equiv  C1RXF1SID_EXIDE, 0x0003
        .equiv  C1RXF1SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF1SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF1SID_SID0, 0x0005
        .equiv  C1RXF1SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID0_MASK, 0x0020

        .equiv  C1RXF1SID_SID1, 0x0006
        .equiv  C1RXF1SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID1_MASK, 0x0040

        .equiv  C1RXF1SID_SID2, 0x0007
        .equiv  C1RXF1SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID2_MASK, 0x0080

        .equiv  C1RXF1SID_SID3, 0x0008
        .equiv  C1RXF1SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID3_MASK, 0x0100

        .equiv  C1RXF1SID_SID4, 0x0009
        .equiv  C1RXF1SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID4_MASK, 0x0200

        .equiv  C1RXF1SID_SID5, 0x000A
        .equiv  C1RXF1SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID5_MASK, 0x0400

        .equiv  C1RXF1SID_SID6, 0x000B
        .equiv  C1RXF1SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID6_MASK, 0x0800

        .equiv  C1RXF1SID_SID7, 0x000C
        .equiv  C1RXF1SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID7_MASK, 0x1000

        .equiv  C1RXF1SID_SID8, 0x000D
        .equiv  C1RXF1SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID8_MASK, 0x2000

        .equiv  C1RXF1SID_SID9, 0x000E
        .equiv  C1RXF1SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID9_MASK, 0x4000

        .equiv  C1RXF1SID_SID10, 0x000F
        .equiv  C1RXF1SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF1SID_SID10_MASK, 0x8000

        .equiv  C1RXF1SID_EID, 0x0000
        .equiv  C1RXF1SID_EID_WIDTH, 0x0002
        .equiv  C1RXF1SID_EID_MASK, 0x0003

        .equiv  C1RXF1SID_SID, 0x0005
        .equiv  C1RXF1SID_SID_WIDTH, 0x000B
        .equiv  C1RXF1SID_SID_MASK, 0xFFE0

;----- C1RXF1EID Bits -----------------------------------------------------
        .equiv  C1RXF1EID_EID0, 0x0000
        .equiv  C1RXF1EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID0_MASK, 0x0001

        .equiv  C1RXF1EID_EID1, 0x0001
        .equiv  C1RXF1EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID1_MASK, 0x0002

        .equiv  C1RXF1EID_EID2, 0x0002
        .equiv  C1RXF1EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID2_MASK, 0x0004

        .equiv  C1RXF1EID_EID3, 0x0003
        .equiv  C1RXF1EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID3_MASK, 0x0008

        .equiv  C1RXF1EID_EID4, 0x0004
        .equiv  C1RXF1EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID4_MASK, 0x0010

        .equiv  C1RXF1EID_EID5, 0x0005
        .equiv  C1RXF1EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID5_MASK, 0x0020

        .equiv  C1RXF1EID_EID6, 0x0006
        .equiv  C1RXF1EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID6_MASK, 0x0040

        .equiv  C1RXF1EID_EID7, 0x0007
        .equiv  C1RXF1EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID7_MASK, 0x0080

        .equiv  C1RXF1EID_EID8, 0x0008
        .equiv  C1RXF1EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID8_MASK, 0x0100

        .equiv  C1RXF1EID_EID9, 0x0009
        .equiv  C1RXF1EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID9_MASK, 0x0200

        .equiv  C1RXF1EID_EID10, 0x000A
        .equiv  C1RXF1EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID10_MASK, 0x0400

        .equiv  C1RXF1EID_EID11, 0x000B
        .equiv  C1RXF1EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID11_MASK, 0x0800

        .equiv  C1RXF1EID_EID12, 0x000C
        .equiv  C1RXF1EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID12_MASK, 0x1000

        .equiv  C1RXF1EID_EID13, 0x000D
        .equiv  C1RXF1EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID13_MASK, 0x2000

        .equiv  C1RXF1EID_EID14, 0x000E
        .equiv  C1RXF1EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID14_MASK, 0x4000

        .equiv  C1RXF1EID_EID15, 0x000F
        .equiv  C1RXF1EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF1EID_EID15_MASK, 0x8000

        .equiv  C1RXF1EID_EID, 0x0000
        .equiv  C1RXF1EID_EID_WIDTH, 0x0010
        .equiv  C1RXF1EID_EID_MASK, 0xFFFF

;----- C1RXF2SID Bits -----------------------------------------------------
        .equiv  C1RXF2SID_EID16, 0x0000
        .equiv  C1RXF2SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF2SID_EID16_MASK, 0x0001

        .equiv  C1RXF2SID_EID17, 0x0001
        .equiv  C1RXF2SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF2SID_EID17_MASK, 0x0002

        .equiv  C1RXF2SID_EXIDE, 0x0003
        .equiv  C1RXF2SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF2SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF2SID_SID0, 0x0005
        .equiv  C1RXF2SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID0_MASK, 0x0020

        .equiv  C1RXF2SID_SID1, 0x0006
        .equiv  C1RXF2SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID1_MASK, 0x0040

        .equiv  C1RXF2SID_SID2, 0x0007
        .equiv  C1RXF2SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID2_MASK, 0x0080

        .equiv  C1RXF2SID_SID3, 0x0008
        .equiv  C1RXF2SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID3_MASK, 0x0100

        .equiv  C1RXF2SID_SID4, 0x0009
        .equiv  C1RXF2SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID4_MASK, 0x0200

        .equiv  C1RXF2SID_SID5, 0x000A
        .equiv  C1RXF2SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID5_MASK, 0x0400

        .equiv  C1RXF2SID_SID6, 0x000B
        .equiv  C1RXF2SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID6_MASK, 0x0800

        .equiv  C1RXF2SID_SID7, 0x000C
        .equiv  C1RXF2SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID7_MASK, 0x1000

        .equiv  C1RXF2SID_SID8, 0x000D
        .equiv  C1RXF2SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID8_MASK, 0x2000

        .equiv  C1RXF2SID_SID9, 0x000E
        .equiv  C1RXF2SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID9_MASK, 0x4000

        .equiv  C1RXF2SID_SID10, 0x000F
        .equiv  C1RXF2SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF2SID_SID10_MASK, 0x8000

        .equiv  C1RXF2SID_EID, 0x0000
        .equiv  C1RXF2SID_EID_WIDTH, 0x0002
        .equiv  C1RXF2SID_EID_MASK, 0x0003

        .equiv  C1RXF2SID_SID, 0x0005
        .equiv  C1RXF2SID_SID_WIDTH, 0x000B
        .equiv  C1RXF2SID_SID_MASK, 0xFFE0

;----- C1RXF2EID Bits -----------------------------------------------------
        .equiv  C1RXF2EID_EID0, 0x0000
        .equiv  C1RXF2EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID0_MASK, 0x0001

        .equiv  C1RXF2EID_EID1, 0x0001
        .equiv  C1RXF2EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID1_MASK, 0x0002

        .equiv  C1RXF2EID_EID2, 0x0002
        .equiv  C1RXF2EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID2_MASK, 0x0004

        .equiv  C1RXF2EID_EID3, 0x0003
        .equiv  C1RXF2EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID3_MASK, 0x0008

        .equiv  C1RXF2EID_EID4, 0x0004
        .equiv  C1RXF2EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID4_MASK, 0x0010

        .equiv  C1RXF2EID_EID5, 0x0005
        .equiv  C1RXF2EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID5_MASK, 0x0020

        .equiv  C1RXF2EID_EID6, 0x0006
        .equiv  C1RXF2EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID6_MASK, 0x0040

        .equiv  C1RXF2EID_EID7, 0x0007
        .equiv  C1RXF2EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID7_MASK, 0x0080

        .equiv  C1RXF2EID_EID8, 0x0008
        .equiv  C1RXF2EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID8_MASK, 0x0100

        .equiv  C1RXF2EID_EID9, 0x0009
        .equiv  C1RXF2EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID9_MASK, 0x0200

        .equiv  C1RXF2EID_EID10, 0x000A
        .equiv  C1RXF2EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID10_MASK, 0x0400

        .equiv  C1RXF2EID_EID11, 0x000B
        .equiv  C1RXF2EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID11_MASK, 0x0800

        .equiv  C1RXF2EID_EID12, 0x000C
        .equiv  C1RXF2EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID12_MASK, 0x1000

        .equiv  C1RXF2EID_EID13, 0x000D
        .equiv  C1RXF2EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID13_MASK, 0x2000

        .equiv  C1RXF2EID_EID14, 0x000E
        .equiv  C1RXF2EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID14_MASK, 0x4000

        .equiv  C1RXF2EID_EID15, 0x000F
        .equiv  C1RXF2EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF2EID_EID15_MASK, 0x8000

        .equiv  C1RXF2EID_EID, 0x0000
        .equiv  C1RXF2EID_EID_WIDTH, 0x0010
        .equiv  C1RXF2EID_EID_MASK, 0xFFFF

;----- C1RXF3SID Bits -----------------------------------------------------
        .equiv  C1RXF3SID_EID16, 0x0000
        .equiv  C1RXF3SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF3SID_EID16_MASK, 0x0001

        .equiv  C1RXF3SID_EID17, 0x0001
        .equiv  C1RXF3SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF3SID_EID17_MASK, 0x0002

        .equiv  C1RXF3SID_EXIDE, 0x0003
        .equiv  C1RXF3SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF3SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF3SID_SID0, 0x0005
        .equiv  C1RXF3SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID0_MASK, 0x0020

        .equiv  C1RXF3SID_SID1, 0x0006
        .equiv  C1RXF3SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID1_MASK, 0x0040

        .equiv  C1RXF3SID_SID2, 0x0007
        .equiv  C1RXF3SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID2_MASK, 0x0080

        .equiv  C1RXF3SID_SID3, 0x0008
        .equiv  C1RXF3SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID3_MASK, 0x0100

        .equiv  C1RXF3SID_SID4, 0x0009
        .equiv  C1RXF3SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID4_MASK, 0x0200

        .equiv  C1RXF3SID_SID5, 0x000A
        .equiv  C1RXF3SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID5_MASK, 0x0400

        .equiv  C1RXF3SID_SID6, 0x000B
        .equiv  C1RXF3SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID6_MASK, 0x0800

        .equiv  C1RXF3SID_SID7, 0x000C
        .equiv  C1RXF3SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID7_MASK, 0x1000

        .equiv  C1RXF3SID_SID8, 0x000D
        .equiv  C1RXF3SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID8_MASK, 0x2000

        .equiv  C1RXF3SID_SID9, 0x000E
        .equiv  C1RXF3SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID9_MASK, 0x4000

        .equiv  C1RXF3SID_SID10, 0x000F
        .equiv  C1RXF3SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF3SID_SID10_MASK, 0x8000

        .equiv  C1RXF3SID_EID, 0x0000
        .equiv  C1RXF3SID_EID_WIDTH, 0x0002
        .equiv  C1RXF3SID_EID_MASK, 0x0003

        .equiv  C1RXF3SID_SID, 0x0005
        .equiv  C1RXF3SID_SID_WIDTH, 0x000B
        .equiv  C1RXF3SID_SID_MASK, 0xFFE0

;----- C1RXF3EID Bits -----------------------------------------------------
        .equiv  C1RXF3EID_EID0, 0x0000
        .equiv  C1RXF3EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID0_MASK, 0x0001

        .equiv  C1RXF3EID_EID1, 0x0001
        .equiv  C1RXF3EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID1_MASK, 0x0002

        .equiv  C1RXF3EID_EID2, 0x0002
        .equiv  C1RXF3EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID2_MASK, 0x0004

        .equiv  C1RXF3EID_EID3, 0x0003
        .equiv  C1RXF3EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID3_MASK, 0x0008

        .equiv  C1RXF3EID_EID4, 0x0004
        .equiv  C1RXF3EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID4_MASK, 0x0010

        .equiv  C1RXF3EID_EID5, 0x0005
        .equiv  C1RXF3EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID5_MASK, 0x0020

        .equiv  C1RXF3EID_EID6, 0x0006
        .equiv  C1RXF3EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID6_MASK, 0x0040

        .equiv  C1RXF3EID_EID7, 0x0007
        .equiv  C1RXF3EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID7_MASK, 0x0080

        .equiv  C1RXF3EID_EID8, 0x0008
        .equiv  C1RXF3EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID8_MASK, 0x0100

        .equiv  C1RXF3EID_EID9, 0x0009
        .equiv  C1RXF3EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID9_MASK, 0x0200

        .equiv  C1RXF3EID_EID10, 0x000A
        .equiv  C1RXF3EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID10_MASK, 0x0400

        .equiv  C1RXF3EID_EID11, 0x000B
        .equiv  C1RXF3EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID11_MASK, 0x0800

        .equiv  C1RXF3EID_EID12, 0x000C
        .equiv  C1RXF3EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID12_MASK, 0x1000

        .equiv  C1RXF3EID_EID13, 0x000D
        .equiv  C1RXF3EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID13_MASK, 0x2000

        .equiv  C1RXF3EID_EID14, 0x000E
        .equiv  C1RXF3EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID14_MASK, 0x4000

        .equiv  C1RXF3EID_EID15, 0x000F
        .equiv  C1RXF3EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF3EID_EID15_MASK, 0x8000

        .equiv  C1RXF3EID_EID, 0x0000
        .equiv  C1RXF3EID_EID_WIDTH, 0x0010
        .equiv  C1RXF3EID_EID_MASK, 0xFFFF

;----- C1RXF4SID Bits -----------------------------------------------------
        .equiv  C1RXF4SID_EID16, 0x0000
        .equiv  C1RXF4SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF4SID_EID16_MASK, 0x0001

        .equiv  C1RXF4SID_EID17, 0x0001
        .equiv  C1RXF4SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF4SID_EID17_MASK, 0x0002

        .equiv  C1RXF4SID_EXIDE, 0x0003
        .equiv  C1RXF4SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF4SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF4SID_SID0, 0x0005
        .equiv  C1RXF4SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID0_MASK, 0x0020

        .equiv  C1RXF4SID_SID1, 0x0006
        .equiv  C1RXF4SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID1_MASK, 0x0040

        .equiv  C1RXF4SID_SID2, 0x0007
        .equiv  C1RXF4SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID2_MASK, 0x0080

        .equiv  C1RXF4SID_SID3, 0x0008
        .equiv  C1RXF4SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID3_MASK, 0x0100

        .equiv  C1RXF4SID_SID4, 0x0009
        .equiv  C1RXF4SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID4_MASK, 0x0200

        .equiv  C1RXF4SID_SID5, 0x000A
        .equiv  C1RXF4SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID5_MASK, 0x0400

        .equiv  C1RXF4SID_SID6, 0x000B
        .equiv  C1RXF4SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID6_MASK, 0x0800

        .equiv  C1RXF4SID_SID7, 0x000C
        .equiv  C1RXF4SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID7_MASK, 0x1000

        .equiv  C1RXF4SID_SID8, 0x000D
        .equiv  C1RXF4SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID8_MASK, 0x2000

        .equiv  C1RXF4SID_SID9, 0x000E
        .equiv  C1RXF4SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID9_MASK, 0x4000

        .equiv  C1RXF4SID_SID10, 0x000F
        .equiv  C1RXF4SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF4SID_SID10_MASK, 0x8000

        .equiv  C1RXF4SID_EID, 0x0000
        .equiv  C1RXF4SID_EID_WIDTH, 0x0002
        .equiv  C1RXF4SID_EID_MASK, 0x0003

        .equiv  C1RXF4SID_SID, 0x0005
        .equiv  C1RXF4SID_SID_WIDTH, 0x000B
        .equiv  C1RXF4SID_SID_MASK, 0xFFE0

;----- C1RXF4EID Bits -----------------------------------------------------
        .equiv  C1RXF4EID_EID0, 0x0000
        .equiv  C1RXF4EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID0_MASK, 0x0001

        .equiv  C1RXF4EID_EID1, 0x0001
        .equiv  C1RXF4EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID1_MASK, 0x0002

        .equiv  C1RXF4EID_EID2, 0x0002
        .equiv  C1RXF4EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID2_MASK, 0x0004

        .equiv  C1RXF4EID_EID3, 0x0003
        .equiv  C1RXF4EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID3_MASK, 0x0008

        .equiv  C1RXF4EID_EID4, 0x0004
        .equiv  C1RXF4EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID4_MASK, 0x0010

        .equiv  C1RXF4EID_EID5, 0x0005
        .equiv  C1RXF4EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID5_MASK, 0x0020

        .equiv  C1RXF4EID_EID6, 0x0006
        .equiv  C1RXF4EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID6_MASK, 0x0040

        .equiv  C1RXF4EID_EID7, 0x0007
        .equiv  C1RXF4EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID7_MASK, 0x0080

        .equiv  C1RXF4EID_EID8, 0x0008
        .equiv  C1RXF4EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID8_MASK, 0x0100

        .equiv  C1RXF4EID_EID9, 0x0009
        .equiv  C1RXF4EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID9_MASK, 0x0200

        .equiv  C1RXF4EID_EID10, 0x000A
        .equiv  C1RXF4EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID10_MASK, 0x0400

        .equiv  C1RXF4EID_EID11, 0x000B
        .equiv  C1RXF4EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID11_MASK, 0x0800

        .equiv  C1RXF4EID_EID12, 0x000C
        .equiv  C1RXF4EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID12_MASK, 0x1000

        .equiv  C1RXF4EID_EID13, 0x000D
        .equiv  C1RXF4EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID13_MASK, 0x2000

        .equiv  C1RXF4EID_EID14, 0x000E
        .equiv  C1RXF4EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID14_MASK, 0x4000

        .equiv  C1RXF4EID_EID15, 0x000F
        .equiv  C1RXF4EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF4EID_EID15_MASK, 0x8000

        .equiv  C1RXF4EID_EID, 0x0000
        .equiv  C1RXF4EID_EID_WIDTH, 0x0010
        .equiv  C1RXF4EID_EID_MASK, 0xFFFF

;----- C1RXF5SID Bits -----------------------------------------------------
        .equiv  C1RXF5SID_EID16, 0x0000
        .equiv  C1RXF5SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF5SID_EID16_MASK, 0x0001

        .equiv  C1RXF5SID_EID17, 0x0001
        .equiv  C1RXF5SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF5SID_EID17_MASK, 0x0002

        .equiv  C1RXF5SID_EXIDE, 0x0003
        .equiv  C1RXF5SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF5SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF5SID_SID0, 0x0005
        .equiv  C1RXF5SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID0_MASK, 0x0020

        .equiv  C1RXF5SID_SID1, 0x0006
        .equiv  C1RXF5SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID1_MASK, 0x0040

        .equiv  C1RXF5SID_SID2, 0x0007
        .equiv  C1RXF5SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID2_MASK, 0x0080

        .equiv  C1RXF5SID_SID3, 0x0008
        .equiv  C1RXF5SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID3_MASK, 0x0100

        .equiv  C1RXF5SID_SID4, 0x0009
        .equiv  C1RXF5SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID4_MASK, 0x0200

        .equiv  C1RXF5SID_SID5, 0x000A
        .equiv  C1RXF5SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID5_MASK, 0x0400

        .equiv  C1RXF5SID_SID6, 0x000B
        .equiv  C1RXF5SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID6_MASK, 0x0800

        .equiv  C1RXF5SID_SID7, 0x000C
        .equiv  C1RXF5SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID7_MASK, 0x1000

        .equiv  C1RXF5SID_SID8, 0x000D
        .equiv  C1RXF5SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID8_MASK, 0x2000

        .equiv  C1RXF5SID_SID9, 0x000E
        .equiv  C1RXF5SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID9_MASK, 0x4000

        .equiv  C1RXF5SID_SID10, 0x000F
        .equiv  C1RXF5SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF5SID_SID10_MASK, 0x8000

        .equiv  C1RXF5SID_EID, 0x0000
        .equiv  C1RXF5SID_EID_WIDTH, 0x0002
        .equiv  C1RXF5SID_EID_MASK, 0x0003

        .equiv  C1RXF5SID_SID, 0x0005
        .equiv  C1RXF5SID_SID_WIDTH, 0x000B
        .equiv  C1RXF5SID_SID_MASK, 0xFFE0

;----- C1RXF5EID Bits -----------------------------------------------------
        .equiv  C1RXF5EID_EID0, 0x0000
        .equiv  C1RXF5EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID0_MASK, 0x0001

        .equiv  C1RXF5EID_EID1, 0x0001
        .equiv  C1RXF5EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID1_MASK, 0x0002

        .equiv  C1RXF5EID_EID2, 0x0002
        .equiv  C1RXF5EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID2_MASK, 0x0004

        .equiv  C1RXF5EID_EID3, 0x0003
        .equiv  C1RXF5EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID3_MASK, 0x0008

        .equiv  C1RXF5EID_EID4, 0x0004
        .equiv  C1RXF5EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID4_MASK, 0x0010

        .equiv  C1RXF5EID_EID5, 0x0005
        .equiv  C1RXF5EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID5_MASK, 0x0020

        .equiv  C1RXF5EID_EID6, 0x0006
        .equiv  C1RXF5EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID6_MASK, 0x0040

        .equiv  C1RXF5EID_EID7, 0x0007
        .equiv  C1RXF5EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID7_MASK, 0x0080

        .equiv  C1RXF5EID_EID8, 0x0008
        .equiv  C1RXF5EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID8_MASK, 0x0100

        .equiv  C1RXF5EID_EID9, 0x0009
        .equiv  C1RXF5EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID9_MASK, 0x0200

        .equiv  C1RXF5EID_EID10, 0x000A
        .equiv  C1RXF5EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID10_MASK, 0x0400

        .equiv  C1RXF5EID_EID11, 0x000B
        .equiv  C1RXF5EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID11_MASK, 0x0800

        .equiv  C1RXF5EID_EID12, 0x000C
        .equiv  C1RXF5EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID12_MASK, 0x1000

        .equiv  C1RXF5EID_EID13, 0x000D
        .equiv  C1RXF5EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID13_MASK, 0x2000

        .equiv  C1RXF5EID_EID14, 0x000E
        .equiv  C1RXF5EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID14_MASK, 0x4000

        .equiv  C1RXF5EID_EID15, 0x000F
        .equiv  C1RXF5EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF5EID_EID15_MASK, 0x8000

        .equiv  C1RXF5EID_EID, 0x0000
        .equiv  C1RXF5EID_EID_WIDTH, 0x0010
        .equiv  C1RXF5EID_EID_MASK, 0xFFFF

;----- C1RXF6SID Bits -----------------------------------------------------
        .equiv  C1RXF6SID_EID16, 0x0000
        .equiv  C1RXF6SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF6SID_EID16_MASK, 0x0001

        .equiv  C1RXF6SID_EID17, 0x0001
        .equiv  C1RXF6SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF6SID_EID17_MASK, 0x0002

        .equiv  C1RXF6SID_EXIDE, 0x0003
        .equiv  C1RXF6SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF6SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF6SID_SID0, 0x0005
        .equiv  C1RXF6SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID0_MASK, 0x0020

        .equiv  C1RXF6SID_SID1, 0x0006
        .equiv  C1RXF6SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID1_MASK, 0x0040

        .equiv  C1RXF6SID_SID2, 0x0007
        .equiv  C1RXF6SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID2_MASK, 0x0080

        .equiv  C1RXF6SID_SID3, 0x0008
        .equiv  C1RXF6SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID3_MASK, 0x0100

        .equiv  C1RXF6SID_SID4, 0x0009
        .equiv  C1RXF6SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID4_MASK, 0x0200

        .equiv  C1RXF6SID_SID5, 0x000A
        .equiv  C1RXF6SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID5_MASK, 0x0400

        .equiv  C1RXF6SID_SID6, 0x000B
        .equiv  C1RXF6SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID6_MASK, 0x0800

        .equiv  C1RXF6SID_SID7, 0x000C
        .equiv  C1RXF6SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID7_MASK, 0x1000

        .equiv  C1RXF6SID_SID8, 0x000D
        .equiv  C1RXF6SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID8_MASK, 0x2000

        .equiv  C1RXF6SID_SID9, 0x000E
        .equiv  C1RXF6SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID9_MASK, 0x4000

        .equiv  C1RXF6SID_SID10, 0x000F
        .equiv  C1RXF6SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF6SID_SID10_MASK, 0x8000

        .equiv  C1RXF6SID_EID, 0x0000
        .equiv  C1RXF6SID_EID_WIDTH, 0x0002
        .equiv  C1RXF6SID_EID_MASK, 0x0003

        .equiv  C1RXF6SID_SID, 0x0005
        .equiv  C1RXF6SID_SID_WIDTH, 0x000B
        .equiv  C1RXF6SID_SID_MASK, 0xFFE0

;----- C1RXF6EID Bits -----------------------------------------------------
        .equiv  C1RXF6EID_EID0, 0x0000
        .equiv  C1RXF6EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID0_MASK, 0x0001

        .equiv  C1RXF6EID_EID1, 0x0001
        .equiv  C1RXF6EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID1_MASK, 0x0002

        .equiv  C1RXF6EID_EID2, 0x0002
        .equiv  C1RXF6EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID2_MASK, 0x0004

        .equiv  C1RXF6EID_EID3, 0x0003
        .equiv  C1RXF6EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID3_MASK, 0x0008

        .equiv  C1RXF6EID_EID4, 0x0004
        .equiv  C1RXF6EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID4_MASK, 0x0010

        .equiv  C1RXF6EID_EID5, 0x0005
        .equiv  C1RXF6EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID5_MASK, 0x0020

        .equiv  C1RXF6EID_EID6, 0x0006
        .equiv  C1RXF6EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID6_MASK, 0x0040

        .equiv  C1RXF6EID_EID7, 0x0007
        .equiv  C1RXF6EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID7_MASK, 0x0080

        .equiv  C1RXF6EID_EID8, 0x0008
        .equiv  C1RXF6EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID8_MASK, 0x0100

        .equiv  C1RXF6EID_EID9, 0x0009
        .equiv  C1RXF6EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID9_MASK, 0x0200

        .equiv  C1RXF6EID_EID10, 0x000A
        .equiv  C1RXF6EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID10_MASK, 0x0400

        .equiv  C1RXF6EID_EID11, 0x000B
        .equiv  C1RXF6EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID11_MASK, 0x0800

        .equiv  C1RXF6EID_EID12, 0x000C
        .equiv  C1RXF6EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID12_MASK, 0x1000

        .equiv  C1RXF6EID_EID13, 0x000D
        .equiv  C1RXF6EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID13_MASK, 0x2000

        .equiv  C1RXF6EID_EID14, 0x000E
        .equiv  C1RXF6EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID14_MASK, 0x4000

        .equiv  C1RXF6EID_EID15, 0x000F
        .equiv  C1RXF6EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF6EID_EID15_MASK, 0x8000

        .equiv  C1RXF6EID_EID, 0x0000
        .equiv  C1RXF6EID_EID_WIDTH, 0x0010
        .equiv  C1RXF6EID_EID_MASK, 0xFFFF

;----- C1RXF7SID Bits -----------------------------------------------------
        .equiv  C1RXF7SID_EID16, 0x0000
        .equiv  C1RXF7SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF7SID_EID16_MASK, 0x0001

        .equiv  C1RXF7SID_EID17, 0x0001
        .equiv  C1RXF7SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF7SID_EID17_MASK, 0x0002

        .equiv  C1RXF7SID_EXIDE, 0x0003
        .equiv  C1RXF7SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF7SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF7SID_SID0, 0x0005
        .equiv  C1RXF7SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID0_MASK, 0x0020

        .equiv  C1RXF7SID_SID1, 0x0006
        .equiv  C1RXF7SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID1_MASK, 0x0040

        .equiv  C1RXF7SID_SID2, 0x0007
        .equiv  C1RXF7SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID2_MASK, 0x0080

        .equiv  C1RXF7SID_SID3, 0x0008
        .equiv  C1RXF7SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID3_MASK, 0x0100

        .equiv  C1RXF7SID_SID4, 0x0009
        .equiv  C1RXF7SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID4_MASK, 0x0200

        .equiv  C1RXF7SID_SID5, 0x000A
        .equiv  C1RXF7SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID5_MASK, 0x0400

        .equiv  C1RXF7SID_SID6, 0x000B
        .equiv  C1RXF7SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID6_MASK, 0x0800

        .equiv  C1RXF7SID_SID7, 0x000C
        .equiv  C1RXF7SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID7_MASK, 0x1000

        .equiv  C1RXF7SID_SID8, 0x000D
        .equiv  C1RXF7SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID8_MASK, 0x2000

        .equiv  C1RXF7SID_SID9, 0x000E
        .equiv  C1RXF7SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID9_MASK, 0x4000

        .equiv  C1RXF7SID_SID10, 0x000F
        .equiv  C1RXF7SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF7SID_SID10_MASK, 0x8000

        .equiv  C1RXF7SID_EID, 0x0000
        .equiv  C1RXF7SID_EID_WIDTH, 0x0002
        .equiv  C1RXF7SID_EID_MASK, 0x0003

        .equiv  C1RXF7SID_SID, 0x0005
        .equiv  C1RXF7SID_SID_WIDTH, 0x000B
        .equiv  C1RXF7SID_SID_MASK, 0xFFE0

;----- C1RXF7EID Bits -----------------------------------------------------
        .equiv  C1RXF7EID_EID0, 0x0000
        .equiv  C1RXF7EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID0_MASK, 0x0001

        .equiv  C1RXF7EID_EID1, 0x0001
        .equiv  C1RXF7EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID1_MASK, 0x0002

        .equiv  C1RXF7EID_EID2, 0x0002
        .equiv  C1RXF7EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID2_MASK, 0x0004

        .equiv  C1RXF7EID_EID3, 0x0003
        .equiv  C1RXF7EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID3_MASK, 0x0008

        .equiv  C1RXF7EID_EID4, 0x0004
        .equiv  C1RXF7EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID4_MASK, 0x0010

        .equiv  C1RXF7EID_EID5, 0x0005
        .equiv  C1RXF7EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID5_MASK, 0x0020

        .equiv  C1RXF7EID_EID6, 0x0006
        .equiv  C1RXF7EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID6_MASK, 0x0040

        .equiv  C1RXF7EID_EID7, 0x0007
        .equiv  C1RXF7EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID7_MASK, 0x0080

        .equiv  C1RXF7EID_EID8, 0x0008
        .equiv  C1RXF7EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID8_MASK, 0x0100

        .equiv  C1RXF7EID_EID9, 0x0009
        .equiv  C1RXF7EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID9_MASK, 0x0200

        .equiv  C1RXF7EID_EID10, 0x000A
        .equiv  C1RXF7EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID10_MASK, 0x0400

        .equiv  C1RXF7EID_EID11, 0x000B
        .equiv  C1RXF7EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID11_MASK, 0x0800

        .equiv  C1RXF7EID_EID12, 0x000C
        .equiv  C1RXF7EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID12_MASK, 0x1000

        .equiv  C1RXF7EID_EID13, 0x000D
        .equiv  C1RXF7EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID13_MASK, 0x2000

        .equiv  C1RXF7EID_EID14, 0x000E
        .equiv  C1RXF7EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID14_MASK, 0x4000

        .equiv  C1RXF7EID_EID15, 0x000F
        .equiv  C1RXF7EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF7EID_EID15_MASK, 0x8000

        .equiv  C1RXF7EID_EID, 0x0000
        .equiv  C1RXF7EID_EID_WIDTH, 0x0010
        .equiv  C1RXF7EID_EID_MASK, 0xFFFF

;----- C1RXF8SID Bits -----------------------------------------------------
        .equiv  C1RXF8SID_EID16, 0x0000
        .equiv  C1RXF8SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF8SID_EID16_MASK, 0x0001

        .equiv  C1RXF8SID_EID17, 0x0001
        .equiv  C1RXF8SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF8SID_EID17_MASK, 0x0002

        .equiv  C1RXF8SID_EXIDE, 0x0003
        .equiv  C1RXF8SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF8SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF8SID_SID0, 0x0005
        .equiv  C1RXF8SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID0_MASK, 0x0020

        .equiv  C1RXF8SID_SID1, 0x0006
        .equiv  C1RXF8SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID1_MASK, 0x0040

        .equiv  C1RXF8SID_SID2, 0x0007
        .equiv  C1RXF8SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID2_MASK, 0x0080

        .equiv  C1RXF8SID_SID3, 0x0008
        .equiv  C1RXF8SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID3_MASK, 0x0100

        .equiv  C1RXF8SID_SID4, 0x0009
        .equiv  C1RXF8SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID4_MASK, 0x0200

        .equiv  C1RXF8SID_SID5, 0x000A
        .equiv  C1RXF8SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID5_MASK, 0x0400

        .equiv  C1RXF8SID_SID6, 0x000B
        .equiv  C1RXF8SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID6_MASK, 0x0800

        .equiv  C1RXF8SID_SID7, 0x000C
        .equiv  C1RXF8SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID7_MASK, 0x1000

        .equiv  C1RXF8SID_SID8, 0x000D
        .equiv  C1RXF8SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID8_MASK, 0x2000

        .equiv  C1RXF8SID_SID9, 0x000E
        .equiv  C1RXF8SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID9_MASK, 0x4000

        .equiv  C1RXF8SID_SID10, 0x000F
        .equiv  C1RXF8SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF8SID_SID10_MASK, 0x8000

        .equiv  C1RXF8SID_EID, 0x0000
        .equiv  C1RXF8SID_EID_WIDTH, 0x0002
        .equiv  C1RXF8SID_EID_MASK, 0x0003

        .equiv  C1RXF8SID_SID, 0x0005
        .equiv  C1RXF8SID_SID_WIDTH, 0x000B
        .equiv  C1RXF8SID_SID_MASK, 0xFFE0

;----- C1RXF8EID Bits -----------------------------------------------------
        .equiv  C1RXF8EID_EID0, 0x0000
        .equiv  C1RXF8EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID0_MASK, 0x0001

        .equiv  C1RXF8EID_EID1, 0x0001
        .equiv  C1RXF8EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID1_MASK, 0x0002

        .equiv  C1RXF8EID_EID2, 0x0002
        .equiv  C1RXF8EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID2_MASK, 0x0004

        .equiv  C1RXF8EID_EID3, 0x0003
        .equiv  C1RXF8EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID3_MASK, 0x0008

        .equiv  C1RXF8EID_EID4, 0x0004
        .equiv  C1RXF8EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID4_MASK, 0x0010

        .equiv  C1RXF8EID_EID5, 0x0005
        .equiv  C1RXF8EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID5_MASK, 0x0020

        .equiv  C1RXF8EID_EID6, 0x0006
        .equiv  C1RXF8EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID6_MASK, 0x0040

        .equiv  C1RXF8EID_EID7, 0x0007
        .equiv  C1RXF8EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID7_MASK, 0x0080

        .equiv  C1RXF8EID_EID8, 0x0008
        .equiv  C1RXF8EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID8_MASK, 0x0100

        .equiv  C1RXF8EID_EID9, 0x0009
        .equiv  C1RXF8EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID9_MASK, 0x0200

        .equiv  C1RXF8EID_EID10, 0x000A
        .equiv  C1RXF8EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID10_MASK, 0x0400

        .equiv  C1RXF8EID_EID11, 0x000B
        .equiv  C1RXF8EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID11_MASK, 0x0800

        .equiv  C1RXF8EID_EID12, 0x000C
        .equiv  C1RXF8EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID12_MASK, 0x1000

        .equiv  C1RXF8EID_EID13, 0x000D
        .equiv  C1RXF8EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID13_MASK, 0x2000

        .equiv  C1RXF8EID_EID14, 0x000E
        .equiv  C1RXF8EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID14_MASK, 0x4000

        .equiv  C1RXF8EID_EID15, 0x000F
        .equiv  C1RXF8EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF8EID_EID15_MASK, 0x8000

        .equiv  C1RXF8EID_EID, 0x0000
        .equiv  C1RXF8EID_EID_WIDTH, 0x0010
        .equiv  C1RXF8EID_EID_MASK, 0xFFFF

;----- C1RXF9SID Bits -----------------------------------------------------
        .equiv  C1RXF9SID_EID16, 0x0000
        .equiv  C1RXF9SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF9SID_EID16_MASK, 0x0001

        .equiv  C1RXF9SID_EID17, 0x0001
        .equiv  C1RXF9SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF9SID_EID17_MASK, 0x0002

        .equiv  C1RXF9SID_EXIDE, 0x0003
        .equiv  C1RXF9SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF9SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF9SID_SID0, 0x0005
        .equiv  C1RXF9SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID0_MASK, 0x0020

        .equiv  C1RXF9SID_SID1, 0x0006
        .equiv  C1RXF9SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID1_MASK, 0x0040

        .equiv  C1RXF9SID_SID2, 0x0007
        .equiv  C1RXF9SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID2_MASK, 0x0080

        .equiv  C1RXF9SID_SID3, 0x0008
        .equiv  C1RXF9SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID3_MASK, 0x0100

        .equiv  C1RXF9SID_SID4, 0x0009
        .equiv  C1RXF9SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID4_MASK, 0x0200

        .equiv  C1RXF9SID_SID5, 0x000A
        .equiv  C1RXF9SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID5_MASK, 0x0400

        .equiv  C1RXF9SID_SID6, 0x000B
        .equiv  C1RXF9SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID6_MASK, 0x0800

        .equiv  C1RXF9SID_SID7, 0x000C
        .equiv  C1RXF9SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID7_MASK, 0x1000

        .equiv  C1RXF9SID_SID8, 0x000D
        .equiv  C1RXF9SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID8_MASK, 0x2000

        .equiv  C1RXF9SID_SID9, 0x000E
        .equiv  C1RXF9SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID9_MASK, 0x4000

        .equiv  C1RXF9SID_SID10, 0x000F
        .equiv  C1RXF9SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF9SID_SID10_MASK, 0x8000

        .equiv  C1RXF9SID_EID, 0x0000
        .equiv  C1RXF9SID_EID_WIDTH, 0x0002
        .equiv  C1RXF9SID_EID_MASK, 0x0003

        .equiv  C1RXF9SID_SID, 0x0005
        .equiv  C1RXF9SID_SID_WIDTH, 0x000B
        .equiv  C1RXF9SID_SID_MASK, 0xFFE0

;----- C1RXF9EID Bits -----------------------------------------------------
        .equiv  C1RXF9EID_EID0, 0x0000
        .equiv  C1RXF9EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID0_MASK, 0x0001

        .equiv  C1RXF9EID_EID1, 0x0001
        .equiv  C1RXF9EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID1_MASK, 0x0002

        .equiv  C1RXF9EID_EID2, 0x0002
        .equiv  C1RXF9EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID2_MASK, 0x0004

        .equiv  C1RXF9EID_EID3, 0x0003
        .equiv  C1RXF9EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID3_MASK, 0x0008

        .equiv  C1RXF9EID_EID4, 0x0004
        .equiv  C1RXF9EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID4_MASK, 0x0010

        .equiv  C1RXF9EID_EID5, 0x0005
        .equiv  C1RXF9EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID5_MASK, 0x0020

        .equiv  C1RXF9EID_EID6, 0x0006
        .equiv  C1RXF9EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID6_MASK, 0x0040

        .equiv  C1RXF9EID_EID7, 0x0007
        .equiv  C1RXF9EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID7_MASK, 0x0080

        .equiv  C1RXF9EID_EID8, 0x0008
        .equiv  C1RXF9EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID8_MASK, 0x0100

        .equiv  C1RXF9EID_EID9, 0x0009
        .equiv  C1RXF9EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID9_MASK, 0x0200

        .equiv  C1RXF9EID_EID10, 0x000A
        .equiv  C1RXF9EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID10_MASK, 0x0400

        .equiv  C1RXF9EID_EID11, 0x000B
        .equiv  C1RXF9EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID11_MASK, 0x0800

        .equiv  C1RXF9EID_EID12, 0x000C
        .equiv  C1RXF9EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID12_MASK, 0x1000

        .equiv  C1RXF9EID_EID13, 0x000D
        .equiv  C1RXF9EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID13_MASK, 0x2000

        .equiv  C1RXF9EID_EID14, 0x000E
        .equiv  C1RXF9EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID14_MASK, 0x4000

        .equiv  C1RXF9EID_EID15, 0x000F
        .equiv  C1RXF9EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF9EID_EID15_MASK, 0x8000

        .equiv  C1RXF9EID_EID, 0x0000
        .equiv  C1RXF9EID_EID_WIDTH, 0x0010
        .equiv  C1RXF9EID_EID_MASK, 0xFFFF

;----- C1RXF10SID Bits -----------------------------------------------------
        .equiv  C1RXF10SID_EID16, 0x0000
        .equiv  C1RXF10SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF10SID_EID16_MASK, 0x0001

        .equiv  C1RXF10SID_EID17, 0x0001
        .equiv  C1RXF10SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF10SID_EID17_MASK, 0x0002

        .equiv  C1RXF10SID_EXIDE, 0x0003
        .equiv  C1RXF10SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF10SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF10SID_SID0, 0x0005
        .equiv  C1RXF10SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID0_MASK, 0x0020

        .equiv  C1RXF10SID_SID1, 0x0006
        .equiv  C1RXF10SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID1_MASK, 0x0040

        .equiv  C1RXF10SID_SID2, 0x0007
        .equiv  C1RXF10SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID2_MASK, 0x0080

        .equiv  C1RXF10SID_SID3, 0x0008
        .equiv  C1RXF10SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID3_MASK, 0x0100

        .equiv  C1RXF10SID_SID4, 0x0009
        .equiv  C1RXF10SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID4_MASK, 0x0200

        .equiv  C1RXF10SID_SID5, 0x000A
        .equiv  C1RXF10SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID5_MASK, 0x0400

        .equiv  C1RXF10SID_SID6, 0x000B
        .equiv  C1RXF10SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID6_MASK, 0x0800

        .equiv  C1RXF10SID_SID7, 0x000C
        .equiv  C1RXF10SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID7_MASK, 0x1000

        .equiv  C1RXF10SID_SID8, 0x000D
        .equiv  C1RXF10SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID8_MASK, 0x2000

        .equiv  C1RXF10SID_SID9, 0x000E
        .equiv  C1RXF10SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID9_MASK, 0x4000

        .equiv  C1RXF10SID_SID10, 0x000F
        .equiv  C1RXF10SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF10SID_SID10_MASK, 0x8000

        .equiv  C1RXF10SID_EID, 0x0000
        .equiv  C1RXF10SID_EID_WIDTH, 0x0002
        .equiv  C1RXF10SID_EID_MASK, 0x0003

        .equiv  C1RXF10SID_SID, 0x0005
        .equiv  C1RXF10SID_SID_WIDTH, 0x000B
        .equiv  C1RXF10SID_SID_MASK, 0xFFE0

;----- C1RXF10EID Bits -----------------------------------------------------
        .equiv  C1RXF10EID_EID0, 0x0000
        .equiv  C1RXF10EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID0_MASK, 0x0001

        .equiv  C1RXF10EID_EID1, 0x0001
        .equiv  C1RXF10EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID1_MASK, 0x0002

        .equiv  C1RXF10EID_EID2, 0x0002
        .equiv  C1RXF10EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID2_MASK, 0x0004

        .equiv  C1RXF10EID_EID3, 0x0003
        .equiv  C1RXF10EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID3_MASK, 0x0008

        .equiv  C1RXF10EID_EID4, 0x0004
        .equiv  C1RXF10EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID4_MASK, 0x0010

        .equiv  C1RXF10EID_EID5, 0x0005
        .equiv  C1RXF10EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID5_MASK, 0x0020

        .equiv  C1RXF10EID_EID6, 0x0006
        .equiv  C1RXF10EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID6_MASK, 0x0040

        .equiv  C1RXF10EID_EID7, 0x0007
        .equiv  C1RXF10EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID7_MASK, 0x0080

        .equiv  C1RXF10EID_EID8, 0x0008
        .equiv  C1RXF10EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID8_MASK, 0x0100

        .equiv  C1RXF10EID_EID9, 0x0009
        .equiv  C1RXF10EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID9_MASK, 0x0200

        .equiv  C1RXF10EID_EID10, 0x000A
        .equiv  C1RXF10EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID10_MASK, 0x0400

        .equiv  C1RXF10EID_EID11, 0x000B
        .equiv  C1RXF10EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID11_MASK, 0x0800

        .equiv  C1RXF10EID_EID12, 0x000C
        .equiv  C1RXF10EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID12_MASK, 0x1000

        .equiv  C1RXF10EID_EID13, 0x000D
        .equiv  C1RXF10EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID13_MASK, 0x2000

        .equiv  C1RXF10EID_EID14, 0x000E
        .equiv  C1RXF10EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID14_MASK, 0x4000

        .equiv  C1RXF10EID_EID15, 0x000F
        .equiv  C1RXF10EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF10EID_EID15_MASK, 0x8000

        .equiv  C1RXF10EID_EID, 0x0000
        .equiv  C1RXF10EID_EID_WIDTH, 0x0010
        .equiv  C1RXF10EID_EID_MASK, 0xFFFF

;----- C1RXF11SID Bits -----------------------------------------------------
        .equiv  C1RXF11SID_EID16, 0x0000
        .equiv  C1RXF11SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF11SID_EID16_MASK, 0x0001

        .equiv  C1RXF11SID_EID17, 0x0001
        .equiv  C1RXF11SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF11SID_EID17_MASK, 0x0002

        .equiv  C1RXF11SID_EXIDE, 0x0003
        .equiv  C1RXF11SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF11SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF11SID_SID0, 0x0005
        .equiv  C1RXF11SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID0_MASK, 0x0020

        .equiv  C1RXF11SID_SID1, 0x0006
        .equiv  C1RXF11SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID1_MASK, 0x0040

        .equiv  C1RXF11SID_SID2, 0x0007
        .equiv  C1RXF11SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID2_MASK, 0x0080

        .equiv  C1RXF11SID_SID3, 0x0008
        .equiv  C1RXF11SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID3_MASK, 0x0100

        .equiv  C1RXF11SID_SID4, 0x0009
        .equiv  C1RXF11SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID4_MASK, 0x0200

        .equiv  C1RXF11SID_SID5, 0x000A
        .equiv  C1RXF11SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID5_MASK, 0x0400

        .equiv  C1RXF11SID_SID6, 0x000B
        .equiv  C1RXF11SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID6_MASK, 0x0800

        .equiv  C1RXF11SID_SID7, 0x000C
        .equiv  C1RXF11SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID7_MASK, 0x1000

        .equiv  C1RXF11SID_SID8, 0x000D
        .equiv  C1RXF11SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID8_MASK, 0x2000

        .equiv  C1RXF11SID_SID9, 0x000E
        .equiv  C1RXF11SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID9_MASK, 0x4000

        .equiv  C1RXF11SID_SID10, 0x000F
        .equiv  C1RXF11SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF11SID_SID10_MASK, 0x8000

        .equiv  C1RXF11SID_EID, 0x0000
        .equiv  C1RXF11SID_EID_WIDTH, 0x0002
        .equiv  C1RXF11SID_EID_MASK, 0x0003

        .equiv  C1RXF11SID_SID, 0x0005
        .equiv  C1RXF11SID_SID_WIDTH, 0x000B
        .equiv  C1RXF11SID_SID_MASK, 0xFFE0

;----- C1RXF11EID Bits -----------------------------------------------------
        .equiv  C1RXF11EID_EID0, 0x0000
        .equiv  C1RXF11EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID0_MASK, 0x0001

        .equiv  C1RXF11EID_EID1, 0x0001
        .equiv  C1RXF11EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID1_MASK, 0x0002

        .equiv  C1RXF11EID_EID2, 0x0002
        .equiv  C1RXF11EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID2_MASK, 0x0004

        .equiv  C1RXF11EID_EID3, 0x0003
        .equiv  C1RXF11EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID3_MASK, 0x0008

        .equiv  C1RXF11EID_EID4, 0x0004
        .equiv  C1RXF11EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID4_MASK, 0x0010

        .equiv  C1RXF11EID_EID5, 0x0005
        .equiv  C1RXF11EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID5_MASK, 0x0020

        .equiv  C1RXF11EID_EID6, 0x0006
        .equiv  C1RXF11EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID6_MASK, 0x0040

        .equiv  C1RXF11EID_EID7, 0x0007
        .equiv  C1RXF11EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID7_MASK, 0x0080

        .equiv  C1RXF11EID_EID8, 0x0008
        .equiv  C1RXF11EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID8_MASK, 0x0100

        .equiv  C1RXF11EID_EID9, 0x0009
        .equiv  C1RXF11EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID9_MASK, 0x0200

        .equiv  C1RXF11EID_EID10, 0x000A
        .equiv  C1RXF11EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID10_MASK, 0x0400

        .equiv  C1RXF11EID_EID11, 0x000B
        .equiv  C1RXF11EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID11_MASK, 0x0800

        .equiv  C1RXF11EID_EID12, 0x000C
        .equiv  C1RXF11EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID12_MASK, 0x1000

        .equiv  C1RXF11EID_EID13, 0x000D
        .equiv  C1RXF11EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID13_MASK, 0x2000

        .equiv  C1RXF11EID_EID14, 0x000E
        .equiv  C1RXF11EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID14_MASK, 0x4000

        .equiv  C1RXF11EID_EID15, 0x000F
        .equiv  C1RXF11EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF11EID_EID15_MASK, 0x8000

        .equiv  C1RXF11EID_EID, 0x0000
        .equiv  C1RXF11EID_EID_WIDTH, 0x0010
        .equiv  C1RXF11EID_EID_MASK, 0xFFFF

;----- C1RXF12SID Bits -----------------------------------------------------
        .equiv  C1RXF12SID_EID16, 0x0000
        .equiv  C1RXF12SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF12SID_EID16_MASK, 0x0001

        .equiv  C1RXF12SID_EID17, 0x0001
        .equiv  C1RXF12SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF12SID_EID17_MASK, 0x0002

        .equiv  C1RXF12SID_EXIDE, 0x0003
        .equiv  C1RXF12SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF12SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF12SID_SID0, 0x0005
        .equiv  C1RXF12SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID0_MASK, 0x0020

        .equiv  C1RXF12SID_SID1, 0x0006
        .equiv  C1RXF12SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID1_MASK, 0x0040

        .equiv  C1RXF12SID_SID2, 0x0007
        .equiv  C1RXF12SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID2_MASK, 0x0080

        .equiv  C1RXF12SID_SID3, 0x0008
        .equiv  C1RXF12SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID3_MASK, 0x0100

        .equiv  C1RXF12SID_SID4, 0x0009
        .equiv  C1RXF12SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID4_MASK, 0x0200

        .equiv  C1RXF12SID_SID5, 0x000A
        .equiv  C1RXF12SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID5_MASK, 0x0400

        .equiv  C1RXF12SID_SID6, 0x000B
        .equiv  C1RXF12SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID6_MASK, 0x0800

        .equiv  C1RXF12SID_SID7, 0x000C
        .equiv  C1RXF12SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID7_MASK, 0x1000

        .equiv  C1RXF12SID_SID8, 0x000D
        .equiv  C1RXF12SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID8_MASK, 0x2000

        .equiv  C1RXF12SID_SID9, 0x000E
        .equiv  C1RXF12SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID9_MASK, 0x4000

        .equiv  C1RXF12SID_SID10, 0x000F
        .equiv  C1RXF12SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF12SID_SID10_MASK, 0x8000

        .equiv  C1RXF12SID_EID, 0x0000
        .equiv  C1RXF12SID_EID_WIDTH, 0x0002
        .equiv  C1RXF12SID_EID_MASK, 0x0003

        .equiv  C1RXF12SID_SID, 0x0005
        .equiv  C1RXF12SID_SID_WIDTH, 0x000B
        .equiv  C1RXF12SID_SID_MASK, 0xFFE0

;----- C1RXF12EID Bits -----------------------------------------------------
        .equiv  C1RXF12EID_EID0, 0x0000
        .equiv  C1RXF12EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID0_MASK, 0x0001

        .equiv  C1RXF12EID_EID1, 0x0001
        .equiv  C1RXF12EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID1_MASK, 0x0002

        .equiv  C1RXF12EID_EID2, 0x0002
        .equiv  C1RXF12EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID2_MASK, 0x0004

        .equiv  C1RXF12EID_EID3, 0x0003
        .equiv  C1RXF12EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID3_MASK, 0x0008

        .equiv  C1RXF12EID_EID4, 0x0004
        .equiv  C1RXF12EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID4_MASK, 0x0010

        .equiv  C1RXF12EID_EID5, 0x0005
        .equiv  C1RXF12EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID5_MASK, 0x0020

        .equiv  C1RXF12EID_EID6, 0x0006
        .equiv  C1RXF12EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID6_MASK, 0x0040

        .equiv  C1RXF12EID_EID7, 0x0007
        .equiv  C1RXF12EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID7_MASK, 0x0080

        .equiv  C1RXF12EID_EID8, 0x0008
        .equiv  C1RXF12EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID8_MASK, 0x0100

        .equiv  C1RXF12EID_EID9, 0x0009
        .equiv  C1RXF12EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID9_MASK, 0x0200

        .equiv  C1RXF12EID_EID10, 0x000A
        .equiv  C1RXF12EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID10_MASK, 0x0400

        .equiv  C1RXF12EID_EID11, 0x000B
        .equiv  C1RXF12EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID11_MASK, 0x0800

        .equiv  C1RXF12EID_EID12, 0x000C
        .equiv  C1RXF12EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID12_MASK, 0x1000

        .equiv  C1RXF12EID_EID13, 0x000D
        .equiv  C1RXF12EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID13_MASK, 0x2000

        .equiv  C1RXF12EID_EID14, 0x000E
        .equiv  C1RXF12EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID14_MASK, 0x4000

        .equiv  C1RXF12EID_EID15, 0x000F
        .equiv  C1RXF12EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF12EID_EID15_MASK, 0x8000

        .equiv  C1RXF12EID_EID, 0x0000
        .equiv  C1RXF12EID_EID_WIDTH, 0x0010
        .equiv  C1RXF12EID_EID_MASK, 0xFFFF

;----- C1RXF13SID Bits -----------------------------------------------------
        .equiv  C1RXF13SID_EID16, 0x0000
        .equiv  C1RXF13SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF13SID_EID16_MASK, 0x0001

        .equiv  C1RXF13SID_EID17, 0x0001
        .equiv  C1RXF13SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF13SID_EID17_MASK, 0x0002

        .equiv  C1RXF13SID_EXIDE, 0x0003
        .equiv  C1RXF13SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF13SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF13SID_SID0, 0x0005
        .equiv  C1RXF13SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID0_MASK, 0x0020

        .equiv  C1RXF13SID_SID1, 0x0006
        .equiv  C1RXF13SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID1_MASK, 0x0040

        .equiv  C1RXF13SID_SID2, 0x0007
        .equiv  C1RXF13SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID2_MASK, 0x0080

        .equiv  C1RXF13SID_SID3, 0x0008
        .equiv  C1RXF13SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID3_MASK, 0x0100

        .equiv  C1RXF13SID_SID4, 0x0009
        .equiv  C1RXF13SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID4_MASK, 0x0200

        .equiv  C1RXF13SID_SID5, 0x000A
        .equiv  C1RXF13SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID5_MASK, 0x0400

        .equiv  C1RXF13SID_SID6, 0x000B
        .equiv  C1RXF13SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID6_MASK, 0x0800

        .equiv  C1RXF13SID_SID7, 0x000C
        .equiv  C1RXF13SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID7_MASK, 0x1000

        .equiv  C1RXF13SID_SID8, 0x000D
        .equiv  C1RXF13SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID8_MASK, 0x2000

        .equiv  C1RXF13SID_SID9, 0x000E
        .equiv  C1RXF13SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID9_MASK, 0x4000

        .equiv  C1RXF13SID_SID10, 0x000F
        .equiv  C1RXF13SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF13SID_SID10_MASK, 0x8000

        .equiv  C1RXF13SID_EID, 0x0000
        .equiv  C1RXF13SID_EID_WIDTH, 0x0002
        .equiv  C1RXF13SID_EID_MASK, 0x0003

        .equiv  C1RXF13SID_SID, 0x0005
        .equiv  C1RXF13SID_SID_WIDTH, 0x000B
        .equiv  C1RXF13SID_SID_MASK, 0xFFE0

;----- C1RXF13EID Bits -----------------------------------------------------
        .equiv  C1RXF13EID_EID0, 0x0000
        .equiv  C1RXF13EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID0_MASK, 0x0001

        .equiv  C1RXF13EID_EID1, 0x0001
        .equiv  C1RXF13EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID1_MASK, 0x0002

        .equiv  C1RXF13EID_EID2, 0x0002
        .equiv  C1RXF13EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID2_MASK, 0x0004

        .equiv  C1RXF13EID_EID3, 0x0003
        .equiv  C1RXF13EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID3_MASK, 0x0008

        .equiv  C1RXF13EID_EID4, 0x0004
        .equiv  C1RXF13EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID4_MASK, 0x0010

        .equiv  C1RXF13EID_EID5, 0x0005
        .equiv  C1RXF13EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID5_MASK, 0x0020

        .equiv  C1RXF13EID_EID6, 0x0006
        .equiv  C1RXF13EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID6_MASK, 0x0040

        .equiv  C1RXF13EID_EID7, 0x0007
        .equiv  C1RXF13EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID7_MASK, 0x0080

        .equiv  C1RXF13EID_EID8, 0x0008
        .equiv  C1RXF13EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID8_MASK, 0x0100

        .equiv  C1RXF13EID_EID9, 0x0009
        .equiv  C1RXF13EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID9_MASK, 0x0200

        .equiv  C1RXF13EID_EID10, 0x000A
        .equiv  C1RXF13EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID10_MASK, 0x0400

        .equiv  C1RXF13EID_EID11, 0x000B
        .equiv  C1RXF13EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID11_MASK, 0x0800

        .equiv  C1RXF13EID_EID12, 0x000C
        .equiv  C1RXF13EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID12_MASK, 0x1000

        .equiv  C1RXF13EID_EID13, 0x000D
        .equiv  C1RXF13EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID13_MASK, 0x2000

        .equiv  C1RXF13EID_EID14, 0x000E
        .equiv  C1RXF13EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID14_MASK, 0x4000

        .equiv  C1RXF13EID_EID15, 0x000F
        .equiv  C1RXF13EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF13EID_EID15_MASK, 0x8000

        .equiv  C1RXF13EID_EID, 0x0000
        .equiv  C1RXF13EID_EID_WIDTH, 0x0010
        .equiv  C1RXF13EID_EID_MASK, 0xFFFF

;----- C1RXF14SID Bits -----------------------------------------------------
        .equiv  C1RXF14SID_EID16, 0x0000
        .equiv  C1RXF14SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF14SID_EID16_MASK, 0x0001

        .equiv  C1RXF14SID_EID17, 0x0001
        .equiv  C1RXF14SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF14SID_EID17_MASK, 0x0002

        .equiv  C1RXF14SID_EXIDE, 0x0003
        .equiv  C1RXF14SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF14SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF14SID_SID0, 0x0005
        .equiv  C1RXF14SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID0_MASK, 0x0020

        .equiv  C1RXF14SID_SID1, 0x0006
        .equiv  C1RXF14SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID1_MASK, 0x0040

        .equiv  C1RXF14SID_SID2, 0x0007
        .equiv  C1RXF14SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID2_MASK, 0x0080

        .equiv  C1RXF14SID_SID3, 0x0008
        .equiv  C1RXF14SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID3_MASK, 0x0100

        .equiv  C1RXF14SID_SID4, 0x0009
        .equiv  C1RXF14SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID4_MASK, 0x0200

        .equiv  C1RXF14SID_SID5, 0x000A
        .equiv  C1RXF14SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID5_MASK, 0x0400

        .equiv  C1RXF14SID_SID6, 0x000B
        .equiv  C1RXF14SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID6_MASK, 0x0800

        .equiv  C1RXF14SID_SID7, 0x000C
        .equiv  C1RXF14SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID7_MASK, 0x1000

        .equiv  C1RXF14SID_SID8, 0x000D
        .equiv  C1RXF14SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID8_MASK, 0x2000

        .equiv  C1RXF14SID_SID9, 0x000E
        .equiv  C1RXF14SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID9_MASK, 0x4000

        .equiv  C1RXF14SID_SID10, 0x000F
        .equiv  C1RXF14SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF14SID_SID10_MASK, 0x8000

        .equiv  C1RXF14SID_EID, 0x0000
        .equiv  C1RXF14SID_EID_WIDTH, 0x0002
        .equiv  C1RXF14SID_EID_MASK, 0x0003

        .equiv  C1RXF14SID_SID, 0x0005
        .equiv  C1RXF14SID_SID_WIDTH, 0x000B
        .equiv  C1RXF14SID_SID_MASK, 0xFFE0

;----- C1RXF14EID Bits -----------------------------------------------------
        .equiv  C1RXF14EID_EID0, 0x0000
        .equiv  C1RXF14EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID0_MASK, 0x0001

        .equiv  C1RXF14EID_EID1, 0x0001
        .equiv  C1RXF14EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID1_MASK, 0x0002

        .equiv  C1RXF14EID_EID2, 0x0002
        .equiv  C1RXF14EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID2_MASK, 0x0004

        .equiv  C1RXF14EID_EID3, 0x0003
        .equiv  C1RXF14EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID3_MASK, 0x0008

        .equiv  C1RXF14EID_EID4, 0x0004
        .equiv  C1RXF14EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID4_MASK, 0x0010

        .equiv  C1RXF14EID_EID5, 0x0005
        .equiv  C1RXF14EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID5_MASK, 0x0020

        .equiv  C1RXF14EID_EID6, 0x0006
        .equiv  C1RXF14EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID6_MASK, 0x0040

        .equiv  C1RXF14EID_EID7, 0x0007
        .equiv  C1RXF14EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID7_MASK, 0x0080

        .equiv  C1RXF14EID_EID8, 0x0008
        .equiv  C1RXF14EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID8_MASK, 0x0100

        .equiv  C1RXF14EID_EID9, 0x0009
        .equiv  C1RXF14EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID9_MASK, 0x0200

        .equiv  C1RXF14EID_EID10, 0x000A
        .equiv  C1RXF14EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID10_MASK, 0x0400

        .equiv  C1RXF14EID_EID11, 0x000B
        .equiv  C1RXF14EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID11_MASK, 0x0800

        .equiv  C1RXF14EID_EID12, 0x000C
        .equiv  C1RXF14EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID12_MASK, 0x1000

        .equiv  C1RXF14EID_EID13, 0x000D
        .equiv  C1RXF14EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID13_MASK, 0x2000

        .equiv  C1RXF14EID_EID14, 0x000E
        .equiv  C1RXF14EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID14_MASK, 0x4000

        .equiv  C1RXF14EID_EID15, 0x000F
        .equiv  C1RXF14EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF14EID_EID15_MASK, 0x8000

        .equiv  C1RXF14EID_EID, 0x0000
        .equiv  C1RXF14EID_EID_WIDTH, 0x0010
        .equiv  C1RXF14EID_EID_MASK, 0xFFFF

;----- C1RXF15SID Bits -----------------------------------------------------
        .equiv  C1RXF15SID_EID16, 0x0000
        .equiv  C1RXF15SID_EID16_WIDTH, 0x0001
        .equiv  C1RXF15SID_EID16_MASK, 0x0001

        .equiv  C1RXF15SID_EID17, 0x0001
        .equiv  C1RXF15SID_EID17_WIDTH, 0x0001
        .equiv  C1RXF15SID_EID17_MASK, 0x0002

        .equiv  C1RXF15SID_EXIDE, 0x0003
        .equiv  C1RXF15SID_EXIDE_WIDTH, 0x0001
        .equiv  C1RXF15SID_EXIDE_MASK, 0x0008

        .equiv  C1RXF15SID_SID0, 0x0005
        .equiv  C1RXF15SID_SID0_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID0_MASK, 0x0020

        .equiv  C1RXF15SID_SID1, 0x0006
        .equiv  C1RXF15SID_SID1_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID1_MASK, 0x0040

        .equiv  C1RXF15SID_SID2, 0x0007
        .equiv  C1RXF15SID_SID2_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID2_MASK, 0x0080

        .equiv  C1RXF15SID_SID3, 0x0008
        .equiv  C1RXF15SID_SID3_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID3_MASK, 0x0100

        .equiv  C1RXF15SID_SID4, 0x0009
        .equiv  C1RXF15SID_SID4_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID4_MASK, 0x0200

        .equiv  C1RXF15SID_SID5, 0x000A
        .equiv  C1RXF15SID_SID5_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID5_MASK, 0x0400

        .equiv  C1RXF15SID_SID6, 0x000B
        .equiv  C1RXF15SID_SID6_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID6_MASK, 0x0800

        .equiv  C1RXF15SID_SID7, 0x000C
        .equiv  C1RXF15SID_SID7_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID7_MASK, 0x1000

        .equiv  C1RXF15SID_SID8, 0x000D
        .equiv  C1RXF15SID_SID8_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID8_MASK, 0x2000

        .equiv  C1RXF15SID_SID9, 0x000E
        .equiv  C1RXF15SID_SID9_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID9_MASK, 0x4000

        .equiv  C1RXF15SID_SID10, 0x000F
        .equiv  C1RXF15SID_SID10_WIDTH, 0x0001
        .equiv  C1RXF15SID_SID10_MASK, 0x8000

        .equiv  C1RXF15SID_EID, 0x0000
        .equiv  C1RXF15SID_EID_WIDTH, 0x0002
        .equiv  C1RXF15SID_EID_MASK, 0x0003

        .equiv  C1RXF15SID_SID, 0x0005
        .equiv  C1RXF15SID_SID_WIDTH, 0x000B
        .equiv  C1RXF15SID_SID_MASK, 0xFFE0

;----- C1RXF15EID Bits -----------------------------------------------------
        .equiv  C1RXF15EID_EID0, 0x0000
        .equiv  C1RXF15EID_EID0_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID0_MASK, 0x0001

        .equiv  C1RXF15EID_EID1, 0x0001
        .equiv  C1RXF15EID_EID1_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID1_MASK, 0x0002

        .equiv  C1RXF15EID_EID2, 0x0002
        .equiv  C1RXF15EID_EID2_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID2_MASK, 0x0004

        .equiv  C1RXF15EID_EID3, 0x0003
        .equiv  C1RXF15EID_EID3_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID3_MASK, 0x0008

        .equiv  C1RXF15EID_EID4, 0x0004
        .equiv  C1RXF15EID_EID4_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID4_MASK, 0x0010

        .equiv  C1RXF15EID_EID5, 0x0005
        .equiv  C1RXF15EID_EID5_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID5_MASK, 0x0020

        .equiv  C1RXF15EID_EID6, 0x0006
        .equiv  C1RXF15EID_EID6_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID6_MASK, 0x0040

        .equiv  C1RXF15EID_EID7, 0x0007
        .equiv  C1RXF15EID_EID7_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID7_MASK, 0x0080

        .equiv  C1RXF15EID_EID8, 0x0008
        .equiv  C1RXF15EID_EID8_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID8_MASK, 0x0100

        .equiv  C1RXF15EID_EID9, 0x0009
        .equiv  C1RXF15EID_EID9_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID9_MASK, 0x0200

        .equiv  C1RXF15EID_EID10, 0x000A
        .equiv  C1RXF15EID_EID10_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID10_MASK, 0x0400

        .equiv  C1RXF15EID_EID11, 0x000B
        .equiv  C1RXF15EID_EID11_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID11_MASK, 0x0800

        .equiv  C1RXF15EID_EID12, 0x000C
        .equiv  C1RXF15EID_EID12_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID12_MASK, 0x1000

        .equiv  C1RXF15EID_EID13, 0x000D
        .equiv  C1RXF15EID_EID13_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID13_MASK, 0x2000

        .equiv  C1RXF15EID_EID14, 0x000E
        .equiv  C1RXF15EID_EID14_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID14_MASK, 0x4000

        .equiv  C1RXF15EID_EID15, 0x000F
        .equiv  C1RXF15EID_EID15_WIDTH, 0x0001
        .equiv  C1RXF15EID_EID15_MASK, 0x8000

        .equiv  C1RXF15EID_EID, 0x0000
        .equiv  C1RXF15EID_EID_WIDTH, 0x0010
        .equiv  C1RXF15EID_EID_MASK, 0xFFFF

;----- CRCCON1 Bits -----------------------------------------------------
        .equiv  CRCCON1_LENDIAN, 0x0003
        .equiv  CRCCON1_LENDIAN_WIDTH, 0x0001
        .equiv  CRCCON1_LENDIAN_MASK, 0x0008
        .equiv  LENDIAN, 0x0003

        .equiv  CRCCON1_CRCGO, 0x0004
        .equiv  CRCCON1_CRCGO_WIDTH, 0x0001
        .equiv  CRCCON1_CRCGO_MASK, 0x0010
        .equiv  CRCGO, 0x0004

        .equiv  CRCCON1_CRCISEL, 0x0005
        .equiv  CRCCON1_CRCISEL_WIDTH, 0x0001
        .equiv  CRCCON1_CRCISEL_MASK, 0x0020
        .equiv  CRCISEL, 0x0005

        .equiv  CRCCON1_CRCMPT, 0x0006
        .equiv  CRCCON1_CRCMPT_WIDTH, 0x0001
        .equiv  CRCCON1_CRCMPT_MASK, 0x0040
        .equiv  CRCMPT, 0x0006

        .equiv  CRCCON1_CRCFUL, 0x0007
        .equiv  CRCCON1_CRCFUL_WIDTH, 0x0001
        .equiv  CRCCON1_CRCFUL_MASK, 0x0080
        .equiv  CRCFUL, 0x0007

        .equiv  CRCCON1_VWORD, 0x0008
        .equiv  CRCCON1_VWORD_WIDTH, 0x0005
        .equiv  CRCCON1_VWORD_MASK, 0x1F00

        .equiv  CRCCON1_CSIDL, 0x000D
        .equiv  CRCCON1_CSIDL_WIDTH, 0x0001
        .equiv  CRCCON1_CSIDL_MASK, 0x2000

        .equiv  CRCCON1_CRCEN, 0x000F
        .equiv  CRCCON1_CRCEN_WIDTH, 0x0001
        .equiv  CRCCON1_CRCEN_MASK, 0x8000
        .equiv  CRCEN, 0x000F

        .equiv  CRCCON1_VWORD0, 0x0008
        .equiv  CRCCON1_VWORD0_WIDTH, 0x0001
        .equiv  CRCCON1_VWORD0_MASK, 0x0100
        .equiv  VWORD0, 0x0008

        .equiv  CRCCON1_VWORD1, 0x0009
        .equiv  CRCCON1_VWORD1_WIDTH, 0x0001
        .equiv  CRCCON1_VWORD1_MASK, 0x0200
        .equiv  VWORD1, 0x0009

        .equiv  CRCCON1_VWORD2, 0x000A
        .equiv  CRCCON1_VWORD2_WIDTH, 0x0001
        .equiv  CRCCON1_VWORD2_MASK, 0x0400
        .equiv  VWORD2, 0x000A

        .equiv  CRCCON1_VWORD3, 0x000B
        .equiv  CRCCON1_VWORD3_WIDTH, 0x0001
        .equiv  CRCCON1_VWORD3_MASK, 0x0800
        .equiv  VWORD3, 0x000B

        .equiv  CRCCON1_VWORD4, 0x000C
        .equiv  CRCCON1_VWORD4_WIDTH, 0x0001
        .equiv  CRCCON1_VWORD4_MASK, 0x1000
        .equiv  VWORD4, 0x000C

;----- CRCCON2 Bits -----------------------------------------------------
        .equiv  CRCCON2_PLEN, 0x0000
        .equiv  CRCCON2_PLEN_WIDTH, 0x0005
        .equiv  CRCCON2_PLEN_MASK, 0x001F

        .equiv  CRCCON2_DWIDTH, 0x0008
        .equiv  CRCCON2_DWIDTH_WIDTH, 0x0005
        .equiv  CRCCON2_DWIDTH_MASK, 0x1F00

        .equiv  CRCCON2_PLEN0, 0x0000
        .equiv  CRCCON2_PLEN0_WIDTH, 0x0001
        .equiv  CRCCON2_PLEN0_MASK, 0x0001
        .equiv  PLEN0, 0x0000

        .equiv  CRCCON2_PLEN1, 0x0001
        .equiv  CRCCON2_PLEN1_WIDTH, 0x0001
        .equiv  CRCCON2_PLEN1_MASK, 0x0002
        .equiv  PLEN1, 0x0001

        .equiv  CRCCON2_PLEN2, 0x0002
        .equiv  CRCCON2_PLEN2_WIDTH, 0x0001
        .equiv  CRCCON2_PLEN2_MASK, 0x0004
        .equiv  PLEN2, 0x0002

        .equiv  CRCCON2_PLEN3, 0x0003
        .equiv  CRCCON2_PLEN3_WIDTH, 0x0001
        .equiv  CRCCON2_PLEN3_MASK, 0x0008
        .equiv  PLEN3, 0x0003

        .equiv  CRCCON2_PLEN4, 0x0004
        .equiv  CRCCON2_PLEN4_WIDTH, 0x0001
        .equiv  CRCCON2_PLEN4_MASK, 0x0010
        .equiv  PLEN4, 0x0004

        .equiv  CRCCON2_DWIDTH0, 0x0008
        .equiv  CRCCON2_DWIDTH0_WIDTH, 0x0001
        .equiv  CRCCON2_DWIDTH0_MASK, 0x0100
        .equiv  DWIDTH0, 0x0008

        .equiv  CRCCON2_DWIDTH1, 0x0009
        .equiv  CRCCON2_DWIDTH1_WIDTH, 0x0001
        .equiv  CRCCON2_DWIDTH1_MASK, 0x0200
        .equiv  DWIDTH1, 0x0009

        .equiv  CRCCON2_DWIDTH2, 0x000A
        .equiv  CRCCON2_DWIDTH2_WIDTH, 0x0001
        .equiv  CRCCON2_DWIDTH2_MASK, 0x0400
        .equiv  DWIDTH2, 0x000A

        .equiv  CRCCON2_DWIDTH3, 0x000B
        .equiv  CRCCON2_DWIDTH3_WIDTH, 0x0001
        .equiv  CRCCON2_DWIDTH3_MASK, 0x0800
        .equiv  DWIDTH3, 0x000B

        .equiv  CRCCON2_DWIDTH4, 0x000C
        .equiv  CRCCON2_DWIDTH4_WIDTH, 0x0001
        .equiv  CRCCON2_DWIDTH4_MASK, 0x1000
        .equiv  DWIDTH4, 0x000C

;----- CRCXORL Bits -----------------------------------------------------
        .equiv  CRCXORL_X1, 0x0001
        .equiv  CRCXORL_X1_WIDTH, 0x0001
        .equiv  CRCXORL_X1_MASK, 0x0002
        .equiv  X1, 0x0001

        .equiv  CRCXORL_X2, 0x0002
        .equiv  CRCXORL_X2_WIDTH, 0x0001
        .equiv  CRCXORL_X2_MASK, 0x0004
        .equiv  X2, 0x0002

        .equiv  CRCXORL_X3, 0x0003
        .equiv  CRCXORL_X3_WIDTH, 0x0001
        .equiv  CRCXORL_X3_MASK, 0x0008
        .equiv  X3, 0x0003

        .equiv  CRCXORL_X4, 0x0004
        .equiv  CRCXORL_X4_WIDTH, 0x0001
        .equiv  CRCXORL_X4_MASK, 0x0010
        .equiv  X4, 0x0004

        .equiv  CRCXORL_X5, 0x0005
        .equiv  CRCXORL_X5_WIDTH, 0x0001
        .equiv  CRCXORL_X5_MASK, 0x0020
        .equiv  X5, 0x0005

        .equiv  CRCXORL_X6, 0x0006
        .equiv  CRCXORL_X6_WIDTH, 0x0001
        .equiv  CRCXORL_X6_MASK, 0x0040
        .equiv  X6, 0x0006

        .equiv  CRCXORL_X7, 0x0007
        .equiv  CRCXORL_X7_WIDTH, 0x0001
        .equiv  CRCXORL_X7_MASK, 0x0080
        .equiv  X7, 0x0007

        .equiv  CRCXORL_X8, 0x0008
        .equiv  CRCXORL_X8_WIDTH, 0x0001
        .equiv  CRCXORL_X8_MASK, 0x0100
        .equiv  X8, 0x0008

        .equiv  CRCXORL_X9, 0x0009
        .equiv  CRCXORL_X9_WIDTH, 0x0001
        .equiv  CRCXORL_X9_MASK, 0x0200
        .equiv  X9, 0x0009

        .equiv  CRCXORL_X10, 0x000A
        .equiv  CRCXORL_X10_WIDTH, 0x0001
        .equiv  CRCXORL_X10_MASK, 0x0400
        .equiv  X10, 0x000A

        .equiv  CRCXORL_X11, 0x000B
        .equiv  CRCXORL_X11_WIDTH, 0x0001
        .equiv  CRCXORL_X11_MASK, 0x0800
        .equiv  X11, 0x000B

        .equiv  CRCXORL_X12, 0x000C
        .equiv  CRCXORL_X12_WIDTH, 0x0001
        .equiv  CRCXORL_X12_MASK, 0x1000
        .equiv  X12, 0x000C

        .equiv  CRCXORL_X13, 0x000D
        .equiv  CRCXORL_X13_WIDTH, 0x0001
        .equiv  CRCXORL_X13_MASK, 0x2000
        .equiv  X13, 0x000D

        .equiv  CRCXORL_X14, 0x000E
        .equiv  CRCXORL_X14_WIDTH, 0x0001
        .equiv  CRCXORL_X14_MASK, 0x4000
        .equiv  X14, 0x000E

        .equiv  CRCXORL_X15, 0x000F
        .equiv  CRCXORL_X15_WIDTH, 0x0001
        .equiv  CRCXORL_X15_MASK, 0x8000
        .equiv  X15, 0x000F

;----- CRCXORH Bits -----------------------------------------------------
        .equiv  CRCXORH_X16, 0x0000
        .equiv  CRCXORH_X16_WIDTH, 0x0001
        .equiv  CRCXORH_X16_MASK, 0x0001
        .equiv  X16, 0x0000

        .equiv  CRCXORH_X17, 0x0001
        .equiv  CRCXORH_X17_WIDTH, 0x0001
        .equiv  CRCXORH_X17_MASK, 0x0002
        .equiv  X17, 0x0001

        .equiv  CRCXORH_X18, 0x0002
        .equiv  CRCXORH_X18_WIDTH, 0x0001
        .equiv  CRCXORH_X18_MASK, 0x0004
        .equiv  X18, 0x0002

        .equiv  CRCXORH_X19, 0x0003
        .equiv  CRCXORH_X19_WIDTH, 0x0001
        .equiv  CRCXORH_X19_MASK, 0x0008
        .equiv  X19, 0x0003

        .equiv  CRCXORH_X20, 0x0004
        .equiv  CRCXORH_X20_WIDTH, 0x0001
        .equiv  CRCXORH_X20_MASK, 0x0010
        .equiv  X20, 0x0004

        .equiv  CRCXORH_X21, 0x0005
        .equiv  CRCXORH_X21_WIDTH, 0x0001
        .equiv  CRCXORH_X21_MASK, 0x0020
        .equiv  X21, 0x0005

        .equiv  CRCXORH_X22, 0x0006
        .equiv  CRCXORH_X22_WIDTH, 0x0001
        .equiv  CRCXORH_X22_MASK, 0x0040
        .equiv  X22, 0x0006

        .equiv  CRCXORH_X23, 0x0007
        .equiv  CRCXORH_X23_WIDTH, 0x0001
        .equiv  CRCXORH_X23_MASK, 0x0080
        .equiv  X23, 0x0007

        .equiv  CRCXORH_X24, 0x0008
        .equiv  CRCXORH_X24_WIDTH, 0x0001
        .equiv  CRCXORH_X24_MASK, 0x0100
        .equiv  X24, 0x0008

        .equiv  CRCXORH_X25, 0x0009
        .equiv  CRCXORH_X25_WIDTH, 0x0001
        .equiv  CRCXORH_X25_MASK, 0x0200
        .equiv  X25, 0x0009

        .equiv  CRCXORH_X26, 0x000A
        .equiv  CRCXORH_X26_WIDTH, 0x0001
        .equiv  CRCXORH_X26_MASK, 0x0400
        .equiv  X26, 0x000A

        .equiv  CRCXORH_X27, 0x000B
        .equiv  CRCXORH_X27_WIDTH, 0x0001
        .equiv  CRCXORH_X27_MASK, 0x0800
        .equiv  X27, 0x000B

        .equiv  CRCXORH_X28, 0x000C
        .equiv  CRCXORH_X28_WIDTH, 0x0001
        .equiv  CRCXORH_X28_MASK, 0x1000
        .equiv  X28, 0x000C

        .equiv  CRCXORH_X29, 0x000D
        .equiv  CRCXORH_X29_WIDTH, 0x0001
        .equiv  CRCXORH_X29_MASK, 0x2000
        .equiv  X29, 0x000D

        .equiv  CRCXORH_X30, 0x000E
        .equiv  CRCXORH_X30_WIDTH, 0x0001
        .equiv  CRCXORH_X30_MASK, 0x4000
        .equiv  X30, 0x000E

        .equiv  CRCXORH_X31, 0x000F
        .equiv  CRCXORH_X31_WIDTH, 0x0001
        .equiv  CRCXORH_X31_MASK, 0x8000
        .equiv  X31, 0x000F

;----- RPOR0 Bits -----------------------------------------------------
        .equiv  RPOR0_RP20R, 0x0000
        .equiv  RPOR0_RP20R_WIDTH, 0x0006
        .equiv  RPOR0_RP20R_MASK, 0x003F

        .equiv  RPOR0_RP35R, 0x0008
        .equiv  RPOR0_RP35R_WIDTH, 0x0006
        .equiv  RPOR0_RP35R_MASK, 0x3F00

        .equiv  RPOR0_RP20R0, 0x0000
        .equiv  RPOR0_RP20R0_WIDTH, 0x0001
        .equiv  RPOR0_RP20R0_MASK, 0x0001
        .equiv  RP20R0, 0x0000

        .equiv  RPOR0_RP20R1, 0x0001
        .equiv  RPOR0_RP20R1_WIDTH, 0x0001
        .equiv  RPOR0_RP20R1_MASK, 0x0002
        .equiv  RP20R1, 0x0001

        .equiv  RPOR0_RP20R2, 0x0002
        .equiv  RPOR0_RP20R2_WIDTH, 0x0001
        .equiv  RPOR0_RP20R2_MASK, 0x0004
        .equiv  RP20R2, 0x0002

        .equiv  RPOR0_RP20R3, 0x0003
        .equiv  RPOR0_RP20R3_WIDTH, 0x0001
        .equiv  RPOR0_RP20R3_MASK, 0x0008
        .equiv  RP20R3, 0x0003

        .equiv  RPOR0_RP20R4, 0x0004
        .equiv  RPOR0_RP20R4_WIDTH, 0x0001
        .equiv  RPOR0_RP20R4_MASK, 0x0010
        .equiv  RP20R4, 0x0004

        .equiv  RPOR0_RP20R5, 0x0005
        .equiv  RPOR0_RP20R5_WIDTH, 0x0001
        .equiv  RPOR0_RP20R5_MASK, 0x0020
        .equiv  RP20R5, 0x0005

        .equiv  RPOR0_RP35R0, 0x0008
        .equiv  RPOR0_RP35R0_WIDTH, 0x0001
        .equiv  RPOR0_RP35R0_MASK, 0x0100
        .equiv  RP35R0, 0x0008

        .equiv  RPOR0_RP35R1, 0x0009
        .equiv  RPOR0_RP35R1_WIDTH, 0x0001
        .equiv  RPOR0_RP35R1_MASK, 0x0200
        .equiv  RP35R1, 0x0009

        .equiv  RPOR0_RP35R2, 0x000A
        .equiv  RPOR0_RP35R2_WIDTH, 0x0001
        .equiv  RPOR0_RP35R2_MASK, 0x0400
        .equiv  RP35R2, 0x000A

        .equiv  RPOR0_RP35R3, 0x000B
        .equiv  RPOR0_RP35R3_WIDTH, 0x0001
        .equiv  RPOR0_RP35R3_MASK, 0x0800
        .equiv  RP35R3, 0x000B

        .equiv  RPOR0_RP35R4, 0x000C
        .equiv  RPOR0_RP35R4_WIDTH, 0x0001
        .equiv  RPOR0_RP35R4_MASK, 0x1000
        .equiv  RP35R4, 0x000C

        .equiv  RPOR0_RP35R5, 0x000D
        .equiv  RPOR0_RP35R5_WIDTH, 0x0001
        .equiv  RPOR0_RP35R5_MASK, 0x2000
        .equiv  RP35R5, 0x000D

;----- RPOR1 Bits -----------------------------------------------------
        .equiv  RPOR1_RP36R, 0x0000
        .equiv  RPOR1_RP36R_WIDTH, 0x0006
        .equiv  RPOR1_RP36R_MASK, 0x003F

        .equiv  RPOR1_RP37R, 0x0008
        .equiv  RPOR1_RP37R_WIDTH, 0x0006
        .equiv  RPOR1_RP37R_MASK, 0x3F00

        .equiv  RPOR1_RP36R0, 0x0000
        .equiv  RPOR1_RP36R0_WIDTH, 0x0001
        .equiv  RPOR1_RP36R0_MASK, 0x0001
        .equiv  RP36R0, 0x0000

        .equiv  RPOR1_RP36R1, 0x0001
        .equiv  RPOR1_RP36R1_WIDTH, 0x0001
        .equiv  RPOR1_RP36R1_MASK, 0x0002
        .equiv  RP36R1, 0x0001

        .equiv  RPOR1_RP36R2, 0x0002
        .equiv  RPOR1_RP36R2_WIDTH, 0x0001
        .equiv  RPOR1_RP36R2_MASK, 0x0004
        .equiv  RP36R2, 0x0002

        .equiv  RPOR1_RP36R3, 0x0003
        .equiv  RPOR1_RP36R3_WIDTH, 0x0001
        .equiv  RPOR1_RP36R3_MASK, 0x0008
        .equiv  RP36R3, 0x0003

        .equiv  RPOR1_RP36R4, 0x0004
        .equiv  RPOR1_RP36R4_WIDTH, 0x0001
        .equiv  RPOR1_RP36R4_MASK, 0x0010
        .equiv  RP36R4, 0x0004

        .equiv  RPOR1_RP36R5, 0x0005
        .equiv  RPOR1_RP36R5_WIDTH, 0x0001
        .equiv  RPOR1_RP36R5_MASK, 0x0020
        .equiv  RP36R5, 0x0005

        .equiv  RPOR1_RP37R0, 0x0008
        .equiv  RPOR1_RP37R0_WIDTH, 0x0001
        .equiv  RPOR1_RP37R0_MASK, 0x0100
        .equiv  RP37R0, 0x0008

        .equiv  RPOR1_RP37R1, 0x0009
        .equiv  RPOR1_RP37R1_WIDTH, 0x0001
        .equiv  RPOR1_RP37R1_MASK, 0x0200
        .equiv  RP37R1, 0x0009

        .equiv  RPOR1_RP37R2, 0x000A
        .equiv  RPOR1_RP37R2_WIDTH, 0x0001
        .equiv  RPOR1_RP37R2_MASK, 0x0400
        .equiv  RP37R2, 0x000A

        .equiv  RPOR1_RP37R3, 0x000B
        .equiv  RPOR1_RP37R3_WIDTH, 0x0001
        .equiv  RPOR1_RP37R3_MASK, 0x0800
        .equiv  RP37R3, 0x000B

        .equiv  RPOR1_RP37R4, 0x000C
        .equiv  RPOR1_RP37R4_WIDTH, 0x0001
        .equiv  RPOR1_RP37R4_MASK, 0x1000
        .equiv  RP37R4, 0x000C

        .equiv  RPOR1_RP37R5, 0x000D
        .equiv  RPOR1_RP37R5_WIDTH, 0x0001
        .equiv  RPOR1_RP37R5_MASK, 0x2000
        .equiv  RP37R5, 0x000D

;----- RPOR2 Bits -----------------------------------------------------
        .equiv  RPOR2_RP38R, 0x0000
        .equiv  RPOR2_RP38R_WIDTH, 0x0006
        .equiv  RPOR2_RP38R_MASK, 0x003F

        .equiv  RPOR2_RP39R, 0x0008
        .equiv  RPOR2_RP39R_WIDTH, 0x0006
        .equiv  RPOR2_RP39R_MASK, 0x3F00

        .equiv  RPOR2_RP38R0, 0x0000
        .equiv  RPOR2_RP38R0_WIDTH, 0x0001
        .equiv  RPOR2_RP38R0_MASK, 0x0001
        .equiv  RP38R0, 0x0000

        .equiv  RPOR2_RP38R1, 0x0001
        .equiv  RPOR2_RP38R1_WIDTH, 0x0001
        .equiv  RPOR2_RP38R1_MASK, 0x0002
        .equiv  RP38R1, 0x0001

        .equiv  RPOR2_RP38R2, 0x0002
        .equiv  RPOR2_RP38R2_WIDTH, 0x0001
        .equiv  RPOR2_RP38R2_MASK, 0x0004
        .equiv  RP38R2, 0x0002

        .equiv  RPOR2_RP38R3, 0x0003
        .equiv  RPOR2_RP38R3_WIDTH, 0x0001
        .equiv  RPOR2_RP38R3_MASK, 0x0008
        .equiv  RP38R3, 0x0003

        .equiv  RPOR2_RP38R4, 0x0004
        .equiv  RPOR2_RP38R4_WIDTH, 0x0001
        .equiv  RPOR2_RP38R4_MASK, 0x0010
        .equiv  RP38R4, 0x0004

        .equiv  RPOR2_RP38R5, 0x0005
        .equiv  RPOR2_RP38R5_WIDTH, 0x0001
        .equiv  RPOR2_RP38R5_MASK, 0x0020
        .equiv  RP38R5, 0x0005

        .equiv  RPOR2_RP39R0, 0x0008
        .equiv  RPOR2_RP39R0_WIDTH, 0x0001
        .equiv  RPOR2_RP39R0_MASK, 0x0100
        .equiv  RP39R0, 0x0008

        .equiv  RPOR2_RP39R1, 0x0009
        .equiv  RPOR2_RP39R1_WIDTH, 0x0001
        .equiv  RPOR2_RP39R1_MASK, 0x0200
        .equiv  RP39R1, 0x0009

        .equiv  RPOR2_RP39R2, 0x000A
        .equiv  RPOR2_RP39R2_WIDTH, 0x0001
        .equiv  RPOR2_RP39R2_MASK, 0x0400
        .equiv  RP39R2, 0x000A

        .equiv  RPOR2_RP39R3, 0x000B
        .equiv  RPOR2_RP39R3_WIDTH, 0x0001
        .equiv  RPOR2_RP39R3_MASK, 0x0800
        .equiv  RP39R3, 0x000B

        .equiv  RPOR2_RP39R4, 0x000C
        .equiv  RPOR2_RP39R4_WIDTH, 0x0001
        .equiv  RPOR2_RP39R4_MASK, 0x1000
        .equiv  RP39R4, 0x000C

        .equiv  RPOR2_RP39R5, 0x000D
        .equiv  RPOR2_RP39R5_WIDTH, 0x0001
        .equiv  RPOR2_RP39R5_MASK, 0x2000
        .equiv  RP39R5, 0x000D

;----- RPOR3 Bits -----------------------------------------------------
        .equiv  RPOR3_RP40R, 0x0000
        .equiv  RPOR3_RP40R_WIDTH, 0x0006
        .equiv  RPOR3_RP40R_MASK, 0x003F

        .equiv  RPOR3_RP41R, 0x0008
        .equiv  RPOR3_RP41R_WIDTH, 0x0006
        .equiv  RPOR3_RP41R_MASK, 0x3F00

        .equiv  RPOR3_RP40R0, 0x0000
        .equiv  RPOR3_RP40R0_WIDTH, 0x0001
        .equiv  RPOR3_RP40R0_MASK, 0x0001
        .equiv  RP40R0, 0x0000

        .equiv  RPOR3_RP40R1, 0x0001
        .equiv  RPOR3_RP40R1_WIDTH, 0x0001
        .equiv  RPOR3_RP40R1_MASK, 0x0002
        .equiv  RP40R1, 0x0001

        .equiv  RPOR3_RP40R2, 0x0002
        .equiv  RPOR3_RP40R2_WIDTH, 0x0001
        .equiv  RPOR3_RP40R2_MASK, 0x0004
        .equiv  RP40R2, 0x0002

        .equiv  RPOR3_RP40R3, 0x0003
        .equiv  RPOR3_RP40R3_WIDTH, 0x0001
        .equiv  RPOR3_RP40R3_MASK, 0x0008
        .equiv  RP40R3, 0x0003

        .equiv  RPOR3_RP40R4, 0x0004
        .equiv  RPOR3_RP40R4_WIDTH, 0x0001
        .equiv  RPOR3_RP40R4_MASK, 0x0010
        .equiv  RP40R4, 0x0004

        .equiv  RPOR3_RP40R5, 0x0005
        .equiv  RPOR3_RP40R5_WIDTH, 0x0001
        .equiv  RPOR3_RP40R5_MASK, 0x0020
        .equiv  RP40R5, 0x0005

        .equiv  RPOR3_RP41R0, 0x0008
        .equiv  RPOR3_RP41R0_WIDTH, 0x0001
        .equiv  RPOR3_RP41R0_MASK, 0x0100
        .equiv  RP41R0, 0x0008

        .equiv  RPOR3_RP41R1, 0x0009
        .equiv  RPOR3_RP41R1_WIDTH, 0x0001
        .equiv  RPOR3_RP41R1_MASK, 0x0200
        .equiv  RP41R1, 0x0009

        .equiv  RPOR3_RP41R2, 0x000A
        .equiv  RPOR3_RP41R2_WIDTH, 0x0001
        .equiv  RPOR3_RP41R2_MASK, 0x0400
        .equiv  RP41R2, 0x000A

        .equiv  RPOR3_RP41R3, 0x000B
        .equiv  RPOR3_RP41R3_WIDTH, 0x0001
        .equiv  RPOR3_RP41R3_MASK, 0x0800
        .equiv  RP41R3, 0x000B

        .equiv  RPOR3_RP41R4, 0x000C
        .equiv  RPOR3_RP41R4_WIDTH, 0x0001
        .equiv  RPOR3_RP41R4_MASK, 0x1000
        .equiv  RP41R4, 0x000C

        .equiv  RPOR3_RP41R5, 0x000D
        .equiv  RPOR3_RP41R5_WIDTH, 0x0001
        .equiv  RPOR3_RP41R5_MASK, 0x2000
        .equiv  RP41R5, 0x000D

;----- RPOR4 Bits -----------------------------------------------------
        .equiv  RPOR4_RP42R, 0x0000
        .equiv  RPOR4_RP42R_WIDTH, 0x0006
        .equiv  RPOR4_RP42R_MASK, 0x003F

        .equiv  RPOR4_RP43R, 0x0008
        .equiv  RPOR4_RP43R_WIDTH, 0x0006
        .equiv  RPOR4_RP43R_MASK, 0x3F00

        .equiv  RPOR4_RP42R0, 0x0000
        .equiv  RPOR4_RP42R0_WIDTH, 0x0001
        .equiv  RPOR4_RP42R0_MASK, 0x0001
        .equiv  RP42R0, 0x0000

        .equiv  RPOR4_RP42R1, 0x0001
        .equiv  RPOR4_RP42R1_WIDTH, 0x0001
        .equiv  RPOR4_RP42R1_MASK, 0x0002
        .equiv  RP42R1, 0x0001

        .equiv  RPOR4_RP42R2, 0x0002
        .equiv  RPOR4_RP42R2_WIDTH, 0x0001
        .equiv  RPOR4_RP42R2_MASK, 0x0004
        .equiv  RP42R2, 0x0002

        .equiv  RPOR4_RP42R3, 0x0003
        .equiv  RPOR4_RP42R3_WIDTH, 0x0001
        .equiv  RPOR4_RP42R3_MASK, 0x0008
        .equiv  RP42R3, 0x0003

        .equiv  RPOR4_RP42R4, 0x0004
        .equiv  RPOR4_RP42R4_WIDTH, 0x0001
        .equiv  RPOR4_RP42R4_MASK, 0x0010
        .equiv  RP42R4, 0x0004

        .equiv  RPOR4_RP42R5, 0x0005
        .equiv  RPOR4_RP42R5_WIDTH, 0x0001
        .equiv  RPOR4_RP42R5_MASK, 0x0020
        .equiv  RP42R5, 0x0005

        .equiv  RPOR4_RP43R0, 0x0008
        .equiv  RPOR4_RP43R0_WIDTH, 0x0001
        .equiv  RPOR4_RP43R0_MASK, 0x0100
        .equiv  RP43R0, 0x0008

        .equiv  RPOR4_RP43R1, 0x0009
        .equiv  RPOR4_RP43R1_WIDTH, 0x0001
        .equiv  RPOR4_RP43R1_MASK, 0x0200
        .equiv  RP43R1, 0x0009

        .equiv  RPOR4_RP43R2, 0x000A
        .equiv  RPOR4_RP43R2_WIDTH, 0x0001
        .equiv  RPOR4_RP43R2_MASK, 0x0400
        .equiv  RP43R2, 0x000A

        .equiv  RPOR4_RP43R3, 0x000B
        .equiv  RPOR4_RP43R3_WIDTH, 0x0001
        .equiv  RPOR4_RP43R3_MASK, 0x0800
        .equiv  RP43R3, 0x000B

        .equiv  RPOR4_RP43R4, 0x000C
        .equiv  RPOR4_RP43R4_WIDTH, 0x0001
        .equiv  RPOR4_RP43R4_MASK, 0x1000
        .equiv  RP43R4, 0x000C

        .equiv  RPOR4_RP43R5, 0x000D
        .equiv  RPOR4_RP43R5_WIDTH, 0x0001
        .equiv  RPOR4_RP43R5_MASK, 0x2000
        .equiv  RP43R5, 0x000D

;----- RPOR5 Bits -----------------------------------------------------
        .equiv  RPOR5_RP54R, 0x0000
        .equiv  RPOR5_RP54R_WIDTH, 0x0006
        .equiv  RPOR5_RP54R_MASK, 0x003F

        .equiv  RPOR5_RP55R, 0x0008
        .equiv  RPOR5_RP55R_WIDTH, 0x0006
        .equiv  RPOR5_RP55R_MASK, 0x3F00

        .equiv  RPOR5_RP54R0, 0x0000
        .equiv  RPOR5_RP54R0_WIDTH, 0x0001
        .equiv  RPOR5_RP54R0_MASK, 0x0001
        .equiv  RP54R0, 0x0000

        .equiv  RPOR5_RP54R1, 0x0001
        .equiv  RPOR5_RP54R1_WIDTH, 0x0001
        .equiv  RPOR5_RP54R1_MASK, 0x0002
        .equiv  RP54R1, 0x0001

        .equiv  RPOR5_RP54R2, 0x0002
        .equiv  RPOR5_RP54R2_WIDTH, 0x0001
        .equiv  RPOR5_RP54R2_MASK, 0x0004
        .equiv  RP54R2, 0x0002

        .equiv  RPOR5_RP54R3, 0x0003
        .equiv  RPOR5_RP54R3_WIDTH, 0x0001
        .equiv  RPOR5_RP54R3_MASK, 0x0008
        .equiv  RP54R3, 0x0003

        .equiv  RPOR5_RP54R4, 0x0004
        .equiv  RPOR5_RP54R4_WIDTH, 0x0001
        .equiv  RPOR5_RP54R4_MASK, 0x0010
        .equiv  RP54R4, 0x0004

        .equiv  RPOR5_RP54R5, 0x0005
        .equiv  RPOR5_RP54R5_WIDTH, 0x0001
        .equiv  RPOR5_RP54R5_MASK, 0x0020
        .equiv  RP54R5, 0x0005

        .equiv  RPOR5_RP55R0, 0x0008
        .equiv  RPOR5_RP55R0_WIDTH, 0x0001
        .equiv  RPOR5_RP55R0_MASK, 0x0100
        .equiv  RP55R0, 0x0008

        .equiv  RPOR5_RP55R1, 0x0009
        .equiv  RPOR5_RP55R1_WIDTH, 0x0001
        .equiv  RPOR5_RP55R1_MASK, 0x0200
        .equiv  RP55R1, 0x0009

        .equiv  RPOR5_RP55R2, 0x000A
        .equiv  RPOR5_RP55R2_WIDTH, 0x0001
        .equiv  RPOR5_RP55R2_MASK, 0x0400
        .equiv  RP55R2, 0x000A

        .equiv  RPOR5_RP55R3, 0x000B
        .equiv  RPOR5_RP55R3_WIDTH, 0x0001
        .equiv  RPOR5_RP55R3_MASK, 0x0800
        .equiv  RP55R3, 0x000B

        .equiv  RPOR5_RP55R4, 0x000C
        .equiv  RPOR5_RP55R4_WIDTH, 0x0001
        .equiv  RPOR5_RP55R4_MASK, 0x1000
        .equiv  RP55R4, 0x000C

        .equiv  RPOR5_RP55R5, 0x000D
        .equiv  RPOR5_RP55R5_WIDTH, 0x0001
        .equiv  RPOR5_RP55R5_MASK, 0x2000
        .equiv  RP55R5, 0x000D

;----- RPOR6 Bits -----------------------------------------------------
        .equiv  RPOR6_RP56R, 0x0000
        .equiv  RPOR6_RP56R_WIDTH, 0x0006
        .equiv  RPOR6_RP56R_MASK, 0x003F

        .equiv  RPOR6_RP57R, 0x0008
        .equiv  RPOR6_RP57R_WIDTH, 0x0006
        .equiv  RPOR6_RP57R_MASK, 0x3F00

        .equiv  RPOR6_RP56R0, 0x0000
        .equiv  RPOR6_RP56R0_WIDTH, 0x0001
        .equiv  RPOR6_RP56R0_MASK, 0x0001
        .equiv  RP56R0, 0x0000

        .equiv  RPOR6_RP56R1, 0x0001
        .equiv  RPOR6_RP56R1_WIDTH, 0x0001
        .equiv  RPOR6_RP56R1_MASK, 0x0002
        .equiv  RP56R1, 0x0001

        .equiv  RPOR6_RP56R2, 0x0002
        .equiv  RPOR6_RP56R2_WIDTH, 0x0001
        .equiv  RPOR6_RP56R2_MASK, 0x0004
        .equiv  RP56R2, 0x0002

        .equiv  RPOR6_RP56R3, 0x0003
        .equiv  RPOR6_RP56R3_WIDTH, 0x0001
        .equiv  RPOR6_RP56R3_MASK, 0x0008
        .equiv  RP56R3, 0x0003

        .equiv  RPOR6_RP56R4, 0x0004
        .equiv  RPOR6_RP56R4_WIDTH, 0x0001
        .equiv  RPOR6_RP56R4_MASK, 0x0010
        .equiv  RP56R4, 0x0004

        .equiv  RPOR6_RP56R5, 0x0005
        .equiv  RPOR6_RP56R5_WIDTH, 0x0001
        .equiv  RPOR6_RP56R5_MASK, 0x0020
        .equiv  RP56R5, 0x0005

        .equiv  RPOR6_RP57R0, 0x0008
        .equiv  RPOR6_RP57R0_WIDTH, 0x0001
        .equiv  RPOR6_RP57R0_MASK, 0x0100
        .equiv  RP57R0, 0x0008

        .equiv  RPOR6_RP57R1, 0x0009
        .equiv  RPOR6_RP57R1_WIDTH, 0x0001
        .equiv  RPOR6_RP57R1_MASK, 0x0200
        .equiv  RP57R1, 0x0009

        .equiv  RPOR6_RP57R2, 0x000A
        .equiv  RPOR6_RP57R2_WIDTH, 0x0001
        .equiv  RPOR6_RP57R2_MASK, 0x0400
        .equiv  RP57R2, 0x000A

        .equiv  RPOR6_RP57R3, 0x000B
        .equiv  RPOR6_RP57R3_WIDTH, 0x0001
        .equiv  RPOR6_RP57R3_MASK, 0x0800
        .equiv  RP57R3, 0x000B

        .equiv  RPOR6_RP57R4, 0x000C
        .equiv  RPOR6_RP57R4_WIDTH, 0x0001
        .equiv  RPOR6_RP57R4_MASK, 0x1000
        .equiv  RP57R4, 0x000C

        .equiv  RPOR6_RP57R5, 0x000D
        .equiv  RPOR6_RP57R5_WIDTH, 0x0001
        .equiv  RPOR6_RP57R5_MASK, 0x2000
        .equiv  RP57R5, 0x000D

;----- RPOR7 Bits -----------------------------------------------------
        .equiv  RPOR7_RP97R, 0x0008
        .equiv  RPOR7_RP97R_WIDTH, 0x0006
        .equiv  RPOR7_RP97R_MASK, 0x3F00

        .equiv  RPOR7_RP97R0, 0x0008
        .equiv  RPOR7_RP97R0_WIDTH, 0x0001
        .equiv  RPOR7_RP97R0_MASK, 0x0100
        .equiv  RP97R0, 0x0008

        .equiv  RPOR7_RP97R1, 0x0009
        .equiv  RPOR7_RP97R1_WIDTH, 0x0001
        .equiv  RPOR7_RP97R1_MASK, 0x0200
        .equiv  RP97R1, 0x0009

        .equiv  RPOR7_RP97R2, 0x000A
        .equiv  RPOR7_RP97R2_WIDTH, 0x0001
        .equiv  RPOR7_RP97R2_MASK, 0x0400
        .equiv  RP97R2, 0x000A

        .equiv  RPOR7_RP97R3, 0x000B
        .equiv  RPOR7_RP97R3_WIDTH, 0x0001
        .equiv  RPOR7_RP97R3_MASK, 0x0800
        .equiv  RP97R3, 0x000B

        .equiv  RPOR7_RP97R4, 0x000C
        .equiv  RPOR7_RP97R4_WIDTH, 0x0001
        .equiv  RPOR7_RP97R4_MASK, 0x1000
        .equiv  RP97R4, 0x000C

        .equiv  RPOR7_RP97R5, 0x000D
        .equiv  RPOR7_RP97R5_WIDTH, 0x0001
        .equiv  RPOR7_RP97R5_MASK, 0x2000
        .equiv  RP97R5, 0x000D

;----- RPOR8 Bits -----------------------------------------------------
        .equiv  RPOR8_RP118R, 0x0008
        .equiv  RPOR8_RP118R_WIDTH, 0x0006
        .equiv  RPOR8_RP118R_MASK, 0x3F00

        .equiv  RPOR8_RP118R0, 0x0008
        .equiv  RPOR8_RP118R0_WIDTH, 0x0001
        .equiv  RPOR8_RP118R0_MASK, 0x0100
        .equiv  RP118R0, 0x0008

        .equiv  RPOR8_RP118R1, 0x0009
        .equiv  RPOR8_RP118R1_WIDTH, 0x0001
        .equiv  RPOR8_RP118R1_MASK, 0x0200
        .equiv  RP118R1, 0x0009

        .equiv  RPOR8_RP118R2, 0x000A
        .equiv  RPOR8_RP118R2_WIDTH, 0x0001
        .equiv  RPOR8_RP118R2_MASK, 0x0400
        .equiv  RP118R2, 0x000A

        .equiv  RPOR8_RP118R3, 0x000B
        .equiv  RPOR8_RP118R3_WIDTH, 0x0001
        .equiv  RPOR8_RP118R3_MASK, 0x0800
        .equiv  RP118R3, 0x000B

        .equiv  RPOR8_RP118R4, 0x000C
        .equiv  RPOR8_RP118R4_WIDTH, 0x0001
        .equiv  RPOR8_RP118R4_MASK, 0x1000
        .equiv  RP118R4, 0x000C

        .equiv  RPOR8_RP118R5, 0x000D
        .equiv  RPOR8_RP118R5_WIDTH, 0x0001
        .equiv  RPOR8_RP118R5_MASK, 0x2000
        .equiv  RP118R5, 0x000D

;----- RPOR9 Bits -----------------------------------------------------
        .equiv  RPOR9_RP120R, 0x0000
        .equiv  RPOR9_RP120R_WIDTH, 0x0006
        .equiv  RPOR9_RP120R_MASK, 0x003F

        .equiv  RPOR9_RP120R0, 0x0000
        .equiv  RPOR9_RP120R0_WIDTH, 0x0001
        .equiv  RPOR9_RP120R0_MASK, 0x0001
        .equiv  RP120R0, 0x0000

        .equiv  RPOR9_RP120R1, 0x0001
        .equiv  RPOR9_RP120R1_WIDTH, 0x0001
        .equiv  RPOR9_RP120R1_MASK, 0x0002
        .equiv  RP120R1, 0x0001

        .equiv  RPOR9_RP120R2, 0x0002
        .equiv  RPOR9_RP120R2_WIDTH, 0x0001
        .equiv  RPOR9_RP120R2_MASK, 0x0004
        .equiv  RP120R2, 0x0002

        .equiv  RPOR9_RP120R3, 0x0003
        .equiv  RPOR9_RP120R3_WIDTH, 0x0001
        .equiv  RPOR9_RP120R3_MASK, 0x0008
        .equiv  RP120R3, 0x0003

        .equiv  RPOR9_RP120R4, 0x0004
        .equiv  RPOR9_RP120R4_WIDTH, 0x0001
        .equiv  RPOR9_RP120R4_MASK, 0x0010
        .equiv  RP120R4, 0x0004

        .equiv  RPOR9_RP120R5, 0x0005
        .equiv  RPOR9_RP120R5_WIDTH, 0x0001
        .equiv  RPOR9_RP120R5_MASK, 0x0020
        .equiv  RP120R5, 0x0005

;----- RPINR0 Bits -----------------------------------------------------
        .equiv  RPINR0_INT1R, 0x0008
        .equiv  RPINR0_INT1R_WIDTH, 0x0007
        .equiv  RPINR0_INT1R_MASK, 0x7F00

        .equiv  RPINR0_INT1R0, 0x0008
        .equiv  RPINR0_INT1R0_WIDTH, 0x0001
        .equiv  RPINR0_INT1R0_MASK, 0x0100
        .equiv  INT1R0, 0x0008

        .equiv  RPINR0_INT1R1, 0x0009
        .equiv  RPINR0_INT1R1_WIDTH, 0x0001
        .equiv  RPINR0_INT1R1_MASK, 0x0200
        .equiv  INT1R1, 0x0009

        .equiv  RPINR0_INT1R2, 0x000A
        .equiv  RPINR0_INT1R2_WIDTH, 0x0001
        .equiv  RPINR0_INT1R2_MASK, 0x0400
        .equiv  INT1R2, 0x000A

        .equiv  RPINR0_INT1R3, 0x000B
        .equiv  RPINR0_INT1R3_WIDTH, 0x0001
        .equiv  RPINR0_INT1R3_MASK, 0x0800
        .equiv  INT1R3, 0x000B

        .equiv  RPINR0_INT1R4, 0x000C
        .equiv  RPINR0_INT1R4_WIDTH, 0x0001
        .equiv  RPINR0_INT1R4_MASK, 0x1000
        .equiv  INT1R4, 0x000C

        .equiv  RPINR0_INT1R5, 0x000D
        .equiv  RPINR0_INT1R5_WIDTH, 0x0001
        .equiv  RPINR0_INT1R5_MASK, 0x2000
        .equiv  INT1R5, 0x000D

        .equiv  RPINR0_INT1R6, 0x000E
        .equiv  RPINR0_INT1R6_WIDTH, 0x0001
        .equiv  RPINR0_INT1R6_MASK, 0x4000
        .equiv  INT1R6, 0x000E

;----- RPINR1 Bits -----------------------------------------------------
        .equiv  RPINR1_INT2R, 0x0000
        .equiv  RPINR1_INT2R_WIDTH, 0x0007
        .equiv  RPINR1_INT2R_MASK, 0x007F

        .equiv  RPINR1_INT2R0, 0x0000
        .equiv  RPINR1_INT2R0_WIDTH, 0x0001
        .equiv  RPINR1_INT2R0_MASK, 0x0001
        .equiv  INT2R0, 0x0000

        .equiv  RPINR1_INT2R1, 0x0001
        .equiv  RPINR1_INT2R1_WIDTH, 0x0001
        .equiv  RPINR1_INT2R1_MASK, 0x0002
        .equiv  INT2R1, 0x0001

        .equiv  RPINR1_INT2R2, 0x0002
        .equiv  RPINR1_INT2R2_WIDTH, 0x0001
        .equiv  RPINR1_INT2R2_MASK, 0x0004
        .equiv  INT2R2, 0x0002

        .equiv  RPINR1_INT2R3, 0x0003
        .equiv  RPINR1_INT2R3_WIDTH, 0x0001
        .equiv  RPINR1_INT2R3_MASK, 0x0008
        .equiv  INT2R3, 0x0003

        .equiv  RPINR1_INT2R4, 0x0004
        .equiv  RPINR1_INT2R4_WIDTH, 0x0001
        .equiv  RPINR1_INT2R4_MASK, 0x0010
        .equiv  INT2R4, 0x0004

        .equiv  RPINR1_INT2R5, 0x0005
        .equiv  RPINR1_INT2R5_WIDTH, 0x0001
        .equiv  RPINR1_INT2R5_MASK, 0x0020
        .equiv  INT2R5, 0x0005

        .equiv  RPINR1_INT2R6, 0x0006
        .equiv  RPINR1_INT2R6_WIDTH, 0x0001
        .equiv  RPINR1_INT2R6_MASK, 0x0040
        .equiv  INT2R6, 0x0006

;----- RPINR3 Bits -----------------------------------------------------
        .equiv  RPINR3_T2CKR, 0x0000
        .equiv  RPINR3_T2CKR_WIDTH, 0x0007
        .equiv  RPINR3_T2CKR_MASK, 0x007F

        .equiv  RPINR3_T2CKR0, 0x0000
        .equiv  RPINR3_T2CKR0_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR0_MASK, 0x0001
        .equiv  T2CKR0, 0x0000

        .equiv  RPINR3_T2CKR1, 0x0001
        .equiv  RPINR3_T2CKR1_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR1_MASK, 0x0002
        .equiv  T2CKR1, 0x0001

        .equiv  RPINR3_T2CKR2, 0x0002
        .equiv  RPINR3_T2CKR2_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR2_MASK, 0x0004
        .equiv  T2CKR2, 0x0002

        .equiv  RPINR3_T2CKR3, 0x0003
        .equiv  RPINR3_T2CKR3_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR3_MASK, 0x0008
        .equiv  T2CKR3, 0x0003

        .equiv  RPINR3_T2CKR4, 0x0004
        .equiv  RPINR3_T2CKR4_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR4_MASK, 0x0010
        .equiv  T2CKR4, 0x0004

        .equiv  RPINR3_T2CKR5, 0x0005
        .equiv  RPINR3_T2CKR5_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR5_MASK, 0x0020
        .equiv  T2CKR5, 0x0005

        .equiv  RPINR3_T2CKR6, 0x0006
        .equiv  RPINR3_T2CKR6_WIDTH, 0x0001
        .equiv  RPINR3_T2CKR6_MASK, 0x0040
        .equiv  T2CKR6, 0x0006

;----- RPINR7 Bits -----------------------------------------------------
        .equiv  RPINR7_IC1R, 0x0000
        .equiv  RPINR7_IC1R_WIDTH, 0x0007
        .equiv  RPINR7_IC1R_MASK, 0x007F

        .equiv  RPINR7_IC2R, 0x0008
        .equiv  RPINR7_IC2R_WIDTH, 0x0007
        .equiv  RPINR7_IC2R_MASK, 0x7F00

        .equiv  RPINR7_IC1R0, 0x0000
        .equiv  RPINR7_IC1R0_WIDTH, 0x0001
        .equiv  RPINR7_IC1R0_MASK, 0x0001
        .equiv  IC1R0, 0x0000

        .equiv  RPINR7_IC1R1, 0x0001
        .equiv  RPINR7_IC1R1_WIDTH, 0x0001
        .equiv  RPINR7_IC1R1_MASK, 0x0002
        .equiv  IC1R1, 0x0001

        .equiv  RPINR7_IC1R2, 0x0002
        .equiv  RPINR7_IC1R2_WIDTH, 0x0001
        .equiv  RPINR7_IC1R2_MASK, 0x0004
        .equiv  IC1R2, 0x0002

        .equiv  RPINR7_IC1R3, 0x0003
        .equiv  RPINR7_IC1R3_WIDTH, 0x0001
        .equiv  RPINR7_IC1R3_MASK, 0x0008
        .equiv  IC1R3, 0x0003

        .equiv  RPINR7_IC1R4, 0x0004
        .equiv  RPINR7_IC1R4_WIDTH, 0x0001
        .equiv  RPINR7_IC1R4_MASK, 0x0010
        .equiv  IC1R4, 0x0004

        .equiv  RPINR7_IC1R5, 0x0005
        .equiv  RPINR7_IC1R5_WIDTH, 0x0001
        .equiv  RPINR7_IC1R5_MASK, 0x0020
        .equiv  IC1R5, 0x0005

        .equiv  RPINR7_IC1R6, 0x0006
        .equiv  RPINR7_IC1R6_WIDTH, 0x0001
        .equiv  RPINR7_IC1R6_MASK, 0x0040
        .equiv  IC1R6, 0x0006

        .equiv  RPINR7_IC2R0, 0x0008
        .equiv  RPINR7_IC2R0_WIDTH, 0x0001
        .equiv  RPINR7_IC2R0_MASK, 0x0100
        .equiv  IC2R0, 0x0008

        .equiv  RPINR7_IC2R1, 0x0009
        .equiv  RPINR7_IC2R1_WIDTH, 0x0001
        .equiv  RPINR7_IC2R1_MASK, 0x0200
        .equiv  IC2R1, 0x0009

        .equiv  RPINR7_IC2R2, 0x000A
        .equiv  RPINR7_IC2R2_WIDTH, 0x0001
        .equiv  RPINR7_IC2R2_MASK, 0x0400
        .equiv  IC2R2, 0x000A

        .equiv  RPINR7_IC2R3, 0x000B
        .equiv  RPINR7_IC2R3_WIDTH, 0x0001
        .equiv  RPINR7_IC2R3_MASK, 0x0800
        .equiv  IC2R3, 0x000B

        .equiv  RPINR7_IC2R4, 0x000C
        .equiv  RPINR7_IC2R4_WIDTH, 0x0001
        .equiv  RPINR7_IC2R4_MASK, 0x1000
        .equiv  IC2R4, 0x000C

        .equiv  RPINR7_IC2R5, 0x000D
        .equiv  RPINR7_IC2R5_WIDTH, 0x0001
        .equiv  RPINR7_IC2R5_MASK, 0x2000
        .equiv  IC2R5, 0x000D

        .equiv  RPINR7_IC2R6, 0x000E
        .equiv  RPINR7_IC2R6_WIDTH, 0x0001
        .equiv  RPINR7_IC2R6_MASK, 0x4000
        .equiv  IC2R6, 0x000E

;----- RPINR8 Bits -----------------------------------------------------
        .equiv  RPINR8_IC3R, 0x0000
        .equiv  RPINR8_IC3R_WIDTH, 0x0007
        .equiv  RPINR8_IC3R_MASK, 0x007F

        .equiv  RPINR8_IC4R, 0x0008
        .equiv  RPINR8_IC4R_WIDTH, 0x0007
        .equiv  RPINR8_IC4R_MASK, 0x7F00

        .equiv  RPINR8_IC3R0, 0x0000
        .equiv  RPINR8_IC3R0_WIDTH, 0x0001
        .equiv  RPINR8_IC3R0_MASK, 0x0001
        .equiv  IC3R0, 0x0000

        .equiv  RPINR8_IC3R1, 0x0001
        .equiv  RPINR8_IC3R1_WIDTH, 0x0001
        .equiv  RPINR8_IC3R1_MASK, 0x0002
        .equiv  IC3R1, 0x0001

        .equiv  RPINR8_IC3R2, 0x0002
        .equiv  RPINR8_IC3R2_WIDTH, 0x0001
        .equiv  RPINR8_IC3R2_MASK, 0x0004
        .equiv  IC3R2, 0x0002

        .equiv  RPINR8_IC3R3, 0x0003
        .equiv  RPINR8_IC3R3_WIDTH, 0x0001
        .equiv  RPINR8_IC3R3_MASK, 0x0008
        .equiv  IC3R3, 0x0003

        .equiv  RPINR8_IC3R4, 0x0004
        .equiv  RPINR8_IC3R4_WIDTH, 0x0001
        .equiv  RPINR8_IC3R4_MASK, 0x0010
        .equiv  IC3R4, 0x0004

        .equiv  RPINR8_IC3R5, 0x0005
        .equiv  RPINR8_IC3R5_WIDTH, 0x0001
        .equiv  RPINR8_IC3R5_MASK, 0x0020
        .equiv  IC3R5, 0x0005

        .equiv  RPINR8_IC3R6, 0x0006
        .equiv  RPINR8_IC3R6_WIDTH, 0x0001
        .equiv  RPINR8_IC3R6_MASK, 0x0040
        .equiv  IC3R6, 0x0006

        .equiv  RPINR8_IC4R0, 0x0008
        .equiv  RPINR8_IC4R0_WIDTH, 0x0001
        .equiv  RPINR8_IC4R0_MASK, 0x0100
        .equiv  IC4R0, 0x0008

        .equiv  RPINR8_IC4R1, 0x0009
        .equiv  RPINR8_IC4R1_WIDTH, 0x0001
        .equiv  RPINR8_IC4R1_MASK, 0x0200
        .equiv  IC4R1, 0x0009

        .equiv  RPINR8_IC4R2, 0x000A
        .equiv  RPINR8_IC4R2_WIDTH, 0x0001
        .equiv  RPINR8_IC4R2_MASK, 0x0400
        .equiv  IC4R2, 0x000A

        .equiv  RPINR8_IC4R3, 0x000B
        .equiv  RPINR8_IC4R3_WIDTH, 0x0001
        .equiv  RPINR8_IC4R3_MASK, 0x0800
        .equiv  IC4R3, 0x000B

        .equiv  RPINR8_IC4R4, 0x000C
        .equiv  RPINR8_IC4R4_WIDTH, 0x0001
        .equiv  RPINR8_IC4R4_MASK, 0x1000
        .equiv  IC4R4, 0x000C

        .equiv  RPINR8_IC4R5, 0x000D
        .equiv  RPINR8_IC4R5_WIDTH, 0x0001
        .equiv  RPINR8_IC4R5_MASK, 0x2000
        .equiv  IC4R5, 0x000D

        .equiv  RPINR8_IC4R6, 0x000E
        .equiv  RPINR8_IC4R6_WIDTH, 0x0001
        .equiv  RPINR8_IC4R6_MASK, 0x4000
        .equiv  IC4R6, 0x000E

;----- RPINR11 Bits -----------------------------------------------------
        .equiv  RPINR11_OCFAR, 0x0000
        .equiv  RPINR11_OCFAR_WIDTH, 0x0007
        .equiv  RPINR11_OCFAR_MASK, 0x007F

        .equiv  RPINR11_OCFAR0, 0x0000
        .equiv  RPINR11_OCFAR0_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR0_MASK, 0x0001
        .equiv  OCFAR0, 0x0000

        .equiv  RPINR11_OCFAR1, 0x0001
        .equiv  RPINR11_OCFAR1_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR1_MASK, 0x0002
        .equiv  OCFAR1, 0x0001

        .equiv  RPINR11_OCFAR2, 0x0002
        .equiv  RPINR11_OCFAR2_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR2_MASK, 0x0004
        .equiv  OCFAR2, 0x0002

        .equiv  RPINR11_OCFAR3, 0x0003
        .equiv  RPINR11_OCFAR3_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR3_MASK, 0x0008
        .equiv  OCFAR3, 0x0003

        .equiv  RPINR11_OCFAR4, 0x0004
        .equiv  RPINR11_OCFAR4_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR4_MASK, 0x0010
        .equiv  OCFAR4, 0x0004

        .equiv  RPINR11_OCFAR5, 0x0005
        .equiv  RPINR11_OCFAR5_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR5_MASK, 0x0020
        .equiv  OCFAR5, 0x0005

        .equiv  RPINR11_OCFAR6, 0x0006
        .equiv  RPINR11_OCFAR6_WIDTH, 0x0001
        .equiv  RPINR11_OCFAR6_MASK, 0x0040
        .equiv  OCFAR6, 0x0006

;----- RPINR12 Bits -----------------------------------------------------
        .equiv  RPINR12_FLT1R, 0x0000
        .equiv  RPINR12_FLT1R_WIDTH, 0x0007
        .equiv  RPINR12_FLT1R_MASK, 0x007F

        .equiv  RPINR12_FLT2R, 0x0008
        .equiv  RPINR12_FLT2R_WIDTH, 0x0007
        .equiv  RPINR12_FLT2R_MASK, 0x7F00

        .equiv  RPINR12_FLT1R0, 0x0000
        .equiv  RPINR12_FLT1R0_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R0_MASK, 0x0001
        .equiv  FLT1R0, 0x0000

        .equiv  RPINR12_FLT1R1, 0x0001
        .equiv  RPINR12_FLT1R1_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R1_MASK, 0x0002
        .equiv  FLT1R1, 0x0001

        .equiv  RPINR12_FLT1R2, 0x0002
        .equiv  RPINR12_FLT1R2_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R2_MASK, 0x0004
        .equiv  FLT1R2, 0x0002

        .equiv  RPINR12_FLT1R3, 0x0003
        .equiv  RPINR12_FLT1R3_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R3_MASK, 0x0008
        .equiv  FLT1R3, 0x0003

        .equiv  RPINR12_FLT1R4, 0x0004
        .equiv  RPINR12_FLT1R4_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R4_MASK, 0x0010
        .equiv  FLT1R4, 0x0004

        .equiv  RPINR12_FLT1R5, 0x0005
        .equiv  RPINR12_FLT1R5_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R5_MASK, 0x0020
        .equiv  FLT1R5, 0x0005

        .equiv  RPINR12_FLT1R6, 0x0006
        .equiv  RPINR12_FLT1R6_WIDTH, 0x0001
        .equiv  RPINR12_FLT1R6_MASK, 0x0040
        .equiv  FLT1R6, 0x0006

        .equiv  RPINR12_FLT2R0, 0x0008
        .equiv  RPINR12_FLT2R0_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R0_MASK, 0x0100
        .equiv  FLT2R0, 0x0008

        .equiv  RPINR12_FLT2R1, 0x0009
        .equiv  RPINR12_FLT2R1_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R1_MASK, 0x0200
        .equiv  FLT2R1, 0x0009

        .equiv  RPINR12_FLT2R2, 0x000A
        .equiv  RPINR12_FLT2R2_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R2_MASK, 0x0400
        .equiv  FLT2R2, 0x000A

        .equiv  RPINR12_FLT2R3, 0x000B
        .equiv  RPINR12_FLT2R3_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R3_MASK, 0x0800
        .equiv  FLT2R3, 0x000B

        .equiv  RPINR12_FLT2R4, 0x000C
        .equiv  RPINR12_FLT2R4_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R4_MASK, 0x1000
        .equiv  FLT2R4, 0x000C

        .equiv  RPINR12_FLT2R5, 0x000D
        .equiv  RPINR12_FLT2R5_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R5_MASK, 0x2000
        .equiv  FLT2R5, 0x000D

        .equiv  RPINR12_FLT2R6, 0x000E
        .equiv  RPINR12_FLT2R6_WIDTH, 0x0001
        .equiv  RPINR12_FLT2R6_MASK, 0x4000
        .equiv  FLT2R6, 0x000E

;----- RPINR14 Bits -----------------------------------------------------
        .equiv  RPINR14_QEA1R, 0x0000
        .equiv  RPINR14_QEA1R_WIDTH, 0x0007
        .equiv  RPINR14_QEA1R_MASK, 0x007F

        .equiv  RPINR14_QEB1R, 0x0008
        .equiv  RPINR14_QEB1R_WIDTH, 0x0007
        .equiv  RPINR14_QEB1R_MASK, 0x7F00

        .equiv  RPINR14_QEA1R0, 0x0000
        .equiv  RPINR14_QEA1R0_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R0_MASK, 0x0001
        .equiv  QEA1R0, 0x0000

        .equiv  RPINR14_QEA1R1, 0x0001
        .equiv  RPINR14_QEA1R1_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R1_MASK, 0x0002
        .equiv  QEA1R1, 0x0001

        .equiv  RPINR14_QEA1R2, 0x0002
        .equiv  RPINR14_QEA1R2_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R2_MASK, 0x0004
        .equiv  QEA1R2, 0x0002

        .equiv  RPINR14_QEA1R3, 0x0003
        .equiv  RPINR14_QEA1R3_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R3_MASK, 0x0008
        .equiv  QEA1R3, 0x0003

        .equiv  RPINR14_QEA1R4, 0x0004
        .equiv  RPINR14_QEA1R4_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R4_MASK, 0x0010
        .equiv  QEA1R4, 0x0004

        .equiv  RPINR14_QEA1R5, 0x0005
        .equiv  RPINR14_QEA1R5_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R5_MASK, 0x0020
        .equiv  QEA1R5, 0x0005

        .equiv  RPINR14_QEA1R6, 0x0006
        .equiv  RPINR14_QEA1R6_WIDTH, 0x0001
        .equiv  RPINR14_QEA1R6_MASK, 0x0040
        .equiv  QEA1R6, 0x0006

        .equiv  RPINR14_QEB1R0, 0x0008
        .equiv  RPINR14_QEB1R0_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R0_MASK, 0x0100
        .equiv  QEB1R0, 0x0008

        .equiv  RPINR14_QEB1R1, 0x0009
        .equiv  RPINR14_QEB1R1_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R1_MASK, 0x0200
        .equiv  QEB1R1, 0x0009

        .equiv  RPINR14_QEB1R2, 0x000A
        .equiv  RPINR14_QEB1R2_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R2_MASK, 0x0400
        .equiv  QEB1R2, 0x000A

        .equiv  RPINR14_QEB1R3, 0x000B
        .equiv  RPINR14_QEB1R3_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R3_MASK, 0x0800
        .equiv  QEB1R3, 0x000B

        .equiv  RPINR14_QEB1R4, 0x000C
        .equiv  RPINR14_QEB1R4_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R4_MASK, 0x1000
        .equiv  QEB1R4, 0x000C

        .equiv  RPINR14_QEB1R5, 0x000D
        .equiv  RPINR14_QEB1R5_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R5_MASK, 0x2000
        .equiv  QEB1R5, 0x000D

        .equiv  RPINR14_QEB1R6, 0x000E
        .equiv  RPINR14_QEB1R6_WIDTH, 0x0001
        .equiv  RPINR14_QEB1R6_MASK, 0x4000
        .equiv  QEB1R6, 0x000E

;----- RPINR15 Bits -----------------------------------------------------
        .equiv  RPINR15_INDX1R, 0x0000
        .equiv  RPINR15_INDX1R_WIDTH, 0x0007
        .equiv  RPINR15_INDX1R_MASK, 0x007F

        .equiv  RPINR15_HOME1R, 0x0008
        .equiv  RPINR15_HOME1R_WIDTH, 0x0007
        .equiv  RPINR15_HOME1R_MASK, 0x7F00

        .equiv  RPINR15_INDX1R0, 0x0000
        .equiv  RPINR15_INDX1R0_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R0_MASK, 0x0001
        .equiv  INDX1R0, 0x0000

        .equiv  RPINR15_INDX1R1, 0x0001
        .equiv  RPINR15_INDX1R1_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R1_MASK, 0x0002
        .equiv  INDX1R1, 0x0001

        .equiv  RPINR15_INDX1R2, 0x0002
        .equiv  RPINR15_INDX1R2_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R2_MASK, 0x0004
        .equiv  INDX1R2, 0x0002

        .equiv  RPINR15_INDX1R3, 0x0003
        .equiv  RPINR15_INDX1R3_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R3_MASK, 0x0008
        .equiv  INDX1R3, 0x0003

        .equiv  RPINR15_INDX1R4, 0x0004
        .equiv  RPINR15_INDX1R4_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R4_MASK, 0x0010
        .equiv  INDX1R4, 0x0004

        .equiv  RPINR15_INDX1R5, 0x0005
        .equiv  RPINR15_INDX1R5_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R5_MASK, 0x0020
        .equiv  INDX1R5, 0x0005

        .equiv  RPINR15_INDX1R6, 0x0006
        .equiv  RPINR15_INDX1R6_WIDTH, 0x0001
        .equiv  RPINR15_INDX1R6_MASK, 0x0040
        .equiv  INDX1R6, 0x0006

        .equiv  RPINR15_HOME1R0, 0x0008
        .equiv  RPINR15_HOME1R0_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R0_MASK, 0x0100
        .equiv  HOME1R0, 0x0008

        .equiv  RPINR15_HOME1R1, 0x0009
        .equiv  RPINR15_HOME1R1_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R1_MASK, 0x0200
        .equiv  HOME1R1, 0x0009

        .equiv  RPINR15_HOME1R2, 0x000A
        .equiv  RPINR15_HOME1R2_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R2_MASK, 0x0400
        .equiv  HOME1R2, 0x000A

        .equiv  RPINR15_HOME1R3, 0x000B
        .equiv  RPINR15_HOME1R3_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R3_MASK, 0x0800
        .equiv  HOME1R3, 0x000B

        .equiv  RPINR15_HOME1R4, 0x000C
        .equiv  RPINR15_HOME1R4_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R4_MASK, 0x1000
        .equiv  HOME1R4, 0x000C

        .equiv  RPINR15_HOME1R5, 0x000D
        .equiv  RPINR15_HOME1R5_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R5_MASK, 0x2000
        .equiv  HOME1R5, 0x000D

        .equiv  RPINR15_HOME1R6, 0x000E
        .equiv  RPINR15_HOME1R6_WIDTH, 0x0001
        .equiv  RPINR15_HOME1R6_MASK, 0x4000
        .equiv  HOME1R6, 0x000E

;----- RPINR18 Bits -----------------------------------------------------
        .equiv  RPINR18_U1RXR, 0x0000
        .equiv  RPINR18_U1RXR_WIDTH, 0x0007
        .equiv  RPINR18_U1RXR_MASK, 0x007F

        .equiv  RPINR18_U1RXR0, 0x0000
        .equiv  RPINR18_U1RXR0_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR0_MASK, 0x0001
        .equiv  U1RXR0, 0x0000

        .equiv  RPINR18_U1RXR1, 0x0001
        .equiv  RPINR18_U1RXR1_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR1_MASK, 0x0002
        .equiv  U1RXR1, 0x0001

        .equiv  RPINR18_U1RXR2, 0x0002
        .equiv  RPINR18_U1RXR2_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR2_MASK, 0x0004
        .equiv  U1RXR2, 0x0002

        .equiv  RPINR18_U1RXR3, 0x0003
        .equiv  RPINR18_U1RXR3_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR3_MASK, 0x0008
        .equiv  U1RXR3, 0x0003

        .equiv  RPINR18_U1RXR4, 0x0004
        .equiv  RPINR18_U1RXR4_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR4_MASK, 0x0010
        .equiv  U1RXR4, 0x0004

        .equiv  RPINR18_U1RXR5, 0x0005
        .equiv  RPINR18_U1RXR5_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR5_MASK, 0x0020
        .equiv  U1RXR5, 0x0005

        .equiv  RPINR18_U1RXR6, 0x0006
        .equiv  RPINR18_U1RXR6_WIDTH, 0x0001
        .equiv  RPINR18_U1RXR6_MASK, 0x0040
        .equiv  U1RXR6, 0x0006

;----- RPINR19 Bits -----------------------------------------------------
        .equiv  RPINR19_U2RXR, 0x0000
        .equiv  RPINR19_U2RXR_WIDTH, 0x0007
        .equiv  RPINR19_U2RXR_MASK, 0x007F

        .equiv  RPINR19_U2RXR0, 0x0000
        .equiv  RPINR19_U2RXR0_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR0_MASK, 0x0001
        .equiv  U2RXR0, 0x0000

        .equiv  RPINR19_U2RXR1, 0x0001
        .equiv  RPINR19_U2RXR1_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR1_MASK, 0x0002
        .equiv  U2RXR1, 0x0001

        .equiv  RPINR19_U2RXR2, 0x0002
        .equiv  RPINR19_U2RXR2_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR2_MASK, 0x0004
        .equiv  U2RXR2, 0x0002

        .equiv  RPINR19_U2RXR3, 0x0003
        .equiv  RPINR19_U2RXR3_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR3_MASK, 0x0008
        .equiv  U2RXR3, 0x0003

        .equiv  RPINR19_U2RXR4, 0x0004
        .equiv  RPINR19_U2RXR4_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR4_MASK, 0x0010
        .equiv  U2RXR4, 0x0004

        .equiv  RPINR19_U2RXR5, 0x0005
        .equiv  RPINR19_U2RXR5_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR5_MASK, 0x0020
        .equiv  U2RXR5, 0x0005

        .equiv  RPINR19_U2RXR6, 0x0006
        .equiv  RPINR19_U2RXR6_WIDTH, 0x0001
        .equiv  RPINR19_U2RXR6_MASK, 0x0040
        .equiv  U2RXR6, 0x0006

;----- RPINR22 Bits -----------------------------------------------------
        .equiv  RPINR22_SDI2R, 0x0000
        .equiv  RPINR22_SDI2R_WIDTH, 0x0007
        .equiv  RPINR22_SDI2R_MASK, 0x007F

        .equiv  RPINR22_SCK2INR, 0x0008
        .equiv  RPINR22_SCK2INR_WIDTH, 0x0007
        .equiv  RPINR22_SCK2INR_MASK, 0x7F00

        .equiv  RPINR22_SDI2R0, 0x0000
        .equiv  RPINR22_SDI2R0_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R0_MASK, 0x0001
        .equiv  SDI2R0, 0x0000

        .equiv  RPINR22_SDI2R1, 0x0001
        .equiv  RPINR22_SDI2R1_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R1_MASK, 0x0002
        .equiv  SDI2R1, 0x0001

        .equiv  RPINR22_SDI2R2, 0x0002
        .equiv  RPINR22_SDI2R2_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R2_MASK, 0x0004
        .equiv  SDI2R2, 0x0002

        .equiv  RPINR22_SDI2R3, 0x0003
        .equiv  RPINR22_SDI2R3_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R3_MASK, 0x0008
        .equiv  SDI2R3, 0x0003

        .equiv  RPINR22_SDI2R4, 0x0004
        .equiv  RPINR22_SDI2R4_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R4_MASK, 0x0010
        .equiv  SDI2R4, 0x0004

        .equiv  RPINR22_SDI2R5, 0x0005
        .equiv  RPINR22_SDI2R5_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R5_MASK, 0x0020
        .equiv  SDI2R5, 0x0005

        .equiv  RPINR22_SDI2R6, 0x0006
        .equiv  RPINR22_SDI2R6_WIDTH, 0x0001
        .equiv  RPINR22_SDI2R6_MASK, 0x0040
        .equiv  SDI2R6, 0x0006

        .equiv  RPINR22_SCK2INR0, 0x0008
        .equiv  RPINR22_SCK2INR0_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR0_MASK, 0x0100
        .equiv  SCK2INR0, 0x0008

        .equiv  RPINR22_SCK2INR1, 0x0009
        .equiv  RPINR22_SCK2INR1_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR1_MASK, 0x0200
        .equiv  SCK2INR1, 0x0009

        .equiv  RPINR22_SCK2INR2, 0x000A
        .equiv  RPINR22_SCK2INR2_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR2_MASK, 0x0400
        .equiv  SCK2INR2, 0x000A

        .equiv  RPINR22_SCK2INR3, 0x000B
        .equiv  RPINR22_SCK2INR3_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR3_MASK, 0x0800
        .equiv  SCK2INR3, 0x000B

        .equiv  RPINR22_SCK2INR4, 0x000C
        .equiv  RPINR22_SCK2INR4_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR4_MASK, 0x1000
        .equiv  SCK2INR4, 0x000C

        .equiv  RPINR22_SCK2INR5, 0x000D
        .equiv  RPINR22_SCK2INR5_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR5_MASK, 0x2000
        .equiv  SCK2INR5, 0x000D

        .equiv  RPINR22_SCK2INR6, 0x000E
        .equiv  RPINR22_SCK2INR6_WIDTH, 0x0001
        .equiv  RPINR22_SCK2INR6_MASK, 0x4000
        .equiv  SCK2INR6, 0x000E

;----- RPINR23 Bits -----------------------------------------------------
        .equiv  RPINR23_SS2R, 0x0000
        .equiv  RPINR23_SS2R_WIDTH, 0x0007
        .equiv  RPINR23_SS2R_MASK, 0x007F

        .equiv  RPINR23_SS2R0, 0x0000
        .equiv  RPINR23_SS2R0_WIDTH, 0x0001
        .equiv  RPINR23_SS2R0_MASK, 0x0001
        .equiv  SS2R0, 0x0000

        .equiv  RPINR23_SS2R1, 0x0001
        .equiv  RPINR23_SS2R1_WIDTH, 0x0001
        .equiv  RPINR23_SS2R1_MASK, 0x0002
        .equiv  SS2R1, 0x0001

        .equiv  RPINR23_SS2R2, 0x0002
        .equiv  RPINR23_SS2R2_WIDTH, 0x0001
        .equiv  RPINR23_SS2R2_MASK, 0x0004
        .equiv  SS2R2, 0x0002

        .equiv  RPINR23_SS2R3, 0x0003
        .equiv  RPINR23_SS2R3_WIDTH, 0x0001
        .equiv  RPINR23_SS2R3_MASK, 0x0008
        .equiv  SS2R3, 0x0003

        .equiv  RPINR23_SS2R4, 0x0004
        .equiv  RPINR23_SS2R4_WIDTH, 0x0001
        .equiv  RPINR23_SS2R4_MASK, 0x0010
        .equiv  SS2R4, 0x0004

        .equiv  RPINR23_SS2R5, 0x0005
        .equiv  RPINR23_SS2R5_WIDTH, 0x0001
        .equiv  RPINR23_SS2R5_MASK, 0x0020
        .equiv  SS2R5, 0x0005

        .equiv  RPINR23_SS2R6, 0x0006
        .equiv  RPINR23_SS2R6_WIDTH, 0x0001
        .equiv  RPINR23_SS2R6_MASK, 0x0040
        .equiv  SS2R6, 0x0006

;----- RPINR26 Bits -----------------------------------------------------
        .equiv  RPINR26_C1RXR, 0x0000
        .equiv  RPINR26_C1RXR_WIDTH, 0x0007
        .equiv  RPINR26_C1RXR_MASK, 0x007F

        .equiv  RPINR26_C1RXR0, 0x0000
        .equiv  RPINR26_C1RXR0_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR0_MASK, 0x0001
        .equiv  C1RXR0, 0x0000

        .equiv  RPINR26_C1RXR1, 0x0001
        .equiv  RPINR26_C1RXR1_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR1_MASK, 0x0002
        .equiv  C1RXR1, 0x0001

        .equiv  RPINR26_C1RXR2, 0x0002
        .equiv  RPINR26_C1RXR2_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR2_MASK, 0x0004
        .equiv  C1RXR2, 0x0002

        .equiv  RPINR26_C1RXR3, 0x0003
        .equiv  RPINR26_C1RXR3_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR3_MASK, 0x0008
        .equiv  C1RXR3, 0x0003

        .equiv  RPINR26_C1RXR4, 0x0004
        .equiv  RPINR26_C1RXR4_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR4_MASK, 0x0010
        .equiv  C1RXR4, 0x0004

        .equiv  RPINR26_C1RXR5, 0x0005
        .equiv  RPINR26_C1RXR5_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR5_MASK, 0x0020
        .equiv  C1RXR5, 0x0005

        .equiv  RPINR26_C1RXR6, 0x0006
        .equiv  RPINR26_C1RXR6_WIDTH, 0x0001
        .equiv  RPINR26_C1RXR6_MASK, 0x0040
        .equiv  C1RXR6, 0x0006

;----- RPINR37 Bits -----------------------------------------------------
        .equiv  RPINR37_SYNCI1R, 0x0008
        .equiv  RPINR37_SYNCI1R_WIDTH, 0x0007
        .equiv  RPINR37_SYNCI1R_MASK, 0x7F00

        .equiv  RPINR37_SYNCI1R0, 0x0008
        .equiv  RPINR37_SYNCI1R0_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R0_MASK, 0x0100
        .equiv  SYNCI1R0, 0x0008

        .equiv  RPINR37_SYNCI1R1, 0x0009
        .equiv  RPINR37_SYNCI1R1_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R1_MASK, 0x0200
        .equiv  SYNCI1R1, 0x0009

        .equiv  RPINR37_SYNCI1R2, 0x000A
        .equiv  RPINR37_SYNCI1R2_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R2_MASK, 0x0400
        .equiv  SYNCI1R2, 0x000A

        .equiv  RPINR37_SYNCI1R3, 0x000B
        .equiv  RPINR37_SYNCI1R3_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R3_MASK, 0x0800
        .equiv  SYNCI1R3, 0x000B

        .equiv  RPINR37_SYNCI1R4, 0x000C
        .equiv  RPINR37_SYNCI1R4_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R4_MASK, 0x1000
        .equiv  SYNCI1R4, 0x000C

        .equiv  RPINR37_SYNCI1R5, 0x000D
        .equiv  RPINR37_SYNCI1R5_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R5_MASK, 0x2000
        .equiv  SYNCI1R5, 0x000D

        .equiv  RPINR37_SYNCI1R6, 0x000E
        .equiv  RPINR37_SYNCI1R6_WIDTH, 0x0001
        .equiv  RPINR37_SYNCI1R6_MASK, 0x4000
        .equiv  SYNCI1R6, 0x000E

;----- RPINR38 Bits -----------------------------------------------------
        .equiv  RPINR38_DTCMP1R, 0x0008
        .equiv  RPINR38_DTCMP1R_WIDTH, 0x0007
        .equiv  RPINR38_DTCMP1R_MASK, 0x7F00

        .equiv  RPINR38_DTCMP1R0, 0x0008
        .equiv  RPINR38_DTCMP1R0_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R0_MASK, 0x0100
        .equiv  DTCMP1R0, 0x0008

        .equiv  RPINR38_DTCMP1R1, 0x0009
        .equiv  RPINR38_DTCMP1R1_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R1_MASK, 0x0200
        .equiv  DTCMP1R1, 0x0009

        .equiv  RPINR38_DTCMP1R2, 0x000A
        .equiv  RPINR38_DTCMP1R2_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R2_MASK, 0x0400
        .equiv  DTCMP1R2, 0x000A

        .equiv  RPINR38_DTCMP1R3, 0x000B
        .equiv  RPINR38_DTCMP1R3_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R3_MASK, 0x0800
        .equiv  DTCMP1R3, 0x000B

        .equiv  RPINR38_DTCMP1R4, 0x000C
        .equiv  RPINR38_DTCMP1R4_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R4_MASK, 0x1000
        .equiv  DTCMP1R4, 0x000C

        .equiv  RPINR38_DTCMP1R5, 0x000D
        .equiv  RPINR38_DTCMP1R5_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R5_MASK, 0x2000
        .equiv  DTCMP1R5, 0x000D

        .equiv  RPINR38_DTCMP1R6, 0x000E
        .equiv  RPINR38_DTCMP1R6_WIDTH, 0x0001
        .equiv  RPINR38_DTCMP1R6_MASK, 0x4000
        .equiv  DTCMP1R6, 0x000E

;----- RPINR39 Bits -----------------------------------------------------
        .equiv  RPINR39_DTCMP2R, 0x0000
        .equiv  RPINR39_DTCMP2R_WIDTH, 0x0007
        .equiv  RPINR39_DTCMP2R_MASK, 0x007F

        .equiv  RPINR39_DTCMP3R, 0x0008
        .equiv  RPINR39_DTCMP3R_WIDTH, 0x0007
        .equiv  RPINR39_DTCMP3R_MASK, 0x7F00

        .equiv  RPINR39_DTCMP2R0, 0x0000
        .equiv  RPINR39_DTCMP2R0_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R0_MASK, 0x0001
        .equiv  DTCMP2R0, 0x0000

        .equiv  RPINR39_DTCMP2R1, 0x0001
        .equiv  RPINR39_DTCMP2R1_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R1_MASK, 0x0002
        .equiv  DTCMP2R1, 0x0001

        .equiv  RPINR39_DTCMP2R2, 0x0002
        .equiv  RPINR39_DTCMP2R2_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R2_MASK, 0x0004
        .equiv  DTCMP2R2, 0x0002

        .equiv  RPINR39_DTCMP2R3, 0x0003
        .equiv  RPINR39_DTCMP2R3_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R3_MASK, 0x0008
        .equiv  DTCMP2R3, 0x0003

        .equiv  RPINR39_DTCMP2R4, 0x0004
        .equiv  RPINR39_DTCMP2R4_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R4_MASK, 0x0010
        .equiv  DTCMP2R4, 0x0004

        .equiv  RPINR39_DTCMP2R5, 0x0005
        .equiv  RPINR39_DTCMP2R5_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R5_MASK, 0x0020
        .equiv  DTCMP2R5, 0x0005

        .equiv  RPINR39_DTCMP2R6, 0x0006
        .equiv  RPINR39_DTCMP2R6_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP2R6_MASK, 0x0040
        .equiv  DTCMP2R6, 0x0006

        .equiv  RPINR39_DTCMP3R0, 0x0008
        .equiv  RPINR39_DTCMP3R0_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R0_MASK, 0x0100
        .equiv  DTCMP3R0, 0x0008

        .equiv  RPINR39_DTCMP3R1, 0x0009
        .equiv  RPINR39_DTCMP3R1_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R1_MASK, 0x0200
        .equiv  DTCMP3R1, 0x0009

        .equiv  RPINR39_DTCMP3R2, 0x000A
        .equiv  RPINR39_DTCMP3R2_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R2_MASK, 0x0400
        .equiv  DTCMP3R2, 0x000A

        .equiv  RPINR39_DTCMP3R3, 0x000B
        .equiv  RPINR39_DTCMP3R3_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R3_MASK, 0x0800
        .equiv  DTCMP3R3, 0x000B

        .equiv  RPINR39_DTCMP3R4, 0x000C
        .equiv  RPINR39_DTCMP3R4_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R4_MASK, 0x1000
        .equiv  DTCMP3R4, 0x000C

        .equiv  RPINR39_DTCMP3R5, 0x000D
        .equiv  RPINR39_DTCMP3R5_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R5_MASK, 0x2000
        .equiv  DTCMP3R5, 0x000D

        .equiv  RPINR39_DTCMP3R6, 0x000E
        .equiv  RPINR39_DTCMP3R6_WIDTH, 0x0001
        .equiv  RPINR39_DTCMP3R6_MASK, 0x4000
        .equiv  DTCMP3R6, 0x000E

;----- NVMCON Bits -----------------------------------------------------
        .equiv  NVMCON_NVMOP, 0x0000
        .equiv  NVMCON_NVMOP_WIDTH, 0x0004
        .equiv  NVMCON_NVMOP_MASK, 0x000F

        .equiv  NVMCON_NVMSIDL, 0x000C
        .equiv  NVMCON_NVMSIDL_WIDTH, 0x0001
        .equiv  NVMCON_NVMSIDL_MASK, 0x1000
        .equiv  NVMSIDL, 0x000C

        .equiv  NVMCON_WRERR, 0x000D
        .equiv  NVMCON_WRERR_WIDTH, 0x0001
        .equiv  NVMCON_WRERR_MASK, 0x2000
        .equiv  WRERR, 0x000D

        .equiv  NVMCON_WREN, 0x000E
        .equiv  NVMCON_WREN_WIDTH, 0x0001
        .equiv  NVMCON_WREN_MASK, 0x4000
        .equiv  WREN, 0x000E

        .equiv  NVMCON_WR, 0x000F
        .equiv  NVMCON_WR_WIDTH, 0x0001
        .equiv  NVMCON_WR_MASK, 0x8000
        .equiv  WR, 0x000F

        .equiv  NVMCON_NVMOP0, 0x0000
        .equiv  NVMCON_NVMOP0_WIDTH, 0x0001
        .equiv  NVMCON_NVMOP0_MASK, 0x0001
        .equiv  NVMOP0, 0x0000

        .equiv  NVMCON_NVMOP1, 0x0001
        .equiv  NVMCON_NVMOP1_WIDTH, 0x0001
        .equiv  NVMCON_NVMOP1_MASK, 0x0002
        .equiv  NVMOP1, 0x0001

        .equiv  NVMCON_NVMOP2, 0x0002
        .equiv  NVMCON_NVMOP2_WIDTH, 0x0001
        .equiv  NVMCON_NVMOP2_MASK, 0x0004
        .equiv  NVMOP2, 0x0002

        .equiv  NVMCON_NVMOP3, 0x0003
        .equiv  NVMCON_NVMOP3_WIDTH, 0x0001
        .equiv  NVMCON_NVMOP3_MASK, 0x0008
        .equiv  NVMOP3, 0x0003

;----- NVMADRU Bits -----------------------------------------------------
        .equiv  NVMADRU, 0x0000
        .equiv  NVMADRU_WIDTH, 0x0008
        .equiv  NVMADRU_MASK, 0x00FF

;----- RCON Bits -----------------------------------------------------
        .equiv  RCON_POR, 0x0000
        .equiv  RCON_POR_WIDTH, 0x0001
        .equiv  RCON_POR_MASK, 0x0001
        .equiv  POR, 0x0000

        .equiv  RCON_BOR, 0x0001
        .equiv  RCON_BOR_WIDTH, 0x0001
        .equiv  RCON_BOR_MASK, 0x0002
        .equiv  BOR, 0x0001

        .equiv  RCON_IDLE, 0x0002
        .equiv  RCON_IDLE_WIDTH, 0x0001
        .equiv  RCON_IDLE_MASK, 0x0004
        .equiv  IDLE, 0x0002

        .equiv  RCON_SLEEP, 0x0003
        .equiv  RCON_SLEEP_WIDTH, 0x0001
        .equiv  RCON_SLEEP_MASK, 0x0008
        .equiv  SLEEP, 0x0003

        .equiv  RCON_WDTO, 0x0004
        .equiv  RCON_WDTO_WIDTH, 0x0001
        .equiv  RCON_WDTO_MASK, 0x0010
        .equiv  WDTO, 0x0004

        .equiv  RCON_SWDTEN, 0x0005
        .equiv  RCON_SWDTEN_WIDTH, 0x0001
        .equiv  RCON_SWDTEN_MASK, 0x0020
        .equiv  SWDTEN, 0x0005

        .equiv  RCON_SWR, 0x0006
        .equiv  RCON_SWR_WIDTH, 0x0001
        .equiv  RCON_SWR_MASK, 0x0040
        .equiv  SWR, 0x0006

        .equiv  RCON_EXTR, 0x0007
        .equiv  RCON_EXTR_WIDTH, 0x0001
        .equiv  RCON_EXTR_MASK, 0x0080
        .equiv  EXTR, 0x0007

        .equiv  RCON_VREGS, 0x0008
        .equiv  RCON_VREGS_WIDTH, 0x0001
        .equiv  RCON_VREGS_MASK, 0x0100
        .equiv  VREGS, 0x0008

        .equiv  RCON_CM, 0x0009
        .equiv  RCON_CM_WIDTH, 0x0001
        .equiv  RCON_CM_MASK, 0x0200
        .equiv  CM, 0x0009

        .equiv  RCON_VREGSF, 0x000B
        .equiv  RCON_VREGSF_WIDTH, 0x0001
        .equiv  RCON_VREGSF_MASK, 0x0800
        .equiv  VREGSF, 0x000B

        .equiv  RCON_IOPUWR, 0x000E
        .equiv  RCON_IOPUWR_WIDTH, 0x0001
        .equiv  RCON_IOPUWR_MASK, 0x4000
        .equiv  IOPUWR, 0x000E

        .equiv  RCON_TRAPR, 0x000F
        .equiv  RCON_TRAPR_WIDTH, 0x0001
        .equiv  RCON_TRAPR_MASK, 0x8000
        .equiv  TRAPR, 0x000F

;----- OSCCON Bits -----------------------------------------------------
        .equiv  OSCCON_OSWEN, 0x0000
        .equiv  OSCCON_OSWEN_WIDTH, 0x0001
        .equiv  OSCCON_OSWEN_MASK, 0x0001
        .equiv  OSWEN, 0x0000

        .equiv  OSCCON_CF, 0x0003
        .equiv  OSCCON_CF_WIDTH, 0x0001
        .equiv  OSCCON_CF_MASK, 0x0008
        .equiv  CF, 0x0003

        .equiv  OSCCON_LOCK, 0x0005
        .equiv  OSCCON_LOCK_WIDTH, 0x0001
        .equiv  OSCCON_LOCK_MASK, 0x0020
        .equiv  LOCK, 0x0005

        .equiv  OSCCON_IOLOCK, 0x0006
        .equiv  OSCCON_IOLOCK_WIDTH, 0x0001
        .equiv  OSCCON_IOLOCK_MASK, 0x0040
        .equiv  IOLOCK, 0x0006

        .equiv  OSCCON_CLKLOCK, 0x0007
        .equiv  OSCCON_CLKLOCK_WIDTH, 0x0001
        .equiv  OSCCON_CLKLOCK_MASK, 0x0080
        .equiv  CLKLOCK, 0x0007

        .equiv  OSCCON_NOSC, 0x0008
        .equiv  OSCCON_NOSC_WIDTH, 0x0003
        .equiv  OSCCON_NOSC_MASK, 0x0700

        .equiv  OSCCON_COSC, 0x000C
        .equiv  OSCCON_COSC_WIDTH, 0x0003
        .equiv  OSCCON_COSC_MASK, 0x7000

        .equiv  OSCCON_NOSC0, 0x0008
        .equiv  OSCCON_NOSC0_WIDTH, 0x0001
        .equiv  OSCCON_NOSC0_MASK, 0x0100
        .equiv  NOSC0, 0x0008

        .equiv  OSCCON_NOSC1, 0x0009
        .equiv  OSCCON_NOSC1_WIDTH, 0x0001
        .equiv  OSCCON_NOSC1_MASK, 0x0200
        .equiv  NOSC1, 0x0009

        .equiv  OSCCON_NOSC2, 0x000A
        .equiv  OSCCON_NOSC2_WIDTH, 0x0001
        .equiv  OSCCON_NOSC2_MASK, 0x0400
        .equiv  NOSC2, 0x000A

        .equiv  OSCCON_COSC0, 0x000C
        .equiv  OSCCON_COSC0_WIDTH, 0x0001
        .equiv  OSCCON_COSC0_MASK, 0x1000
        .equiv  COSC0, 0x000C

        .equiv  OSCCON_COSC1, 0x000D
        .equiv  OSCCON_COSC1_WIDTH, 0x0001
        .equiv  OSCCON_COSC1_MASK, 0x2000
        .equiv  COSC1, 0x000D

        .equiv  OSCCON_COSC2, 0x000E
        .equiv  OSCCON_COSC2_WIDTH, 0x0001
        .equiv  OSCCON_COSC2_MASK, 0x4000
        .equiv  COSC2, 0x000E

;----- CLKDIV Bits -----------------------------------------------------
        .equiv  CLKDIV_PLLPRE, 0x0000
        .equiv  CLKDIV_PLLPRE_WIDTH, 0x0005
        .equiv  CLKDIV_PLLPRE_MASK, 0x001F

        .equiv  CLKDIV_PLLPOST, 0x0006
        .equiv  CLKDIV_PLLPOST_WIDTH, 0x0002
        .equiv  CLKDIV_PLLPOST_MASK, 0x00C0

        .equiv  CLKDIV_FRCDIV, 0x0008
        .equiv  CLKDIV_FRCDIV_WIDTH, 0x0003
        .equiv  CLKDIV_FRCDIV_MASK, 0x0700

        .equiv  CLKDIV_DOZEN, 0x000B
        .equiv  CLKDIV_DOZEN_WIDTH, 0x0001
        .equiv  CLKDIV_DOZEN_MASK, 0x0800
        .equiv  DOZEN, 0x000B

        .equiv  CLKDIV_DOZE, 0x000C
        .equiv  CLKDIV_DOZE_WIDTH, 0x0003
        .equiv  CLKDIV_DOZE_MASK, 0x7000

        .equiv  CLKDIV_ROI, 0x000F
        .equiv  CLKDIV_ROI_WIDTH, 0x0001
        .equiv  CLKDIV_ROI_MASK, 0x8000
        .equiv  ROI, 0x000F

        .equiv  CLKDIV_PLLPRE0, 0x0000
        .equiv  CLKDIV_PLLPRE0_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPRE0_MASK, 0x0001
        .equiv  PLLPRE0, 0x0000

        .equiv  CLKDIV_PLLPRE1, 0x0001
        .equiv  CLKDIV_PLLPRE1_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPRE1_MASK, 0x0002
        .equiv  PLLPRE1, 0x0001

        .equiv  CLKDIV_PLLPRE2, 0x0002
        .equiv  CLKDIV_PLLPRE2_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPRE2_MASK, 0x0004
        .equiv  PLLPRE2, 0x0002

        .equiv  CLKDIV_PLLPRE3, 0x0003
        .equiv  CLKDIV_PLLPRE3_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPRE3_MASK, 0x0008
        .equiv  PLLPRE3, 0x0003

        .equiv  CLKDIV_PLLPRE4, 0x0004
        .equiv  CLKDIV_PLLPRE4_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPRE4_MASK, 0x0010
        .equiv  PLLPRE4, 0x0004

        .equiv  CLKDIV_PLLPOST0, 0x0006
        .equiv  CLKDIV_PLLPOST0_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPOST0_MASK, 0x0040
        .equiv  PLLPOST0, 0x0006

        .equiv  CLKDIV_PLLPOST1, 0x0007
        .equiv  CLKDIV_PLLPOST1_WIDTH, 0x0001
        .equiv  CLKDIV_PLLPOST1_MASK, 0x0080
        .equiv  PLLPOST1, 0x0007

        .equiv  CLKDIV_FRCDIV0, 0x0008
        .equiv  CLKDIV_FRCDIV0_WIDTH, 0x0001
        .equiv  CLKDIV_FRCDIV0_MASK, 0x0100
        .equiv  FRCDIV0, 0x0008

        .equiv  CLKDIV_FRCDIV1, 0x0009
        .equiv  CLKDIV_FRCDIV1_WIDTH, 0x0001
        .equiv  CLKDIV_FRCDIV1_MASK, 0x0200
        .equiv  FRCDIV1, 0x0009

        .equiv  CLKDIV_FRCDIV2, 0x000A
        .equiv  CLKDIV_FRCDIV2_WIDTH, 0x0001
        .equiv  CLKDIV_FRCDIV2_MASK, 0x0400
        .equiv  FRCDIV2, 0x000A

        .equiv  CLKDIV_DOZE0, 0x000C
        .equiv  CLKDIV_DOZE0_WIDTH, 0x0001
        .equiv  CLKDIV_DOZE0_MASK, 0x1000
        .equiv  DOZE0, 0x000C

        .equiv  CLKDIV_DOZE1, 0x000D
        .equiv  CLKDIV_DOZE1_WIDTH, 0x0001
        .equiv  CLKDIV_DOZE1_MASK, 0x2000
        .equiv  DOZE1, 0x000D

        .equiv  CLKDIV_DOZE2, 0x000E
        .equiv  CLKDIV_DOZE2_WIDTH, 0x0001
        .equiv  CLKDIV_DOZE2_MASK, 0x4000
        .equiv  DOZE2, 0x000E

;----- PLLFBD Bits -----------------------------------------------------
        .equiv  PLLFBD_PLLDIV, 0x0000
        .equiv  PLLFBD_PLLDIV_WIDTH, 0x0009
        .equiv  PLLFBD_PLLDIV_MASK, 0x01FF

        .equiv  PLLFBD_PLLDIV0, 0x0000
        .equiv  PLLFBD_PLLDIV0_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV0_MASK, 0x0001
        .equiv  PLLDIV0, 0x0000

        .equiv  PLLFBD_PLLDIV1, 0x0001
        .equiv  PLLFBD_PLLDIV1_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV1_MASK, 0x0002
        .equiv  PLLDIV1, 0x0001

        .equiv  PLLFBD_PLLDIV2, 0x0002
        .equiv  PLLFBD_PLLDIV2_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV2_MASK, 0x0004
        .equiv  PLLDIV2, 0x0002

        .equiv  PLLFBD_PLLDIV3, 0x0003
        .equiv  PLLFBD_PLLDIV3_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV3_MASK, 0x0008
        .equiv  PLLDIV3, 0x0003

        .equiv  PLLFBD_PLLDIV4, 0x0004
        .equiv  PLLFBD_PLLDIV4_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV4_MASK, 0x0010
        .equiv  PLLDIV4, 0x0004

        .equiv  PLLFBD_PLLDIV5, 0x0005
        .equiv  PLLFBD_PLLDIV5_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV5_MASK, 0x0020
        .equiv  PLLDIV5, 0x0005

        .equiv  PLLFBD_PLLDIV6, 0x0006
        .equiv  PLLFBD_PLLDIV6_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV6_MASK, 0x0040
        .equiv  PLLDIV6, 0x0006

        .equiv  PLLFBD_PLLDIV7, 0x0007
        .equiv  PLLFBD_PLLDIV7_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV7_MASK, 0x0080
        .equiv  PLLDIV7, 0x0007

        .equiv  PLLFBD_PLLDIV8, 0x0008
        .equiv  PLLFBD_PLLDIV8_WIDTH, 0x0001
        .equiv  PLLFBD_PLLDIV8_MASK, 0x0100
        .equiv  PLLDIV8, 0x0008

;----- OSCTUN Bits -----------------------------------------------------
        .equiv  OSCTUN_TUN, 0x0000
        .equiv  OSCTUN_TUN_WIDTH, 0x0006
        .equiv  OSCTUN_TUN_MASK, 0x003F

        .equiv  OSCTUN_TUN0, 0x0000
        .equiv  OSCTUN_TUN0_WIDTH, 0x0001
        .equiv  OSCTUN_TUN0_MASK, 0x0001
        .equiv  TUN0, 0x0000

        .equiv  OSCTUN_TUN1, 0x0001
        .equiv  OSCTUN_TUN1_WIDTH, 0x0001
        .equiv  OSCTUN_TUN1_MASK, 0x0002
        .equiv  TUN1, 0x0001

        .equiv  OSCTUN_TUN2, 0x0002
        .equiv  OSCTUN_TUN2_WIDTH, 0x0001
        .equiv  OSCTUN_TUN2_MASK, 0x0004
        .equiv  TUN2, 0x0002

        .equiv  OSCTUN_TUN3, 0x0003
        .equiv  OSCTUN_TUN3_WIDTH, 0x0001
        .equiv  OSCTUN_TUN3_MASK, 0x0008
        .equiv  TUN3, 0x0003

        .equiv  OSCTUN_TUN4, 0x0004
        .equiv  OSCTUN_TUN4_WIDTH, 0x0001
        .equiv  OSCTUN_TUN4_MASK, 0x0010
        .equiv  TUN4, 0x0004

        .equiv  OSCTUN_TUN5, 0x0005
        .equiv  OSCTUN_TUN5_WIDTH, 0x0001
        .equiv  OSCTUN_TUN5_MASK, 0x0020
        .equiv  TUN5, 0x0005

;----- REFOCON Bits -----------------------------------------------------
        .equiv  REFOCON_RODIV, 0x0008
        .equiv  REFOCON_RODIV_WIDTH, 0x0004
        .equiv  REFOCON_RODIV_MASK, 0x0F00

        .equiv  REFOCON_ROSEL, 0x000C
        .equiv  REFOCON_ROSEL_WIDTH, 0x0001
        .equiv  REFOCON_ROSEL_MASK, 0x1000
        .equiv  ROSEL, 0x000C

        .equiv  REFOCON_ROSSLP, 0x000D
        .equiv  REFOCON_ROSSLP_WIDTH, 0x0001
        .equiv  REFOCON_ROSSLP_MASK, 0x2000
        .equiv  ROSSLP, 0x000D

        .equiv  REFOCON_ROON, 0x000F
        .equiv  REFOCON_ROON_WIDTH, 0x0001
        .equiv  REFOCON_ROON_MASK, 0x8000
        .equiv  ROON, 0x000F

        .equiv  REFOCON_RODIV0, 0x0008
        .equiv  REFOCON_RODIV0_WIDTH, 0x0001
        .equiv  REFOCON_RODIV0_MASK, 0x0100
        .equiv  RODIV0, 0x0008

        .equiv  REFOCON_RODIV1, 0x0009
        .equiv  REFOCON_RODIV1_WIDTH, 0x0001
        .equiv  REFOCON_RODIV1_MASK, 0x0200
        .equiv  RODIV1, 0x0009

        .equiv  REFOCON_RODIV2, 0x000A
        .equiv  REFOCON_RODIV2_WIDTH, 0x0001
        .equiv  REFOCON_RODIV2_MASK, 0x0400
        .equiv  RODIV2, 0x000A

        .equiv  REFOCON_RODIV3, 0x000B
        .equiv  REFOCON_RODIV3_WIDTH, 0x0001
        .equiv  REFOCON_RODIV3_MASK, 0x0800
        .equiv  RODIV3, 0x000B

;----- PMD1 Bits -----------------------------------------------------
        .equiv  PMD1_AD1MD, 0x0000
        .equiv  PMD1_AD1MD_WIDTH, 0x0001
        .equiv  PMD1_AD1MD_MASK, 0x0001
        .equiv  AD1MD, 0x0000

        .equiv  PMD1_C1MD, 0x0001
        .equiv  PMD1_C1MD_WIDTH, 0x0001
        .equiv  PMD1_C1MD_MASK, 0x0002
        .equiv  C1MD, 0x0001

        .equiv  PMD1_SPI1MD, 0x0003
        .equiv  PMD1_SPI1MD_WIDTH, 0x0001
        .equiv  PMD1_SPI1MD_MASK, 0x0008
        .equiv  SPI1MD, 0x0003

        .equiv  PMD1_SPI2MD, 0x0004
        .equiv  PMD1_SPI2MD_WIDTH, 0x0001
        .equiv  PMD1_SPI2MD_MASK, 0x0010
        .equiv  SPI2MD, 0x0004

        .equiv  PMD1_U1MD, 0x0005
        .equiv  PMD1_U1MD_WIDTH, 0x0001
        .equiv  PMD1_U1MD_MASK, 0x0020
        .equiv  U1MD, 0x0005

        .equiv  PMD1_U2MD, 0x0006
        .equiv  PMD1_U2MD_WIDTH, 0x0001
        .equiv  PMD1_U2MD_MASK, 0x0040
        .equiv  U2MD, 0x0006

        .equiv  PMD1_I2C1MD, 0x0007
        .equiv  PMD1_I2C1MD_WIDTH, 0x0001
        .equiv  PMD1_I2C1MD_MASK, 0x0080
        .equiv  I2C1MD, 0x0007

        .equiv  PMD1_PWMMD, 0x0009
        .equiv  PMD1_PWMMD_WIDTH, 0x0001
        .equiv  PMD1_PWMMD_MASK, 0x0200
        .equiv  PWMMD, 0x0009

        .equiv  PMD1_QEI1MD, 0x000A
        .equiv  PMD1_QEI1MD_WIDTH, 0x0001
        .equiv  PMD1_QEI1MD_MASK, 0x0400
        .equiv  QEI1MD, 0x000A

        .equiv  PMD1_T1MD, 0x000B
        .equiv  PMD1_T1MD_WIDTH, 0x0001
        .equiv  PMD1_T1MD_MASK, 0x0800
        .equiv  T1MD, 0x000B

        .equiv  PMD1_T2MD, 0x000C
        .equiv  PMD1_T2MD_WIDTH, 0x0001
        .equiv  PMD1_T2MD_MASK, 0x1000
        .equiv  T2MD, 0x000C

        .equiv  PMD1_T3MD, 0x000D
        .equiv  PMD1_T3MD_WIDTH, 0x0001
        .equiv  PMD1_T3MD_MASK, 0x2000
        .equiv  T3MD, 0x000D

        .equiv  PMD1_T4MD, 0x000E
        .equiv  PMD1_T4MD_WIDTH, 0x0001
        .equiv  PMD1_T4MD_MASK, 0x4000
        .equiv  T4MD, 0x000E

        .equiv  PMD1_T5MD, 0x000F
        .equiv  PMD1_T5MD_WIDTH, 0x0001
        .equiv  PMD1_T5MD_MASK, 0x8000
        .equiv  T5MD, 0x000F

;----- PMD2 Bits -----------------------------------------------------
        .equiv  PMD2_OC1MD, 0x0000
        .equiv  PMD2_OC1MD_WIDTH, 0x0001
        .equiv  PMD2_OC1MD_MASK, 0x0001
        .equiv  OC1MD, 0x0000

        .equiv  PMD2_OC2MD, 0x0001
        .equiv  PMD2_OC2MD_WIDTH, 0x0001
        .equiv  PMD2_OC2MD_MASK, 0x0002
        .equiv  OC2MD, 0x0001

        .equiv  PMD2_OC3MD, 0x0002
        .equiv  PMD2_OC3MD_WIDTH, 0x0001
        .equiv  PMD2_OC3MD_MASK, 0x0004
        .equiv  OC3MD, 0x0002

        .equiv  PMD2_OC4MD, 0x0003
        .equiv  PMD2_OC4MD_WIDTH, 0x0001
        .equiv  PMD2_OC4MD_MASK, 0x0008
        .equiv  OC4MD, 0x0003

        .equiv  PMD2_IC1MD, 0x0008
        .equiv  PMD2_IC1MD_WIDTH, 0x0001
        .equiv  PMD2_IC1MD_MASK, 0x0100
        .equiv  IC1MD, 0x0008

        .equiv  PMD2_IC2MD, 0x0009
        .equiv  PMD2_IC2MD_WIDTH, 0x0001
        .equiv  PMD2_IC2MD_MASK, 0x0200
        .equiv  IC2MD, 0x0009

        .equiv  PMD2_IC3MD, 0x000A
        .equiv  PMD2_IC3MD_WIDTH, 0x0001
        .equiv  PMD2_IC3MD_MASK, 0x0400
        .equiv  IC3MD, 0x000A

        .equiv  PMD2_IC4MD, 0x000B
        .equiv  PMD2_IC4MD_WIDTH, 0x0001
        .equiv  PMD2_IC4MD_MASK, 0x0800
        .equiv  IC4MD, 0x000B

;----- PMD3 Bits -----------------------------------------------------
        .equiv  PMD3_I2C2MD, 0x0001
        .equiv  PMD3_I2C2MD_WIDTH, 0x0001
        .equiv  PMD3_I2C2MD_MASK, 0x0002
        .equiv  I2C2MD, 0x0001

        .equiv  PMD3_CRCMD, 0x0007
        .equiv  PMD3_CRCMD_WIDTH, 0x0001
        .equiv  PMD3_CRCMD_MASK, 0x0080
        .equiv  CRCMD, 0x0007

        .equiv  PMD3_CMPMD, 0x000A
        .equiv  PMD3_CMPMD_WIDTH, 0x0001
        .equiv  PMD3_CMPMD_MASK, 0x0400
        .equiv  CMPMD, 0x000A

;----- PMD4 Bits -----------------------------------------------------
        .equiv  PMD4_CTMUMD, 0x0002
        .equiv  PMD4_CTMUMD_WIDTH, 0x0001
        .equiv  PMD4_CTMUMD_MASK, 0x0004
        .equiv  CTMUMD, 0x0002

        .equiv  PMD4_REFOMD, 0x0003
        .equiv  PMD4_REFOMD_WIDTH, 0x0001
        .equiv  PMD4_REFOMD_MASK, 0x0008
        .equiv  REFOMD, 0x0003

;----- PMD6 Bits -----------------------------------------------------
        .equiv  PMD6_PWM1MD, 0x0008
        .equiv  PMD6_PWM1MD_WIDTH, 0x0001
        .equiv  PMD6_PWM1MD_MASK, 0x0100
        .equiv  PWM1MD, 0x0008

        .equiv  PMD6_PWM2MD, 0x0009
        .equiv  PMD6_PWM2MD_WIDTH, 0x0001
        .equiv  PMD6_PWM2MD_MASK, 0x0200
        .equiv  PWM2MD, 0x0009

        .equiv  PMD6_PWM3MD, 0x000A
        .equiv  PMD6_PWM3MD_WIDTH, 0x0001
        .equiv  PMD6_PWM3MD_MASK, 0x0400
        .equiv  PWM3MD, 0x000A

;----- PMD7 Bits -----------------------------------------------------
        .equiv  PMD7_PTGMD, 0x0003
        .equiv  PMD7_PTGMD_WIDTH, 0x0001
        .equiv  PMD7_PTGMD_MASK, 0x0008
        .equiv  PTGMD, 0x0003

        .equiv  PMD7_DMA0MD, 0x0004
        .equiv  PMD7_DMA0MD_WIDTH, 0x0001
        .equiv  PMD7_DMA0MD_MASK, 0x0010
        .equiv  DMA0MD, 0x0004

        .equiv  PMD7_DMA1MD, 0x0004
        .equiv  PMD7_DMA1MD_WIDTH, 0x0001
        .equiv  PMD7_DMA1MD_MASK, 0x0010
        .equiv  DMA1MD, 0x0004

        .equiv  PMD7_DMA2MD, 0x0004
        .equiv  PMD7_DMA2MD_WIDTH, 0x0001
        .equiv  PMD7_DMA2MD_MASK, 0x0010
        .equiv  DMA2MD, 0x0004

        .equiv  PMD7_DMA3MD, 0x0004
        .equiv  PMD7_DMA3MD_WIDTH, 0x0001
        .equiv  PMD7_DMA3MD_MASK, 0x0010
        .equiv  DMA3MD, 0x0004

;----- IFS0 Bits -----------------------------------------------------
        .equiv  IFS0_INT0IF, 0x0000
        .equiv  IFS0_INT0IF_WIDTH, 0x0001
        .equiv  IFS0_INT0IF_MASK, 0x0001
        .equiv  INT0IF, 0x0000

        .equiv  IFS0_IC1IF, 0x0001
        .equiv  IFS0_IC1IF_WIDTH, 0x0001
        .equiv  IFS0_IC1IF_MASK, 0x0002
        .equiv  IC1IF, 0x0001

        .equiv  IFS0_OC1IF, 0x0002
        .equiv  IFS0_OC1IF_WIDTH, 0x0001
        .equiv  IFS0_OC1IF_MASK, 0x0004
        .equiv  OC1IF, 0x0002

        .equiv  IFS0_T1IF, 0x0003
        .equiv  IFS0_T1IF_WIDTH, 0x0001
        .equiv  IFS0_T1IF_MASK, 0x0008
        .equiv  T1IF, 0x0003

        .equiv  IFS0_DMA0IF, 0x0004
        .equiv  IFS0_DMA0IF_WIDTH, 0x0001
        .equiv  IFS0_DMA0IF_MASK, 0x0010
        .equiv  DMA0IF, 0x0004

        .equiv  IFS0_IC2IF, 0x0005
        .equiv  IFS0_IC2IF_WIDTH, 0x0001
        .equiv  IFS0_IC2IF_MASK, 0x0020
        .equiv  IC2IF, 0x0005

        .equiv  IFS0_OC2IF, 0x0006
        .equiv  IFS0_OC2IF_WIDTH, 0x0001
        .equiv  IFS0_OC2IF_MASK, 0x0040
        .equiv  OC2IF, 0x0006

        .equiv  IFS0_T2IF, 0x0007
        .equiv  IFS0_T2IF_WIDTH, 0x0001
        .equiv  IFS0_T2IF_MASK, 0x0080
        .equiv  T2IF, 0x0007

        .equiv  IFS0_T3IF, 0x0008
        .equiv  IFS0_T3IF_WIDTH, 0x0001
        .equiv  IFS0_T3IF_MASK, 0x0100
        .equiv  T3IF, 0x0008

        .equiv  IFS0_SPI1EIF, 0x0009
        .equiv  IFS0_SPI1EIF_WIDTH, 0x0001
        .equiv  IFS0_SPI1EIF_MASK, 0x0200
        .equiv  SPI1EIF, 0x0009

        .equiv  IFS0_SPI1IF, 0x000A
        .equiv  IFS0_SPI1IF_WIDTH, 0x0001
        .equiv  IFS0_SPI1IF_MASK, 0x0400
        .equiv  SPI1IF, 0x000A

        .equiv  IFS0_U1RXIF, 0x000B
        .equiv  IFS0_U1RXIF_WIDTH, 0x0001
        .equiv  IFS0_U1RXIF_MASK, 0x0800
        .equiv  U1RXIF, 0x000B

        .equiv  IFS0_U1TXIF, 0x000C
        .equiv  IFS0_U1TXIF_WIDTH, 0x0001
        .equiv  IFS0_U1TXIF_MASK, 0x1000
        .equiv  U1TXIF, 0x000C

        .equiv  IFS0_AD1IF, 0x000D
        .equiv  IFS0_AD1IF_WIDTH, 0x0001
        .equiv  IFS0_AD1IF_MASK, 0x2000
        .equiv  AD1IF, 0x000D

        .equiv  IFS0_DMA1IF, 0x000E
        .equiv  IFS0_DMA1IF_WIDTH, 0x0001
        .equiv  IFS0_DMA1IF_MASK, 0x4000
        .equiv  DMA1IF, 0x000E

;----- IFS1 Bits -----------------------------------------------------
        .equiv  IFS1_SI2C1IF, 0x0000
        .equiv  IFS1_SI2C1IF_WIDTH, 0x0001
        .equiv  IFS1_SI2C1IF_MASK, 0x0001
        .equiv  SI2C1IF, 0x0000

        .equiv  IFS1_MI2C1IF, 0x0001
        .equiv  IFS1_MI2C1IF_WIDTH, 0x0001
        .equiv  IFS1_MI2C1IF_MASK, 0x0002
        .equiv  MI2C1IF, 0x0001

        .equiv  IFS1_CMIF, 0x0002
        .equiv  IFS1_CMIF_WIDTH, 0x0001
        .equiv  IFS1_CMIF_MASK, 0x0004
        .equiv  CMIF, 0x0002

        .equiv  IFS1_CNIF, 0x0003
        .equiv  IFS1_CNIF_WIDTH, 0x0001
        .equiv  IFS1_CNIF_MASK, 0x0008
        .equiv  CNIF, 0x0003

        .equiv  IFS1_INT1IF, 0x0004
        .equiv  IFS1_INT1IF_WIDTH, 0x0001
        .equiv  IFS1_INT1IF_MASK, 0x0010
        .equiv  INT1IF, 0x0004

        .equiv  IFS1_DMA2IF, 0x0008
        .equiv  IFS1_DMA2IF_WIDTH, 0x0001
        .equiv  IFS1_DMA2IF_MASK, 0x0100
        .equiv  DMA2IF, 0x0008

        .equiv  IFS1_OC3IF, 0x0009
        .equiv  IFS1_OC3IF_WIDTH, 0x0001
        .equiv  IFS1_OC3IF_MASK, 0x0200
        .equiv  OC3IF, 0x0009

        .equiv  IFS1_OC4IF, 0x000A
        .equiv  IFS1_OC4IF_WIDTH, 0x0001
        .equiv  IFS1_OC4IF_MASK, 0x0400
        .equiv  OC4IF, 0x000A

        .equiv  IFS1_T4IF, 0x000B
        .equiv  IFS1_T4IF_WIDTH, 0x0001
        .equiv  IFS1_T4IF_MASK, 0x0800
        .equiv  T4IF, 0x000B

        .equiv  IFS1_T5IF, 0x000C
        .equiv  IFS1_T5IF_WIDTH, 0x0001
        .equiv  IFS1_T5IF_MASK, 0x1000
        .equiv  T5IF, 0x000C

        .equiv  IFS1_INT2IF, 0x000D
        .equiv  IFS1_INT2IF_WIDTH, 0x0001
        .equiv  IFS1_INT2IF_MASK, 0x2000
        .equiv  INT2IF, 0x000D

        .equiv  IFS1_U2RXIF, 0x000E
        .equiv  IFS1_U2RXIF_WIDTH, 0x0001
        .equiv  IFS1_U2RXIF_MASK, 0x4000
        .equiv  U2RXIF, 0x000E

        .equiv  IFS1_U2TXIF, 0x000F
        .equiv  IFS1_U2TXIF_WIDTH, 0x0001
        .equiv  IFS1_U2TXIF_MASK, 0x8000
        .equiv  U2TXIF, 0x000F

;----- IFS2 Bits -----------------------------------------------------
        .equiv  IFS2_SPI2EIF, 0x0000
        .equiv  IFS2_SPI2EIF_WIDTH, 0x0001
        .equiv  IFS2_SPI2EIF_MASK, 0x0001
        .equiv  SPI2EIF, 0x0000

        .equiv  IFS2_SPI2IF, 0x0001
        .equiv  IFS2_SPI2IF_WIDTH, 0x0001
        .equiv  IFS2_SPI2IF_MASK, 0x0002
        .equiv  SPI2IF, 0x0001

        .equiv  IFS2_C1RXIF, 0x0002
        .equiv  IFS2_C1RXIF_WIDTH, 0x0001
        .equiv  IFS2_C1RXIF_MASK, 0x0004
        .equiv  C1RXIF, 0x0002

        .equiv  IFS2_C1IF, 0x0003
        .equiv  IFS2_C1IF_WIDTH, 0x0001
        .equiv  IFS2_C1IF_MASK, 0x0008
        .equiv  C1IF, 0x0003

        .equiv  IFS2_DMA3IF, 0x0004
        .equiv  IFS2_DMA3IF_WIDTH, 0x0001
        .equiv  IFS2_DMA3IF_MASK, 0x0010
        .equiv  DMA3IF, 0x0004

        .equiv  IFS2_IC3IF, 0x0005
        .equiv  IFS2_IC3IF_WIDTH, 0x0001
        .equiv  IFS2_IC3IF_MASK, 0x0020
        .equiv  IC3IF, 0x0005

        .equiv  IFS2_IC4IF, 0x0006
        .equiv  IFS2_IC4IF_WIDTH, 0x0001
        .equiv  IFS2_IC4IF_MASK, 0x0040
        .equiv  IC4IF, 0x0006

;----- IFS3 Bits -----------------------------------------------------
        .equiv  IFS3_SI2C2IF, 0x0001
        .equiv  IFS3_SI2C2IF_WIDTH, 0x0001
        .equiv  IFS3_SI2C2IF_MASK, 0x0002
        .equiv  SI2C2IF, 0x0001

        .equiv  IFS3_MI2C2IF, 0x0002
        .equiv  IFS3_MI2C2IF_WIDTH, 0x0001
        .equiv  IFS3_MI2C2IF_MASK, 0x0004
        .equiv  MI2C2IF, 0x0002

        .equiv  IFS3_PSEMIF, 0x0009
        .equiv  IFS3_PSEMIF_WIDTH, 0x0001
        .equiv  IFS3_PSEMIF_MASK, 0x0200
        .equiv  PSEMIF, 0x0009

        .equiv  IFS3_QEI1IF, 0x000A
        .equiv  IFS3_QEI1IF_WIDTH, 0x0001
        .equiv  IFS3_QEI1IF_MASK, 0x0400
        .equiv  QEI1IF, 0x000A

;----- IFS4 Bits -----------------------------------------------------
        .equiv  IFS4_U1EIF, 0x0001
        .equiv  IFS4_U1EIF_WIDTH, 0x0001
        .equiv  IFS4_U1EIF_MASK, 0x0002
        .equiv  U1EIF, 0x0001

        .equiv  IFS4_U2EIF, 0x0002
        .equiv  IFS4_U2EIF_WIDTH, 0x0001
        .equiv  IFS4_U2EIF_MASK, 0x0004
        .equiv  U2EIF, 0x0002

        .equiv  IFS4_CRCIF, 0x0003
        .equiv  IFS4_CRCIF_WIDTH, 0x0001
        .equiv  IFS4_CRCIF_MASK, 0x0008
        .equiv  CRCIF, 0x0003

        .equiv  IFS4_C1TXIF, 0x0006
        .equiv  IFS4_C1TXIF_WIDTH, 0x0001
        .equiv  IFS4_C1TXIF_MASK, 0x0040
        .equiv  C1TXIF, 0x0006

        .equiv  IFS4_CTMUIF, 0x000D
        .equiv  IFS4_CTMUIF_WIDTH, 0x0001
        .equiv  IFS4_CTMUIF_MASK, 0x2000
        .equiv  CTMUIF, 0x000D

;----- IFS5 Bits -----------------------------------------------------
        .equiv  IFS5_PWM1IF, 0x000E
        .equiv  IFS5_PWM1IF_WIDTH, 0x0001
        .equiv  IFS5_PWM1IF_MASK, 0x4000
        .equiv  PWM1IF, 0x000E

        .equiv  IFS5_PWM2IF, 0x000F
        .equiv  IFS5_PWM2IF_WIDTH, 0x0001
        .equiv  IFS5_PWM2IF_MASK, 0x8000
        .equiv  PWM2IF, 0x000F

;----- IFS6 Bits -----------------------------------------------------
        .equiv  IFS6_PWM3IF, 0x0000
        .equiv  IFS6_PWM3IF_WIDTH, 0x0001
        .equiv  IFS6_PWM3IF_MASK, 0x0001
        .equiv  PWM3IF, 0x0000

;----- IFS8 Bits -----------------------------------------------------
        .equiv  IFS8_ICDIF, 0x000E
        .equiv  IFS8_ICDIF_WIDTH, 0x0001
        .equiv  IFS8_ICDIF_MASK, 0x4000
        .equiv  ICDIF, 0x000E

        .equiv  IFS8_JTAGIF, 0x000F
        .equiv  IFS8_JTAGIF_WIDTH, 0x0001
        .equiv  IFS8_JTAGIF_MASK, 0x8000
        .equiv  JTAGIF, 0x000F

;----- IFS9 Bits -----------------------------------------------------
        .equiv  IFS9_PTGSTEPIF, 0x0001
        .equiv  IFS9_PTGSTEPIF_WIDTH, 0x0001
        .equiv  IFS9_PTGSTEPIF_MASK, 0x0002
        .equiv  PTGSTEPIF, 0x0001

        .equiv  IFS9_PTGWDTIF, 0x0002
        .equiv  IFS9_PTGWDTIF_WIDTH, 0x0001
        .equiv  IFS9_PTGWDTIF_MASK, 0x0004
        .equiv  PTGWDTIF, 0x0002

        .equiv  IFS9_PTG0IF, 0x0003
        .equiv  IFS9_PTG0IF_WIDTH, 0x0001
        .equiv  IFS9_PTG0IF_MASK, 0x0008
        .equiv  PTG0IF, 0x0003

        .equiv  IFS9_PTG1IF, 0x0004
        .equiv  IFS9_PTG1IF_WIDTH, 0x0001
        .equiv  IFS9_PTG1IF_MASK, 0x0010
        .equiv  PTG1IF, 0x0004

        .equiv  IFS9_PTG2IF, 0x0005
        .equiv  IFS9_PTG2IF_WIDTH, 0x0001
        .equiv  IFS9_PTG2IF_MASK, 0x0020
        .equiv  PTG2IF, 0x0005

        .equiv  IFS9_PTG3IF, 0x0006
        .equiv  IFS9_PTG3IF_WIDTH, 0x0001
        .equiv  IFS9_PTG3IF_MASK, 0x0040
        .equiv  PTG3IF, 0x0006

;----- IEC0 Bits -----------------------------------------------------
        .equiv  IEC0_INT0IE, 0x0000
        .equiv  IEC0_INT0IE_WIDTH, 0x0001
        .equiv  IEC0_INT0IE_MASK, 0x0001
        .equiv  INT0IE, 0x0000

        .equiv  IEC0_IC1IE, 0x0001
        .equiv  IEC0_IC1IE_WIDTH, 0x0001
        .equiv  IEC0_IC1IE_MASK, 0x0002
        .equiv  IC1IE, 0x0001

        .equiv  IEC0_OC1IE, 0x0002
        .equiv  IEC0_OC1IE_WIDTH, 0x0001
        .equiv  IEC0_OC1IE_MASK, 0x0004
        .equiv  OC1IE, 0x0002

        .equiv  IEC0_T1IE, 0x0003
        .equiv  IEC0_T1IE_WIDTH, 0x0001
        .equiv  IEC0_T1IE_MASK, 0x0008
        .equiv  T1IE, 0x0003

        .equiv  IEC0_DMA0IE, 0x0004
        .equiv  IEC0_DMA0IE_WIDTH, 0x0001
        .equiv  IEC0_DMA0IE_MASK, 0x0010
        .equiv  DMA0IE, 0x0004

        .equiv  IEC0_IC2IE, 0x0005
        .equiv  IEC0_IC2IE_WIDTH, 0x0001
        .equiv  IEC0_IC2IE_MASK, 0x0020
        .equiv  IC2IE, 0x0005

        .equiv  IEC0_OC2IE, 0x0006
        .equiv  IEC0_OC2IE_WIDTH, 0x0001
        .equiv  IEC0_OC2IE_MASK, 0x0040
        .equiv  OC2IE, 0x0006

        .equiv  IEC0_T2IE, 0x0007
        .equiv  IEC0_T2IE_WIDTH, 0x0001
        .equiv  IEC0_T2IE_MASK, 0x0080
        .equiv  T2IE, 0x0007

        .equiv  IEC0_T3IE, 0x0008
        .equiv  IEC0_T3IE_WIDTH, 0x0001
        .equiv  IEC0_T3IE_MASK, 0x0100
        .equiv  T3IE, 0x0008

        .equiv  IEC0_SPI1EIE, 0x0009
        .equiv  IEC0_SPI1EIE_WIDTH, 0x0001
        .equiv  IEC0_SPI1EIE_MASK, 0x0200
        .equiv  SPI1EIE, 0x0009

        .equiv  IEC0_SPI1IE, 0x000A
        .equiv  IEC0_SPI1IE_WIDTH, 0x0001
        .equiv  IEC0_SPI1IE_MASK, 0x0400
        .equiv  SPI1IE, 0x000A

        .equiv  IEC0_U1RXIE, 0x000B
        .equiv  IEC0_U1RXIE_WIDTH, 0x0001
        .equiv  IEC0_U1RXIE_MASK, 0x0800
        .equiv  U1RXIE, 0x000B

        .equiv  IEC0_U1TXIE, 0x000C
        .equiv  IEC0_U1TXIE_WIDTH, 0x0001
        .equiv  IEC0_U1TXIE_MASK, 0x1000
        .equiv  U1TXIE, 0x000C

        .equiv  IEC0_AD1IE, 0x000D
        .equiv  IEC0_AD1IE_WIDTH, 0x0001
        .equiv  IEC0_AD1IE_MASK, 0x2000
        .equiv  AD1IE, 0x000D

        .equiv  IEC0_DMA1IE, 0x000E
        .equiv  IEC0_DMA1IE_WIDTH, 0x0001
        .equiv  IEC0_DMA1IE_MASK, 0x4000
        .equiv  DMA1IE, 0x000E

;----- IEC1 Bits -----------------------------------------------------
        .equiv  IEC1_SI2C1IE, 0x0000
        .equiv  IEC1_SI2C1IE_WIDTH, 0x0001
        .equiv  IEC1_SI2C1IE_MASK, 0x0001
        .equiv  SI2C1IE, 0x0000

        .equiv  IEC1_MI2C1IE, 0x0001
        .equiv  IEC1_MI2C1IE_WIDTH, 0x0001
        .equiv  IEC1_MI2C1IE_MASK, 0x0002
        .equiv  MI2C1IE, 0x0001

        .equiv  IEC1_CMIE, 0x0002
        .equiv  IEC1_CMIE_WIDTH, 0x0001
        .equiv  IEC1_CMIE_MASK, 0x0004
        .equiv  CMIE, 0x0002

        .equiv  IEC1_CNIE, 0x0003
        .equiv  IEC1_CNIE_WIDTH, 0x0001
        .equiv  IEC1_CNIE_MASK, 0x0008
        .equiv  CNIE, 0x0003

        .equiv  IEC1_INT1IE, 0x0004
        .equiv  IEC1_INT1IE_WIDTH, 0x0001
        .equiv  IEC1_INT1IE_MASK, 0x0010
        .equiv  INT1IE, 0x0004

        .equiv  IEC1_DMA2IE, 0x0008
        .equiv  IEC1_DMA2IE_WIDTH, 0x0001
        .equiv  IEC1_DMA2IE_MASK, 0x0100
        .equiv  DMA2IE, 0x0008

        .equiv  IEC1_OC3IE, 0x0009
        .equiv  IEC1_OC3IE_WIDTH, 0x0001
        .equiv  IEC1_OC3IE_MASK, 0x0200
        .equiv  OC3IE, 0x0009

        .equiv  IEC1_OC4IE, 0x000A
        .equiv  IEC1_OC4IE_WIDTH, 0x0001
        .equiv  IEC1_OC4IE_MASK, 0x0400
        .equiv  OC4IE, 0x000A

        .equiv  IEC1_T4IE, 0x000B
        .equiv  IEC1_T4IE_WIDTH, 0x0001
        .equiv  IEC1_T4IE_MASK, 0x0800
        .equiv  T4IE, 0x000B

        .equiv  IEC1_T5IE, 0x000C
        .equiv  IEC1_T5IE_WIDTH, 0x0001
        .equiv  IEC1_T5IE_MASK, 0x1000
        .equiv  T5IE, 0x000C

        .equiv  IEC1_INT2IE, 0x000D
        .equiv  IEC1_INT2IE_WIDTH, 0x0001
        .equiv  IEC1_INT2IE_MASK, 0x2000
        .equiv  INT2IE, 0x000D

        .equiv  IEC1_U2RXIE, 0x000E
        .equiv  IEC1_U2RXIE_WIDTH, 0x0001
        .equiv  IEC1_U2RXIE_MASK, 0x4000
        .equiv  U2RXIE, 0x000E

        .equiv  IEC1_U2TXIE, 0x000F
        .equiv  IEC1_U2TXIE_WIDTH, 0x0001
        .equiv  IEC1_U2TXIE_MASK, 0x8000
        .equiv  U2TXIE, 0x000F

;----- IEC2 Bits -----------------------------------------------------
        .equiv  IEC2_SPI2EIE, 0x0000
        .equiv  IEC2_SPI2EIE_WIDTH, 0x0001
        .equiv  IEC2_SPI2EIE_MASK, 0x0001
        .equiv  SPI2EIE, 0x0000

        .equiv  IEC2_SPI2IE, 0x0001
        .equiv  IEC2_SPI2IE_WIDTH, 0x0001
        .equiv  IEC2_SPI2IE_MASK, 0x0002
        .equiv  SPI2IE, 0x0001

        .equiv  IEC2_C1RXIE, 0x0002
        .equiv  IEC2_C1RXIE_WIDTH, 0x0001
        .equiv  IEC2_C1RXIE_MASK, 0x0004
        .equiv  C1RXIE, 0x0002

        .equiv  IEC2_C1IE, 0x0003
        .equiv  IEC2_C1IE_WIDTH, 0x0001
        .equiv  IEC2_C1IE_MASK, 0x0008
        .equiv  C1IE, 0x0003

        .equiv  IEC2_DMA3IE, 0x0004
        .equiv  IEC2_DMA3IE_WIDTH, 0x0001
        .equiv  IEC2_DMA3IE_MASK, 0x0010
        .equiv  DMA3IE, 0x0004

        .equiv  IEC2_IC3IE, 0x0005
        .equiv  IEC2_IC3IE_WIDTH, 0x0001
        .equiv  IEC2_IC3IE_MASK, 0x0020
        .equiv  IC3IE, 0x0005

        .equiv  IEC2_IC4IE, 0x0006
        .equiv  IEC2_IC4IE_WIDTH, 0x0001
        .equiv  IEC2_IC4IE_MASK, 0x0040
        .equiv  IC4IE, 0x0006

;----- IEC3 Bits -----------------------------------------------------
        .equiv  IEC3_SI2C2IE, 0x0001
        .equiv  IEC3_SI2C2IE_WIDTH, 0x0001
        .equiv  IEC3_SI2C2IE_MASK, 0x0002
        .equiv  SI2C2IE, 0x0001

        .equiv  IEC3_MI2C2IE, 0x0002
        .equiv  IEC3_MI2C2IE_WIDTH, 0x0001
        .equiv  IEC3_MI2C2IE_MASK, 0x0004
        .equiv  MI2C2IE, 0x0002

        .equiv  IEC3_PSEMIE, 0x0009
        .equiv  IEC3_PSEMIE_WIDTH, 0x0001
        .equiv  IEC3_PSEMIE_MASK, 0x0200
        .equiv  PSEMIE, 0x0009

        .equiv  IEC3_QEI1IE, 0x000A
        .equiv  IEC3_QEI1IE_WIDTH, 0x0001
        .equiv  IEC3_QEI1IE_MASK, 0x0400
        .equiv  QEI1IE, 0x000A

;----- IEC4 Bits -----------------------------------------------------
        .equiv  IEC4_U1EIE, 0x0001
        .equiv  IEC4_U1EIE_WIDTH, 0x0001
        .equiv  IEC4_U1EIE_MASK, 0x0002
        .equiv  U1EIE, 0x0001

        .equiv  IEC4_U2EIE, 0x0002
        .equiv  IEC4_U2EIE_WIDTH, 0x0001
        .equiv  IEC4_U2EIE_MASK, 0x0004
        .equiv  U2EIE, 0x0002

        .equiv  IEC4_CRCIE, 0x0003
        .equiv  IEC4_CRCIE_WIDTH, 0x0001
        .equiv  IEC4_CRCIE_MASK, 0x0008
        .equiv  CRCIE, 0x0003

        .equiv  IEC4_C1TXIE, 0x0006
        .equiv  IEC4_C1TXIE_WIDTH, 0x0001
        .equiv  IEC4_C1TXIE_MASK, 0x0040
        .equiv  C1TXIE, 0x0006

        .equiv  IEC4_CTMUIE, 0x000D
        .equiv  IEC4_CTMUIE_WIDTH, 0x0001
        .equiv  IEC4_CTMUIE_MASK, 0x2000
        .equiv  CTMUIE, 0x000D

;----- IEC5 Bits -----------------------------------------------------
        .equiv  IEC5_PWM1IE, 0x000E
        .equiv  IEC5_PWM1IE_WIDTH, 0x0001
        .equiv  IEC5_PWM1IE_MASK, 0x4000
        .equiv  PWM1IE, 0x000E

        .equiv  IEC5_PWM2IE, 0x000F
        .equiv  IEC5_PWM2IE_WIDTH, 0x0001
        .equiv  IEC5_PWM2IE_MASK, 0x8000
        .equiv  PWM2IE, 0x000F

;----- IEC6 Bits -----------------------------------------------------
        .equiv  IEC6_PWM3IE, 0x0000
        .equiv  IEC6_PWM3IE_WIDTH, 0x0001
        .equiv  IEC6_PWM3IE_MASK, 0x0001
        .equiv  PWM3IE, 0x0000

;----- IEC8 Bits -----------------------------------------------------
        .equiv  IEC8_ICDIF, 0x000E
        .equiv  IEC8_ICDIF_WIDTH, 0x0001
        .equiv  IEC8_ICDIF_MASK, 0x4000

        .equiv  IEC8_JTAGIE, 0x000F
        .equiv  IEC8_JTAGIE_WIDTH, 0x0001
        .equiv  IEC8_JTAGIE_MASK, 0x8000
        .equiv  JTAGIE, 0x000F

;----- IEC9 Bits -----------------------------------------------------
        .equiv  IEC9_PTGSTEPIE, 0x0001
        .equiv  IEC9_PTGSTEPIE_WIDTH, 0x0001
        .equiv  IEC9_PTGSTEPIE_MASK, 0x0002
        .equiv  PTGSTEPIE, 0x0001

        .equiv  IEC9_PTGWDTIE, 0x0002
        .equiv  IEC9_PTGWDTIE_WIDTH, 0x0001
        .equiv  IEC9_PTGWDTIE_MASK, 0x0004
        .equiv  PTGWDTIE, 0x0002

        .equiv  IEC9_PTG0IE, 0x0003
        .equiv  IEC9_PTG0IE_WIDTH, 0x0001
        .equiv  IEC9_PTG0IE_MASK, 0x0008
        .equiv  PTG0IE, 0x0003

        .equiv  IEC9_PTG1IE, 0x0004
        .equiv  IEC9_PTG1IE_WIDTH, 0x0001
        .equiv  IEC9_PTG1IE_MASK, 0x0010
        .equiv  PTG1IE, 0x0004

        .equiv  IEC9_PTG2IE, 0x0005
        .equiv  IEC9_PTG2IE_WIDTH, 0x0001
        .equiv  IEC9_PTG2IE_MASK, 0x0020
        .equiv  PTG2IE, 0x0005

        .equiv  IEC9_PTG3IE, 0x0006
        .equiv  IEC9_PTG3IE_WIDTH, 0x0001
        .equiv  IEC9_PTG3IE_MASK, 0x0040
        .equiv  PTG3IE, 0x0006

;----- IPC0 Bits -----------------------------------------------------
        .equiv  IPC0_INT0IP, 0x0000
        .equiv  IPC0_INT0IP_WIDTH, 0x0003
        .equiv  IPC0_INT0IP_MASK, 0x0007

        .equiv  IPC0_IC1IP, 0x0004
        .equiv  IPC0_IC1IP_WIDTH, 0x0003
        .equiv  IPC0_IC1IP_MASK, 0x0070

        .equiv  IPC0_OC1IP, 0x0008
        .equiv  IPC0_OC1IP_WIDTH, 0x0003
        .equiv  IPC0_OC1IP_MASK, 0x0700

        .equiv  IPC0_T1IP, 0x000C
        .equiv  IPC0_T1IP_WIDTH, 0x0003
        .equiv  IPC0_T1IP_MASK, 0x7000

        .equiv  IPC0_INT0IP0, 0x0000
        .equiv  IPC0_INT0IP0_WIDTH, 0x0001
        .equiv  IPC0_INT0IP0_MASK, 0x0001
        .equiv  INT0IP0, 0x0000

        .equiv  IPC0_INT0IP1, 0x0001
        .equiv  IPC0_INT0IP1_WIDTH, 0x0001
        .equiv  IPC0_INT0IP1_MASK, 0x0002
        .equiv  INT0IP1, 0x0001

        .equiv  IPC0_INT0IP2, 0x0002
        .equiv  IPC0_INT0IP2_WIDTH, 0x0001
        .equiv  IPC0_INT0IP2_MASK, 0x0004
        .equiv  INT0IP2, 0x0002

        .equiv  IPC0_IC1IP0, 0x0004
        .equiv  IPC0_IC1IP0_WIDTH, 0x0001
        .equiv  IPC0_IC1IP0_MASK, 0x0010
        .equiv  IC1IP0, 0x0004

        .equiv  IPC0_IC1IP1, 0x0005
        .equiv  IPC0_IC1IP1_WIDTH, 0x0001
        .equiv  IPC0_IC1IP1_MASK, 0x0020
        .equiv  IC1IP1, 0x0005

        .equiv  IPC0_IC1IP2, 0x0006
        .equiv  IPC0_IC1IP2_WIDTH, 0x0001
        .equiv  IPC0_IC1IP2_MASK, 0x0040
        .equiv  IC1IP2, 0x0006

        .equiv  IPC0_OC1IP0, 0x0008
        .equiv  IPC0_OC1IP0_WIDTH, 0x0001
        .equiv  IPC0_OC1IP0_MASK, 0x0100
        .equiv  OC1IP0, 0x0008

        .equiv  IPC0_OC1IP1, 0x0009
        .equiv  IPC0_OC1IP1_WIDTH, 0x0001
        .equiv  IPC0_OC1IP1_MASK, 0x0200
        .equiv  OC1IP1, 0x0009

        .equiv  IPC0_OC1IP2, 0x000A
        .equiv  IPC0_OC1IP2_WIDTH, 0x0001
        .equiv  IPC0_OC1IP2_MASK, 0x0400
        .equiv  OC1IP2, 0x000A

        .equiv  IPC0_T1IP0, 0x000C
        .equiv  IPC0_T1IP0_WIDTH, 0x0001
        .equiv  IPC0_T1IP0_MASK, 0x1000
        .equiv  T1IP0, 0x000C

        .equiv  IPC0_T1IP1, 0x000D
        .equiv  IPC0_T1IP1_WIDTH, 0x0001
        .equiv  IPC0_T1IP1_MASK, 0x2000
        .equiv  T1IP1, 0x000D

        .equiv  IPC0_T1IP2, 0x000E
        .equiv  IPC0_T1IP2_WIDTH, 0x0001
        .equiv  IPC0_T1IP2_MASK, 0x4000
        .equiv  T1IP2, 0x000E

;----- IPC1 Bits -----------------------------------------------------
        .equiv  IPC1_DMA0IP, 0x0000
        .equiv  IPC1_DMA0IP_WIDTH, 0x0003
        .equiv  IPC1_DMA0IP_MASK, 0x0007

        .equiv  IPC1_IC2IP, 0x0004
        .equiv  IPC1_IC2IP_WIDTH, 0x0003
        .equiv  IPC1_IC2IP_MASK, 0x0070

        .equiv  IPC1_OC2IP, 0x0008
        .equiv  IPC1_OC2IP_WIDTH, 0x0003
        .equiv  IPC1_OC2IP_MASK, 0x0700

        .equiv  IPC1_T2IP, 0x000C
        .equiv  IPC1_T2IP_WIDTH, 0x0003
        .equiv  IPC1_T2IP_MASK, 0x7000

        .equiv  IPC1_DMA0IP0, 0x0000
        .equiv  IPC1_DMA0IP0_WIDTH, 0x0001
        .equiv  IPC1_DMA0IP0_MASK, 0x0001
        .equiv  DMA0IP0, 0x0000

        .equiv  IPC1_DMA0IP1, 0x0001
        .equiv  IPC1_DMA0IP1_WIDTH, 0x0001
        .equiv  IPC1_DMA0IP1_MASK, 0x0002
        .equiv  DMA0IP1, 0x0001

        .equiv  IPC1_DMA0IP2, 0x0002
        .equiv  IPC1_DMA0IP2_WIDTH, 0x0001
        .equiv  IPC1_DMA0IP2_MASK, 0x0004
        .equiv  DMA0IP2, 0x0002

        .equiv  IPC1_IC2IP0, 0x0004
        .equiv  IPC1_IC2IP0_WIDTH, 0x0001
        .equiv  IPC1_IC2IP0_MASK, 0x0010
        .equiv  IC2IP0, 0x0004

        .equiv  IPC1_IC2IP1, 0x0005
        .equiv  IPC1_IC2IP1_WIDTH, 0x0001
        .equiv  IPC1_IC2IP1_MASK, 0x0020
        .equiv  IC2IP1, 0x0005

        .equiv  IPC1_IC2IP2, 0x0006
        .equiv  IPC1_IC2IP2_WIDTH, 0x0001
        .equiv  IPC1_IC2IP2_MASK, 0x0040
        .equiv  IC2IP2, 0x0006

        .equiv  IPC1_OC2IP0, 0x0008
        .equiv  IPC1_OC2IP0_WIDTH, 0x0001
        .equiv  IPC1_OC2IP0_MASK, 0x0100
        .equiv  OC2IP0, 0x0008

        .equiv  IPC1_OC2IP1, 0x0009
        .equiv  IPC1_OC2IP1_WIDTH, 0x0001
        .equiv  IPC1_OC2IP1_MASK, 0x0200
        .equiv  OC2IP1, 0x0009

        .equiv  IPC1_OC2IP2, 0x000A
        .equiv  IPC1_OC2IP2_WIDTH, 0x0001
        .equiv  IPC1_OC2IP2_MASK, 0x0400
        .equiv  OC2IP2, 0x000A

        .equiv  IPC1_T2IP0, 0x000C
        .equiv  IPC1_T2IP0_WIDTH, 0x0001
        .equiv  IPC1_T2IP0_MASK, 0x1000
        .equiv  T2IP0, 0x000C

        .equiv  IPC1_T2IP1, 0x000D
        .equiv  IPC1_T2IP1_WIDTH, 0x0001
        .equiv  IPC1_T2IP1_MASK, 0x2000
        .equiv  T2IP1, 0x000D

        .equiv  IPC1_T2IP2, 0x000E
        .equiv  IPC1_T2IP2_WIDTH, 0x0001
        .equiv  IPC1_T2IP2_MASK, 0x4000
        .equiv  T2IP2, 0x000E

;----- IPC2 Bits -----------------------------------------------------
        .equiv  IPC2_T3IP, 0x0000
        .equiv  IPC2_T3IP_WIDTH, 0x0003
        .equiv  IPC2_T3IP_MASK, 0x0007

        .equiv  IPC2_SPI1EIP, 0x0004
        .equiv  IPC2_SPI1EIP_WIDTH, 0x0003
        .equiv  IPC2_SPI1EIP_MASK, 0x0070

        .equiv  IPC2_SPI1IP, 0x0008
        .equiv  IPC2_SPI1IP_WIDTH, 0x0003
        .equiv  IPC2_SPI1IP_MASK, 0x0700

        .equiv  IPC2_U1RXIP, 0x000C
        .equiv  IPC2_U1RXIP_WIDTH, 0x0003
        .equiv  IPC2_U1RXIP_MASK, 0x7000

        .equiv  IPC2_T3IP0, 0x0000
        .equiv  IPC2_T3IP0_WIDTH, 0x0001
        .equiv  IPC2_T3IP0_MASK, 0x0001
        .equiv  T3IP0, 0x0000

        .equiv  IPC2_T3IP1, 0x0001
        .equiv  IPC2_T3IP1_WIDTH, 0x0001
        .equiv  IPC2_T3IP1_MASK, 0x0002
        .equiv  T3IP1, 0x0001

        .equiv  IPC2_T3IP2, 0x0002
        .equiv  IPC2_T3IP2_WIDTH, 0x0001
        .equiv  IPC2_T3IP2_MASK, 0x0004
        .equiv  T3IP2, 0x0002

        .equiv  IPC2_SPI1EIP0, 0x0004
        .equiv  IPC2_SPI1EIP0_WIDTH, 0x0001
        .equiv  IPC2_SPI1EIP0_MASK, 0x0010
        .equiv  SPI1EIP0, 0x0004

        .equiv  IPC2_SPI1EIP1, 0x0005
        .equiv  IPC2_SPI1EIP1_WIDTH, 0x0001
        .equiv  IPC2_SPI1EIP1_MASK, 0x0020
        .equiv  SPI1EIP1, 0x0005

        .equiv  IPC2_SPI1EIP2, 0x0006
        .equiv  IPC2_SPI1EIP2_WIDTH, 0x0001
        .equiv  IPC2_SPI1EIP2_MASK, 0x0040
        .equiv  SPI1EIP2, 0x0006

        .equiv  IPC2_SPI1IP0, 0x0008
        .equiv  IPC2_SPI1IP0_WIDTH, 0x0001
        .equiv  IPC2_SPI1IP0_MASK, 0x0100
        .equiv  SPI1IP0, 0x0008

        .equiv  IPC2_SPI1IP1, 0x0009
        .equiv  IPC2_SPI1IP1_WIDTH, 0x0001
        .equiv  IPC2_SPI1IP1_MASK, 0x0200
        .equiv  SPI1IP1, 0x0009

        .equiv  IPC2_SPI1IP2, 0x000A
        .equiv  IPC2_SPI1IP2_WIDTH, 0x0001
        .equiv  IPC2_SPI1IP2_MASK, 0x0400
        .equiv  SPI1IP2, 0x000A

        .equiv  IPC2_U1RXIP0, 0x000C
        .equiv  IPC2_U1RXIP0_WIDTH, 0x0001
        .equiv  IPC2_U1RXIP0_MASK, 0x1000
        .equiv  U1RXIP0, 0x000C

        .equiv  IPC2_U1RXIP1, 0x000D
        .equiv  IPC2_U1RXIP1_WIDTH, 0x0001
        .equiv  IPC2_U1RXIP1_MASK, 0x2000
        .equiv  U1RXIP1, 0x000D

        .equiv  IPC2_U1RXIP2, 0x000E
        .equiv  IPC2_U1RXIP2_WIDTH, 0x0001
        .equiv  IPC2_U1RXIP2_MASK, 0x4000
        .equiv  U1RXIP2, 0x000E

;----- IPC3 Bits -----------------------------------------------------
        .equiv  IPC3_U1TXIP, 0x0000
        .equiv  IPC3_U1TXIP_WIDTH, 0x0003
        .equiv  IPC3_U1TXIP_MASK, 0x0007

        .equiv  IPC3_AD1IP, 0x0004
        .equiv  IPC3_AD1IP_WIDTH, 0x0003
        .equiv  IPC3_AD1IP_MASK, 0x0070

        .equiv  IPC3_DMA1IP, 0x0008
        .equiv  IPC3_DMA1IP_WIDTH, 0x0003
        .equiv  IPC3_DMA1IP_MASK, 0x0700

        .equiv  IPC3_U1TXIP0, 0x0000
        .equiv  IPC3_U1TXIP0_WIDTH, 0x0001
        .equiv  IPC3_U1TXIP0_MASK, 0x0001
        .equiv  U1TXIP0, 0x0000

        .equiv  IPC3_U1TXIP1, 0x0001
        .equiv  IPC3_U1TXIP1_WIDTH, 0x0001
        .equiv  IPC3_U1TXIP1_MASK, 0x0002
        .equiv  U1TXIP1, 0x0001

        .equiv  IPC3_U1TXIP2, 0x0002
        .equiv  IPC3_U1TXIP2_WIDTH, 0x0001
        .equiv  IPC3_U1TXIP2_MASK, 0x0004
        .equiv  U1TXIP2, 0x0002

        .equiv  IPC3_AD1IP0, 0x0004
        .equiv  IPC3_AD1IP0_WIDTH, 0x0001
        .equiv  IPC3_AD1IP0_MASK, 0x0010
        .equiv  AD1IP0, 0x0004

        .equiv  IPC3_AD1IP1, 0x0005
        .equiv  IPC3_AD1IP1_WIDTH, 0x0001
        .equiv  IPC3_AD1IP1_MASK, 0x0020
        .equiv  AD1IP1, 0x0005

        .equiv  IPC3_AD1IP2, 0x0006
        .equiv  IPC3_AD1IP2_WIDTH, 0x0001
        .equiv  IPC3_AD1IP2_MASK, 0x0040
        .equiv  AD1IP2, 0x0006

        .equiv  IPC3_DMA1IP0, 0x0008
        .equiv  IPC3_DMA1IP0_WIDTH, 0x0001
        .equiv  IPC3_DMA1IP0_MASK, 0x0100
        .equiv  DMA1IP0, 0x0008

        .equiv  IPC3_DMA1IP1, 0x0009
        .equiv  IPC3_DMA1IP1_WIDTH, 0x0001
        .equiv  IPC3_DMA1IP1_MASK, 0x0200
        .equiv  DMA1IP1, 0x0009

        .equiv  IPC3_DMA1IP2, 0x000A
        .equiv  IPC3_DMA1IP2_WIDTH, 0x0001
        .equiv  IPC3_DMA1IP2_MASK, 0x0400
        .equiv  DMA1IP2, 0x000A

        .equiv  IPC3_NVMIP0, 0x000C
        .equiv  IPC3_NVMIP0_WIDTH, 0x0001
        .equiv  IPC3_NVMIP0_MASK, 0x1000
        .equiv  NVMIP0, 0x000C

        .equiv  IPC3_NVMIP1, 0x000D
        .equiv  IPC3_NVMIP1_WIDTH, 0x0001
        .equiv  IPC3_NVMIP1_MASK, 0x2000
        .equiv  NVMIP1, 0x000D

        .equiv  IPC3_NVMIP2, 0x000E
        .equiv  IPC3_NVMIP2_WIDTH, 0x0001
        .equiv  IPC3_NVMIP2_MASK, 0x4000
        .equiv  NVMIP2, 0x000E

;----- IPC4 Bits -----------------------------------------------------
        .equiv  IPC4_SI2C1IP, 0x0000
        .equiv  IPC4_SI2C1IP_WIDTH, 0x0003
        .equiv  IPC4_SI2C1IP_MASK, 0x0007

        .equiv  IPC4_MI2C1IP, 0x0004
        .equiv  IPC4_MI2C1IP_WIDTH, 0x0003
        .equiv  IPC4_MI2C1IP_MASK, 0x0070

        .equiv  IPC4_CMIP, 0x0008
        .equiv  IPC4_CMIP_WIDTH, 0x0003
        .equiv  IPC4_CMIP_MASK, 0x0700

        .equiv  IPC4_CNIP, 0x000C
        .equiv  IPC4_CNIP_WIDTH, 0x0003
        .equiv  IPC4_CNIP_MASK, 0x7000

        .equiv  IPC4_SI2C1IP0, 0x0000
        .equiv  IPC4_SI2C1IP0_WIDTH, 0x0001
        .equiv  IPC4_SI2C1IP0_MASK, 0x0001
        .equiv  SI2C1IP0, 0x0000

        .equiv  IPC4_SI2C1IP1, 0x0001
        .equiv  IPC4_SI2C1IP1_WIDTH, 0x0001
        .equiv  IPC4_SI2C1IP1_MASK, 0x0002
        .equiv  SI2C1IP1, 0x0001

        .equiv  IPC4_SI2C1IP2, 0x0002
        .equiv  IPC4_SI2C1IP2_WIDTH, 0x0001
        .equiv  IPC4_SI2C1IP2_MASK, 0x0004
        .equiv  SI2C1IP2, 0x0002

        .equiv  IPC4_MI2C1IP0, 0x0004
        .equiv  IPC4_MI2C1IP0_WIDTH, 0x0001
        .equiv  IPC4_MI2C1IP0_MASK, 0x0010
        .equiv  MI2C1IP0, 0x0004

        .equiv  IPC4_MI2C1IP1, 0x0005
        .equiv  IPC4_MI2C1IP1_WIDTH, 0x0001
        .equiv  IPC4_MI2C1IP1_MASK, 0x0020
        .equiv  MI2C1IP1, 0x0005

        .equiv  IPC4_MI2C1IP2, 0x0006
        .equiv  IPC4_MI2C1IP2_WIDTH, 0x0001
        .equiv  IPC4_MI2C1IP2_MASK, 0x0040
        .equiv  MI2C1IP2, 0x0006

        .equiv  IPC4_CMIP0, 0x0008
        .equiv  IPC4_CMIP0_WIDTH, 0x0001
        .equiv  IPC4_CMIP0_MASK, 0x0100
        .equiv  CMIP0, 0x0008

        .equiv  IPC4_CMIP1, 0x0009
        .equiv  IPC4_CMIP1_WIDTH, 0x0001
        .equiv  IPC4_CMIP1_MASK, 0x0200
        .equiv  CMIP1, 0x0009

        .equiv  IPC4_CMIP2, 0x000A
        .equiv  IPC4_CMIP2_WIDTH, 0x0001
        .equiv  IPC4_CMIP2_MASK, 0x0400
        .equiv  CMIP2, 0x000A

        .equiv  IPC4_CNIP0, 0x000C
        .equiv  IPC4_CNIP0_WIDTH, 0x0001
        .equiv  IPC4_CNIP0_MASK, 0x1000
        .equiv  CNIP0, 0x000C

        .equiv  IPC4_CNIP1, 0x000D
        .equiv  IPC4_CNIP1_WIDTH, 0x0001
        .equiv  IPC4_CNIP1_MASK, 0x2000
        .equiv  CNIP1, 0x000D

        .equiv  IPC4_CNIP2, 0x000E
        .equiv  IPC4_CNIP2_WIDTH, 0x0001
        .equiv  IPC4_CNIP2_MASK, 0x4000
        .equiv  CNIP2, 0x000E

;----- IPC5 Bits -----------------------------------------------------
        .equiv  IPC5_INT1IP, 0x0000
        .equiv  IPC5_INT1IP_WIDTH, 0x0003
        .equiv  IPC5_INT1IP_MASK, 0x0007

        .equiv  IPC5_INT1IP0, 0x0000
        .equiv  IPC5_INT1IP0_WIDTH, 0x0001
        .equiv  IPC5_INT1IP0_MASK, 0x0001
        .equiv  INT1IP0, 0x0000

        .equiv  IPC5_INT1IP1, 0x0001
        .equiv  IPC5_INT1IP1_WIDTH, 0x0001
        .equiv  IPC5_INT1IP1_MASK, 0x0002
        .equiv  INT1IP1, 0x0001

        .equiv  IPC5_INT1IP2, 0x0002
        .equiv  IPC5_INT1IP2_WIDTH, 0x0001
        .equiv  IPC5_INT1IP2_MASK, 0x0004
        .equiv  INT1IP2, 0x0002

;----- IPC6 Bits -----------------------------------------------------
        .equiv  IPC6_DMA2IP, 0x0000
        .equiv  IPC6_DMA2IP_WIDTH, 0x0003
        .equiv  IPC6_DMA2IP_MASK, 0x0007

        .equiv  IPC6_OC3IP, 0x0004
        .equiv  IPC6_OC3IP_WIDTH, 0x0003
        .equiv  IPC6_OC3IP_MASK, 0x0070

        .equiv  IPC6_OC4IP, 0x0008
        .equiv  IPC6_OC4IP_WIDTH, 0x0003
        .equiv  IPC6_OC4IP_MASK, 0x0700

        .equiv  IPC6_T4IP, 0x000C
        .equiv  IPC6_T4IP_WIDTH, 0x0003
        .equiv  IPC6_T4IP_MASK, 0x7000

        .equiv  IPC6_DMA2IP0, 0x0000
        .equiv  IPC6_DMA2IP0_WIDTH, 0x0001
        .equiv  IPC6_DMA2IP0_MASK, 0x0001
        .equiv  DMA2IP0, 0x0000

        .equiv  IPC6_DMA2IP1, 0x0001
        .equiv  IPC6_DMA2IP1_WIDTH, 0x0001
        .equiv  IPC6_DMA2IP1_MASK, 0x0002
        .equiv  DMA2IP1, 0x0001

        .equiv  IPC6_DMA2IP2, 0x0002
        .equiv  IPC6_DMA2IP2_WIDTH, 0x0001
        .equiv  IPC6_DMA2IP2_MASK, 0x0004
        .equiv  DMA2IP2, 0x0002

        .equiv  IPC6_OC3IP0, 0x0004
        .equiv  IPC6_OC3IP0_WIDTH, 0x0001
        .equiv  IPC6_OC3IP0_MASK, 0x0010
        .equiv  OC3IP0, 0x0004

        .equiv  IPC6_OC3IP1, 0x0005
        .equiv  IPC6_OC3IP1_WIDTH, 0x0001
        .equiv  IPC6_OC3IP1_MASK, 0x0020
        .equiv  OC3IP1, 0x0005

        .equiv  IPC6_OC3IP2, 0x0006
        .equiv  IPC6_OC3IP2_WIDTH, 0x0001
        .equiv  IPC6_OC3IP2_MASK, 0x0040
        .equiv  OC3IP2, 0x0006

        .equiv  IPC6_OC4IP0, 0x0008
        .equiv  IPC6_OC4IP0_WIDTH, 0x0001
        .equiv  IPC6_OC4IP0_MASK, 0x0100
        .equiv  OC4IP0, 0x0008

        .equiv  IPC6_OC4IP1, 0x0009
        .equiv  IPC6_OC4IP1_WIDTH, 0x0001
        .equiv  IPC6_OC4IP1_MASK, 0x0200
        .equiv  OC4IP1, 0x0009

        .equiv  IPC6_OC4IP2, 0x000A
        .equiv  IPC6_OC4IP2_WIDTH, 0x0001
        .equiv  IPC6_OC4IP2_MASK, 0x0400
        .equiv  OC4IP2, 0x000A

        .equiv  IPC6_T4IP0, 0x000C
        .equiv  IPC6_T4IP0_WIDTH, 0x0001
        .equiv  IPC6_T4IP0_MASK, 0x1000
        .equiv  T4IP0, 0x000C

        .equiv  IPC6_T4IP1, 0x000D
        .equiv  IPC6_T4IP1_WIDTH, 0x0001
        .equiv  IPC6_T4IP1_MASK, 0x2000
        .equiv  T4IP1, 0x000D

        .equiv  IPC6_T4IP2, 0x000E
        .equiv  IPC6_T4IP2_WIDTH, 0x0001
        .equiv  IPC6_T4IP2_MASK, 0x4000
        .equiv  T4IP2, 0x000E

;----- IPC7 Bits -----------------------------------------------------
        .equiv  IPC7_T5IP, 0x0000
        .equiv  IPC7_T5IP_WIDTH, 0x0003
        .equiv  IPC7_T5IP_MASK, 0x0007

        .equiv  IPC7_INT2IP, 0x0004
        .equiv  IPC7_INT2IP_WIDTH, 0x0003
        .equiv  IPC7_INT2IP_MASK, 0x0070

        .equiv  IPC7_U2RXIP, 0x0008
        .equiv  IPC7_U2RXIP_WIDTH, 0x0003
        .equiv  IPC7_U2RXIP_MASK, 0x0700

        .equiv  IPC7_U2TXIP, 0x000C
        .equiv  IPC7_U2TXIP_WIDTH, 0x0003
        .equiv  IPC7_U2TXIP_MASK, 0x7000

        .equiv  IPC7_T5IP0, 0x0000
        .equiv  IPC7_T5IP0_WIDTH, 0x0001
        .equiv  IPC7_T5IP0_MASK, 0x0001
        .equiv  T5IP0, 0x0000

        .equiv  IPC7_T5IP1, 0x0001
        .equiv  IPC7_T5IP1_WIDTH, 0x0001
        .equiv  IPC7_T5IP1_MASK, 0x0002
        .equiv  T5IP1, 0x0001

        .equiv  IPC7_T5IP2, 0x0002
        .equiv  IPC7_T5IP2_WIDTH, 0x0001
        .equiv  IPC7_T5IP2_MASK, 0x0004
        .equiv  T5IP2, 0x0002

        .equiv  IPC7_INT2IP0, 0x0004
        .equiv  IPC7_INT2IP0_WIDTH, 0x0001
        .equiv  IPC7_INT2IP0_MASK, 0x0010
        .equiv  INT2IP0, 0x0004

        .equiv  IPC7_INT2IP1, 0x0005
        .equiv  IPC7_INT2IP1_WIDTH, 0x0001
        .equiv  IPC7_INT2IP1_MASK, 0x0020
        .equiv  INT2IP1, 0x0005

        .equiv  IPC7_INT2IP2, 0x0006
        .equiv  IPC7_INT2IP2_WIDTH, 0x0001
        .equiv  IPC7_INT2IP2_MASK, 0x0040
        .equiv  INT2IP2, 0x0006

        .equiv  IPC7_U2RXIP0, 0x0008
        .equiv  IPC7_U2RXIP0_WIDTH, 0x0001
        .equiv  IPC7_U2RXIP0_MASK, 0x0100
        .equiv  U2RXIP0, 0x0008

        .equiv  IPC7_U2RXIP1, 0x0009
        .equiv  IPC7_U2RXIP1_WIDTH, 0x0001
        .equiv  IPC7_U2RXIP1_MASK, 0x0200
        .equiv  U2RXIP1, 0x0009

        .equiv  IPC7_U2RXIP2, 0x000A
        .equiv  IPC7_U2RXIP2_WIDTH, 0x0001
        .equiv  IPC7_U2RXIP2_MASK, 0x0400
        .equiv  U2RXIP2, 0x000A

        .equiv  IPC7_U2TXIP0, 0x000C
        .equiv  IPC7_U2TXIP0_WIDTH, 0x0001
        .equiv  IPC7_U2TXIP0_MASK, 0x1000
        .equiv  U2TXIP0, 0x000C

        .equiv  IPC7_U2TXIP1, 0x000D
        .equiv  IPC7_U2TXIP1_WIDTH, 0x0001
        .equiv  IPC7_U2TXIP1_MASK, 0x2000
        .equiv  U2TXIP1, 0x000D

        .equiv  IPC7_U2TXIP2, 0x000E
        .equiv  IPC7_U2TXIP2_WIDTH, 0x0001
        .equiv  IPC7_U2TXIP2_MASK, 0x4000
        .equiv  U2TXIP2, 0x000E

;----- IPC8 Bits -----------------------------------------------------
        .equiv  IPC8_SPI2EIP, 0x0000
        .equiv  IPC8_SPI2EIP_WIDTH, 0x0003
        .equiv  IPC8_SPI2EIP_MASK, 0x0007

        .equiv  IPC8_SPI2IP, 0x0004
        .equiv  IPC8_SPI2IP_WIDTH, 0x0003
        .equiv  IPC8_SPI2IP_MASK, 0x0070

        .equiv  IPC8_C1RXIP, 0x0008
        .equiv  IPC8_C1RXIP_WIDTH, 0x0003
        .equiv  IPC8_C1RXIP_MASK, 0x0700

        .equiv  IPC8_C1IP, 0x000C
        .equiv  IPC8_C1IP_WIDTH, 0x0003
        .equiv  IPC8_C1IP_MASK, 0x7000

        .equiv  IPC8_SPI2EIP0, 0x0000
        .equiv  IPC8_SPI2EIP0_WIDTH, 0x0001
        .equiv  IPC8_SPI2EIP0_MASK, 0x0001
        .equiv  SPI2EIP0, 0x0000

        .equiv  IPC8_SPI2EIP1, 0x0001
        .equiv  IPC8_SPI2EIP1_WIDTH, 0x0001
        .equiv  IPC8_SPI2EIP1_MASK, 0x0002
        .equiv  SPI2EIP1, 0x0001

        .equiv  IPC8_SPI2EIP2, 0x0002
        .equiv  IPC8_SPI2EIP2_WIDTH, 0x0001
        .equiv  IPC8_SPI2EIP2_MASK, 0x0004
        .equiv  SPI2EIP2, 0x0002

        .equiv  IPC8_SPI2IP0, 0x0004
        .equiv  IPC8_SPI2IP0_WIDTH, 0x0001
        .equiv  IPC8_SPI2IP0_MASK, 0x0010
        .equiv  SPI2IP0, 0x0004

        .equiv  IPC8_SPI2IP1, 0x0005
        .equiv  IPC8_SPI2IP1_WIDTH, 0x0001
        .equiv  IPC8_SPI2IP1_MASK, 0x0020
        .equiv  SPI2IP1, 0x0005

        .equiv  IPC8_SPI2IP2, 0x0006
        .equiv  IPC8_SPI2IP2_WIDTH, 0x0001
        .equiv  IPC8_SPI2IP2_MASK, 0x0040
        .equiv  SPI2IP2, 0x0006

        .equiv  IPC8_C1RXIP0, 0x0008
        .equiv  IPC8_C1RXIP0_WIDTH, 0x0001
        .equiv  IPC8_C1RXIP0_MASK, 0x0100
        .equiv  C1RXIP0, 0x0008

        .equiv  IPC8_C1RXIP1, 0x0009
        .equiv  IPC8_C1RXIP1_WIDTH, 0x0001
        .equiv  IPC8_C1RXIP1_MASK, 0x0200
        .equiv  C1RXIP1, 0x0009

        .equiv  IPC8_C1RXIP2, 0x000A
        .equiv  IPC8_C1RXIP2_WIDTH, 0x0001
        .equiv  IPC8_C1RXIP2_MASK, 0x0400
        .equiv  C1RXIP2, 0x000A

        .equiv  IPC8_C1IP0, 0x000C
        .equiv  IPC8_C1IP0_WIDTH, 0x0001
        .equiv  IPC8_C1IP0_MASK, 0x1000
        .equiv  C1IP0, 0x000C

        .equiv  IPC8_C1IP1, 0x000D
        .equiv  IPC8_C1IP1_WIDTH, 0x0001
        .equiv  IPC8_C1IP1_MASK, 0x2000
        .equiv  C1IP1, 0x000D

        .equiv  IPC8_C1IP2, 0x000E
        .equiv  IPC8_C1IP2_WIDTH, 0x0001
        .equiv  IPC8_C1IP2_MASK, 0x4000
        .equiv  C1IP2, 0x000E

;----- IPC9 Bits -----------------------------------------------------
        .equiv  IPC9_DMA3IP, 0x0000
        .equiv  IPC9_DMA3IP_WIDTH, 0x0003
        .equiv  IPC9_DMA3IP_MASK, 0x0007

        .equiv  IPC9_IC3IP, 0x0004
        .equiv  IPC9_IC3IP_WIDTH, 0x0003
        .equiv  IPC9_IC3IP_MASK, 0x0070

        .equiv  IPC9_IC4IP, 0x0008
        .equiv  IPC9_IC4IP_WIDTH, 0x0003
        .equiv  IPC9_IC4IP_MASK, 0x0700

        .equiv  IPC9_DMA3IP0, 0x0000
        .equiv  IPC9_DMA3IP0_WIDTH, 0x0001
        .equiv  IPC9_DMA3IP0_MASK, 0x0001
        .equiv  DMA3IP0, 0x0000

        .equiv  IPC9_DMA3IP1, 0x0001
        .equiv  IPC9_DMA3IP1_WIDTH, 0x0001
        .equiv  IPC9_DMA3IP1_MASK, 0x0002
        .equiv  DMA3IP1, 0x0001

        .equiv  IPC9_DMA3IP2, 0x0002
        .equiv  IPC9_DMA3IP2_WIDTH, 0x0001
        .equiv  IPC9_DMA3IP2_MASK, 0x0004
        .equiv  DMA3IP2, 0x0002

        .equiv  IPC9_IC3IP0, 0x0004
        .equiv  IPC9_IC3IP0_WIDTH, 0x0001
        .equiv  IPC9_IC3IP0_MASK, 0x0010
        .equiv  IC3IP0, 0x0004

        .equiv  IPC9_IC3IP1, 0x0005
        .equiv  IPC9_IC3IP1_WIDTH, 0x0001
        .equiv  IPC9_IC3IP1_MASK, 0x0020
        .equiv  IC3IP1, 0x0005

        .equiv  IPC9_IC3IP2, 0x0006
        .equiv  IPC9_IC3IP2_WIDTH, 0x0001
        .equiv  IPC9_IC3IP2_MASK, 0x0040
        .equiv  IC3IP2, 0x0006

        .equiv  IPC9_IC4IP0, 0x0008
        .equiv  IPC9_IC4IP0_WIDTH, 0x0001
        .equiv  IPC9_IC4IP0_MASK, 0x0100
        .equiv  IC4IP0, 0x0008

        .equiv  IPC9_IC4IP1, 0x0009
        .equiv  IPC9_IC4IP1_WIDTH, 0x0001
        .equiv  IPC9_IC4IP1_MASK, 0x0200
        .equiv  IC4IP1, 0x0009

        .equiv  IPC9_IC4IP2, 0x000A
        .equiv  IPC9_IC4IP2_WIDTH, 0x0001
        .equiv  IPC9_IC4IP2_MASK, 0x0400
        .equiv  IC4IP2, 0x000A

;----- IPC12 Bits -----------------------------------------------------
        .equiv  IPC12_SI2C2IP, 0x0004
        .equiv  IPC12_SI2C2IP_WIDTH, 0x0003
        .equiv  IPC12_SI2C2IP_MASK, 0x0070

        .equiv  IPC12_MI2C2IP, 0x0008
        .equiv  IPC12_MI2C2IP_WIDTH, 0x0003
        .equiv  IPC12_MI2C2IP_MASK, 0x0700

        .equiv  IPC12_SI2C2IP0, 0x0004
        .equiv  IPC12_SI2C2IP0_WIDTH, 0x0001
        .equiv  IPC12_SI2C2IP0_MASK, 0x0010
        .equiv  SI2C2IP0, 0x0004

        .equiv  IPC12_SI2C2IP1, 0x0005
        .equiv  IPC12_SI2C2IP1_WIDTH, 0x0001
        .equiv  IPC12_SI2C2IP1_MASK, 0x0020
        .equiv  SI2C2IP1, 0x0005

        .equiv  IPC12_SI2C2IP2, 0x0006
        .equiv  IPC12_SI2C2IP2_WIDTH, 0x0001
        .equiv  IPC12_SI2C2IP2_MASK, 0x0040
        .equiv  SI2C2IP2, 0x0006

        .equiv  IPC12_MI2C2IP0, 0x0008
        .equiv  IPC12_MI2C2IP0_WIDTH, 0x0001
        .equiv  IPC12_MI2C2IP0_MASK, 0x0100
        .equiv  MI2C2IP0, 0x0008

        .equiv  IPC12_MI2C2IP1, 0x0009
        .equiv  IPC12_MI2C2IP1_WIDTH, 0x0001
        .equiv  IPC12_MI2C2IP1_MASK, 0x0200
        .equiv  MI2C2IP1, 0x0009

        .equiv  IPC12_MI2C2IP2, 0x000A
        .equiv  IPC12_MI2C2IP2_WIDTH, 0x0001
        .equiv  IPC12_MI2C2IP2_MASK, 0x0400
        .equiv  MI2C2IP2, 0x000A

;----- IPC14 Bits -----------------------------------------------------
        .equiv  IPC14_PSEMIP, 0x0004
        .equiv  IPC14_PSEMIP_WIDTH, 0x0003
        .equiv  IPC14_PSEMIP_MASK, 0x0070

        .equiv  IPC14_QEI1IP, 0x0008
        .equiv  IPC14_QEI1IP_WIDTH, 0x0003
        .equiv  IPC14_QEI1IP_MASK, 0x0700

        .equiv  IPC14_PSEMIP0, 0x0004
        .equiv  IPC14_PSEMIP0_WIDTH, 0x0001
        .equiv  IPC14_PSEMIP0_MASK, 0x0010
        .equiv  PSEMIP0, 0x0004

        .equiv  IPC14_PSEMIP1, 0x0005
        .equiv  IPC14_PSEMIP1_WIDTH, 0x0001
        .equiv  IPC14_PSEMIP1_MASK, 0x0020
        .equiv  PSEMIP1, 0x0005

        .equiv  IPC14_PSEMIP2, 0x0006
        .equiv  IPC14_PSEMIP2_WIDTH, 0x0001
        .equiv  IPC14_PSEMIP2_MASK, 0x0040
        .equiv  PSEMIP2, 0x0006

        .equiv  IPC14_QEI1IP0, 0x0008
        .equiv  IPC14_QEI1IP0_WIDTH, 0x0001
        .equiv  IPC14_QEI1IP0_MASK, 0x0100
        .equiv  QEI1IP0, 0x0008

        .equiv  IPC14_QEI1IP1, 0x0009
        .equiv  IPC14_QEI1IP1_WIDTH, 0x0001
        .equiv  IPC14_QEI1IP1_MASK, 0x0200
        .equiv  QEI1IP1, 0x0009

        .equiv  IPC14_QEI1IP2, 0x000A
        .equiv  IPC14_QEI1IP2_WIDTH, 0x0001
        .equiv  IPC14_QEI1IP2_MASK, 0x0400
        .equiv  QEI1IP2, 0x000A

;----- IPC16 Bits -----------------------------------------------------
        .equiv  IPC16_U1EIP, 0x0004
        .equiv  IPC16_U1EIP_WIDTH, 0x0003
        .equiv  IPC16_U1EIP_MASK, 0x0070

        .equiv  IPC16_U2EIP, 0x0008
        .equiv  IPC16_U2EIP_WIDTH, 0x0003
        .equiv  IPC16_U2EIP_MASK, 0x0700

        .equiv  IPC16_CRCIP, 0x000C
        .equiv  IPC16_CRCIP_WIDTH, 0x0003
        .equiv  IPC16_CRCIP_MASK, 0x7000

        .equiv  IPC16_U1EIP0, 0x0004
        .equiv  IPC16_U1EIP0_WIDTH, 0x0001
        .equiv  IPC16_U1EIP0_MASK, 0x0010
        .equiv  U1EIP0, 0x0004

        .equiv  IPC16_U1EIP1, 0x0005
        .equiv  IPC16_U1EIP1_WIDTH, 0x0001
        .equiv  IPC16_U1EIP1_MASK, 0x0020
        .equiv  U1EIP1, 0x0005

        .equiv  IPC16_U1EIP2, 0x0006
        .equiv  IPC16_U1EIP2_WIDTH, 0x0001
        .equiv  IPC16_U1EIP2_MASK, 0x0040
        .equiv  U1EIP2, 0x0006

        .equiv  IPC16_U2EIP0, 0x0008
        .equiv  IPC16_U2EIP0_WIDTH, 0x0001
        .equiv  IPC16_U2EIP0_MASK, 0x0100
        .equiv  U2EIP0, 0x0008

        .equiv  IPC16_U2EIP1, 0x0009
        .equiv  IPC16_U2EIP1_WIDTH, 0x0001
        .equiv  IPC16_U2EIP1_MASK, 0x0200
        .equiv  U2EIP1, 0x0009

        .equiv  IPC16_U2EIP2, 0x000A
        .equiv  IPC16_U2EIP2_WIDTH, 0x0001
        .equiv  IPC16_U2EIP2_MASK, 0x0400
        .equiv  U2EIP2, 0x000A

        .equiv  IPC16_CRCIP0, 0x000C
        .equiv  IPC16_CRCIP0_WIDTH, 0x0001
        .equiv  IPC16_CRCIP0_MASK, 0x1000
        .equiv  CRCIP0, 0x000C

        .equiv  IPC16_CRCIP1, 0x000D
        .equiv  IPC16_CRCIP1_WIDTH, 0x0001
        .equiv  IPC16_CRCIP1_MASK, 0x2000
        .equiv  CRCIP1, 0x000D

        .equiv  IPC16_CRCIP2, 0x000E
        .equiv  IPC16_CRCIP2_WIDTH, 0x0001
        .equiv  IPC16_CRCIP2_MASK, 0x4000
        .equiv  CRCIP2, 0x000E

;----- IPC17 Bits -----------------------------------------------------
        .equiv  IPC17_C1TXIP, 0x0008
        .equiv  IPC17_C1TXIP_WIDTH, 0x0003
        .equiv  IPC17_C1TXIP_MASK, 0x0700

        .equiv  IPC17_C1TXIP0, 0x0008
        .equiv  IPC17_C1TXIP0_WIDTH, 0x0001
        .equiv  IPC17_C1TXIP0_MASK, 0x0100
        .equiv  C1TXIP0, 0x0008

        .equiv  IPC17_C1TXIP1, 0x0009
        .equiv  IPC17_C1TXIP1_WIDTH, 0x0001
        .equiv  IPC17_C1TXIP1_MASK, 0x0200
        .equiv  C1TXIP1, 0x0009

        .equiv  IPC17_C1TXIP2, 0x000A
        .equiv  IPC17_C1TXIP2_WIDTH, 0x0001
        .equiv  IPC17_C1TXIP2_MASK, 0x0400
        .equiv  C1TXIP2, 0x000A

;----- IPC19 Bits -----------------------------------------------------
        .equiv  IPC19_CTMUIP, 0x0004
        .equiv  IPC19_CTMUIP_WIDTH, 0x0003
        .equiv  IPC19_CTMUIP_MASK, 0x0070

;----- IPC23 Bits -----------------------------------------------------
        .equiv  IPC23_PWM1IP, 0x0008
        .equiv  IPC23_PWM1IP_WIDTH, 0x0003
        .equiv  IPC23_PWM1IP_MASK, 0x0700

        .equiv  IPC23_PWM2IP, 0x000C
        .equiv  IPC23_PWM2IP_WIDTH, 0x0003
        .equiv  IPC23_PWM2IP_MASK, 0x7000

        .equiv  IPC23_PWM1IP0, 0x0008
        .equiv  IPC23_PWM1IP0_WIDTH, 0x0001
        .equiv  IPC23_PWM1IP0_MASK, 0x0100
        .equiv  PWM1IP0, 0x0008

        .equiv  IPC23_PWM1IP1, 0x0009
        .equiv  IPC23_PWM1IP1_WIDTH, 0x0001
        .equiv  IPC23_PWM1IP1_MASK, 0x0200
        .equiv  PWM1IP1, 0x0009

        .equiv  IPC23_PWM1IP2, 0x000A
        .equiv  IPC23_PWM1IP2_WIDTH, 0x0001
        .equiv  IPC23_PWM1IP2_MASK, 0x0400
        .equiv  PWM1IP2, 0x000A

        .equiv  IPC23_PWM2IP0, 0x000C
        .equiv  IPC23_PWM2IP0_WIDTH, 0x0001
        .equiv  IPC23_PWM2IP0_MASK, 0x1000
        .equiv  PWM2IP0, 0x000C

        .equiv  IPC23_PWM2IP1, 0x000D
        .equiv  IPC23_PWM2IP1_WIDTH, 0x0001
        .equiv  IPC23_PWM2IP1_MASK, 0x2000
        .equiv  PWM2IP1, 0x000D

        .equiv  IPC23_PWM2IP2, 0x000E
        .equiv  IPC23_PWM2IP2_WIDTH, 0x0001
        .equiv  IPC23_PWM2IP2_MASK, 0x4000
        .equiv  PWM2IP2, 0x000E

;----- IPC24 Bits -----------------------------------------------------
        .equiv  IPC24_PWM3IP, 0x0000
        .equiv  IPC24_PWM3IP_WIDTH, 0x0003
        .equiv  IPC24_PWM3IP_MASK, 0x0007

        .equiv  IPC24_PWM3IP0, 0x0000
        .equiv  IPC24_PWM3IP0_WIDTH, 0x0001
        .equiv  IPC24_PWM3IP0_MASK, 0x0001
        .equiv  PWM3IP0, 0x0000

        .equiv  IPC24_PWM3IP1, 0x0001
        .equiv  IPC24_PWM3IP1_WIDTH, 0x0001
        .equiv  IPC24_PWM3IP1_MASK, 0x0002
        .equiv  PWM3IP1, 0x0001

        .equiv  IPC24_PWM3IP2, 0x0002
        .equiv  IPC24_PWM3IP2_WIDTH, 0x0001
        .equiv  IPC24_PWM3IP2_MASK, 0x0004
        .equiv  PWM3IP2, 0x0002

;----- IPC35 Bits -----------------------------------------------------
        .equiv  IPC35_ICDIP, 0x0008
        .equiv  IPC35_ICDIP_WIDTH, 0x0003
        .equiv  IPC35_ICDIP_MASK, 0x0700

        .equiv  IPC35_JTAGIP, 0x000C
        .equiv  IPC35_JTAGIP_WIDTH, 0x0003
        .equiv  IPC35_JTAGIP_MASK, 0x7000

        .equiv  IPC35_ICDIP0, 0x0008
        .equiv  IPC35_ICDIP0_WIDTH, 0x0001
        .equiv  IPC35_ICDIP0_MASK, 0x0100
        .equiv  ICDIP0, 0x0008

        .equiv  IPC35_ICDIP1, 0x0009
        .equiv  IPC35_ICDIP1_WIDTH, 0x0001
        .equiv  IPC35_ICDIP1_MASK, 0x0200
        .equiv  ICDIP1, 0x0009

        .equiv  IPC35_ICDIP2, 0x000A
        .equiv  IPC35_ICDIP2_WIDTH, 0x0001
        .equiv  IPC35_ICDIP2_MASK, 0x0400
        .equiv  ICDIP2, 0x000A

        .equiv  IPC35_JTAGIP0, 0x000C
        .equiv  IPC35_JTAGIP0_WIDTH, 0x0001
        .equiv  IPC35_JTAGIP0_MASK, 0x1000
        .equiv  JTAGIP0, 0x000C

        .equiv  IPC35_JTAGIP1, 0x000D
        .equiv  IPC35_JTAGIP1_WIDTH, 0x0001
        .equiv  IPC35_JTAGIP1_MASK, 0x2000
        .equiv  JTAGIP1, 0x000D

        .equiv  IPC35_JTAGIP2, 0x000E
        .equiv  IPC35_JTAGIP2_WIDTH, 0x0001
        .equiv  IPC35_JTAGIP2_MASK, 0x4000
        .equiv  JTAGIP2, 0x000E

;----- IPC36 Bits -----------------------------------------------------
        .equiv  IPC36_PTGSTEPIP, 0x0004
        .equiv  IPC36_PTGSTEPIP_WIDTH, 0x0003
        .equiv  IPC36_PTGSTEPIP_MASK, 0x0070

        .equiv  IPC36_PTGWDTIP, 0x0008
        .equiv  IPC36_PTGWDTIP_WIDTH, 0x0003
        .equiv  IPC36_PTGWDTIP_MASK, 0x0700

        .equiv  IPC36_PTG0IP, 0x000C
        .equiv  IPC36_PTG0IP_WIDTH, 0x0003
        .equiv  IPC36_PTG0IP_MASK, 0x7000

;----- IPC37 Bits -----------------------------------------------------
        .equiv  IPC37_PTG1IP, 0x0000
        .equiv  IPC37_PTG1IP_WIDTH, 0x0003
        .equiv  IPC37_PTG1IP_MASK, 0x0007

        .equiv  IPC37_PTG2IP, 0x0004
        .equiv  IPC37_PTG2IP_WIDTH, 0x0003
        .equiv  IPC37_PTG2IP_MASK, 0x0070

        .equiv  IPC37_PTG3IP, 0x0008
        .equiv  IPC37_PTG3IP_WIDTH, 0x0003
        .equiv  IPC37_PTG3IP_MASK, 0x0700

;----- INTCON1 Bits -----------------------------------------------------
        .equiv  INTCON1_OSCFAIL, 0x0001
        .equiv  INTCON1_OSCFAIL_WIDTH, 0x0001
        .equiv  INTCON1_OSCFAIL_MASK, 0x0002
        .equiv  OSCFAIL, 0x0001

        .equiv  INTCON1_STKERR, 0x0002
        .equiv  INTCON1_STKERR_WIDTH, 0x0001
        .equiv  INTCON1_STKERR_MASK, 0x0004
        .equiv  STKERR, 0x0002

        .equiv  INTCON1_ADDRERR, 0x0003
        .equiv  INTCON1_ADDRERR_WIDTH, 0x0001
        .equiv  INTCON1_ADDRERR_MASK, 0x0008
        .equiv  ADDRERR, 0x0003

        .equiv  INTCON1_MATHERR, 0x0004
        .equiv  INTCON1_MATHERR_WIDTH, 0x0001
        .equiv  INTCON1_MATHERR_MASK, 0x0010
        .equiv  MATHERR, 0x0004

        .equiv  INTCON1_DMACERR, 0x0005
        .equiv  INTCON1_DMACERR_WIDTH, 0x0001
        .equiv  INTCON1_DMACERR_MASK, 0x0020
        .equiv  DMACERR, 0x0005

        .equiv  INTCON1_DIV0ERR, 0x0006
        .equiv  INTCON1_DIV0ERR_WIDTH, 0x0001
        .equiv  INTCON1_DIV0ERR_MASK, 0x0040
        .equiv  DIV0ERR, 0x0006

        .equiv  INTCON1_SFTACERR, 0x0007
        .equiv  INTCON1_SFTACERR_WIDTH, 0x0001
        .equiv  INTCON1_SFTACERR_MASK, 0x0080
        .equiv  SFTACERR, 0x0007

        .equiv  INTCON1_COVTE, 0x0008
        .equiv  INTCON1_COVTE_WIDTH, 0x0001
        .equiv  INTCON1_COVTE_MASK, 0x0100
        .equiv  COVTE, 0x0008

        .equiv  INTCON1_OVBTE, 0x0009
        .equiv  INTCON1_OVBTE_WIDTH, 0x0001
        .equiv  INTCON1_OVBTE_MASK, 0x0200
        .equiv  OVBTE, 0x0009

        .equiv  INTCON1_OVATE, 0x000A
        .equiv  INTCON1_OVATE_WIDTH, 0x0001
        .equiv  INTCON1_OVATE_MASK, 0x0400
        .equiv  OVATE, 0x000A

        .equiv  INTCON1_COVBERR, 0x000B
        .equiv  INTCON1_COVBERR_WIDTH, 0x0001
        .equiv  INTCON1_COVBERR_MASK, 0x0800
        .equiv  COVBERR, 0x000B

        .equiv  INTCON1_COVAERR, 0x000C
        .equiv  INTCON1_COVAERR_WIDTH, 0x0001
        .equiv  INTCON1_COVAERR_MASK, 0x1000
        .equiv  COVAERR, 0x000C

        .equiv  INTCON1_OVBERR, 0x000D
        .equiv  INTCON1_OVBERR_WIDTH, 0x0001
        .equiv  INTCON1_OVBERR_MASK, 0x2000
        .equiv  OVBERR, 0x000D

        .equiv  INTCON1_OVAERR, 0x000E
        .equiv  INTCON1_OVAERR_WIDTH, 0x0001
        .equiv  INTCON1_OVAERR_MASK, 0x4000
        .equiv  OVAERR, 0x000E

        .equiv  INTCON1_NSTDIS, 0x000F
        .equiv  INTCON1_NSTDIS_WIDTH, 0x0001
        .equiv  INTCON1_NSTDIS_MASK, 0x8000
        .equiv  NSTDIS, 0x000F

;----- INTCON2 Bits -----------------------------------------------------
        .equiv  INTCON2_INT0EP, 0x0000
        .equiv  INTCON2_INT0EP_WIDTH, 0x0001
        .equiv  INTCON2_INT0EP_MASK, 0x0001
        .equiv  INT0EP, 0x0000

        .equiv  INTCON2_INT1EP, 0x0001
        .equiv  INTCON2_INT1EP_WIDTH, 0x0001
        .equiv  INTCON2_INT1EP_MASK, 0x0002
        .equiv  INT1EP, 0x0001

        .equiv  INTCON2_INT2EP, 0x0002
        .equiv  INTCON2_INT2EP_WIDTH, 0x0001
        .equiv  INTCON2_INT2EP_MASK, 0x0004
        .equiv  INT2EP, 0x0002

        .equiv  INTCON2_SWTRAP, 0x000D
        .equiv  INTCON2_SWTRAP_WIDTH, 0x0001
        .equiv  INTCON2_SWTRAP_MASK, 0x2000
        .equiv  SWTRAP, 0x000D

        .equiv  INTCON2_DISI, 0x000E
        .equiv  INTCON2_DISI_WIDTH, 0x0001
        .equiv  INTCON2_DISI_MASK, 0x4000
        .equiv  DISI, 0x000E

        .equiv  INTCON2_GIE, 0x000F
        .equiv  INTCON2_GIE_WIDTH, 0x0001
        .equiv  INTCON2_GIE_MASK, 0x8000
        .equiv  GIE, 0x000F

;----- INTCON3 Bits -----------------------------------------------------
        .equiv  INTCON3_DOOVR, 0x0004
        .equiv  INTCON3_DOOVR_WIDTH, 0x0001
        .equiv  INTCON3_DOOVR_MASK, 0x0010
        .equiv  DOOVR, 0x0004

        .equiv  INTCON3_DAE, 0x0005
        .equiv  INTCON3_DAE_WIDTH, 0x0001
        .equiv  INTCON3_DAE_MASK, 0x0020
        .equiv  DAE, 0x0005

;----- INTCON4 Bits -----------------------------------------------------
        .equiv  INTCON4_SGHT, 0x0000
        .equiv  INTCON4_SGHT_WIDTH, 0x0001
        .equiv  INTCON4_SGHT_MASK, 0x0001
        .equiv  SGHT, 0x0000

;----- INTTREG Bits -----------------------------------------------------
        .equiv  INTTREG_VECNUM, 0x0000
        .equiv  INTTREG_VECNUM_WIDTH, 0x0008
        .equiv  INTTREG_VECNUM_MASK, 0x00FF

        .equiv  INTTREG_ILR, 0x0008
        .equiv  INTTREG_ILR_WIDTH, 0x0004
        .equiv  INTTREG_ILR_MASK, 0x0F00

        .equiv  INTTREG_VECNUM0, 0x0000
        .equiv  INTTREG_VECNUM0_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM0_MASK, 0x0001
        .equiv  VECNUM0, 0x0000

        .equiv  INTTREG_VECNUM1, 0x0001
        .equiv  INTTREG_VECNUM1_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM1_MASK, 0x0002
        .equiv  VECNUM1, 0x0001

        .equiv  INTTREG_VECNUM2, 0x0002
        .equiv  INTTREG_VECNUM2_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM2_MASK, 0x0004
        .equiv  VECNUM2, 0x0002

        .equiv  INTTREG_VECNUM3, 0x0003
        .equiv  INTTREG_VECNUM3_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM3_MASK, 0x0008
        .equiv  VECNUM3, 0x0003

        .equiv  INTTREG_VECNUM4, 0x0004
        .equiv  INTTREG_VECNUM4_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM4_MASK, 0x0010
        .equiv  VECNUM4, 0x0004

        .equiv  INTTREG_VECNUM5, 0x0005
        .equiv  INTTREG_VECNUM5_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM5_MASK, 0x0020
        .equiv  VECNUM5, 0x0005

        .equiv  INTTREG_VECNUM6, 0x0006
        .equiv  INTTREG_VECNUM6_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM6_MASK, 0x0040
        .equiv  VECNUM6, 0x0006

        .equiv  INTTREG_VECNUM7, 0x0007
        .equiv  INTTREG_VECNUM7_WIDTH, 0x0001
        .equiv  INTTREG_VECNUM7_MASK, 0x0080
        .equiv  VECNUM7, 0x0007

        .equiv  INTTREG_ILR0, 0x0008
        .equiv  INTTREG_ILR0_WIDTH, 0x0001
        .equiv  INTTREG_ILR0_MASK, 0x0100
        .equiv  ILR0, 0x0008

        .equiv  INTTREG_ILR1, 0x0009
        .equiv  INTTREG_ILR1_WIDTH, 0x0001
        .equiv  INTTREG_ILR1_MASK, 0x0200
        .equiv  ILR1, 0x0009

        .equiv  INTTREG_ILR2, 0x000A
        .equiv  INTTREG_ILR2_WIDTH, 0x0001
        .equiv  INTTREG_ILR2_MASK, 0x0400
        .equiv  ILR2, 0x000A

        .equiv  INTTREG_ILR3, 0x000B
        .equiv  INTTREG_ILR3_WIDTH, 0x0001
        .equiv  INTTREG_ILR3_MASK, 0x0800
        .equiv  ILR3, 0x000B

;----- OC1CON1 Bits -----------------------------------------------------
        .equiv  OC1CON1_OCM, 0x0000
        .equiv  OC1CON1_OCM_WIDTH, 0x0003
        .equiv  OC1CON1_OCM_MASK, 0x0007

        .equiv  OC1CON1_TRIGMODE, 0x0003
        .equiv  OC1CON1_TRIGMODE_WIDTH, 0x0001
        .equiv  OC1CON1_TRIGMODE_MASK, 0x0008
        .equiv  TRIGMODE, 0x0003

        .equiv  OC1CON1_OCFLTA, 0x0004
        .equiv  OC1CON1_OCFLTA_WIDTH, 0x0001
        .equiv  OC1CON1_OCFLTA_MASK, 0x0010
        .equiv  OCFLTA, 0x0004

        .equiv  OC1CON1_OCFLTB, 0x0005
        .equiv  OC1CON1_OCFLTB_WIDTH, 0x0001
        .equiv  OC1CON1_OCFLTB_MASK, 0x0020
        .equiv  OCFLTB, 0x0005

        .equiv  OC1CON1_ENFLTA, 0x0007
        .equiv  OC1CON1_ENFLTA_WIDTH, 0x0001
        .equiv  OC1CON1_ENFLTA_MASK, 0x0080
        .equiv  ENFLTA, 0x0007

        .equiv  OC1CON1_ENFLTB, 0x0008
        .equiv  OC1CON1_ENFLTB_WIDTH, 0x0001
        .equiv  OC1CON1_ENFLTB_MASK, 0x0100
        .equiv  ENFLTB, 0x0008

        .equiv  OC1CON1_OCTSEL, 0x000A
        .equiv  OC1CON1_OCTSEL_WIDTH, 0x0003
        .equiv  OC1CON1_OCTSEL_MASK, 0x1C00

        .equiv  OC1CON1_OCSIDL, 0x000D
        .equiv  OC1CON1_OCSIDL_WIDTH, 0x0001
        .equiv  OC1CON1_OCSIDL_MASK, 0x2000
        .equiv  OCSIDL, 0x000D

        .equiv  OC1CON1_OCM0, 0x0000
        .equiv  OC1CON1_OCM0_WIDTH, 0x0001
        .equiv  OC1CON1_OCM0_MASK, 0x0001
        .equiv  OCM0, 0x0000

        .equiv  OC1CON1_OCM1, 0x0001
        .equiv  OC1CON1_OCM1_WIDTH, 0x0001
        .equiv  OC1CON1_OCM1_MASK, 0x0002
        .equiv  OCM1, 0x0001

        .equiv  OC1CON1_OCM2, 0x0002
        .equiv  OC1CON1_OCM2_WIDTH, 0x0001
        .equiv  OC1CON1_OCM2_MASK, 0x0004
        .equiv  OCM2, 0x0002

        .equiv  OC1CON1_OCFLT, 0x0004
        .equiv  OC1CON1_OCFLT_WIDTH, 0x0003
        .equiv  OC1CON1_OCFLT_MASK, 0x0070

        .equiv  OC1CON1_ENFLT, 0x0007
        .equiv  OC1CON1_ENFLT_WIDTH, 0x0003
        .equiv  OC1CON1_ENFLT_MASK, 0x0380

        .equiv  OC1CON1_OCTSEL0, 0x000A
        .equiv  OC1CON1_OCTSEL0_WIDTH, 0x0001
        .equiv  OC1CON1_OCTSEL0_MASK, 0x0400
        .equiv  OCTSEL0, 0x000A

        .equiv  OC1CON1_OCTSEL1, 0x000B
        .equiv  OC1CON1_OCTSEL1_WIDTH, 0x0001
        .equiv  OC1CON1_OCTSEL1_MASK, 0x0800
        .equiv  OCTSEL1, 0x000B

        .equiv  OC1CON1_OCTSEL2, 0x000C
        .equiv  OC1CON1_OCTSEL2_WIDTH, 0x0001
        .equiv  OC1CON1_OCTSEL2_MASK, 0x1000
        .equiv  OCTSEL2, 0x000C

        .equiv  OC1CON1_OCFLT0, 0x0004
        .equiv  OC1CON1_OCFLT0_WIDTH, 0x0001
        .equiv  OC1CON1_OCFLT0_MASK, 0x0010
        .equiv  OCFLT0, 0x0004

        .equiv  OC1CON1_OCFLT1, 0x0005
        .equiv  OC1CON1_OCFLT1_WIDTH, 0x0001
        .equiv  OC1CON1_OCFLT1_MASK, 0x0020
        .equiv  OCFLT1, 0x0005

        .equiv  OC1CON1_ENFLT0, 0x0007
        .equiv  OC1CON1_ENFLT0_WIDTH, 0x0001
        .equiv  OC1CON1_ENFLT0_MASK, 0x0080
        .equiv  ENFLT0, 0x0007

        .equiv  OC1CON1_ENFLT1, 0x0008
        .equiv  OC1CON1_ENFLT1_WIDTH, 0x0001
        .equiv  OC1CON1_ENFLT1_MASK, 0x0100
        .equiv  ENFLT1, 0x0008

;----- OC1CON2 Bits -----------------------------------------------------
        .equiv  OC1CON2_SYNCSEL, 0x0000
        .equiv  OC1CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  OC1CON2_SYNCSEL_MASK, 0x001F

        .equiv  OC1CON2_OCTRIS, 0x0005
        .equiv  OC1CON2_OCTRIS_WIDTH, 0x0001
        .equiv  OC1CON2_OCTRIS_MASK, 0x0020
        .equiv  OCTRIS, 0x0005

        .equiv  OC1CON2_TRIGSTAT, 0x0006
        .equiv  OC1CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  OC1CON2_TRIGSTAT_MASK, 0x0040

        .equiv  OC1CON2_OCTRIG, 0x0007
        .equiv  OC1CON2_OCTRIG_WIDTH, 0x0001
        .equiv  OC1CON2_OCTRIG_MASK, 0x0080
        .equiv  OCTRIG, 0x0007

        .equiv  OC1CON2_OC32, 0x0008
        .equiv  OC1CON2_OC32_WIDTH, 0x0001
        .equiv  OC1CON2_OC32_MASK, 0x0100
        .equiv  OC32, 0x0008

        .equiv  OC1CON2_OCINV, 0x000C
        .equiv  OC1CON2_OCINV_WIDTH, 0x0001
        .equiv  OC1CON2_OCINV_MASK, 0x1000
        .equiv  OCINV, 0x000C

        .equiv  OC1CON2_FLTTRIEN, 0x000D
        .equiv  OC1CON2_FLTTRIEN_WIDTH, 0x0001
        .equiv  OC1CON2_FLTTRIEN_MASK, 0x2000
        .equiv  FLTTRIEN, 0x000D

        .equiv  OC1CON2_FLTOUT, 0x000E
        .equiv  OC1CON2_FLTOUT_WIDTH, 0x0001
        .equiv  OC1CON2_FLTOUT_MASK, 0x4000
        .equiv  FLTOUT, 0x000E

        .equiv  OC1CON2_FLTMD, 0x000F
        .equiv  OC1CON2_FLTMD_WIDTH, 0x0001
        .equiv  OC1CON2_FLTMD_MASK, 0x8000
        .equiv  FLTMD, 0x000F

        .equiv  OC1CON2_SYNCSEL0, 0x0000
        .equiv  OC1CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  OC1CON2_SYNCSEL0_MASK, 0x0001

        .equiv  OC1CON2_SYNCSEL1, 0x0001
        .equiv  OC1CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  OC1CON2_SYNCSEL1_MASK, 0x0002

        .equiv  OC1CON2_SYNCSEL2, 0x0002
        .equiv  OC1CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  OC1CON2_SYNCSEL2_MASK, 0x0004

        .equiv  OC1CON2_SYNCSEL3, 0x0003
        .equiv  OC1CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  OC1CON2_SYNCSEL3_MASK, 0x0008

        .equiv  OC1CON2_SYNCSEL4, 0x0004
        .equiv  OC1CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  OC1CON2_SYNCSEL4_MASK, 0x0010

        .equiv  OC1CON2_FLTMODE, 0x000E
        .equiv  OC1CON2_FLTMODE_WIDTH, 0x0001
        .equiv  OC1CON2_FLTMODE_MASK, 0x4000
        .equiv  FLTMODE, 0x000E

;----- OC2CON1 Bits -----------------------------------------------------
        .equiv  OC2CON1_OCM, 0x0000
        .equiv  OC2CON1_OCM_WIDTH, 0x0003
        .equiv  OC2CON1_OCM_MASK, 0x0007

        .equiv  OC2CON1_TRIGMODE, 0x0003
        .equiv  OC2CON1_TRIGMODE_WIDTH, 0x0001
        .equiv  OC2CON1_TRIGMODE_MASK, 0x0008

        .equiv  OC2CON1_OCFLTA, 0x0004
        .equiv  OC2CON1_OCFLTA_WIDTH, 0x0001
        .equiv  OC2CON1_OCFLTA_MASK, 0x0010

        .equiv  OC2CON1_OCFLTB, 0x0005
        .equiv  OC2CON1_OCFLTB_WIDTH, 0x0001
        .equiv  OC2CON1_OCFLTB_MASK, 0x0020

        .equiv  OC2CON1_ENFLTA, 0x0007
        .equiv  OC2CON1_ENFLTA_WIDTH, 0x0001
        .equiv  OC2CON1_ENFLTA_MASK, 0x0080

        .equiv  OC2CON1_ENFLTB, 0x0008
        .equiv  OC2CON1_ENFLTB_WIDTH, 0x0001
        .equiv  OC2CON1_ENFLTB_MASK, 0x0100

        .equiv  OC2CON1_OCTSEL, 0x000A
        .equiv  OC2CON1_OCTSEL_WIDTH, 0x0003
        .equiv  OC2CON1_OCTSEL_MASK, 0x1C00

        .equiv  OC2CON1_OCSIDL, 0x000D
        .equiv  OC2CON1_OCSIDL_WIDTH, 0x0001
        .equiv  OC2CON1_OCSIDL_MASK, 0x2000

        .equiv  OC2CON1_OCM0, 0x0000
        .equiv  OC2CON1_OCM0_WIDTH, 0x0001
        .equiv  OC2CON1_OCM0_MASK, 0x0001

        .equiv  OC2CON1_OCM1, 0x0001
        .equiv  OC2CON1_OCM1_WIDTH, 0x0001
        .equiv  OC2CON1_OCM1_MASK, 0x0002

        .equiv  OC2CON1_OCM2, 0x0002
        .equiv  OC2CON1_OCM2_WIDTH, 0x0001
        .equiv  OC2CON1_OCM2_MASK, 0x0004

        .equiv  OC2CON1_OCFLT, 0x0004
        .equiv  OC2CON1_OCFLT_WIDTH, 0x0003
        .equiv  OC2CON1_OCFLT_MASK, 0x0070

        .equiv  OC2CON1_ENFLT, 0x0007
        .equiv  OC2CON1_ENFLT_WIDTH, 0x0003
        .equiv  OC2CON1_ENFLT_MASK, 0x0380

        .equiv  OC2CON1_OCTSEL0, 0x000A
        .equiv  OC2CON1_OCTSEL0_WIDTH, 0x0001
        .equiv  OC2CON1_OCTSEL0_MASK, 0x0400

        .equiv  OC2CON1_OCTSEL1, 0x000B
        .equiv  OC2CON1_OCTSEL1_WIDTH, 0x0001
        .equiv  OC2CON1_OCTSEL1_MASK, 0x0800

        .equiv  OC2CON1_OCTSEL2, 0x000C
        .equiv  OC2CON1_OCTSEL2_WIDTH, 0x0001
        .equiv  OC2CON1_OCTSEL2_MASK, 0x1000

        .equiv  OC2CON1_OCFLT0, 0x0004
        .equiv  OC2CON1_OCFLT0_WIDTH, 0x0001
        .equiv  OC2CON1_OCFLT0_MASK, 0x0010

        .equiv  OC2CON1_OCFLT1, 0x0005
        .equiv  OC2CON1_OCFLT1_WIDTH, 0x0001
        .equiv  OC2CON1_OCFLT1_MASK, 0x0020

        .equiv  OC2CON1_ENFLT0, 0x0007
        .equiv  OC2CON1_ENFLT0_WIDTH, 0x0001
        .equiv  OC2CON1_ENFLT0_MASK, 0x0080

        .equiv  OC2CON1_ENFLT1, 0x0008
        .equiv  OC2CON1_ENFLT1_WIDTH, 0x0001
        .equiv  OC2CON1_ENFLT1_MASK, 0x0100

;----- OC2CON2 Bits -----------------------------------------------------
        .equiv  OC2CON2_SYNCSEL, 0x0000
        .equiv  OC2CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  OC2CON2_SYNCSEL_MASK, 0x001F

        .equiv  OC2CON2_OCTRIS, 0x0005
        .equiv  OC2CON2_OCTRIS_WIDTH, 0x0001
        .equiv  OC2CON2_OCTRIS_MASK, 0x0020

        .equiv  OC2CON2_TRIGSTAT, 0x0006
        .equiv  OC2CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  OC2CON2_TRIGSTAT_MASK, 0x0040

        .equiv  OC2CON2_OCTRIG, 0x0007
        .equiv  OC2CON2_OCTRIG_WIDTH, 0x0001
        .equiv  OC2CON2_OCTRIG_MASK, 0x0080

        .equiv  OC2CON2_OC32, 0x0008
        .equiv  OC2CON2_OC32_WIDTH, 0x0001
        .equiv  OC2CON2_OC32_MASK, 0x0100

        .equiv  OC2CON2_OCINV, 0x000C
        .equiv  OC2CON2_OCINV_WIDTH, 0x0001
        .equiv  OC2CON2_OCINV_MASK, 0x1000

        .equiv  OC2CON2_FLTTRIEN, 0x000D
        .equiv  OC2CON2_FLTTRIEN_WIDTH, 0x0001
        .equiv  OC2CON2_FLTTRIEN_MASK, 0x2000

        .equiv  OC2CON2_FLTOUT, 0x000E
        .equiv  OC2CON2_FLTOUT_WIDTH, 0x0001
        .equiv  OC2CON2_FLTOUT_MASK, 0x4000

        .equiv  OC2CON2_FLTMD, 0x000F
        .equiv  OC2CON2_FLTMD_WIDTH, 0x0001
        .equiv  OC2CON2_FLTMD_MASK, 0x8000

        .equiv  OC2CON2_SYNCSEL0, 0x0000
        .equiv  OC2CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  OC2CON2_SYNCSEL0_MASK, 0x0001

        .equiv  OC2CON2_SYNCSEL1, 0x0001
        .equiv  OC2CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  OC2CON2_SYNCSEL1_MASK, 0x0002

        .equiv  OC2CON2_SYNCSEL2, 0x0002
        .equiv  OC2CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  OC2CON2_SYNCSEL2_MASK, 0x0004

        .equiv  OC2CON2_SYNCSEL3, 0x0003
        .equiv  OC2CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  OC2CON2_SYNCSEL3_MASK, 0x0008

        .equiv  OC2CON2_SYNCSEL4, 0x0004
        .equiv  OC2CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  OC2CON2_SYNCSEL4_MASK, 0x0010

        .equiv  OC2CON2_FLTMODE, 0x000E
        .equiv  OC2CON2_FLTMODE_WIDTH, 0x0001
        .equiv  OC2CON2_FLTMODE_MASK, 0x4000

;----- OC3CON1 Bits -----------------------------------------------------
        .equiv  OC3CON1_OCM, 0x0000
        .equiv  OC3CON1_OCM_WIDTH, 0x0003
        .equiv  OC3CON1_OCM_MASK, 0x0007

        .equiv  OC3CON1_TRIGMODE, 0x0003
        .equiv  OC3CON1_TRIGMODE_WIDTH, 0x0001
        .equiv  OC3CON1_TRIGMODE_MASK, 0x0008

        .equiv  OC3CON1_OCFLTA, 0x0004
        .equiv  OC3CON1_OCFLTA_WIDTH, 0x0001
        .equiv  OC3CON1_OCFLTA_MASK, 0x0010

        .equiv  OC3CON1_OCFLTB, 0x0005
        .equiv  OC3CON1_OCFLTB_WIDTH, 0x0001
        .equiv  OC3CON1_OCFLTB_MASK, 0x0020

        .equiv  OC3CON1_ENFLTA, 0x0007
        .equiv  OC3CON1_ENFLTA_WIDTH, 0x0001
        .equiv  OC3CON1_ENFLTA_MASK, 0x0080

        .equiv  OC3CON1_ENFLTB, 0x0008
        .equiv  OC3CON1_ENFLTB_WIDTH, 0x0001
        .equiv  OC3CON1_ENFLTB_MASK, 0x0100

        .equiv  OC3CON1_OCTSEL, 0x000A
        .equiv  OC3CON1_OCTSEL_WIDTH, 0x0003
        .equiv  OC3CON1_OCTSEL_MASK, 0x1C00

        .equiv  OC3CON1_OCSIDL, 0x000D
        .equiv  OC3CON1_OCSIDL_WIDTH, 0x0001
        .equiv  OC3CON1_OCSIDL_MASK, 0x2000

        .equiv  OC3CON1_OCM0, 0x0000
        .equiv  OC3CON1_OCM0_WIDTH, 0x0001
        .equiv  OC3CON1_OCM0_MASK, 0x0001

        .equiv  OC3CON1_OCM1, 0x0001
        .equiv  OC3CON1_OCM1_WIDTH, 0x0001
        .equiv  OC3CON1_OCM1_MASK, 0x0002

        .equiv  OC3CON1_OCM2, 0x0002
        .equiv  OC3CON1_OCM2_WIDTH, 0x0001
        .equiv  OC3CON1_OCM2_MASK, 0x0004

        .equiv  OC3CON1_OCFLT, 0x0004
        .equiv  OC3CON1_OCFLT_WIDTH, 0x0003
        .equiv  OC3CON1_OCFLT_MASK, 0x0070

        .equiv  OC3CON1_ENFLT, 0x0007
        .equiv  OC3CON1_ENFLT_WIDTH, 0x0003
        .equiv  OC3CON1_ENFLT_MASK, 0x0380

        .equiv  OC3CON1_OCTSEL0, 0x000A
        .equiv  OC3CON1_OCTSEL0_WIDTH, 0x0001
        .equiv  OC3CON1_OCTSEL0_MASK, 0x0400

        .equiv  OC3CON1_OCTSEL1, 0x000B
        .equiv  OC3CON1_OCTSEL1_WIDTH, 0x0001
        .equiv  OC3CON1_OCTSEL1_MASK, 0x0800

        .equiv  OC3CON1_OCTSEL2, 0x000C
        .equiv  OC3CON1_OCTSEL2_WIDTH, 0x0001
        .equiv  OC3CON1_OCTSEL2_MASK, 0x1000

        .equiv  OC3CON1_OCFLT0, 0x0004
        .equiv  OC3CON1_OCFLT0_WIDTH, 0x0001
        .equiv  OC3CON1_OCFLT0_MASK, 0x0010

        .equiv  OC3CON1_OCFLT1, 0x0005
        .equiv  OC3CON1_OCFLT1_WIDTH, 0x0001
        .equiv  OC3CON1_OCFLT1_MASK, 0x0020

        .equiv  OC3CON1_ENFLT0, 0x0007
        .equiv  OC3CON1_ENFLT0_WIDTH, 0x0001
        .equiv  OC3CON1_ENFLT0_MASK, 0x0080

        .equiv  OC3CON1_ENFLT1, 0x0008
        .equiv  OC3CON1_ENFLT1_WIDTH, 0x0001
        .equiv  OC3CON1_ENFLT1_MASK, 0x0100

;----- OC3CON2 Bits -----------------------------------------------------
        .equiv  OC3CON2_SYNCSEL, 0x0000
        .equiv  OC3CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  OC3CON2_SYNCSEL_MASK, 0x001F

        .equiv  OC3CON2_OCTRIS, 0x0005
        .equiv  OC3CON2_OCTRIS_WIDTH, 0x0001
        .equiv  OC3CON2_OCTRIS_MASK, 0x0020

        .equiv  OC3CON2_TRIGSTAT, 0x0006
        .equiv  OC3CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  OC3CON2_TRIGSTAT_MASK, 0x0040

        .equiv  OC3CON2_OCTRIG, 0x0007
        .equiv  OC3CON2_OCTRIG_WIDTH, 0x0001
        .equiv  OC3CON2_OCTRIG_MASK, 0x0080

        .equiv  OC3CON2_OC32, 0x0008
        .equiv  OC3CON2_OC32_WIDTH, 0x0001
        .equiv  OC3CON2_OC32_MASK, 0x0100

        .equiv  OC3CON2_OCINV, 0x000C
        .equiv  OC3CON2_OCINV_WIDTH, 0x0001
        .equiv  OC3CON2_OCINV_MASK, 0x1000

        .equiv  OC3CON2_FLTTRIEN, 0x000D
        .equiv  OC3CON2_FLTTRIEN_WIDTH, 0x0001
        .equiv  OC3CON2_FLTTRIEN_MASK, 0x2000

        .equiv  OC3CON2_FLTOUT, 0x000E
        .equiv  OC3CON2_FLTOUT_WIDTH, 0x0001
        .equiv  OC3CON2_FLTOUT_MASK, 0x4000

        .equiv  OC3CON2_FLTMD, 0x000F
        .equiv  OC3CON2_FLTMD_WIDTH, 0x0001
        .equiv  OC3CON2_FLTMD_MASK, 0x8000

        .equiv  OC3CON2_SYNCSEL0, 0x0000
        .equiv  OC3CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  OC3CON2_SYNCSEL0_MASK, 0x0001

        .equiv  OC3CON2_SYNCSEL1, 0x0001
        .equiv  OC3CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  OC3CON2_SYNCSEL1_MASK, 0x0002

        .equiv  OC3CON2_SYNCSEL2, 0x0002
        .equiv  OC3CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  OC3CON2_SYNCSEL2_MASK, 0x0004

        .equiv  OC3CON2_SYNCSEL3, 0x0003
        .equiv  OC3CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  OC3CON2_SYNCSEL3_MASK, 0x0008

        .equiv  OC3CON2_SYNCSEL4, 0x0004
        .equiv  OC3CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  OC3CON2_SYNCSEL4_MASK, 0x0010

        .equiv  OC3CON2_FLTMODE, 0x000E
        .equiv  OC3CON2_FLTMODE_WIDTH, 0x0001
        .equiv  OC3CON2_FLTMODE_MASK, 0x4000

;----- OC4CON1 Bits -----------------------------------------------------
        .equiv  OC4CON1_OCM, 0x0000
        .equiv  OC4CON1_OCM_WIDTH, 0x0003
        .equiv  OC4CON1_OCM_MASK, 0x0007

        .equiv  OC4CON1_TRIGMODE, 0x0003
        .equiv  OC4CON1_TRIGMODE_WIDTH, 0x0001
        .equiv  OC4CON1_TRIGMODE_MASK, 0x0008

        .equiv  OC4CON1_OCFLTA, 0x0004
        .equiv  OC4CON1_OCFLTA_WIDTH, 0x0001
        .equiv  OC4CON1_OCFLTA_MASK, 0x0010

        .equiv  OC4CON1_OCFLTB, 0x0005
        .equiv  OC4CON1_OCFLTB_WIDTH, 0x0001
        .equiv  OC4CON1_OCFLTB_MASK, 0x0020

        .equiv  OC4CON1_ENFLTA, 0x0007
        .equiv  OC4CON1_ENFLTA_WIDTH, 0x0001
        .equiv  OC4CON1_ENFLTA_MASK, 0x0080

        .equiv  OC4CON1_ENFLTB, 0x0008
        .equiv  OC4CON1_ENFLTB_WIDTH, 0x0001
        .equiv  OC4CON1_ENFLTB_MASK, 0x0100

        .equiv  OC4CON1_OCTSEL, 0x000A
        .equiv  OC4CON1_OCTSEL_WIDTH, 0x0003
        .equiv  OC4CON1_OCTSEL_MASK, 0x1C00

        .equiv  OC4CON1_OCSIDL, 0x000D
        .equiv  OC4CON1_OCSIDL_WIDTH, 0x0001
        .equiv  OC4CON1_OCSIDL_MASK, 0x2000

        .equiv  OC4CON1_OCM0, 0x0000
        .equiv  OC4CON1_OCM0_WIDTH, 0x0001
        .equiv  OC4CON1_OCM0_MASK, 0x0001

        .equiv  OC4CON1_OCM1, 0x0001
        .equiv  OC4CON1_OCM1_WIDTH, 0x0001
        .equiv  OC4CON1_OCM1_MASK, 0x0002

        .equiv  OC4CON1_OCM2, 0x0002
        .equiv  OC4CON1_OCM2_WIDTH, 0x0001
        .equiv  OC4CON1_OCM2_MASK, 0x0004

        .equiv  OC4CON1_OCFLT, 0x0004
        .equiv  OC4CON1_OCFLT_WIDTH, 0x0003
        .equiv  OC4CON1_OCFLT_MASK, 0x0070

        .equiv  OC4CON1_ENFLT, 0x0007
        .equiv  OC4CON1_ENFLT_WIDTH, 0x0003
        .equiv  OC4CON1_ENFLT_MASK, 0x0380

        .equiv  OC4CON1_OCTSEL0, 0x000A
        .equiv  OC4CON1_OCTSEL0_WIDTH, 0x0001
        .equiv  OC4CON1_OCTSEL0_MASK, 0x0400

        .equiv  OC4CON1_OCTSEL1, 0x000B
        .equiv  OC4CON1_OCTSEL1_WIDTH, 0x0001
        .equiv  OC4CON1_OCTSEL1_MASK, 0x0800

        .equiv  OC4CON1_OCTSEL2, 0x000C
        .equiv  OC4CON1_OCTSEL2_WIDTH, 0x0001
        .equiv  OC4CON1_OCTSEL2_MASK, 0x1000

        .equiv  OC4CON1_OCFLT0, 0x0004
        .equiv  OC4CON1_OCFLT0_WIDTH, 0x0001
        .equiv  OC4CON1_OCFLT0_MASK, 0x0010

        .equiv  OC4CON1_OCFLT1, 0x0005
        .equiv  OC4CON1_OCFLT1_WIDTH, 0x0001
        .equiv  OC4CON1_OCFLT1_MASK, 0x0020

        .equiv  OC4CON1_ENFLT0, 0x0007
        .equiv  OC4CON1_ENFLT0_WIDTH, 0x0001
        .equiv  OC4CON1_ENFLT0_MASK, 0x0080

        .equiv  OC4CON1_ENFLT1, 0x0008
        .equiv  OC4CON1_ENFLT1_WIDTH, 0x0001
        .equiv  OC4CON1_ENFLT1_MASK, 0x0100

;----- OC4CON2 Bits -----------------------------------------------------
        .equiv  OC4CON2_SYNCSEL, 0x0000
        .equiv  OC4CON2_SYNCSEL_WIDTH, 0x0005
        .equiv  OC4CON2_SYNCSEL_MASK, 0x001F

        .equiv  OC4CON2_OCTRIS, 0x0005
        .equiv  OC4CON2_OCTRIS_WIDTH, 0x0001
        .equiv  OC4CON2_OCTRIS_MASK, 0x0020

        .equiv  OC4CON2_TRIGSTAT, 0x0006
        .equiv  OC4CON2_TRIGSTAT_WIDTH, 0x0001
        .equiv  OC4CON2_TRIGSTAT_MASK, 0x0040

        .equiv  OC4CON2_OCTRIG, 0x0007
        .equiv  OC4CON2_OCTRIG_WIDTH, 0x0001
        .equiv  OC4CON2_OCTRIG_MASK, 0x0080

        .equiv  OC4CON2_OC32, 0x0008
        .equiv  OC4CON2_OC32_WIDTH, 0x0001
        .equiv  OC4CON2_OC32_MASK, 0x0100

        .equiv  OC4CON2_OCINV, 0x000C
        .equiv  OC4CON2_OCINV_WIDTH, 0x0001
        .equiv  OC4CON2_OCINV_MASK, 0x1000

        .equiv  OC4CON2_FLTTRIEN, 0x000D
        .equiv  OC4CON2_FLTTRIEN_WIDTH, 0x0001
        .equiv  OC4CON2_FLTTRIEN_MASK, 0x2000

        .equiv  OC4CON2_FLTOUT, 0x000E
        .equiv  OC4CON2_FLTOUT_WIDTH, 0x0001
        .equiv  OC4CON2_FLTOUT_MASK, 0x4000

        .equiv  OC4CON2_FLTMD, 0x000F
        .equiv  OC4CON2_FLTMD_WIDTH, 0x0001
        .equiv  OC4CON2_FLTMD_MASK, 0x8000

        .equiv  OC4CON2_SYNCSEL0, 0x0000
        .equiv  OC4CON2_SYNCSEL0_WIDTH, 0x0001
        .equiv  OC4CON2_SYNCSEL0_MASK, 0x0001

        .equiv  OC4CON2_SYNCSEL1, 0x0001
        .equiv  OC4CON2_SYNCSEL1_WIDTH, 0x0001
        .equiv  OC4CON2_SYNCSEL1_MASK, 0x0002

        .equiv  OC4CON2_SYNCSEL2, 0x0002
        .equiv  OC4CON2_SYNCSEL2_WIDTH, 0x0001
        .equiv  OC4CON2_SYNCSEL2_MASK, 0x0004

        .equiv  OC4CON2_SYNCSEL3, 0x0003
        .equiv  OC4CON2_SYNCSEL3_WIDTH, 0x0001
        .equiv  OC4CON2_SYNCSEL3_MASK, 0x0008

        .equiv  OC4CON2_SYNCSEL4, 0x0004
        .equiv  OC4CON2_SYNCSEL4_WIDTH, 0x0001
        .equiv  OC4CON2_SYNCSEL4_MASK, 0x0010

        .equiv  OC4CON2_FLTMODE, 0x000E
        .equiv  OC4CON2_FLTMODE_WIDTH, 0x0001
        .equiv  OC4CON2_FLTMODE_MASK, 0x4000

;----- CMSTAT Bits -----------------------------------------------------
        .equiv  CMSTAT_C1OUT, 0x0000
        .equiv  CMSTAT_C1OUT_WIDTH, 0x0001
        .equiv  CMSTAT_C1OUT_MASK, 0x0001
        .equiv  C1OUT, 0x0000

        .equiv  CMSTAT_C2OUT, 0x0001
        .equiv  CMSTAT_C2OUT_WIDTH, 0x0001
        .equiv  CMSTAT_C2OUT_MASK, 0x0002
        .equiv  C2OUT, 0x0001

        .equiv  CMSTAT_C3OUT, 0x0002
        .equiv  CMSTAT_C3OUT_WIDTH, 0x0001
        .equiv  CMSTAT_C3OUT_MASK, 0x0004
        .equiv  C3OUT, 0x0002

        .equiv  CMSTAT_C4OUT, 0x0003
        .equiv  CMSTAT_C4OUT_WIDTH, 0x0001
        .equiv  CMSTAT_C4OUT_MASK, 0x0008
        .equiv  C4OUT, 0x0003

        .equiv  CMSTAT_C1EVT, 0x0008
        .equiv  CMSTAT_C1EVT_WIDTH, 0x0001
        .equiv  CMSTAT_C1EVT_MASK, 0x0100
        .equiv  C1EVT, 0x0008

        .equiv  CMSTAT_C2EVT, 0x0009
        .equiv  CMSTAT_C2EVT_WIDTH, 0x0001
        .equiv  CMSTAT_C2EVT_MASK, 0x0200
        .equiv  C2EVT, 0x0009

        .equiv  CMSTAT_C3EVT, 0x000A
        .equiv  CMSTAT_C3EVT_WIDTH, 0x0001
        .equiv  CMSTAT_C3EVT_MASK, 0x0400
        .equiv  C3EVT, 0x000A

        .equiv  CMSTAT_C4EVT, 0x000B
        .equiv  CMSTAT_C4EVT_WIDTH, 0x0001
        .equiv  CMSTAT_C4EVT_MASK, 0x0800
        .equiv  C4EVT, 0x000B

        .equiv  CMSTAT_PSIDL, 0x000F
        .equiv  CMSTAT_PSIDL_WIDTH, 0x0001
        .equiv  CMSTAT_PSIDL_MASK, 0x8000
        .equiv  PSIDL, 0x000F

;----- CVRCON Bits -----------------------------------------------------
        .equiv  CVRCON_CVR, 0x0000
        .equiv  CVRCON_CVR_WIDTH, 0x0004
        .equiv  CVRCON_CVR_MASK, 0x000F

        .equiv  CVRCON_CVRSS, 0x0004
        .equiv  CVRCON_CVRSS_WIDTH, 0x0001
        .equiv  CVRCON_CVRSS_MASK, 0x0010
        .equiv  CVRSS, 0x0004

        .equiv  CVRCON_CVRR, 0x0005
        .equiv  CVRCON_CVRR_WIDTH, 0x0001
        .equiv  CVRCON_CVRR_MASK, 0x0020
        .equiv  CVRR, 0x0005

        .equiv  CVRCON_CVROE, 0x0006
        .equiv  CVRCON_CVROE_WIDTH, 0x0001
        .equiv  CVRCON_CVROE_MASK, 0x0040
        .equiv  CVROE, 0x0006

        .equiv  CVRCON_CVREN, 0x0007
        .equiv  CVRCON_CVREN_WIDTH, 0x0001
        .equiv  CVRCON_CVREN_MASK, 0x0080
        .equiv  CVREN, 0x0007

        .equiv  CVRCON_VREFSEL, 0x000A
        .equiv  CVRCON_VREFSEL_WIDTH, 0x0001
        .equiv  CVRCON_VREFSEL_MASK, 0x0400
        .equiv  VREFSEL, 0x000A

        .equiv  CVRCON_CVR2OE, 0x000E
        .equiv  CVRCON_CVR2OE_WIDTH, 0x0001
        .equiv  CVRCON_CVR2OE_MASK, 0x4000
        .equiv  CVR2OE, 0x000E

        .equiv  CVRCON_CVR0, 0x0000
        .equiv  CVRCON_CVR0_WIDTH, 0x0001
        .equiv  CVRCON_CVR0_MASK, 0x0001
        .equiv  CVR0, 0x0000

        .equiv  CVRCON_CVR1, 0x0001
        .equiv  CVRCON_CVR1_WIDTH, 0x0001
        .equiv  CVRCON_CVR1_MASK, 0x0002
        .equiv  CVR1, 0x0001

        .equiv  CVRCON_CVR2, 0x0002
        .equiv  CVRCON_CVR2_WIDTH, 0x0001
        .equiv  CVRCON_CVR2_MASK, 0x0004
        .equiv  CVR2, 0x0002

        .equiv  CVRCON_CVR3, 0x0003
        .equiv  CVRCON_CVR3_WIDTH, 0x0001
        .equiv  CVRCON_CVR3_MASK, 0x0008
        .equiv  CVR3, 0x0003

        .equiv  CVRCON_CVR1OE, 0x0006
        .equiv  CVRCON_CVR1OE_WIDTH, 0x0001
        .equiv  CVRCON_CVR1OE_MASK, 0x0040
        .equiv  CVR1OE, 0x0006

;----- CM1CON Bits -----------------------------------------------------
        .equiv  CM1CON_CCH, 0x0000
        .equiv  CM1CON_CCH_WIDTH, 0x0002
        .equiv  CM1CON_CCH_MASK, 0x0003

        .equiv  CM1CON_CREF, 0x0004
        .equiv  CM1CON_CREF_WIDTH, 0x0001
        .equiv  CM1CON_CREF_MASK, 0x0010
        .equiv  CREF, 0x0004

        .equiv  CM1CON_EVPOL, 0x0006
        .equiv  CM1CON_EVPOL_WIDTH, 0x0002
        .equiv  CM1CON_EVPOL_MASK, 0x00C0

        .equiv  CM1CON_COUT, 0x0008
        .equiv  CM1CON_COUT_WIDTH, 0x0001
        .equiv  CM1CON_COUT_MASK, 0x0100
        .equiv  COUT, 0x0008

        .equiv  CM1CON_CEVT, 0x0009
        .equiv  CM1CON_CEVT_WIDTH, 0x0001
        .equiv  CM1CON_CEVT_MASK, 0x0200
        .equiv  CEVT, 0x0009

        .equiv  CM1CON_OPMODE_CM1CON, 0x000A
        .equiv  CM1CON_OPMODE_CM1CON_WIDTH, 0x0001
        .equiv  CM1CON_OPMODE_CM1CON_MASK, 0x0400
        .equiv  OPMODE_CM1CON, 0x000A

        .equiv  CM1CON_CPOL, 0x000D
        .equiv  CM1CON_CPOL_WIDTH, 0x0001
        .equiv  CM1CON_CPOL_MASK, 0x2000
        .equiv  CPOL, 0x000D

        .equiv  CM1CON_COE, 0x000E
        .equiv  CM1CON_COE_WIDTH, 0x0001
        .equiv  CM1CON_COE_MASK, 0x4000
        .equiv  COE, 0x000E

        .equiv  CM1CON_CON, 0x000F
        .equiv  CM1CON_CON_WIDTH, 0x0001
        .equiv  CM1CON_CON_MASK, 0x8000
        .equiv  CON, 0x000F

        .equiv  CM1CON_CCH0, 0x0000
        .equiv  CM1CON_CCH0_WIDTH, 0x0001
        .equiv  CM1CON_CCH0_MASK, 0x0001
        .equiv  CCH0, 0x0000

        .equiv  CM1CON_CCH1, 0x0001
        .equiv  CM1CON_CCH1_WIDTH, 0x0001
        .equiv  CM1CON_CCH1_MASK, 0x0002
        .equiv  CCH1, 0x0001

        .equiv  CM1CON_EVPOL0, 0x0006
        .equiv  CM1CON_EVPOL0_WIDTH, 0x0001
        .equiv  CM1CON_EVPOL0_MASK, 0x0040
        .equiv  EVPOL0, 0x0006

        .equiv  CM1CON_EVPOL1, 0x0007
        .equiv  CM1CON_EVPOL1_WIDTH, 0x0001
        .equiv  CM1CON_EVPOL1_MASK, 0x0080
        .equiv  EVPOL1, 0x0007

        .equiv  CM1CON_CEN, 0x000F
        .equiv  CM1CON_CEN_WIDTH, 0x0001
        .equiv  CM1CON_CEN_MASK, 0x8000
        .equiv  CEN, 0x000F

;----- CM1MSKSRC Bits -----------------------------------------------------
        .equiv  CM1MSKSRC_SELSRCA, 0x0000
        .equiv  CM1MSKSRC_SELSRCA_WIDTH, 0x0004
        .equiv  CM1MSKSRC_SELSRCA_MASK, 0x000F

        .equiv  CM1MSKSRC_SELSRCB, 0x0004
        .equiv  CM1MSKSRC_SELSRCB_WIDTH, 0x0004
        .equiv  CM1MSKSRC_SELSRCB_MASK, 0x00F0

        .equiv  CM1MSKSRC_SELSRCC, 0x0008
        .equiv  CM1MSKSRC_SELSRCC_WIDTH, 0x0004
        .equiv  CM1MSKSRC_SELSRCC_MASK, 0x0F00

        .equiv  CM1MSKSRC_SELSRCA0, 0x0000
        .equiv  CM1MSKSRC_SELSRCA0_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCA0_MASK, 0x0001
        .equiv  SELSRCA0, 0x0000

        .equiv  CM1MSKSRC_SELSRCA1, 0x0001
        .equiv  CM1MSKSRC_SELSRCA1_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCA1_MASK, 0x0002
        .equiv  SELSRCA1, 0x0001

        .equiv  CM1MSKSRC_SELSRCA2, 0x0002
        .equiv  CM1MSKSRC_SELSRCA2_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCA2_MASK, 0x0004
        .equiv  SELSRCA2, 0x0002

        .equiv  CM1MSKSRC_SELSRCA3, 0x0003
        .equiv  CM1MSKSRC_SELSRCA3_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCA3_MASK, 0x0008
        .equiv  SELSRCA3, 0x0003

        .equiv  CM1MSKSRC_SELSRCB0, 0x0004
        .equiv  CM1MSKSRC_SELSRCB0_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCB0_MASK, 0x0010
        .equiv  SELSRCB0, 0x0004

        .equiv  CM1MSKSRC_SELSRCB1, 0x0005
        .equiv  CM1MSKSRC_SELSRCB1_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCB1_MASK, 0x0020
        .equiv  SELSRCB1, 0x0005

        .equiv  CM1MSKSRC_SELSRCB2, 0x0006
        .equiv  CM1MSKSRC_SELSRCB2_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCB2_MASK, 0x0040
        .equiv  SELSRCB2, 0x0006

        .equiv  CM1MSKSRC_SELSRCB3, 0x0007
        .equiv  CM1MSKSRC_SELSRCB3_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCB3_MASK, 0x0080
        .equiv  SELSRCB3, 0x0007

        .equiv  CM1MSKSRC_SELSRCC0, 0x0008
        .equiv  CM1MSKSRC_SELSRCC0_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCC0_MASK, 0x0100
        .equiv  SELSRCC0, 0x0008

        .equiv  CM1MSKSRC_SELSRCC1, 0x0009
        .equiv  CM1MSKSRC_SELSRCC1_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCC1_MASK, 0x0200
        .equiv  SELSRCC1, 0x0009

        .equiv  CM1MSKSRC_SELSRCC2, 0x000A
        .equiv  CM1MSKSRC_SELSRCC2_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCC2_MASK, 0x0400
        .equiv  SELSRCC2, 0x000A

        .equiv  CM1MSKSRC_SELSRCC3, 0x000B
        .equiv  CM1MSKSRC_SELSRCC3_WIDTH, 0x0001
        .equiv  CM1MSKSRC_SELSRCC3_MASK, 0x0800
        .equiv  SELSRCC3, 0x000B

;----- CM1MSKCON Bits -----------------------------------------------------
        .equiv  CM1MSKCON_AANEN, 0x0000
        .equiv  CM1MSKCON_AANEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_AANEN_MASK, 0x0001
        .equiv  AANEN, 0x0000

        .equiv  CM1MSKCON_AAEN, 0x0001
        .equiv  CM1MSKCON_AAEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_AAEN_MASK, 0x0002
        .equiv  AAEN, 0x0001

        .equiv  CM1MSKCON_ABNEN, 0x0002
        .equiv  CM1MSKCON_ABNEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_ABNEN_MASK, 0x0004
        .equiv  ABNEN, 0x0002

        .equiv  CM1MSKCON_ABEN, 0x0003
        .equiv  CM1MSKCON_ABEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_ABEN_MASK, 0x0008
        .equiv  ABEN, 0x0003

        .equiv  CM1MSKCON_ACNEN, 0x0004
        .equiv  CM1MSKCON_ACNEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_ACNEN_MASK, 0x0010
        .equiv  ACNEN, 0x0004

        .equiv  CM1MSKCON_ACEN, 0x0005
        .equiv  CM1MSKCON_ACEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_ACEN_MASK, 0x0020
        .equiv  ACEN, 0x0005

        .equiv  CM1MSKCON_PAGS, 0x0006
        .equiv  CM1MSKCON_PAGS_WIDTH, 0x0001
        .equiv  CM1MSKCON_PAGS_MASK, 0x0040
        .equiv  PAGS, 0x0006

        .equiv  CM1MSKCON_NAGS, 0x0007
        .equiv  CM1MSKCON_NAGS_WIDTH, 0x0001
        .equiv  CM1MSKCON_NAGS_MASK, 0x0080
        .equiv  NAGS, 0x0007

        .equiv  CM1MSKCON_OANEN, 0x0008
        .equiv  CM1MSKCON_OANEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OANEN_MASK, 0x0100
        .equiv  OANEN, 0x0008

        .equiv  CM1MSKCON_OAEN, 0x0009
        .equiv  CM1MSKCON_OAEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OAEN_MASK, 0x0200
        .equiv  OAEN, 0x0009

        .equiv  CM1MSKCON_OBNEN, 0x000A
        .equiv  CM1MSKCON_OBNEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OBNEN_MASK, 0x0400
        .equiv  OBNEN, 0x000A

        .equiv  CM1MSKCON_OBEN, 0x000B
        .equiv  CM1MSKCON_OBEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OBEN_MASK, 0x0800
        .equiv  OBEN, 0x000B

        .equiv  CM1MSKCON_OCNEN, 0x000C
        .equiv  CM1MSKCON_OCNEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OCNEN_MASK, 0x1000
        .equiv  OCNEN, 0x000C

        .equiv  CM1MSKCON_OCEN, 0x000D
        .equiv  CM1MSKCON_OCEN_WIDTH, 0x0001
        .equiv  CM1MSKCON_OCEN_MASK, 0x2000
        .equiv  OCEN, 0x000D

        .equiv  CM1MSKCON_HLMS, 0x000F
        .equiv  CM1MSKCON_HLMS_WIDTH, 0x0001
        .equiv  CM1MSKCON_HLMS_MASK, 0x8000
        .equiv  HLMS, 0x000F

;----- CM1FLTR Bits -----------------------------------------------------
        .equiv  CM1FLTR_CFDIV, 0x0000
        .equiv  CM1FLTR_CFDIV_WIDTH, 0x0003
        .equiv  CM1FLTR_CFDIV_MASK, 0x0007

        .equiv  CM1FLTR_CFLTREN, 0x0003
        .equiv  CM1FLTR_CFLTREN_WIDTH, 0x0001
        .equiv  CM1FLTR_CFLTREN_MASK, 0x0008
        .equiv  CFLTREN, 0x0003

        .equiv  CM1FLTR_CFSEL, 0x0004
        .equiv  CM1FLTR_CFSEL_WIDTH, 0x0003
        .equiv  CM1FLTR_CFSEL_MASK, 0x0070

        .equiv  CM1FLTR_CFDIV0, 0x0000
        .equiv  CM1FLTR_CFDIV0_WIDTH, 0x0001
        .equiv  CM1FLTR_CFDIV0_MASK, 0x0001
        .equiv  CFDIV0, 0x0000

        .equiv  CM1FLTR_CFDIV1, 0x0001
        .equiv  CM1FLTR_CFDIV1_WIDTH, 0x0001
        .equiv  CM1FLTR_CFDIV1_MASK, 0x0002
        .equiv  CFDIV1, 0x0001

        .equiv  CM1FLTR_CFDIV2, 0x0002
        .equiv  CM1FLTR_CFDIV2_WIDTH, 0x0001
        .equiv  CM1FLTR_CFDIV2_MASK, 0x0004
        .equiv  CFDIV2, 0x0002

        .equiv  CM1FLTR_CFSEL0, 0x0004
        .equiv  CM1FLTR_CFSEL0_WIDTH, 0x0001
        .equiv  CM1FLTR_CFSEL0_MASK, 0x0010
        .equiv  CFSEL0, 0x0004

        .equiv  CM1FLTR_CFSEL1, 0x0005
        .equiv  CM1FLTR_CFSEL1_WIDTH, 0x0001
        .equiv  CM1FLTR_CFSEL1_MASK, 0x0020
        .equiv  CFSEL1, 0x0005

        .equiv  CM1FLTR_CFSEL2, 0x0006
        .equiv  CM1FLTR_CFSEL2_WIDTH, 0x0001
        .equiv  CM1FLTR_CFSEL2_MASK, 0x0040
        .equiv  CFSEL2, 0x0006

;----- CM2CON Bits -----------------------------------------------------
        .equiv  CM2CON_CCH, 0x0000
        .equiv  CM2CON_CCH_WIDTH, 0x0002
        .equiv  CM2CON_CCH_MASK, 0x0003

        .equiv  CM2CON_CREF, 0x0004
        .equiv  CM2CON_CREF_WIDTH, 0x0001
        .equiv  CM2CON_CREF_MASK, 0x0010

        .equiv  CM2CON_EVPOL, 0x0006
        .equiv  CM2CON_EVPOL_WIDTH, 0x0002
        .equiv  CM2CON_EVPOL_MASK, 0x00C0

        .equiv  CM2CON_COUT, 0x0008
        .equiv  CM2CON_COUT_WIDTH, 0x0001
        .equiv  CM2CON_COUT_MASK, 0x0100

        .equiv  CM2CON_CEVT, 0x0009
        .equiv  CM2CON_CEVT_WIDTH, 0x0001
        .equiv  CM2CON_CEVT_MASK, 0x0200

        .equiv  CM2CON_OPMODE_CM2CON, 0x000A
        .equiv  CM2CON_OPMODE_CM2CON_WIDTH, 0x0001
        .equiv  CM2CON_OPMODE_CM2CON_MASK, 0x0400
        .equiv  OPMODE_CM2CON, 0x000A

        .equiv  CM2CON_CPOL, 0x000D
        .equiv  CM2CON_CPOL_WIDTH, 0x0001
        .equiv  CM2CON_CPOL_MASK, 0x2000

        .equiv  CM2CON_COE, 0x000E
        .equiv  CM2CON_COE_WIDTH, 0x0001
        .equiv  CM2CON_COE_MASK, 0x4000

        .equiv  CM2CON_CON, 0x000F
        .equiv  CM2CON_CON_WIDTH, 0x0001
        .equiv  CM2CON_CON_MASK, 0x8000

        .equiv  CM2CON_CCH0, 0x0000
        .equiv  CM2CON_CCH0_WIDTH, 0x0001
        .equiv  CM2CON_CCH0_MASK, 0x0001

        .equiv  CM2CON_CCH1, 0x0001
        .equiv  CM2CON_CCH1_WIDTH, 0x0001
        .equiv  CM2CON_CCH1_MASK, 0x0002

        .equiv  CM2CON_EVPOL0, 0x0006
        .equiv  CM2CON_EVPOL0_WIDTH, 0x0001
        .equiv  CM2CON_EVPOL0_MASK, 0x0040

        .equiv  CM2CON_EVPOL1, 0x0007
        .equiv  CM2CON_EVPOL1_WIDTH, 0x0001
        .equiv  CM2CON_EVPOL1_MASK, 0x0080

        .equiv  CM2CON_CEN, 0x000F
        .equiv  CM2CON_CEN_WIDTH, 0x0001
        .equiv  CM2CON_CEN_MASK, 0x8000

;----- CM2MSKSRC Bits -----------------------------------------------------
        .equiv  CM2MSKSRC_SELSRCA, 0x0000
        .equiv  CM2MSKSRC_SELSRCA_WIDTH, 0x0004
        .equiv  CM2MSKSRC_SELSRCA_MASK, 0x000F

        .equiv  CM2MSKSRC_SELSRCB, 0x0004
        .equiv  CM2MSKSRC_SELSRCB_WIDTH, 0x0004
        .equiv  CM2MSKSRC_SELSRCB_MASK, 0x00F0

        .equiv  CM2MSKSRC_SELSRCC, 0x0008
        .equiv  CM2MSKSRC_SELSRCC_WIDTH, 0x0004
        .equiv  CM2MSKSRC_SELSRCC_MASK, 0x0F00

        .equiv  CM2MSKSRC_SELSRCA0, 0x0000
        .equiv  CM2MSKSRC_SELSRCA0_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCA0_MASK, 0x0001

        .equiv  CM2MSKSRC_SELSRCA1, 0x0001
        .equiv  CM2MSKSRC_SELSRCA1_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCA1_MASK, 0x0002

        .equiv  CM2MSKSRC_SELSRCA2, 0x0002
        .equiv  CM2MSKSRC_SELSRCA2_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCA2_MASK, 0x0004

        .equiv  CM2MSKSRC_SELSRCA3, 0x0003
        .equiv  CM2MSKSRC_SELSRCA3_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCA3_MASK, 0x0008

        .equiv  CM2MSKSRC_SELSRCB0, 0x0004
        .equiv  CM2MSKSRC_SELSRCB0_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCB0_MASK, 0x0010

        .equiv  CM2MSKSRC_SELSRCB1, 0x0005
        .equiv  CM2MSKSRC_SELSRCB1_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCB1_MASK, 0x0020

        .equiv  CM2MSKSRC_SELSRCB2, 0x0006
        .equiv  CM2MSKSRC_SELSRCB2_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCB2_MASK, 0x0040

        .equiv  CM2MSKSRC_SELSRCB3, 0x0007
        .equiv  CM2MSKSRC_SELSRCB3_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCB3_MASK, 0x0080

        .equiv  CM2MSKSRC_SELSRCC0, 0x0008
        .equiv  CM2MSKSRC_SELSRCC0_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCC0_MASK, 0x0100

        .equiv  CM2MSKSRC_SELSRCC1, 0x0009
        .equiv  CM2MSKSRC_SELSRCC1_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCC1_MASK, 0x0200

        .equiv  CM2MSKSRC_SELSRCC2, 0x000A
        .equiv  CM2MSKSRC_SELSRCC2_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCC2_MASK, 0x0400

        .equiv  CM2MSKSRC_SELSRCC3, 0x000B
        .equiv  CM2MSKSRC_SELSRCC3_WIDTH, 0x0001
        .equiv  CM2MSKSRC_SELSRCC3_MASK, 0x0800

;----- CM2MSKCON Bits -----------------------------------------------------
        .equiv  CM2MSKCON_AANEN, 0x0000
        .equiv  CM2MSKCON_AANEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_AANEN_MASK, 0x0001

        .equiv  CM2MSKCON_AAEN, 0x0001
        .equiv  CM2MSKCON_AAEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_AAEN_MASK, 0x0002

        .equiv  CM2MSKCON_ABNEN, 0x0002
        .equiv  CM2MSKCON_ABNEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_ABNEN_MASK, 0x0004

        .equiv  CM2MSKCON_ABEN, 0x0003
        .equiv  CM2MSKCON_ABEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_ABEN_MASK, 0x0008

        .equiv  CM2MSKCON_ACNEN, 0x0004
        .equiv  CM2MSKCON_ACNEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_ACNEN_MASK, 0x0010

        .equiv  CM2MSKCON_ACEN, 0x0005
        .equiv  CM2MSKCON_ACEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_ACEN_MASK, 0x0020

        .equiv  CM2MSKCON_PAGS, 0x0006
        .equiv  CM2MSKCON_PAGS_WIDTH, 0x0001
        .equiv  CM2MSKCON_PAGS_MASK, 0x0040

        .equiv  CM2MSKCON_NAGS, 0x0007
        .equiv  CM2MSKCON_NAGS_WIDTH, 0x0001
        .equiv  CM2MSKCON_NAGS_MASK, 0x0080

        .equiv  CM2MSKCON_OANEN, 0x0008
        .equiv  CM2MSKCON_OANEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OANEN_MASK, 0x0100

        .equiv  CM2MSKCON_OAEN, 0x0009
        .equiv  CM2MSKCON_OAEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OAEN_MASK, 0x0200

        .equiv  CM2MSKCON_OBNEN, 0x000A
        .equiv  CM2MSKCON_OBNEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OBNEN_MASK, 0x0400

        .equiv  CM2MSKCON_OBEN, 0x000B
        .equiv  CM2MSKCON_OBEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OBEN_MASK, 0x0800

        .equiv  CM2MSKCON_OCNEN, 0x000C
        .equiv  CM2MSKCON_OCNEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OCNEN_MASK, 0x1000

        .equiv  CM2MSKCON_OCEN, 0x000D
        .equiv  CM2MSKCON_OCEN_WIDTH, 0x0001
        .equiv  CM2MSKCON_OCEN_MASK, 0x2000

        .equiv  CM2MSKCON_HLMS, 0x000F
        .equiv  CM2MSKCON_HLMS_WIDTH, 0x0001
        .equiv  CM2MSKCON_HLMS_MASK, 0x8000

;----- CM2FLTR Bits -----------------------------------------------------
        .equiv  CM2FLTR_CFDIV, 0x0000
        .equiv  CM2FLTR_CFDIV_WIDTH, 0x0003
        .equiv  CM2FLTR_CFDIV_MASK, 0x0007

        .equiv  CM2FLTR_CFLTREN, 0x0003
        .equiv  CM2FLTR_CFLTREN_WIDTH, 0x0001
        .equiv  CM2FLTR_CFLTREN_MASK, 0x0008

        .equiv  CM2FLTR_CFSEL, 0x0004
        .equiv  CM2FLTR_CFSEL_WIDTH, 0x0003
        .equiv  CM2FLTR_CFSEL_MASK, 0x0070

        .equiv  CM2FLTR_CFDIV0, 0x0000
        .equiv  CM2FLTR_CFDIV0_WIDTH, 0x0001
        .equiv  CM2FLTR_CFDIV0_MASK, 0x0001

        .equiv  CM2FLTR_CFDIV1, 0x0001
        .equiv  CM2FLTR_CFDIV1_WIDTH, 0x0001
        .equiv  CM2FLTR_CFDIV1_MASK, 0x0002

        .equiv  CM2FLTR_CFDIV2, 0x0002
        .equiv  CM2FLTR_CFDIV2_WIDTH, 0x0001
        .equiv  CM2FLTR_CFDIV2_MASK, 0x0004

        .equiv  CM2FLTR_CFSEL0, 0x0004
        .equiv  CM2FLTR_CFSEL0_WIDTH, 0x0001
        .equiv  CM2FLTR_CFSEL0_MASK, 0x0010

        .equiv  CM2FLTR_CFSEL1, 0x0005
        .equiv  CM2FLTR_CFSEL1_WIDTH, 0x0001
        .equiv  CM2FLTR_CFSEL1_MASK, 0x0020

        .equiv  CM2FLTR_CFSEL2, 0x0006
        .equiv  CM2FLTR_CFSEL2_WIDTH, 0x0001
        .equiv  CM2FLTR_CFSEL2_MASK, 0x0040

;----- CM3CON Bits -----------------------------------------------------
        .equiv  CM3CON_CCH, 0x0000
        .equiv  CM3CON_CCH_WIDTH, 0x0002
        .equiv  CM3CON_CCH_MASK, 0x0003

        .equiv  CM3CON_CREF, 0x0004
        .equiv  CM3CON_CREF_WIDTH, 0x0001
        .equiv  CM3CON_CREF_MASK, 0x0010

        .equiv  CM3CON_EVPOL, 0x0006
        .equiv  CM3CON_EVPOL_WIDTH, 0x0002
        .equiv  CM3CON_EVPOL_MASK, 0x00C0

        .equiv  CM3CON_COUT, 0x0008
        .equiv  CM3CON_COUT_WIDTH, 0x0001
        .equiv  CM3CON_COUT_MASK, 0x0100

        .equiv  CM3CON_CEVT, 0x0009
        .equiv  CM3CON_CEVT_WIDTH, 0x0001
        .equiv  CM3CON_CEVT_MASK, 0x0200

        .equiv  CM3CON_OPMODE_CM3CON, 0x000A
        .equiv  CM3CON_OPMODE_CM3CON_WIDTH, 0x0001
        .equiv  CM3CON_OPMODE_CM3CON_MASK, 0x0400
        .equiv  OPMODE_CM3CON, 0x000A

        .equiv  CM3CON_CPOL, 0x000D
        .equiv  CM3CON_CPOL_WIDTH, 0x0001
        .equiv  CM3CON_CPOL_MASK, 0x2000

        .equiv  CM3CON_COE, 0x000E
        .equiv  CM3CON_COE_WIDTH, 0x0001
        .equiv  CM3CON_COE_MASK, 0x4000

        .equiv  CM3CON_CON, 0x000F
        .equiv  CM3CON_CON_WIDTH, 0x0001
        .equiv  CM3CON_CON_MASK, 0x8000

        .equiv  CM3CON_CCH0, 0x0000
        .equiv  CM3CON_CCH0_WIDTH, 0x0001
        .equiv  CM3CON_CCH0_MASK, 0x0001

        .equiv  CM3CON_CCH1, 0x0001
        .equiv  CM3CON_CCH1_WIDTH, 0x0001
        .equiv  CM3CON_CCH1_MASK, 0x0002

        .equiv  CM3CON_EVPOL0, 0x0006
        .equiv  CM3CON_EVPOL0_WIDTH, 0x0001
        .equiv  CM3CON_EVPOL0_MASK, 0x0040

        .equiv  CM3CON_EVPOL1, 0x0007
        .equiv  CM3CON_EVPOL1_WIDTH, 0x0001
        .equiv  CM3CON_EVPOL1_MASK, 0x0080

        .equiv  CM3CON_CEN, 0x000F
        .equiv  CM3CON_CEN_WIDTH, 0x0001
        .equiv  CM3CON_CEN_MASK, 0x8000

;----- CM3MSKSRC Bits -----------------------------------------------------
        .equiv  CM3MSKSRC_SELSRCA, 0x0000
        .equiv  CM3MSKSRC_SELSRCA_WIDTH, 0x0004
        .equiv  CM3MSKSRC_SELSRCA_MASK, 0x000F

        .equiv  CM3MSKSRC_SELSRCB, 0x0004
        .equiv  CM3MSKSRC_SELSRCB_WIDTH, 0x0004
        .equiv  CM3MSKSRC_SELSRCB_MASK, 0x00F0

        .equiv  CM3MSKSRC_SELSRCC, 0x0008
        .equiv  CM3MSKSRC_SELSRCC_WIDTH, 0x0004
        .equiv  CM3MSKSRC_SELSRCC_MASK, 0x0F00

        .equiv  CM3MSKSRC_SELSRCA0, 0x0000
        .equiv  CM3MSKSRC_SELSRCA0_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCA0_MASK, 0x0001

        .equiv  CM3MSKSRC_SELSRCA1, 0x0001
        .equiv  CM3MSKSRC_SELSRCA1_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCA1_MASK, 0x0002

        .equiv  CM3MSKSRC_SELSRCA2, 0x0002
        .equiv  CM3MSKSRC_SELSRCA2_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCA2_MASK, 0x0004

        .equiv  CM3MSKSRC_SELSRCA3, 0x0003
        .equiv  CM3MSKSRC_SELSRCA3_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCA3_MASK, 0x0008

        .equiv  CM3MSKSRC_SELSRCB0, 0x0004
        .equiv  CM3MSKSRC_SELSRCB0_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCB0_MASK, 0x0010

        .equiv  CM3MSKSRC_SELSRCB1, 0x0005
        .equiv  CM3MSKSRC_SELSRCB1_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCB1_MASK, 0x0020

        .equiv  CM3MSKSRC_SELSRCB2, 0x0006
        .equiv  CM3MSKSRC_SELSRCB2_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCB2_MASK, 0x0040

        .equiv  CM3MSKSRC_SELSRCB3, 0x0007
        .equiv  CM3MSKSRC_SELSRCB3_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCB3_MASK, 0x0080

        .equiv  CM3MSKSRC_SELSRCC0, 0x0008
        .equiv  CM3MSKSRC_SELSRCC0_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCC0_MASK, 0x0100

        .equiv  CM3MSKSRC_SELSRCC1, 0x0009
        .equiv  CM3MSKSRC_SELSRCC1_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCC1_MASK, 0x0200

        .equiv  CM3MSKSRC_SELSRCC2, 0x000A
        .equiv  CM3MSKSRC_SELSRCC2_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCC2_MASK, 0x0400

        .equiv  CM3MSKSRC_SELSRCC3, 0x000B
        .equiv  CM3MSKSRC_SELSRCC3_WIDTH, 0x0001
        .equiv  CM3MSKSRC_SELSRCC3_MASK, 0x0800

;----- CM3MSKCON Bits -----------------------------------------------------
        .equiv  CM3MSKCON_AANEN, 0x0000
        .equiv  CM3MSKCON_AANEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_AANEN_MASK, 0x0001

        .equiv  CM3MSKCON_AAEN, 0x0001
        .equiv  CM3MSKCON_AAEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_AAEN_MASK, 0x0002

        .equiv  CM3MSKCON_ABNEN, 0x0002
        .equiv  CM3MSKCON_ABNEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_ABNEN_MASK, 0x0004

        .equiv  CM3MSKCON_ABEN, 0x0003
        .equiv  CM3MSKCON_ABEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_ABEN_MASK, 0x0008

        .equiv  CM3MSKCON_ACNEN, 0x0004
        .equiv  CM3MSKCON_ACNEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_ACNEN_MASK, 0x0010

        .equiv  CM3MSKCON_ACEN, 0x0005
        .equiv  CM3MSKCON_ACEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_ACEN_MASK, 0x0020

        .equiv  CM3MSKCON_PAGS, 0x0006
        .equiv  CM3MSKCON_PAGS_WIDTH, 0x0001
        .equiv  CM3MSKCON_PAGS_MASK, 0x0040

        .equiv  CM3MSKCON_NAGS, 0x0007
        .equiv  CM3MSKCON_NAGS_WIDTH, 0x0001
        .equiv  CM3MSKCON_NAGS_MASK, 0x0080

        .equiv  CM3MSKCON_OANEN, 0x0008
        .equiv  CM3MSKCON_OANEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OANEN_MASK, 0x0100

        .equiv  CM3MSKCON_OAEN, 0x0009
        .equiv  CM3MSKCON_OAEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OAEN_MASK, 0x0200

        .equiv  CM3MSKCON_OBNEN, 0x000A
        .equiv  CM3MSKCON_OBNEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OBNEN_MASK, 0x0400

        .equiv  CM3MSKCON_OBEN, 0x000B
        .equiv  CM3MSKCON_OBEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OBEN_MASK, 0x0800

        .equiv  CM3MSKCON_OCNEN, 0x000C
        .equiv  CM3MSKCON_OCNEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OCNEN_MASK, 0x1000

        .equiv  CM3MSKCON_OCEN, 0x000D
        .equiv  CM3MSKCON_OCEN_WIDTH, 0x0001
        .equiv  CM3MSKCON_OCEN_MASK, 0x2000

        .equiv  CM3MSKCON_HLMS, 0x000F
        .equiv  CM3MSKCON_HLMS_WIDTH, 0x0001
        .equiv  CM3MSKCON_HLMS_MASK, 0x8000

;----- CM3FLTR Bits -----------------------------------------------------
        .equiv  CM3FLTR_CFDIV, 0x0000
        .equiv  CM3FLTR_CFDIV_WIDTH, 0x0003
        .equiv  CM3FLTR_CFDIV_MASK, 0x0007

        .equiv  CM3FLTR_CFLTREN, 0x0003
        .equiv  CM3FLTR_CFLTREN_WIDTH, 0x0001
        .equiv  CM3FLTR_CFLTREN_MASK, 0x0008

        .equiv  CM3FLTR_CFSEL, 0x0004
        .equiv  CM3FLTR_CFSEL_WIDTH, 0x0003
        .equiv  CM3FLTR_CFSEL_MASK, 0x0070

        .equiv  CM3FLTR_CFDIV0, 0x0000
        .equiv  CM3FLTR_CFDIV0_WIDTH, 0x0001
        .equiv  CM3FLTR_CFDIV0_MASK, 0x0001

        .equiv  CM3FLTR_CFDIV1, 0x0001
        .equiv  CM3FLTR_CFDIV1_WIDTH, 0x0001
        .equiv  CM3FLTR_CFDIV1_MASK, 0x0002

        .equiv  CM3FLTR_CFDIV2, 0x0002
        .equiv  CM3FLTR_CFDIV2_WIDTH, 0x0001
        .equiv  CM3FLTR_CFDIV2_MASK, 0x0004

        .equiv  CM3FLTR_CFSEL0, 0x0004
        .equiv  CM3FLTR_CFSEL0_WIDTH, 0x0001
        .equiv  CM3FLTR_CFSEL0_MASK, 0x0010

        .equiv  CM3FLTR_CFSEL1, 0x0005
        .equiv  CM3FLTR_CFSEL1_WIDTH, 0x0001
        .equiv  CM3FLTR_CFSEL1_MASK, 0x0020

        .equiv  CM3FLTR_CFSEL2, 0x0006
        .equiv  CM3FLTR_CFSEL2_WIDTH, 0x0001
        .equiv  CM3FLTR_CFSEL2_MASK, 0x0040

;----- CM4CON Bits -----------------------------------------------------
        .equiv  CM4CON_CCH, 0x0000
        .equiv  CM4CON_CCH_WIDTH, 0x0002
        .equiv  CM4CON_CCH_MASK, 0x0003

        .equiv  CM4CON_CREF, 0x0004
        .equiv  CM4CON_CREF_WIDTH, 0x0001
        .equiv  CM4CON_CREF_MASK, 0x0010

        .equiv  CM4CON_EVPOL, 0x0006
        .equiv  CM4CON_EVPOL_WIDTH, 0x0002
        .equiv  CM4CON_EVPOL_MASK, 0x00C0

        .equiv  CM4CON_COUT, 0x0008
        .equiv  CM4CON_COUT_WIDTH, 0x0001
        .equiv  CM4CON_COUT_MASK, 0x0100

        .equiv  CM4CON_CEVT, 0x0009
        .equiv  CM4CON_CEVT_WIDTH, 0x0001
        .equiv  CM4CON_CEVT_MASK, 0x0200

        .equiv  CM4CON_CPOL, 0x000D
        .equiv  CM4CON_CPOL_WIDTH, 0x0001
        .equiv  CM4CON_CPOL_MASK, 0x2000

        .equiv  CM4CON_COE, 0x000E
        .equiv  CM4CON_COE_WIDTH, 0x0001
        .equiv  CM4CON_COE_MASK, 0x4000

        .equiv  CM4CON_CON, 0x000F
        .equiv  CM4CON_CON_WIDTH, 0x0001
        .equiv  CM4CON_CON_MASK, 0x8000

        .equiv  CM4CON_CCH0, 0x0000
        .equiv  CM4CON_CCH0_WIDTH, 0x0001
        .equiv  CM4CON_CCH0_MASK, 0x0001

        .equiv  CM4CON_CCH1, 0x0001
        .equiv  CM4CON_CCH1_WIDTH, 0x0001
        .equiv  CM4CON_CCH1_MASK, 0x0002

        .equiv  CM4CON_EVPOL0, 0x0006
        .equiv  CM4CON_EVPOL0_WIDTH, 0x0001
        .equiv  CM4CON_EVPOL0_MASK, 0x0040

        .equiv  CM4CON_EVPOL1, 0x0007
        .equiv  CM4CON_EVPOL1_WIDTH, 0x0001
        .equiv  CM4CON_EVPOL1_MASK, 0x0080

        .equiv  CM4CON_CEN, 0x000F
        .equiv  CM4CON_CEN_WIDTH, 0x0001
        .equiv  CM4CON_CEN_MASK, 0x8000

;----- CM4MSKSRC Bits -----------------------------------------------------
        .equiv  CM4MSKSRC_SELSRCA, 0x0000
        .equiv  CM4MSKSRC_SELSRCA_WIDTH, 0x0004
        .equiv  CM4MSKSRC_SELSRCA_MASK, 0x000F

        .equiv  CM4MSKSRC_SELSRCB, 0x0004
        .equiv  CM4MSKSRC_SELSRCB_WIDTH, 0x0004
        .equiv  CM4MSKSRC_SELSRCB_MASK, 0x00F0

        .equiv  CM4MSKSRC_SELSRCC, 0x0008
        .equiv  CM4MSKSRC_SELSRCC_WIDTH, 0x0004
        .equiv  CM4MSKSRC_SELSRCC_MASK, 0x0F00

        .equiv  CM4MSKSRC_SELSRCA0, 0x0000
        .equiv  CM4MSKSRC_SELSRCA0_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCA0_MASK, 0x0001

        .equiv  CM4MSKSRC_SELSRCA1, 0x0001
        .equiv  CM4MSKSRC_SELSRCA1_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCA1_MASK, 0x0002

        .equiv  CM4MSKSRC_SELSRCA2, 0x0002
        .equiv  CM4MSKSRC_SELSRCA2_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCA2_MASK, 0x0004

        .equiv  CM4MSKSRC_SELSRCA3, 0x0003
        .equiv  CM4MSKSRC_SELSRCA3_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCA3_MASK, 0x0008

        .equiv  CM4MSKSRC_SELSRCB0, 0x0004
        .equiv  CM4MSKSRC_SELSRCB0_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCB0_MASK, 0x0010

        .equiv  CM4MSKSRC_SELSRCB1, 0x0005
        .equiv  CM4MSKSRC_SELSRCB1_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCB1_MASK, 0x0020

        .equiv  CM4MSKSRC_SELSRCB2, 0x0006
        .equiv  CM4MSKSRC_SELSRCB2_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCB2_MASK, 0x0040

        .equiv  CM4MSKSRC_SELSRCB3, 0x0007
        .equiv  CM4MSKSRC_SELSRCB3_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCB3_MASK, 0x0080

        .equiv  CM4MSKSRC_SELSRCC0, 0x0008
        .equiv  CM4MSKSRC_SELSRCC0_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCC0_MASK, 0x0100

        .equiv  CM4MSKSRC_SELSRCC1, 0x0009
        .equiv  CM4MSKSRC_SELSRCC1_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCC1_MASK, 0x0200

        .equiv  CM4MSKSRC_SELSRCC2, 0x000A
        .equiv  CM4MSKSRC_SELSRCC2_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCC2_MASK, 0x0400

        .equiv  CM4MSKSRC_SELSRCC3, 0x000B
        .equiv  CM4MSKSRC_SELSRCC3_WIDTH, 0x0001
        .equiv  CM4MSKSRC_SELSRCC3_MASK, 0x0800

;----- CM4MSKCON Bits -----------------------------------------------------
        .equiv  CM4MSKCON_AANEN, 0x0000
        .equiv  CM4MSKCON_AANEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_AANEN_MASK, 0x0001

        .equiv  CM4MSKCON_AAEN, 0x0001
        .equiv  CM4MSKCON_AAEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_AAEN_MASK, 0x0002

        .equiv  CM4MSKCON_ABNEN, 0x0002
        .equiv  CM4MSKCON_ABNEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_ABNEN_MASK, 0x0004

        .equiv  CM4MSKCON_ABEN, 0x0003
        .equiv  CM4MSKCON_ABEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_ABEN_MASK, 0x0008

        .equiv  CM4MSKCON_ACNEN, 0x0004
        .equiv  CM4MSKCON_ACNEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_ACNEN_MASK, 0x0010

        .equiv  CM4MSKCON_ACEN, 0x0005
        .equiv  CM4MSKCON_ACEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_ACEN_MASK, 0x0020

        .equiv  CM4MSKCON_PAGS, 0x0006
        .equiv  CM4MSKCON_PAGS_WIDTH, 0x0001
        .equiv  CM4MSKCON_PAGS_MASK, 0x0040

        .equiv  CM4MSKCON_NAGS, 0x0007
        .equiv  CM4MSKCON_NAGS_WIDTH, 0x0001
        .equiv  CM4MSKCON_NAGS_MASK, 0x0080

        .equiv  CM4MSKCON_OANEN, 0x0008
        .equiv  CM4MSKCON_OANEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OANEN_MASK, 0x0100

        .equiv  CM4MSKCON_OAEN, 0x0009
        .equiv  CM4MSKCON_OAEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OAEN_MASK, 0x0200

        .equiv  CM4MSKCON_OBNEN, 0x000A
        .equiv  CM4MSKCON_OBNEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OBNEN_MASK, 0x0400

        .equiv  CM4MSKCON_OBEN, 0x000B
        .equiv  CM4MSKCON_OBEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OBEN_MASK, 0x0800

        .equiv  CM4MSKCON_OCNEN, 0x000C
        .equiv  CM4MSKCON_OCNEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OCNEN_MASK, 0x1000

        .equiv  CM4MSKCON_OCEN, 0x000D
        .equiv  CM4MSKCON_OCEN_WIDTH, 0x0001
        .equiv  CM4MSKCON_OCEN_MASK, 0x2000

        .equiv  CM4MSKCON_HLMS, 0x000F
        .equiv  CM4MSKCON_HLMS_WIDTH, 0x0001
        .equiv  CM4MSKCON_HLMS_MASK, 0x8000

;----- CM4FLTR Bits -----------------------------------------------------
        .equiv  CM4FLTR_CFDIV, 0x0000
        .equiv  CM4FLTR_CFDIV_WIDTH, 0x0003
        .equiv  CM4FLTR_CFDIV_MASK, 0x0007

        .equiv  CM4FLTR_CFLTREN, 0x0003
        .equiv  CM4FLTR_CFLTREN_WIDTH, 0x0001
        .equiv  CM4FLTR_CFLTREN_MASK, 0x0008

        .equiv  CM4FLTR_CFSEL, 0x0004
        .equiv  CM4FLTR_CFSEL_WIDTH, 0x0003
        .equiv  CM4FLTR_CFSEL_MASK, 0x0070

        .equiv  CM4FLTR_CFDIV0, 0x0000
        .equiv  CM4FLTR_CFDIV0_WIDTH, 0x0001
        .equiv  CM4FLTR_CFDIV0_MASK, 0x0001

        .equiv  CM4FLTR_CFDIV1, 0x0001
        .equiv  CM4FLTR_CFDIV1_WIDTH, 0x0001
        .equiv  CM4FLTR_CFDIV1_MASK, 0x0002

        .equiv  CM4FLTR_CFDIV2, 0x0002
        .equiv  CM4FLTR_CFDIV2_WIDTH, 0x0001
        .equiv  CM4FLTR_CFDIV2_MASK, 0x0004

        .equiv  CM4FLTR_CFSEL0, 0x0004
        .equiv  CM4FLTR_CFSEL0_WIDTH, 0x0001
        .equiv  CM4FLTR_CFSEL0_MASK, 0x0010

        .equiv  CM4FLTR_CFSEL1, 0x0005
        .equiv  CM4FLTR_CFSEL1_WIDTH, 0x0001
        .equiv  CM4FLTR_CFSEL1_MASK, 0x0020

        .equiv  CM4FLTR_CFSEL2, 0x0006
        .equiv  CM4FLTR_CFSEL2_WIDTH, 0x0001
        .equiv  CM4FLTR_CFSEL2_MASK, 0x0040

;----- PTGCST Bits -----------------------------------------------------
        .equiv  PTGCST_PTGITM, 0x0000
        .equiv  PTGCST_PTGITM_WIDTH, 0x0002
        .equiv  PTGCST_PTGITM_MASK, 0x0003

        .equiv  PTGCST_PTGWTO, 0x0006
        .equiv  PTGCST_PTGWTO_WIDTH, 0x0001
        .equiv  PTGCST_PTGWTO_MASK, 0x0040
        .equiv  PTGWTO, 0x0006

        .equiv  PTGCST_PTGSTRT, 0x0007
        .equiv  PTGCST_PTGSTRT_WIDTH, 0x0001
        .equiv  PTGCST_PTGSTRT_MASK, 0x0080
        .equiv  PTGSTRT, 0x0007

        .equiv  PTGCST_PTGIVIS, 0x0008
        .equiv  PTGCST_PTGIVIS_WIDTH, 0x0001
        .equiv  PTGCST_PTGIVIS_MASK, 0x0100
        .equiv  PTGIVIS, 0x0008

        .equiv  PTGCST_PTGSSEN, 0x0009
        .equiv  PTGCST_PTGSSEN_WIDTH, 0x0001
        .equiv  PTGCST_PTGSSEN_MASK, 0x0200
        .equiv  PTGSSEN, 0x0009

        .equiv  PTGCST_PTGSWT, 0x000A
        .equiv  PTGCST_PTGSWT_WIDTH, 0x0001
        .equiv  PTGCST_PTGSWT_MASK, 0x0400
        .equiv  PTGSWT, 0x000A

        .equiv  PTGCST_PTGTOGL, 0x000C
        .equiv  PTGCST_PTGTOGL_WIDTH, 0x0001
        .equiv  PTGCST_PTGTOGL_MASK, 0x1000
        .equiv  PTGTOGL, 0x000C

        .equiv  PTGCST_PTGSIDL, 0x000D
        .equiv  PTGCST_PTGSIDL_WIDTH, 0x0001
        .equiv  PTGCST_PTGSIDL_MASK, 0x2000
        .equiv  PTGSIDL, 0x000D

        .equiv  PTGCST_PTGEN, 0x000F
        .equiv  PTGCST_PTGEN_WIDTH, 0x0001
        .equiv  PTGCST_PTGEN_MASK, 0x8000
        .equiv  PTGEN, 0x000F

;----- PTGCON Bits -----------------------------------------------------
        .equiv  PTGCON_PTGWDT, 0x0000
        .equiv  PTGCON_PTGWDT_WIDTH, 0x0003
        .equiv  PTGCON_PTGWDT_MASK, 0x0007

        .equiv  PTGCON_PTGPWD, 0x0004
        .equiv  PTGCON_PTGPWD_WIDTH, 0x0004
        .equiv  PTGCON_PTGPWD_MASK, 0x00F0

        .equiv  PTGCON_PTGDIV, 0x0008
        .equiv  PTGCON_PTGDIV_WIDTH, 0x0005
        .equiv  PTGCON_PTGDIV_MASK, 0x1F00

        .equiv  PTGCON_PTGCLK, 0x000D
        .equiv  PTGCON_PTGCLK_WIDTH, 0x0003
        .equiv  PTGCON_PTGCLK_MASK, 0xE000

;----- PTGBTE Bits -----------------------------------------------------
        .equiv  PTGBTE_OC1TSS, 0x0000
        .equiv  PTGBTE_OC1TSS_WIDTH, 0x0001
        .equiv  PTGBTE_OC1TSS_MASK, 0x0001
        .equiv  OC1TSS, 0x0000

        .equiv  PTGBTE_OC2TSS, 0x0001
        .equiv  PTGBTE_OC2TSS_WIDTH, 0x0001
        .equiv  PTGBTE_OC2TSS_MASK, 0x0002
        .equiv  OC2TSS, 0x0001

        .equiv  PTGBTE_OC3TSS, 0x0002
        .equiv  PTGBTE_OC3TSS_WIDTH, 0x0001
        .equiv  PTGBTE_OC3TSS_MASK, 0x0004
        .equiv  OC3TSS, 0x0002

        .equiv  PTGBTE_OC4TSS, 0x0003
        .equiv  PTGBTE_OC4TSS_WIDTH, 0x0001
        .equiv  PTGBTE_OC4TSS_MASK, 0x0008
        .equiv  OC4TSS, 0x0003

        .equiv  PTGBTE_OC1CS, 0x0004
        .equiv  PTGBTE_OC1CS_WIDTH, 0x0001
        .equiv  PTGBTE_OC1CS_MASK, 0x0010
        .equiv  OC1CS, 0x0004

        .equiv  PTGBTE_OC2CS, 0x0005
        .equiv  PTGBTE_OC2CS_WIDTH, 0x0001
        .equiv  PTGBTE_OC2CS_MASK, 0x0020
        .equiv  OC2CS, 0x0005

        .equiv  PTGBTE_OC3CS, 0x0006
        .equiv  PTGBTE_OC3CS_WIDTH, 0x0001
        .equiv  PTGBTE_OC3CS_MASK, 0x0040
        .equiv  OC3CS, 0x0006

        .equiv  PTGBTE_OC4CS, 0x0007
        .equiv  PTGBTE_OC4CS_WIDTH, 0x0001
        .equiv  PTGBTE_OC4CS_MASK, 0x0080
        .equiv  OC4CS, 0x0007

        .equiv  PTGBTE_IC1TSS, 0x0008
        .equiv  PTGBTE_IC1TSS_WIDTH, 0x0001
        .equiv  PTGBTE_IC1TSS_MASK, 0x0100
        .equiv  IC1TSS, 0x0008

        .equiv  PTGBTE_IC2TSS, 0x0009
        .equiv  PTGBTE_IC2TSS_WIDTH, 0x0001
        .equiv  PTGBTE_IC2TSS_MASK, 0x0200
        .equiv  IC2TSS, 0x0009

        .equiv  PTGBTE_IC3TSS, 0x000A
        .equiv  PTGBTE_IC3TSS_WIDTH, 0x0001
        .equiv  PTGBTE_IC3TSS_MASK, 0x0400
        .equiv  IC3TSS, 0x000A

        .equiv  PTGBTE_IC4TSS, 0x000B
        .equiv  PTGBTE_IC4TSS_WIDTH, 0x0001
        .equiv  PTGBTE_IC4TSS_MASK, 0x0800
        .equiv  IC4TSS, 0x000B

        .equiv  PTGBTE_ADCTS1, 0x000C
        .equiv  PTGBTE_ADCTS1_WIDTH, 0x0001
        .equiv  PTGBTE_ADCTS1_MASK, 0x1000
        .equiv  ADCTS1, 0x000C

        .equiv  PTGBTE_ADCTS2, 0x000D
        .equiv  PTGBTE_ADCTS2_WIDTH, 0x0001
        .equiv  PTGBTE_ADCTS2_MASK, 0x2000
        .equiv  ADCTS2, 0x000D

        .equiv  PTGBTE_ADCTS3, 0x000E
        .equiv  PTGBTE_ADCTS3_WIDTH, 0x0001
        .equiv  PTGBTE_ADCTS3_MASK, 0x4000
        .equiv  ADCTS3, 0x000E

        .equiv  PTGBTE_ADCTS4, 0x000F
        .equiv  PTGBTE_ADCTS4_WIDTH, 0x0001
        .equiv  PTGBTE_ADCTS4_MASK, 0x8000
        .equiv  ADCTS4, 0x000F

        .equiv  PTGBTE, 0x0000
        .equiv  PTGBTE_WIDTH, 0x0010
        .equiv  PTGBTE_MASK, 0xFFFF

;----- PTGQPTR Bits -----------------------------------------------------
        .equiv  PTGQPTR, 0x0000
        .equiv  PTGQPTR_WIDTH, 0x0005
        .equiv  PTGQPTR_MASK, 0x001F

;----- PTGQUE0 Bits -----------------------------------------------------
        .equiv  PTGQUE0_STEP0, 0x0000
        .equiv  PTGQUE0_STEP0_WIDTH, 0x0008
        .equiv  PTGQUE0_STEP0_MASK, 0x00FF

        .equiv  PTGQUE0_STEP1, 0x0008
        .equiv  PTGQUE0_STEP1_WIDTH, 0x0008
        .equiv  PTGQUE0_STEP1_MASK, 0xFF00

;----- PTGQUE1 Bits -----------------------------------------------------
        .equiv  PTGQUE1_STEP2, 0x0000
        .equiv  PTGQUE1_STEP2_WIDTH, 0x0008
        .equiv  PTGQUE1_STEP2_MASK, 0x00FF

        .equiv  PTGQUE1_STEP3, 0x0008
        .equiv  PTGQUE1_STEP3_WIDTH, 0x0008
        .equiv  PTGQUE1_STEP3_MASK, 0xFF00

;----- PTGQUE2 Bits -----------------------------------------------------
        .equiv  PTGQUE2_STEP4, 0x0000
        .equiv  PTGQUE2_STEP4_WIDTH, 0x0008
        .equiv  PTGQUE2_STEP4_MASK, 0x00FF

        .equiv  PTGQUE2_STEP5, 0x0008
        .equiv  PTGQUE2_STEP5_WIDTH, 0x0008
        .equiv  PTGQUE2_STEP5_MASK, 0xFF00

;----- PTGQUE3 Bits -----------------------------------------------------
        .equiv  PTGQUE3_STEP6, 0x0000
        .equiv  PTGQUE3_STEP6_WIDTH, 0x0008
        .equiv  PTGQUE3_STEP6_MASK, 0x00FF

        .equiv  PTGQUE3_STEP7, 0x0008
        .equiv  PTGQUE3_STEP7_WIDTH, 0x0008
        .equiv  PTGQUE3_STEP7_MASK, 0xFF00

;----- PTGQUE4 Bits -----------------------------------------------------
        .equiv  PTGQUE4_STEP8, 0x0000
        .equiv  PTGQUE4_STEP8_WIDTH, 0x0008
        .equiv  PTGQUE4_STEP8_MASK, 0x00FF

        .equiv  PTGQUE4_STEP9, 0x0008
        .equiv  PTGQUE4_STEP9_WIDTH, 0x0008
        .equiv  PTGQUE4_STEP9_MASK, 0xFF00

;----- PTGQUE5 Bits -----------------------------------------------------
        .equiv  PTGQUE5_STEP10, 0x0000
        .equiv  PTGQUE5_STEP10_WIDTH, 0x0008
        .equiv  PTGQUE5_STEP10_MASK, 0x00FF

        .equiv  PTGQUE5_STEP11, 0x0008
        .equiv  PTGQUE5_STEP11_WIDTH, 0x0008
        .equiv  PTGQUE5_STEP11_MASK, 0xFF00

;----- PTGQUE6 Bits -----------------------------------------------------
        .equiv  PTGQUE6_STEP12, 0x0000
        .equiv  PTGQUE6_STEP12_WIDTH, 0x0008
        .equiv  PTGQUE6_STEP12_MASK, 0x00FF

        .equiv  PTGQUE6_STEP13, 0x0008
        .equiv  PTGQUE6_STEP13_WIDTH, 0x0008
        .equiv  PTGQUE6_STEP13_MASK, 0xFF00

;----- PTGQUE7 Bits -----------------------------------------------------
        .equiv  PTGQUE7_STEP14, 0x0000
        .equiv  PTGQUE7_STEP14_WIDTH, 0x0008
        .equiv  PTGQUE7_STEP14_MASK, 0x00FF

        .equiv  PTGQUE7_STEP15, 0x0008
        .equiv  PTGQUE7_STEP15_WIDTH, 0x0008
        .equiv  PTGQUE7_STEP15_MASK, 0xFF00

;----- DMA0CON Bits -----------------------------------------------------
        .equiv  DMA0CON_MODE, 0x0000
        .equiv  DMA0CON_MODE_WIDTH, 0x0002
        .equiv  DMA0CON_MODE_MASK, 0x0003

        .equiv  DMA0CON_AMODE, 0x0004
        .equiv  DMA0CON_AMODE_WIDTH, 0x0002
        .equiv  DMA0CON_AMODE_MASK, 0x0030

        .equiv  DMA0CON_NULLW, 0x000B
        .equiv  DMA0CON_NULLW_WIDTH, 0x0001
        .equiv  DMA0CON_NULLW_MASK, 0x0800
        .equiv  NULLW, 0x000B

        .equiv  DMA0CON_HALF, 0x000C
        .equiv  DMA0CON_HALF_WIDTH, 0x0001
        .equiv  DMA0CON_HALF_MASK, 0x1000
        .equiv  HALF, 0x000C

        .equiv  DMA0CON_DIR, 0x000D
        .equiv  DMA0CON_DIR_WIDTH, 0x0001
        .equiv  DMA0CON_DIR_MASK, 0x2000
        .equiv  DIR, 0x000D

        .equiv  DMA0CON_SIZE, 0x000E
        .equiv  DMA0CON_SIZE_WIDTH, 0x0001
        .equiv  DMA0CON_SIZE_MASK, 0x4000
        .equiv  SIZE, 0x000E

        .equiv  DMA0CON_CHEN, 0x000F
        .equiv  DMA0CON_CHEN_WIDTH, 0x0001
        .equiv  DMA0CON_CHEN_MASK, 0x8000
        .equiv  CHEN, 0x000F

        .equiv  DMA0CON_MODE0, 0x0000
        .equiv  DMA0CON_MODE0_WIDTH, 0x0001
        .equiv  DMA0CON_MODE0_MASK, 0x0001
        .equiv  MODE0, 0x0000

        .equiv  DMA0CON_MODE1, 0x0001
        .equiv  DMA0CON_MODE1_WIDTH, 0x0001
        .equiv  DMA0CON_MODE1_MASK, 0x0002
        .equiv  MODE1, 0x0001

        .equiv  DMA0CON_AMODE0, 0x0004
        .equiv  DMA0CON_AMODE0_WIDTH, 0x0001
        .equiv  DMA0CON_AMODE0_MASK, 0x0010
        .equiv  AMODE0, 0x0004

        .equiv  DMA0CON_AMODE1, 0x0005
        .equiv  DMA0CON_AMODE1_WIDTH, 0x0001
        .equiv  DMA0CON_AMODE1_MASK, 0x0020
        .equiv  AMODE1, 0x0005

;----- DMA0REQ Bits -----------------------------------------------------
        .equiv  DMA0REQ_IRQSEL, 0x0000
        .equiv  DMA0REQ_IRQSEL_WIDTH, 0x0008
        .equiv  DMA0REQ_IRQSEL_MASK, 0x00FF

        .equiv  DMA0REQ_FORCE, 0x000F
        .equiv  DMA0REQ_FORCE_WIDTH, 0x0001
        .equiv  DMA0REQ_FORCE_MASK, 0x8000
        .equiv  FORCE, 0x000F

        .equiv  DMA0REQ_IRQSEL0, 0x0000
        .equiv  DMA0REQ_IRQSEL0_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL0_MASK, 0x0001
        .equiv  IRQSEL0, 0x0000

        .equiv  DMA0REQ_IRQSEL1, 0x0001
        .equiv  DMA0REQ_IRQSEL1_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL1_MASK, 0x0002
        .equiv  IRQSEL1, 0x0001

        .equiv  DMA0REQ_IRQSEL2, 0x0002
        .equiv  DMA0REQ_IRQSEL2_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL2_MASK, 0x0004
        .equiv  IRQSEL2, 0x0002

        .equiv  DMA0REQ_IRQSEL3, 0x0003
        .equiv  DMA0REQ_IRQSEL3_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL3_MASK, 0x0008
        .equiv  IRQSEL3, 0x0003

        .equiv  DMA0REQ_IRQSEL4, 0x0004
        .equiv  DMA0REQ_IRQSEL4_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL4_MASK, 0x0010
        .equiv  IRQSEL4, 0x0004

        .equiv  DMA0REQ_IRQSEL5, 0x0005
        .equiv  DMA0REQ_IRQSEL5_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL5_MASK, 0x0020
        .equiv  IRQSEL5, 0x0005

        .equiv  DMA0REQ_IRQSEL6, 0x0006
        .equiv  DMA0REQ_IRQSEL6_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL6_MASK, 0x0040
        .equiv  IRQSEL6, 0x0006

        .equiv  DMA0REQ_IRQSEL7, 0x0007
        .equiv  DMA0REQ_IRQSEL7_WIDTH, 0x0001
        .equiv  DMA0REQ_IRQSEL7_MASK, 0x0080
        .equiv  IRQSEL7, 0x0007

;----- DMA0STAH Bits -----------------------------------------------------
        .equiv  DMA0STAH_STA, 0x0000
        .equiv  DMA0STAH_STA_WIDTH, 0x0008
        .equiv  DMA0STAH_STA_MASK, 0x00FF

;----- DMA0STBH Bits -----------------------------------------------------
        .equiv  DMA0STBH_STB, 0x0000
        .equiv  DMA0STBH_STB_WIDTH, 0x0008
        .equiv  DMA0STBH_STB_MASK, 0x00FF

;----- DMA0CNT Bits -----------------------------------------------------
        .equiv  DMA0CNT_CNT, 0x0000
        .equiv  DMA0CNT_CNT_WIDTH, 0x000E
        .equiv  DMA0CNT_CNT_MASK, 0x3FFF

;----- DMA1CON Bits -----------------------------------------------------
        .equiv  DMA1CON_MODE, 0x0000
        .equiv  DMA1CON_MODE_WIDTH, 0x0002
        .equiv  DMA1CON_MODE_MASK, 0x0003

        .equiv  DMA1CON_AMODE, 0x0004
        .equiv  DMA1CON_AMODE_WIDTH, 0x0002
        .equiv  DMA1CON_AMODE_MASK, 0x0030

        .equiv  DMA1CON_NULLW, 0x000B
        .equiv  DMA1CON_NULLW_WIDTH, 0x0001
        .equiv  DMA1CON_NULLW_MASK, 0x0800

        .equiv  DMA1CON_HALF, 0x000C
        .equiv  DMA1CON_HALF_WIDTH, 0x0001
        .equiv  DMA1CON_HALF_MASK, 0x1000

        .equiv  DMA1CON_DIR, 0x000D
        .equiv  DMA1CON_DIR_WIDTH, 0x0001
        .equiv  DMA1CON_DIR_MASK, 0x2000

        .equiv  DMA1CON_SIZE, 0x000E
        .equiv  DMA1CON_SIZE_WIDTH, 0x0001
        .equiv  DMA1CON_SIZE_MASK, 0x4000

        .equiv  DMA1CON_CHEN, 0x000F
        .equiv  DMA1CON_CHEN_WIDTH, 0x0001
        .equiv  DMA1CON_CHEN_MASK, 0x8000

        .equiv  DMA1CON_MODE0, 0x0000
        .equiv  DMA1CON_MODE0_WIDTH, 0x0001
        .equiv  DMA1CON_MODE0_MASK, 0x0001

        .equiv  DMA1CON_MODE1, 0x0001
        .equiv  DMA1CON_MODE1_WIDTH, 0x0001
        .equiv  DMA1CON_MODE1_MASK, 0x0002

        .equiv  DMA1CON_AMODE0, 0x0004
        .equiv  DMA1CON_AMODE0_WIDTH, 0x0001
        .equiv  DMA1CON_AMODE0_MASK, 0x0010

        .equiv  DMA1CON_AMODE1, 0x0005
        .equiv  DMA1CON_AMODE1_WIDTH, 0x0001
        .equiv  DMA1CON_AMODE1_MASK, 0x0020

;----- DMA1REQ Bits -----------------------------------------------------
        .equiv  DMA1REQ_IRQSEL, 0x0000
        .equiv  DMA1REQ_IRQSEL_WIDTH, 0x0008
        .equiv  DMA1REQ_IRQSEL_MASK, 0x00FF

        .equiv  DMA1REQ_FORCE, 0x000F
        .equiv  DMA1REQ_FORCE_WIDTH, 0x0001
        .equiv  DMA1REQ_FORCE_MASK, 0x8000

        .equiv  DMA1REQ_IRQSEL0, 0x0000
        .equiv  DMA1REQ_IRQSEL0_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL0_MASK, 0x0001

        .equiv  DMA1REQ_IRQSEL1, 0x0001
        .equiv  DMA1REQ_IRQSEL1_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL1_MASK, 0x0002

        .equiv  DMA1REQ_IRQSEL2, 0x0002
        .equiv  DMA1REQ_IRQSEL2_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL2_MASK, 0x0004

        .equiv  DMA1REQ_IRQSEL3, 0x0003
        .equiv  DMA1REQ_IRQSEL3_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL3_MASK, 0x0008

        .equiv  DMA1REQ_IRQSEL4, 0x0004
        .equiv  DMA1REQ_IRQSEL4_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL4_MASK, 0x0010

        .equiv  DMA1REQ_IRQSEL5, 0x0005
        .equiv  DMA1REQ_IRQSEL5_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL5_MASK, 0x0020

        .equiv  DMA1REQ_IRQSEL6, 0x0006
        .equiv  DMA1REQ_IRQSEL6_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL6_MASK, 0x0040

        .equiv  DMA1REQ_IRQSEL7, 0x0007
        .equiv  DMA1REQ_IRQSEL7_WIDTH, 0x0001
        .equiv  DMA1REQ_IRQSEL7_MASK, 0x0080

;----- DMA1STAH Bits -----------------------------------------------------
        .equiv  DMA1STAH_STA, 0x0000
        .equiv  DMA1STAH_STA_WIDTH, 0x0008
        .equiv  DMA1STAH_STA_MASK, 0x00FF

;----- DMA1STBH Bits -----------------------------------------------------
        .equiv  DMA1STBH_STB, 0x0000
        .equiv  DMA1STBH_STB_WIDTH, 0x0008
        .equiv  DMA1STBH_STB_MASK, 0x00FF

;----- DMA1CNT Bits -----------------------------------------------------
        .equiv  DMA1CNT_CNT, 0x0000
        .equiv  DMA1CNT_CNT_WIDTH, 0x000E
        .equiv  DMA1CNT_CNT_MASK, 0x3FFF

;----- DMA2CON Bits -----------------------------------------------------
        .equiv  DMA2CON_MODE, 0x0000
        .equiv  DMA2CON_MODE_WIDTH, 0x0002
        .equiv  DMA2CON_MODE_MASK, 0x0003

        .equiv  DMA2CON_AMODE, 0x0004
        .equiv  DMA2CON_AMODE_WIDTH, 0x0002
        .equiv  DMA2CON_AMODE_MASK, 0x0030

        .equiv  DMA2CON_NULLW, 0x000B
        .equiv  DMA2CON_NULLW_WIDTH, 0x0001
        .equiv  DMA2CON_NULLW_MASK, 0x0800

        .equiv  DMA2CON_HALF, 0x000C
        .equiv  DMA2CON_HALF_WIDTH, 0x0001
        .equiv  DMA2CON_HALF_MASK, 0x1000

        .equiv  DMA2CON_DIR, 0x000D
        .equiv  DMA2CON_DIR_WIDTH, 0x0001
        .equiv  DMA2CON_DIR_MASK, 0x2000

        .equiv  DMA2CON_SIZE, 0x000E
        .equiv  DMA2CON_SIZE_WIDTH, 0x0001
        .equiv  DMA2CON_SIZE_MASK, 0x4000

        .equiv  DMA2CON_CHEN, 0x000F
        .equiv  DMA2CON_CHEN_WIDTH, 0x0001
        .equiv  DMA2CON_CHEN_MASK, 0x8000

        .equiv  DMA2CON_MODE0, 0x0000
        .equiv  DMA2CON_MODE0_WIDTH, 0x0001
        .equiv  DMA2CON_MODE0_MASK, 0x0001

        .equiv  DMA2CON_MODE1, 0x0001
        .equiv  DMA2CON_MODE1_WIDTH, 0x0001
        .equiv  DMA2CON_MODE1_MASK, 0x0002

        .equiv  DMA2CON_AMODE0, 0x0004
        .equiv  DMA2CON_AMODE0_WIDTH, 0x0001
        .equiv  DMA2CON_AMODE0_MASK, 0x0010

        .equiv  DMA2CON_AMODE1, 0x0005
        .equiv  DMA2CON_AMODE1_WIDTH, 0x0001
        .equiv  DMA2CON_AMODE1_MASK, 0x0020

;----- DMA2REQ Bits -----------------------------------------------------
        .equiv  DMA2REQ_IRQSEL, 0x0000
        .equiv  DMA2REQ_IRQSEL_WIDTH, 0x0008
        .equiv  DMA2REQ_IRQSEL_MASK, 0x00FF

        .equiv  DMA2REQ_FORCE, 0x000F
        .equiv  DMA2REQ_FORCE_WIDTH, 0x0001
        .equiv  DMA2REQ_FORCE_MASK, 0x8000

        .equiv  DMA2REQ_IRQSEL0, 0x0000
        .equiv  DMA2REQ_IRQSEL0_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL0_MASK, 0x0001

        .equiv  DMA2REQ_IRQSEL1, 0x0001
        .equiv  DMA2REQ_IRQSEL1_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL1_MASK, 0x0002

        .equiv  DMA2REQ_IRQSEL2, 0x0002
        .equiv  DMA2REQ_IRQSEL2_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL2_MASK, 0x0004

        .equiv  DMA2REQ_IRQSEL3, 0x0003
        .equiv  DMA2REQ_IRQSEL3_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL3_MASK, 0x0008

        .equiv  DMA2REQ_IRQSEL4, 0x0004
        .equiv  DMA2REQ_IRQSEL4_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL4_MASK, 0x0010

        .equiv  DMA2REQ_IRQSEL5, 0x0005
        .equiv  DMA2REQ_IRQSEL5_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL5_MASK, 0x0020

        .equiv  DMA2REQ_IRQSEL6, 0x0006
        .equiv  DMA2REQ_IRQSEL6_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL6_MASK, 0x0040

        .equiv  DMA2REQ_IRQSEL7, 0x0007
        .equiv  DMA2REQ_IRQSEL7_WIDTH, 0x0001
        .equiv  DMA2REQ_IRQSEL7_MASK, 0x0080

;----- DMA2STAH Bits -----------------------------------------------------
        .equiv  DMA2STAH_STA, 0x0000
        .equiv  DMA2STAH_STA_WIDTH, 0x0008
        .equiv  DMA2STAH_STA_MASK, 0x00FF

;----- DMA2STBH Bits -----------------------------------------------------
        .equiv  DMA2STBH_STB, 0x0000
        .equiv  DMA2STBH_STB_WIDTH, 0x0008
        .equiv  DMA2STBH_STB_MASK, 0x00FF

;----- DMA2CNT Bits -----------------------------------------------------
        .equiv  DMA2CNT_CNT, 0x0000
        .equiv  DMA2CNT_CNT_WIDTH, 0x000E
        .equiv  DMA2CNT_CNT_MASK, 0x3FFF

;----- DMA3CON Bits -----------------------------------------------------
        .equiv  DMA3CON_MODE, 0x0000
        .equiv  DMA3CON_MODE_WIDTH, 0x0002
        .equiv  DMA3CON_MODE_MASK, 0x0003

        .equiv  DMA3CON_AMODE, 0x0004
        .equiv  DMA3CON_AMODE_WIDTH, 0x0002
        .equiv  DMA3CON_AMODE_MASK, 0x0030

        .equiv  DMA3CON_NULLW, 0x000B
        .equiv  DMA3CON_NULLW_WIDTH, 0x0001
        .equiv  DMA3CON_NULLW_MASK, 0x0800

        .equiv  DMA3CON_HALF, 0x000C
        .equiv  DMA3CON_HALF_WIDTH, 0x0001
        .equiv  DMA3CON_HALF_MASK, 0x1000

        .equiv  DMA3CON_DIR, 0x000D
        .equiv  DMA3CON_DIR_WIDTH, 0x0001
        .equiv  DMA3CON_DIR_MASK, 0x2000

        .equiv  DMA3CON_SIZE, 0x000E
        .equiv  DMA3CON_SIZE_WIDTH, 0x0001
        .equiv  DMA3CON_SIZE_MASK, 0x4000

        .equiv  DMA3CON_CHEN, 0x000F
        .equiv  DMA3CON_CHEN_WIDTH, 0x0001
        .equiv  DMA3CON_CHEN_MASK, 0x8000

        .equiv  DMA3CON_MODE0, 0x0000
        .equiv  DMA3CON_MODE0_WIDTH, 0x0001
        .equiv  DMA3CON_MODE0_MASK, 0x0001

        .equiv  DMA3CON_MODE1, 0x0001
        .equiv  DMA3CON_MODE1_WIDTH, 0x0001
        .equiv  DMA3CON_MODE1_MASK, 0x0002

        .equiv  DMA3CON_AMODE0, 0x0004
        .equiv  DMA3CON_AMODE0_WIDTH, 0x0001
        .equiv  DMA3CON_AMODE0_MASK, 0x0010

        .equiv  DMA3CON_AMODE1, 0x0005
        .equiv  DMA3CON_AMODE1_WIDTH, 0x0001
        .equiv  DMA3CON_AMODE1_MASK, 0x0020

;----- DMA3REQ Bits -----------------------------------------------------
        .equiv  DMA3REQ_IRQSEL, 0x0000
        .equiv  DMA3REQ_IRQSEL_WIDTH, 0x0008
        .equiv  DMA3REQ_IRQSEL_MASK, 0x00FF

        .equiv  DMA3REQ_FORCE, 0x000F
        .equiv  DMA3REQ_FORCE_WIDTH, 0x0001
        .equiv  DMA3REQ_FORCE_MASK, 0x8000

        .equiv  DMA3REQ_IRQSEL0, 0x0000
        .equiv  DMA3REQ_IRQSEL0_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL0_MASK, 0x0001

        .equiv  DMA3REQ_IRQSEL1, 0x0001
        .equiv  DMA3REQ_IRQSEL1_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL1_MASK, 0x0002

        .equiv  DMA3REQ_IRQSEL2, 0x0002
        .equiv  DMA3REQ_IRQSEL2_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL2_MASK, 0x0004

        .equiv  DMA3REQ_IRQSEL3, 0x0003
        .equiv  DMA3REQ_IRQSEL3_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL3_MASK, 0x0008

        .equiv  DMA3REQ_IRQSEL4, 0x0004
        .equiv  DMA3REQ_IRQSEL4_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL4_MASK, 0x0010

        .equiv  DMA3REQ_IRQSEL5, 0x0005
        .equiv  DMA3REQ_IRQSEL5_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL5_MASK, 0x0020

        .equiv  DMA3REQ_IRQSEL6, 0x0006
        .equiv  DMA3REQ_IRQSEL6_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL6_MASK, 0x0040

        .equiv  DMA3REQ_IRQSEL7, 0x0007
        .equiv  DMA3REQ_IRQSEL7_WIDTH, 0x0001
        .equiv  DMA3REQ_IRQSEL7_MASK, 0x0080

;----- DMA3STAH Bits -----------------------------------------------------
        .equiv  DMA3STAH_STA, 0x0000
        .equiv  DMA3STAH_STA_WIDTH, 0x0008
        .equiv  DMA3STAH_STA_MASK, 0x00FF

;----- DMA3STBH Bits -----------------------------------------------------
        .equiv  DMA3STBH_STB, 0x0000
        .equiv  DMA3STBH_STB_WIDTH, 0x0008
        .equiv  DMA3STBH_STB_MASK, 0x00FF

;----- DMA3CNT Bits -----------------------------------------------------
        .equiv  DMA3CNT_CNT, 0x0000
        .equiv  DMA3CNT_CNT_WIDTH, 0x000E
        .equiv  DMA3CNT_CNT_MASK, 0x3FFF

;----- DMAPWC Bits -----------------------------------------------------
        .equiv  DMAPWC_PWCOL0, 0x0000
        .equiv  DMAPWC_PWCOL0_WIDTH, 0x0001
        .equiv  DMAPWC_PWCOL0_MASK, 0x0001
        .equiv  PWCOL0, 0x0000

        .equiv  DMAPWC_PWCOL1, 0x0001
        .equiv  DMAPWC_PWCOL1_WIDTH, 0x0001
        .equiv  DMAPWC_PWCOL1_MASK, 0x0002
        .equiv  PWCOL1, 0x0001

        .equiv  DMAPWC_PWCOL2, 0x0002
        .equiv  DMAPWC_PWCOL2_WIDTH, 0x0001
        .equiv  DMAPWC_PWCOL2_MASK, 0x0004
        .equiv  PWCOL2, 0x0002

        .equiv  DMAPWC_PWCOL3, 0x0003
        .equiv  DMAPWC_PWCOL3_WIDTH, 0x0001
        .equiv  DMAPWC_PWCOL3_MASK, 0x0008
        .equiv  PWCOL3, 0x0003

;----- DMARQC Bits -----------------------------------------------------
        .equiv  DMARQC_RQCOL0, 0x0000
        .equiv  DMARQC_RQCOL0_WIDTH, 0x0001
        .equiv  DMARQC_RQCOL0_MASK, 0x0001
        .equiv  RQCOL0, 0x0000

        .equiv  DMARQC_RQCOL1, 0x0001
        .equiv  DMARQC_RQCOL1_WIDTH, 0x0001
        .equiv  DMARQC_RQCOL1_MASK, 0x0002
        .equiv  RQCOL1, 0x0001

        .equiv  DMARQC_RQCOL2, 0x0002
        .equiv  DMARQC_RQCOL2_WIDTH, 0x0001
        .equiv  DMARQC_RQCOL2_MASK, 0x0004
        .equiv  RQCOL2, 0x0002

        .equiv  DMARQC_RQCOL3, 0x0003
        .equiv  DMARQC_RQCOL3_WIDTH, 0x0001
        .equiv  DMARQC_RQCOL3_MASK, 0x0008
        .equiv  RQCOL3, 0x0003

;----- DMAPPS Bits -----------------------------------------------------
        .equiv  DMAPPS_PPST0, 0x0000
        .equiv  DMAPPS_PPST0_WIDTH, 0x0001
        .equiv  DMAPPS_PPST0_MASK, 0x0001
        .equiv  PPST0, 0x0000

        .equiv  DMAPPS_PPST1, 0x0001
        .equiv  DMAPPS_PPST1_WIDTH, 0x0001
        .equiv  DMAPPS_PPST1_MASK, 0x0002
        .equiv  PPST1, 0x0001

        .equiv  DMAPPS_PPST2, 0x0002
        .equiv  DMAPPS_PPST2_WIDTH, 0x0001
        .equiv  DMAPPS_PPST2_MASK, 0x0004
        .equiv  PPST2, 0x0002

        .equiv  DMAPPS_PPST3, 0x0003
        .equiv  DMAPPS_PPST3_WIDTH, 0x0001
        .equiv  DMAPPS_PPST3_MASK, 0x0008
        .equiv  PPST3, 0x0003

;----- DMALCA Bits -----------------------------------------------------
        .equiv  DMALCA_LSTCH, 0x0000
        .equiv  DMALCA_LSTCH_WIDTH, 0x0004
        .equiv  DMALCA_LSTCH_MASK, 0x000F

        .equiv  DMALCA_LSTCH0, 0x0000
        .equiv  DMALCA_LSTCH0_WIDTH, 0x0001
        .equiv  DMALCA_LSTCH0_MASK, 0x0001
        .equiv  LSTCH0, 0x0000

        .equiv  DMALCA_LSTCH1, 0x0001
        .equiv  DMALCA_LSTCH1_WIDTH, 0x0001
        .equiv  DMALCA_LSTCH1_MASK, 0x0002
        .equiv  LSTCH1, 0x0001

        .equiv  DMALCA_LSTCH2, 0x0002
        .equiv  DMALCA_LSTCH2_WIDTH, 0x0001
        .equiv  DMALCA_LSTCH2_MASK, 0x0004
        .equiv  LSTCH2, 0x0002

        .equiv  DMALCA_LSTCH3, 0x0003
        .equiv  DMALCA_LSTCH3_WIDTH, 0x0001
        .equiv  DMALCA_LSTCH3_MASK, 0x0008
        .equiv  LSTCH3, 0x0003

;----- DSADRH Bits -----------------------------------------------------
        .equiv  DSADRH_DSADR, 0x0000
        .equiv  DSADRH_DSADR_WIDTH, 0x0008
        .equiv  DSADRH_DSADR_MASK, 0x00FF

;----- PTCON Bits -----------------------------------------------------
        .equiv  PTCON_SEVTPS, 0x0000
        .equiv  PTCON_SEVTPS_WIDTH, 0x0004
        .equiv  PTCON_SEVTPS_MASK, 0x000F

        .equiv  PTCON_SYNCSRC, 0x0004
        .equiv  PTCON_SYNCSRC_WIDTH, 0x0003
        .equiv  PTCON_SYNCSRC_MASK, 0x0070

        .equiv  PTCON_SYNCEN, 0x0007
        .equiv  PTCON_SYNCEN_WIDTH, 0x0001
        .equiv  PTCON_SYNCEN_MASK, 0x0080
        .equiv  SYNCEN, 0x0007

        .equiv  PTCON_SYNCOEN, 0x0008
        .equiv  PTCON_SYNCOEN_WIDTH, 0x0001
        .equiv  PTCON_SYNCOEN_MASK, 0x0100
        .equiv  SYNCOEN, 0x0008

        .equiv  PTCON_SYNCPOL, 0x0009
        .equiv  PTCON_SYNCPOL_WIDTH, 0x0001
        .equiv  PTCON_SYNCPOL_MASK, 0x0200
        .equiv  SYNCPOL, 0x0009

        .equiv  PTCON_EIPU, 0x000A
        .equiv  PTCON_EIPU_WIDTH, 0x0001
        .equiv  PTCON_EIPU_MASK, 0x0400
        .equiv  EIPU, 0x000A

        .equiv  PTCON_SEIEN, 0x000B
        .equiv  PTCON_SEIEN_WIDTH, 0x0001
        .equiv  PTCON_SEIEN_MASK, 0x0800
        .equiv  SEIEN, 0x000B

        .equiv  PTCON_SESTAT, 0x000C
        .equiv  PTCON_SESTAT_WIDTH, 0x0001
        .equiv  PTCON_SESTAT_MASK, 0x1000
        .equiv  SESTAT, 0x000C

        .equiv  PTCON_PTSIDL, 0x000D
        .equiv  PTCON_PTSIDL_WIDTH, 0x0001
        .equiv  PTCON_PTSIDL_MASK, 0x2000
        .equiv  PTSIDL, 0x000D

        .equiv  PTCON_PTEN, 0x000F
        .equiv  PTCON_PTEN_WIDTH, 0x0001
        .equiv  PTCON_PTEN_MASK, 0x8000
        .equiv  PTEN, 0x000F

        .equiv  PTCON_SEVTPS0, 0x0000
        .equiv  PTCON_SEVTPS0_WIDTH, 0x0001
        .equiv  PTCON_SEVTPS0_MASK, 0x0001
        .equiv  SEVTPS0, 0x0000

        .equiv  PTCON_SEVTPS1, 0x0001
        .equiv  PTCON_SEVTPS1_WIDTH, 0x0001
        .equiv  PTCON_SEVTPS1_MASK, 0x0002
        .equiv  SEVTPS1, 0x0001

        .equiv  PTCON_SEVTPS2, 0x0002
        .equiv  PTCON_SEVTPS2_WIDTH, 0x0001
        .equiv  PTCON_SEVTPS2_MASK, 0x0004
        .equiv  SEVTPS2, 0x0002

        .equiv  PTCON_SEVTPS3, 0x0003
        .equiv  PTCON_SEVTPS3_WIDTH, 0x0001
        .equiv  PTCON_SEVTPS3_MASK, 0x0008
        .equiv  SEVTPS3, 0x0003

        .equiv  PTCON_SYNCSRC0, 0x0004
        .equiv  PTCON_SYNCSRC0_WIDTH, 0x0001
        .equiv  PTCON_SYNCSRC0_MASK, 0x0010
        .equiv  SYNCSRC0, 0x0004

        .equiv  PTCON_SYNCSRC1, 0x0005
        .equiv  PTCON_SYNCSRC1_WIDTH, 0x0001
        .equiv  PTCON_SYNCSRC1_MASK, 0x0020
        .equiv  SYNCSRC1, 0x0005

        .equiv  PTCON_SYNCSRC2, 0x0006
        .equiv  PTCON_SYNCSRC2_WIDTH, 0x0001
        .equiv  PTCON_SYNCSRC2_MASK, 0x0040
        .equiv  SYNCSRC2, 0x0006

;----- PTCON2 Bits -----------------------------------------------------
        .equiv  PTCON2_PCLKDIV, 0x0000
        .equiv  PTCON2_PCLKDIV_WIDTH, 0x0003
        .equiv  PTCON2_PCLKDIV_MASK, 0x0007

        .equiv  PTCON2_PCLKDIV0, 0x0000
        .equiv  PTCON2_PCLKDIV0_WIDTH, 0x0001
        .equiv  PTCON2_PCLKDIV0_MASK, 0x0001
        .equiv  PCLKDIV0, 0x0000

        .equiv  PTCON2_PCLKDIV1, 0x0001
        .equiv  PTCON2_PCLKDIV1_WIDTH, 0x0001
        .equiv  PTCON2_PCLKDIV1_MASK, 0x0002
        .equiv  PCLKDIV1, 0x0001

        .equiv  PTCON2_PCLKDIV2, 0x0002
        .equiv  PTCON2_PCLKDIV2_WIDTH, 0x0001
        .equiv  PTCON2_PCLKDIV2_MASK, 0x0004
        .equiv  PCLKDIV2, 0x0002

;----- SEVTCMP Bits -----------------------------------------------------
        .equiv  SEVTCMP, 0x0003
        .equiv  SEVTCMP_WIDTH, 0x000D
        .equiv  SEVTCMP_MASK, 0xFFF8

;----- CHOP Bits -----------------------------------------------------
        .equiv  CHOP_CHOPCLK, 0x0000
        .equiv  CHOP_CHOPCLK_WIDTH, 0x000A
        .equiv  CHOP_CHOPCLK_MASK, 0x03FF

        .equiv  CHOP_CHPCLKEN, 0x000F
        .equiv  CHOP_CHPCLKEN_WIDTH, 0x0001
        .equiv  CHOP_CHPCLKEN_MASK, 0x8000
        .equiv  CHPCLKEN, 0x000F

        .equiv  CHOP_CHOPCLK0, 0x0000
        .equiv  CHOP_CHOPCLK0_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK0_MASK, 0x0001
        .equiv  CHOPCLK0, 0x0000

        .equiv  CHOP_CHOPCLK1, 0x0001
        .equiv  CHOP_CHOPCLK1_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK1_MASK, 0x0002
        .equiv  CHOPCLK1, 0x0001

        .equiv  CHOP_CHOPCLK2, 0x0002
        .equiv  CHOP_CHOPCLK2_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK2_MASK, 0x0004
        .equiv  CHOPCLK2, 0x0002

        .equiv  CHOP_CHOPCLK3, 0x0003
        .equiv  CHOP_CHOPCLK3_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK3_MASK, 0x0008
        .equiv  CHOPCLK3, 0x0003

        .equiv  CHOP_CHOPCLK4, 0x0004
        .equiv  CHOP_CHOPCLK4_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK4_MASK, 0x0010
        .equiv  CHOPCLK4, 0x0004

        .equiv  CHOP_CHOPCLK5, 0x0005
        .equiv  CHOP_CHOPCLK5_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK5_MASK, 0x0020
        .equiv  CHOPCLK5, 0x0005

        .equiv  CHOP_CHOPCLK6, 0x0006
        .equiv  CHOP_CHOPCLK6_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK6_MASK, 0x0040
        .equiv  CHOPCLK6, 0x0006

        .equiv  CHOP_CHOPCLK7, 0x0007
        .equiv  CHOP_CHOPCLK7_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK7_MASK, 0x0080
        .equiv  CHOPCLK7, 0x0007

        .equiv  CHOP_CHOPCLK8, 0x0008
        .equiv  CHOP_CHOPCLK8_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK8_MASK, 0x0100
        .equiv  CHOPCLK8, 0x0008

        .equiv  CHOP_CHOPCLK9, 0x0009
        .equiv  CHOP_CHOPCLK9_WIDTH, 0x0001
        .equiv  CHOP_CHOPCLK9_MASK, 0x0200
        .equiv  CHOPCLK9, 0x0009

;----- PWMCON1 Bits -----------------------------------------------------
        .equiv  PWMCON1_IUE, 0x0000
        .equiv  PWMCON1_IUE_WIDTH, 0x0001
        .equiv  PWMCON1_IUE_MASK, 0x0001
        .equiv  IUE, 0x0000

        .equiv  PWMCON1_XPRES, 0x0001
        .equiv  PWMCON1_XPRES_WIDTH, 0x0001
        .equiv  PWMCON1_XPRES_MASK, 0x0002
        .equiv  XPRES, 0x0001

        .equiv  PWMCON1_CAM, 0x0002
        .equiv  PWMCON1_CAM_WIDTH, 0x0001
        .equiv  PWMCON1_CAM_MASK, 0x0004
        .equiv  CAM, 0x0002

        .equiv  PWMCON1_MTBS, 0x0003
        .equiv  PWMCON1_MTBS_WIDTH, 0x0001
        .equiv  PWMCON1_MTBS_MASK, 0x0008
        .equiv  MTBS, 0x0003

        .equiv  PWMCON1_DTCP, 0x0005
        .equiv  PWMCON1_DTCP_WIDTH, 0x0001
        .equiv  PWMCON1_DTCP_MASK, 0x0020
        .equiv  DTCP, 0x0005

        .equiv  PWMCON1_DTC, 0x0006
        .equiv  PWMCON1_DTC_WIDTH, 0x0002
        .equiv  PWMCON1_DTC_MASK, 0x00C0

        .equiv  PWMCON1_MDCS, 0x0008
        .equiv  PWMCON1_MDCS_WIDTH, 0x0001
        .equiv  PWMCON1_MDCS_MASK, 0x0100
        .equiv  MDCS, 0x0008

        .equiv  PWMCON1_ITB, 0x0009
        .equiv  PWMCON1_ITB_WIDTH, 0x0001
        .equiv  PWMCON1_ITB_MASK, 0x0200
        .equiv  ITB, 0x0009

        .equiv  PWMCON1_TRGIEN, 0x000A
        .equiv  PWMCON1_TRGIEN_WIDTH, 0x0001
        .equiv  PWMCON1_TRGIEN_MASK, 0x0400
        .equiv  TRGIEN, 0x000A

        .equiv  PWMCON1_CLIEN, 0x000B
        .equiv  PWMCON1_CLIEN_WIDTH, 0x0001
        .equiv  PWMCON1_CLIEN_MASK, 0x0800
        .equiv  CLIEN, 0x000B

        .equiv  PWMCON1_FLTIEN, 0x000C
        .equiv  PWMCON1_FLTIEN_WIDTH, 0x0001
        .equiv  PWMCON1_FLTIEN_MASK, 0x1000
        .equiv  FLTIEN, 0x000C

        .equiv  PWMCON1_TRGSTAT, 0x000D
        .equiv  PWMCON1_TRGSTAT_WIDTH, 0x0001
        .equiv  PWMCON1_TRGSTAT_MASK, 0x2000
        .equiv  TRGSTAT, 0x000D

        .equiv  PWMCON1_CLSTAT, 0x000E
        .equiv  PWMCON1_CLSTAT_WIDTH, 0x0001
        .equiv  PWMCON1_CLSTAT_MASK, 0x4000
        .equiv  CLSTAT, 0x000E

        .equiv  PWMCON1_FLTSTAT, 0x000F
        .equiv  PWMCON1_FLTSTAT_WIDTH, 0x0001
        .equiv  PWMCON1_FLTSTAT_MASK, 0x8000
        .equiv  FLTSTAT, 0x000F

        .equiv  PWMCON1_DTC0, 0x0006
        .equiv  PWMCON1_DTC0_WIDTH, 0x0001
        .equiv  PWMCON1_DTC0_MASK, 0x0040
        .equiv  DTC0, 0x0006

        .equiv  PWMCON1_DTC1, 0x0007
        .equiv  PWMCON1_DTC1_WIDTH, 0x0001
        .equiv  PWMCON1_DTC1_MASK, 0x0080
        .equiv  DTC1, 0x0007

;----- IOCON1 Bits -----------------------------------------------------
        .equiv  IOCON1_OSYNC, 0x0000
        .equiv  IOCON1_OSYNC_WIDTH, 0x0001
        .equiv  IOCON1_OSYNC_MASK, 0x0001
        .equiv  OSYNC, 0x0000

        .equiv  IOCON1_SWAP, 0x0001
        .equiv  IOCON1_SWAP_WIDTH, 0x0001
        .equiv  IOCON1_SWAP_MASK, 0x0002
        .equiv  SWAP, 0x0001

        .equiv  IOCON1_CLDAT, 0x0002
        .equiv  IOCON1_CLDAT_WIDTH, 0x0002
        .equiv  IOCON1_CLDAT_MASK, 0x000C

        .equiv  IOCON1_FLTDAT, 0x0004
        .equiv  IOCON1_FLTDAT_WIDTH, 0x0002
        .equiv  IOCON1_FLTDAT_MASK, 0x0030

        .equiv  IOCON1_OVRDAT, 0x0006
        .equiv  IOCON1_OVRDAT_WIDTH, 0x0002
        .equiv  IOCON1_OVRDAT_MASK, 0x00C0

        .equiv  IOCON1_OVRENL, 0x0008
        .equiv  IOCON1_OVRENL_WIDTH, 0x0001
        .equiv  IOCON1_OVRENL_MASK, 0x0100
        .equiv  OVRENL, 0x0008

        .equiv  IOCON1_OVRENH, 0x0009
        .equiv  IOCON1_OVRENH_WIDTH, 0x0001
        .equiv  IOCON1_OVRENH_MASK, 0x0200
        .equiv  OVRENH, 0x0009

        .equiv  IOCON1_PMOD, 0x000A
        .equiv  IOCON1_PMOD_WIDTH, 0x0002
        .equiv  IOCON1_PMOD_MASK, 0x0C00

        .equiv  IOCON1_POLL, 0x000C
        .equiv  IOCON1_POLL_WIDTH, 0x0001
        .equiv  IOCON1_POLL_MASK, 0x1000
        .equiv  POLL, 0x000C

        .equiv  IOCON1_POLH, 0x000D
        .equiv  IOCON1_POLH_WIDTH, 0x0001
        .equiv  IOCON1_POLH_MASK, 0x2000
        .equiv  POLH, 0x000D

        .equiv  IOCON1_PENL, 0x000E
        .equiv  IOCON1_PENL_WIDTH, 0x0001
        .equiv  IOCON1_PENL_MASK, 0x4000
        .equiv  PENL, 0x000E

        .equiv  IOCON1_PENH, 0x000F
        .equiv  IOCON1_PENH_WIDTH, 0x0001
        .equiv  IOCON1_PENH_MASK, 0x8000
        .equiv  PENH, 0x000F

        .equiv  IOCON1_CLDAT0, 0x0002
        .equiv  IOCON1_CLDAT0_WIDTH, 0x0001
        .equiv  IOCON1_CLDAT0_MASK, 0x0004
        .equiv  CLDAT0, 0x0002

        .equiv  IOCON1_CLDAT1, 0x0003
        .equiv  IOCON1_CLDAT1_WIDTH, 0x0001
        .equiv  IOCON1_CLDAT1_MASK, 0x0008
        .equiv  CLDAT1, 0x0003

        .equiv  IOCON1_FLTDAT0, 0x0004
        .equiv  IOCON1_FLTDAT0_WIDTH, 0x0001
        .equiv  IOCON1_FLTDAT0_MASK, 0x0010
        .equiv  FLTDAT0, 0x0004

        .equiv  IOCON1_FLTDAT1, 0x0005
        .equiv  IOCON1_FLTDAT1_WIDTH, 0x0001
        .equiv  IOCON1_FLTDAT1_MASK, 0x0020
        .equiv  FLTDAT1, 0x0005

        .equiv  IOCON1_OVRDAT0, 0x0006
        .equiv  IOCON1_OVRDAT0_WIDTH, 0x0001
        .equiv  IOCON1_OVRDAT0_MASK, 0x0040
        .equiv  OVRDAT0, 0x0006

        .equiv  IOCON1_OVRDAT1, 0x0007
        .equiv  IOCON1_OVRDAT1_WIDTH, 0x0001
        .equiv  IOCON1_OVRDAT1_MASK, 0x0080
        .equiv  OVRDAT1, 0x0007

        .equiv  IOCON1_PMOD0, 0x000A
        .equiv  IOCON1_PMOD0_WIDTH, 0x0001
        .equiv  IOCON1_PMOD0_MASK, 0x0400
        .equiv  PMOD0, 0x000A

        .equiv  IOCON1_PMOD1, 0x000B
        .equiv  IOCON1_PMOD1_WIDTH, 0x0001
        .equiv  IOCON1_PMOD1_MASK, 0x0800
        .equiv  PMOD1, 0x000B

;----- FCLCON1 Bits -----------------------------------------------------
        .equiv  FCLCON1_FLTMOD, 0x0000
        .equiv  FCLCON1_FLTMOD_WIDTH, 0x0002
        .equiv  FCLCON1_FLTMOD_MASK, 0x0003

        .equiv  FCLCON1_FLTPOL, 0x0002
        .equiv  FCLCON1_FLTPOL_WIDTH, 0x0001
        .equiv  FCLCON1_FLTPOL_MASK, 0x0004
        .equiv  FLTPOL, 0x0002

        .equiv  FCLCON1_FLTSRC, 0x0003
        .equiv  FCLCON1_FLTSRC_WIDTH, 0x0005
        .equiv  FCLCON1_FLTSRC_MASK, 0x00F8

        .equiv  FCLCON1_CLMOD, 0x0008
        .equiv  FCLCON1_CLMOD_WIDTH, 0x0001
        .equiv  FCLCON1_CLMOD_MASK, 0x0100
        .equiv  CLMOD, 0x0008

        .equiv  FCLCON1_CLPOL, 0x0009
        .equiv  FCLCON1_CLPOL_WIDTH, 0x0001
        .equiv  FCLCON1_CLPOL_MASK, 0x0200
        .equiv  CLPOL, 0x0009

        .equiv  FCLCON1_CLSRC, 0x000A
        .equiv  FCLCON1_CLSRC_WIDTH, 0x0005
        .equiv  FCLCON1_CLSRC_MASK, 0x7C00

        .equiv  FCLCON1_FLTMOD0, 0x0000
        .equiv  FCLCON1_FLTMOD0_WIDTH, 0x0001
        .equiv  FCLCON1_FLTMOD0_MASK, 0x0001
        .equiv  FLTMOD0, 0x0000

        .equiv  FCLCON1_FLTMOD1, 0x0001
        .equiv  FCLCON1_FLTMOD1_WIDTH, 0x0001
        .equiv  FCLCON1_FLTMOD1_MASK, 0x0002
        .equiv  FLTMOD1, 0x0001

        .equiv  FCLCON1_FLTSRC0, 0x0003
        .equiv  FCLCON1_FLTSRC0_WIDTH, 0x0001
        .equiv  FCLCON1_FLTSRC0_MASK, 0x0008
        .equiv  FLTSRC0, 0x0003

        .equiv  FCLCON1_FLTSRC1, 0x0004
        .equiv  FCLCON1_FLTSRC1_WIDTH, 0x0001
        .equiv  FCLCON1_FLTSRC1_MASK, 0x0010
        .equiv  FLTSRC1, 0x0004

        .equiv  FCLCON1_FLTSRC2, 0x0005
        .equiv  FCLCON1_FLTSRC2_WIDTH, 0x0001
        .equiv  FCLCON1_FLTSRC2_MASK, 0x0020
        .equiv  FLTSRC2, 0x0005

        .equiv  FCLCON1_FLTSRC3, 0x0006
        .equiv  FCLCON1_FLTSRC3_WIDTH, 0x0001
        .equiv  FCLCON1_FLTSRC3_MASK, 0x0040
        .equiv  FLTSRC3, 0x0006

        .equiv  FCLCON1_FLTSRC4, 0x0007
        .equiv  FCLCON1_FLTSRC4_WIDTH, 0x0001
        .equiv  FCLCON1_FLTSRC4_MASK, 0x0080
        .equiv  FLTSRC4, 0x0007

        .equiv  FCLCON1_CLSRC0, 0x000A
        .equiv  FCLCON1_CLSRC0_WIDTH, 0x0001
        .equiv  FCLCON1_CLSRC0_MASK, 0x0400
        .equiv  CLSRC0, 0x000A

        .equiv  FCLCON1_CLSRC1, 0x000B
        .equiv  FCLCON1_CLSRC1_WIDTH, 0x0001
        .equiv  FCLCON1_CLSRC1_MASK, 0x0800
        .equiv  CLSRC1, 0x000B

        .equiv  FCLCON1_CLSRC2, 0x000C
        .equiv  FCLCON1_CLSRC2_WIDTH, 0x0001
        .equiv  FCLCON1_CLSRC2_MASK, 0x1000
        .equiv  CLSRC2, 0x000C

        .equiv  FCLCON1_CLSRC3, 0x000D
        .equiv  FCLCON1_CLSRC3_WIDTH, 0x0001
        .equiv  FCLCON1_CLSRC3_MASK, 0x2000
        .equiv  CLSRC3, 0x000D

        .equiv  FCLCON1_CLSRC4, 0x000E
        .equiv  FCLCON1_CLSRC4_WIDTH, 0x0001
        .equiv  FCLCON1_CLSRC4_MASK, 0x4000
        .equiv  CLSRC4, 0x000E

;----- TRIG1 Bits -----------------------------------------------------
        .equiv  TRIG1_TRGCMP, 0x0003
        .equiv  TRIG1_TRGCMP_WIDTH, 0x000D
        .equiv  TRIG1_TRGCMP_MASK, 0xFFF8

        .equiv  TRIG1_TRGCMP0, 0x0003
        .equiv  TRIG1_TRGCMP0_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP0_MASK, 0x0008
        .equiv  TRGCMP0, 0x0003

        .equiv  TRIG1_TRGCMP1, 0x0004
        .equiv  TRIG1_TRGCMP1_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP1_MASK, 0x0010
        .equiv  TRGCMP1, 0x0004

        .equiv  TRIG1_TRGCMP2, 0x0005
        .equiv  TRIG1_TRGCMP2_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP2_MASK, 0x0020
        .equiv  TRGCMP2, 0x0005

        .equiv  TRIG1_TRGCMP3, 0x0006
        .equiv  TRIG1_TRGCMP3_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP3_MASK, 0x0040
        .equiv  TRGCMP3, 0x0006

        .equiv  TRIG1_TRGCMP4, 0x0007
        .equiv  TRIG1_TRGCMP4_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP4_MASK, 0x0080
        .equiv  TRGCMP4, 0x0007

        .equiv  TRIG1_TRGCMP5, 0x0008
        .equiv  TRIG1_TRGCMP5_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP5_MASK, 0x0100
        .equiv  TRGCMP5, 0x0008

        .equiv  TRIG1_TRGCMP6, 0x0009
        .equiv  TRIG1_TRGCMP6_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP6_MASK, 0x0200
        .equiv  TRGCMP6, 0x0009

        .equiv  TRIG1_TRGCMP7, 0x000A
        .equiv  TRIG1_TRGCMP7_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP7_MASK, 0x0400
        .equiv  TRGCMP7, 0x000A

        .equiv  TRIG1_TRGCMP8, 0x000B
        .equiv  TRIG1_TRGCMP8_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP8_MASK, 0x0800
        .equiv  TRGCMP8, 0x000B

        .equiv  TRIG1_TRGCMP9, 0x000C
        .equiv  TRIG1_TRGCMP9_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP9_MASK, 0x1000
        .equiv  TRGCMP9, 0x000C

        .equiv  TRIG1_TRGCMP10, 0x000D
        .equiv  TRIG1_TRGCMP10_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP10_MASK, 0x2000
        .equiv  TRGCMP10, 0x000D

        .equiv  TRIG1_TRGCMP11, 0x000E
        .equiv  TRIG1_TRGCMP11_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP11_MASK, 0x4000
        .equiv  TRGCMP11, 0x000E

        .equiv  TRIG1_TRGCMP12, 0x000F
        .equiv  TRIG1_TRGCMP12_WIDTH, 0x0001
        .equiv  TRIG1_TRGCMP12_MASK, 0x8000
        .equiv  TRGCMP12, 0x000F

;----- TRGCON1 Bits -----------------------------------------------------
        .equiv  TRGCON1_TRGSTRT, 0x0000
        .equiv  TRGCON1_TRGSTRT_WIDTH, 0x0006
        .equiv  TRGCON1_TRGSTRT_MASK, 0x003F

        .equiv  TRGCON1_TRGDIV, 0x000C
        .equiv  TRGCON1_TRGDIV_WIDTH, 0x0004
        .equiv  TRGCON1_TRGDIV_MASK, 0xF000

        .equiv  TRGCON1_TRGSTRT0, 0x0000
        .equiv  TRGCON1_TRGSTRT0_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT0_MASK, 0x0001
        .equiv  TRGSTRT0, 0x0000

        .equiv  TRGCON1_TRGSTRT1, 0x0001
        .equiv  TRGCON1_TRGSTRT1_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT1_MASK, 0x0002
        .equiv  TRGSTRT1, 0x0001

        .equiv  TRGCON1_TRGSTRT2, 0x0002
        .equiv  TRGCON1_TRGSTRT2_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT2_MASK, 0x0004
        .equiv  TRGSTRT2, 0x0002

        .equiv  TRGCON1_TRGSTRT3, 0x0003
        .equiv  TRGCON1_TRGSTRT3_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT3_MASK, 0x0008
        .equiv  TRGSTRT3, 0x0003

        .equiv  TRGCON1_TRGSTRT4, 0x0004
        .equiv  TRGCON1_TRGSTRT4_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT4_MASK, 0x0010
        .equiv  TRGSTRT4, 0x0004

        .equiv  TRGCON1_TRGSTRT5, 0x0005
        .equiv  TRGCON1_TRGSTRT5_WIDTH, 0x0001
        .equiv  TRGCON1_TRGSTRT5_MASK, 0x0020
        .equiv  TRGSTRT5, 0x0005

        .equiv  TRGCON1_TRGDIV0, 0x000C
        .equiv  TRGCON1_TRGDIV0_WIDTH, 0x0001
        .equiv  TRGCON1_TRGDIV0_MASK, 0x1000
        .equiv  TRGDIV0, 0x000C

        .equiv  TRGCON1_TRGDIV1, 0x000D
        .equiv  TRGCON1_TRGDIV1_WIDTH, 0x0001
        .equiv  TRGCON1_TRGDIV1_MASK, 0x2000
        .equiv  TRGDIV1, 0x000D

        .equiv  TRGCON1_TRGDIV2, 0x000E
        .equiv  TRGCON1_TRGDIV2_WIDTH, 0x0001
        .equiv  TRGCON1_TRGDIV2_MASK, 0x4000
        .equiv  TRGDIV2, 0x000E

        .equiv  TRGCON1_TRGDIV3, 0x000F
        .equiv  TRGCON1_TRGDIV3_WIDTH, 0x0001
        .equiv  TRGCON1_TRGDIV3_MASK, 0x8000
        .equiv  TRGDIV3, 0x000F

;----- LEBCON1 Bits -----------------------------------------------------
        .equiv  LEBCON1_BPLL, 0x0000
        .equiv  LEBCON1_BPLL_WIDTH, 0x0001
        .equiv  LEBCON1_BPLL_MASK, 0x0001
        .equiv  BPLL, 0x0000

        .equiv  LEBCON1_BPLH, 0x0001
        .equiv  LEBCON1_BPLH_WIDTH, 0x0001
        .equiv  LEBCON1_BPLH_MASK, 0x0002
        .equiv  BPLH, 0x0001

        .equiv  LEBCON1_BPHL, 0x0002
        .equiv  LEBCON1_BPHL_WIDTH, 0x0001
        .equiv  LEBCON1_BPHL_MASK, 0x0004
        .equiv  BPHL, 0x0002

        .equiv  LEBCON1_BPHH, 0x0003
        .equiv  LEBCON1_BPHH_WIDTH, 0x0001
        .equiv  LEBCON1_BPHH_MASK, 0x0008
        .equiv  BPHH, 0x0003

        .equiv  LEBCON1_BCL_LEBCON1, 0x0004
        .equiv  LEBCON1_BCL_LEBCON1_WIDTH, 0x0001
        .equiv  LEBCON1_BCL_LEBCON1_MASK, 0x0010
        .equiv  BCL_LEBCON1, 0x0004

        .equiv  LEBCON1_BCH, 0x0005
        .equiv  LEBCON1_BCH_WIDTH, 0x0001
        .equiv  LEBCON1_BCH_MASK, 0x0020
        .equiv  BCH, 0x0005

        .equiv  LEBCON1_CLLEBEN, 0x000A
        .equiv  LEBCON1_CLLEBEN_WIDTH, 0x0001
        .equiv  LEBCON1_CLLEBEN_MASK, 0x0400
        .equiv  CLLEBEN, 0x000A

        .equiv  LEBCON1_FLTLEBEN, 0x000B
        .equiv  LEBCON1_FLTLEBEN_WIDTH, 0x0001
        .equiv  LEBCON1_FLTLEBEN_MASK, 0x0800
        .equiv  FLTLEBEN, 0x000B

        .equiv  LEBCON1_PLF, 0x000C
        .equiv  LEBCON1_PLF_WIDTH, 0x0001
        .equiv  LEBCON1_PLF_MASK, 0x1000
        .equiv  PLF, 0x000C

        .equiv  LEBCON1_PLR, 0x000D
        .equiv  LEBCON1_PLR_WIDTH, 0x0001
        .equiv  LEBCON1_PLR_MASK, 0x2000
        .equiv  PLR, 0x000D

        .equiv  LEBCON1_PHF, 0x000E
        .equiv  LEBCON1_PHF_WIDTH, 0x0001
        .equiv  LEBCON1_PHF_MASK, 0x4000
        .equiv  PHF, 0x000E

        .equiv  LEBCON1_PHR, 0x000F
        .equiv  LEBCON1_PHR_WIDTH, 0x0001
        .equiv  LEBCON1_PHR_MASK, 0x8000
        .equiv  PHR, 0x000F

;----- LEBDLY1 Bits -----------------------------------------------------
        .equiv  LEBDLY1_LEB, 0x0003
        .equiv  LEBDLY1_LEB_WIDTH, 0x0009
        .equiv  LEBDLY1_LEB_MASK, 0x0FF8

        .equiv  LEBDLY1_LEB0, 0x0003
        .equiv  LEBDLY1_LEB0_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB0_MASK, 0x0008
        .equiv  LEB0, 0x0003

        .equiv  LEBDLY1_LEB1, 0x0004
        .equiv  LEBDLY1_LEB1_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB1_MASK, 0x0010
        .equiv  LEB1, 0x0004

        .equiv  LEBDLY1_LEB2, 0x0005
        .equiv  LEBDLY1_LEB2_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB2_MASK, 0x0020
        .equiv  LEB2, 0x0005

        .equiv  LEBDLY1_LEB3, 0x0006
        .equiv  LEBDLY1_LEB3_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB3_MASK, 0x0040
        .equiv  LEB3, 0x0006

        .equiv  LEBDLY1_LEB4, 0x0007
        .equiv  LEBDLY1_LEB4_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB4_MASK, 0x0080
        .equiv  LEB4, 0x0007

        .equiv  LEBDLY1_LEB5, 0x0008
        .equiv  LEBDLY1_LEB5_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB5_MASK, 0x0100
        .equiv  LEB5, 0x0008

        .equiv  LEBDLY1_LEB6, 0x0009
        .equiv  LEBDLY1_LEB6_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB6_MASK, 0x0200
        .equiv  LEB6, 0x0009

        .equiv  LEBDLY1_LEB7, 0x000A
        .equiv  LEBDLY1_LEB7_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB7_MASK, 0x0400
        .equiv  LEB7, 0x000A

        .equiv  LEBDLY1_LEB8, 0x000B
        .equiv  LEBDLY1_LEB8_WIDTH, 0x0001
        .equiv  LEBDLY1_LEB8_MASK, 0x0800
        .equiv  LEB8, 0x000B

;----- AUXCON1 Bits -----------------------------------------------------
        .equiv  AUXCON1_CHOPLEN, 0x0000
        .equiv  AUXCON1_CHOPLEN_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPLEN_MASK, 0x0001
        .equiv  CHOPLEN, 0x0000

        .equiv  AUXCON1_CHOPHEN, 0x0001
        .equiv  AUXCON1_CHOPHEN_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPHEN_MASK, 0x0002
        .equiv  CHOPHEN, 0x0001

        .equiv  AUXCON1_CHOPSEL, 0x0002
        .equiv  AUXCON1_CHOPSEL_WIDTH, 0x0004
        .equiv  AUXCON1_CHOPSEL_MASK, 0x003C

        .equiv  AUXCON1_BLANKSEL, 0x0008
        .equiv  AUXCON1_BLANKSEL_WIDTH, 0x0004
        .equiv  AUXCON1_BLANKSEL_MASK, 0x0F00

        .equiv  AUXCON1_CHOPSEL0, 0x0002
        .equiv  AUXCON1_CHOPSEL0_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPSEL0_MASK, 0x0004
        .equiv  CHOPSEL0, 0x0002

        .equiv  AUXCON1_CHOPSEL1, 0x0003
        .equiv  AUXCON1_CHOPSEL1_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPSEL1_MASK, 0x0008
        .equiv  CHOPSEL1, 0x0003

        .equiv  AUXCON1_CHOPSEL2, 0x0004
        .equiv  AUXCON1_CHOPSEL2_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPSEL2_MASK, 0x0010
        .equiv  CHOPSEL2, 0x0004

        .equiv  AUXCON1_CHOPSEL3, 0x0005
        .equiv  AUXCON1_CHOPSEL3_WIDTH, 0x0001
        .equiv  AUXCON1_CHOPSEL3_MASK, 0x0020
        .equiv  CHOPSEL3, 0x0005

        .equiv  AUXCON1_BLANKSEL0, 0x0008
        .equiv  AUXCON1_BLANKSEL0_WIDTH, 0x0001
        .equiv  AUXCON1_BLANKSEL0_MASK, 0x0100
        .equiv  BLANKSEL0, 0x0008

        .equiv  AUXCON1_BLANKSEL1, 0x0009
        .equiv  AUXCON1_BLANKSEL1_WIDTH, 0x0001
        .equiv  AUXCON1_BLANKSEL1_MASK, 0x0200
        .equiv  BLANKSEL1, 0x0009

        .equiv  AUXCON1_BLANKSEL2, 0x000A
        .equiv  AUXCON1_BLANKSEL2_WIDTH, 0x0001
        .equiv  AUXCON1_BLANKSEL2_MASK, 0x0400
        .equiv  BLANKSEL2, 0x000A

        .equiv  AUXCON1_BLANKSEL3, 0x000B
        .equiv  AUXCON1_BLANKSEL3_WIDTH, 0x0001
        .equiv  AUXCON1_BLANKSEL3_MASK, 0x0800
        .equiv  BLANKSEL3, 0x000B

;----- PWMCON2 Bits -----------------------------------------------------
        .equiv  PWMCON2_IUE, 0x0000
        .equiv  PWMCON2_IUE_WIDTH, 0x0001
        .equiv  PWMCON2_IUE_MASK, 0x0001

        .equiv  PWMCON2_XPRES, 0x0001
        .equiv  PWMCON2_XPRES_WIDTH, 0x0001
        .equiv  PWMCON2_XPRES_MASK, 0x0002

        .equiv  PWMCON2_CAM, 0x0002
        .equiv  PWMCON2_CAM_WIDTH, 0x0001
        .equiv  PWMCON2_CAM_MASK, 0x0004

        .equiv  PWMCON2_MTBS, 0x0003
        .equiv  PWMCON2_MTBS_WIDTH, 0x0001
        .equiv  PWMCON2_MTBS_MASK, 0x0008

        .equiv  PWMCON2_DTCP, 0x0005
        .equiv  PWMCON2_DTCP_WIDTH, 0x0001
        .equiv  PWMCON2_DTCP_MASK, 0x0020

        .equiv  PWMCON2_DTC, 0x0006
        .equiv  PWMCON2_DTC_WIDTH, 0x0002
        .equiv  PWMCON2_DTC_MASK, 0x00C0

        .equiv  PWMCON2_MDCS, 0x0008
        .equiv  PWMCON2_MDCS_WIDTH, 0x0001
        .equiv  PWMCON2_MDCS_MASK, 0x0100

        .equiv  PWMCON2_ITB, 0x0009
        .equiv  PWMCON2_ITB_WIDTH, 0x0001
        .equiv  PWMCON2_ITB_MASK, 0x0200

        .equiv  PWMCON2_TRGIEN, 0x000A
        .equiv  PWMCON2_TRGIEN_WIDTH, 0x0001
        .equiv  PWMCON2_TRGIEN_MASK, 0x0400

        .equiv  PWMCON2_CLIEN, 0x000B
        .equiv  PWMCON2_CLIEN_WIDTH, 0x0001
        .equiv  PWMCON2_CLIEN_MASK, 0x0800

        .equiv  PWMCON2_FLTIEN, 0x000C
        .equiv  PWMCON2_FLTIEN_WIDTH, 0x0001
        .equiv  PWMCON2_FLTIEN_MASK, 0x1000

        .equiv  PWMCON2_TRGSTAT, 0x000D
        .equiv  PWMCON2_TRGSTAT_WIDTH, 0x0001
        .equiv  PWMCON2_TRGSTAT_MASK, 0x2000

        .equiv  PWMCON2_CLSTAT, 0x000E
        .equiv  PWMCON2_CLSTAT_WIDTH, 0x0001
        .equiv  PWMCON2_CLSTAT_MASK, 0x4000

        .equiv  PWMCON2_FLTSTAT, 0x000F
        .equiv  PWMCON2_FLTSTAT_WIDTH, 0x0001
        .equiv  PWMCON2_FLTSTAT_MASK, 0x8000

        .equiv  PWMCON2_DTC0, 0x0006
        .equiv  PWMCON2_DTC0_WIDTH, 0x0001
        .equiv  PWMCON2_DTC0_MASK, 0x0040

        .equiv  PWMCON2_DTC1, 0x0007
        .equiv  PWMCON2_DTC1_WIDTH, 0x0001
        .equiv  PWMCON2_DTC1_MASK, 0x0080

;----- IOCON2 Bits -----------------------------------------------------
        .equiv  IOCON2_OSYNC, 0x0000
        .equiv  IOCON2_OSYNC_WIDTH, 0x0001
        .equiv  IOCON2_OSYNC_MASK, 0x0001

        .equiv  IOCON2_SWAP, 0x0001
        .equiv  IOCON2_SWAP_WIDTH, 0x0001
        .equiv  IOCON2_SWAP_MASK, 0x0002

        .equiv  IOCON2_CLDAT, 0x0002
        .equiv  IOCON2_CLDAT_WIDTH, 0x0002
        .equiv  IOCON2_CLDAT_MASK, 0x000C

        .equiv  IOCON2_FLTDAT, 0x0004
        .equiv  IOCON2_FLTDAT_WIDTH, 0x0002
        .equiv  IOCON2_FLTDAT_MASK, 0x0030

        .equiv  IOCON2_OVRDAT, 0x0006
        .equiv  IOCON2_OVRDAT_WIDTH, 0x0002
        .equiv  IOCON2_OVRDAT_MASK, 0x00C0

        .equiv  IOCON2_OVRENL, 0x0008
        .equiv  IOCON2_OVRENL_WIDTH, 0x0001
        .equiv  IOCON2_OVRENL_MASK, 0x0100

        .equiv  IOCON2_OVRENH, 0x0009
        .equiv  IOCON2_OVRENH_WIDTH, 0x0001
        .equiv  IOCON2_OVRENH_MASK, 0x0200

        .equiv  IOCON2_PMOD, 0x000A
        .equiv  IOCON2_PMOD_WIDTH, 0x0002
        .equiv  IOCON2_PMOD_MASK, 0x0C00

        .equiv  IOCON2_POLL, 0x000C
        .equiv  IOCON2_POLL_WIDTH, 0x0001
        .equiv  IOCON2_POLL_MASK, 0x1000

        .equiv  IOCON2_POLH, 0x000D
        .equiv  IOCON2_POLH_WIDTH, 0x0001
        .equiv  IOCON2_POLH_MASK, 0x2000

        .equiv  IOCON2_PENL, 0x000E
        .equiv  IOCON2_PENL_WIDTH, 0x0001
        .equiv  IOCON2_PENL_MASK, 0x4000

        .equiv  IOCON2_PENH, 0x000F
        .equiv  IOCON2_PENH_WIDTH, 0x0001
        .equiv  IOCON2_PENH_MASK, 0x8000

        .equiv  IOCON2_CLDAT0, 0x0002
        .equiv  IOCON2_CLDAT0_WIDTH, 0x0001
        .equiv  IOCON2_CLDAT0_MASK, 0x0004

        .equiv  IOCON2_CLDAT1, 0x0003
        .equiv  IOCON2_CLDAT1_WIDTH, 0x0001
        .equiv  IOCON2_CLDAT1_MASK, 0x0008

        .equiv  IOCON2_FLTDAT0, 0x0004
        .equiv  IOCON2_FLTDAT0_WIDTH, 0x0001
        .equiv  IOCON2_FLTDAT0_MASK, 0x0010

        .equiv  IOCON2_FLTDAT1, 0x0005
        .equiv  IOCON2_FLTDAT1_WIDTH, 0x0001
        .equiv  IOCON2_FLTDAT1_MASK, 0x0020

        .equiv  IOCON2_OVRDAT0, 0x0006
        .equiv  IOCON2_OVRDAT0_WIDTH, 0x0001
        .equiv  IOCON2_OVRDAT0_MASK, 0x0040

        .equiv  IOCON2_OVRDAT1, 0x0007
        .equiv  IOCON2_OVRDAT1_WIDTH, 0x0001
        .equiv  IOCON2_OVRDAT1_MASK, 0x0080

        .equiv  IOCON2_PMOD0, 0x000A
        .equiv  IOCON2_PMOD0_WIDTH, 0x0001
        .equiv  IOCON2_PMOD0_MASK, 0x0400

        .equiv  IOCON2_PMOD1, 0x000B
        .equiv  IOCON2_PMOD1_WIDTH, 0x0001
        .equiv  IOCON2_PMOD1_MASK, 0x0800

;----- FCLCON2 Bits -----------------------------------------------------
        .equiv  FCLCON2_FLTMOD, 0x0000
        .equiv  FCLCON2_FLTMOD_WIDTH, 0x0002
        .equiv  FCLCON2_FLTMOD_MASK, 0x0003

        .equiv  FCLCON2_FLTPOL, 0x0002
        .equiv  FCLCON2_FLTPOL_WIDTH, 0x0001
        .equiv  FCLCON2_FLTPOL_MASK, 0x0004

        .equiv  FCLCON2_FLTSRC, 0x0003
        .equiv  FCLCON2_FLTSRC_WIDTH, 0x0005
        .equiv  FCLCON2_FLTSRC_MASK, 0x00F8

        .equiv  FCLCON2_CLMOD, 0x0008
        .equiv  FCLCON2_CLMOD_WIDTH, 0x0001
        .equiv  FCLCON2_CLMOD_MASK, 0x0100

        .equiv  FCLCON2_CLPOL, 0x0009
        .equiv  FCLCON2_CLPOL_WIDTH, 0x0001
        .equiv  FCLCON2_CLPOL_MASK, 0x0200

        .equiv  FCLCON2_CLSRC, 0x000A
        .equiv  FCLCON2_CLSRC_WIDTH, 0x0005
        .equiv  FCLCON2_CLSRC_MASK, 0x7C00

        .equiv  FCLCON2_FLTMOD0, 0x0000
        .equiv  FCLCON2_FLTMOD0_WIDTH, 0x0001
        .equiv  FCLCON2_FLTMOD0_MASK, 0x0001

        .equiv  FCLCON2_FLTMOD1, 0x0001
        .equiv  FCLCON2_FLTMOD1_WIDTH, 0x0001
        .equiv  FCLCON2_FLTMOD1_MASK, 0x0002

        .equiv  FCLCON2_FLTSRC0, 0x0003
        .equiv  FCLCON2_FLTSRC0_WIDTH, 0x0001
        .equiv  FCLCON2_FLTSRC0_MASK, 0x0008

        .equiv  FCLCON2_FLTSRC1, 0x0004
        .equiv  FCLCON2_FLTSRC1_WIDTH, 0x0001
        .equiv  FCLCON2_FLTSRC1_MASK, 0x0010

        .equiv  FCLCON2_FLTSRC2, 0x0005
        .equiv  FCLCON2_FLTSRC2_WIDTH, 0x0001
        .equiv  FCLCON2_FLTSRC2_MASK, 0x0020

        .equiv  FCLCON2_FLTSRC3, 0x0006
        .equiv  FCLCON2_FLTSRC3_WIDTH, 0x0001
        .equiv  FCLCON2_FLTSRC3_MASK, 0x0040

        .equiv  FCLCON2_FLTSRC4, 0x0007
        .equiv  FCLCON2_FLTSRC4_WIDTH, 0x0001
        .equiv  FCLCON2_FLTSRC4_MASK, 0x0080

        .equiv  FCLCON2_CLSRC0, 0x000A
        .equiv  FCLCON2_CLSRC0_WIDTH, 0x0001
        .equiv  FCLCON2_CLSRC0_MASK, 0x0400

        .equiv  FCLCON2_CLSRC1, 0x000B
        .equiv  FCLCON2_CLSRC1_WIDTH, 0x0001
        .equiv  FCLCON2_CLSRC1_MASK, 0x0800

        .equiv  FCLCON2_CLSRC2, 0x000C
        .equiv  FCLCON2_CLSRC2_WIDTH, 0x0001
        .equiv  FCLCON2_CLSRC2_MASK, 0x1000

        .equiv  FCLCON2_CLSRC3, 0x000D
        .equiv  FCLCON2_CLSRC3_WIDTH, 0x0001
        .equiv  FCLCON2_CLSRC3_MASK, 0x2000

        .equiv  FCLCON2_CLSRC4, 0x000E
        .equiv  FCLCON2_CLSRC4_WIDTH, 0x0001
        .equiv  FCLCON2_CLSRC4_MASK, 0x4000

;----- TRIG2 Bits -----------------------------------------------------
        .equiv  TRIG2_TRGCMP, 0x0003
        .equiv  TRIG2_TRGCMP_WIDTH, 0x000D
        .equiv  TRIG2_TRGCMP_MASK, 0xFFF8

        .equiv  TRIG2_TRGCMP0, 0x0003
        .equiv  TRIG2_TRGCMP0_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP0_MASK, 0x0008

        .equiv  TRIG2_TRGCMP1, 0x0004
        .equiv  TRIG2_TRGCMP1_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP1_MASK, 0x0010

        .equiv  TRIG2_TRGCMP2, 0x0005
        .equiv  TRIG2_TRGCMP2_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP2_MASK, 0x0020

        .equiv  TRIG2_TRGCMP3, 0x0006
        .equiv  TRIG2_TRGCMP3_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP3_MASK, 0x0040

        .equiv  TRIG2_TRGCMP4, 0x0007
        .equiv  TRIG2_TRGCMP4_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP4_MASK, 0x0080

        .equiv  TRIG2_TRGCMP5, 0x0008
        .equiv  TRIG2_TRGCMP5_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP5_MASK, 0x0100

        .equiv  TRIG2_TRGCMP6, 0x0009
        .equiv  TRIG2_TRGCMP6_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP6_MASK, 0x0200

        .equiv  TRIG2_TRGCMP7, 0x000A
        .equiv  TRIG2_TRGCMP7_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP7_MASK, 0x0400

        .equiv  TRIG2_TRGCMP8, 0x000B
        .equiv  TRIG2_TRGCMP8_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP8_MASK, 0x0800

        .equiv  TRIG2_TRGCMP9, 0x000C
        .equiv  TRIG2_TRGCMP9_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP9_MASK, 0x1000

        .equiv  TRIG2_TRGCMP10, 0x000D
        .equiv  TRIG2_TRGCMP10_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP10_MASK, 0x2000

        .equiv  TRIG2_TRGCMP11, 0x000E
        .equiv  TRIG2_TRGCMP11_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP11_MASK, 0x4000

        .equiv  TRIG2_TRGCMP12, 0x000F
        .equiv  TRIG2_TRGCMP12_WIDTH, 0x0001
        .equiv  TRIG2_TRGCMP12_MASK, 0x8000

;----- TRGCON2 Bits -----------------------------------------------------
        .equiv  TRGCON2_TRGSTRT, 0x0000
        .equiv  TRGCON2_TRGSTRT_WIDTH, 0x0006
        .equiv  TRGCON2_TRGSTRT_MASK, 0x003F

        .equiv  TRGCON2_TRGDIV, 0x000C
        .equiv  TRGCON2_TRGDIV_WIDTH, 0x0004
        .equiv  TRGCON2_TRGDIV_MASK, 0xF000

        .equiv  TRGCON2_TRGSTRT0, 0x0000
        .equiv  TRGCON2_TRGSTRT0_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT0_MASK, 0x0001

        .equiv  TRGCON2_TRGSTRT1, 0x0001
        .equiv  TRGCON2_TRGSTRT1_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT1_MASK, 0x0002

        .equiv  TRGCON2_TRGSTRT2, 0x0002
        .equiv  TRGCON2_TRGSTRT2_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT2_MASK, 0x0004

        .equiv  TRGCON2_TRGSTRT3, 0x0003
        .equiv  TRGCON2_TRGSTRT3_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT3_MASK, 0x0008

        .equiv  TRGCON2_TRGSTRT4, 0x0004
        .equiv  TRGCON2_TRGSTRT4_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT4_MASK, 0x0010

        .equiv  TRGCON2_TRGSTRT5, 0x0005
        .equiv  TRGCON2_TRGSTRT5_WIDTH, 0x0001
        .equiv  TRGCON2_TRGSTRT5_MASK, 0x0020

        .equiv  TRGCON2_TRGDIV0, 0x000C
        .equiv  TRGCON2_TRGDIV0_WIDTH, 0x0001
        .equiv  TRGCON2_TRGDIV0_MASK, 0x1000

        .equiv  TRGCON2_TRGDIV1, 0x000D
        .equiv  TRGCON2_TRGDIV1_WIDTH, 0x0001
        .equiv  TRGCON2_TRGDIV1_MASK, 0x2000

        .equiv  TRGCON2_TRGDIV2, 0x000E
        .equiv  TRGCON2_TRGDIV2_WIDTH, 0x0001
        .equiv  TRGCON2_TRGDIV2_MASK, 0x4000

        .equiv  TRGCON2_TRGDIV3, 0x000F
        .equiv  TRGCON2_TRGDIV3_WIDTH, 0x0001
        .equiv  TRGCON2_TRGDIV3_MASK, 0x8000

;----- LEBCON2 Bits -----------------------------------------------------
        .equiv  LEBCON2_BPLL, 0x0000
        .equiv  LEBCON2_BPLL_WIDTH, 0x0001
        .equiv  LEBCON2_BPLL_MASK, 0x0001

        .equiv  LEBCON2_BPLH, 0x0001
        .equiv  LEBCON2_BPLH_WIDTH, 0x0001
        .equiv  LEBCON2_BPLH_MASK, 0x0002

        .equiv  LEBCON2_BPHL, 0x0002
        .equiv  LEBCON2_BPHL_WIDTH, 0x0001
        .equiv  LEBCON2_BPHL_MASK, 0x0004

        .equiv  LEBCON2_BPHH, 0x0003
        .equiv  LEBCON2_BPHH_WIDTH, 0x0001
        .equiv  LEBCON2_BPHH_MASK, 0x0008

        .equiv  LEBCON2_BCL_LEBCON2, 0x0004
        .equiv  LEBCON2_BCL_LEBCON2_WIDTH, 0x0001
        .equiv  LEBCON2_BCL_LEBCON2_MASK, 0x0010
        .equiv  BCL_LEBCON2, 0x0004

        .equiv  LEBCON2_BCH, 0x0005
        .equiv  LEBCON2_BCH_WIDTH, 0x0001
        .equiv  LEBCON2_BCH_MASK, 0x0020

        .equiv  LEBCON2_CLLEBEN, 0x000A
        .equiv  LEBCON2_CLLEBEN_WIDTH, 0x0001
        .equiv  LEBCON2_CLLEBEN_MASK, 0x0400

        .equiv  LEBCON2_FLTLEBEN, 0x000B
        .equiv  LEBCON2_FLTLEBEN_WIDTH, 0x0001
        .equiv  LEBCON2_FLTLEBEN_MASK, 0x0800

        .equiv  LEBCON2_PLF, 0x000C
        .equiv  LEBCON2_PLF_WIDTH, 0x0001
        .equiv  LEBCON2_PLF_MASK, 0x1000

        .equiv  LEBCON2_PLR, 0x000D
        .equiv  LEBCON2_PLR_WIDTH, 0x0001
        .equiv  LEBCON2_PLR_MASK, 0x2000

        .equiv  LEBCON2_PHF, 0x000E
        .equiv  LEBCON2_PHF_WIDTH, 0x0001
        .equiv  LEBCON2_PHF_MASK, 0x4000

        .equiv  LEBCON2_PHR, 0x000F
        .equiv  LEBCON2_PHR_WIDTH, 0x0001
        .equiv  LEBCON2_PHR_MASK, 0x8000

;----- LEBDLY2 Bits -----------------------------------------------------
        .equiv  LEBDLY2_LEB, 0x0003
        .equiv  LEBDLY2_LEB_WIDTH, 0x0009
        .equiv  LEBDLY2_LEB_MASK, 0x0FF8

        .equiv  LEBDLY2_LEB0, 0x0003
        .equiv  LEBDLY2_LEB0_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB0_MASK, 0x0008

        .equiv  LEBDLY2_LEB1, 0x0004
        .equiv  LEBDLY2_LEB1_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB1_MASK, 0x0010

        .equiv  LEBDLY2_LEB2, 0x0005
        .equiv  LEBDLY2_LEB2_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB2_MASK, 0x0020

        .equiv  LEBDLY2_LEB3, 0x0006
        .equiv  LEBDLY2_LEB3_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB3_MASK, 0x0040

        .equiv  LEBDLY2_LEB4, 0x0007
        .equiv  LEBDLY2_LEB4_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB4_MASK, 0x0080

        .equiv  LEBDLY2_LEB5, 0x0008
        .equiv  LEBDLY2_LEB5_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB5_MASK, 0x0100

        .equiv  LEBDLY2_LEB6, 0x0009
        .equiv  LEBDLY2_LEB6_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB6_MASK, 0x0200

        .equiv  LEBDLY2_LEB7, 0x000A
        .equiv  LEBDLY2_LEB7_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB7_MASK, 0x0400

        .equiv  LEBDLY2_LEB8, 0x000B
        .equiv  LEBDLY2_LEB8_WIDTH, 0x0001
        .equiv  LEBDLY2_LEB8_MASK, 0x0800

;----- AUXCON2 Bits -----------------------------------------------------
        .equiv  AUXCON2_CHOPLEN, 0x0000
        .equiv  AUXCON2_CHOPLEN_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPLEN_MASK, 0x0001

        .equiv  AUXCON2_CHOPHEN, 0x0001
        .equiv  AUXCON2_CHOPHEN_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPHEN_MASK, 0x0002

        .equiv  AUXCON2_CHOPSEL, 0x0002
        .equiv  AUXCON2_CHOPSEL_WIDTH, 0x0004
        .equiv  AUXCON2_CHOPSEL_MASK, 0x003C

        .equiv  AUXCON2_BLANKSEL, 0x0008
        .equiv  AUXCON2_BLANKSEL_WIDTH, 0x0004
        .equiv  AUXCON2_BLANKSEL_MASK, 0x0F00

        .equiv  AUXCON2_CHOPSEL0, 0x0002
        .equiv  AUXCON2_CHOPSEL0_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPSEL0_MASK, 0x0004

        .equiv  AUXCON2_CHOPSEL1, 0x0003
        .equiv  AUXCON2_CHOPSEL1_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPSEL1_MASK, 0x0008

        .equiv  AUXCON2_CHOPSEL2, 0x0004
        .equiv  AUXCON2_CHOPSEL2_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPSEL2_MASK, 0x0010

        .equiv  AUXCON2_CHOPSEL3, 0x0005
        .equiv  AUXCON2_CHOPSEL3_WIDTH, 0x0001
        .equiv  AUXCON2_CHOPSEL3_MASK, 0x0020

        .equiv  AUXCON2_BLANKSEL0, 0x0008
        .equiv  AUXCON2_BLANKSEL0_WIDTH, 0x0001
        .equiv  AUXCON2_BLANKSEL0_MASK, 0x0100

        .equiv  AUXCON2_BLANKSEL1, 0x0009
        .equiv  AUXCON2_BLANKSEL1_WIDTH, 0x0001
        .equiv  AUXCON2_BLANKSEL1_MASK, 0x0200

        .equiv  AUXCON2_BLANKSEL2, 0x000A
        .equiv  AUXCON2_BLANKSEL2_WIDTH, 0x0001
        .equiv  AUXCON2_BLANKSEL2_MASK, 0x0400

        .equiv  AUXCON2_BLANKSEL3, 0x000B
        .equiv  AUXCON2_BLANKSEL3_WIDTH, 0x0001
        .equiv  AUXCON2_BLANKSEL3_MASK, 0x0800

;----- PWMCON3 Bits -----------------------------------------------------
        .equiv  PWMCON3_IUE, 0x0000
        .equiv  PWMCON3_IUE_WIDTH, 0x0001
        .equiv  PWMCON3_IUE_MASK, 0x0001

        .equiv  PWMCON3_XPRES, 0x0001
        .equiv  PWMCON3_XPRES_WIDTH, 0x0001
        .equiv  PWMCON3_XPRES_MASK, 0x0002

        .equiv  PWMCON3_CAM, 0x0002
        .equiv  PWMCON3_CAM_WIDTH, 0x0001
        .equiv  PWMCON3_CAM_MASK, 0x0004

        .equiv  PWMCON3_MTBS, 0x0003
        .equiv  PWMCON3_MTBS_WIDTH, 0x0001
        .equiv  PWMCON3_MTBS_MASK, 0x0008

        .equiv  PWMCON3_DTCP, 0x0005
        .equiv  PWMCON3_DTCP_WIDTH, 0x0001
        .equiv  PWMCON3_DTCP_MASK, 0x0020

        .equiv  PWMCON3_DTC, 0x0006
        .equiv  PWMCON3_DTC_WIDTH, 0x0002
        .equiv  PWMCON3_DTC_MASK, 0x00C0

        .equiv  PWMCON3_MDCS, 0x0008
        .equiv  PWMCON3_MDCS_WIDTH, 0x0001
        .equiv  PWMCON3_MDCS_MASK, 0x0100

        .equiv  PWMCON3_ITB, 0x0009
        .equiv  PWMCON3_ITB_WIDTH, 0x0001
        .equiv  PWMCON3_ITB_MASK, 0x0200

        .equiv  PWMCON3_TRGIEN, 0x000A
        .equiv  PWMCON3_TRGIEN_WIDTH, 0x0001
        .equiv  PWMCON3_TRGIEN_MASK, 0x0400

        .equiv  PWMCON3_CLIEN, 0x000B
        .equiv  PWMCON3_CLIEN_WIDTH, 0x0001
        .equiv  PWMCON3_CLIEN_MASK, 0x0800

        .equiv  PWMCON3_FLTIEN, 0x000C
        .equiv  PWMCON3_FLTIEN_WIDTH, 0x0001
        .equiv  PWMCON3_FLTIEN_MASK, 0x1000

        .equiv  PWMCON3_TRGSTAT, 0x000D
        .equiv  PWMCON3_TRGSTAT_WIDTH, 0x0001
        .equiv  PWMCON3_TRGSTAT_MASK, 0x2000

        .equiv  PWMCON3_CLSTAT, 0x000E
        .equiv  PWMCON3_CLSTAT_WIDTH, 0x0001
        .equiv  PWMCON3_CLSTAT_MASK, 0x4000

        .equiv  PWMCON3_FLTSTAT, 0x000F
        .equiv  PWMCON3_FLTSTAT_WIDTH, 0x0001
        .equiv  PWMCON3_FLTSTAT_MASK, 0x8000

        .equiv  PWMCON3_DTC0, 0x0006
        .equiv  PWMCON3_DTC0_WIDTH, 0x0001
        .equiv  PWMCON3_DTC0_MASK, 0x0040

        .equiv  PWMCON3_DTC1, 0x0007
        .equiv  PWMCON3_DTC1_WIDTH, 0x0001
        .equiv  PWMCON3_DTC1_MASK, 0x0080

;----- IOCON3 Bits -----------------------------------------------------
        .equiv  IOCON3_OSYNC, 0x0000
        .equiv  IOCON3_OSYNC_WIDTH, 0x0001
        .equiv  IOCON3_OSYNC_MASK, 0x0001

        .equiv  IOCON3_SWAP, 0x0001
        .equiv  IOCON3_SWAP_WIDTH, 0x0001
        .equiv  IOCON3_SWAP_MASK, 0x0002

        .equiv  IOCON3_CLDAT, 0x0002
        .equiv  IOCON3_CLDAT_WIDTH, 0x0002
        .equiv  IOCON3_CLDAT_MASK, 0x000C

        .equiv  IOCON3_FLTDAT, 0x0004
        .equiv  IOCON3_FLTDAT_WIDTH, 0x0002
        .equiv  IOCON3_FLTDAT_MASK, 0x0030

        .equiv  IOCON3_OVRDAT, 0x0006
        .equiv  IOCON3_OVRDAT_WIDTH, 0x0002
        .equiv  IOCON3_OVRDAT_MASK, 0x00C0

        .equiv  IOCON3_OVRENL, 0x0008
        .equiv  IOCON3_OVRENL_WIDTH, 0x0001
        .equiv  IOCON3_OVRENL_MASK, 0x0100

        .equiv  IOCON3_OVRENH, 0x0009
        .equiv  IOCON3_OVRENH_WIDTH, 0x0001
        .equiv  IOCON3_OVRENH_MASK, 0x0200

        .equiv  IOCON3_PMOD, 0x000A
        .equiv  IOCON3_PMOD_WIDTH, 0x0002
        .equiv  IOCON3_PMOD_MASK, 0x0C00

        .equiv  IOCON3_POLL, 0x000C
        .equiv  IOCON3_POLL_WIDTH, 0x0001
        .equiv  IOCON3_POLL_MASK, 0x1000

        .equiv  IOCON3_POLH, 0x000D
        .equiv  IOCON3_POLH_WIDTH, 0x0001
        .equiv  IOCON3_POLH_MASK, 0x2000

        .equiv  IOCON3_PENL, 0x000E
        .equiv  IOCON3_PENL_WIDTH, 0x0001
        .equiv  IOCON3_PENL_MASK, 0x4000

        .equiv  IOCON3_PENH, 0x000F
        .equiv  IOCON3_PENH_WIDTH, 0x0001
        .equiv  IOCON3_PENH_MASK, 0x8000

        .equiv  IOCON3_CLDAT0, 0x0002
        .equiv  IOCON3_CLDAT0_WIDTH, 0x0001
        .equiv  IOCON3_CLDAT0_MASK, 0x0004

        .equiv  IOCON3_CLDAT1, 0x0003
        .equiv  IOCON3_CLDAT1_WIDTH, 0x0001
        .equiv  IOCON3_CLDAT1_MASK, 0x0008

        .equiv  IOCON3_FLTDAT0, 0x0004
        .equiv  IOCON3_FLTDAT0_WIDTH, 0x0001
        .equiv  IOCON3_FLTDAT0_MASK, 0x0010

        .equiv  IOCON3_FLTDAT1, 0x0005
        .equiv  IOCON3_FLTDAT1_WIDTH, 0x0001
        .equiv  IOCON3_FLTDAT1_MASK, 0x0020

        .equiv  IOCON3_OVRDAT0, 0x0006
        .equiv  IOCON3_OVRDAT0_WIDTH, 0x0001
        .equiv  IOCON3_OVRDAT0_MASK, 0x0040

        .equiv  IOCON3_OVRDAT1, 0x0007
        .equiv  IOCON3_OVRDAT1_WIDTH, 0x0001
        .equiv  IOCON3_OVRDAT1_MASK, 0x0080

        .equiv  IOCON3_PMOD0, 0x000A
        .equiv  IOCON3_PMOD0_WIDTH, 0x0001
        .equiv  IOCON3_PMOD0_MASK, 0x0400

        .equiv  IOCON3_PMOD1, 0x000B
        .equiv  IOCON3_PMOD1_WIDTH, 0x0001
        .equiv  IOCON3_PMOD1_MASK, 0x0800

;----- FCLCON3 Bits -----------------------------------------------------
        .equiv  FCLCON3_FLTMOD, 0x0000
        .equiv  FCLCON3_FLTMOD_WIDTH, 0x0002
        .equiv  FCLCON3_FLTMOD_MASK, 0x0003

        .equiv  FCLCON3_FLTPOL, 0x0002
        .equiv  FCLCON3_FLTPOL_WIDTH, 0x0001
        .equiv  FCLCON3_FLTPOL_MASK, 0x0004

        .equiv  FCLCON3_FLTSRC, 0x0003
        .equiv  FCLCON3_FLTSRC_WIDTH, 0x0005
        .equiv  FCLCON3_FLTSRC_MASK, 0x00F8

        .equiv  FCLCON3_CLMOD, 0x0008
        .equiv  FCLCON3_CLMOD_WIDTH, 0x0001
        .equiv  FCLCON3_CLMOD_MASK, 0x0100

        .equiv  FCLCON3_CLPOL, 0x0009
        .equiv  FCLCON3_CLPOL_WIDTH, 0x0001
        .equiv  FCLCON3_CLPOL_MASK, 0x0200

        .equiv  FCLCON3_CLSRC, 0x000A
        .equiv  FCLCON3_CLSRC_WIDTH, 0x0005
        .equiv  FCLCON3_CLSRC_MASK, 0x7C00

        .equiv  FCLCON3_FLTMOD0, 0x0000
        .equiv  FCLCON3_FLTMOD0_WIDTH, 0x0001
        .equiv  FCLCON3_FLTMOD0_MASK, 0x0001

        .equiv  FCLCON3_FLTMOD1, 0x0001
        .equiv  FCLCON3_FLTMOD1_WIDTH, 0x0001
        .equiv  FCLCON3_FLTMOD1_MASK, 0x0002

        .equiv  FCLCON3_FLTSRC0, 0x0003
        .equiv  FCLCON3_FLTSRC0_WIDTH, 0x0001
        .equiv  FCLCON3_FLTSRC0_MASK, 0x0008

        .equiv  FCLCON3_FLTSRC1, 0x0004
        .equiv  FCLCON3_FLTSRC1_WIDTH, 0x0001
        .equiv  FCLCON3_FLTSRC1_MASK, 0x0010

        .equiv  FCLCON3_FLTSRC2, 0x0005
        .equiv  FCLCON3_FLTSRC2_WIDTH, 0x0001
        .equiv  FCLCON3_FLTSRC2_MASK, 0x0020

        .equiv  FCLCON3_FLTSRC3, 0x0006
        .equiv  FCLCON3_FLTSRC3_WIDTH, 0x0001
        .equiv  FCLCON3_FLTSRC3_MASK, 0x0040

        .equiv  FCLCON3_FLTSRC4, 0x0007
        .equiv  FCLCON3_FLTSRC4_WIDTH, 0x0001
        .equiv  FCLCON3_FLTSRC4_MASK, 0x0080

        .equiv  FCLCON3_CLSRC0, 0x000A
        .equiv  FCLCON3_CLSRC0_WIDTH, 0x0001
        .equiv  FCLCON3_CLSRC0_MASK, 0x0400

        .equiv  FCLCON3_CLSRC1, 0x000B
        .equiv  FCLCON3_CLSRC1_WIDTH, 0x0001
        .equiv  FCLCON3_CLSRC1_MASK, 0x0800

        .equiv  FCLCON3_CLSRC2, 0x000C
        .equiv  FCLCON3_CLSRC2_WIDTH, 0x0001
        .equiv  FCLCON3_CLSRC2_MASK, 0x1000

        .equiv  FCLCON3_CLSRC3, 0x000D
        .equiv  FCLCON3_CLSRC3_WIDTH, 0x0001
        .equiv  FCLCON3_CLSRC3_MASK, 0x2000

        .equiv  FCLCON3_CLSRC4, 0x000E
        .equiv  FCLCON3_CLSRC4_WIDTH, 0x0001
        .equiv  FCLCON3_CLSRC4_MASK, 0x4000

;----- TRIG3 Bits -----------------------------------------------------
        .equiv  TRIG3_TRGCMP, 0x0003
        .equiv  TRIG3_TRGCMP_WIDTH, 0x000D
        .equiv  TRIG3_TRGCMP_MASK, 0xFFF8

        .equiv  TRIG3_TRGCMP0, 0x0003
        .equiv  TRIG3_TRGCMP0_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP0_MASK, 0x0008

        .equiv  TRIG3_TRGCMP1, 0x0004
        .equiv  TRIG3_TRGCMP1_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP1_MASK, 0x0010

        .equiv  TRIG3_TRGCMP2, 0x0005
        .equiv  TRIG3_TRGCMP2_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP2_MASK, 0x0020

        .equiv  TRIG3_TRGCMP3, 0x0006
        .equiv  TRIG3_TRGCMP3_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP3_MASK, 0x0040

        .equiv  TRIG3_TRGCMP4, 0x0007
        .equiv  TRIG3_TRGCMP4_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP4_MASK, 0x0080

        .equiv  TRIG3_TRGCMP5, 0x0008
        .equiv  TRIG3_TRGCMP5_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP5_MASK, 0x0100

        .equiv  TRIG3_TRGCMP6, 0x0009
        .equiv  TRIG3_TRGCMP6_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP6_MASK, 0x0200

        .equiv  TRIG3_TRGCMP7, 0x000A
        .equiv  TRIG3_TRGCMP7_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP7_MASK, 0x0400

        .equiv  TRIG3_TRGCMP8, 0x000B
        .equiv  TRIG3_TRGCMP8_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP8_MASK, 0x0800

        .equiv  TRIG3_TRGCMP9, 0x000C
        .equiv  TRIG3_TRGCMP9_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP9_MASK, 0x1000

        .equiv  TRIG3_TRGCMP10, 0x000D
        .equiv  TRIG3_TRGCMP10_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP10_MASK, 0x2000

        .equiv  TRIG3_TRGCMP11, 0x000E
        .equiv  TRIG3_TRGCMP11_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP11_MASK, 0x4000

        .equiv  TRIG3_TRGCMP12, 0x000F
        .equiv  TRIG3_TRGCMP12_WIDTH, 0x0001
        .equiv  TRIG3_TRGCMP12_MASK, 0x8000

;----- TRGCON3 Bits -----------------------------------------------------
        .equiv  TRGCON3_TRGSTRT, 0x0000
        .equiv  TRGCON3_TRGSTRT_WIDTH, 0x0006
        .equiv  TRGCON3_TRGSTRT_MASK, 0x003F

        .equiv  TRGCON3_TRGDIV, 0x000C
        .equiv  TRGCON3_TRGDIV_WIDTH, 0x0004
        .equiv  TRGCON3_TRGDIV_MASK, 0xF000

        .equiv  TRGCON3_TRGSTRT0, 0x0000
        .equiv  TRGCON3_TRGSTRT0_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT0_MASK, 0x0001

        .equiv  TRGCON3_TRGSTRT1, 0x0001
        .equiv  TRGCON3_TRGSTRT1_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT1_MASK, 0x0002

        .equiv  TRGCON3_TRGSTRT2, 0x0002
        .equiv  TRGCON3_TRGSTRT2_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT2_MASK, 0x0004

        .equiv  TRGCON3_TRGSTRT3, 0x0003
        .equiv  TRGCON3_TRGSTRT3_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT3_MASK, 0x0008

        .equiv  TRGCON3_TRGSTRT4, 0x0004
        .equiv  TRGCON3_TRGSTRT4_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT4_MASK, 0x0010

        .equiv  TRGCON3_TRGSTRT5, 0x0005
        .equiv  TRGCON3_TRGSTRT5_WIDTH, 0x0001
        .equiv  TRGCON3_TRGSTRT5_MASK, 0x0020

        .equiv  TRGCON3_TRGDIV0, 0x000C
        .equiv  TRGCON3_TRGDIV0_WIDTH, 0x0001
        .equiv  TRGCON3_TRGDIV0_MASK, 0x1000

        .equiv  TRGCON3_TRGDIV1, 0x000D
        .equiv  TRGCON3_TRGDIV1_WIDTH, 0x0001
        .equiv  TRGCON3_TRGDIV1_MASK, 0x2000

        .equiv  TRGCON3_TRGDIV2, 0x000E
        .equiv  TRGCON3_TRGDIV2_WIDTH, 0x0001
        .equiv  TRGCON3_TRGDIV2_MASK, 0x4000

        .equiv  TRGCON3_TRGDIV3, 0x000F
        .equiv  TRGCON3_TRGDIV3_WIDTH, 0x0001
        .equiv  TRGCON3_TRGDIV3_MASK, 0x8000

;----- LEBCON3 Bits -----------------------------------------------------
        .equiv  LEBCON3_BPLL, 0x0000
        .equiv  LEBCON3_BPLL_WIDTH, 0x0001
        .equiv  LEBCON3_BPLL_MASK, 0x0001

        .equiv  LEBCON3_BPLH, 0x0001
        .equiv  LEBCON3_BPLH_WIDTH, 0x0001
        .equiv  LEBCON3_BPLH_MASK, 0x0002

        .equiv  LEBCON3_BPHL, 0x0002
        .equiv  LEBCON3_BPHL_WIDTH, 0x0001
        .equiv  LEBCON3_BPHL_MASK, 0x0004

        .equiv  LEBCON3_BPHH, 0x0003
        .equiv  LEBCON3_BPHH_WIDTH, 0x0001
        .equiv  LEBCON3_BPHH_MASK, 0x0008

        .equiv  LEBCON3_BCL_LEBCON3, 0x0004
        .equiv  LEBCON3_BCL_LEBCON3_WIDTH, 0x0001
        .equiv  LEBCON3_BCL_LEBCON3_MASK, 0x0010
        .equiv  BCL_LEBCON3, 0x0004

        .equiv  LEBCON3_BCH, 0x0005
        .equiv  LEBCON3_BCH_WIDTH, 0x0001
        .equiv  LEBCON3_BCH_MASK, 0x0020

        .equiv  LEBCON3_CLLEBEN, 0x000A
        .equiv  LEBCON3_CLLEBEN_WIDTH, 0x0001
        .equiv  LEBCON3_CLLEBEN_MASK, 0x0400

        .equiv  LEBCON3_FLTLEBEN, 0x000B
        .equiv  LEBCON3_FLTLEBEN_WIDTH, 0x0001
        .equiv  LEBCON3_FLTLEBEN_MASK, 0x0800

        .equiv  LEBCON3_PLF, 0x000C
        .equiv  LEBCON3_PLF_WIDTH, 0x0001
        .equiv  LEBCON3_PLF_MASK, 0x1000

        .equiv  LEBCON3_PLR, 0x000D
        .equiv  LEBCON3_PLR_WIDTH, 0x0001
        .equiv  LEBCON3_PLR_MASK, 0x2000

        .equiv  LEBCON3_PHF, 0x000E
        .equiv  LEBCON3_PHF_WIDTH, 0x0001
        .equiv  LEBCON3_PHF_MASK, 0x4000

        .equiv  LEBCON3_PHR, 0x000F
        .equiv  LEBCON3_PHR_WIDTH, 0x0001
        .equiv  LEBCON3_PHR_MASK, 0x8000

;----- LEBDLY3 Bits -----------------------------------------------------
        .equiv  LEBDLY3_LEB, 0x0003
        .equiv  LEBDLY3_LEB_WIDTH, 0x0009
        .equiv  LEBDLY3_LEB_MASK, 0x0FF8

        .equiv  LEBDLY3_LEB0, 0x0003
        .equiv  LEBDLY3_LEB0_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB0_MASK, 0x0008

        .equiv  LEBDLY3_LEB1, 0x0004
        .equiv  LEBDLY3_LEB1_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB1_MASK, 0x0010

        .equiv  LEBDLY3_LEB2, 0x0005
        .equiv  LEBDLY3_LEB2_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB2_MASK, 0x0020

        .equiv  LEBDLY3_LEB3, 0x0006
        .equiv  LEBDLY3_LEB3_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB3_MASK, 0x0040

        .equiv  LEBDLY3_LEB4, 0x0007
        .equiv  LEBDLY3_LEB4_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB4_MASK, 0x0080

        .equiv  LEBDLY3_LEB5, 0x0008
        .equiv  LEBDLY3_LEB5_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB5_MASK, 0x0100

        .equiv  LEBDLY3_LEB6, 0x0009
        .equiv  LEBDLY3_LEB6_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB6_MASK, 0x0200

        .equiv  LEBDLY3_LEB7, 0x000A
        .equiv  LEBDLY3_LEB7_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB7_MASK, 0x0400

        .equiv  LEBDLY3_LEB8, 0x000B
        .equiv  LEBDLY3_LEB8_WIDTH, 0x0001
        .equiv  LEBDLY3_LEB8_MASK, 0x0800

;----- AUXCON3 Bits -----------------------------------------------------
        .equiv  AUXCON3_CHOPLEN, 0x0000
        .equiv  AUXCON3_CHOPLEN_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPLEN_MASK, 0x0001

        .equiv  AUXCON3_CHOPHEN, 0x0001
        .equiv  AUXCON3_CHOPHEN_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPHEN_MASK, 0x0002

        .equiv  AUXCON3_CHOPSEL, 0x0002
        .equiv  AUXCON3_CHOPSEL_WIDTH, 0x0004
        .equiv  AUXCON3_CHOPSEL_MASK, 0x003C

        .equiv  AUXCON3_BLANKSEL, 0x0008
        .equiv  AUXCON3_BLANKSEL_WIDTH, 0x0004
        .equiv  AUXCON3_BLANKSEL_MASK, 0x0F00

        .equiv  AUXCON3_CHOPSEL0, 0x0002
        .equiv  AUXCON3_CHOPSEL0_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPSEL0_MASK, 0x0004

        .equiv  AUXCON3_CHOPSEL1, 0x0003
        .equiv  AUXCON3_CHOPSEL1_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPSEL1_MASK, 0x0008

        .equiv  AUXCON3_CHOPSEL2, 0x0004
        .equiv  AUXCON3_CHOPSEL2_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPSEL2_MASK, 0x0010

        .equiv  AUXCON3_CHOPSEL3, 0x0005
        .equiv  AUXCON3_CHOPSEL3_WIDTH, 0x0001
        .equiv  AUXCON3_CHOPSEL3_MASK, 0x0020

        .equiv  AUXCON3_BLANKSEL0, 0x0008
        .equiv  AUXCON3_BLANKSEL0_WIDTH, 0x0001
        .equiv  AUXCON3_BLANKSEL0_MASK, 0x0100

        .equiv  AUXCON3_BLANKSEL1, 0x0009
        .equiv  AUXCON3_BLANKSEL1_WIDTH, 0x0001
        .equiv  AUXCON3_BLANKSEL1_MASK, 0x0200

        .equiv  AUXCON3_BLANKSEL2, 0x000A
        .equiv  AUXCON3_BLANKSEL2_WIDTH, 0x0001
        .equiv  AUXCON3_BLANKSEL2_MASK, 0x0400

        .equiv  AUXCON3_BLANKSEL3, 0x000B
        .equiv  AUXCON3_BLANKSEL3_WIDTH, 0x0001
        .equiv  AUXCON3_BLANKSEL3_MASK, 0x0800

;----- TRISA Bits -----------------------------------------------------
        .equiv  TRISA_TRISA0, 0x0000
        .equiv  TRISA_TRISA0_WIDTH, 0x0001
        .equiv  TRISA_TRISA0_MASK, 0x0001
        .equiv  TRISA0, 0x0000

        .equiv  TRISA_TRISA1, 0x0001
        .equiv  TRISA_TRISA1_WIDTH, 0x0001
        .equiv  TRISA_TRISA1_MASK, 0x0002
        .equiv  TRISA1, 0x0001

        .equiv  TRISA_TRISA4, 0x0004
        .equiv  TRISA_TRISA4_WIDTH, 0x0001
        .equiv  TRISA_TRISA4_MASK, 0x0010
        .equiv  TRISA4, 0x0004

        .equiv  TRISA_TRISA7, 0x0007
        .equiv  TRISA_TRISA7_WIDTH, 0x0001
        .equiv  TRISA_TRISA7_MASK, 0x0080
        .equiv  TRISA7, 0x0007

        .equiv  TRISA_TRISA8, 0x0008
        .equiv  TRISA_TRISA8_WIDTH, 0x0001
        .equiv  TRISA_TRISA8_MASK, 0x0100
        .equiv  TRISA8, 0x0008

        .equiv  TRISA_TRISA9, 0x0009
        .equiv  TRISA_TRISA9_WIDTH, 0x0001
        .equiv  TRISA_TRISA9_MASK, 0x0200
        .equiv  TRISA9, 0x0009

        .equiv  TRISA_TRISA10, 0x000A
        .equiv  TRISA_TRISA10_WIDTH, 0x0001
        .equiv  TRISA_TRISA10_MASK, 0x0400
        .equiv  TRISA10, 0x000A

        .equiv  TRISA_TRISA11, 0x000B
        .equiv  TRISA_TRISA11_WIDTH, 0x0001
        .equiv  TRISA_TRISA11_MASK, 0x0800
        .equiv  TRISA11, 0x000B

        .equiv  TRISA_TRISA12, 0x000C
        .equiv  TRISA_TRISA12_WIDTH, 0x0001
        .equiv  TRISA_TRISA12_MASK, 0x1000
        .equiv  TRISA12, 0x000C

;----- PORTA Bits -----------------------------------------------------
        .equiv  PORTA_RA0, 0x0000
        .equiv  PORTA_RA0_WIDTH, 0x0001
        .equiv  PORTA_RA0_MASK, 0x0001
        .equiv  RA0, 0x0000

        .equiv  PORTA_RA1, 0x0001
        .equiv  PORTA_RA1_WIDTH, 0x0001
        .equiv  PORTA_RA1_MASK, 0x0002
        .equiv  RA1, 0x0001

        .equiv  PORTA_RA4, 0x0004
        .equiv  PORTA_RA4_WIDTH, 0x0001
        .equiv  PORTA_RA4_MASK, 0x0010
        .equiv  RA4, 0x0004

        .equiv  PORTA_RA7, 0x0007
        .equiv  PORTA_RA7_WIDTH, 0x0001
        .equiv  PORTA_RA7_MASK, 0x0080
        .equiv  RA7, 0x0007

        .equiv  PORTA_RA8, 0x0008
        .equiv  PORTA_RA8_WIDTH, 0x0001
        .equiv  PORTA_RA8_MASK, 0x0100
        .equiv  RA8, 0x0008

        .equiv  PORTA_RA9, 0x0009
        .equiv  PORTA_RA9_WIDTH, 0x0001
        .equiv  PORTA_RA9_MASK, 0x0200
        .equiv  RA9, 0x0009

        .equiv  PORTA_RA10, 0x000A
        .equiv  PORTA_RA10_WIDTH, 0x0001
        .equiv  PORTA_RA10_MASK, 0x0400
        .equiv  RA10, 0x000A

        .equiv  PORTA_RA11, 0x000B
        .equiv  PORTA_RA11_WIDTH, 0x0001
        .equiv  PORTA_RA11_MASK, 0x0800
        .equiv  RA11, 0x000B

        .equiv  PORTA_RA12, 0x000C
        .equiv  PORTA_RA12_WIDTH, 0x0001
        .equiv  PORTA_RA12_MASK, 0x1000
        .equiv  RA12, 0x000C

;----- LATA Bits -----------------------------------------------------
        .equiv  LATA_LATA0, 0x0000
        .equiv  LATA_LATA0_WIDTH, 0x0001
        .equiv  LATA_LATA0_MASK, 0x0001
        .equiv  LATA0, 0x0000

        .equiv  LATA_LATA1, 0x0001
        .equiv  LATA_LATA1_WIDTH, 0x0001
        .equiv  LATA_LATA1_MASK, 0x0002
        .equiv  LATA1, 0x0001

        .equiv  LATA_LATA4, 0x0004
        .equiv  LATA_LATA4_WIDTH, 0x0001
        .equiv  LATA_LATA4_MASK, 0x0010
        .equiv  LATA4, 0x0004

        .equiv  LATA_LATA7, 0x0007
        .equiv  LATA_LATA7_WIDTH, 0x0001
        .equiv  LATA_LATA7_MASK, 0x0080
        .equiv  LATA7, 0x0007

        .equiv  LATA_LATA8, 0x0008
        .equiv  LATA_LATA8_WIDTH, 0x0001
        .equiv  LATA_LATA8_MASK, 0x0100
        .equiv  LATA8, 0x0008

        .equiv  LATA_LATA9, 0x0009
        .equiv  LATA_LATA9_WIDTH, 0x0001
        .equiv  LATA_LATA9_MASK, 0x0200
        .equiv  LATA9, 0x0009

        .equiv  LATA_LATA10, 0x000A
        .equiv  LATA_LATA10_WIDTH, 0x0001
        .equiv  LATA_LATA10_MASK, 0x0400
        .equiv  LATA10, 0x000A

        .equiv  LATA_LATA11, 0x000B
        .equiv  LATA_LATA11_WIDTH, 0x0001
        .equiv  LATA_LATA11_MASK, 0x0800
        .equiv  LATA11, 0x000B

        .equiv  LATA_LATA12, 0x000C
        .equiv  LATA_LATA12_WIDTH, 0x0001
        .equiv  LATA_LATA12_MASK, 0x1000
        .equiv  LATA12, 0x000C

;----- ODCA Bits -----------------------------------------------------
        .equiv  ODCA_ODCA0, 0x0000
        .equiv  ODCA_ODCA0_WIDTH, 0x0001
        .equiv  ODCA_ODCA0_MASK, 0x0001
        .equiv  ODCA0, 0x0000

        .equiv  ODCA_ODCA1, 0x0001
        .equiv  ODCA_ODCA1_WIDTH, 0x0001
        .equiv  ODCA_ODCA1_MASK, 0x0002
        .equiv  ODCA1, 0x0001

        .equiv  ODCA_ODCA4, 0x0004
        .equiv  ODCA_ODCA4_WIDTH, 0x0001
        .equiv  ODCA_ODCA4_MASK, 0x0010
        .equiv  ODCA4, 0x0004

        .equiv  ODCA_ODCA7, 0x0007
        .equiv  ODCA_ODCA7_WIDTH, 0x0001
        .equiv  ODCA_ODCA7_MASK, 0x0080
        .equiv  ODCA7, 0x0007

        .equiv  ODCA_ODCA8, 0x0008
        .equiv  ODCA_ODCA8_WIDTH, 0x0001
        .equiv  ODCA_ODCA8_MASK, 0x0100
        .equiv  ODCA8, 0x0008

        .equiv  ODCA_ODCA9, 0x0009
        .equiv  ODCA_ODCA9_WIDTH, 0x0001
        .equiv  ODCA_ODCA9_MASK, 0x0200
        .equiv  ODCA9, 0x0009

        .equiv  ODCA_ODCA10, 0x000A
        .equiv  ODCA_ODCA10_WIDTH, 0x0001
        .equiv  ODCA_ODCA10_MASK, 0x0400
        .equiv  ODCA10, 0x000A

        .equiv  ODCA_ODCA11, 0x000B
        .equiv  ODCA_ODCA11_WIDTH, 0x0001
        .equiv  ODCA_ODCA11_MASK, 0x0800
        .equiv  ODCA11, 0x000B

        .equiv  ODCA_ODCA12, 0x000C
        .equiv  ODCA_ODCA12_WIDTH, 0x0001
        .equiv  ODCA_ODCA12_MASK, 0x1000
        .equiv  ODCA12, 0x000C

;----- CNENA Bits -----------------------------------------------------
        .equiv  CNENA_CNIEA0, 0x0000
        .equiv  CNENA_CNIEA0_WIDTH, 0x0001
        .equiv  CNENA_CNIEA0_MASK, 0x0001
        .equiv  CNIEA0, 0x0000

        .equiv  CNENA_CNIEA1, 0x0001
        .equiv  CNENA_CNIEA1_WIDTH, 0x0001
        .equiv  CNENA_CNIEA1_MASK, 0x0002
        .equiv  CNIEA1, 0x0001

        .equiv  CNENA_CNIEA4, 0x0004
        .equiv  CNENA_CNIEA4_WIDTH, 0x0001
        .equiv  CNENA_CNIEA4_MASK, 0x0010
        .equiv  CNIEA4, 0x0004

        .equiv  CNENA_CNIEA7, 0x0007
        .equiv  CNENA_CNIEA7_WIDTH, 0x0001
        .equiv  CNENA_CNIEA7_MASK, 0x0080
        .equiv  CNIEA7, 0x0007

        .equiv  CNENA_CNIEA8, 0x0008
        .equiv  CNENA_CNIEA8_WIDTH, 0x0001
        .equiv  CNENA_CNIEA8_MASK, 0x0100
        .equiv  CNIEA8, 0x0008

        .equiv  CNENA_CNIEA9, 0x0009
        .equiv  CNENA_CNIEA9_WIDTH, 0x0001
        .equiv  CNENA_CNIEA9_MASK, 0x0200
        .equiv  CNIEA9, 0x0009

        .equiv  CNENA_CNIEA10, 0x000A
        .equiv  CNENA_CNIEA10_WIDTH, 0x0001
        .equiv  CNENA_CNIEA10_MASK, 0x0400
        .equiv  CNIEA10, 0x000A

        .equiv  CNENA_CNIEA11, 0x000B
        .equiv  CNENA_CNIEA11_WIDTH, 0x0001
        .equiv  CNENA_CNIEA11_MASK, 0x0800
        .equiv  CNIEA11, 0x000B

        .equiv  CNENA_CNIEA12, 0x000C
        .equiv  CNENA_CNIEA12_WIDTH, 0x0001
        .equiv  CNENA_CNIEA12_MASK, 0x1000
        .equiv  CNIEA12, 0x000C

;----- CNPUA Bits -----------------------------------------------------
        .equiv  CNPUA_CNPUA0, 0x0000
        .equiv  CNPUA_CNPUA0_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA0_MASK, 0x0001
        .equiv  CNPUA0, 0x0000

        .equiv  CNPUA_CNPUA1, 0x0001
        .equiv  CNPUA_CNPUA1_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA1_MASK, 0x0002
        .equiv  CNPUA1, 0x0001

        .equiv  CNPUA_CNPUA4, 0x0004
        .equiv  CNPUA_CNPUA4_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA4_MASK, 0x0010
        .equiv  CNPUA4, 0x0004

        .equiv  CNPUA_CNPUA7, 0x0007
        .equiv  CNPUA_CNPUA7_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA7_MASK, 0x0080
        .equiv  CNPUA7, 0x0007

        .equiv  CNPUA_CNPUA8, 0x0008
        .equiv  CNPUA_CNPUA8_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA8_MASK, 0x0100
        .equiv  CNPUA8, 0x0008

        .equiv  CNPUA_CNPUA9, 0x0009
        .equiv  CNPUA_CNPUA9_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA9_MASK, 0x0200
        .equiv  CNPUA9, 0x0009

        .equiv  CNPUA_CNPUA10, 0x000A
        .equiv  CNPUA_CNPUA10_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA10_MASK, 0x0400
        .equiv  CNPUA10, 0x000A

        .equiv  CNPUA_CNPUA11, 0x000B
        .equiv  CNPUA_CNPUA11_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA11_MASK, 0x0800
        .equiv  CNPUA11, 0x000B

        .equiv  CNPUA_CNPUA12, 0x000C
        .equiv  CNPUA_CNPUA12_WIDTH, 0x0001
        .equiv  CNPUA_CNPUA12_MASK, 0x1000
        .equiv  CNPUA12, 0x000C

;----- CNPDA Bits -----------------------------------------------------
        .equiv  CNPDA_CNPDA0, 0x0000
        .equiv  CNPDA_CNPDA0_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA0_MASK, 0x0001
        .equiv  CNPDA0, 0x0000

        .equiv  CNPDA_CNPDA1, 0x0001
        .equiv  CNPDA_CNPDA1_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA1_MASK, 0x0002
        .equiv  CNPDA1, 0x0001

        .equiv  CNPDA_CNPDA4, 0x0004
        .equiv  CNPDA_CNPDA4_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA4_MASK, 0x0010
        .equiv  CNPDA4, 0x0004

        .equiv  CNPDA_CNPDA7, 0x0007
        .equiv  CNPDA_CNPDA7_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA7_MASK, 0x0080
        .equiv  CNPDA7, 0x0007

        .equiv  CNPDA_CNPDA8, 0x0008
        .equiv  CNPDA_CNPDA8_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA8_MASK, 0x0100
        .equiv  CNPDA8, 0x0008

        .equiv  CNPDA_CNPDA9, 0x0009
        .equiv  CNPDA_CNPDA9_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA9_MASK, 0x0200
        .equiv  CNPDA9, 0x0009

        .equiv  CNPDA_CNPDA10, 0x000A
        .equiv  CNPDA_CNPDA10_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA10_MASK, 0x0400
        .equiv  CNPDA10, 0x000A

        .equiv  CNPDA_CNPDA11, 0x000B
        .equiv  CNPDA_CNPDA11_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA11_MASK, 0x0800
        .equiv  CNPDA11, 0x000B

        .equiv  CNPDA_CNPDA12, 0x000C
        .equiv  CNPDA_CNPDA12_WIDTH, 0x0001
        .equiv  CNPDA_CNPDA12_MASK, 0x1000
        .equiv  CNPDA12, 0x000C

;----- ANSELA Bits -----------------------------------------------------
        .equiv  ANSELA_ANSA0, 0x0000
        .equiv  ANSELA_ANSA0_WIDTH, 0x0001
        .equiv  ANSELA_ANSA0_MASK, 0x0001
        .equiv  ANSA0, 0x0000

        .equiv  ANSELA_ANSA1, 0x0001
        .equiv  ANSELA_ANSA1_WIDTH, 0x0001
        .equiv  ANSELA_ANSA1_MASK, 0x0002
        .equiv  ANSA1, 0x0001

        .equiv  ANSELA_ANSA4, 0x0004
        .equiv  ANSELA_ANSA4_WIDTH, 0x0001
        .equiv  ANSELA_ANSA4_MASK, 0x0010
        .equiv  ANSA4, 0x0004

        .equiv  ANSELA_ANSA11, 0x000B
        .equiv  ANSELA_ANSA11_WIDTH, 0x0001
        .equiv  ANSELA_ANSA11_MASK, 0x0800
        .equiv  ANSA11, 0x000B

        .equiv  ANSELA_ANSA12, 0x000C
        .equiv  ANSELA_ANSA12_WIDTH, 0x0001
        .equiv  ANSELA_ANSA12_MASK, 0x1000
        .equiv  ANSA12, 0x000C

;----- TRISB Bits -----------------------------------------------------
        .equiv  TRISB_TRISB0, 0x0000
        .equiv  TRISB_TRISB0_WIDTH, 0x0001
        .equiv  TRISB_TRISB0_MASK, 0x0001
        .equiv  TRISB0, 0x0000

        .equiv  TRISB_TRISB1, 0x0001
        .equiv  TRISB_TRISB1_WIDTH, 0x0001
        .equiv  TRISB_TRISB1_MASK, 0x0002
        .equiv  TRISB1, 0x0001

        .equiv  TRISB_TRISB2, 0x0002
        .equiv  TRISB_TRISB2_WIDTH, 0x0001
        .equiv  TRISB_TRISB2_MASK, 0x0004
        .equiv  TRISB2, 0x0002

        .equiv  TRISB_TRISB3, 0x0003
        .equiv  TRISB_TRISB3_WIDTH, 0x0001
        .equiv  TRISB_TRISB3_MASK, 0x0008
        .equiv  TRISB3, 0x0003

        .equiv  TRISB_TRISB4, 0x0004
        .equiv  TRISB_TRISB4_WIDTH, 0x0001
        .equiv  TRISB_TRISB4_MASK, 0x0010
        .equiv  TRISB4, 0x0004

        .equiv  TRISB_TRISB5, 0x0005
        .equiv  TRISB_TRISB5_WIDTH, 0x0001
        .equiv  TRISB_TRISB5_MASK, 0x0020
        .equiv  TRISB5, 0x0005

        .equiv  TRISB_TRISB6, 0x0006
        .equiv  TRISB_TRISB6_WIDTH, 0x0001
        .equiv  TRISB_TRISB6_MASK, 0x0040
        .equiv  TRISB6, 0x0006

        .equiv  TRISB_TRISB7, 0x0007
        .equiv  TRISB_TRISB7_WIDTH, 0x0001
        .equiv  TRISB_TRISB7_MASK, 0x0080
        .equiv  TRISB7, 0x0007

        .equiv  TRISB_TRISB8, 0x0008
        .equiv  TRISB_TRISB8_WIDTH, 0x0001
        .equiv  TRISB_TRISB8_MASK, 0x0100
        .equiv  TRISB8, 0x0008

        .equiv  TRISB_TRISB9, 0x0009
        .equiv  TRISB_TRISB9_WIDTH, 0x0001
        .equiv  TRISB_TRISB9_MASK, 0x0200
        .equiv  TRISB9, 0x0009

        .equiv  TRISB_TRISB10, 0x000A
        .equiv  TRISB_TRISB10_WIDTH, 0x0001
        .equiv  TRISB_TRISB10_MASK, 0x0400
        .equiv  TRISB10, 0x000A

        .equiv  TRISB_TRISB11, 0x000B
        .equiv  TRISB_TRISB11_WIDTH, 0x0001
        .equiv  TRISB_TRISB11_MASK, 0x0800
        .equiv  TRISB11, 0x000B

        .equiv  TRISB_TRISB12, 0x000C
        .equiv  TRISB_TRISB12_WIDTH, 0x0001
        .equiv  TRISB_TRISB12_MASK, 0x1000
        .equiv  TRISB12, 0x000C

        .equiv  TRISB_TRISB13, 0x000D
        .equiv  TRISB_TRISB13_WIDTH, 0x0001
        .equiv  TRISB_TRISB13_MASK, 0x2000
        .equiv  TRISB13, 0x000D

        .equiv  TRISB_TRISB14, 0x000E
        .equiv  TRISB_TRISB14_WIDTH, 0x0001
        .equiv  TRISB_TRISB14_MASK, 0x4000
        .equiv  TRISB14, 0x000E

        .equiv  TRISB_TRISB15, 0x000F
        .equiv  TRISB_TRISB15_WIDTH, 0x0001
        .equiv  TRISB_TRISB15_MASK, 0x8000
        .equiv  TRISB15, 0x000F

;----- PORTB Bits -----------------------------------------------------
        .equiv  PORTB_RB0, 0x0000
        .equiv  PORTB_RB0_WIDTH, 0x0001
        .equiv  PORTB_RB0_MASK, 0x0001
        .equiv  RB0, 0x0000

        .equiv  PORTB_RB1, 0x0001
        .equiv  PORTB_RB1_WIDTH, 0x0001
        .equiv  PORTB_RB1_MASK, 0x0002
        .equiv  RB1, 0x0001

        .equiv  PORTB_RB2, 0x0002
        .equiv  PORTB_RB2_WIDTH, 0x0001
        .equiv  PORTB_RB2_MASK, 0x0004
        .equiv  RB2, 0x0002

        .equiv  PORTB_RB3, 0x0003
        .equiv  PORTB_RB3_WIDTH, 0x0001
        .equiv  PORTB_RB3_MASK, 0x0008
        .equiv  RB3, 0x0003

        .equiv  PORTB_RB4, 0x0004
        .equiv  PORTB_RB4_WIDTH, 0x0001
        .equiv  PORTB_RB4_MASK, 0x0010
        .equiv  RB4, 0x0004

        .equiv  PORTB_RB5, 0x0005
        .equiv  PORTB_RB5_WIDTH, 0x0001
        .equiv  PORTB_RB5_MASK, 0x0020
        .equiv  RB5, 0x0005

        .equiv  PORTB_RB6, 0x0006
        .equiv  PORTB_RB6_WIDTH, 0x0001
        .equiv  PORTB_RB6_MASK, 0x0040
        .equiv  RB6, 0x0006

        .equiv  PORTB_RB7, 0x0007
        .equiv  PORTB_RB7_WIDTH, 0x0001
        .equiv  PORTB_RB7_MASK, 0x0080
        .equiv  RB7, 0x0007

        .equiv  PORTB_RB8, 0x0008
        .equiv  PORTB_RB8_WIDTH, 0x0001
        .equiv  PORTB_RB8_MASK, 0x0100
        .equiv  RB8, 0x0008

        .equiv  PORTB_RB9, 0x0009
        .equiv  PORTB_RB9_WIDTH, 0x0001
        .equiv  PORTB_RB9_MASK, 0x0200
        .equiv  RB9, 0x0009

        .equiv  PORTB_RB10, 0x000A
        .equiv  PORTB_RB10_WIDTH, 0x0001
        .equiv  PORTB_RB10_MASK, 0x0400
        .equiv  RB10, 0x000A

        .equiv  PORTB_RB11, 0x000B
        .equiv  PORTB_RB11_WIDTH, 0x0001
        .equiv  PORTB_RB11_MASK, 0x0800
        .equiv  RB11, 0x000B

        .equiv  PORTB_RB12, 0x000C
        .equiv  PORTB_RB12_WIDTH, 0x0001
        .equiv  PORTB_RB12_MASK, 0x1000
        .equiv  RB12, 0x000C

        .equiv  PORTB_RB13, 0x000D
        .equiv  PORTB_RB13_WIDTH, 0x0001
        .equiv  PORTB_RB13_MASK, 0x2000
        .equiv  RB13, 0x000D

        .equiv  PORTB_RB14, 0x000E
        .equiv  PORTB_RB14_WIDTH, 0x0001
        .equiv  PORTB_RB14_MASK, 0x4000
        .equiv  RB14, 0x000E

        .equiv  PORTB_RB15, 0x000F
        .equiv  PORTB_RB15_WIDTH, 0x0001
        .equiv  PORTB_RB15_MASK, 0x8000
        .equiv  RB15, 0x000F

;----- LATB Bits -----------------------------------------------------
        .equiv  LATB_LATB0, 0x0000
        .equiv  LATB_LATB0_WIDTH, 0x0001
        .equiv  LATB_LATB0_MASK, 0x0001
        .equiv  LATB0, 0x0000

        .equiv  LATB_LATB1, 0x0001
        .equiv  LATB_LATB1_WIDTH, 0x0001
        .equiv  LATB_LATB1_MASK, 0x0002
        .equiv  LATB1, 0x0001

        .equiv  LATB_LATB2, 0x0002
        .equiv  LATB_LATB2_WIDTH, 0x0001
        .equiv  LATB_LATB2_MASK, 0x0004
        .equiv  LATB2, 0x0002

        .equiv  LATB_LATB3, 0x0003
        .equiv  LATB_LATB3_WIDTH, 0x0001
        .equiv  LATB_LATB3_MASK, 0x0008
        .equiv  LATB3, 0x0003

        .equiv  LATB_LATB4, 0x0004
        .equiv  LATB_LATB4_WIDTH, 0x0001
        .equiv  LATB_LATB4_MASK, 0x0010
        .equiv  LATB4, 0x0004

        .equiv  LATB_LATB5, 0x0005
        .equiv  LATB_LATB5_WIDTH, 0x0001
        .equiv  LATB_LATB5_MASK, 0x0020
        .equiv  LATB5, 0x0005

        .equiv  LATB_LATB6, 0x0006
        .equiv  LATB_LATB6_WIDTH, 0x0001
        .equiv  LATB_LATB6_MASK, 0x0040
        .equiv  LATB6, 0x0006

        .equiv  LATB_LATB7, 0x0007
        .equiv  LATB_LATB7_WIDTH, 0x0001
        .equiv  LATB_LATB7_MASK, 0x0080
        .equiv  LATB7, 0x0007

        .equiv  LATB_LATB8, 0x0008
        .equiv  LATB_LATB8_WIDTH, 0x0001
        .equiv  LATB_LATB8_MASK, 0x0100
        .equiv  LATB8, 0x0008

        .equiv  LATB_LATB9, 0x0009
        .equiv  LATB_LATB9_WIDTH, 0x0001
        .equiv  LATB_LATB9_MASK, 0x0200
        .equiv  LATB9, 0x0009

        .equiv  LATB_LATB10, 0x000A
        .equiv  LATB_LATB10_WIDTH, 0x0001
        .equiv  LATB_LATB10_MASK, 0x0400
        .equiv  LATB10, 0x000A

        .equiv  LATB_LATB11, 0x000B
        .equiv  LATB_LATB11_WIDTH, 0x0001
        .equiv  LATB_LATB11_MASK, 0x0800
        .equiv  LATB11, 0x000B

        .equiv  LATB_LATB12, 0x000C
        .equiv  LATB_LATB12_WIDTH, 0x0001
        .equiv  LATB_LATB12_MASK, 0x1000
        .equiv  LATB12, 0x000C

        .equiv  LATB_LATB13, 0x000D
        .equiv  LATB_LATB13_WIDTH, 0x0001
        .equiv  LATB_LATB13_MASK, 0x2000
        .equiv  LATB13, 0x000D

        .equiv  LATB_LATB14, 0x000E
        .equiv  LATB_LATB14_WIDTH, 0x0001
        .equiv  LATB_LATB14_MASK, 0x4000
        .equiv  LATB14, 0x000E

        .equiv  LATB_LATB15, 0x000F
        .equiv  LATB_LATB15_WIDTH, 0x0001
        .equiv  LATB_LATB15_MASK, 0x8000
        .equiv  LATB15, 0x000F

;----- ODCB Bits -----------------------------------------------------
        .equiv  ODCB_ODCB0, 0x0000
        .equiv  ODCB_ODCB0_WIDTH, 0x0001
        .equiv  ODCB_ODCB0_MASK, 0x0001
        .equiv  ODCB0, 0x0000

        .equiv  ODCB_ODCB1, 0x0001
        .equiv  ODCB_ODCB1_WIDTH, 0x0001
        .equiv  ODCB_ODCB1_MASK, 0x0002
        .equiv  ODCB1, 0x0001

        .equiv  ODCB_ODCB2, 0x0002
        .equiv  ODCB_ODCB2_WIDTH, 0x0001
        .equiv  ODCB_ODCB2_MASK, 0x0004
        .equiv  ODCB2, 0x0002

        .equiv  ODCB_ODCB3, 0x0003
        .equiv  ODCB_ODCB3_WIDTH, 0x0001
        .equiv  ODCB_ODCB3_MASK, 0x0008
        .equiv  ODCB3, 0x0003

        .equiv  ODCB_ODCB4, 0x0004
        .equiv  ODCB_ODCB4_WIDTH, 0x0001
        .equiv  ODCB_ODCB4_MASK, 0x0010
        .equiv  ODCB4, 0x0004

        .equiv  ODCB_ODCB5, 0x0005
        .equiv  ODCB_ODCB5_WIDTH, 0x0001
        .equiv  ODCB_ODCB5_MASK, 0x0020
        .equiv  ODCB5, 0x0005

        .equiv  ODCB_ODCB6, 0x0006
        .equiv  ODCB_ODCB6_WIDTH, 0x0001
        .equiv  ODCB_ODCB6_MASK, 0x0040
        .equiv  ODCB6, 0x0006

        .equiv  ODCB_ODCB7, 0x0007
        .equiv  ODCB_ODCB7_WIDTH, 0x0001
        .equiv  ODCB_ODCB7_MASK, 0x0080
        .equiv  ODCB7, 0x0007

        .equiv  ODCB_ODCB8, 0x0008
        .equiv  ODCB_ODCB8_WIDTH, 0x0001
        .equiv  ODCB_ODCB8_MASK, 0x0100
        .equiv  ODCB8, 0x0008

        .equiv  ODCB_ODCB9, 0x0009
        .equiv  ODCB_ODCB9_WIDTH, 0x0001
        .equiv  ODCB_ODCB9_MASK, 0x0200
        .equiv  ODCB9, 0x0009

        .equiv  ODCB_ODCB10, 0x000A
        .equiv  ODCB_ODCB10_WIDTH, 0x0001
        .equiv  ODCB_ODCB10_MASK, 0x0400
        .equiv  ODCB10, 0x000A

        .equiv  ODCB_ODCB11, 0x000B
        .equiv  ODCB_ODCB11_WIDTH, 0x0001
        .equiv  ODCB_ODCB11_MASK, 0x0800
        .equiv  ODCB11, 0x000B

        .equiv  ODCB_ODCB12, 0x000C
        .equiv  ODCB_ODCB12_WIDTH, 0x0001
        .equiv  ODCB_ODCB12_MASK, 0x1000
        .equiv  ODCB12, 0x000C

        .equiv  ODCB_ODCB13, 0x000D
        .equiv  ODCB_ODCB13_WIDTH, 0x0001
        .equiv  ODCB_ODCB13_MASK, 0x2000
        .equiv  ODCB13, 0x000D

        .equiv  ODCB_ODCB14, 0x000E
        .equiv  ODCB_ODCB14_WIDTH, 0x0001
        .equiv  ODCB_ODCB14_MASK, 0x4000
        .equiv  ODCB14, 0x000E

        .equiv  ODCB_ODCB15, 0x000F
        .equiv  ODCB_ODCB15_WIDTH, 0x0001
        .equiv  ODCB_ODCB15_MASK, 0x8000
        .equiv  ODCB15, 0x000F

;----- CNENB Bits -----------------------------------------------------
        .equiv  CNENB_CNIEB0, 0x0000
        .equiv  CNENB_CNIEB0_WIDTH, 0x0001
        .equiv  CNENB_CNIEB0_MASK, 0x0001
        .equiv  CNIEB0, 0x0000

        .equiv  CNENB_CNIEB1, 0x0001
        .equiv  CNENB_CNIEB1_WIDTH, 0x0001
        .equiv  CNENB_CNIEB1_MASK, 0x0002
        .equiv  CNIEB1, 0x0001

        .equiv  CNENB_CNIEB2, 0x0002
        .equiv  CNENB_CNIEB2_WIDTH, 0x0001
        .equiv  CNENB_CNIEB2_MASK, 0x0004
        .equiv  CNIEB2, 0x0002

        .equiv  CNENB_CNIEB3, 0x0003
        .equiv  CNENB_CNIEB3_WIDTH, 0x0001
        .equiv  CNENB_CNIEB3_MASK, 0x0008
        .equiv  CNIEB3, 0x0003

        .equiv  CNENB_CNIEB4, 0x0004
        .equiv  CNENB_CNIEB4_WIDTH, 0x0001
        .equiv  CNENB_CNIEB4_MASK, 0x0010
        .equiv  CNIEB4, 0x0004

        .equiv  CNENB_CNIEB5, 0x0005
        .equiv  CNENB_CNIEB5_WIDTH, 0x0001
        .equiv  CNENB_CNIEB5_MASK, 0x0020
        .equiv  CNIEB5, 0x0005

        .equiv  CNENB_CNIEB6, 0x0006
        .equiv  CNENB_CNIEB6_WIDTH, 0x0001
        .equiv  CNENB_CNIEB6_MASK, 0x0040
        .equiv  CNIEB6, 0x0006

        .equiv  CNENB_CNIEB7, 0x0007
        .equiv  CNENB_CNIEB7_WIDTH, 0x0001
        .equiv  CNENB_CNIEB7_MASK, 0x0080
        .equiv  CNIEB7, 0x0007

        .equiv  CNENB_CNIEB8, 0x0008
        .equiv  CNENB_CNIEB8_WIDTH, 0x0001
        .equiv  CNENB_CNIEB8_MASK, 0x0100
        .equiv  CNIEB8, 0x0008

        .equiv  CNENB_CNIEB9, 0x0009
        .equiv  CNENB_CNIEB9_WIDTH, 0x0001
        .equiv  CNENB_CNIEB9_MASK, 0x0200
        .equiv  CNIEB9, 0x0009

        .equiv  CNENB_CNIEB10, 0x000A
        .equiv  CNENB_CNIEB10_WIDTH, 0x0001
        .equiv  CNENB_CNIEB10_MASK, 0x0400
        .equiv  CNIEB10, 0x000A

        .equiv  CNENB_CNIEB11, 0x000B
        .equiv  CNENB_CNIEB11_WIDTH, 0x0001
        .equiv  CNENB_CNIEB11_MASK, 0x0800
        .equiv  CNIEB11, 0x000B

        .equiv  CNENB_CNIEB12, 0x000C
        .equiv  CNENB_CNIEB12_WIDTH, 0x0001
        .equiv  CNENB_CNIEB12_MASK, 0x1000
        .equiv  CNIEB12, 0x000C

        .equiv  CNENB_CNIEB13, 0x000D
        .equiv  CNENB_CNIEB13_WIDTH, 0x0001
        .equiv  CNENB_CNIEB13_MASK, 0x2000
        .equiv  CNIEB13, 0x000D

        .equiv  CNENB_CNIEB14, 0x000E
        .equiv  CNENB_CNIEB14_WIDTH, 0x0001
        .equiv  CNENB_CNIEB14_MASK, 0x4000
        .equiv  CNIEB14, 0x000E

        .equiv  CNENB_CNIEB15, 0x000F
        .equiv  CNENB_CNIEB15_WIDTH, 0x0001
        .equiv  CNENB_CNIEB15_MASK, 0x8000
        .equiv  CNIEB15, 0x000F

;----- CNPUB Bits -----------------------------------------------------
        .equiv  CNPUB_CNPUB0, 0x0000
        .equiv  CNPUB_CNPUB0_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB0_MASK, 0x0001
        .equiv  CNPUB0, 0x0000

        .equiv  CNPUB_CNPUB1, 0x0001
        .equiv  CNPUB_CNPUB1_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB1_MASK, 0x0002
        .equiv  CNPUB1, 0x0001

        .equiv  CNPUB_CNPUB2, 0x0002
        .equiv  CNPUB_CNPUB2_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB2_MASK, 0x0004
        .equiv  CNPUB2, 0x0002

        .equiv  CNPUB_CNPUB3, 0x0003
        .equiv  CNPUB_CNPUB3_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB3_MASK, 0x0008
        .equiv  CNPUB3, 0x0003

        .equiv  CNPUB_CNPUB4, 0x0004
        .equiv  CNPUB_CNPUB4_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB4_MASK, 0x0010
        .equiv  CNPUB4, 0x0004

        .equiv  CNPUB_CNPUB5, 0x0005
        .equiv  CNPUB_CNPUB5_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB5_MASK, 0x0020
        .equiv  CNPUB5, 0x0005

        .equiv  CNPUB_CNPUB6, 0x0006
        .equiv  CNPUB_CNPUB6_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB6_MASK, 0x0040
        .equiv  CNPUB6, 0x0006

        .equiv  CNPUB_CNPUB7, 0x0007
        .equiv  CNPUB_CNPUB7_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB7_MASK, 0x0080
        .equiv  CNPUB7, 0x0007

        .equiv  CNPUB_CNPUB8, 0x0008
        .equiv  CNPUB_CNPUB8_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB8_MASK, 0x0100
        .equiv  CNPUB8, 0x0008

        .equiv  CNPUB_CNPUB9, 0x0009
        .equiv  CNPUB_CNPUB9_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB9_MASK, 0x0200
        .equiv  CNPUB9, 0x0009

        .equiv  CNPUB_CNPUB10, 0x000A
        .equiv  CNPUB_CNPUB10_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB10_MASK, 0x0400
        .equiv  CNPUB10, 0x000A

        .equiv  CNPUB_CNPUB11, 0x000B
        .equiv  CNPUB_CNPUB11_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB11_MASK, 0x0800
        .equiv  CNPUB11, 0x000B

        .equiv  CNPUB_CNPUB12, 0x000C
        .equiv  CNPUB_CNPUB12_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB12_MASK, 0x1000
        .equiv  CNPUB12, 0x000C

        .equiv  CNPUB_CNPUB13, 0x000D
        .equiv  CNPUB_CNPUB13_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB13_MASK, 0x2000
        .equiv  CNPUB13, 0x000D

        .equiv  CNPUB_CNPUB14, 0x000E
        .equiv  CNPUB_CNPUB14_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB14_MASK, 0x4000
        .equiv  CNPUB14, 0x000E

        .equiv  CNPUB_CNPUB15, 0x000F
        .equiv  CNPUB_CNPUB15_WIDTH, 0x0001
        .equiv  CNPUB_CNPUB15_MASK, 0x8000
        .equiv  CNPUB15, 0x000F

;----- CNPDB Bits -----------------------------------------------------
        .equiv  CNPDB_CNPDB0, 0x0000
        .equiv  CNPDB_CNPDB0_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB0_MASK, 0x0001
        .equiv  CNPDB0, 0x0000

        .equiv  CNPDB_CNPDB1, 0x0001
        .equiv  CNPDB_CNPDB1_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB1_MASK, 0x0002
        .equiv  CNPDB1, 0x0001

        .equiv  CNPDB_CNPDB2, 0x0002
        .equiv  CNPDB_CNPDB2_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB2_MASK, 0x0004
        .equiv  CNPDB2, 0x0002

        .equiv  CNPDB_CNPDB3, 0x0003
        .equiv  CNPDB_CNPDB3_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB3_MASK, 0x0008
        .equiv  CNPDB3, 0x0003

        .equiv  CNPDB_CNPDB4, 0x0004
        .equiv  CNPDB_CNPDB4_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB4_MASK, 0x0010
        .equiv  CNPDB4, 0x0004

        .equiv  CNPDB_CNPDB5, 0x0005
        .equiv  CNPDB_CNPDB5_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB5_MASK, 0x0020
        .equiv  CNPDB5, 0x0005

        .equiv  CNPDB_CNPDB6, 0x0006
        .equiv  CNPDB_CNPDB6_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB6_MASK, 0x0040
        .equiv  CNPDB6, 0x0006

        .equiv  CNPDB_CNPDB7, 0x0007
        .equiv  CNPDB_CNPDB7_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB7_MASK, 0x0080
        .equiv  CNPDB7, 0x0007

        .equiv  CNPDB_CNPDB8, 0x0008
        .equiv  CNPDB_CNPDB8_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB8_MASK, 0x0100
        .equiv  CNPDB8, 0x0008

        .equiv  CNPDB_CNPDB9, 0x0009
        .equiv  CNPDB_CNPDB9_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB9_MASK, 0x0200
        .equiv  CNPDB9, 0x0009

        .equiv  CNPDB_CNPDB10, 0x000A
        .equiv  CNPDB_CNPDB10_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB10_MASK, 0x0400
        .equiv  CNPDB10, 0x000A

        .equiv  CNPDB_CNPDB11, 0x000B
        .equiv  CNPDB_CNPDB11_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB11_MASK, 0x0800
        .equiv  CNPDB11, 0x000B

        .equiv  CNPDB_CNPDB12, 0x000C
        .equiv  CNPDB_CNPDB12_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB12_MASK, 0x1000
        .equiv  CNPDB12, 0x000C

        .equiv  CNPDB_CNPDB13, 0x000D
        .equiv  CNPDB_CNPDB13_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB13_MASK, 0x2000
        .equiv  CNPDB13, 0x000D

        .equiv  CNPDB_CNPDB14, 0x000E
        .equiv  CNPDB_CNPDB14_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB14_MASK, 0x4000
        .equiv  CNPDB14, 0x000E

        .equiv  CNPDB_CNPDB15, 0x000F
        .equiv  CNPDB_CNPDB15_WIDTH, 0x0001
        .equiv  CNPDB_CNPDB15_MASK, 0x8000
        .equiv  CNPDB15, 0x000F

;----- ANSELB Bits -----------------------------------------------------
        .equiv  ANSELB_ANSB0, 0x0000
        .equiv  ANSELB_ANSB0_WIDTH, 0x0001
        .equiv  ANSELB_ANSB0_MASK, 0x0001
        .equiv  ANSB0, 0x0000

        .equiv  ANSELB_ANSB1, 0x0001
        .equiv  ANSELB_ANSB1_WIDTH, 0x0001
        .equiv  ANSELB_ANSB1_MASK, 0x0002
        .equiv  ANSB1, 0x0001

        .equiv  ANSELB_ANSB2, 0x0002
        .equiv  ANSELB_ANSB2_WIDTH, 0x0001
        .equiv  ANSELB_ANSB2_MASK, 0x0004
        .equiv  ANSB2, 0x0002

        .equiv  ANSELB_ANSB3, 0x0003
        .equiv  ANSELB_ANSB3_WIDTH, 0x0001
        .equiv  ANSELB_ANSB3_MASK, 0x0008
        .equiv  ANSB3, 0x0003

        .equiv  ANSELB_ANSB8, 0x0008
        .equiv  ANSELB_ANSB8_WIDTH, 0x0001
        .equiv  ANSELB_ANSB8_MASK, 0x0100
        .equiv  ANSB8, 0x0008

;----- TRISC Bits -----------------------------------------------------
        .equiv  TRISC_TRISC0, 0x0000
        .equiv  TRISC_TRISC0_WIDTH, 0x0001
        .equiv  TRISC_TRISC0_MASK, 0x0001
        .equiv  TRISC0, 0x0000

        .equiv  TRISC_TRISC1, 0x0001
        .equiv  TRISC_TRISC1_WIDTH, 0x0001
        .equiv  TRISC_TRISC1_MASK, 0x0002
        .equiv  TRISC1, 0x0001

        .equiv  TRISC_TRISC2, 0x0002
        .equiv  TRISC_TRISC2_WIDTH, 0x0001
        .equiv  TRISC_TRISC2_MASK, 0x0004
        .equiv  TRISC2, 0x0002

        .equiv  TRISC_TRISC3, 0x0003
        .equiv  TRISC_TRISC3_WIDTH, 0x0001
        .equiv  TRISC_TRISC3_MASK, 0x0008
        .equiv  TRISC3, 0x0003

        .equiv  TRISC_TRISC4, 0x0004
        .equiv  TRISC_TRISC4_WIDTH, 0x0001
        .equiv  TRISC_TRISC4_MASK, 0x0010
        .equiv  TRISC4, 0x0004

        .equiv  TRISC_TRISC5, 0x0005
        .equiv  TRISC_TRISC5_WIDTH, 0x0001
        .equiv  TRISC_TRISC5_MASK, 0x0020
        .equiv  TRISC5, 0x0005

        .equiv  TRISC_TRISC6, 0x0006
        .equiv  TRISC_TRISC6_WIDTH, 0x0001
        .equiv  TRISC_TRISC6_MASK, 0x0040
        .equiv  TRISC6, 0x0006

        .equiv  TRISC_TRISC7, 0x0007
        .equiv  TRISC_TRISC7_WIDTH, 0x0001
        .equiv  TRISC_TRISC7_MASK, 0x0080
        .equiv  TRISC7, 0x0007

        .equiv  TRISC_TRISC8, 0x0008
        .equiv  TRISC_TRISC8_WIDTH, 0x0001
        .equiv  TRISC_TRISC8_MASK, 0x0100
        .equiv  TRISC8, 0x0008

        .equiv  TRISC_TRISC9, 0x0009
        .equiv  TRISC_TRISC9_WIDTH, 0x0001
        .equiv  TRISC_TRISC9_MASK, 0x0200
        .equiv  TRISC9, 0x0009

        .equiv  TRISC_TRISC10, 0x000A
        .equiv  TRISC_TRISC10_WIDTH, 0x0001
        .equiv  TRISC_TRISC10_MASK, 0x0400
        .equiv  TRISC10, 0x000A

        .equiv  TRISC_TRISC11, 0x000B
        .equiv  TRISC_TRISC11_WIDTH, 0x0001
        .equiv  TRISC_TRISC11_MASK, 0x0800
        .equiv  TRISC11, 0x000B

        .equiv  TRISC_TRISC12, 0x000C
        .equiv  TRISC_TRISC12_WIDTH, 0x0001
        .equiv  TRISC_TRISC12_MASK, 0x1000
        .equiv  TRISC12, 0x000C

        .equiv  TRISC_TRISC13, 0x000D
        .equiv  TRISC_TRISC13_WIDTH, 0x0001
        .equiv  TRISC_TRISC13_MASK, 0x2000
        .equiv  TRISC13, 0x000D

        .equiv  TRISC_TRISC15, 0x000F
        .equiv  TRISC_TRISC15_WIDTH, 0x0001
        .equiv  TRISC_TRISC15_MASK, 0x8000
        .equiv  TRISC15, 0x000F

;----- PORTC Bits -----------------------------------------------------
        .equiv  PORTC_RC0, 0x0000
        .equiv  PORTC_RC0_WIDTH, 0x0001
        .equiv  PORTC_RC0_MASK, 0x0001
        .equiv  RC0, 0x0000

        .equiv  PORTC_RC1, 0x0001
        .equiv  PORTC_RC1_WIDTH, 0x0001
        .equiv  PORTC_RC1_MASK, 0x0002
        .equiv  RC1, 0x0001

        .equiv  PORTC_RC2, 0x0002
        .equiv  PORTC_RC2_WIDTH, 0x0001
        .equiv  PORTC_RC2_MASK, 0x0004
        .equiv  RC2, 0x0002

        .equiv  PORTC_RC3, 0x0003
        .equiv  PORTC_RC3_WIDTH, 0x0001
        .equiv  PORTC_RC3_MASK, 0x0008
        .equiv  RC3, 0x0003

        .equiv  PORTC_RC4, 0x0004
        .equiv  PORTC_RC4_WIDTH, 0x0001
        .equiv  PORTC_RC4_MASK, 0x0010
        .equiv  RC4, 0x0004

        .equiv  PORTC_RC5, 0x0005
        .equiv  PORTC_RC5_WIDTH, 0x0001
        .equiv  PORTC_RC5_MASK, 0x0020
        .equiv  RC5, 0x0005

        .equiv  PORTC_RC6, 0x0006
        .equiv  PORTC_RC6_WIDTH, 0x0001
        .equiv  PORTC_RC6_MASK, 0x0040
        .equiv  RC6, 0x0006

        .equiv  PORTC_RC7, 0x0007
        .equiv  PORTC_RC7_WIDTH, 0x0001
        .equiv  PORTC_RC7_MASK, 0x0080
        .equiv  RC7, 0x0007

        .equiv  PORTC_RC8, 0x0008
        .equiv  PORTC_RC8_WIDTH, 0x0001
        .equiv  PORTC_RC8_MASK, 0x0100
        .equiv  RC8, 0x0008

        .equiv  PORTC_RC9, 0x0009
        .equiv  PORTC_RC9_WIDTH, 0x0001
        .equiv  PORTC_RC9_MASK, 0x0200
        .equiv  RC9, 0x0009

        .equiv  PORTC_RC10, 0x000A
        .equiv  PORTC_RC10_WIDTH, 0x0001
        .equiv  PORTC_RC10_MASK, 0x0400
        .equiv  RC10, 0x000A

        .equiv  PORTC_RC11, 0x000B
        .equiv  PORTC_RC11_WIDTH, 0x0001
        .equiv  PORTC_RC11_MASK, 0x0800
        .equiv  RC11, 0x000B

        .equiv  PORTC_RC12, 0x000C
        .equiv  PORTC_RC12_WIDTH, 0x0001
        .equiv  PORTC_RC12_MASK, 0x1000
        .equiv  RC12, 0x000C

        .equiv  PORTC_RC13, 0x000D
        .equiv  PORTC_RC13_WIDTH, 0x0001
        .equiv  PORTC_RC13_MASK, 0x2000
        .equiv  RC13, 0x000D

        .equiv  PORTC_RC15, 0x000F
        .equiv  PORTC_RC15_WIDTH, 0x0001
        .equiv  PORTC_RC15_MASK, 0x8000
        .equiv  RC15, 0x000F

;----- LATC Bits -----------------------------------------------------
        .equiv  LATC_LATC0, 0x0000
        .equiv  LATC_LATC0_WIDTH, 0x0001
        .equiv  LATC_LATC0_MASK, 0x0001
        .equiv  LATC0, 0x0000

        .equiv  LATC_LATC1, 0x0001
        .equiv  LATC_LATC1_WIDTH, 0x0001
        .equiv  LATC_LATC1_MASK, 0x0002
        .equiv  LATC1, 0x0001

        .equiv  LATC_LATC2, 0x0002
        .equiv  LATC_LATC2_WIDTH, 0x0001
        .equiv  LATC_LATC2_MASK, 0x0004
        .equiv  LATC2, 0x0002

        .equiv  LATC_LATC3, 0x0003
        .equiv  LATC_LATC3_WIDTH, 0x0001
        .equiv  LATC_LATC3_MASK, 0x0008
        .equiv  LATC3, 0x0003

        .equiv  LATC_LATC4, 0x0004
        .equiv  LATC_LATC4_WIDTH, 0x0001
        .equiv  LATC_LATC4_MASK, 0x0010
        .equiv  LATC4, 0x0004

        .equiv  LATC_LATC5, 0x0005
        .equiv  LATC_LATC5_WIDTH, 0x0001
        .equiv  LATC_LATC5_MASK, 0x0020
        .equiv  LATC5, 0x0005

        .equiv  LATC_LATC6, 0x0006
        .equiv  LATC_LATC6_WIDTH, 0x0001
        .equiv  LATC_LATC6_MASK, 0x0040
        .equiv  LATC6, 0x0006

        .equiv  LATC_LATC7, 0x0007
        .equiv  LATC_LATC7_WIDTH, 0x0001
        .equiv  LATC_LATC7_MASK, 0x0080
        .equiv  LATC7, 0x0007

        .equiv  LATC_LATC8, 0x0008
        .equiv  LATC_LATC8_WIDTH, 0x0001
        .equiv  LATC_LATC8_MASK, 0x0100
        .equiv  LATC8, 0x0008

        .equiv  LATC_LATC9, 0x0009
        .equiv  LATC_LATC9_WIDTH, 0x0001
        .equiv  LATC_LATC9_MASK, 0x0200
        .equiv  LATC9, 0x0009

        .equiv  LATC_LATC10, 0x000A
        .equiv  LATC_LATC10_WIDTH, 0x0001
        .equiv  LATC_LATC10_MASK, 0x0400
        .equiv  LATC10, 0x000A

        .equiv  LATC_LATC11, 0x000B
        .equiv  LATC_LATC11_WIDTH, 0x0001
        .equiv  LATC_LATC11_MASK, 0x0800
        .equiv  LATC11, 0x000B

        .equiv  LATC_LATC12, 0x000C
        .equiv  LATC_LATC12_WIDTH, 0x0001
        .equiv  LATC_LATC12_MASK, 0x1000
        .equiv  LATC12, 0x000C

        .equiv  LATC_LATC13, 0x000D
        .equiv  LATC_LATC13_WIDTH, 0x0001
        .equiv  LATC_LATC13_MASK, 0x2000
        .equiv  LATC13, 0x000D

        .equiv  LATC_LATC15, 0x000F
        .equiv  LATC_LATC15_WIDTH, 0x0001
        .equiv  LATC_LATC15_MASK, 0x8000
        .equiv  LATC15, 0x000F

;----- ODCC Bits -----------------------------------------------------
        .equiv  ODCC_ODCC0, 0x0000
        .equiv  ODCC_ODCC0_WIDTH, 0x0001
        .equiv  ODCC_ODCC0_MASK, 0x0001
        .equiv  ODCC0, 0x0000

        .equiv  ODCC_ODCC1, 0x0001
        .equiv  ODCC_ODCC1_WIDTH, 0x0001
        .equiv  ODCC_ODCC1_MASK, 0x0002
        .equiv  ODCC1, 0x0001

        .equiv  ODCC_ODCC2, 0x0002
        .equiv  ODCC_ODCC2_WIDTH, 0x0001
        .equiv  ODCC_ODCC2_MASK, 0x0004
        .equiv  ODCC2, 0x0002

        .equiv  ODCC_ODCC3, 0x0003
        .equiv  ODCC_ODCC3_WIDTH, 0x0001
        .equiv  ODCC_ODCC3_MASK, 0x0008
        .equiv  ODCC3, 0x0003

        .equiv  ODCC_ODCC4, 0x0004
        .equiv  ODCC_ODCC4_WIDTH, 0x0001
        .equiv  ODCC_ODCC4_MASK, 0x0010
        .equiv  ODCC4, 0x0004

        .equiv  ODCC_ODCC5, 0x0005
        .equiv  ODCC_ODCC5_WIDTH, 0x0001
        .equiv  ODCC_ODCC5_MASK, 0x0020
        .equiv  ODCC5, 0x0005

        .equiv  ODCC_ODCC6, 0x0006
        .equiv  ODCC_ODCC6_WIDTH, 0x0001
        .equiv  ODCC_ODCC6_MASK, 0x0040
        .equiv  ODCC6, 0x0006

        .equiv  ODCC_ODCC7, 0x0007
        .equiv  ODCC_ODCC7_WIDTH, 0x0001
        .equiv  ODCC_ODCC7_MASK, 0x0080
        .equiv  ODCC7, 0x0007

        .equiv  ODCC_ODCC8, 0x0008
        .equiv  ODCC_ODCC8_WIDTH, 0x0001
        .equiv  ODCC_ODCC8_MASK, 0x0100
        .equiv  ODCC8, 0x0008

        .equiv  ODCC_ODCC9, 0x0009
        .equiv  ODCC_ODCC9_WIDTH, 0x0001
        .equiv  ODCC_ODCC9_MASK, 0x0200
        .equiv  ODCC9, 0x0009

        .equiv  ODCC_ODCC10, 0x000A
        .equiv  ODCC_ODCC10_WIDTH, 0x0001
        .equiv  ODCC_ODCC10_MASK, 0x0400
        .equiv  ODCC10, 0x000A

        .equiv  ODCC_ODCC11, 0x000B
        .equiv  ODCC_ODCC11_WIDTH, 0x0001
        .equiv  ODCC_ODCC11_MASK, 0x0800
        .equiv  ODCC11, 0x000B

        .equiv  ODCC_ODCC12, 0x000C
        .equiv  ODCC_ODCC12_WIDTH, 0x0001
        .equiv  ODCC_ODCC12_MASK, 0x1000
        .equiv  ODCC12, 0x000C

        .equiv  ODCC_ODCC13, 0x000D
        .equiv  ODCC_ODCC13_WIDTH, 0x0001
        .equiv  ODCC_ODCC13_MASK, 0x2000
        .equiv  ODCC13, 0x000D

        .equiv  ODCC_ODCC15, 0x000F
        .equiv  ODCC_ODCC15_WIDTH, 0x0001
        .equiv  ODCC_ODCC15_MASK, 0x8000
        .equiv  ODCC15, 0x000F

;----- CNENC Bits -----------------------------------------------------
        .equiv  CNENC_CNIEC0, 0x0000
        .equiv  CNENC_CNIEC0_WIDTH, 0x0001
        .equiv  CNENC_CNIEC0_MASK, 0x0001
        .equiv  CNIEC0, 0x0000

        .equiv  CNENC_CNIEC1, 0x0001
        .equiv  CNENC_CNIEC1_WIDTH, 0x0001
        .equiv  CNENC_CNIEC1_MASK, 0x0002
        .equiv  CNIEC1, 0x0001

        .equiv  CNENC_CNIEC2, 0x0002
        .equiv  CNENC_CNIEC2_WIDTH, 0x0001
        .equiv  CNENC_CNIEC2_MASK, 0x0004
        .equiv  CNIEC2, 0x0002

        .equiv  CNENC_CNIEC3, 0x0003
        .equiv  CNENC_CNIEC3_WIDTH, 0x0001
        .equiv  CNENC_CNIEC3_MASK, 0x0008
        .equiv  CNIEC3, 0x0003

        .equiv  CNENC_CNIEC4, 0x0004
        .equiv  CNENC_CNIEC4_WIDTH, 0x0001
        .equiv  CNENC_CNIEC4_MASK, 0x0010
        .equiv  CNIEC4, 0x0004

        .equiv  CNENC_CNIEC5, 0x0005
        .equiv  CNENC_CNIEC5_WIDTH, 0x0001
        .equiv  CNENC_CNIEC5_MASK, 0x0020
        .equiv  CNIEC5, 0x0005

        .equiv  CNENC_CNIEC6, 0x0006
        .equiv  CNENC_CNIEC6_WIDTH, 0x0001
        .equiv  CNENC_CNIEC6_MASK, 0x0040
        .equiv  CNIEC6, 0x0006

        .equiv  CNENC_CNIEC7, 0x0007
        .equiv  CNENC_CNIEC7_WIDTH, 0x0001
        .equiv  CNENC_CNIEC7_MASK, 0x0080
        .equiv  CNIEC7, 0x0007

        .equiv  CNENC_CNIEC8, 0x0008
        .equiv  CNENC_CNIEC8_WIDTH, 0x0001
        .equiv  CNENC_CNIEC8_MASK, 0x0100
        .equiv  CNIEC8, 0x0008

        .equiv  CNENC_CNIEC9, 0x0009
        .equiv  CNENC_CNIEC9_WIDTH, 0x0001
        .equiv  CNENC_CNIEC9_MASK, 0x0200
        .equiv  CNIEC9, 0x0009

        .equiv  CNENC_CNIEC10, 0x000A
        .equiv  CNENC_CNIEC10_WIDTH, 0x0001
        .equiv  CNENC_CNIEC10_MASK, 0x0400
        .equiv  CNIEC10, 0x000A

        .equiv  CNENC_CNIEC11, 0x000B
        .equiv  CNENC_CNIEC11_WIDTH, 0x0001
        .equiv  CNENC_CNIEC11_MASK, 0x0800
        .equiv  CNIEC11, 0x000B

        .equiv  CNENC_CNIEC12, 0x000C
        .equiv  CNENC_CNIEC12_WIDTH, 0x0001
        .equiv  CNENC_CNIEC12_MASK, 0x1000
        .equiv  CNIEC12, 0x000C

        .equiv  CNENC_CNIEC13, 0x000D
        .equiv  CNENC_CNIEC13_WIDTH, 0x0001
        .equiv  CNENC_CNIEC13_MASK, 0x2000
        .equiv  CNIEC13, 0x000D

        .equiv  CNENC_CNIEC15, 0x000F
        .equiv  CNENC_CNIEC15_WIDTH, 0x0001
        .equiv  CNENC_CNIEC15_MASK, 0x8000
        .equiv  CNIEC15, 0x000F

;----- CNPUC Bits -----------------------------------------------------
        .equiv  CNPUC_CNPUC0, 0x0000
        .equiv  CNPUC_CNPUC0_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC0_MASK, 0x0001
        .equiv  CNPUC0, 0x0000

        .equiv  CNPUC_CNPUC1, 0x0001
        .equiv  CNPUC_CNPUC1_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC1_MASK, 0x0002
        .equiv  CNPUC1, 0x0001

        .equiv  CNPUC_CNPUC2, 0x0002
        .equiv  CNPUC_CNPUC2_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC2_MASK, 0x0004
        .equiv  CNPUC2, 0x0002

        .equiv  CNPUC_CNPUC3, 0x0003
        .equiv  CNPUC_CNPUC3_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC3_MASK, 0x0008
        .equiv  CNPUC3, 0x0003

        .equiv  CNPUC_CNPUC4, 0x0004
        .equiv  CNPUC_CNPUC4_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC4_MASK, 0x0010
        .equiv  CNPUC4, 0x0004

        .equiv  CNPUC_CNPUC5, 0x0005
        .equiv  CNPUC_CNPUC5_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC5_MASK, 0x0020
        .equiv  CNPUC5, 0x0005

        .equiv  CNPUC_CNPUC6, 0x0006
        .equiv  CNPUC_CNPUC6_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC6_MASK, 0x0040
        .equiv  CNPUC6, 0x0006

        .equiv  CNPUC_CNPUC7, 0x0007
        .equiv  CNPUC_CNPUC7_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC7_MASK, 0x0080
        .equiv  CNPUC7, 0x0007

        .equiv  CNPUC_CNPUC8, 0x0008
        .equiv  CNPUC_CNPUC8_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC8_MASK, 0x0100
        .equiv  CNPUC8, 0x0008

        .equiv  CNPUC_CNPUC9, 0x0009
        .equiv  CNPUC_CNPUC9_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC9_MASK, 0x0200
        .equiv  CNPUC9, 0x0009

        .equiv  CNPUC_CNPUC10, 0x000A
        .equiv  CNPUC_CNPUC10_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC10_MASK, 0x0400
        .equiv  CNPUC10, 0x000A

        .equiv  CNPUC_CNPUC11, 0x000B
        .equiv  CNPUC_CNPUC11_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC11_MASK, 0x0800
        .equiv  CNPUC11, 0x000B

        .equiv  CNPUC_CNPUC12, 0x000C
        .equiv  CNPUC_CNPUC12_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC12_MASK, 0x1000
        .equiv  CNPUC12, 0x000C

        .equiv  CNPUC_CNPUC13, 0x000D
        .equiv  CNPUC_CNPUC13_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC13_MASK, 0x2000
        .equiv  CNPUC13, 0x000D

        .equiv  CNPUC_CNPUC15, 0x000F
        .equiv  CNPUC_CNPUC15_WIDTH, 0x0001
        .equiv  CNPUC_CNPUC15_MASK, 0x8000
        .equiv  CNPUC15, 0x000F

;----- CNPDC Bits -----------------------------------------------------
        .equiv  CNPDC_CNPDC0, 0x0000
        .equiv  CNPDC_CNPDC0_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC0_MASK, 0x0001
        .equiv  CNPDC0, 0x0000

        .equiv  CNPDC_CNPDC1, 0x0001
        .equiv  CNPDC_CNPDC1_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC1_MASK, 0x0002
        .equiv  CNPDC1, 0x0001

        .equiv  CNPDC_CNPDC2, 0x0002
        .equiv  CNPDC_CNPDC2_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC2_MASK, 0x0004
        .equiv  CNPDC2, 0x0002

        .equiv  CNPDC_CNPDC3, 0x0003
        .equiv  CNPDC_CNPDC3_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC3_MASK, 0x0008
        .equiv  CNPDC3, 0x0003

        .equiv  CNPDC_CNPDC4, 0x0004
        .equiv  CNPDC_CNPDC4_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC4_MASK, 0x0010
        .equiv  CNPDC4, 0x0004

        .equiv  CNPDC_CNPDC5, 0x0005
        .equiv  CNPDC_CNPDC5_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC5_MASK, 0x0020
        .equiv  CNPDC5, 0x0005

        .equiv  CNPDC_CNPDC6, 0x0006
        .equiv  CNPDC_CNPDC6_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC6_MASK, 0x0040
        .equiv  CNPDC6, 0x0006

        .equiv  CNPDC_CNPDC7, 0x0007
        .equiv  CNPDC_CNPDC7_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC7_MASK, 0x0080
        .equiv  CNPDC7, 0x0007

        .equiv  CNPDC_CNPDC8, 0x0008
        .equiv  CNPDC_CNPDC8_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC8_MASK, 0x0100
        .equiv  CNPDC8, 0x0008

        .equiv  CNPDC_CNPDC9, 0x0009
        .equiv  CNPDC_CNPDC9_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC9_MASK, 0x0200
        .equiv  CNPDC9, 0x0009

        .equiv  CNPDC_CNPDC10, 0x000A
        .equiv  CNPDC_CNPDC10_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC10_MASK, 0x0400
        .equiv  CNPDC10, 0x000A

        .equiv  CNPDC_CNPDC11, 0x000B
        .equiv  CNPDC_CNPDC11_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC11_MASK, 0x0800
        .equiv  CNPDC11, 0x000B

        .equiv  CNPDC_CNPDC12, 0x000C
        .equiv  CNPDC_CNPDC12_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC12_MASK, 0x1000
        .equiv  CNPDC12, 0x000C

        .equiv  CNPDC_CNPDC13, 0x000D
        .equiv  CNPDC_CNPDC13_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC13_MASK, 0x2000
        .equiv  CNPDC13, 0x000D

        .equiv  CNPDC_CNPDC15, 0x000F
        .equiv  CNPDC_CNPDC15_WIDTH, 0x0001
        .equiv  CNPDC_CNPDC15_MASK, 0x8000
        .equiv  CNPDC15, 0x000F

;----- ANSELC Bits -----------------------------------------------------
        .equiv  ANSELC_ANSC0, 0x0000
        .equiv  ANSELC_ANSC0_WIDTH, 0x0001
        .equiv  ANSELC_ANSC0_MASK, 0x0001
        .equiv  ANSC0, 0x0000

        .equiv  ANSELC_ANSC1, 0x0001
        .equiv  ANSELC_ANSC1_WIDTH, 0x0001
        .equiv  ANSELC_ANSC1_MASK, 0x0002
        .equiv  ANSC1, 0x0001

        .equiv  ANSELC_ANSC2, 0x0002
        .equiv  ANSELC_ANSC2_WIDTH, 0x0001
        .equiv  ANSELC_ANSC2_MASK, 0x0004
        .equiv  ANSC2, 0x0002

        .equiv  ANSELC_ANSC11, 0x000B
        .equiv  ANSELC_ANSC11_WIDTH, 0x0001
        .equiv  ANSELC_ANSC11_MASK, 0x0800
        .equiv  ANSC11, 0x000B

;----- TRISD Bits -----------------------------------------------------
        .equiv  TRISD_TRISD5, 0x0005
        .equiv  TRISD_TRISD5_WIDTH, 0x0001
        .equiv  TRISD_TRISD5_MASK, 0x0020
        .equiv  TRISD5, 0x0005

        .equiv  TRISD_TRISD6, 0x0006
        .equiv  TRISD_TRISD6_WIDTH, 0x0001
        .equiv  TRISD_TRISD6_MASK, 0x0040
        .equiv  TRISD6, 0x0006

        .equiv  TRISD_TRISD8, 0x0008
        .equiv  TRISD_TRISD8_WIDTH, 0x0001
        .equiv  TRISD_TRISD8_MASK, 0x0100
        .equiv  TRISD8, 0x0008

;----- PORTD Bits -----------------------------------------------------
        .equiv  PORTD_RD5, 0x0005
        .equiv  PORTD_RD5_WIDTH, 0x0001
        .equiv  PORTD_RD5_MASK, 0x0020
        .equiv  RD5, 0x0005

        .equiv  PORTD_RD6, 0x0006
        .equiv  PORTD_RD6_WIDTH, 0x0001
        .equiv  PORTD_RD6_MASK, 0x0040
        .equiv  RD6, 0x0006

        .equiv  PORTD_RD8, 0x0008
        .equiv  PORTD_RD8_WIDTH, 0x0001
        .equiv  PORTD_RD8_MASK, 0x0100
        .equiv  RD8, 0x0008

;----- LATD Bits -----------------------------------------------------
        .equiv  LATD_LATD5, 0x0005
        .equiv  LATD_LATD5_WIDTH, 0x0001
        .equiv  LATD_LATD5_MASK, 0x0020
        .equiv  LATD5, 0x0005

        .equiv  LATD_LATD6, 0x0006
        .equiv  LATD_LATD6_WIDTH, 0x0001
        .equiv  LATD_LATD6_MASK, 0x0040
        .equiv  LATD6, 0x0006

        .equiv  LATD_LATD8, 0x0008
        .equiv  LATD_LATD8_WIDTH, 0x0001
        .equiv  LATD_LATD8_MASK, 0x0100
        .equiv  LATD8, 0x0008

;----- ODCD Bits -----------------------------------------------------
        .equiv  ODCD_ODCD5, 0x0005
        .equiv  ODCD_ODCD5_WIDTH, 0x0001
        .equiv  ODCD_ODCD5_MASK, 0x0020
        .equiv  ODCD5, 0x0005

        .equiv  ODCD_ODCD6, 0x0006
        .equiv  ODCD_ODCD6_WIDTH, 0x0001
        .equiv  ODCD_ODCD6_MASK, 0x0040
        .equiv  ODCD6, 0x0006

        .equiv  ODCD_ODCD8, 0x0008
        .equiv  ODCD_ODCD8_WIDTH, 0x0001
        .equiv  ODCD_ODCD8_MASK, 0x0100
        .equiv  ODCD8, 0x0008

;----- CNEND Bits -----------------------------------------------------
        .equiv  CNEND_CNIED5, 0x0005
        .equiv  CNEND_CNIED5_WIDTH, 0x0001
        .equiv  CNEND_CNIED5_MASK, 0x0020
        .equiv  CNIED5, 0x0005

        .equiv  CNEND_CNIED6, 0x0006
        .equiv  CNEND_CNIED6_WIDTH, 0x0001
        .equiv  CNEND_CNIED6_MASK, 0x0040
        .equiv  CNIED6, 0x0006

        .equiv  CNEND_CNIED8, 0x0008
        .equiv  CNEND_CNIED8_WIDTH, 0x0001
        .equiv  CNEND_CNIED8_MASK, 0x0100
        .equiv  CNIED8, 0x0008

;----- CNPUD Bits -----------------------------------------------------
        .equiv  CNPUD_CNPUD5, 0x0005
        .equiv  CNPUD_CNPUD5_WIDTH, 0x0001
        .equiv  CNPUD_CNPUD5_MASK, 0x0020
        .equiv  CNPUD5, 0x0005

        .equiv  CNPUD_CNPUD6, 0x0006
        .equiv  CNPUD_CNPUD6_WIDTH, 0x0001
        .equiv  CNPUD_CNPUD6_MASK, 0x0040
        .equiv  CNPUD6, 0x0006

        .equiv  CNPUD_CNPUD8, 0x0008
        .equiv  CNPUD_CNPUD8_WIDTH, 0x0001
        .equiv  CNPUD_CNPUD8_MASK, 0x0100
        .equiv  CNPUD8, 0x0008

;----- CNPDD Bits -----------------------------------------------------
        .equiv  CNPDD_CNPDD5, 0x0005
        .equiv  CNPDD_CNPDD5_WIDTH, 0x0001
        .equiv  CNPDD_CNPDD5_MASK, 0x0020
        .equiv  CNPDD5, 0x0005

        .equiv  CNPDD_CNPDD6, 0x0006
        .equiv  CNPDD_CNPDD6_WIDTH, 0x0001
        .equiv  CNPDD_CNPDD6_MASK, 0x0040
        .equiv  CNPDD6, 0x0006

        .equiv  CNPDD_CNPDD8, 0x0008
        .equiv  CNPDD_CNPDD8_WIDTH, 0x0001
        .equiv  CNPDD_CNPDD8_MASK, 0x0100
        .equiv  CNPDD8, 0x0008

;----- TRISE Bits -----------------------------------------------------
        .equiv  TRISE_TRISE12, 0x000C
        .equiv  TRISE_TRISE12_WIDTH, 0x0001
        .equiv  TRISE_TRISE12_MASK, 0x1000
        .equiv  TRISE12, 0x000C

        .equiv  TRISE_TRISE13, 0x000D
        .equiv  TRISE_TRISE13_WIDTH, 0x0001
        .equiv  TRISE_TRISE13_MASK, 0x2000
        .equiv  TRISE13, 0x000D

        .equiv  TRISE_TRISE14, 0x000E
        .equiv  TRISE_TRISE14_WIDTH, 0x0001
        .equiv  TRISE_TRISE14_MASK, 0x4000
        .equiv  TRISE14, 0x000E

        .equiv  TRISE_TRISE15, 0x000F
        .equiv  TRISE_TRISE15_WIDTH, 0x0001
        .equiv  TRISE_TRISE15_MASK, 0x8000
        .equiv  TRISE15, 0x000F

;----- PORTE Bits -----------------------------------------------------
        .equiv  PORTE_RE12, 0x000C
        .equiv  PORTE_RE12_WIDTH, 0x0001
        .equiv  PORTE_RE12_MASK, 0x1000
        .equiv  RE12, 0x000C

        .equiv  PORTE_RE13, 0x000D
        .equiv  PORTE_RE13_WIDTH, 0x0001
        .equiv  PORTE_RE13_MASK, 0x2000
        .equiv  RE13, 0x000D

        .equiv  PORTE_RE14, 0x000E
        .equiv  PORTE_RE14_WIDTH, 0x0001
        .equiv  PORTE_RE14_MASK, 0x4000
        .equiv  RE14, 0x000E

        .equiv  PORTE_RE15, 0x000F
        .equiv  PORTE_RE15_WIDTH, 0x0001
        .equiv  PORTE_RE15_MASK, 0x8000
        .equiv  RE15, 0x000F

;----- LATE Bits -----------------------------------------------------
        .equiv  LATE_LATE12, 0x000C
        .equiv  LATE_LATE12_WIDTH, 0x0001
        .equiv  LATE_LATE12_MASK, 0x1000
        .equiv  LATE12, 0x000C

        .equiv  LATE_LATE13, 0x000D
        .equiv  LATE_LATE13_WIDTH, 0x0001
        .equiv  LATE_LATE13_MASK, 0x2000
        .equiv  LATE13, 0x000D

        .equiv  LATE_LATE14, 0x000E
        .equiv  LATE_LATE14_WIDTH, 0x0001
        .equiv  LATE_LATE14_MASK, 0x4000
        .equiv  LATE14, 0x000E

        .equiv  LATE_LATE15, 0x000F
        .equiv  LATE_LATE15_WIDTH, 0x0001
        .equiv  LATE_LATE15_MASK, 0x8000
        .equiv  LATE15, 0x000F

;----- ODCE Bits -----------------------------------------------------
        .equiv  ODCE_ODCE12, 0x000C
        .equiv  ODCE_ODCE12_WIDTH, 0x0001
        .equiv  ODCE_ODCE12_MASK, 0x1000
        .equiv  ODCE12, 0x000C

        .equiv  ODCE_ODCE13, 0x000D
        .equiv  ODCE_ODCE13_WIDTH, 0x0001
        .equiv  ODCE_ODCE13_MASK, 0x2000
        .equiv  ODCE13, 0x000D

        .equiv  ODCE_ODCE14, 0x000E
        .equiv  ODCE_ODCE14_WIDTH, 0x0001
        .equiv  ODCE_ODCE14_MASK, 0x4000
        .equiv  ODCE14, 0x000E

        .equiv  ODCE_ODCE15, 0x000F
        .equiv  ODCE_ODCE15_WIDTH, 0x0001
        .equiv  ODCE_ODCE15_MASK, 0x8000
        .equiv  ODCE15, 0x000F

;----- CNENE Bits -----------------------------------------------------
        .equiv  CNENE_CNIEE12, 0x000C
        .equiv  CNENE_CNIEE12_WIDTH, 0x0001
        .equiv  CNENE_CNIEE12_MASK, 0x1000
        .equiv  CNIEE12, 0x000C

        .equiv  CNENE_CNIEE13, 0x000D
        .equiv  CNENE_CNIEE13_WIDTH, 0x0001
        .equiv  CNENE_CNIEE13_MASK, 0x2000
        .equiv  CNIEE13, 0x000D

        .equiv  CNENE_CNIEE14, 0x000E
        .equiv  CNENE_CNIEE14_WIDTH, 0x0001
        .equiv  CNENE_CNIEE14_MASK, 0x4000
        .equiv  CNIEE14, 0x000E

        .equiv  CNENE_CNIEE15, 0x000F
        .equiv  CNENE_CNIEE15_WIDTH, 0x0001
        .equiv  CNENE_CNIEE15_MASK, 0x8000
        .equiv  CNIEE15, 0x000F

;----- CNPUE Bits -----------------------------------------------------
        .equiv  CNPUE_CNPUE12, 0x000C
        .equiv  CNPUE_CNPUE12_WIDTH, 0x0001
        .equiv  CNPUE_CNPUE12_MASK, 0x1000
        .equiv  CNPUE12, 0x000C

        .equiv  CNPUE_CNPUE13, 0x000D
        .equiv  CNPUE_CNPUE13_WIDTH, 0x0001
        .equiv  CNPUE_CNPUE13_MASK, 0x2000
        .equiv  CNPUE13, 0x000D

        .equiv  CNPUE_CNPUE14, 0x000E
        .equiv  CNPUE_CNPUE14_WIDTH, 0x0001
        .equiv  CNPUE_CNPUE14_MASK, 0x4000
        .equiv  CNPUE14, 0x000E

        .equiv  CNPUE_CNPUE15, 0x000F
        .equiv  CNPUE_CNPUE15_WIDTH, 0x0001
        .equiv  CNPUE_CNPUE15_MASK, 0x8000
        .equiv  CNPUE15, 0x000F

;----- CNPDE Bits -----------------------------------------------------
        .equiv  CNPDE_CNPDE12, 0x000C
        .equiv  CNPDE_CNPDE12_WIDTH, 0x0001
        .equiv  CNPDE_CNPDE12_MASK, 0x1000
        .equiv  CNPDE12, 0x000C

        .equiv  CNPDE_CNPDE13, 0x000D
        .equiv  CNPDE_CNPDE13_WIDTH, 0x0001
        .equiv  CNPDE_CNPDE13_MASK, 0x2000
        .equiv  CNPDE13, 0x000D

        .equiv  CNPDE_CNPDE14, 0x000E
        .equiv  CNPDE_CNPDE14_WIDTH, 0x0001
        .equiv  CNPDE_CNPDE14_MASK, 0x4000
        .equiv  CNPDE14, 0x000E

        .equiv  CNPDE_CNPDE15, 0x000F
        .equiv  CNPDE_CNPDE15_WIDTH, 0x0001
        .equiv  CNPDE_CNPDE15_MASK, 0x8000
        .equiv  CNPDE15, 0x000F

;----- ANSELE Bits -----------------------------------------------------
        .equiv  ANSELE_ANSE12, 0x000C
        .equiv  ANSELE_ANSE12_WIDTH, 0x0001
        .equiv  ANSELE_ANSE12_MASK, 0x1000
        .equiv  ANSE12, 0x000C

        .equiv  ANSELE_ANSE13, 0x000D
        .equiv  ANSELE_ANSE13_WIDTH, 0x0001
        .equiv  ANSELE_ANSE13_MASK, 0x2000
        .equiv  ANSE13, 0x000D

        .equiv  ANSELE_ANSE14, 0x000E
        .equiv  ANSELE_ANSE14_WIDTH, 0x0001
        .equiv  ANSELE_ANSE14_MASK, 0x4000
        .equiv  ANSE14, 0x000E

        .equiv  ANSELE_ANSE15, 0x000F
        .equiv  ANSELE_ANSE15_WIDTH, 0x0001
        .equiv  ANSELE_ANSE15_MASK, 0x8000
        .equiv  ANSE15, 0x000F

;----- TRISF Bits -----------------------------------------------------
        .equiv  TRISF_TRISF0, 0x0000
        .equiv  TRISF_TRISF0_WIDTH, 0x0001
        .equiv  TRISF_TRISF0_MASK, 0x0001
        .equiv  TRISF0, 0x0000

        .equiv  TRISF_TRISF1, 0x0001
        .equiv  TRISF_TRISF1_WIDTH, 0x0001
        .equiv  TRISF_TRISF1_MASK, 0x0002
        .equiv  TRISF1, 0x0001

;----- PORTF Bits -----------------------------------------------------
        .equiv  PORTF_RF0, 0x0000
        .equiv  PORTF_RF0_WIDTH, 0x0001
        .equiv  PORTF_RF0_MASK, 0x0001
        .equiv  RF0, 0x0000

        .equiv  PORTF_RF1, 0x0001
        .equiv  PORTF_RF1_WIDTH, 0x0001
        .equiv  PORTF_RF1_MASK, 0x0002
        .equiv  RF1, 0x0001

;----- LATF Bits -----------------------------------------------------
        .equiv  LATF_LATF0, 0x0000
        .equiv  LATF_LATF0_WIDTH, 0x0001
        .equiv  LATF_LATF0_MASK, 0x0001
        .equiv  LATF0, 0x0000

        .equiv  LATF_LATF1, 0x0001
        .equiv  LATF_LATF1_WIDTH, 0x0001
        .equiv  LATF_LATF1_MASK, 0x0002
        .equiv  LATF1, 0x0001

;----- ODCF Bits -----------------------------------------------------
        .equiv  ODCF_ODCF0, 0x0000
        .equiv  ODCF_ODCF0_WIDTH, 0x0001
        .equiv  ODCF_ODCF0_MASK, 0x0001
        .equiv  ODCF0, 0x0000

        .equiv  ODCF_ODCF1, 0x0001
        .equiv  ODCF_ODCF1_WIDTH, 0x0001
        .equiv  ODCF_ODCF1_MASK, 0x0002
        .equiv  ODCF1, 0x0001

;----- CNENF Bits -----------------------------------------------------
        .equiv  CNENF_CNIEF0, 0x0000
        .equiv  CNENF_CNIEF0_WIDTH, 0x0001
        .equiv  CNENF_CNIEF0_MASK, 0x0001
        .equiv  CNIEF0, 0x0000

        .equiv  CNENF_CNIEF1, 0x0001
        .equiv  CNENF_CNIEF1_WIDTH, 0x0001
        .equiv  CNENF_CNIEF1_MASK, 0x0002
        .equiv  CNIEF1, 0x0001

;----- CNPUF Bits -----------------------------------------------------
        .equiv  CNPUF_CNPUF0, 0x0000
        .equiv  CNPUF_CNPUF0_WIDTH, 0x0001
        .equiv  CNPUF_CNPUF0_MASK, 0x0001
        .equiv  CNPUF0, 0x0000

        .equiv  CNPUF_CNPUF1, 0x0001
        .equiv  CNPUF_CNPUF1_WIDTH, 0x0001
        .equiv  CNPUF_CNPUF1_MASK, 0x0002
        .equiv  CNPUF1, 0x0001

;----- CNPDF Bits -----------------------------------------------------
        .equiv  CNPDF_CNPDF0, 0x0000
        .equiv  CNPDF_CNPDF0_WIDTH, 0x0001
        .equiv  CNPDF_CNPDF0_MASK, 0x0001
        .equiv  CNPDF0, 0x0000

        .equiv  CNPDF_CNPDF1, 0x0001
        .equiv  CNPDF_CNPDF1_WIDTH, 0x0001
        .equiv  CNPDF_CNPDF1_MASK, 0x0002
        .equiv  CNPDF1, 0x0001

;----- TRISG Bits -----------------------------------------------------
        .equiv  TRISG_TRISG6, 0x0006
        .equiv  TRISG_TRISG6_WIDTH, 0x0001
        .equiv  TRISG_TRISG6_MASK, 0x0040
        .equiv  TRISG6, 0x0006

        .equiv  TRISG_TRISG7, 0x0007
        .equiv  TRISG_TRISG7_WIDTH, 0x0001
        .equiv  TRISG_TRISG7_MASK, 0x0080
        .equiv  TRISG7, 0x0007

        .equiv  TRISG_TRISG8, 0x0008
        .equiv  TRISG_TRISG8_WIDTH, 0x0001
        .equiv  TRISG_TRISG8_MASK, 0x0100
        .equiv  TRISG8, 0x0008

        .equiv  TRISG_TRISG9, 0x0009
        .equiv  TRISG_TRISG9_WIDTH, 0x0001
        .equiv  TRISG_TRISG9_MASK, 0x0200
        .equiv  TRISG9, 0x0009

;----- PORTG Bits -----------------------------------------------------
        .equiv  PORTG_RG6, 0x0006
        .equiv  PORTG_RG6_WIDTH, 0x0001
        .equiv  PORTG_RG6_MASK, 0x0040
        .equiv  RG6, 0x0006

        .equiv  PORTG_RG7, 0x0007
        .equiv  PORTG_RG7_WIDTH, 0x0001
        .equiv  PORTG_RG7_MASK, 0x0080
        .equiv  RG7, 0x0007

        .equiv  PORTG_RG8, 0x0008
        .equiv  PORTG_RG8_WIDTH, 0x0001
        .equiv  PORTG_RG8_MASK, 0x0100
        .equiv  RG8, 0x0008

        .equiv  PORTG_RG9, 0x0009
        .equiv  PORTG_RG9_WIDTH, 0x0001
        .equiv  PORTG_RG9_MASK, 0x0200
        .equiv  RG9, 0x0009

;----- LATG Bits -----------------------------------------------------
        .equiv  LATG_LATG6, 0x0006
        .equiv  LATG_LATG6_WIDTH, 0x0001
        .equiv  LATG_LATG6_MASK, 0x0040
        .equiv  LATG6, 0x0006

        .equiv  LATG_LATG7, 0x0007
        .equiv  LATG_LATG7_WIDTH, 0x0001
        .equiv  LATG_LATG7_MASK, 0x0080
        .equiv  LATG7, 0x0007

        .equiv  LATG_LATG8, 0x0008
        .equiv  LATG_LATG8_WIDTH, 0x0001
        .equiv  LATG_LATG8_MASK, 0x0100
        .equiv  LATG8, 0x0008

        .equiv  LATG_LATG9, 0x0009
        .equiv  LATG_LATG9_WIDTH, 0x0001
        .equiv  LATG_LATG9_MASK, 0x0200
        .equiv  LATG9, 0x0009

;----- ODCG Bits -----------------------------------------------------
        .equiv  ODCG_ODCG6, 0x0006
        .equiv  ODCG_ODCG6_WIDTH, 0x0001
        .equiv  ODCG_ODCG6_MASK, 0x0040
        .equiv  ODCG6, 0x0006

        .equiv  ODCG_ODCG7, 0x0007
        .equiv  ODCG_ODCG7_WIDTH, 0x0001
        .equiv  ODCG_ODCG7_MASK, 0x0080
        .equiv  ODCG7, 0x0007

        .equiv  ODCG_ODCG8, 0x0008
        .equiv  ODCG_ODCG8_WIDTH, 0x0001
        .equiv  ODCG_ODCG8_MASK, 0x0100
        .equiv  ODCG8, 0x0008

        .equiv  ODCG_ODCG9, 0x0009
        .equiv  ODCG_ODCG9_WIDTH, 0x0001
        .equiv  ODCG_ODCG9_MASK, 0x0200
        .equiv  ODCG9, 0x0009

;----- CNENG Bits -----------------------------------------------------
        .equiv  CNENG_CNIEG6, 0x0006
        .equiv  CNENG_CNIEG6_WIDTH, 0x0001
        .equiv  CNENG_CNIEG6_MASK, 0x0040
        .equiv  CNIEG6, 0x0006

        .equiv  CNENG_CNIEG7, 0x0007
        .equiv  CNENG_CNIEG7_WIDTH, 0x0001
        .equiv  CNENG_CNIEG7_MASK, 0x0080
        .equiv  CNIEG7, 0x0007

        .equiv  CNENG_CNIEG8, 0x0008
        .equiv  CNENG_CNIEG8_WIDTH, 0x0001
        .equiv  CNENG_CNIEG8_MASK, 0x0100
        .equiv  CNIEG8, 0x0008

        .equiv  CNENG_CNIEG9, 0x0009
        .equiv  CNENG_CNIEG9_WIDTH, 0x0001
        .equiv  CNENG_CNIEG9_MASK, 0x0200
        .equiv  CNIEG9, 0x0009

;----- CNPUG Bits -----------------------------------------------------
        .equiv  CNPUG_CNPUG6, 0x0006
        .equiv  CNPUG_CNPUG6_WIDTH, 0x0001
        .equiv  CNPUG_CNPUG6_MASK, 0x0040
        .equiv  CNPUG6, 0x0006

        .equiv  CNPUG_CNPUG7, 0x0007
        .equiv  CNPUG_CNPUG7_WIDTH, 0x0001
        .equiv  CNPUG_CNPUG7_MASK, 0x0080
        .equiv  CNPUG7, 0x0007

        .equiv  CNPUG_CNPUG8, 0x0008
        .equiv  CNPUG_CNPUG8_WIDTH, 0x0001
        .equiv  CNPUG_CNPUG8_MASK, 0x0100
        .equiv  CNPUG8, 0x0008

        .equiv  CNPUG_CNPUG9, 0x0009
        .equiv  CNPUG_CNPUG9_WIDTH, 0x0001
        .equiv  CNPUG_CNPUG9_MASK, 0x0200
        .equiv  CNPUG9, 0x0009

;----- CNPDG Bits -----------------------------------------------------
        .equiv  CNPDG_CNPDG6, 0x0006
        .equiv  CNPDG_CNPDG6_WIDTH, 0x0001
        .equiv  CNPDG_CNPDG6_MASK, 0x0040
        .equiv  CNPDG6, 0x0006

        .equiv  CNPDG_CNPDG7, 0x0007
        .equiv  CNPDG_CNPDG7_WIDTH, 0x0001
        .equiv  CNPDG_CNPDG7_MASK, 0x0080
        .equiv  CNPDG7, 0x0007

        .equiv  CNPDG_CNPDG8, 0x0008
        .equiv  CNPDG_CNPDG8_WIDTH, 0x0001
        .equiv  CNPDG_CNPDG8_MASK, 0x0100
        .equiv  CNPDG8, 0x0008

        .equiv  CNPDG_CNPDG9, 0x0009
        .equiv  CNPDG_CNPDG9_WIDTH, 0x0001
        .equiv  CNPDG_CNPDG9_MASK, 0x0200
        .equiv  CNPDG9, 0x0009

;----- APPS Bits -----------------------------------------------------
        .equiv  APPS_APIFUL, 0x0000
        .equiv  APPS_APIFUL_WIDTH, 0x0001
        .equiv  APPS_APIFUL_MASK, 0x0001
        .equiv  APIFUL, 0x0000

        .equiv  APPS_APIOV, 0x0001
        .equiv  APPS_APIOV_WIDTH, 0x0001
        .equiv  APPS_APIOV_MASK, 0x0002
        .equiv  APIOV, 0x0001

        .equiv  APPS_APOFUL, 0x0002
        .equiv  APPS_APOFUL_WIDTH, 0x0001
        .equiv  APPS_APOFUL_MASK, 0x0004
        .equiv  APOFUL, 0x0002

        .equiv  APPS_APOOV, 0x0003
        .equiv  APPS_APOOV_WIDTH, 0x0001
        .equiv  APPS_APOOV_MASK, 0x0008
        .equiv  APOOV, 0x0003

        .equiv  APPS_STRFUL, 0x0004
        .equiv  APPS_STRFUL_WIDTH, 0x0001
        .equiv  APPS_STRFUL_MASK, 0x0010
        .equiv  STRFUL, 0x0004



;  Some useful macros for PWRSAV instructions

   .equiv SLEEP_MODE, 0x0
   .equiv IDLE_MODE, 0x1


;==========================================================================
;
;   Configuration Words
;
;   Configuration words exist in Program Space and their locations are
;   defined in the device linker script. They can be set in source code
;   or in the MPLAB IDE. Each configuration word should be specified
;   only once (multiple settings may be combined.)
;
;==========================================================================
;
;  Setting configuration words using macros:
;
;  The following macro named 'config' can be used to set configuration words:
;==========================================================================
;  NOTICE: CONFIG MACRO IS ****D E P R E C A T E D****
;  Please use #pragma in a separate C file in the project.
;  Some features in linker and compiler cannot use values
;  set using this method. Please migrate to #pragma config method.
;==========================================================================
;
        .macro config REG, VALUE
        .pushsection \REG.sec, code
        .global \REG
        .warn "DEPRECATED. Please use #pragma config in a C file"
\REG:   .pword \VALUE
        .popsection
        .endm
;
;  For example, to set CONFIG_REG using the macro above, the following line
;  can be pasted only at the beginning of the assembly source code,
;  immediately below the '.include' directive.
;
;        config __CONFIG_REG, SETTING_A & SETTING_B
;
;  Note that the 'config' macro takes two arguments: the first is the name
;  of a configuration word (in this case, __CONFIG_REG), the second argument
;  is a boolean expression that may include multiple settings.
;  The example above would enable SETTING_A and also SETTING_B.
;
;  A description of all possible settings for each configuration word
;  appears below.
;
;==========================================================================
;
;  Setting configuration words without using macros:
;
;  To set configuration words without using the 'config' macro,
;  use the following format:
;
;           .section __CONFIG_REG.sec, code
;           .global __CONFIG_REG
;__CONFIG_REG: .pword SETTING_A & SETTING_B
;
;  This source code is equivalent to the expanded macro from the previous
;  example.
;
;==========================================================================


;----- FICD (0x157f0) --------------------------------------------------
;
;  The following settings are available for FICD:
;
;   ICD Communication Channel Select bits:
;     ICS_NONE             Reserved, do not use
;     ICS_PGD3             Communicate on PGEC3 and PGED3
;     ICS_PGD2             Communicate on PGEC2 and PGED2
;     ICS_PGD1             Communicate on PGEC1 and PGED1
;
;   JTAG Enable bit:
;     JTAGEN_OFF           JTAG is disabled
;     JTAGEN_ON            JTAG is enabled
;
        .equiv ICS_NONE,        0xFFFC ; Reserved, do not use
        .equiv ICS_PGD3,        0xFFFD ; Communicate on PGEC3 and PGED3
        .equiv ICS_PGD2,        0xFFFE ; Communicate on PGEC2 and PGED2
        .equiv ICS_PGD1,        0xFFFF ; Communicate on PGEC1 and PGED1

        .equiv JTAGEN_OFF,      0xFFDF ; JTAG is disabled
        .equiv JTAGEN_ON,       0xFFFF ; JTAG is enabled


;----- FPOR (0x157f2) --------------------------------------------------
;
;  The following settings are available for FPOR:
;
;   Alternate I2C1 pins:
;     ALTI2C1_ON           I2C1 mapped to ASDA1/ASCL1 pins
;     ALTI2C1_OFF          I2C1 mapped to SDA1/SCL1 pins
;
;   Alternate I2C2 pins:
;     ALTI2C2_ON           I2C2 mapped to ASDA2/ASCL2 pins
;     ALTI2C2_OFF          I2C2 mapped to SDA2/SCL2 pins
;
;   Watchdog Window Select bits:
;     WDTWIN_WIN75         WDT Window is 75% of WDT period
;     WDTWIN_WIN50         WDT Window is 50% of WDT period
;     WDTWIN_WIN37         WDT Window is 37.5% of WDT period
;     WDTWIN_WIN25         WDT Window is 25% of WDT period
;
        .equiv ALTI2C1_ON,      0xFFEF ; I2C1 mapped to ASDA1/ASCL1 pins
        .equiv ALTI2C1_OFF,     0xFFFF ; I2C1 mapped to SDA1/SCL1 pins

        .equiv ALTI2C2_ON,      0xFFDF ; I2C2 mapped to ASDA2/ASCL2 pins
        .equiv ALTI2C2_OFF,     0xFFFF ; I2C2 mapped to SDA2/SCL2 pins

        .equiv WDTWIN_WIN75,    0xFF3F ; WDT Window is 75% of WDT period
        .equiv WDTWIN_WIN50,    0xFF7F ; WDT Window is 50% of WDT period
        .equiv WDTWIN_WIN37,    0xFFBF ; WDT Window is 37.5% of WDT period
        .equiv WDTWIN_WIN25,    0xFFFF ; WDT Window is 25% of WDT period


;----- FWDT (0x157f4) --------------------------------------------------
;
;  The following settings are available for FWDT:
;
;   Watchdog Timer Postscaler bits:
;     WDTPOST_PS1          1:1
;     WDTPOST_PS2          1:2
;     WDTPOST_PS4          1:4
;     WDTPOST_PS8          1:8
;     WDTPOST_PS16         1:16
;     WDTPOST_PS32         1:32
;     WDTPOST_PS64         1:64
;     WDTPOST_PS128        1:128
;     WDTPOST_PS256        1:256
;     WDTPOST_PS512        1:512
;     WDTPOST_PS1024       1:1,024
;     WDTPOST_PS2048       1:2,048
;     WDTPOST_PS4096       1:4,096
;     WDTPOST_PS8192       1:8,192
;     WDTPOST_PS16384      1:16,384
;     WDTPOST_PS32768      1:32,768
;
;   Watchdog Timer Prescaler bit:
;     WDTPRE_PR32          1:32
;     WDTPRE_PR128         1:128
;
;   PLL Lock Enable bit:
;     PLLKEN_OFF           Clock switch will not wait for the PLL lock signal.
;     PLLKEN_ON            Clock switch to PLL source will wait until the PLL lock signal is valid.
;
;   Watchdog Timer Window Enable bit:
;     WINDIS_ON            Watchdog Timer in Window mode
;     WINDIS_OFF           Watchdog Timer in Non-Window mode
;
;   Watchdog Timer Enable bit:
;     FWDTEN_OFF           Watchdog timer enabled/disabled by user software
;     FWDTEN_ON            Watchdog timer always enabled
;
        .equiv WDTPOST_PS1,     0xFFF0 ; 1:1
        .equiv WDTPOST_PS2,     0xFFF1 ; 1:2
        .equiv WDTPOST_PS4,     0xFFF2 ; 1:4
        .equiv WDTPOST_PS8,     0xFFF3 ; 1:8
        .equiv WDTPOST_PS16,    0xFFF4 ; 1:16
        .equiv WDTPOST_PS32,    0xFFF5 ; 1:32
        .equiv WDTPOST_PS64,    0xFFF6 ; 1:64
        .equiv WDTPOST_PS128,   0xFFF7 ; 1:128
        .equiv WDTPOST_PS256,   0xFFF8 ; 1:256
        .equiv WDTPOST_PS512,   0xFFF9 ; 1:512
        .equiv WDTPOST_PS1024,  0xFFFA ; 1:1,024
        .equiv WDTPOST_PS2048,  0xFFFB ; 1:2,048
        .equiv WDTPOST_PS4096,  0xFFFC ; 1:4,096
        .equiv WDTPOST_PS8192,  0xFFFD ; 1:8,192
        .equiv WDTPOST_PS16384, 0xFFFE ; 1:16,384
        .equiv WDTPOST_PS32768, 0xFFFF ; 1:32,768

        .equiv WDTPRE_PR32,     0xFFEF ; 1:32
        .equiv WDTPRE_PR128,    0xFFFF ; 1:128

        .equiv PLLKEN_OFF,      0xFFDF ; Clock switch will not wait for the PLL lock signal.
        .equiv PLLKEN_ON,       0xFFFF ; Clock switch to PLL source will wait until the PLL lock signal is valid.

        .equiv WINDIS_ON,       0xFFBF ; Watchdog Timer in Window mode
        .equiv WINDIS_OFF,      0xFFFF ; Watchdog Timer in Non-Window mode

        .equiv FWDTEN_OFF,      0xFF7F ; Watchdog timer enabled/disabled by user software
        .equiv FWDTEN_ON,       0xFFFF ; Watchdog timer always enabled


;----- FOSC (0x157f6) --------------------------------------------------
;
;  The following settings are available for FOSC:
;
;   Primary Oscillator Mode Select bits:
;     POSCMD_EC            EC (External Clock) Mode
;     POSCMD_XT            XT Crystal Oscillator Mode
;     POSCMD_HS            HS Crystal Oscillator Mode
;     POSCMD_NONE          Primary Oscillator disabled
;
;   OSC2 Pin Function bit:
;     OSCIOFNC_ON          OSC2 is general purpose digital I/O pin
;     OSCIOFNC_OFF         OSC2 is clock output
;
;   Peripheral pin select configuration:
;     IOL1WAY_OFF          Allow multiple reconfigurations
;     IOL1WAY_ON           Allow only one reconfiguration
;
;   Clock Switching Mode bits:
;     FCKSM_CSECME         Both Clock switching and Fail-safe Clock Monitor are enabled
;     FCKSM_CSECMD         Clock switching is enabled,Fail-safe Clock Monitor is disabled
;     FCKSM_CSDCMD         Both Clock switching and Fail-safe Clock Monitor are disabled
;
        .equiv POSCMD_EC,       0xFFFC ; EC (External Clock) Mode
        .equiv POSCMD_XT,       0xFFFD ; XT Crystal Oscillator Mode
        .equiv POSCMD_HS,       0xFFFE ; HS Crystal Oscillator Mode
        .equiv POSCMD_NONE,     0xFFFF ; Primary Oscillator disabled

        .equiv OSCIOFNC_ON,     0xFFFB ; OSC2 is general purpose digital I/O pin
        .equiv OSCIOFNC_OFF,    0xFFFF ; OSC2 is clock output

        .equiv IOL1WAY_OFF,     0xFFDF ; Allow multiple reconfigurations
        .equiv IOL1WAY_ON,      0xFFFF ; Allow only one reconfiguration

        .equiv FCKSM_CSECME,    0xFF3F ; Both Clock switching and Fail-safe Clock Monitor are enabled
        .equiv FCKSM_CSECMD,    0xFF7F ; Clock switching is enabled,Fail-safe Clock Monitor is disabled
        .equiv FCKSM_CSDCMD,    0xFFBF ; Both Clock switching and Fail-safe Clock Monitor are disabled


;----- FOSCSEL (0x157f8) --------------------------------------------------
;
;  The following settings are available for FOSCSEL:
;
;   Oscillator Source Selection:
;     FNOSC_FRC            Internal Fast RC (FRC)
;     FNOSC_FRCPLL         Fast RC Oscillator with divide-by-N with PLL module (FRCPLL)
;     FNOSC_PRI            Primary Oscillator (XT, HS, EC)
;     FNOSC_PRIPLL         Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL)
;     FNOSC_LPRC           Low-Power RC Oscillator (LPRC)
;     FNOSC_FRCDIVN        Internal Fast RC (FRC) Oscillator with postscaler
;
;   PWM Lock Enable bit:
;     PWMLOCK_OFF          PWM registers may be written without key sequence
;     PWMLOCK_ON           Certain PWM registers may only be written after key sequence
;
;   Two-speed Oscillator Start-up Enable bit:
;     IESO_OFF             Start up with user-selected oscillator source
;     IESO_ON              Start up device with FRC, then switch to user-selected oscillator source
;
        .equiv FNOSC_FRC,       0xFFF8 ; Internal Fast RC (FRC)
        .equiv FNOSC_FRCPLL,    0xFFF9 ; Fast RC Oscillator with divide-by-N with PLL module (FRCPLL)
        .equiv FNOSC_PRI,       0xFFFA ; Primary Oscillator (XT, HS, EC)
        .equiv FNOSC_PRIPLL,    0xFFFB ; Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL)
        .equiv FNOSC_LPRC,      0xFFFD ; Low-Power RC Oscillator (LPRC)
        .equiv FNOSC_FRCDIVN,   0xFFFF ; Internal Fast RC (FRC) Oscillator with postscaler

        .equiv PWMLOCK_OFF,     0xFFBF ; PWM registers may be written without key sequence
        .equiv PWMLOCK_ON,      0xFFFF ; Certain PWM registers may only be written after key sequence

        .equiv IESO_OFF,        0xFF7F ; Start up with user-selected oscillator source
        .equiv IESO_ON,         0xFFFF ; Start up device with FRC, then switch to user-selected oscillator source


;----- FGS (0x157fa) --------------------------------------------------
;
;  The following settings are available for FGS:
;
;   General Segment Write-Protect bit:
;     GWRP_ON              General Segment is write protected
;     GWRP_OFF             General Segment may be written
;
;   General Segment Code-Protect bit:
;     GCP_ON               General Segment Code protection Enabled
;     GCP_OFF              General Segment Code protect is Disabled
;
        .equiv GWRP_ON,         0xFFFE ; General Segment is write protected
        .equiv GWRP_OFF,        0xFFFF ; General Segment may be written

        .equiv GCP_ON,          0xFFFD ; General Segment Code protection Enabled
        .equiv GCP_OFF,         0xFFFF ; General Segment Code protect is Disabled


;----- FUID0 (0x800ff8) --------------------------------------------------
;
;  The following settings are available for FUID0:
;
;   :
;


;----- FUID1 (0x800ffa) --------------------------------------------------
;
;  The following settings are available for FUID1:
;
;   :
;


;----- FUID2 (0x800ffc) --------------------------------------------------
;
;  The following settings are available for FUID2:
;
;   :
;


;----- FUID3 (0x800ffe) --------------------------------------------------
;
;  The following settings are available for FUID3:
;
;   :
;


;;
;; PPS Remapping Pin Names
;;

        .equiv  RPOUT_U1TX, 0x0001
        .equiv  RPOUT_U2TX, 0x0003
        .equiv  RPOUT_SDO2, 0x0008
        .equiv  RPOUT_SCK2OUT, 0x0009
        .equiv  RPOUT_SS2OUT, 0x000A
        .equiv  RPOUT_C1TX, 0x000E
        .equiv  RPOUT_OC1, 0x0010
        .equiv  RPOUT_OC2, 0x0011
        .equiv  RPOUT_OC3, 0x0012
        .equiv  RPOUT_OC4, 0x0013
        .equiv  RPOUT_C1OUT, 0x0018
        .equiv  RPOUT_C2OUT, 0x0019
        .equiv  RPOUT_C3OUT, 0x001A
        .equiv  RPOUT_PSYNCO1, 0x002D
        .equiv  RPOUT_QEI1CCMP, 0x002F
        .equiv  RPOUT_REFCLK, 0x0031
        .equiv  RPOUT_C4OUT, 0x0032

.LIST
.endif
