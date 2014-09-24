#include "knapsack.h"
#include "package.h"


Knapsack::Knapsack(long max){
    weight_limit_ = max;
    capacity_ = 10;
    size_ = 0;
    data_ = new Package [10];
}

bool Knapsack::add(Package p) {
        if ( weight_limit_ - size_ - 1 <= 0) {
            return false;
        } 

        else if (capacity_ - size_ - 1 >= 0){
            data_[size_++] = p;
            return true;
        }
        else{
            Package *new_data = new Package [capacity_ * 2];
            capacity_ *= 2;
            copy(data_, data_ + size_ , new_data);
            swap(data_, new_data);
            data_[size_++] = p;
            delete [] new_data;
            return true;
        }
    }

bool Knapsack::empty(){
    cout << "size: "<<size_<<endl;
    if(size_ < 1){
        return true;
    }
    else{
        return false;
    }
}

long Knapsack::weight(){
    long sum = 0;
    for (long p = 0 ; p <= size_; p++){
        sum += data_[p].weight_;
    }
    return sum;
}

long Knapsack::priority(){
    long pri = 0;
    for (long p = 0 ; p <= size_; p++){
        pri += data_[p].priority_;
    }
    return pri;
}

ostream& operator<<(ostream &out, const Knapsack &k){
    out << "Weight Limit: "<< k.weight_limit_<<endl;
    out << "Size: "<<k.size_<<endl;
    out << "Capacity: "<<k.capacity_<<endl;

    for (long p = 0 ; p <= k.size_; p++){
        out << k.data_[p]<<endl;
    }

    out << endl;
  return out;
}

void solve_KS(vector<Package>& vp, Knapsack& k){
    sort(vp.begin(), vp.end(), package_compare);
    for (auto p : vp){
        if (p.weight_ + k.size_ <= k.weight_limit_){
            k.add(p);
        }
        else{
            break;
        }
    }
}
