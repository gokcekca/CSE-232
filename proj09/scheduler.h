/////////////////////////////////////////////////////////////////
// Can Gokcek - Computer Project #9 - Round Robin Scheduler .h //
/////////////////////////////////////////////////////////////////
#include "job.h"
#ifndef SCHEDULER_H
#define	SCHEDULER_H

class Scheduler{
private:
    deque<Job> process_queue;
    deque<Job> arrival_queue;
    deque<Job> done_jobs;
public:
    void load_jobs(string);
    void round_robin();
    bool finished();
    void display();
};

#endif	/* SCHEDULER_H */

