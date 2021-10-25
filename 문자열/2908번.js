function solution(data) {
    let [a, b] = data.map(el => el.split('').reverse().join(''));
    console.log((a > b ? a : b));
}


const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

solution(input);