var john = {
    name: "John",
    helloLater: function() {
        setTimeout(() => {
            console.log("Hello, I'm " + this.name);
        }, 1000);
    }
};
john.helloLater();