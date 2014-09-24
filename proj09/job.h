///////////////////////////////////////////////////////////
//Can Gokcek - Computer Project #9 - Round Robin Job .h  //
///////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <iomanip>
#include <deque>
#include <algorithm>

using std::deque;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::stol;
using std::vector;
using std::string;
using std::sort;

#ifndef JOB_H
#define JOB_H

class Job{
 private:
  int jobid_;
  int arrival_time_;
  int service_time_;
  int finish_time_;
  int time_left_;

 public:
  Job() : jobid_(0), arrival_time_(0), service_time_(0){};
  Job(int j, int a, int s) : jobid_(j), arrival_time_(a), service_time_(s), time_left_(s){};

  int get_job_id() const {return jobid_;}
  int get_arrival_time() const {return arrival_time_;}
  int get_time_left() const {return time_left_;}
  int get_finish_time() {return finish_time_;}
  void set_finish_time(int f_time){finish_time_ = f_time;}
  void update_time_left(int); 
};



#endif  /* JOB_H */

