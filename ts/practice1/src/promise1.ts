import { readFile } from "fs/promises";

readFile("package.json", "utf8")
  .finally(() => {
    console.log("1. finally");
  })
  .catch(() => "")
  .then((result) => console.log(`2. ${result}`));
