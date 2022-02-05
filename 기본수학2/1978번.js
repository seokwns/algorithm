function solution(data) {
    const testCase = parseInt(data[0]);
    const cases = data[1].split(' ');

    let prime_numbers = [0, 0, 1, 1, 0, 1];

    for (let i = 2, len = Math.sqrt(1000); i <= len; i++) {
        for (let j = 2; i * j <= 1000; j++) {
            prime_numbers[i * j] = 0;
        }
    }


    let count = 0;
    for (let i = 0; i < testCase; i++) {
        if (prime_numbers[parseInt(cases[i])] !== 0) {
            count++;
        }
    }

    console.log(count);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);

// solution(['4', '1 3 5 7'])