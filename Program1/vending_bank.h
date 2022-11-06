#ifndef VENDING_BANK_H
#define VENDING_BANK_H
#include <string>

class VendingBank{
    public:
        //constructors
        VendingBank();
        VendingBank(int id);
        

        //getters-setters
        int id() const;
        bool checkCoin() const;
        void insert();
        double changeBack();

        //other variables
        double totalAmount;
        double penny = 0.01 const;
        double nickel = 0.05 const;
        double dime = 0.1 const;
        double quarter = 0.25 const;
        double fifty = 0.5 const;
        double dollCoin = 1.0 const;

    private:
        int id_;
        int totalCoins;
        int pennyNumber();
        int nickelNumber();
        int dimeNumber();
        int quarterNumber();
        int fiftyNumber();
        int dollcoinNumber();
        void removePenny();
        void removeNickel();
        void removeDime();
        void removeQuarter();
        void removeFifty();
        void removeDollCoin();

       

};
#endif
