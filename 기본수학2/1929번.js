function solution(data) {
    let start = parseInt(data[0]);
    let end = parseInt(data[1]);
    const set = new Set();

    for (let i = 1; i <= end; i += 2) {
        set.add(i);
    }

    set.delete(1);
    set.add(2);

    for (let i = 3; i < Math.sqrt(end) + 1; i++) {
        if (set.has(i)) {
            for (let k = i * i; k <= end; k += i) {
                set.delete(k);
            }
        }
    }

    let result = '';
    
    for (let i = start; i <= end; i++) {
        if (set.has(i)) {
            result += i + '\n';
        }
    }

    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split(' ');

solution(input);


solution(['1', '1000000'])