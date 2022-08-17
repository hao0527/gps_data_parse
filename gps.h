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
	float latitude;			// γ�� ddmm.mmmm
	float longitude;		// ���� dddmm.mmmm
	int8_t isNorth;			// 1:North, 0:South, -1:��Ч
	int8_t isEast;  		// 1:East, 0:West, -1:��Ч
	uint8_t positionFix;    // 0:δ��λ, 1:�ǲ�ֶ�λ, 2:��ֶ�λ, 3:��ЧPPS, 6:���ڹ���
	uint8_t satellitesUsed;	// ������(0~12)
	float HDOP;				// ˮƽ����
	float MSLAltitude;		// ��λ�߶�
	float geoidsSeparation;	// ����߶�
}MessageGGA_s;

typedef struct
{
	uint32_t utcTime;		// UTCʱ�� hhmmss
	uint32_t utcDate;		// UTC���� ddmmyy
	int8_t status;			// 1:������Ч, 0:������Ч, -1:�쳣
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
