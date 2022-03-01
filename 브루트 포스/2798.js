function solution(data) {
    const ttmp = data.split('\n');
    const n = parseInt(ttmp[0].split(' ')[0]);
    const m = parseInt(ttmp[0].split(' ')[1]);
    const nums = ttmp[1].split(' ').map((value) => {
        let t = parseInt(value);
        if (t < m) return t;
    });

    let results = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                let tt = nums[i] + nums[j] + nums[k];
                if (tt <= m && results < tt) results = tt;
            }
        }
    }


    console.log(results);
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);

solution('10 500\n93 181 245 214 315 36 185 138 216 295');