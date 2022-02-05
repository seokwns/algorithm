/*
2 3 5 7 11 13 17 19 23 31


14
= 7 + 7
= (5+2) + (5+2)
= (3+2+2) + (3+2+2)
= (2+1+2+2) + (2+1+2+2)
= 



그냥 n보다 작거나 같은 소수들 전부 구한 다음
n에서 소수 뺀 값이 소수이면 저장

이후 저장된 조합들 중에서

두 수의 차이가 가장 작은 것 출력


하면 간단하네
*/


function solution(data) {
    const set = new Set();
    const testCase = parseInt(data[0]);
    const max = 10000;

    set.add(2);

    for (let i = 3; i <= max; i += 2) {
        set.add(i);
    }

    for (let i = 3; i < Math.sqrt(max) + 1; i += 2) {
        if (set.has(i)) {
            for (let k = i * i; k <= max; k += i) {
                set.delete(k);
            }
        }
    }


    let result = '';
    let prime_numbers = Array.from(set);


    for (let t = 1; t <= testCase; t++) {
        let i = 0;
        let now = parseInt(data[t]);
        let dd = [0, now];

        while(prime_numbers[i] <= now) {
            let tmp = now - prime_numbers[i];

            if (set.has(tmp)) {
                if (Math.abs(prime_numbers[i] - tmp) < Math.abs(dd[0] - dd[1])) {
                    dd = [prime_numbers[i], tmp];
                }
            }
            i++;
        }

        result += Math.min(dd[0], dd[1]) + ' ' + Math.max(dd[0], dd[1]) + '\n';
    }

    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);

solution(['3', '8', '10', '16'])
solution(['1', '4'])