/*
 * software_timer.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */


#include"software_timer.h"

int timer_counter[2]={0,0};
int timer_flag[2]={0,0};

void setTimer(int number, int duration){
	timer_counter[number]=duration;
	timer_flag[number]=0;
}
void timerRun(int number){
	if(timer_counter[number]>0)
	{
		timer_counter[number]--;
		if(timer_counter[number]<=0){
			timer_flag[number]=1;
		}
	}
}
