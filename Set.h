#pragma once
#include "vector.hpp"
#include "string.hpp"

class Set : public vector<String>{
public:
    ~Set(){
        delete[] _vector;
        _vector = nullptr;
    }
    Set(const Set& a){
        *this = a;
    }
    Set(){
        _vector = new String[2];
        _curr_len = 0;
        _len = 2;
    }
    explicit Set(String& elem){
        vector::push_back(elem);
    }
    Set(const char* elem){
        vector::push_back(String(elem));
    }

    void push_back (const char* a){
        String s(a);
        if(find(s) == -1) {
            Set::push_back(s);
            sort(true);
        }
    }
    void push_back (const String& a){
        if(find(a) == -1) {
            vector::push_back(a);
            sort(true);
        }
    }
    friend std::ostream& operator<<(std::ostream& out, Set& s){
        out << '[';
        for(int i = 0; i < s.len(); ++i){
            out << s[i];
            if(i+1 != s.len()){
                out << ',';
            }
        }
        out << ']';
        return out;
    }
    friend Set operator+(const Set& s1,const Set& s2){
        Set NewSet(s1);
        NewSet += s2;
        return NewSet;
    }
    friend Set operator-(const Set& s1,const Set& s2){
        Set NewSet(s1);
        NewSet -= s2;
        return NewSet;
    }
    friend Set operator*(const Set& s1,const Set& s2){
        Set NewSet(s1);
        NewSet *= s2;
        return NewSet;
    }

    bool operator==(Set& s){
        if(len() != s.len()){
            return false;
        }
        for(int i = 0; i < len(); ++i){
            if(_vector[i] != s[i]){
                return false;
            }
        }
        return true;
    }

    Set& operator=(const Set& arr){

        _curr_len = 0;
        delete[] _vector;
        _len = 2;
        _vector = new String[2];
        for(unsigned int i = 0; i < arr._curr_len; ++i){
            Set::push_back(arr._vector[i]);
        }
        return *this;
    }


    Set& operator+=(const Set& s){
        Set NewSet(*this);
        for(unsigned int i = 0; i < s.len(); ++i){
            NewSet.push_back(s[i]);
        }
        *this = NewSet;
        return *this;
    }
    Set& operator-=(const Set& s){
        Set NewSet;
        for(unsigned int i = 0; i < len(); ++i){
            if(find(s._vector[i]) == -1){
                NewSet.push_back(_vector[i]);
            }
        }
        *this = NewSet;
        return *this;
    }
    Set& operator*=(const Set& s){
        Set NewSet;
        for(unsigned int i = 0; i < s.len(); ++i){
            if(s.find(_vector[i]) != -1){
                NewSet.push_back(_vector[i]);
            }
        }
        *this = NewSet;
        return *this;
    }
//    String* _vector;
//    unsigned int _len;
//    unsigned int _curr_len;
//
//    void _vector_extend(){
//        if ((_curr_len + 1) * 2 < _len) {
//
//            String *extended_vector;
//            extended_vector = new String[_len / 2];
//            for (unsigned int i = 0; i < _curr_len; ++i) {
//                extended_vector[i] = _vector[i];
//            }
//            delete[] _vector;
//            _vector = extended_vector;
//            _len /= 2;
//            return;
//        } else if ((_curr_len + 1) < _len) {
//            return;
//        } else {
//            String *extended_vector;
//            extended_vector = new String[_len * 2];
//            for (unsigned int i = 0; i < _curr_len; ++i) {
//                extended_vector[i] = _vector[i];
//            }
//            delete[] _vector;
//            _vector = extended_vector;
//            _len *= 2;
//            return;
//        }
//
//    }
//
//public:
//    Set(){
//       _len = 0;
//       _curr_len = 0;
//       _vector = nullptr;
//    }
//    explicit Set(String& elem){
//        _curr_len = 0;
//        _len = 2;
//        _vector = new String[_len];
//        _vector[0] = elem;
//    }
//    ~Set(){
//        delete[] _vector;
//        _len = 0;
//        _curr_len = 0;
//    }
//    void push_back(String& element) {
//        _curr_len++;
//        _vector_extend();
//        _vector[_curr_len - 1] = element;
//    }
//
//    void pop(int index ) override {
//        for (int i = index - 1; i < _curr_len - 1; ++i) {
//            _vector[i] = _vector[i + 1];
//        }
//        --_curr_len;
//    }
//
//    unsigned int len() override {
//        return _curr_len;
//    }
//
//    String &operator[](int index) override {
//        if(index <= _curr_len){
//            return _vector[index];
//        } else{
//            return _vector[_curr_len];
//        }
//    }
//    Set& operator=(Set& a){
//        _curr_len = a._curr_len;
//        _len = a._len;
//        for(unsigned int i = 0; i <= _curr_len; ++i){
//            _vector[i] = a._vector[i];
//        }
//        return *this;
//    }
};
