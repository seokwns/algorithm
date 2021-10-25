/*
1(1개)

2 3 4 5 6 7 (6개)

8 9 10 11 12 13 14 15 16 17 18 19 (12개)

20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 (18개)


38~61 (24개)

: 1레이어 증가 = 6개 추가


n이 있는 레이어: 6 * (1..합) < n
*/

function getLayer(n) {
    let layer = 1, i = 1;

    while(i < n) {
        i += 6 * layer;
        layer++;
    }

    console.log(layer);
}

let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ').map((el) => parseInt(el));

getLayer(input[0]);