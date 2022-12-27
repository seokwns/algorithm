function solution(data) {
    const sp = data.split('\n');
    const [N, S] = sp[0].split(' ').map(Number);
    const nums = sp[1].split(' ').map(Number);

    let ans = 100001;
    let start = 0, end = 0;
    let sum = nums[0];


    while(true) {
        if (sum >= S) {
            ans = Math.min(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        else {
            if (end == N) {
                break;
            }
            else {
                end++;
                sum += nums[end];
            }
        }
    }

    if (ans == 100001) ans = 0;
    console.log(ans);
}



// let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString();

// solution(input);


solution('10 15\n5 1 3 5 10 7 4 9 2 8');