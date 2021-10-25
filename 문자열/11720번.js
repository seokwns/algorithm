let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let result = input[1].split('').reduce((accumulator, value) => {
    accumulator += parseInt(value);

    return accumulator;
}, 0);


console.log(result);