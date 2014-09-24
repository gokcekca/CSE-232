
#include "package.h"
#include "knapsack.h"


Package::Package(long weight, long priority){

    weight_ = weight;
    priority_ = priority;

}

bool package_compare(const Package& lhs, const Package& rhs){
    long ratio1 = lhs.priority_ / lhs.weight_;
    long ratio2 = rhs.priority_ / rhs.weight_;

    if (ratio1 > ratio2)
        return true;
    else
        return false;
}
ostream& operator<<(ostream &out, const Package &p){
    out << "Package = "<< "Weight: " << p.weight_ << "  "<< "Priority: "<<p.priority_;
}