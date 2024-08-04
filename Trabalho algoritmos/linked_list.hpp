#ifndef _LINKED_LIST_IFRN_
#define _LINKED_LIST_IFRN_

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next;
        int_node* prev;
    };

    int_node* head;
    int_node* tail;
    unsigned int size_;

public:
    linked_list() : head(nullptr), tail(nullptr), size_(0) {}

    ~linked_list() {
        clear();
    }

    unsigned int size() const {
        return size_;
    }

    unsigned int capacity() const {
        return size_;
    }

    double percent_occupied() const {
        return size_ == 0 ? 0.0 : 1.0;
    }

    bool insert_at(unsigned int index, int value) {
        if (index > size_) return false;
        int_node* new_node = new int_node{value, nullptr, nullptr};
        if (index == 0) {
            new_node->next = head;
            if (head) head->prev = new_node;
            head = new_node;
            if (!tail) tail = new_node;
        } else {
            int_node* current = head;
            for (unsigned int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            if (current->next) current->next->prev = new_node;
            current->next = new_node;
            new_node->prev = current;
            if (new_node->next == nullptr) tail = new_node;
        }
        ++size_;
        return true;
    }

    bool remove_at(unsigned int index) {
        if (index >= size_) return false;
        int_node* to_remove = head;
        for (unsigned int i = 0; i < index; ++i) {
            to_remove = to_remove->next;
        }
        if (to_remove->prev) to_remove->prev->next = to_remove->next;
        if (to_remove->next) to_remove->next->prev = to_remove->prev;
        if (to_remove == head) head = to_remove->next;
        if (to_remove == tail) tail = to_remove->prev;
        delete to_remove;
        --size_;
        return true;
    }

    int get_at(unsigned int index) const {
        if (index >= size_) return -1;
        int_node* current = head;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    void clear() {
        while (head != nullptr) {
            int_node* to_remove = head;
            head = head->next;
            delete to_remove;
        }
        tail = nullptr;
        size_ = 0;
    }

    void push_back(int value) {
        int_node* new_node = new int_node{value, nullptr, tail};
        if (tail) tail->next = new_node;
        tail = new_node;
        if (!head) head = new_node;
        ++size_;
    }

    void push_front(int value) {
        int_node* new_node = new int_node{value, head, nullptr};
        if (head) head->prev = new_node;
        head = new_node;
        if (!tail) tail = new_node;
        ++size_;
    }

    bool pop_back() {
        if (tail == nullptr) return false;
        int_node* to_remove = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete to_remove;
        --size_;
        return true;
    }

    bool pop_front() {
        if (head == nullptr) return false;
        int_node* to_remove = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete to_remove;
        --size_;
        return true;
    }

    int front() const {
        return head ? head->value : -1;
    }

    int back() const {
        return tail ? tail->value : -1;
    }

    bool remove(int value) {
        int_node* current = head;
        while (current) {
            if (current->value == value) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                --size_;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int find(int value) const {
        int_node* current = head;
        int index = 0;
        while (current) {
            if (current->value == value) return index;
            current = current->next;
            ++index;
        }
        return -1;
    }

    int count(int value) const {
        int_node* current = head;
        int cnt = 0;
        while (current) {
            if (current->value == value) ++cnt;
            current = current->next;
        }
        return cnt;
    }

    int sum() const {
        int_node* current = head;
        int total = 0;
        while (current) {
            total += current->value;
            current = current->next;
        }
        return total;
    }
};

#endif // _LINKED_LIST_IFRN_
