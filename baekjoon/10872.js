function solution(data) {
    let n = parseInt(data);
    let result = 1;
    for (let i = n; i > 0; i--) {
        result *= i;
    }

    console.log(result);
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);