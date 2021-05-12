#include "MBUtils.h"
#include "ACTable.h"
#include "PrimeFactor.h"
#include "PrimeEntry.h"
#include <cstdint>
using namespace std;

PrimeEntry::PrimeEntry(){
	int i=0;
	m_done = true;
	interrupt = false;
	backup_NUM = 0;
  	m_start_time = 0;
  	m_end_time = 0;
  	m_received_index = 0;
  	m_calculated_index = 0;
	int m_iter = 0;
}

void::PrimeEntry::factor(unsigned long int max_steps){

	if (m_done == false){   
        	interrupt = true;
        	backup_prime =  current_prime;
        	backup_NUM = m_orig;
	}

	if(interrupt){
		current_prime = backup_prime;
		m_orig = backup_NUM;
		interrupt = false;
	}
	
	for(i=2;i<1000000000;){
		
		if(m_orig%i==0){
			current_prime.push_back(i);
			m_orig = m_orig/i;
			}
		else if(i>sqrt(m_orig)){
			if(m_orig!=1){
				current_prime.push_back(m_orig);
				m_done = true;
				break;
			}
		}
		else{
			i++;
			if(m_iter>max_steps){
				m_done = false;
				break;
			}
		}
		}
}
	

double PrimeEntry::getElapsedTime(){
	return(m_end_time-m_start_time);
	}


string PrimeEntry::getReport(){
	return("orig="+to_string(m_orig)+",received="+to_string(m_received_index)+",calculated="+to_string(m_calculated_index));
	}
