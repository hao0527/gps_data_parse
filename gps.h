#ifndef __GPS_H
#define __GPS_H

typedef signed char			int8_t;
typedef short int			int16_t;
typedef int					int32_t;
typedef unsigned char		uint8_t;
typedef unsigned short int	uint16_t;
typedef unsigned int		uint32_t;

#define GPS_DATA_LENGTH 1000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	float latitude;			// 纬度 ddmm.mmmm
	float longitude;		// 经度 dddmm.mmmm
	int8_t isNorth;			// 1:North, 0:South, -1:无效
	int8_t isEast;  		// 1:East, 0:West, -1:无效
	uint8_t positionFix;    // 0:未定位, 1:非差分定位, 2:差分定位, 3:无效PPS, 6:正在估算
	uint8_t satellitesUsed;	// 卫星数(0~12)
	float HDOP;				// 水平精度
	float MSLAltitude;		// 定位高度
	float geoidsSeparation;	// 地面高度
}MessageGGA_s;

typedef struct
{
	uint32_t utcTime;		// UTC时间 hhmmss
	uint32_t utcDate;		// UTC日期 ddmmyy
	int8_t status;			// 1:数据有效, 0:数据无效, -1:异常
}MessageRMC_s;

extern MessageGGA_s g_stMessageGGA;
extern MessageRMC_s g_stMessageRMC;
extern uint32_t g_utcTime;

uint8_t gps_receiveData(uint8_t *pData, uint16_t size);
uint16_t gps_getDataSize(uint8_t *pData);
uint8_t gps_parseGGA(uint8_t *pData);
uint8_t gps_parseRMC(uint8_t *pData);
uint32_t gps_addSecondUtcTime(uint32_t now);

#ifdef __cplusplus
}
#endif

#endif
