'use strict';

class User {
    constructor(name) {
        this._name = name;
    }

    say() {
        return 'My name is ' + this._name;
    }
}

var user = new User('Alice');
console.log(user.say());
