#include <Windows.h>
#include "serial.h"

void* serial_openSerial(void* lpFileName, unsigned int baudRate, unsigned int dwInQueue, unsigned int dwOutQueue) {
	HANDLE hComm = NULL;
	DCB dcb;
	COMMTIMEOUTS commTimeOuts;
	hComm = CreateFile(lpFileName,       //串口名称
						GENERIC_READ | GENERIC_WRITE, //允许读和写
						0,             //独占方式
						NULL,          // 无安全属性，不可被子程序继承
						OPEN_EXISTING, //创建文件的性质，打开而不是创建
						0,             // Non Overlapped I/O
						NULL);         // Null for Comm Devices
	DWORD erM = GetLastError();
	SetupComm(hComm, dwInQueue, dwOutQueue);
	GetCommState(hComm, &dcb);
	dcb.BaudRate = baudRate;
	SetCommState(hComm, &dcb);
	commTimeOuts.ReadIntervalTimeout = 0;
	commTimeOuts.ReadTotalTimeoutMultiplier = 0;
	commTimeOuts.ReadTotalTimeoutConstant = 10;
	commTimeOuts.WriteTotalTimeoutMultiplier = 0;
	commTimeOuts.WriteTotalTimeoutConstant = 0;
	SetCommTimeouts(hComm, &commTimeOuts);
	return hComm;
}

int serial_readLen(void* hComm, unsigned char* pBuff, unsigned int len, unsigned int* pLenRead) {
	return ReadFile(hComm, pBuff, len, pLenRead, NULL);
}

int serial_closeSerial(void* hComm) {
	return CloseHandle(hComm);
}

int serial_purgeSerial(void* hComm) {
	return PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR);
}