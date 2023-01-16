function solution(data) {
    const sp = data.split('\n').map((e) => parseInt(e));
    sp.shift();
    const sorted = sp.sort((a, b) => a - b);
    console.log(sorted.join('\n'));
}

let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);
solution('5\n5\n2\n3\n4\n1');