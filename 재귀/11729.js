/*

A(n) = A(n-1) + 1 + A(n-1)
     = 2 * A(n - 1) + 1
*/


const process = [];


function moving(n, a, b, c) { //a: 있었던 곳, b: 갈 곳, c: 나머지 하나
    if (n == 1) {
        process.push(a + ' ' + b);
    }
    else {
        moving(n - 1, a, c, b);
        moving(1, a, b, c);
        moving(n - 1, c, b, a);
    }
}


function solution(data) {
    const n = parseInt(data);
    const result = Math.pow(2, n) - 1;
    console.log(result);
    moving(n, 1, 3, 2);

    console.log(process.join('\n'));
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);