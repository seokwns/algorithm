function solution(data) {
    let points = {
        x: [],
        y: []
    }

    data.forEach(value => {
        let tmp = value.split(' ');
        points.x.push(parseInt(tmp[0]));
        points.y.push(parseInt(tmp[1]));
    });

    let result = [];

    points.x.forEach((value) => {
        if (points.x.filter(e => e === value).length === 1) {
            result[0] = value;
        }
    });
    points.y.forEach((value) => {
        if (points.y.filter(e => e === value).length === 1) {
            result[1] = value;
        }
    });


    console.log(result.join(' '));
}


let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

solution(input);

solution(['5 5', '5 7', '7 5']);
solution(['30 20', '10 10', '10 20']);