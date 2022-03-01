function solution(data) {
    const ttt = data.split('\n');
    const ttttt = ttt[0].split(' ');
    const n = parseInt(ttttt[0]);
    const m = parseInt(ttttt[1]);

    const board = [];

    for (let i = 1, len = ttt.length; i < len; i++) {
        board[i - 1] = ttt[i].split('');
    }

    Object.freeze(board);


    let count = [];
    let index = 0;
    let res = 32;


    for (let x = 0; x < n - 7; x++) {
        for (let y = 0; y < m - 7; y++) {
            let cnt = [0, 0];

            for (let i = 0; i < 8; i++) {
                for (let j = 0; j < 8; j++) {
                    if ((i + j) % 2 == 0) {
                        if (board[x + i][y + j] == 'B') cnt[1]++; 
                        if (board[x + i][y + j] == 'W') cnt[0]++;
                    }
                    else {
                        if (board[x + i][y + j] == 'B') cnt[0]++;
                        if (board[x + i][y + j] == 'W') cnt[1]++;
                    }
                }
            }

            res = Math.min(res, cnt[0], cnt[1]);
        }
    }

    console.log(res);
}



let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);

solution('11 12\nBWWBWWBWWBWW\nBWWBWBBWWBWW\nWBWWBWBBWWBW\nBWWBWBBWWBWW\nWBWWBWBBWWBWn\nBWWBWBBWWBWW\nWBWWBWBBWWBW\nBWWBWBWWWBWW\nWBWWBWBBWWBW\nBWWBWBBWWBWW\nWBWWBWBBWWBW');
solution('10 10\nBBBBBBBBBB\nBBWBWBWBWB\nBWBWBWBWBB\nBBWBWBWBWB\nBWBWBWBWBB\nBBWBWBWBWB\nBWBWBWBWBB\nBBWBWBWBWB\nBWBWBWBWBB\nBBBBBBBBBB');
solution('8 8\nWBWBWBWB\nBWBWBWBW\nWBWBWBWB\nBWBBBWBW\nWBWBWBWB\nBWBWBWBW\nWBWBWWWB\nBWBWBWBW')
solution('9 23\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBB\nBBBBBBBBBBBBBBBBBBBBBBW')
solution('8 8\nBBWBWBWB\nBWBWBWBW\nWBWBWBWB\nBWBBBWBW\nWBWBWBWB\nBWBWBWBW\nWBWBWBWB\nBWBWBWBB')