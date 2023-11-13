/*
 * global.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Admin
 */
#include"global.h"



int timer_counter[3]={0,0,0};
int timer_flag[3]={0,0,0};

void setTimer(int number, int duration){
	timer_counter[number]=duration/tick;
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
