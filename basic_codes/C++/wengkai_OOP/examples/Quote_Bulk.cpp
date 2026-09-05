#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Quote{

protected:
    double price;

private:
    string bookNo;

public:
    Quote(double price, string isbn):price(price),bookNo(isbn){}
    
    virtual int net_price(int n){
        double sum = n*price;
        cout << "The net price is " << n*price << endl;
        return sum;
    }

    virtual ~Quote(){}
};

class Quote_Bulk:public Quote{

    private:
        int max_qty;
        double dsc;

    public:
        Quote_Bulk(double price, string isbn,int num,double dsc):
        Quote(price,isbn),max_qty(num),dsc(dsc){}

        virtual int net_price(int n){
            double sum;
            sum = n > max_qty ? max_qty*(1-dsc)*price + (n-max_qty)*price 
            : n*(1-dsc)*price;
            cout << "The net price is " << sum << endl;
            return sum;
        }

        virtual ~Quote_Bulk(){}

};

void print_total(Quote* book,int n){
    cout << book->net_price(n) << endl;
}

int main(){

    Quote_Bulk book(20,"123",10,0.5);
    print_total(&book,15);

}