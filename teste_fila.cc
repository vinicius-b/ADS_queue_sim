/*
 * fila.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: marcusbunn e vini.bandeira
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "task.h"
#include <queue>

#include "rand_exp.h"
#define HUGE_VAL 999999999
#define T_MAX 60000 // 60s
using namespace std;

enum estado{
	IDLE,
	BUSY
};

estado server_state = IDLE;
double sim_time = 0.0;
double waiting_time = 0.0;
double last_event_time = 0.0;
double next_departure = HUGE_VAL;
double mean_arrival = 2;
double mean_processing = 1;
double cumulated_queue_length = 0.0;
double busy_time_total = 0.0;
int queue_counter = 0;
queue<task> FILA;
rand_exp rng1;
rand_exp rng2;

void update_statistics(){
	double time_since_last_event = sim_time - last_event_time;
	cumulated_queue_length += FILA.size() * time_since_last_event;
	if (server_state == BUSY)
		busy_time_total += time_since_last_event;
}


int main()
{
	double next_arrival = rng1.exp(mean_arrival);
	while (sim_time < T_MAX)
	{
		if (next_arrival < next_departure)
		{
			sim_time = next_arrival;
			if (server_state == IDLE)
			{
				server_state = BUSY;
			next_departure = sim_time + rng2.exp(mean_processing);
			}
			else
			{
//				contador_tasks++;
//				task nova_tarefa(sim_time,contador_tasks);
				task nova_tarefa(sim_time);
				FILA.push(nova_tarefa);
			}
			next_arrival = sim_time + rng1.exp(mean_arrival);
		}
		else
		{
			sim_time = next_departure;
			update_statistics();
			if ( FILA.empty() )
			{
				server_state = IDLE;
				next_departure = HUGE_VAL;
			}
			else
			{
				task t = FILA.front();
				FILA.pop();
				next_departure = sim_time + exp (mean_processing);
				queue_counter++;
				waiting_time += sim_time - t.get_time();
			}
		}
		last_event_time = sim_time;
	}
}



