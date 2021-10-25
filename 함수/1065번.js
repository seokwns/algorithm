function isOneNumber(n) {
    let temp = n.toString().split('');

    if (temp.length === 1 || temp.length === 2) {
        return true;
    }

    const d = temp[0] - temp[1];

    for(let i = 1; i < temp.length - 1; i++) {
        if (temp[i] - temp[i + 1] !== d) {
            return false;
        }
    }

    return true;
}


function solution(data) {
    let count = 0;
    for (let i = 1; i <= data; i++) {
        if (isOneNumber(i)) {
            count++;
        }
    }

    console.log(count)
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(parseInt(input));