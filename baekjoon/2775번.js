/*
1
1
1
1
1  7  
1  6  21
1  5  15
1  4  10 20 35 56 84 120 165
1  3  6  10 15 21 28 36 45
1  2  3  4  5  6  7  8  9 : 0층
1  1  1  1  1  1  1  1  1 : -1층

이 표를 좌측 하단에서 우측 상단으로 보면, 이항계수들이다.
즉, 이항정리 문제.

일반화된 이항정리는 다음과 같다.
(x+y)^a = sigma k=o to infinite a(a-1)(a-2)...(a-k+1) * x^(a-k) * y^k / k!

즉 이 문제에서 구하고자 하는 것은 k층 n호에 몇 명이 살고 있는지 출력하는 것.
(x+y)의 k+n 제곱을 전개한 식에서 n번째 항의 계수를 구하는 것과 같다.

즉, ( (k+n)(k+n-1)(k+n-2)...(k+n-(n-1)) / n! ) 이것이 정답!
*/



function solution(data) {
    let testCase = data[0];
    
    for(let i = 0; i < testCase; i++) {
        let current = 2 * i + 1;
        let k = data[current];
        let n = data[current + 1];

        let result = 1;
        for(let j = 0; j < n - 1; j++) {
            result = result * (k + n - j);
        }
        
        for(let j = 1; j < n; j++) {
            result = result / j;
        }
        
        console.log(Math.abs(result));
    }
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n').map((el) => parseInt(el));

solution(input);