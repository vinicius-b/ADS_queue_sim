/*
 * rand_exp.cpp
 *
 *  Created on: 20 de mar de 2017
 *      Author: vinicius
 */
#include "rand_exp.h"
#include <stdlib.h>

using namespace std;

rand_exp::rand_exp(){

}

double rand_exp::exp(int mean){
	int seed = rand() % 10;
	double exp;

	exp = (1-seed)/mean;
	return exp;

}


