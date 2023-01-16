function solution(data) {

    let bigger = 0, smaller = 1;

    if (data[0].length === 1 && data[1].length === 1) {
        console.log(parseInt(data[0]) + parseInt(data[1]));
        return;
    }

    if (data[0].length >= data[1].length) {
        bigger = 0;
        smaller = 1;
    }
    else {
        bigger = 1;
        smaller = 0;
    }
    
    if (data[0] === data[1]) {
        bigger = 0;
        smaller = 1;
    }
    

    data[0] = data[0].split('').reverse().map(el => parseInt(el));
    data[1] = data[1].split('').reverse().map(el => parseInt(el));

    
    let result = [];
    let tmp = 0;

    
    for (let i = 0; i <= data[bigger].length; i++) {

        let _tmp;
        
        if (i < data[smaller].length) {
            _tmp = data[bigger][i] + data[smaller][i] + tmp;
        }
        else if (i < data[bigger].length) {
            _tmp = data[bigger][i] + tmp;
        }
        else if (i === data[bigger].length) {
            if (tmp !== 0) {
                result[i] = tmp;
            }
            break;
        }
        
        if (_tmp >= 10) {
            tmp = Math.floor(_tmp / 10);
        }
        else {
            tmp = 0;
        }

        result[i] = _tmp % 10;
    }


    console.log(result.reverse().join(''));
}




// let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split(' ');

// solution([input[0], input[1]]);

// solution(["9223372036854775807", "9223372036854775808"]);
// solution(["999", "10"]);
// solution(["111111111111111111111111111111111111111", "9"]);
// solution(["111", "222"]);
// solution(["10", "111111111111111111111111111111111111111111111111"]);
// solution(["1111111111111111111111111111111111111111111", "1"]);
// solution(['1', '1']);
// solution(['111111111111111111111111111', '111111111111111111111111111']);


/*
이거 이상하다
아무리 해봐도 정답이 나오는데
제출하면 계속 틀렸다고만 나온다,,,

그래서 숫자의 크기를 고려할 필요 없는 파이썬으로 대체
*/
// a, b = input().split()
// a = int(a)
// b = int(b)

// print(a+b)


let a = BigInt("9223372036854775807");
let b = BigInt("9223372036854775808");

console.log(BigInt(a+b).toString());