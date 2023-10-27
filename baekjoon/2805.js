function solution(data) {
    const sp1 = data.split('\n');
    const sp2 = sp1[0].split(' ');

    const N = parseInt(sp2[0]);
    const M = parseInt(sp2[1]);
    const lens = sp1[1].split(' ').map(value => parseInt(value)).sort((a, b) => a - b);

    let left = 0, right = lens[N - 1] + 1, mid;
    let maxx = 0;

    while (left <= right) {
        mid = Math.floor((right + left) / 2);
        if (check(lens, mid, M, N)) {
            if (maxx < mid) {
                maxx = mid;
            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    console.log(maxx);
}

function check(arr, l, m, n) {
    let res = 0;
    for (let i = 0; i < n; i++) {
        let d = arr[i] - l;
        res += (d > 0? d : 0);
        if (res >= m) return true;
    }

    return false;
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);


solution('4 7\n20 15 10 17');