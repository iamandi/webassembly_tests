# webassembly_tests

Testing webassembly tutorials

# References

https://emscripten.org/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html#calling-compiled-c-functions-from-javascript-using-ccall-cwrap
https://developer.mozilla.org/en-US/docs/WebAssembly/existing_C_to_wasm
https://medium.com/front-end-weekly/webassembly-part-2-writing-our-first-calculator-program-c1576153df4e

# Square root function compilation

emcc sqrt.c -o sqrt.js -s MODULARIZE -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'

    - The MODULARIZE option makes emcc emit code in a modular format that is easy to import and use with require(): require() of the module returns a factory function that can instantiate the compiled code, returning a Promise to tell us when it is ready, and giving us the instance of the module as a parameter.

# External libp library compilation

emcc -o webp.js -s MODULARIZE -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -I libwebp webp.c libwebp/src/{dec,dsp,demux,enc,mux,utils}/\*.c

    - EXPORTED_FUNCTIONS tells the compiler what we want to be accessible from the compiled code (everything else might be removed if it is not used), and EXPORTED_RUNTIME_METHODS tells the compiler that we want to use the runtime functions ccall and cwrap (otherwise, it will not include them).
    - EXPORTED_FUNCTIONS affects compilation to JavaScript. If you first compile to an object file, then compile the object to JavaScript, you need that option on the second command. If you do it all together as in the example here (source straight to JavaScript) then this just works, of course.
