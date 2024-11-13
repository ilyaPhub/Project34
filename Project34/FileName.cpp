#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;

public:
    Pet(const string& petName) : name(petName) {}
    virtual ~Pet() {}

    virtual void Sound() const = 0; 
    virtual void Show() const {
        cout << "Name: " << name << endl;
    }
    virtual void Type() const = 0;
};

class Dog : public Pet {
public:
    Dog(const string& dogName) : Pet(dogName) {}

    void Sound() const override {
        cout << name << " says: Woof!" << endl;
    }
    void Type() const override {
        cout << "Type: Dog" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const string& catName) : Pet(catName) {}

    void Sound() const override {
        cout << name << " says: Meow!" << endl;
    }
    void Type() const override {
        cout << "Type: Cat" << endl;
    }
};

class Parrot : public Pet {
public:
    Parrot(const string& parrotName) : Pet(parrotName) {}

    void Sound() const override {
        cout << name << " says: Squawk!" << endl;
    }
    void Type() const override {
        cout << "Type: Parrot" << endl;
    }
};

class Hamster : public Pet {
public:
    Hamster(const string& hamsterName) : Pet(hamsterName) {}

    void Sound() const override {
        cout << name << " says: Squeak!" << endl;
    }
    void Type() const override {
        cout << "Type: Hamster" << endl;
    }
};

int main() {
    const int SIZE = 4;
    Pet* pets[SIZE] = {
        new Dog("Buddy"),
        new Cat("Whiskers"),
        new Parrot("Polly"),
        new Hamster("Nibbles")
    };

    for (int i = 0; i < SIZE; ++i) {
        pets[i]->Show();
        pets[i]->Type();
        pets[i]->Sound();
        cout << "-----------------" << endl;
    }

    for (int i = 0; i < SIZE; ++i) {
        delete pets[i];
    }

    return 0;
}
