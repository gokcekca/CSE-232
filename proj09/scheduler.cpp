/////////////////////////////////////////////////////////////////
//Can Gokcek - Computer Project #9 - Round Robin Scheduler .cpp//
/////////////////////////////////////////////////////////////////
#include "scheduler.h"
void Scheduler::load_jobs(string s){
    ifstream in_file(s);        //Initialze file stream;
    int a, b, c;                //Initialze empty vars.
    string l;
    while(getline(in_file,l)){    //Get each line,
        stringstream sst(l);      //Convert to stringstream.
        sst >> a >> b >> c;       //Get data from stream into stringstream.
      arrival_queue.push_back(Job(a,b,c));    //Push onto queue.
    }

    sort(arrival_queue.begin(),arrival_queue.end(),    //Sort the jobs by arrival time.
     [](const Job& job1, const Job& job2)
       {return job1.get_arrival_time() < job2.get_arrival_time(); });

}

void Scheduler::round_robin(){
    long time_clock = 0;    //Initialize time clock.

    while(finished() == false){    //While not done,
        for (auto j : arrival_queue){    //Iterate through arrival queue.
            if (j.get_arrival_time() <= time_clock){    //If arrival time is now or before,
                process_queue.push_back(j);            //Push onto process queue,
                arrival_queue.pop_front();             //and remove from arrival queue.
            }
        }
            for (auto k : process_queue){            //Iterate through process queue.

                if (k.get_arrival_time() < time_clock){    //If arrival time is less than current time,
                    k.update_time_left(1);                 //"Process" the process by decreasing time left.
                    time_clock++;                          //Update time clock.

                    if (k.get_time_left() == 0){           //If process is done,
                        k.set_finish_time(time_clock);     //Set its finish time,
                        done_jobs.push_back(k);            //Push it onto done job deque,
                        process_queue.pop_front();         //and remove it from arrival queue.
                        break;                             //Break out of process loop.
                    }
                    else{                                  //If process isn't done,
                        process_queue.push_back(k);        //Put it on the end of process queue,
                        process_queue.pop_front();         //and remove it from the front.
                        break;                             //Break out of the process loop.
                    }
                
                }
                else{                                //If earliest job can't be done yet,
                    time_clock++;                    //update the time clock,
                    break;                           //and break out of the process queue.
                }
            }
        if (process_queue.empty() == true){          //If nothing is in process queue,
            time_clock++;                            //update the time clock.
        }
    }
}

bool Scheduler::finished(){
    if (process_queue.empty() == true && arrival_queue.empty() == true){        //If both deques are empty,
        return true;                                                            //Finished!
    }
    else{
        return false;
    }
}

void Scheduler::display(){
    double average = 0;            //Initialize empty vars.
    double count = 0;
    cout << "--------------------------------------------------"<<endl;    
    for (auto j : done_jobs){      //Iterate through deque of done jobs.
        cout << "Job ID:     Arrival Time:     Finish Time:"<<endl;
        cout <<j.get_job_id()<<"            "<<j.get_arrival_time()<<"                  "<<j.get_finish_time()<<endl;
        average+=(j.get_finish_time()-j.get_arrival_time());    //Add to average sum.
        count++;                                                //Increase count for taking average.
    }
    average /=count;                //Take average.
    cout << "THE AVERAGE TIME WAS: "<<average<<endl;
    cout << "--------------------------------------------------"<<endl;    
}
