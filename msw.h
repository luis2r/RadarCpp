/**********************************************************************
 *
 *  msw.h
 *
 *  Header for msw.c
 *
 *
 **********************************************************************/
/* *INDENT-OFF* */
#ifndef _MSW_H
#define _MSW_H

//#include "i7k.h"
#include "common.h"

#define DEFAULT_READ_BUF_SIZE 250

#define MAX_CMD_SIZE  250
#define MAX_COM_PORTS 256
#define USB0          0
#define USB1          1
#define USB2          2
#define USB3          3
#define USB4          4
#define USB5          5
#define USB6          6
#define USB7          7
#define USB8          8
#define USB9          9
#define USB10         10

#endif

#define EXPORTS
#define CALLBACK
#define WINAPI
#define FAR
#define NEAR

#define Data5Bit	5
#define Data6Bit	6
#define Data7Bit	7
#define Data8Bit	8

#define NonParity	0
#define OddParity	1
#define EvenParity	2

#define OneStopBit	0
#define One5StopBit	1
#define TwoStopBit	2


typedef __bool_t BOOL;

typedef u_byte_t BYTE;
typedef u_word_t WORD;
typedef u_dword_t DWORD;

typedef unsigned char UCHAR;

extern int _fd[];

extern EXPORTS WORD CALLBACK Receive_Cmd(char cPort, char szResult[],
										 WORD wTimeOut, WORD wChksum);

/* Macros to warp MS-Windows functions
#define Sleep(a)
 */
/* Macros to warp Turbo C functions 
#define getch()   (int)getchar()
#define getche()  (int)getchar()
#define kbhit()   (int)getchar()
*/
/* Macros to warp DOS functions 
#define RECEIVE_CMD(a, b, c, d) (int)Receive_Cmd((char)(a), (b), (long)(c), (int)(d))
#define SEND_CMD(a,b,c,d) (int)Send_Cmd((char)(a), (b), (WORD)(d))
#define OPEN_COM(p,b)     (int)Open_Com((char)(p), (DWORD)(b), Data8Bit, NonParity, OneStopBit)
#define CLOSE_COM(p)      (int)Close_Com((char)(p))
*/

/*
WORD Send_Receive_Cmd(char cPort, char szCmd[], char szResult[], WORD wTimeOut, WORD wChksum, WORD * wT);
//WORD Receive_Cmd(char cPort, char szResult[], WORD wTimeOut, WORD wChksum);
WORD Receive_Binary(char cPort, char szResult[], WORD wTimeOut, DWORD wLen, WORD *wT);
WORD Send_Cmd(char cPort, char szCmd[], WORD wChksum);
WORD Send_Binary(char cPort, char szCmd[],int iLen);
extern BOOL Close_Com(char port);
extern WORD Open_Com(char port, DWORD baudrate, char cData, char cParity, char cStop);


WORD SetLineStatus(BYTE cPort, BYTE DTR_Trig, BYTE RTS_Trig);
WORD FW_C2U_SendTrig(BYTE cPort, BYTE Trig);
WORD SetLineStatus(BYTE cPort, BYTE DTR_Trig, BYTE RTS_Trig);

#include "i7000.h"
*/

						/* _MSW_H */
