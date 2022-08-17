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
		printf("纬度:%.4f, 经度:%.4f, 水平精度:%.2f, 卫星数:%d, 日期:%d, 时间:%d, 状态:%d\n", \
			g_stMessageGGA.latitude, g_stMessageGGA.longitude, g_stMessageGGA.HDOP, \
			g_stMessageGGA.satellitesUsed, g_stMessageRMC.utcDate, g_stMessageRMC.utcTime, g_stMessageRMC.status);
	}
}
