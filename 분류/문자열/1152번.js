const fs = require("fs");
const [input] = (
  process.platform === "linux" ? fs.readFileSync("/dev/stdin").toString() : ` `
)
  .trim()
  .split("\n");

let arr = input.split(' ');
if (arr[0] === '') {
    arr.shift();
}

console.log(arr.length);