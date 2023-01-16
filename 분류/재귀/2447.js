function star(arr, x, y, len) {
    if (len == 1) {
        arr[x][y] = '*';
    }
    else {
        const _len = len / 3;

        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                if ( i != 1 || j != 1 ) {
                    star(arr, x + (_len * i), y + (_len * j), _len );
                }
            }
        }
    }
}


function solution(data) {
    const n = parseInt(data);
    const dots = new Array(n);

    for (let i = 0; i < n; i++) {
        dots[i] = new Array(n);
    }

    star(dots, 0, 0, n);
    let str = '';

    for (let x = 0; x < n; x++) {
        for (let y = 0; y < n; y++) {
            if (dots[x][y] == undefined) str += ' ';
            else str += dots[x][y];
        }
        str += '\n';
    }

    console.log(str);
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);