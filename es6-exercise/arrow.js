var add = (a, b) => {
    return a + b;
};

var add2 = (a, b) => a + b;

var square = n => n * n;

var john = {
    name: "John",
    helloLater: function() {
        setTimeout(() => {
            console.log("Hello, I'm " + this.name);
        }, 1000);
    }
};
john.helloLater();