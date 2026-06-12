#include<iostream>
#include<vector>


using namespace std;


class Product{

    public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }

};




class ShoppingCart{
     
    private:
    vector<Product *> products;

    public:

    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product *> getProducts(){
            return products;
    }

    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p->price;
        }

        return total;
    }

};

class ShoppingCartPrinter{
    private: 
    ShoppingCart *cart;

    public:
    
    ShoppingCartPrinter(ShoppingCart *cart){
        this->cart = cart;
    }

    void printInvoice(){

        vector<Product *> products = cart->getProducts();
        cout<<"Name\tPrice"<<endl;
        for(auto product: products){
            cout<<product->name<<" "<<product->price<<endl;
        }

        cout<<"Total Price: "<<cart->calculateTotal();
    }

};





int main()
{
    ShoppingCart *C1 = new ShoppingCart();

    C1->addProduct(new Product("Laptop", 10000));
    C1->addProduct(new Product("Bag", 2000));

    ShoppingCartPrinter *P1 = new ShoppingCartPrinter(C1);
    
    P1->printInvoice();
}