/*
 * software_timer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


#include"global.h"

extern int timer_flag[3];
void setTimer(int count,int duration);
void timerRun(int count);
#endif /* INC_SOFTWARE_TIMER_H_ */
