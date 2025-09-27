#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
    private:
        string name;
        int price;
        int quantity;
    public: 
        Item(string name, int price, int quantity): name(name), price(price), quantity(quantity){}
        int totalCost() {
            return quantity * price;
        }

        bool operator== (const Item &item) {
            if(name == item.name && price == item.price && quantity == item.quantity){
                return true;
            }
            return false;
        }

        void display() {
            cout << "Item: " << name << ", Price: " << price << ", Quantity: " << quantity << ", Total: " << totalCost() << endl;
        }
};

class Inventory {
    private:
        static vector<Item> items;
    public:
        static Item createAndAddAItem(string name, int price, int quantity) {
            Item item = Item(name, price, quantity);
            items.push_back(item);
            return item;
        }

        static void removeItems (Item &item) {
            auto it = find(items.begin(), items.end(), item);
            if(it != items.end()){
                items.erase(it);
            }else{
                cout << "Item not Found" << endl;
            }
        }

        static void showInventoryValue() {
            int total = 0;
            for(int i = 0; i < items.size(); i++) {
                total += items[i].totalCost();
                items[i].display();
            }
            cout << "Total inventory value: " << total << endl;
        }
};

vector<Item> Inventory::items;