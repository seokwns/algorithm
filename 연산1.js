function init(args) {
    let results = [];

    for(let i = 0; i <= Math.sqrt(args); i++) {
        for(let j = 1; j <= Math.sqrt(args); j++) {
            if(Math.pow(1 + i, j) <= args && Math.pow(1 + i, j + 1) > args) {
                let tt = 0;
                if(j > 1) tt = 1;
                results.push(i + tt + Math.abs(args - Math.pow(1 + i, j)));
                results.push(i + tt + Math.abs(args - Math.pow(1 + i, j + 1)));
            }
        }
    }

    let mmin = results[0];
    for(let i = 1; i < results.length; i++) {
        if(mmin > results[i]) mmin = results[i];
    }
    
    console.log("output : ", results);
}

init(80);