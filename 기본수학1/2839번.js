/*
3과 5를 조합해서 N을 만들어야 함.
만들 수 없으면 -1

3x + 5y = N
y = (N - 3x) / 5

x,y,N 양의 정수

이때 x+y 최솟값
= x + ( N - 3x ) / 5
= N / 5 + 2/5x 최솟값
*/


function solution(data) {
    let check = [];

    for (let i = 0; i < data; i++) {
        let current = (data - 3 * i) / 5;

        if (current >= 0 && isInt(current)) {
            check.push(data / 5 + 0.4 * i);
        }
    }


    if (check.length === 0) {
        console.log(-1);
        return;
    }


    let x = check[0];
    for (let i = 0; i < check.length; i++) {
        if (x > check[i]) {
            x = check[i];
        }
    }

    console.log(x);
}


function isInt(num) {
    if(num - parseInt(num) === 0) {
        return true;
    }
    else {
        return false;
    }
}


let fs = require('fs');
let input = parseInt(fs.readFileSync('/dev/stdin').toString())

solution(input);