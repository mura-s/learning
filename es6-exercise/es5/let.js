"use strict";

var _loop = function (i) {
    setTimeout(function () {
        console.log(i);
    }, i * 100);
};

for (var i = 0; i < 5; i++) {
    _loop(i);
}