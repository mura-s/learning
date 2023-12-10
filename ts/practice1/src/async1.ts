const asyncFn = async () => {
  console.log("asyncFn");
  return 1;
};

const v = await asyncFn();
console.log(v);

export {};
