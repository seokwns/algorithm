function solution(n) {
    let result = [1, 1];

    let layer = 1, i = 1;
    while (i + layer <= n) {
        i += layer;
        layer++;
    }

    
    let rest = n - i;

    if(layer%2 === 0) {
        result = [rest + 1, layer - rest];
    }
    else {
        result = [layer - rest, rest + 1];
    }


    console.log(result[0] + "/" + result[1]);
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ').map((el) => parseInt(el));

solution(input[0]);