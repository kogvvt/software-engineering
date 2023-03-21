#include <iostream>
#include <string>
#include "Cook.h"
#include "Food.h"
#include "InternetProvider.h"
#include "User.h"
int main() {
    Cook gordon;
    gordon.setName("gordon");
    Food salmon = gordon.createFood("salmon",1,111);
    InternetProvider ip;
    ip.setName("SomeProvider");
    User* user = new User;
    user->connectToTheInternet(ip);
    cout << "Cook named " <<gordon.getName() <<" cooked a " <<salmon.getName() << ", it has position " <<
    salmon.getID() << " on our menu and costs " << salmon.getPrice()<<" zlotych" <<endl;

    delete user;
    return 0;
}
