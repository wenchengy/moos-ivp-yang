#include "MBUtils.h"
#include "ACTable.h"
#include "PrimeFactor.h"
#include "PrimeEntry.h"
#include <cstdint>
using namespace std;

//---------------------------------------------------------
// Constructor

PrimeEntry::PrimeEntry(){
	m_N = 0;
}


void   PrimeEntry::factor(unsigned long int max_steps){
  
  m_ii=0;

  if (m_N==0){ 
      m_N=m_orig;
      m_k=2;
      m_start_time=MOOSTime();
    }

  while (m_k<=ceil(sqrtl(m_N))){
       m_ii++; // Add iteration
       if (m_ii>max_steps){ //Reached max steps, stop factoring
	 break;
       }
       if (m_N%m_k==0){ //Divisible
	 m_factors.push_back(m_k);
	 m_N=m_N/m_k; // Update N_m
	 m_k=2; //Reset k.
       }
       m_k++;

  }

    if (m_k>=ceil(sqrtl(m_N))){ //Finished
    m_finished_iter=m_ii;
    m_finish_time=MOOSTime();

      if (m_N!=1){ //Add last (prime) number

	m_factors.push_back(m_N);
      }
    setDone(true);

  }
  else{
    setDone(false);
  }

}


std::string  PrimeEntry::getReport(){

  stringstream ss;
  ss << "orig ="<<m_orig<<", received="<<m_received_index<<", calculated="<<m_calculated_index<<", "<<"solve_time=";
  m_solve_time=m_finish_time-m_start_time; 
  ss<<m_solve_time<<", ";


  vector<unsigned long int>::iterator p;
  ss<<"primes=";
  sort(m_factors.begin(),m_factors.end()); 
  for(p=m_factors.begin();p!=m_factors.end();p++){
    ss<<*p<<":";
  }

  ss.seekp(-1, std::ios_base::end); //Delete last ":"

  ss<<", username=Eric Yang"<<std::endl;
  
  return ss.str();
}

