function throwError() {
  throw new Error("throwError: Something went wrong!");
}

function wrapInTryCatch() {
  try {
    throwError();
  } catch (error) {
    if (error instanceof Error) {
      console.log("wrapInTryCatch: Catch");
      throw new Error(`wrap: ${error.message}`);
    }
  } finally {
    console.log("wrapInTryCatch: Finally"); // This will be executed
  }
}

wrapInTryCatch();
console.log("finish"); // This won't be executed
