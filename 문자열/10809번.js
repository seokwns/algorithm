function solution(data) {
    let letters = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1];
    data.split('').map((el, index) => {
        let loc = el.charCodeAt(0) - 'a'.charCodeAt(0);
        if (letters[loc] === -1) {
            letters[loc] = index;
        } 
    });

    let str = ''
    for (let i = 0; i < letters.length; i++) {
        if(i !== letters.length - 1) str += letters[i] + ' ';
        else str += letters[i];
    }

    console.log(str);
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);