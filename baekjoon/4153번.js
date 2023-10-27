function solution(data) {
    const count = data.length;
    let result = '';

    for (let i = 0; i < count; i++) {
        let tmp = data[i].split(' ').map(e => {
            return parseInt(e);
        });

        tmp.sort((a, b) => {
            return (a - b);
        });

        if (tmp[0] === 0) {
            break;
        }


        if (tmp[0] === tmp[1]) {
            result += 'wrong\n'
        }
        else if (Math.hypot(tmp[0], tmp[1]) === tmp[2]) {
            result += 'right\n';
        }
        else {
            result += 'wrong\n';
        }
    }


    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);


solution(['6 8 10', '25 52 60', '5 12 13', '0 0 0']);