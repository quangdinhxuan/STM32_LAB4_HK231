/*
 * uart_fsm.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Admin
 */


#include"uart_fsm.h"



//cmd
int cmd_status = INIT;
uint8_t cmd_data_index = 0;
uint8_t cmd_flag = 0;
char cmd_data [MAX_BUFFER_SIZE]= "";


uint32_t ADC_value;
char str[100];
//uart

int uart_status = INIT;
uint8_t idx_buffer = 0;// i
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_flag = 0;
uint32_t ADC_value=0;
int check_RST(char str[]){
	int flag = 0;
	if (str[0] == 'R' && str[1] == 'S' && str[2] == 'T'){
		flag = 1;
	}
	else{
		flag = 0;
	}
	return flag;
}

int check_OK(char str[]){
	int flag = 0;
	if (str[0] == 'O' && str[1] == 'K'){
		flag = 1;
	}
	else{
		flag = 0;
	}
	return flag;
}
void  command_parser_fsm(){
	switch(cmd_status){
	case INIT:
		if(buffer[idx_buffer]=='!'){
			cmd_status=READ;
			idx_buffer++;
			cmd_flag = 0;
		}
		break;
	case READ:
		if (buffer[idx_buffer] != '!' && buffer[idx_buffer] != '#'){//read RST/OK
			cmd_data[cmd_data_index] = buffer[idx_buffer];
			cmd_data_index++;
		}
		if (buffer[idx_buffer] == '#') {
			cmd_data[cmd_data_index] = '\0';
			if(check_RST(cmd_data)==1){
				uart_status=RST;
				cmd_flag = 1;

			}
			else if(check_OK(cmd_data)==1) {
				uart_status=OK;
				cmd_flag = 1;

			}
			cmd_data_index=0;
			cmd_status = INIT;
		}
		idx_buffer++;
		if(idx_buffer==30) idx_buffer=0;
		break;
	default:
		break;
}
}
void uart_communiation_fsm (){

	switch(uart_status){
	case RST:
		if(check_RST(cmd_data)==1&&cmd_flag==1){
			HAL_UART_Transmit(&huart2, " \r\n",3, 1000);
			cmd_flag = 0;
		    uart_status=OK;
		    HAL_ADC_Start(&hadc1);
		    ADC_value = HAL_ADC_GetValue(&hadc1);
		    HAL_UART_Transmit(&huart2, (void *)str,sprintf(str, "!ADC=%d# \r\n",ADC_value), 1000);
		    setTimer(0,300);
		}
		break;
	case OK:
		if(check_OK(cmd_data)==1&&cmd_flag==1){
			cmd_flag = 0;
			HAL_UART_Transmit(&huart2, " \r\n",3, 1000);
			uart_status=RST;
			break;
		}
		else if(timer_flag[0]==1){
			HAL_ADC_Start(&hadc1);
			HAL_UART_Transmit(&huart2, (void *)str,sprintf(str, "!ADC=%d# \r\n",ADC_value), 1000);
			HAL_ADC_Stop(&hadc1);
			setTimer(0,300);
		}

		break;

	default:
		break;
	}
}

