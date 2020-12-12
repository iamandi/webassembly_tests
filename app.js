const sqrtFactory = require("./sqrt");
const webpFactory = require("./webp");

sqrtFactory().then((instance) => {
  instance._sayHi(); // direct calling works
  instance.ccall("sayHi"); // using ccall etc. also work
  console.log(instance._int_sqrt(12)); // values can be returned, etc.
});

webpFactory().then((instance) => {
  console.log(`webp version: ${instance._webpVersion()}`);
});
