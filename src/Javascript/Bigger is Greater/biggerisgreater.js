"use strict";

const fs = require("fs");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .replace(/\s*$/, "")
    .split("\n")
    .map((str) => str.replace(/\s*$/, ""));

  main();
});

function readLine() {
  return inputString[currentLine++];
}

// Complete the biggerIsGreater function below.
function biggerIsGreater(w) {
  let values = [...w];
  let point1 = values.length - 1;

  while (point1 > 0 && values[point1] <= values[point1 - 1]) point1--;

  if (!point1) return "no answer";

  let point2 = point1;

  point1--;

  let min = values[point2];

  for (let i = point1 + 2; i < values.length; i++) {
    values[i] < min &&
      values[i] > values[point1] &&
      ((point2 = i), (min = values[i]));
  }

  [values[point1], values[point2]] = [values[point2], values[point1]];

  return [
    ...values.slice(0, point1 + 1),
    ...values
      .slice(point1 + 1, values.length)
      .sort((x, y) => (x >= y ? 1 : -1)),
  ].join("");
}

function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const T = parseInt(readLine(), 10);

  for (let TItr = 0; TItr < T; TItr++) {
    const w = readLine();

    let result = biggerIsGreater(w);

    ws.write(result + "\n");
  }

  ws.end();
}
