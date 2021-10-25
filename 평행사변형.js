/*
 * 백준 알고리즘 문제
 * 서로 다른 3개의 점이 주어지면, 적절한 점 D를 찾아 평행사변형을 만들 수 있다.
 * 이때, D가 여러 개 나올 수도 있다.
 * 만들어진 모든 사각형 중 가장 큰 둘레 길이와 가장 작은 둘레 길이의 차이를 출력하시오
 * 만들 수 있는 평행사변형이 없다면, -1을 출력
 * 
 * 제한시간 2초 / 메모리 제한 128MB
*/

class Dot {
    constructor(cx, cy) {
        this.x = cx;
        this.y = cy;
    }

    distance(_dot) {
        let dx = this.x - _dot.x;
        let dy = this.y - _dot.y;

        return Math.hypot(dx, dy);
    }

    getA(_dot) {
        return (this.y - _dot.y) / (this.x - _dot.x);
    }
}



function init(args) {
    let A = new Dot(args[0], args[1]);
    let B = new Dot(args[2], args[3]);
    let C = new Dot(args[4], args[5]);

    if(A.getA(B) == A.getA(C)) {
        console.log("-1");
        return;
    }

    let diss = [C.distance(A) + C.distance(B), A.distance(B) + A.distance(C), B.distance(C) + B.distance(A)];

    let dmin = Math.min(diss[0], diss[1], diss[2]);
    let dmax = Math.max(diss[0], diss[1], diss[2]);

    console.log((dmax - dmin) * 2);
}


init([2, -1, -7, 2, -1, 0]); //0, 0, 0, 1, 1, 0