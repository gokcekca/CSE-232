/* 
 * File:   rand_walk.h
 * Author: cangokcek
 *
 * Created on February 24, 2014, 10:55 AM
 */

#ifndef RAND_WALK_H
#define	RAND_WALK_H

 void read_index(map<long, string> & , string &);

 void read_arc(map<long, vector<long>> &, string &);

 long select(default_random_engine &, vector<long> &);

 map<string, long> do_walk(map<long, vector<long>> & , map<long, string> &, long ,long, default_random_engine &);




#endif	/* RAND_WALK_H */

