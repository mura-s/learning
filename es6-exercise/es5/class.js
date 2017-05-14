"use strict";

var _get = function get(_x, _x2, _x3) { var _again = true; _function: while (_again) { var object = _x, property = _x2, receiver = _x3; desc = parent = getter = undefined; _again = false; if (object === null) object = Function.prototype; var desc = Object.getOwnPropertyDescriptor(object, property); if (desc === undefined) { var parent = Object.getPrototypeOf(object); if (parent === null) { return undefined; } else { _x = parent; _x2 = property; _x3 = receiver; _again = true; continue _function; } } else if ("value" in desc) { return desc.value; } else { var getter = desc.get; if (getter === undefined) { return undefined; } return getter.call(receiver); } } };

var _createClass = (function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; })();

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

var Person = (function () {
    function Person(name) {
        _classCallCheck(this, Person);

        this.name = name;
    }

    _createClass(Person, [{
        key: "greet",
        value: function greet() {
            console.log("Hello, I'm " + this.name);
        }
    }], [{
        key: "create",
        value: function create(name) {
            return new Person(name);
        }
    }]);

    return Person;
})();

var Author = (function (_Person) {
    _inherits(Author, _Person);

    function Author(name, book) {
        _classCallCheck(this, Author);

        _get(Object.getPrototypeOf(Author.prototype), "constructor", this).call(this, name);
        this.book = book;
    }

    _createClass(Author, [{
        key: "greet",
        value: function greet() {
            _get(Object.getPrototypeOf(Author.prototype), "greet", this).call(this);
            console.log("I wrote " + this.book);
        }
    }], [{
        key: "create",
        value: function create(name, book) {
            return new Author(name, book);
        }
    }]);

    return Author;
})(Person);

var author = new Author("John", "Book");
author.greet();