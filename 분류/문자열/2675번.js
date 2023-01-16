function solution(data) {
    const testCase = parseInt(data[0]);
    const alphanumeric = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:';

    for (let i = 1; i <= testCase; i++) {
        const sp = data[i].split(' ');
        const repeat = sp[0];
        let result = '';

        sp[1].split('').forEach(el => {
            if (alphanumeric.indexOf(el) !== -1) {
                for (let j = 0; j < repeat; j++) {
                    result += el;
                }
            }
        });

        console.log(result);
    }
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

solution(input);