import { createInterface } from "readline";

const rl = createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Input number:", (line) => {
  const num = Number(line);
  console.log(num);
  const message = 0 <= num && num < 100 ? `${num} is valid` : "-1";
  console.log(message);
  rl.close();
});
