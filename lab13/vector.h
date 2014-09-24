#ifndef VECTOR_H
#define    VECTOR_H
#include<algorithm>
#include<iostream>
#include<stdexcept>
using std::transform;
using std::copy;
using std::fill;
using std::cout;
using std::endl;
using std::swap;

namespace student {

    template<typename ElementType>
    class vector {
    private:
        ElementType *data_;
        size_t capacity_;
        size_t size_;
    public:
        vector(size_t capacity = 10);
        ~vector();
        vector(const vector &v); // copy
        vector& operator=(vector);

        size_t capacity() const {
            return capacity_;
        }

        size_t size() const {
            return size_;
        }
        void push_back(ElementType);
        ElementType& operator[](size_t val);
        ElementType front();
        ElementType back();
        void clear();
        ElementType pop_back();


    };

    template <typename ElementType>
    vector<ElementType>::vector(size_t capacity) {
        size_ = 0;
        capacity_ = capacity;
        data_ = new ElementType[10];
    }

    template<typename ElementType>
    vector<ElementType>::~vector() {
        delete [] data_;
    }

    template<typename ElementType>
    void vector<ElementType>::push_back(ElementType e) {
        if ((capacity_ - size_) > 0) {
            data_[size_++] = e;
        } else {
            ElementType *new_data = new ElementType[capacity_ * 2];
            capacity_ *= 2;
            copy(data_, data_ + capacity_, new_data);
            swap(data_, new_data);
            data_[size_++] = e;
            delete [] new_data;
        }
    }
    template<typename ElementType>

    ElementType& vector<ElementType>::operator [](size_t val) {
        if (val < capacity_)
            return data_[val];
        else
            throw std::out_of_range("OUT OF RANGE, OUT OF YO MIND");
    }

    template<typename ElementType>
    ElementType vector<ElementType>::front() {
        if (size_ > 0)
            return data_[0];
        else
            throw std::out_of_range("NO FRONT TO SPEAK OF.")

    }

    template<typename ElementType>
    ElementType vector<ElementType>::back() {
        if (size_ > 0)
                return data_[size_ - 1];
        else
            throw std::out_of_range("NO BACK TO SPEAK OF.")
    }

    template<typename ElementType>
    vector<ElementType>::vector(const vector<ElementType> &v) {
        if (this != &v) {
            size_ = v.size_;
            capacity_ = v.capacity_;
            data_ = new ElementType[v.capacity_];
            copy(v.data_, v.data_ + v.capacity_, data_);
        }
    }

    template<typename ElementType>
    vector<ElementType>& vector<ElementType>::operator=(vector<ElementType> v) {
        swap(this->size_, v.size_);
        swap(this->capacity_, v.capacity_);
        swap(this->data_, v.data_);
        return *this;
    }

    template<typename ElementType>
    void vector<ElementType>::clear() {
        capacity_ = 10;
        size_ = 0;
        data_ = new ElementType[10];
    }

    template<typename ElementType>
    ElementType vector<ElementType>::pop_back() {
        ElementType out = data_[size_];
        if (size_ <= capacity_ / 2) {
            ElementType *new_data = new ElementType[capacity_ / 2];
            capacity_ /= 2;
            copy(data_, data_ + size_ - 1, new_data);
            swap(data_, new_data);
            size_--;
            delete [] new_data;

        }
        return out;
    }
}

#endif    /* VECTOR_H */

