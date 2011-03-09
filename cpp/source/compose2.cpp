#include <deque>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

template <typename F, typename F1, typename F2> 
struct Composer2: public std::unary_function<
    typename F1::argument_type,
    typename F::result_type
> {
    F f;
    F1 f1;
    F2 f2;

    Composer2(F _f, F1 _f1, F2 _f2)
        : f(_f)
        , f1(_f1)
        , f2(_f2)
    {}

    result_type operator () (const argument_type& x) const {
        return f(f1(x), f2(x));
    }
};


template <typename F, typename F1, typename F2>
Composer2<F,F1,F2> compose2 (F f, F1 f1, F2 f2) {
    return Composer2<F,F1,F2>(f,f1,f2);
}

int main () {
    std::deque<int> d;
    d.push_back(1);
    d.push_back(12);
    d.push_back(3);
    d.push_back(15);
    d.push_back(42);

    std::vector<int> results;
    std::remove_copy_if(d.begin(), d.end(), std::back_inserter(results),
        compose2(std::logical_or<bool>(), 
         bind1st(std::greater<int>(), 10),
         bind2nd(std::greater<int>(), 20)
        )
    );

  for (std::vector<int>::iterator it = results.begin(); it != results.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

}


