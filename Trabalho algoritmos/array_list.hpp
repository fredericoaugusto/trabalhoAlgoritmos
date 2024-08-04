#ifndef _ARRAY_LIST_IFRN_
#define _ARRAY_LIST_IFRN_

class array_list {
private:
    int* data;
    unsigned int size_, capacity_;

    void increase_capacity() {
        int new_capacity;
        if (capacity_ < 100) {
            new_capacity = capacity_ + 100;
        } else if (capacity_ < 1000) {
            new_capacity = capacity_ + 1000;
        } else {
            new_capacity = capacity_ * 2;
        }
        int* new_data = new int[new_capacity];
        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    array_list() {
        data = new int[8];
        size_ = 0;
        capacity_ = 8;
    }

    ~array_list() {
        delete[] data;
    }

    unsigned int size() const {
        return size_;
    }

    unsigned int capacity() const {
        return capacity_;
    }

    double percent_occupied() const {
        return static_cast<double>(size_) / capacity_;
    }

    bool insert_at(unsigned int index, int value) {
        if (index > size_) return false;
        if (size_ == capacity_) increase_capacity();
        for (unsigned int i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
        return true;
    }

    bool remove_at(unsigned int index) {
        if (index >= size_) return false;
        for (unsigned int i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
        return true;
    }

    int get_at(unsigned int index) const {
        if (index >= size_) return -1;
        return data[index];
    }

    void clear() {
        size_ = 0;
    }

    void push_back(int value) {
        if (size_ == capacity_) increase_capacity();
        data[size_++] = value;
    }

    void push_front(int value) {
        insert_at(0, value);
    }

    bool pop_back() {
        if (size_ == 0) return false;
        --size_;
        return true;
    }

    bool pop_front() {
        return remove_at(0);
    }

    int front() const {
        return size_ == 0 ? -1 : data[0];
    }

    int back() const {
        return size_ == 0 ? -1 : data[size_ - 1];
    }

    bool remove(int value) {
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                remove_at(i);
                return true;
            }
        }
        return false;
    }

    int find(int value) const {
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    int count(int value) const {
        int cnt = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) ++cnt;
        }
        return cnt;
    }

    int sum() const {
        int total = 0;
        for (unsigned int i = 0; i < size_; ++i) {
            total += data[i];
        }
        return total;
    }
};

#endif // _ARRAY_LIST_IFRN_
