template <typename T>
class Stack
{
    public :

    void push (const T &val) {elems_.push(val);}
    void pop () {elems_.pop_back();}
    T top () const {return elems_[0];}
    bool empty () const {return elems_.empty();}

    private :

    std::vector<T> elems_;
};
