function solution(data) {
    const tt = data.split('\n');
    const n = parseInt(tt[0]);

    const counts = [];
    const parsed = [];

    for (let i = 0; i < n; i++) {
        counts[i] = 0;
        parsed[i] = tt[i + 1].split(' ').map((value) => parseInt(value));
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let ap = parsed[i];
            let bp = parsed[j];

            if (ap[0] > bp[0] && ap[1] > bp[1]) {
                counts[i]++;
            }
        }
    }

    const ranks = [];
    for (let i = 0; i < n; i++) {
        let r = 1;
        for (let j = 0; j < n; j++) {
            if (counts[i] < counts[j]) {
                let ap = parsed[i];
                let bp = parsed[j];

                if (ap[0] < bp[0] && ap[1] < bp[1]) {
                    r++;
                }
            }
        }

        ranks[i] = r;
    }

    console.log(ranks.join(' '));
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);

solution('5\n55 185\n58 183\n88 186\n60 175\n46 155');
solution('8\n5 11\n5 12\n5 13\n6 14\n11 5\n12 5\n13 5\n14 6')