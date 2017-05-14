"use strict";

var add = function add(a, b) {
    return a + b;
};

var add2 = function add2(a, b) {
    return a + b;
};

var square = function square(n) {
    return n * n;
};

var john = {
    name: "John",
    helloLater: function helloLater() {
        var _this = this;

        setTimeout(function () {
            console.log("Hello, I'm " + _this.name);
        }, 1000);
    }
};
john.helloLater();