function solution(data) {
    let a = BigInt(data[0]);
    let b = BigInt(data[1]);

    console.log(a + b);
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

solution(input);