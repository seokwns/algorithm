function solution(a, b, v) {
    if (a === b) {
        console.log(-1);
        return;
    }


    let day = 1;
    let one_day = a - b;

    let _day = Math.ceil((v - a) / one_day);

    if (_day * one_day + a >= v) {
        day = _day + 1;
    }
    else {
        day = Math.floor(v / one_day);
    }



    console.log(day);
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ').map((el) => parseInt(el));

solution(input[0], input[1], input[2]);