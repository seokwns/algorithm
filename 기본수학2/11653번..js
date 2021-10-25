function solution(data) {
    let n = parseInt(data);

    if (n === 1) {
        return;
    }

    let result = [];

    for (let i = 2; i <= n; i++) {
        while (n%i === 0) {
            n /= i;
            result.push(i);
        }
    }


    console.log(result.join('\n'));
}


let input = require('fs').readFileSync('/dev/stdin').toString();

solution(input);


solution('72')
// solution('3')
// solution('6')
// solution('2')
// solution('9991')
