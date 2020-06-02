"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", function () {
  inputString = inputString
    .replace(/\s*$/, "")
    .split("\n")
    .map((str) => str.replace(/\s*$/, ""));

  main();
});

function readLine() {
  return inputString[currentLine++];
}

// Complete the kaprekarNumbers function below.
function kaprekarNumbers(p, q) {
  let result = Array.from(
    { length: q - p + 1 },
    (value, index) => index + p
  ).reduce((target, value, index) => {
    let square = `${value ** 2}`;
    let right = +square.substring(
      square.length - `${value}`.length,
      square.length
    );
    let left = +square.substring(0, square.length - `${value}`.length);

    left + right == value && target.push(value);

    return target;
  }, []);

  console.log(!result.length ? "INVALID RANGE" : result.join(" "));
}

function main() {
  const p = parseInt(readLine(), 10);

  const q = parseInt(readLine(), 10);

  kaprekarNumbers(p, q);
}
