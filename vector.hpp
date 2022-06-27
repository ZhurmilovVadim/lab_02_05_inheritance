//
// Created by vadim on 01.03.2022.
//

#ifndef Lab2_05_Inheritance_vector
#define Lab2_05_Inheritance_vector

template<class T>
class vector {
protected:
    T *_vector;
    unsigned int _len;
    unsigned int _curr_len;

    void _vector_extend() {
        if ((_curr_len + 1) * 2 < _len) {

            T *extended_vector;
            extended_vector = new T[_len / 2];
            for (unsigned int i = 0; i < _curr_len; ++i) {
                extended_vector[i] = _vector[i];
            }
            delete[] _vector;
            _vector = extended_vector;
            _len /= 2;
            return;
        } else if ((_curr_len + 1) < _len) {
            return;
        } else {
            T *extended_vector;
            extended_vector = new T[_len * 2];
            for (unsigned int i = 0; i < _curr_len; ++i) {
                extended_vector[i] = _vector[i];
            }
            delete[] _vector;
            _vector = extended_vector;
            _len *= 2;
            return;
        }

    }

public:
    vector() {
        _vector = new T[2];
        _len = 2;
        _curr_len = 0;
    }

    vector(T elem) {
        _vector = new T[2];
        _len = 2;
        _curr_len = 0;
        push_back(elem);
    }

//    ~vector() {
//        for (int i = 0; i < _curr_len; ++i){
//            delete [] _vector[i];
//        }
//        delete[] _vector;
//        _vector = nullptr;
//    }

    void push_back(T element) {
        _curr_len++;
        _vector_extend();
        _vector[_curr_len - 1] = element;
    }

    void pop(int index) {
        for (int i = index - 1; i < _curr_len - 1; ++i) {
            _vector[i] = _vector[i + 1];
        }
        --_curr_len;
    }

    unsigned int len() const {
        return _curr_len;
    }

    T &operator[](int index) {
        return _vector[index];
    }

    T operator[](int index) const{
        return _vector[index];
    }

    vector &operator=(vector &a) {
        _curr_len = a._curr_len;
        _len = a._len;
        for (unsigned int i = 0; i <= _curr_len; ++i) {
            _vector[i] = a[i];
        }
        return *this;
    }

    size_t find(T elem) const{
        for(unsigned int i = 0; i < len(); ++i){
            if(elem == _vector[i]){
                return i;
            }
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& out, vector& s){
        out << '{';
        for(int i = 0; i < s.len(); ++i){
            out << s[i];
            if(i+1 != s.len()){
                out << ',';
            }
        }
        out << '}';
        return out;
    }

    void sort(bool mode) {
    if(_curr_len == 1) {
        return;
    }
        int peres = 0;
        int per = -1;
        for (int i = 0; i < _curr_len - 1; i++) {
            if (per != peres) {
                per = peres;
                for (int n = 0; n < _curr_len - 1 - i; n++) {
                    if (_vector[n] < _vector[n + 1] && !mode || _vector[n] > _vector[n + 1] && mode) {
                        T a = _vector[n];
                        _vector[n] = _vector[n + 1];
                        _vector[n + 1] = a;
                        peres++;
                    }
                }
            }
        }
    }

};


#endif //Lab2_05_Inheritance_vector