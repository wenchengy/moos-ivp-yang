#include <iostream>
#include <string>
#include <list>
#include "PrimeEntry.h"

using namespace std;

//---------------------------------------------------------
// Procedure: factor()

void PrimeEntry::factor(unsigned long int max_steps){
 
    m_ii=0;

    if (m_N==0){ 
        m_N=m_orig;
        m_k=2;
        m_start_time=MOOSTime();
    }

    while (m_k<=ceil(sqrtl(m_N))){
        
        m_ii++;

        if (m_ii>max_steps){
            break;
            }

            while (m_N%m_k==0){ 
                m_factors.push_back(m_k);
	            m_N=m_N/m_k; 
            }
        m_k++;
    }

   if (m_k>=ceil(sqrtl(m_N))){ 
       m_finish_time=MOOSTime();

      if (m_N!=1){ 
      m_factors.push_back(m_N);
      }
    setDone(true);
  }
  else{
    setDone(false);
  }

}

//-----------------------------------------------------------------------
// Procedure: getReport()
string  PrimeEntry::getReport(){

    m_solve_time =  m_finish_time-m_start_time;

    stringstream ss;
        ss << "orig = "<<m_orig<<", received = "<<m_received_index<<", calculated = "<<m_calculated_index<<", solve_time = "<<m_solve_time;

vector<unsigned long int>::iterator p;
  ss<<", primes = ";
  sort(m_factors.begin(),m_factors.end()); 
  for(p=m_factors.begin();p!=m_factors.end();p++){
    ss<<*p<<":";
  }

  ss.seekp(-1, std::ios_base::end);

  ss <<", username=YANG"<<endl;
  return ss.str();
}

