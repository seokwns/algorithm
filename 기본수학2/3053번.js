function solution(data) {
    const r = parseInt(data);
    const s1 = (r * r * Math.PI).toFixed(6);
    const s2 = 2 * r * r;

    console.log(s1 + '\n' + s2);
}

let input = require('fs').readFileSync('/dev/stdin').toString();

solution(input);