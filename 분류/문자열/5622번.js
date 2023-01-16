function solution(data) {
    let sp = data.toLowerCase().split('');
    let time = {
        a: 2,
        b: 2,
        c: 2,
        d: 3,
        e: 3,
        f: 3,
        g: 4,
        h: 4,
        i: 4,
        j: 5,
        k: 5,
        l: 5,
        m: 6,
        n: 6,
        o: 6,
        p: 7,
        q: 7,
        r: 7,
        s: 7,
        t: 8,
        u: 8,
        v: 8,
        w: 9,
        x: 9,
        y: 9,
        z: 9
    };


    let result = 0;
    for (let i = 0; i < sp.length; i++) {
        result += 1 + time[sp[i]];
    }

    console.log(result);
}


const input = require('fs').readFileSync('/dev/stdin').toString().trim();

solution(input);