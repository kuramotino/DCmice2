/*
 * spi_com.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Ryu
 */

#ifndef INC_SPI_COM_H_
#define INC_SPI_COM_H_

typedef struct
{
	float gyro_x;
	float gyro_y;
	float gyro_z;
	float accel_x;
	float accel_y;
	float accel_z;
}ICM_DATA;

extern ICM_DATA icm_data;

extern uint8_t WhoAmI;
uint8_t read_spi(uint8_t reg);
void write_spi(uint8_t reg, uint8_t data);
void gyro_init(void);
float gyro_get(uint8_t H_reg);
float accel_get(uint8_t H_reg);
void Update_ICM(void);
void Show_ICM(void);

#endif /* INC_SPI_COM_H_ */
