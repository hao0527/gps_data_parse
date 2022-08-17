#include <stdio.h>
#include <Windows.h>
#include "gps.h"
#include "serial.h"

uint8_t aGpsData[GPS_DATA_LENGTH];
void* hComm = NULL;

int main()
{
	hComm = serial_openSerial("COM4", 115200, GPS_DATA_LENGTH, 0);
	if (hComm == -1)
		printf("openSerial error");

	while (1)
	{
		gps_receiveData(aGpsData, GPS_DATA_LENGTH);
			gps_parseRMC(aGpsData);
		gps_parseGGA(aGpsData);
		//printf("%d\t", g_stMessageRMC.utcTime);
		printf("γ��:%.4f, ����:%.4f, ˮƽ����:%.2f, ������:%d, ����:%d, ʱ��:%d, ״̬:%d\n", \
			g_stMessageGGA.latitude, g_stMessageGGA.longitude, g_stMessageGGA.HDOP, \
			g_stMessageGGA.satellitesUsed, g_stMessageRMC.utcDate, g_stMessageRMC.utcTime, g_stMessageRMC.status);
	}
}
