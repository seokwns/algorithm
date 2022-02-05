function solution(data) {
    const cases = parseInt(data[0]);
    let result = '';

    for (let i = 1; i <= cases; i++) {
        let tmp = data[i].split(' ').map(value => parseInt(value));

        let p1 = [tmp[0], tmp[1]], r1 = tmp[2];
        let p2 = [tmp[3], tmp[4]], r2 = tmp[5];

        let d = Math.sqrt(Math.pow(p1[0] - p2[0], 2) + Math.pow(p1[1] - p2[1], 2));

        
        if (d === 0 && r1 === r2) {
            result += '-1\n';
        }
        else if (d > r1 + r2 || d + r1 < r2 || d + r2 < r1) {
            result += '0\n';
        }
        else if (d === r1 + r2 || d + r1 === r2 || d + r2 === r1) {
            result += '1\n';
        }
        else {
            result += '2\n';
        }
    }

    console.log(result);
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);


solution(['3', '0 0 13 40 0 37', '0 0 3 0 7 4', '1 1 1 1 1 5']);