#include <iterator>

template <typename T>
class Container {
private:
    // данные

private:   
    class Iterator: public std::iterator<std::random_access_iterator_tag, T> {
    protected:
        //Container& cont; // При необходимости итератор может хранить ссылку на контейнер
        //size_t index; // или индекс (указатель) на элемент, узел, и т.д.
    public:
        // ...
        Iterator (/*...*/);
        reference operator * () const;
        pointer operator -> () const;
        Iterator& operator ++ (); 
        Iterator operator ++ (int); 
        bool operator == (Iterator rhs) const;
        bool operator != (Iterator rhs) const;
    };

    friend class Iterator;

public:
    typedef Iterator iterator; // аналогично - для const_iterator и обратных итераторов
    typedef T value_type;
 
    Container(/*...*/);
    ~Container(/*...*/);

    bool empty() const;
    size_t size() const;
    void swap(Container& c);

    iterator begin() { return iterator(); } // + const-версия для const_iterator
    iterator end(); // + const-версия для const_iterator
    // + версии rbegin() и rend()

};