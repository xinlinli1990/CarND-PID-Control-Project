#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->total_cte = 0.0;
	this->prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
	this->total_cte += cte;

	this->p_error = this->Kp * cte;
	this->i_error = this->Ki * this->total_cte;
	this->d_error = this->Kd * (cte - this->prev_cte);

	this->prev_cte = cte;
}

double PID::TotalError() {
	cout << "TOTAL CTE" << total_cte 
		<< "TOTAL ERROR: " 
	     <<this->p_error + this->i_error + this->d_error << std::endl;
	return this->p_error + this->i_error + this->d_error;
}

