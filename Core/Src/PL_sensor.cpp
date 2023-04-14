/*
 * PL_sensor.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Ryu
 */
#include <main.h>
#include "adc.h"
#include "stdio.h"
#include "PL_sensor.h"

uint16_t g_ADCBuffer[5];
int AD_step=0;
uint16_t g_sensor_on[5];
uint16_t g_sensor_off[5];
uint16_t g_sensor_now[5];
uint16_t adc_value=0;

/*DMAがスタートしたら実行するコード*//*******************************************************************/
void pl_callback_getSensor(void) {
	int j;
	//HAL_GPIO_WritePin(ILED5_GPIO_Port,ILED5_Pin,GPIO_PIN_SET);
	HAL_ADC_Stop_DMA(&hadc1);
	switch(AD_step) {
	    case 0:
	    	g_sensor_off[0] = g_ADCBuffer[0];
	    	g_sensor_off[1] = g_ADCBuffer[1];
	    	g_sensor_off[2] = g_ADCBuffer[2];
	    	g_sensor_off[3] = g_ADCBuffer[3];
	    	g_sensor_off[4] = g_ADCBuffer[4];
		    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		    for(j = 0; j <= 500; j++) {
		    }
		    break;
		case 1:
			g_sensor_off[0] = g_ADCBuffer[0];
			g_sensor_off[1] = g_ADCBuffer[1];
			g_sensor_on[2] = g_ADCBuffer[2];
			g_sensor_off[3] = g_ADCBuffer[3];
			g_sensor_off[4] = g_ADCBuffer[4];
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
			for(j = 0; j <= 500; j++) {
			}
			break;
		case 2:
			g_sensor_on[0] = g_ADCBuffer[0];
			g_sensor_off[1] = g_ADCBuffer[1];
			g_sensor_off[2] = g_ADCBuffer[2];
			g_sensor_off[3] = g_ADCBuffer[3];
			g_sensor_on[4] = g_ADCBuffer[4];
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
			for(j = 0; j <= 500; j++) {
			}
			break;
		case 3:
			g_sensor_off[0] = g_ADCBuffer[0];
			g_sensor_on[1] = g_ADCBuffer[1];
			g_sensor_off[2] = g_ADCBuffer[2];
			g_sensor_off[3] = g_ADCBuffer[3];
			g_sensor_off[4] = g_ADCBuffer[4];
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
			for(j = 0; j <= 500; j++) {
			}
			break;
		case 4:
			g_sensor_off[0] = g_ADCBuffer[0];
			g_sensor_off[1] = g_ADCBuffer[1];
			g_sensor_off[2] = g_ADCBuffer[2];
			g_sensor_on[3] = g_ADCBuffer[3];
			g_sensor_off[4] = g_ADCBuffer[4];
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
			for(j = 0; j <= 500; j++) {
			}
			break;
	}


	AD_step++;

	if(AD_step!= 5) {
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)g_ADCBuffer,sizeof(g_ADCBuffer) / sizeof(uint16_t));
	} else{
		AD_step= 0;
	}
}
/*******************************************************************/
/*割り込み用動作関数(センサー取得)(interupt_calSensor)*//*******************************************************************/
/*センサーの情報を取得する割り込み関数．*//*******************************************************************/
void pl_interupt_getSensor(void){
	//HAL_GPIO_WritePin(ILED8_GPIO_Port,ILED8_Pin,GPIO_PIN_SET);
	    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)g_ADCBuffer,sizeof(g_ADCBuffer) / sizeof(uint16_t));
	    g_sensor_now[0]=g_sensor_on[0]-g_sensor_off[0];
		g_sensor_now[1]=g_sensor_on[1]-g_sensor_off[1];
		g_sensor_now[2]=g_sensor_on[2]-g_sensor_off[2];
		g_sensor_now[3]=g_sensor_on[3]-g_sensor_off[3];
		g_sensor_now[4]=g_sensor_on[4]-g_sensor_off[4];
}

void test_adc()
{
	//for(int i=0;i<5;i++)
	//{
		//HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
		//HAL_ADC_Start(&hadc1);
		//HAL_ADC_PollForConversion(&hadc1,1);
		//adc_value=HAL_ADC_GetValue(&hadc1);
		//g_sensor_now[0]=adc_value;
		//HAL_ADC_Stop(&hadc1);
		if(AD_step==0)
		{
			AD_step++;
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		}
		else
		{
			AD_step=0;
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
		    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		}
	//}
}
