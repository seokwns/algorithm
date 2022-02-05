function solution(data) {
    const sp = data.split(' ');
    const x = parseInt(sp[0]), y = parseInt(sp[1]);
    const w = parseInt(sp[2]), h = parseInt(sp[3]);


    console.log(Math.min(x, y, w - x, h - y));
}



let input = require('fs').readFileSync('/dev/stdin').toString();

solution(input);


solution('6 2 10 3');
solution('1 1 5 5');
solution('653 375 1000 1000');
solution('161 181 762 375');