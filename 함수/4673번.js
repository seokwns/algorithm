function d(n) {
    let result = n;
    let resm = n.toString().split('');

    for (let i = 0; i < resm.length; i++) {
        result += parseInt(resm[i])
    }

    return result;
}


function solution(N) {
    let numbers = [0, 0];
    let res = '';
    
    for (let i = 1; i <= N; i++) {
        numbers[d(i)] = 1;
        if (numbers[i] !== 1) {
            res += i + '\n';
        }
    }

    console.log(res);
}


solution(10000)