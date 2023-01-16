function solution(data) {
    const fibo = [0, 1, 1, 2, 3, 5, 8];
    const n = parseInt(data);
    
    if (n == 0) {
        console.log('0');
        return;
    }
    else if (n == 1) {
        console.log('1');
        return;
    }
    else {
        for (let i = 2; i <= n; i++) {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
    }

    console.log(fibo[n]);
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);