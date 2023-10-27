function solution(data) {
    const testCase = parseInt(data[0]);
    let count = 0;

    for (let i = 1; i <= testCase; i++) {

        if (data[i].length === 1 || data[i].length === 2) {
            count++;
            continue;
        }

        if (data[i].length === 3) {
            if (data[i][0] !== data[i][2]) {
                count++;
            }
            else {
                if (data[i][0] === data[i][1]) {
                    count++;
                }
            }
            continue;
        }

        let sp = data[i].split('');
        let searched = '';
        let tmp = sp[0];

        for (let j = 0, len = sp.length; j < len; j++) {
            if (j === len - 1) {
                if (searched.indexOf(sp[j]) === -1) {
                    count++;
                }
            }

            if (searched.indexOf(sp[j]) !== -1) {
                break;
            }
            else {
                if (sp[j] === tmp) {
                    if (sp[j+1] === tmp) {
                        continue;
                    }
                    else {
                        searched += sp[j];
                        tmp = sp[j+1];
                    }
                }
            }
        }
    }

    console.log(count);
}


const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);


solution(['3', 'happy', 'new', 'year'])
solution(['4', 'aba', 'abab', 'abcabc', 'a'])
solution(['5', 'ab', 'aa', 'aca', 'ba', 'bb'])
solution(['2', 'yzyzy', 'zyzyz'])
solution(['1', 'z'])
solution(['1', 'aaa'])