/*
 * task.h
 *
 *  Created on: Mar 14, 2017
 *      Author: marcusbunn
 */

#ifndef TASK_H_
#define TASK_H_

#include <stdio.h>

class task{

public:
	task(double Time) : tempo(Time){}

//	task(double Time , int PID) : tempo(Time), processo(PID){}

	double get_time()
	{
		return task::tempo;
	}

//	int get_pid()
//	{
//		return task::processo;
//	}

private:
	double tempo;
//	int processo;

};



#endif /* TASK_H_ */
