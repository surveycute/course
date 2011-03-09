#include <iterator>

template <typename T>
class Container {
private:
    // ������

private:   
    class Iterator: public std::iterator<std::random_access_iterator_tag, T> {
    protected:
        //Container& cont; // ��� ������������� �������� ����� ������� ������ �� ���������
        //size_t index; // ��� ������ (���������) �� �������, ����, � �.�.
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
    typedef Iterator iterator; // ���������� - ��� const_iterator � �������� ����������
    typedef T value_type;
 
    Container(/*...*/);
    ~Container(/*...*/);

    bool empty() const;
    size_t size() const;
    void swap(Container& c);

    iterator begin() { return iterator(); } // + const-������ ��� const_iterator
    iterator end(); // + const-������ ��� const_iterator
    // + ������ rbegin() � rend()

};