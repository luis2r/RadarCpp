#include<iostream>
#include "i7565H1H2.h"
#include <unistd.h>
#include <bitset>

using namespace std;

/*
unsigned char u_byte_t  BYTE;

unsigned int u_dword_t, DWORD;
 */
bitset<8> ToBits(unsigned char byte) {
    return bitset<8>(byte);
}

int main(void) {
    //char command;
    int wRetVal;
    WORD Ret;
    _VCI_CAN_PARAM vcparam;

    /*******************adicionado************************/
    vcparam.DevPort = USB0;
    vcparam.DevType = I7565H2;
    vcparam.CAN1_Baud = CANBaud_500K;
    vcparam.CAN2_Baud = CANBaud_500K;

    /****abrir puerto*/
    wRetVal = VCI_OpenCAN(&vcparam);
    /****************************************************/


    if (wRetVal > 0) {
        cout << "open " << vcparam.DevPort << " virtual COM port failed! Error : " << wRetVal << endl;
        return 0;
    }
    int cont = 0;
    int cont2 = 0;
    while (cont < 10) {
        /***************enviar mensaje***********************************/
        int port1, port2;
        _VCI_CAN_MSG CANTx;

        memset(&CANTx, 0, sizeof (CANTx));

        port1 = CAN1; //CAN1 = 1
        port2 = CAN2; //CAN2 = 2

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



        Ret = VCI_SendCANMsg(vcparam.DevPort, port1, &CANTx);
        if (Ret) {
            cout << "I-7565-H1/H2 Error : Error Code = " << Ret << endl;
        } else {
            cout << "Send CAN1 port Message(Mode " << CANTx.Mode << " ID(Hex) " << CANTx.ID << " RTR " << CANTx.RTR << " DLC " << CANTx.DLC << " D1 " << CANTx.Data[0] << " D2 " << CANTx.Data[1] << " D3 " << CANTx.Data[2] << " D4 " << CANTx.Data[3] << " D5 " << CANTx.Data[4] << " D6 " << CANTx.Data[5] << " D7 " << CANTx.Data[6] << " D8 " << CANTx.Data[7] << " ) OK" << endl;
            printf("Send CAN Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", CANTx.Mode, CANTx.ID, CANTx.RTR, CANTx.DLC, CANTx.Data[0], CANTx.Data[1], CANTx.Data[2], CANTx.Data[3], CANTx.Data[4], CANTx.Data[5], CANTx.Data[6], CANTx.Data[7]);
        }


        Ret = VCI_SendCANMsg(vcparam.DevPort, port1, &CANTx);
        if (Ret) {
            cout << "I-7565-H1/H2 Error : Error Code = " << Ret << endl;
        } else {
            //cout << "Send CAN1 port Message(Mode " << CANTx.Mode << " ID(Hex) " << CANTx.ID << " RTR " << CANTx.RTR << " DLC " << CANTx.DLC << " D1 " << CANTx.Data[0] << " D2 " << CANTx.Data[1] << " D3 " << CANTx.Data[2] << " D4 " << CANTx.Data[3] << " D5 " << CANTx.Data[4] << " D6 " << CANTx.Data[5] << " D7 " << CANTx.Data[6] << " D8 " << CANTx.Data[7] << " ) OK" << endl;
            printf("Send CAN Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", CANTx.Mode, CANTx.ID, CANTx.RTR, CANTx.DLC, CANTx.Data[0], CANTx.Data[1], CANTx.Data[2], CANTx.Data[3], CANTx.Data[4], CANTx.Data[5], CANTx.Data[6], CANTx.Data[7]);
        }
        cont++;
    }
    for (int i = 0; i < 500000000; i++) {
        cont2--;
    }
    cont = 0;

    while (cont < 5) {
        /*
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



                Ret = VCI_SendCANMsg(vcparam.DevPort, port1, &CANTx);
                if (Ret) {
                    cout << "I-7565-H1/H2 Error : Error Code = " << Ret << endl;
                } else {
                    //cout << "Send CAN1 port Message(Mode "<<CANTx.Mode<<" ID(Hex) "<<CANTx.ID<<" RTR "<<CANTx.RTR<<" DLC "<<CANTx.DLC<<" D1 "<<CANTx.Data[0]<<" D2 "<<CANTx.Data[1]<<" D3 "<<CANTx.Data[2]<<" D4 "<<CANTx.Data[3]<<" D5 "<<CANTx.Data[4]<<" D6 "<<CANTx.Data[5]<<" D7 "<<CANTx.Data[6]<<" D8 "<<CANTx.Data[7]<<" ) OK"<< endl;
                    printf("Send CAN Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", CANTx.Mode, CANTx.ID, CANTx.RTR, CANTx.DLC, CANTx.Data[0], CANTx.Data[1], CANTx.Data[2], CANTx.Data[3], CANTx.Data[4], CANTx.Data[5], CANTx.Data[6], CANTx.Data[7]);
                }
         */
        /***************recibir mensaje***********************************/
        /***************recibir mensaje***********************************/
        int port1, port2;
        _VCI_CAN_MSG CANRx;
        unsigned int rx_count = 0;
        int i = 0;
        memset(&CANRx, 0, sizeof (CANRx));
        if (vcparam.DevType == I7565H2) {
            //printf("CAN Port : Press CAN Port number(1~2):");

            //scanf("%d", &port2);
            port2 = CAN2;
            //getchar();

        } else {

        }

        Ret = VCI_Get_RxMsgCnt(vcparam.DevPort, port2, &rx_count);

        if (Ret) {
            printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
        } else {
            if (rx_count > 0) {
                for (i = 0; i < rx_count; i++) {
                    Ret = VCI_RecvCANMsg(vcparam.DevPort, port2, &CANRx);

                    if (Ret) {
                        printf("I-7565-H1/H2 Error : Error Code = %d\r\n", Ret);
                    } else {
                        printf("CAN %d Receive Message(Mode %d ID(Hex) %x RTR %d DLC %d D1 %x D2 %x D3 %x D4 %x D5 %x D6 %x D7 %x D8 %x) OK\r\n", port2, CANRx.Mode, CANRx.ID, CANRx.RTR, CANRx.DLC, CANRx.Data[0], CANRx.Data[1], CANRx.Data[2], CANRx.Data[3], CANRx.Data[4], CANRx.Data[5], CANRx.Data[6], CANRx.Data[7]);
                    }
                    unsigned char byte = CANRx.Data[6];

                    bitset<8> my_bset = ToBits(byte);

                    cout << my_bset[0];
                    cout << my_bset[1];
                    cout << my_bset[2];
                    cout << my_bset[3];
                    cout << my_bset[4];
                    cout << my_bset[5];
                    cout << my_bset[6];
                    cout << my_bset[7] << endl;

                    memset(&CANRx, 0, sizeof (CANRx));
                }
            } else {
                printf("CAN %d : No Data\n", port2);
            }
        }




        cont++;
    }
}