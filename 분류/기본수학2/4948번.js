function solution(data) {
    const set = new Set();
    const max = 123456 * 2;

    for (let i = 3; i <= max; i += 2) {
        set.add(i);
    }

    set.add(2);

    for (let i = 3; i < Math.sqrt(max) + 1; i += 2) {
        if (set.has(i)) {
            for (let k = i * i; k <= max; k += i) {
                set.delete(k);
            }
        }
    }


    let result = '';
    let index = 0;

    while(data[index] !== '0') {
        let n = parseInt(data[index]);
        let count = 0;

        for (let i = n + 1; i <= 2 * n; i++) {
            if (set.has(i)) count++;
        }

        result += count + '\n';
        index++;
    }
    

    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);


solution(['1', '10', '13', '100', '1000', '10000', '100000', '0'])