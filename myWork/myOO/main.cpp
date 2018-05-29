#include <iostream>

using namespace std;

/******************使用基类的构造函数**************/
class Base{
public:
    Base(int a): i(a){}
    int i;
};

class Derived: public Base{
public:
    Derived(int a, string s):Base(a), m(s){}

    using Base::Base;
    //Equivalent to:
    //Derived(int a):Base(a), m(){}

    string m;
};

/**main**/
#if false
    Derived d1(1);
    Derived d2(1, "1");
#endif
/*****************************************************/

class Quote{
public:
    Quote() = default;

    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price){}

    virtual double net_price(size_t n) const{
        return n*price;
    };
    string isbn() const{
        return bookNo;
    };

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote{
public:
    Bulk_quote() = default;
    //Bulk_quote(const string&, double, size_t, double);
    Bulk_quote(const string& book, double p, size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc){}

    double net_price(size_t cnt)const override{
        if(cnt >= min_qty){
            return cnt * (1 - discount) * price;
        }
        else{
            return cnt * price;y
        }
    }
    ~Bulk_quote() override = default;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " # sold: " << n
    << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote basic;
    Bulk_quote bulk;
    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);

    return 0;
}
