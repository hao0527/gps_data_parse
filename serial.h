#ifndef __SERIAL_H
#define __SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

void* serial_openSerial(void* lpFileName, unsigned int baudRate, unsigned int dwInQueue, unsigned int dwOutQueue);
int serial_readLen(void* hComm, unsigned char* pBuff, unsigned int len, unsigned int* pLenRead);
int serial_closeSerial(void* hComm);
int serial_purgeSerial(void* hComm);

#ifdef __cplusplus
}
#endif

#endif // !__SERIAL_H
