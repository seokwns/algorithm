function solution(data) {
    const start = parseInt(data[0]);
    const end = parseInt(data[1]);
    
    let prime_numbers = [0, 0, 1, 1, 0, 1];
    for (let i = 2, len = end / 2; i <= len; i++) {
        for (let j = 2; j <= end / j; j++) {
            prime_numbers[i * j] = 0;
        }
    }

    let min_prime = end;
    let prime_sum = 0;
    for (let i = start; i <= end; i++) {
        if (prime_numbers[i] !== 0) {
            prime_sum += i;

            if (min_prime > i) {
                min_prime = i;
            }
        }
    }


    let result = (prime_sum === 0? '-1' : (prime_sum + '\n' + min_prime));
    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);


// solution(['64', '65'])