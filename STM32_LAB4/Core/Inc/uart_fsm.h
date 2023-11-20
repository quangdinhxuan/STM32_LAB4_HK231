/*
 * uart_fsm.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Admin
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include"global.h"
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
#define MAX_BUFFER_SIZE  30
extern uint8_t temp;
extern uint8_t idx_buffer;
extern uint8_t cmd_flag;
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern char cmd_data[];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t buffer[MAX_BUFFER_SIZE];

#define INIT 0
#define READ 1


#define RST 2
#define OK 3

void command_parser_fsm();
void uart_communiation_fsm();
#endif /* INC_UART_FSM_H_ */
