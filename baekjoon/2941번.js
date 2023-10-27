function solution(data) {
    let croc = data.replace(/c\=|c\-|dz\=|d\-|lj|nj|s\=|z\=/g, '1');

    let sp = croc.split('');
    if (sp[0] === ' ') {
        sp.pop();
    }

    
    console.log(sp.length);
}


const input = require('fs').readFileSync('/dev/stdin').toString().trim();

solution(input);