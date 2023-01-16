function gets(n) {
    const tr = n.toString().split('');
    
    return tr.reduce((accumulator, value) => {
        return (accumulator + parseInt(value));
    }, n);
}

function solution(data) {
    const n = parseInt(data);
    let result = n + 1;

    for (let i = 0; i < n; i++) {
        let t = gets(i);
        if (t == n && i < result) {
            result = i;
        }
    }

    if (result == n + 1) {
        console.log('0');
    }
    else {
        console.log(result);
    }
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);

solution(216)