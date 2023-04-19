#include "InternetStoreSystem.h"
#include "User.h"

int main() {
    InternetStoreSystem *internetStoreSystem = new InternetStoreSystem("Simple store");
    User *registeredUser = new User("Krystian123","12345");
    User *userToRegister = new User("Marcin33", "54321");
    cout << "Registering a user using internetStoreSystem.register() method, so that we can later check if the User can successfully log in:" <<endl;
    internetStoreSystem->registerUser(registeredUser);
    cout<<endl;
    cout<< "Checking, if a registered user can log into the system using user.login() method:"<<endl;
    registeredUser->login(internetStoreSystem);
    cout<<endl;
    cout<<"Using the same method for NOT REGISTERED USER using the user.login() method:"<<endl;
    userToRegister->login(internetStoreSystem);
    cout<<endl;
    cout << "Users that are registered:" <<endl;
    internetStoreSystem->getUsers();
    delete internetStoreSystem;
    return 0;
}
