#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "i7565H1H2.h"

#define kbhit()   (int)getchar()
char Kbhit(void);

char Kbhit(void) {
    int n = 0;

    ioctl(0, FIONREAD, &n);
    if (n) return kbhit();

    return n;
}

int main(void) {
    int usb, devtype, can1_baud = 0, can2_baud = 0, init = 0;
    char command;
    int i, wRetVal;
    DWORD RxMsgCnt = 0, j = 0;
    DWORD temp;
    WORD Ret;
    _VCI_CAN_PARAM vcparam;
    _VCI_MODULE_INFO vminfo;


    /*******************adicionado************************/
    vcparam.DevPort = USB0;
    vcparam.DevType = I7565H2;


    vcparam.CAN1_Baud = CANBaud_500K;
    vcparam.CAN2_Baud = CANBaud_500K;

    wRetVal = VCI_OpenCAN(&vcparam);
    /****************************************************/
 

    if (wRetVal > 0) {
        printf("open %d virtual COM port failed! Erro : %d\r\n", vcparam.DevPort, wRetVal);
        return 0;
    }

    /***************enviar mensaje***********************************/
    char option[2];
    int port, id, mode, rtr, len, data;
    _VCI_CAN_MSG CANTx;

    memset(&CANTx, 0, sizeof(CANTx));
        command = Kbhit();

        port = CAN1; //CAN1 = 1

        CANTx.Mode = 0;
        CANTx.ID = 0x4F1;
        CANTx.RTR = 0;
        CANTx.DLC = 8;
        CANTx.Data[0] = 0x00;
        CANTx.Data[1] = 0x00;
        CANTx.Data[2] = 0x00;
        CANTx.Data[3] = 0x00;
        CANTx.Data[4] = 0x00;
        CANTx.Data[5] = 0x00;
        CANTx.Data[6] = 0xBF;
        CANTx.Data[7] = 0x00;



        Ret = VCI_SendCANMsg(vcparam.DevPort, port, &CANTx);
        if (Ret) {
            printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
        } else {
            printf("Send CAN Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", CANTx.Mode, CANTx.ID, CANTx.RTR, CANTx.DLC, CANTx.Data[0], CANTx.Data[1], CANTx.Data[2], CANTx.Data[3], CANTx.Data[4], CANTx.Data[5], CANTx.Data[6], CANTx.Data[7]);
        }
        /***************enviar mensaje***********************************/
     
        
        /***************enviar Enable Hardware Cyclic Send CAN Message ***********************************/
        //char option[2];
        //int id, 
	//int mode, rtr, len, data, 
	int count, time;
        //_VCI_CAN_MSG CANTx;



        memset(&CANTx, 0, sizeof (CANTx));


//        if (vcparam.DevType == I7565H2) {
//            printf("CAN Port : Press CAN Port number(1~2):");
//            //port = CAN1 or CAN2
//            scanf("%d", &port);
//            getchar();
//        } else {
//            port = CAN1; //CAN1 = 1
//        }

        count = 10;
        time = 10;

        CANTx.Mode = 0;
        CANTx.ID = 0x4F1;
        CANTx.RTR = 0;
        CANTx.DLC = 8;
        CANTx.Data[0] = 0x00;
        CANTx.Data[1] = 0x00;
        CANTx.Data[2] = 0x00;
        CANTx.Data[3] = 0x00;
        CANTx.Data[4] = 0x00;
        CANTx.Data[5] = 0x00;
        CANTx.Data[6] = 0xBF;
        CANTx.Data[7] = 0x00;


        //Send 10 CANMsg and Stop from CAN1
        Ret = VCI_EnableHWCyclicTxMsg(vcparam.DevPort, port, &CANTx, time, count);

        if (Ret) {
            printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
        } else {
            printf("Send CAN Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", CANTx.Mode, CANTx.ID, CANTx.RTR, CANTx.DLC, CANTx.Data[0], CANTx.Data[1], CANTx.Data[2], CANTx.Data[3], CANTx.Data[4], CANTx.Data[5], CANTx.Data[6], CANTx.Data[7]);
        }
        /***************enviar Enable Hardware Cyclic Send CAN Message***********************************/        
        
    while (1) { 

        /***************recibir mensaje***********************************/
        _VCI_CAN_MSG CANRx;
        unsigned int rx_count = 0, i = 0;

        memset(&CANRx, 0, sizeof (CANRx));

        port = CAN1; //CAN1 = 1



        Ret = VCI_Get_RxMsgCnt(vcparam.DevPort, port, &rx_count);

        if (Ret) {
            printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
        } else {
            if (rx_count > 0) {
                for (i = 0; i < rx_count; i++) {
                    Ret = VCI_RecvCANMsg(vcparam.DevPort, port, &CANRx);

                    if (Ret) {
                        printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
                    } else {
                        printf("CAN %d Receive Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", port, CANRx.Mode, CANRx.ID, CANRx.RTR, CANRx.DLC, CANRx.Data[0], CANRx.Data[1], CANRx.Data[2], CANRx.Data[3], CANRx.Data[4], CANRx.Data[5], CANRx.Data[6], CANRx.Data[7]);
                    }

                    memset(&CANRx, 0, sizeof (CANRx));
                }
            } else {
                printf("CAN %d : No Data\n", port);
            }
        }
        /***************recibir mensaje***********************************/
    }
}

#ifdef __cplusplus
}
#endif


