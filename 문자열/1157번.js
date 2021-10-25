function solution(data) {
    const count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    data.toLowerCase().split('').forEach(el => {
        let loc = el.charCodeAt(0) - 'a'.charCodeAt(0);
        count[loc]++;
    });

    let max = count[0];
    let index = 0;
    let check = false;

    for (let i = 1; i < count.length; i++) {
        if (count[i] > max) {
            max = count[i];
            index = i;
            check = false;
        }
        else if (count[i] === max) {
            check = true;
        }
    }


    if (check) {
        console.log('?');
    }
    else if (!check) {
        console.log((String.fromCharCode('a'.charCodeAt(0) + index)).toUpperCase());
    }
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);